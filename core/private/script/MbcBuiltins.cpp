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
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "script/MbcValue.h"
#include "script/ScriptContainer.h"
#include "text/Fonts.h"
#include "text/Text.h"
#include "text/TextBuffer.h"
#include "ui/ScriptInterface.h"
#include "world/WorldObjects.h"



void SferaMbcRuntime::scriptConfiguration()
{
    auto &config = g_sfera_config_text_runtime;
    const auto operation = SferaNumeric::enumFromBits<SferaConfigTextRuntimeOperation>(nextInteger());
    switch (operation)
    {
    case SferaConfigTextRuntimeOperation::Write:
    {
        const auto keyOffset = nextWord();
        if (execution_failed)
        {
            break;
        }
        const std::string key(textAt(keyOffset));
        if (native_call->cursor >= native_call->arguments.size())
        {
            reportError("Too few parameters");
            break;
        }
        const auto type = SferaNumeric::enumBits(native_call->arguments[native_call->cursor].type);
        std::string value;
        bool quoted = false;
        if (!key.empty() && key.front() == '*')
        {
            const auto offset = nextWord();
            const auto size = nextInteger();
            if (execution_failed)
            {
                break;
            }
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
            {
                break;
            }
            value = textAt(offset);
            quoted = true;
        }
        else
        {
            reportError("cfg_set: unsupported value type");
            break;
        }
        if (!execution_failed)
        {
            pushInteger(config.writeValue(key, value, quoted) ? 0u : UINT32_MAX);
        }
        break;
    }
    case SferaConfigTextRuntimeOperation::Read:
    {
        const auto keyReference = nextSliceReference();
        if (execution_failed)
        {
            break;
        }
        const auto key = textIn(keyReference);
        if (native_call->cursor >= native_call->arguments.size())
        {
            reportError("Too few parameters");
            break;
        }
        const auto type = native_call->arguments[native_call->cursor].type;
        const auto destination = nextSliceReference();
        const auto capacity = native_call->count == 4 ? nextWord() : 10000000u;
        if (execution_failed)
        {
            break;
        }
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
            {
                writeMemory(destination.base, value);
            }
        }
        else if (type == SferaMbcValueTypeRealPointer)
        {
            auto value = readMemory<float>(destination.base);
            result = config.readFloat(key, value);
            if (result)
            {
                writeMemory(destination.base, value);
            }
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
        {
            reportError("poppointerup(): unexpected NULL-pointer fetched");
        }
        if (execution_failed)
        {
            break;
        }
        const auto text = textIn(reference);
        if (operation == SferaConfigTextRuntimeOperation::UseText)
        {
            config.useText(reference.base, sliceBytes(reference).size(), active_process);
            pushInteger(0);
        }
        else if (operation == SferaConfigTextRuntimeOperation::Load)
        {
            pushInteger(config.load(std::string(text)) ? 0u : UINT32_MAX);
        }
        else
        {
            const auto length = text.size();
            if (length >= SferaConfigTextRuntime::filename_capacity)
            {
                reportError("cfg: filename is too long");
                break;
            }
            if (operation == SferaConfigTextRuntimeOperation::Clear)
            {
                config.clear(std::string(text));
            }
            else
            {
                config.filename.assign(text);
            }
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
        {
            reportError("poppointerup(): unexpected NULL-pointer fetched");
        }
        const std::uint32_t capacity = nextWord();
        if (!execution_failed)
        {
            pushInteger(SferaNumeric::lowWord(config.copyTo(sliceBytes(destination).first(std::min<std::size_t>(capacity, sliceBytes(destination).size())))));
        }
        break;
    }
    case SferaConfigTextRuntimeOperation::Length:
        if (std::in_range<std::uint32_t>(config.text().size()))
        {
            pushInteger(SferaNumeric::lowWord(config.text().size()));
        }
        else
        {
            reportError("cfg: text is too long for MBC");
        }
        break;
    default:
        break;
    }
}

void SferaMbcRuntime::scriptContainerCommand()
{
    auto *container = nativeResource<SferaScriptContainer *>(nextWord());
    if (container == nullptr)
    {
        pushInteger(UINT32_MAX);
    }
    else if (container->header.kind >= SferaDataContainerHeaderKind::List && container->header.kind <= SferaDataContainerHeaderKind::HashMap)
    {
        container->execute(*this);
    }
}

void SferaMbcRuntime::scriptContainerManagement()
{
    const auto command = SferaNumeric::enumFromBits<SferaScriptContainerLifecycle>(nextInteger());
    if (command == SferaScriptContainerLifecycle::Create)
    {
        const auto kind = SferaNumeric::enumFromBits<SferaScriptContainerKind>(SferaNumeric::word(nextInteger()));
        if (kind < SferaScriptContainerKind::List || kind > SferaScriptContainerKind::HashMap)
        {
            pushInteger(0);
            return;
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
        return;
    }
    if (command < SferaScriptContainerLifecycle::Destroy || command > SferaScriptContainerLifecycle::KeyType)
    {
        pushInteger(UINT32_MAX);
        return;
    }
    const std::uint32_t handle = nextInteger();
    if (command == SferaScriptContainerLifecycle::Destroy)
    {
        active_process->unregisterResource(handle, SferaMbcRuntimeResourceKind::container);
    }
    auto *container = nativeResource<SferaScriptContainer *>(handle);
    if (container == nullptr)
    {
        pushInteger(UINT32_MAX);
        return;
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
        {
            pushInteger(UINT32_MAX);
        }
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
}

void SferaMbcRuntime::scriptFail()
{
    std::string message;
    message = std::format("MBInter:\n {:f}", nextReal());
    SferaClientApplication::terminateWithError(message);
}

void SferaMbcRuntime::scriptExit()
{
    if (native_call->count == 0)
    {
        throw SferaClientApplicationExitRequested{};
    }
    if (native_call->count > 1)
    {
        g_sfera_mbc_runtime.dispatch_slot = -1;
    }
    const auto message = nextSliceReference().base;
    SferaClientApplication::terminateWithError(textAt(message));
}

void SferaMbcRuntime::scriptLoadProcess()
{
    const auto name = nextSliceReference().base;
    const auto index = native_call->count > 1 ? nextWord() : UINT32_MAX;
    if (execution_failed)
    {
        return;
    }
    if (name == 0)
    {
        ::OutputDebugStringA("NULL-pointer dereferencing: ffprc_load\n");
    }
    active_tag = loadProcess(textAt(name), index);
    pushInteger(active_tag);
}

void SferaMbcRuntime::scriptUnloadProcess()
{
    const std::uint32_t requested = nextInteger();
    const auto *process = findProcess(requested);
    const auto index = process == nullptr ? UINT32_MAX : requested;
    if (execution_failed)
    {
        return;
    }
    if (index == SferaNumeric::word(process_index))
    {
        active_tag = UINT32_MAX;
    }
    else
    {
        active_tag = unloadProcess(index);
    }
    pushInteger(active_tag);
}

void SferaMbcRuntime::scriptLinkProcess()
{
    const auto name = nextSliceReference().base;
    if (name == 0)
    {
        ::OutputDebugStringA("NULL-pointer dereferencing: ffprc_link\n");
    }
    active_tag = linkProcess(textAt(name));
    pushInteger(active_tag);
}

void SferaMbcRuntime::scriptDiscardInteger()
{
    nextInteger();
}

void SferaMbcRuntime::scriptNoop()
{
    return;
}

void SferaMbcRuntime::scriptProcessName(bool current, bool module)
{
    const auto id = current ? process_index : nextWord();
    const auto destination = nextWord();
    if (destination == 0 && !module)
    {
        WorldDiagnostics::warning(current ? "NULL-pointer dereferencing: thisname\n" : "NULL-pointer dereferencing: prc_name\n");
    }
    if (execution_failed)
    {
        return;
    }
    std::optional<std::string_view> name;
    if (current)
    {
        name = active_process->name;
    }
    else if ((!current && !module) && id < std::size(processes) && processes[id].chain_prev_index >= 0)
    {
        name = processes[id].name;
    }
    else if (module && id < 4096u)
    {
        name = SferaNativeCatalog::moduleName(id);
    }
    if (name)
    {
        copyText({destination, 0, 0}, *name);
    }
    if (!current)
    {
        pushInteger(name && (!module || !name->empty()) ? 0 : UINT32_MAX);
    }
}

void SferaMbcRuntime::scriptFindModule()
{
    const auto name = nextInteger();
    if (execution_failed)
    {
        return;
    }
    pushInteger(SferaNativeCatalog::findModuleTag(textAt(name)));
}

void SferaMbcRuntime::scriptFindProcess()
{
    const bool byName = native_call->arguments[native_call->cursor].type == SferaMbcValueTypeBytePointer;
    std::string name;
    std::uint32_t module = 0;
    if (byName)
    {
        const auto slice = nextSliceReference();
        if (slice.base == 0)
        {
            WorldDiagnostics::warning("NULL-pointer dereferencing: ffprc_id\n");
        }
        name = textIn(slice);
    }
    else
    {
        module = nextInteger();
    }
    auto index = process_chain_first;
    if (native_call->count > 1)
    {
        const std::uint32_t previous = nextInteger();
        if (previous >= std::size(processes) || SferaNumeric::word(processes[previous].chain_next_index) == previous)
        {
            pushInteger(-1);
            return;
        }
        index = processes[previous].chain_next_index;
    }
    if (execution_failed)
    {
        return;
    }
    int result = -1;
    for (std::size_t visited = 0; visited < std::size(processes) && index >= 0 && index < std::size(processes); ++visited)
    {
        const auto &process = processes[index];
        if (process.chain_prev_index == -1)
        {
            break;
        }
        if (byName ? name == process.name : module == 0 || process.module_tag == module)
        {
            result = process.process_id;
            break;
        }
        if (process.chain_next_index == index)
        {
            break;
        }
        index = process.chain_next_index;
    }
    pushInteger(result);
}

void SferaMbcRuntime::scriptSimulationTick()
{
    pushInteger(g_sfera_mbc_runtime.simulation_tick);
}

void SferaMbcRuntime::scriptProcessModule()
{
    const std::uint32_t index = nextInteger();
    const bool valid = index < std::size(processes) && processes[index].process_id == index && processes[index].chain_prev_index >= 0;
    if (!execution_failed)
    {
        pushInteger(valid ? processes[index].module_tag : UINT32_MAX);
    }
}

void SferaMbcRuntime::scriptActiveTag()
{
    pushInteger(active_tag);
}

void SferaMbcRuntime::scriptArgumentCount()
{
    pushInteger(native_call->count);
}

void SferaMbcRuntime::scriptCurrentModule()
{
    pushInteger(processes[process_index].module_tag);
}

void SferaMbcRuntime::scriptCurrentProcess()
{
    pushInteger(processes[process_index].process_id);
}

void SferaMbcRuntime::scriptZeroResult()
{
    pushInteger(0);
}

void SferaMbcRuntime::scriptProfileValue()
{
    nextInteger();
    if (!execution_failed)
    {
        pushInteger(0);
    }
}

void SferaMbcRuntime::scriptProcessFlag()
{
    pushInteger(active_process->flags & SferaMbcProcessRecordFlagsunloadAfterExecution);
}

void SferaMbcRuntime::scriptCallerProcess()
{
    pushInteger(native_caller_process);
}

void SferaMbcRuntime::scriptDiscardArgument()
{
    const auto &argument = native_call->arguments[native_call->cursor];
    if (!argument.isPointer() && argument.type == SferaMbcValueTypeReal)
    {
        nextReal();
    }
    else
    {
        nextInteger();
    }
}

void SferaMbcRuntime::scriptStopInterpreter()
{
    if (native_call->count != 1)
    {
        halt_state = SferaMbcRuntimeHaltState::Requested;
    }
    else
    {
        const auto mode = nextInteger();
        if (mode == 0)
        {
            halt_state = SferaMbcRuntimeHaltState::Requested;
        }
        else if (mode == 1 || mode == -1)
        {
            SferaClientApplication::quit_requested = true;
        }
    }
}

void SferaMbcRuntime::scriptInvalidResult()
{
    pushInteger(UINT32_MAX);
}

void SferaMbcRuntime::scriptOpenFile(bool create)
{
    const auto name = nextWord();
    if (name == 0)
    {
        WorldDiagnostics::warning(create ? "NULL-pointer dereferencing: ffcreate\n" : "NULL-pointer dereferencing: ffopen\n");
    }
    if (create && execution_failed)
    {
        return;
    }
    const auto path = textAt(name);
    ::_chmod(path.data(), _S_IREAD | _S_IWRITE);
    if (execution_failed)
    {
        return;
    }
    int flags = _O_BINARY | _O_RDWR;
    int sharing = _SH_DENYNO;
    if (create)
    {
        flags |= _O_CREAT | (native_call->count == 2 ? 0 : _O_TRUNC);
    }
    else if (native_call->count > 1 && nextInteger() == 1)
    {
        flags = _O_BINARY | _O_RDONLY;
    }
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
}

void SferaMbcRuntime::scriptCloseFile()
{
    const auto file = nextInteger();
    if (!execution_failed && file >= 0)
    {
        ::_close(file);
        active_process->unregisterResource(file, SferaMbcRuntimeResourceKind::file);
    }
}

void SferaMbcRuntime::scriptTransferFile(bool reading)
{
    const auto file = nextInteger();
    if (reading && execution_failed)
    {
        return;
    }
    auto &buffer = nextSliceReference();
    const std::uint32_t size = nextInteger();
    if (execution_failed)
    {
        return;
    }
    if (!buffer.contains(size))
    {
        buffer.diagnoseRange(size);
    }
    const auto data = memoryBytes(buffer.base, size);
    if (size == 0)
    {
        pushInteger(0);
        return;
    }
    const auto result = reading ? ::_read(file, data.data(), size) : file < 0 ? 0 : ::_write(file, data.data(), size);
    pushInteger(result);
}

void SferaMbcRuntime::scriptReadLine()
{
    const auto file = nextInteger();
    if (execution_failed)
    {
        return;
    }
    const auto destination = nextAddress();
    if (destination.base == 0)
    {
        WorldDiagnostics::warning("NULL-pointer dereferencing: ffread\n");
    }
    const auto capacity = nextInteger();
    if (execution_failed)
    {
        return;
    }
    if (capacity < 0)
    {
        reportError("Negative line buffer capacity");
        return;
    }
    const auto output = memoryBytes(destination.base, capacity);
    int size = 0;
    // ReadLine has a byte-count ABI: a full buffer is not required to end in NUL.
    while (size < capacity)
    {
        std::uint8_t character;
        if (::_read(file, &character, sizeof(character)) != 1)
        {
            break;
        }
        if (character == '\n' || character == '\0')
        {
            output[size] = 0;
            break;
        }
        output[size++] = character;
    }
    pushInteger(size);
}

void SferaMbcRuntime::scriptLockFile()
{
    const auto file = nextInteger();
    const auto unlock = nextInteger();
    const auto size = nextInteger();
    if (!execution_failed)
    {
        pushInteger(::_locking(file, unlock ? _LK_UNLCK : _LK_NBLCK, size));
    }
}

void SferaMbcRuntime::scriptSeekFile()
{
    const auto file = nextInteger();
    const auto offset = nextInteger();
    const auto origin = nextInteger();
    if (!execution_failed)
    {
        pushInteger(::_lseek(file, offset, origin == 1 ? SEEK_SET : origin == 2 ? SEEK_CUR : SEEK_END));
    }
}

void SferaMbcRuntime::scriptFileSize()
{
    const auto file = nextInteger();
    if (!execution_failed)
    {
        pushInteger(::_filelength(file));
    }
}

void SferaMbcRuntime::scriptFileTime()
{
    const auto file = nextInteger();
    if (!execution_failed)
    {
        struct _stat64i32 status{};
        ::_fstat64i32(file, &status);
        pushInteger(SferaNumeric::lowWord(status.st_mtime));
    }
}

void SferaMbcRuntime::scriptResizeFile()
{
    const auto file = nextInteger();
    const auto size = nextInteger();
    if (!execution_failed)
    {
        ::_chsize_s(file, size);
    }
}

void SferaMbcRuntime::scriptSetFileTime()
{
    const auto file = nextInteger();
    const auto time = nextInteger();
    if (!execution_failed)
    {
        __utimbuf64 times{time, time};
        ::_futime64(file, &times);
    }
}

void SferaMbcRuntime::scriptRemoveFile()
{
    const auto name = nextInteger();
    if (!execution_failed)
    {
        pushInteger(std::remove(textAt(name).data()));
    }
}

void SferaMbcRuntime::scriptRenameFile()
{
    const auto source = nextWord();
    const auto destination = nextWord();
    if (!execution_failed)
    {
        pushInteger(std::rename(textAt(source).data(), textAt(destination).data()));
    }
}

void SferaMbcRuntime::scriptSin()
{
    const double value = nextReal();
    pushReal(std::sin(value));
}

void SferaMbcRuntime::scriptCos()
{
    const double value = nextReal();
    pushReal(std::cos(value));
}

void SferaMbcRuntime::scriptExp()
{
    const double value = nextReal();
    pushReal(std::exp(value));
}

void SferaMbcRuntime::scriptAbsoluteReal()
{
    const double value = nextReal();
    pushReal(value < 0.0 ? -value : value);
}

void SferaMbcRuntime::scriptSquareRoot()
{
    const double value = nextReal();
    pushReal(std::sqrt(value < 0.0 ? -value : value));
}


void SferaMbcRuntime::scriptArcTangent()
{
    const double y = nextReal();
    const double x = nextReal();
    pushReal(std::atan2(y, x));
}

void SferaMbcRuntime::scriptIntegerValue(bool absolute)
{
    const auto value = nextInteger();
    if (absolute && value < 0)
    {
        pushInteger(0u - SferaNumeric::word(value));
    }
    else
    {
        pushInteger(value);
    }
}

void SferaMbcRuntime::scriptRandomReal()
{
    pushReal(std::rand() / 32768.0f);
}

void SferaMbcRuntime::scriptPackColor()
{
    const auto red = nextInteger();
    const auto green = nextInteger();
    const auto blue = nextInteger();
    pushInteger(D3DCOLOR_XRGB(red, green, blue));
}

void SferaMbcRuntime::scriptScaleColor()
{
    const auto color = SferaColor::fromArgb(nextWord());
    const double factor = nextReal();
    const std::uint8_t red = SferaNumeric::lowByte(SferaMbcValue::truncate(color.red() * factor));
    const std::uint8_t green = SferaNumeric::lowByte(SferaMbcValue::truncate(color.green() * factor));
    const std::uint8_t blue = SferaNumeric::lowByte(SferaMbcValue::truncate(color.blue() * factor));
    pushInteger(D3DCOLOR_XRGB(red, green, blue));
}

void SferaMbcRuntime::scriptBitAnd()
{
    const std::uint32_t value = nextInteger();
    const auto argument = nextWord();
    pushInteger(value & argument);
}

void SferaMbcRuntime::scriptBitOr()
{
    const std::uint32_t value = nextInteger();
    const auto argument = nextWord();
    pushInteger(value | argument);
}

void SferaMbcRuntime::scriptBitXor()
{
    const std::uint32_t value = nextInteger();
    const auto argument = nextWord();
    pushInteger(value ^ argument);
}

void SferaMbcRuntime::scriptBitNot()
{
    const std::uint32_t value = nextInteger();
    pushInteger(~value);
}

void SferaMbcRuntime::scriptShiftLeft()
{
    const std::uint32_t value = nextInteger();
    const auto argument = nextWord();
    const auto shift = argument % std::numeric_limits<std::uint32_t>::digits;
    pushInteger(value << shift);
}

void SferaMbcRuntime::scriptShiftRight()
{
    const std::uint32_t value = nextInteger();
    const auto argument = nextWord();
    const auto shift = argument % std::numeric_limits<std::uint32_t>::digits;
    pushInteger(SferaNumeric::signedWord(value) >> shift);
}

void SferaMbcRuntime::scriptClearBit()
{
    const std::uint32_t value = nextInteger();
    const auto argument = nextWord();
    const auto shift = argument % std::numeric_limits<std::uint32_t>::digits;
    pushInteger(value & ~(1u << shift));
}

void SferaMbcRuntime::scriptSetBit()
{
    const std::uint32_t value = nextInteger();
    const auto argument = nextWord();
    const auto shift = argument % std::numeric_limits<std::uint32_t>::digits;
    pushInteger(value | (1u << shift));
}

void SferaMbcRuntime::scriptTestBit()
{
    const std::uint32_t value = nextInteger();
    const auto argument = nextWord();
    const auto shift = argument % std::numeric_limits<std::uint32_t>::digits;
    pushInteger(SferaNumeric::signedWord(value & (1u << shift)) >> shift);
}

void SferaMbcRuntime::calculateDistance()
{
    std::array<double, 3> delta{};
    if (native_call->count == 2)
    {
        auto first = nextSlice();
        auto second = nextSlice();
        if (!first.contains(sizeof(SferaVec3F)))
        {
            first.diagnoseRange(sizeof(SferaVec3F));
        }
        if (!second.contains(sizeof(SferaVec3F)))
        {
            second.diagnoseRange(sizeof(SferaVec3F));
        }
        if (execution_failed)
        {
            return;
        }
        const auto a = readMemory<SferaVec3F>(first.base);
        const auto b = readMemory<SferaVec3F>(second.base);
        const double ax = a.x;
        const double ay = a.y;
        const double az = a.z;
        delta = {ax - b.x, ay - b.y, az - b.z};
    }
    else
    {
        const auto dimensions = native_call->count == 4 || native_call->count == 5 ? 2u : 3u;
        std::array<float, 3> first{}, second{};
        for (std::uint32_t index = 0; index < dimensions; ++index)
        {
            first[index] = nextReal();
        }
        for (std::uint32_t index = 0; index < dimensions; ++index)
        {
            second[index] = nextReal();
        }
        for (std::uint32_t index = 0; index < dimensions; ++index)
        {
            const double value = first[index];
            delta[index] = value - second[index];
        }
    }
    const float square = SferaNumeric::real32(delta[1] * delta[1] + delta[0] * delta[0] + delta[2] * delta[2]);
    pushReal(native_call->count == 2 || native_call->count == 4 || native_call->count == 6 ? std::sqrt(square) : square);
}

void SferaMbcRuntime::scriptAllocateMemory()
{
    const auto size = nextInteger();
    if (execution_failed)
    {
        return;
    }
    if (size <= 0)
    {
        pushInteger(0);
    }
    else
    {
        const auto offset = active_process->growMemory(size);
        pushSlice({offset, offset, offset + size - 1}, SferaMbcValueTypeBytePointer);
    }
}

void SferaMbcRuntime::scriptDynamicArray(bool allocate)
{
    const auto reference = nextSliceReference();
    const auto size = allocate ? nextInteger() : 0;
    if (execution_failed)
    {
        return;
    }
    if (!reference.contains(SferaSliceReference32::scriptWidth))
    {
        reportError("Dynamic array reference outside slice");
        return;
    }
    // Validate the entire lvalue before creating or destroying any allocation.
    const auto previous = readMemory<SferaSliceReference32>(reference.base);
    if (allocate)
    {
        const auto offset = size > 0 ? allocateDynamic(size) : 0u;
        try
        {
            if (offset != 0)
            {
                active_process->registerResource(reference.base, SferaMbcRuntimeResourceKind::dynamicArray);
            }
        }
        catch (...)
        {
            releaseDynamic(offset);
            throw;
        }
        const SferaSliceReference32 replacement{offset, offset, offset == 0 ? 0u : offset + size - 1u};
        writeMemory(reference.base, ownReference(replacement));
        // Replacement is transactional; an old owned allocation cannot leak.
        if (previous.base != 0)
        {
            releaseDynamic(previous.base);
        }
        if (offset == 0)
        {
            active_process->unregisterResource(reference.base, SferaMbcRuntimeResourceKind::dynamicArray);
        }
    }
    else if (previous.base != 0)
    {
        if (!releaseDynamic(previous.base))
        {
            reportError("Dynamic array does not own this address");
            return;
        }
        const SferaSliceReference32 empty{};
        writeMemory(reference.base, empty);
        active_process->unregisterResource(reference.base, SferaMbcRuntimeResourceKind::dynamicArray);
    }
}

void SferaMbcRuntime::scriptNamedValue(bool writing)
{
    const auto name = nextInteger();
    const auto value = writing ? nextWord() : 0u;
    const auto index = native_call->count > (writing ? 2 : 1) ? nextInteger() : 0;
    const auto text = textAt(name);
    if (writing)
    {
        setNamedValue(text, value, index);
    }
    else
    {
        pushInteger(namedValue(text, index));
    }
}


void SferaMbcRuntime::scriptCopyProcess(bool rawMemory)
{
    const std::uint32_t destinationProcess = nextInteger();
    auto &destination = nextSliceReference();
    if (destination.base == 0)
    {
        ::OutputDebugStringA("NULL-pointer dereferencing: ffmempcpy\n");
        return;
    }
    const std::uint32_t sourceProcess = nextInteger();
    const auto &source = nextSliceReference();
    const auto count = rawMemory || native_call->count == 5 ? nextInteger() : 0;
    if (execution_failed)
    {
        return;
    }
    auto *target = findProcess(destinationProcess);
    auto *origin = findProcess(sourceProcess);
    if (target == nullptr || origin == nullptr)
    {
        active_tag = UINT32_MAX;
        pushInteger(UINT32_MAX);
        return;
    }
    if (rawMemory)
    {
        if (count < 0)
        {
            reportError("Negative process copy length");
            return;
        }
        const auto input = memoryBytes(source.base, count, origin);
        if (!destination.contains(count))
        {
            destination.diagnoseRange(count);
        }
        const auto output = memoryBytes(destination.base, count, target);
        SferaBinary::copy(output, input);
    }
    else
    {
        const auto text = textIn(source, origin);
        copyString(textBuffer(destination, target), text, count);
    }
}

void SferaMbcRuntime::scriptMemoryChecksum()
{
    nextInteger();
    auto &slice = nextSliceReference();
    const std::uint32_t size = nextInteger();
    if (execution_failed)
    {
        return;
    }
    if (!slice.contains(size))
    {
        slice.diagnoseRange(size);
    }
    pushInteger(0);
}

void SferaMbcRuntime::scriptCompareMemory()
{
    const auto left = nextSlice();
    if (left.base == 0)
    {
        reportError("poppointerup(): unexpected NULL-pointer fetched");
    }
    const auto right = nextSlice();
    if (right.base == 0)
    {
        reportError("poppointerup(): unexpected NULL-pointer fetched");
    }
    const std::uint32_t size = nextInteger();
    if (!execution_failed)
    {
        const auto result = size == 0 ? 0 : std::memcmp(memoryBytes(left.base, size).data(), memoryBytes(right.base, size).data(), size);
        pushInteger((result > 0) - (result < 0));
    }
}




void SferaMbcRuntime::scriptTransferString(bool writing)
{
    auto cursor = nextSliceReference();
    auto &argument = nextSliceReference();
    auto &source = writing ? argument : cursor;
    auto &destination = writing ? cursor : argument;
    if (!source.contains())
    {
        source.diagnoseRange(0);
        return;
    }
    if (execution_failed)
    {
        return;
    }
    const auto input = textIn(source);
    if (input.size() >= UINT32_MAX)
    {
        reportError("String exceeds the MBC address range");
        return;
    }
    const std::uint32_t length = SferaNumeric::lowWord(input.size() + 1u);
    copyText(destination, input);
    if (!cursor.contains(length))
    {
        cursor.diagnoseRange(length);
    }
    else
    {
        cursor.base += length;
    }
    pushSlice(cursor, SferaMbcValueTypeBytePointer);
}

void SferaMbcRuntime::scriptLowerBoundInteger()
{
    auto dataSlice = nextSlice();
    const auto count = nextInteger();
    const auto key = nextInteger();
    if (execution_failed)
    {
        return;
    }
    const auto length = SferaNumeric::word(count) * sizeof(int);
    if (!dataSlice.contains(SferaNumeric::lowWord(length)))
    {
        dataSlice.diagnoseRange(SferaNumeric::lowWord(length));
    }
    if (count < 0)
    {
        pushInteger(UINT32_MAX);
        return;
    }
    int begin = 0, end = count - 1;
    while (begin < end)
    {
        const auto middle = begin + (end - begin) / 2;
        if (readMemory<int>(dataSlice.base + middle * sizeof(int)) < key)
        {
            begin = middle + 1;
        }
        else
        {
            end = middle;
        }
    }
    pushInteger(begin);
}

void SferaMbcRuntime::scriptConnect()
{
    const auto host = nextSliceReference().base;
    nextSliceReference();
    const auto mode = native_call->count > 2 ? nextWord() : 3u;
    pushInteger(g_sfera_network_runtime.initialize(std::string(textAt(host)), mode));
}

void SferaMbcRuntime::scriptDisconnect()
{
    g_sfera_network_runtime.shutdown();
}

void SferaMbcRuntime::scriptTickDifference()
{
    const std::uint32_t first = nextInteger();
    const std::uint32_t second = nextInteger();
    pushInteger(SferaNetworkRuntime::tickDifference(first, second));
}

void SferaMbcRuntime::scriptNetworkInitialization()
{
    pushInteger(g_sfera_network_runtime.initialization_result);
}

auto SferaMbcRuntime::playerListName(int offset)
{
    return textAt(offset, 149);
}

auto SferaMbcRuntime::findPlayerList(PlayerLists &manager, int offset)
{
    return manager.find(playerListName(offset));
}

auto SferaMbcRuntime::copyPlayerListName(std::uint32_t address, std::string_view value)
{
    auto *output = memoryAt(address, value.size() + 1);
    std::copy(value.begin(), value.end(), output);
    output[value.size()] = 0;
}

void SferaMbcRuntime::scriptPlayerLists()
{
    const auto command = nextInteger();
    if (command < 1 || command > 11)
    {
        return;
    }
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
        {
            pushInteger(manager.create(playerListName(listName), minimum, mode, parameter != 0));
        }
        break;
    }
    case 2:
    {
        const auto listName = nextInteger();
        if (!execution_failed)
        {
            pushInteger(manager.erase(playerListName(listName)));
        }
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
        {
            break;
        }
        auto *list = findPlayerList(manager, listName);
        if (list == nullptr)
        {
            pushInteger(-1);
            break;
        }
        PlayerListEntry item;
        item.name = playerListName(itemName);
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
        {
            break;
        }
        auto *list = findPlayerList(manager, listName);
        if (list == nullptr)
        {
            pushInteger(-1);
            break;
        }
        pushInteger(manager.removeItem(*list, playerListName(itemName)));
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
        {
            break;
        }
        auto *current = command == 6 ? manager.currentList() : manager.selectList(playerListName(first));
        const auto nameOutput = command == 6 ? first : second;
        if (current == nullptr)
        {
            if (command != 7)
            {
                copyPlayerListName(nameOutput, {});
            }
            pushInteger(-1);
            break;
        }
        auto *item = command == 7 ? current->find(playerListName(second)) : command == 5 ? current->first() : current->next();
        if (item == nullptr)
        {
            if (command != 7)
            {
                copyPlayerListName(nameOutput, {});
            }
            pushInteger(-2);
            break;
        }
        if (command != 7)
        {
            copyPlayerListName(nameOutput, item->name);
        }
        writeMemory(fields[0], item->attributes[0]);
        writeMemory(fields[1], item->attributes[1]);
        writeMemory(fields[2], item->attributes[2]);
        if (command != 7)
        {
            writeMemory(fields[3], SferaNumeric::lowWord(item->payload.size()));
        }
        if (payload != 0 && !item->payload.empty())
        {
            std::copy(item->payload.begin(), item->payload.end(), memoryAt(payload, item->payload.size()));
        }
        if (command == 7)
        {
            if (fields[3] == 0)
            {
                WorldDiagnostics::warning("NULL-pointer dereferencing: list, L_FINDITEM, 4\n");
            }
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
        {
            break;
        }
        auto *list = findPlayerList(manager, listName);
        const auto *item = list == nullptr ? nullptr : list->select({a, b, c});
        copyPlayerListName(output, item == nullptr ? std::string_view{} : item->name);
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
        {
            break;
        }
        auto *list = findPlayerList(manager, listName);
        if (list == nullptr)
        {
            pushInteger(-1);
            break;
        }
        auto *item = list->find(playerListName(itemName));
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
        {
            break;
        }
        auto *list = manager.selectList(playerListName(listName));
        if (list == nullptr)
        {
            pushInteger(-2);
            break;
        }
        const auto *item = list->find(playerListName(itemName));
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
}


void SferaMbcRuntime::scriptFindString(bool sensitive)
{
    auto &haystack = nextSliceReference();
    const auto needle = nextSliceReference();
    if (execution_failed)
    {
        return;
    }
    const auto text = textIn(haystack);
    const auto match = textIn(needle);
    const auto found = sensitive ? text.find(match) : SferaText::findInsensitive(text, match);
    if (found == std::string_view::npos)
    {
        pushSlice({}, SferaMbcValueTypeBytePointer);
    }
    else
    {
        haystack.base += SferaNumeric::lowWord(found);
        pushSlice(haystack, SferaMbcValueTypeBytePointer);
    }
}


bool SferaMbcRuntime::activeEffectMatches(const SferaActiveEffect *created, const std::shared_ptr<SferaActiveEffect> &item)
{
    return item.get() == created;
}

void SferaMbcRuntime::scriptMouseMotion()
{
    const auto x = nextInteger();
    const auto y = nextInteger();
    if (!execution_failed)
    {
        pushInteger(x == -2 && y == -2 ? g_sfera_direct_input_runtime.mouse.wheel : x == -1 ? g_sfera_direct_input_runtime.mouse.dx : y == -1 ? g_sfera_direct_input_runtime.mouse.dy : 0);
    }
}

void SferaMbcRuntime::scriptFontSettings()
{
    const auto &suffix = g_sfera_font_runtime.language_suffix;
    const auto offset = mapMemory(suffix.c_str(), suffix.size() + 1);
    pushSlice({offset, offset, offset + SferaNumeric::lowWord(suffix.size())}, SferaMbcValueTypeBytePointer);
}

void SferaMbcRuntime::scriptDestroyResource(SferaMbcRuntimeResourceKind kind)
{
    const auto handle = nextInteger();
    if (execution_failed)
    {
        return;
    }
    if ((kind == SferaMbcRuntimeResourceKind::worldObject))
    {
        if (handle != -1)
        {
            g_sfera_world_objects.destroy(handle);
        }
    }
    else if (handle >= 0)
    {
        if ((kind == SferaMbcRuntimeResourceKind::textControl))
        {
            WorldGuiControls::destroyText(handle);
        }
        else
        {
            WorldGuiControls::destroySprite(handle);
        }
    }
    active_process->unregisterResource(handle, kind);
}

void SferaMbcRuntime::scriptSetRenderEnabled()
{
    const auto handle = nextInteger();
    if (handle < 0)
    {
        return;
    }
    const auto enabled = nextInteger();
    if (!execution_failed)
    {
        SphereRenderCharacterModels::checkedExtended(g_sfera_world_objects.object(handle, "GetObjectPointer"))->render_enabled = enabled != 0;
    }
}

void SferaMbcRuntime::scriptCreateObject()
{
    const auto name = nextInteger();
    const std::uint32_t kind = nextInteger();
    const auto independent = native_call->count > 2 ? nextInteger() : 0;
    if (execution_failed)
    {
        return;
    }
    static constexpr std::array<std::uint32_t, 11> factories{0, 1, 2, 3, 1, 4, 5, 6, 4, 5, 3};
    const auto factory = kind < factories.size() ? factories[kind] : 0;
    const auto filename = textAt(name);
    const auto handle = g_sfera_world_objects.create(filename, independent == 1 ? nullptr : active_process, factory, independent != 1);
    pushInteger(handle);
    if (SferaNumeric::signedWord(handle) < 0)
    {
        reportError(std::format("Error creating object: {}", filename));
        execution_failed = false;
        return;
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
}

void SferaMbcRuntime::scriptText()
{
    const auto create = native_call->arguments[native_call->cursor].type == SferaMbcValueTypeBytePointer;
    const auto first = nextWord();
    if (!create)
    {
        const auto color = nextInteger();
        const auto style = nextInteger();
        const auto font = nextInteger();
        const auto scale = SferaMbcValue::truncate(nextReal());
        if (execution_failed)
        {
            return;
        }
        auto *window = GameInterface::window(first, "GetWindowPointer");
        if (window == nullptr)
        {
            reportError("Wrong parameters for 'text' function");
            return;
        }
        window->textColor = color;
        window->textStyle = style;
        window->font = font;
        window->fontScale = scale;
        return;
    }
    const auto parent = nextWord();
    const auto x = nextInteger();
    const auto y = nextInteger();
    if (native_call->count >= 8)
    {
        auto *window = GameInterface::window(parent, "GetWindowPointer");
        if (window == nullptr)
        {
            reportError("Wrong parameters for 'text' function");
            return;
        }
        window->textColor = nextInteger();
        window->textStyle = nextInteger();
        window->font = nextInteger();
        window->fontScale = SferaMbcValue::truncate(nextReal());
    }
    if (native_call->count == 9)
    {
        nextInteger();
    }
    if (execution_failed)
    {
        return;
    }
    const auto text = textAt(first);
    const auto length = text.size();
    if (length >= text_capacity)
    {
        reportError("Script text exceeds text buffer capacity");
        return;
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
}

void SferaMbcRuntime::scriptTextColor()
{
    const auto handle = nextInteger();
    const auto color = nextInteger();
    if (native_call->count == 3)
    {
        const auto alpha = nextInteger();
        if (!execution_failed)
        {
            WorldGuiControls::setAppearance(handle, alpha, color);
        }
    }
    else if (!execution_failed)
    {
        auto *control = WorldGuiControls::control(handle);
        if (control == nullptr)
        {
            WorldDiagnostics::fail("text_color: wrong handle");
        }
        control->color = color;
    }
}

void SferaMbcRuntime::scriptSprite()
{
    const auto texture = nextInteger();
    const auto parent = nextInteger();
    if (native_call->count == 2)
    {
        WorldGuiControls::setAppearance(texture, parent);
        pushInteger(0);
        return;
    }
    const auto x = nextInteger();
    const auto y = nextInteger();
    const auto width = nextInteger();
    const auto height = nextInteger();
    const auto alpha = native_call->count > 6 ? nextInteger() : std::numeric_limits<std::uint8_t>::max();
    if (native_call->count > 7)
    {
        nextInteger();
    }
    if (native_call->count > 8)
    {
        nextInteger();
    }
    if (native_call->count > 9)
    {
        nextInteger();
        nextInteger();
    }
    if (execution_failed)
    {
        return;
    }
    const auto handle = WorldGuiControls::createSprite(x, y, width, height, textAt(texture), parent, alpha);
    if (handle < 0)
    {
        reportError("Error creating sprite");
    }
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
}

void SferaMbcRuntime::scriptEffect()
{
    if (g_sfera_effect_manager.diagnostics.enabled)
    {
        ++g_sfera_effect_manager.diagnostics.vm_requests;
    }
    const auto handle = nextInteger();
    const auto effect = nextWord();
    const auto parameter = native_call->count >= 3 ? nextWord() : 0u;
    if (native_call->count == 4)
    {
        nextInteger();
    }
    if (execution_failed)
    {
        return;
    }
    SferaActiveEffect *created = nullptr;
    if (native_call->count == 4)
    {
        if (handle == 0)
        {
            reportError("Effect attached to zero handle!", "");
        }
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
            return;
        }
        if (native_call->count >= 3 && parameter != 0)
        {
            SferaEffectParameter value;
            switch (effect)
            {
            case 1:
            {
                const auto *bytes = memoryAt(parameter, 6);
                SferaEffectParameterColor rgb;
                for (std::size_t channel = 0; channel < rgb.channels.size(); ++channel)
                {
                    rgb.channels[channel] = SferaBinary::readLittleEndian<std::uint16_t>(bytes + channel * 2);
                }
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
            {
                pushInteger(g_sfera_effect_manager.setEffectParameters(handle, {&value, 1}));
            }
            return;
        }
        if (native_call->count >= 3 && SferaNumeric::word(handle) == g_sfera_world_objects.controlled_object_handle)
        {
            pushInteger(UINT32_MAX);
            return;
        }
        created = g_sfera_effect_manager.createActiveEffect(effect, handle);
    }
    if (created == nullptr)
    {
        pushInteger(UINT32_MAX);
        return;
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
}

void SferaMbcRuntime::scriptSceneContext()
{
    if (native_call->count == 0)
    {
        pushInteger(g_sfera_direct_input_runtime.virtual_key);
    }
    const auto kind = nextInteger();
    pushInteger(kind == 0 ? g_sfera_direct_input_runtime.virtual_key : kind == 1 ? g_sfera_direct_input_runtime.character : g_sfera_direct_input_runtime.scan_code);
}

void SferaMbcRuntime::scriptKeyboardState()
{
    const std::uint32_t key = nextInteger();
    pushInteger(SferaClientApplication::application_active && key < std::size(g_sfera_direct_input_runtime.keyboard_state)
                    ? SferaNumeric::signedByte(g_sfera_direct_input_runtime.keyboard_state[key])
                    : 0);
}

void SferaMbcRuntime::scriptAnimationValue(bool animation)
{
    const auto handle = nextInteger();
    const auto value = nextInteger();
    const bool secondary = native_call->count > 2 && nextInteger() != 0;
    if (native_call->count <= 2 && execution_failed)
    {
        return;
    }
    auto *field = animation ? (secondary ? SphereRenderModelPose::secondaryAnimation(handle) : SphereRenderModelPose::animation(handle))
                                                                  : (secondary ? SphereRenderModelPose::secondaryFrame(handle) : SphereRenderModelPose::frame(handle));
    if (field != nullptr)
    {
        *field = value;
    }
}

void SferaMbcRuntime::scriptAnimationLength()
{
    const auto handle = nextInteger();
    const auto animation = nextInteger();
    if (!execution_failed)
    {
        pushInteger(SphereRenderModelPose::animationLength(handle, animation));
    }
}

void SferaMbcRuntime::scriptSetInterpolation()
{
    const auto handle = nextInteger();
    const auto value = nextReal();
    if (!execution_failed)
    {
        auto *field = SphereRenderModelPose::interpolation(handle);
        if (field != nullptr)
        {
            *field = value;
        }
    }
}

void SferaMbcRuntime::scriptObjectProcess()
{
    const auto handle = nextInteger();
    if (execution_failed)
    {
        return;
    }
    const auto *object = handle >= 0 ? g_sfera_world_objects.object(handle, "GetProcess") : nullptr;
    const auto *owner = object != nullptr ? WorldObjects::boundProcess(*object) : nullptr;
    pushInteger(owner != nullptr ? owner->process_id : UINT32_MAX);
}

void SferaMbcRuntime::scriptWorldPosition(bool absolute)
{
    const auto handle = nextInteger();
    if (handle < 0)
    {
        return;
    }
    SferaVec3F position;
    position.x = nextReal();
    position.y = nextReal();
    position.z = nextReal();
    auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
    if (object == nullptr)
    {
        active_tag = UINT32_MAX;
        return;
    }
    if (execution_failed)
    {
        return;
    }
    if (absolute)
    {
        object->position = position;
    }
    else
    {
        object->position = object->position + position;
    }
    if (SferaNumeric::word(handle) == g_sfera_world_objects.controlled_object_handle)
    {
        g_sfera_motion.tracked_position.x = object->position.x + 333.0f;
        g_sfera_motion.tracked_position.y = object->position.y + 333.0f;
        g_sfera_motion.tracked_position.z = object->position.z + 333.0f;
    }
    if (absolute && native_call->count >= 5)
    {
        g_sfera_world_objects.updateSpatialIndex(handle);
        if (native_call->count == 6)
        {
            nextInteger();
            object->spatial_membership = nextInteger();
        }
    }
}

void SferaMbcRuntime::scriptCommandVelocity()
{
    const auto handle = nextInteger();
    if (handle < 0)
    {
        return;
    }
    const auto x = nextReal();
    const auto second = nextReal();
    auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
    if (object == nullptr)
    {
        active_tag = UINT32_MAX;
        return;
    }
    if (execution_failed)
    {
        return;
    }
    auto *extended = SphereRenderCharacterModels::checkedExtended(object);
    extended->commanded_velocity.x = x;
    if (native_call->count == 4)
    {
        const auto z = nextReal();
        extended->commanded_velocity.y = second;
        extended->commanded_velocity.z = z;
    }
    else
    {
        extended->commanded_velocity.z = second;
    }
}

void SferaMbcRuntime::scriptObjectVelocity(bool vertical)
{
    const auto handle = nextInteger();
    if (handle < 0)
    {
        return;
    }
    float value = 0;
    if (!vertical)
    {
        value = nextReal();
    }
    auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
    if (object == nullptr)
    {
        active_tag = UINT32_MAX;
        return;
    }
    if (vertical)
    {
        value = native_call->count == 3 ? g_sfera_motion.responseValue(nextInteger()) : nextReal();
    }
    if (!execution_failed)
    {
        auto *extended = SphereRenderCharacterModels::checkedExtended(object);
        if (vertical)
        {
            extended->physical_velocity.y = value;
        }
        else
        {
            extended->angular_velocity = value;
        }
    }
}

void SferaMbcRuntime::scriptAirborne()
{
    const auto handle = nextInteger();
    if (handle < 0)
    {
        pushInteger(0);
        return;
    }
    auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
    if (object == nullptr)
    {
        active_tag = UINT32_MAX;
        return;
    }
    if (execution_failed)
    {
        return;
    }
    const auto command = nextInteger();
    auto *extended = SphereRenderCharacterModels::checkedExtended(object);
    if (command == -1)
    {
        pushInteger(extended->airborne);
    }
    else
    {
        extended->airborne = true;
        pushInteger(0);
    }
}

void SferaMbcRuntime::scriptEditorPick()
{
    if (nextInteger() != 0)
    {
        return;
    }
    const auto distance = nextInteger();
    const auto position = nextInteger();
    if (!execution_failed)
    {
        if (distance != 0)
        {
            writeMemory(distance, 0.0f);
        }
        if (position != 0)
        {
            writeMemory(position, SferaVec3F{});
        }
        pushInteger(UINT32_MAX);
    }
}

void SferaMbcRuntime::scriptMovementContact()
{
    const auto handle = nextInteger();
    if (handle < 0)
    {
        pushInteger(0);
        return;
    }
    std::uint32_t result = 0, direction = 0, depth = 0;
    if (native_call->count == 5)
    {
        result = nextInteger();
        direction = nextInteger();
        depth = nextInteger();
        nextInteger();
    }
    if (execution_failed)
    {
        return;
    }
    if (native_call->count <= 1)
    {
        pushInteger(g_sfera_contacts.testMovement(handle, false));
        return;
    }
    auto *object = g_sfera_world_objects.object(handle, "GetObjectPointer");
    g_sfera_mbc_runtime.current_object = object;
    if (object == nullptr)
    {
        active_tag = UINT32_MAX;
        return;
    }
    auto *extended = SphereRenderCharacterModels::checkedExtended(object);
    pushInteger(extended->movement_blocked ? 0 : UINT32_MAX);
    extended->movement_blocked = false;
    if (native_call->count == 5)
    {
        const std::uint32_t avoidance_enabled = extended->avoidance_enabled;
        writeMemory(result, avoidance_enabled);
        if (extended->avoidance_enabled)
        {
            if (direction != 0)
            {
                writeMemory(direction, extended->avoidance_direction);
            }
            if (depth != 0)
            {
                writeMemory(depth, extended->avoidance_depth);
            }
        }
    }
}

void SferaMbcRuntime::scriptObjectComponent(bool position, std::size_t axis)
{
    const auto handle = nextInteger();
    const auto *object = g_sfera_world_objects.object(handle, position ? "GetPos" : "GetAngles");
    if (object == nullptr)
    {
        pushReal(0.0f);
        return;
    }
    if (!position || !execution_failed)
    {
        pushReal((position ? object->position : object->rotation).component(axis));
    }
}

void SferaMbcRuntime::scriptObjectTransform(bool absoluteRotation, bool forwardOnly, bool rotate)
{
    const auto handle = nextInteger();
    if (absoluteRotation && handle < 0)
    {
        return;
    }
    SferaVec3F value{};
    if (forwardOnly)
    {
        value.z = nextReal();
    }
    else
    {
        value.x = nextReal();
        value.y = nextReal();
        value.z = nextReal();
    }
    if (absoluteRotation)
    {
        auto *object = g_sfera_world_objects.object(handle, "GetObjectPointer");
        if (object == nullptr)
        {
            active_tag = UINT32_MAX;
        }
        else if (!execution_failed)
        {
            object->rotation = value;
        }
    }
    else if (!execution_failed)
    {
        if (rotate)
        {
            g_sfera_world_objects.rotate(handle, value);
        }
        else
        {
            g_sfera_world_objects.moveLocal(handle, value);
        }
    }
}

