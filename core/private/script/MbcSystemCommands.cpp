#include <windows.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <format>
#include <functional>
#include <io.h>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "application/ClientApplication.h"
#include "audio/GameAudio.h"
#include "binary/Binary.h"
#include "camera/Camera.h"
#include "chat/ChatFilter.h"
#include "diagnostics/ClientDiagnostics.h"
#include "effects/ActiveEffect.h"
#include "effects/EffectManager.h"
#include "gameplay/ActorMotion.h"
#include "input/Cursors.h"
#include "input/DirectInputDevices.h"
#include "math/Vector.h"
#include "network/Network.h"
#include "numeric/Numeric.h"
#include "render/CharacterRenderer.h"
#include "render/GraphicsRuntime.h"
#include "render/SceneRenderer.h"
#include "resources/FileResources.h"
#include "resources/TextureRepository.h"
#include "runtime/Clock.h"
#include "scene/SceneObject.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "script/MbcValue.h"
#include "text/Text.h"
#include "text/TextBuffer.h"
#include "ui/GameInterfaceManager.h"
#include "ui/ScriptInterface.h"
#include "ui/Window.h"
#include "world/GameCalendar.h"
#include "world/WorldObjects.h"

std::uint32_t SferaMbcRuntime::systemCommandAddress(std::string_view name)
{
    const std::uint32_t offset = nextInteger();
    if (offset == 0)
        ::OutputDebugStringA(std::format("NULL-pointer dereferencing: ffsys, {}\n", name).c_str());
    return offset;
}

std::string SferaMbcRuntime::systemCommandText(std::uint32_t offset)
{
    return textAt(offset);
}

void SferaMbcRuntime::systemCommand()
{
    const auto operation = nextInteger();

    switch (operation)
    {
    case 0:
    case 1:
    case 3:
    case 38:
    case 4:
    case 10:
    case 29:
    case 32:
    case 36:
    case 41:
    case 44:
    case 45:
    case 46:
    case 47:
    case 59:
    case 65:
    case 78:
    case 80:
    case 81:
    case 84:
    case 87:
    case 88:
    case 89:
    case 94:
    case 96:
    case 98:
    case 99:
    case 100:
    case 119:
    case 224:
    case 230:
    case 231:
        executeSystemWorld(operation);
        return;
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 53:
    case 57:
    case 58:
    case 107:
    case 131:
    case 225:
    case 226:
        executeSystemEnvironment(operation);
        return;
    case 11:
    case 14:
    case 18:
    case 33:
    case 34:
    case 37:
    case 35:
    case 39:
    case 152:
    case 212:
    case 213:
    case 214:
    case 218:
    case 219:
    case 220:
    case 221:
        executeSystemInterface(operation);
        return;
    case 12:
    case 22:
    case 24:
    case 25:
    case 26:
    case 27:
    case 43:
    case 60:
    case 61:
    case 77:
    case 86:
    case 103:
    case 140:
    case 150:
    case 508:
    case 509:
    case 510:
        executeSystemRuntime(operation);
        return;
    case 19:
    case 20:
    case 21:
    case 64:
    case 66:
    case 67:
    case 68:
    case 73:
    case 75:
    case 92:
    case 113:
    case 115:
    case 116:
    case 120:
    case 136:
        executeSystemResources(operation);
        return;
    case 23:
    case 28:
    case 63:
    case 69:
    case 70:
    case 71:
    case 72:
    case 74:
    case 79:
    case 82:
    case 83:
    case 85:
    case 93:
    case 95:
    case 106:
    case 109:
    case 110:
    case 111:
    case 112:
    case 114:
    case 132:
    case 133:
    case 134:
    case 138:
    case 206:
    case 207:
    case 215:
    case 216:
        executeSystemCompatibility(operation);
        return;
    case 121:
    case 122:
    case 123:
    case 124:
    case 127:
    case 125:
    case 128:
    case 126:
    case 227:
    case 228:
    case 229:
        executeSystemValues(operation);
        return;
    default:
        return;
    }
}

void SferaMbcRuntime::executeSystemCompatibility(std::int32_t operation)
{
    switch (operation)
    {
    case 23:
        nextInteger();
        return;
    case 28:
        pushInteger(0u);
        return;
    case 63:
        nextInteger();
        nextReal();
        return;
    case 69:
        nextInteger();
        return;
    case 70:
    {
        nextInteger();
        const auto x = nextInteger();
        const auto y = nextInteger();
        if (!execution_failed)
        {
            if (x != 0)
                writeMemory(x, std::uint8_t{});
            if (y != 0)
                writeMemory(y, std::uint8_t{});
        }
        return;
    }
    case 71:
        nextInteger();
        nextInteger();
        return;
    case 72:
        nextInteger();
        nextInteger();
        return;
    case 74:
        nextInteger();
        nextInteger();
        nextInteger();
        return;
    case 79:
        nextInteger();
        nextInteger();
        return;
    case 82:
        nextInteger();
        return;
    case 83:
        nextInteger();
        nextInteger();
        nextInteger();
        if (!execution_failed)
            pushInteger(UINT32_MAX);
        return;
    case 85:
    {
        nextInteger();
        nextInteger();
        nextInteger();
        if (!execution_failed)
            pushInteger(0);
        return;
    }
    case 93:
        nextInteger();
        return;
    case 95:
        nextReal();
        nextReal();
        if (!execution_failed)
            pushInteger(0);
        return;
    case 106:
    {
        nextSlice();
        nextInteger();
        nextInteger();
        return;
    }
    case 109:
        nextInteger();
        nextInteger();
        return;
    case 110:
    {
        nextInteger();
        const auto count_address = nextInteger();
        nextInteger();
        const auto status_address = nextInteger();
        if (execution_failed)
            return;
        if (count_address != 0)
            writeMemory(count_address, int{0});
        if (status_address != 0)
            writeMemory(status_address, int{1});
        return;
    }
    case 111:
        return;
    case 112:
        pushInteger(1);
        return;
    case 114:
        pushInteger(0);
        return;
    case 132:
        nextInteger();
        pushInteger(0);
        return;
    case 133:
    case 134:
    case 138:
        pushInteger(0);
        return;
    case 206:
        pushInteger(0);
        return;
    case 207:
        pushInteger(0);
        return;
    case 215:
        nextInteger();
        if (!execution_failed)
            pushInteger(0);
        return;
    case 216:
        nextInteger();
        nextInteger();
        if (!execution_failed)
            pushInteger(0);
        return;
    default:
        return;
    }
}

void SferaMbcRuntime::executeSystemEnvironment(std::int32_t operation)
{
    switch (operation)
    {
    case 2:
        g_sfera_graphics_runtime.environment_factor = nextReal();
        return;
    case 5:
        g_sfera_mbc_runtime.game_calendar = nextInteger();
        return;
    case 6:
        pushInteger(g_sfera_mbc_runtime.game_calendar);
        return;
    case 7:
    {
        float fraction = 0;
        if (argument_count > 1)
        {
            const float numerator = SferaNumeric::real32(nextInteger());
            const auto denominator = nextInteger();
            const double precise_numerator = numerator;
            fraction = SferaNumeric::real32(precise_numerator / denominator);
        }
        const auto calendar = g_sfera_mbc_runtime.game_calendar;
        const auto ticks = (((calendar >> 8) & 31) * 60 + ((calendar >> 2) & 63)) * 4 + (calendar & 3);
        const double precise_ticks = ticks;
        const float factor = SferaNumeric::real32(0.9994999766349792 - (precise_ticks + fraction) / 5760.0);
        g_sfera_graphics_runtime.environment_factor = factor < 0 ? 0 : factor;
        return;
    }
    case 8:
        g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::advance(g_sfera_mbc_runtime.game_calendar);
        return;
    case 9:
        pushInteger(SferaGameCalendar::component(g_sfera_mbc_runtime.game_calendar, nextInteger()));
        return;
    case 53:
        pushInteger(WorldClock::calendarTicks());
        return;
    case 57:
    {
        const auto component = nextInteger();
        const auto timestamp = ::_time64(nullptr);
        tm local{};
        ::_localtime64_s(&local, &timestamp);
        switch (component)
        {
        case 0:
            pushInteger(local.tm_hour);
            return;
        case 1:
            pushInteger(local.tm_mday);
            return;
        case 2:
            pushInteger(local.tm_mon);
            return;
        case 3:
            pushInteger(local.tm_year);
            return;
        case 4:
            pushInteger(local.tm_wday);
            return;
        case 5:
            pushInteger(local.tm_min);
            return;
        case 7:
            pushInteger(SferaNumeric::lowWord(WorldClock::nowTicks()));
            return;
        case 8:
        {
            const auto source = nextSlice();
            if (source.base != 0 && !execution_failed)
            {
                auto value = readMemory<tm>(source.base);
                pushInteger(SferaNumeric::lowWord(::_mktime64(&value)));
                writeMemory(source.base, value);
            }
            return;
        }
        case 9:
        {
            const __time64_t first = nextInteger();
            const __time64_t second = nextInteger();
            pushInteger(SferaNumeric::truncateInt(::_difftime64(first, second)));
            return;
        }
        default:
            pushInteger(SferaNumeric::lowWord(timestamp));
            return;
        }
    }
    case 58:
    {
        const auto component = nextInteger();
        const auto value = nextInteger();
        if (!execution_failed)
            g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::withComponent(g_sfera_mbc_runtime.game_calendar, component, value);
        return;
    }
    case 107:
    {
        const auto enabled = nextInteger() != 0;
        if (!execution_failed)
            SphereRenderSceneRenderer::use_default_environment = enabled;
        return;
    }
    case 131:
    {
        const auto destination = nextWord();
        if (execution_failed)
            return;
        SYSTEMTIME time{};
        ::GetLocalTime(&time);
        std::string date;
        date = std::format("{}-{:02d}-{:02d} {:02d}:{:02d}:{:02d}", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
        copyText({destination, 0, 0}, date);
        pushInteger(0);
        return;
    }
    case 225:
    {
        const __time64_t timestamp = nextInteger();
        const auto destination = nextSlice();
        if (destination.base == 0 || execution_failed)
            return;
        tm local{};
        if (::_localtime64_s(&local, &timestamp) == 0)
            writeMemory(destination.base, local);
        return;
    }
    case 226:
        pushInteger(::GetTickCount());
        return;
    default:
        return;
    }
}

void SferaMbcRuntime::executeSystemInterface(std::int32_t operation)
{
    switch (operation)
    {
    case 11:
    {
        const auto value = nextInteger();
        if (value < 0)
            pushInteger(g_sfera_direct_input_runtime.text_filter);
        else
            g_sfera_direct_input_runtime.text_filter = value;
        return;
    }
    case 14:
        pushInteger(g_sfera_direct_input_runtime.text_filter == 0 && g_sfera_direct_input_runtime.binding_capture == 0 && !g_sfera_interface.options.binding_dialog_open);
        return;
    case 18:
    {
        const auto object = nextInteger();
        const auto handle = nextInteger();
        if (execution_failed)
            return;
        auto *control = WorldGuiControls::control(handle);
        if (!control)
        {
            reportError("Wrong GUI control handle");
            return;
        }
        control->objectHandle = object;
        if (argument_count >= 4)
            control->height_factor = nextReal();
        if (argument_count == 5)
            nextInteger();
        return;
    }
    case 33:
    {
        const auto x = systemCommandAddress("G_MOUSEXY, 1");
        const auto y = systemCommandAddress("G_MOUSEXY, 2");
        if (execution_failed)
            return;
        SferaCursorPosition position{};
        CCursorManager::instance().activeCursor()->getPosition(&position);
        writeMemory<float>(x, SferaNumeric::real32(position.x));
        writeMemory<float>(y, SferaNumeric::real32(position.y));
        return;
    }
    case 34:
    case 37:
        pushInteger(g_sfera_direct_input_runtime.mouse.buttons & (operation == 34 ? 1 : 2));
        return;
    case 35:
    {
        const auto cursor = nextInteger();
        const auto mask = nextInteger();
        if (execution_failed)
            return;
        if (cursor)
            g_sfera_interface.default_cursor_name = systemCommandText(cursor);
        SphereRenderSceneRenderer::visible_character_parts = mask;
        return;
    }
    case 39:
    {
        const float x = nextReal();
        const float y = nextReal();
        if (!execution_failed)
            CCursorManager::instance().activeCursor()->setPosition(SferaNumeric::truncateInt(x), SferaNumeric::truncateInt(y));
        return;
    }
    case 152:
        g_sfera_interface.initializeResources();
        return;
    case 212:
        pushInteger(g_sfera_interface.invite_messages);
        return;
    case 213:
    case 214:
    {
        auto *window = nativeResource<SphereUIWindow *>(nextWord());
        if (window != nullptr)
        {
            if (operation == 213)
                g_sfera_interface.raiseWindow(*window);
            else
                g_sfera_interface.lowerWindow(*window);
        }
        return;
    }
    case 218:
        g_sfera_interface.saved_ui_enabled = g_sfera_interface.ui_enabled;
        g_sfera_interface.ui_enabled = false;
        return;
    case 219:
    {
        const auto message = nextInteger();
        if (!execution_failed)
            pushInteger(g_sfera_interface.chat_filter->rejects(systemCommandText(message)));
        return;
    }
    case 220:
    {
        const auto message = nextInteger();
        if (!execution_failed)
            pushInteger(SphereUIChatFilter::invalidIdentifier(systemCommandText(message)));
        return;
    }
    case 221:
        g_sfera_interface.ui_enabled = g_sfera_interface.saved_ui_enabled;
        return;
    default:
        return;
    }
}

void SferaMbcRuntime::executeSystemResources(std::int32_t operation)
{
    switch (operation)
    {
    case 19:
    case 20:
    {
        const auto patternOrHandle = nextWord();
        const auto destination = systemCommandAddress(operation == 19 ? "FINDFIRST" : "FINDNEXT");
        if (execution_failed)
            return;
        const auto result = operation == 19 ? ::_findfirst64i32(systemCommandText(patternOrHandle).data(), &script_find_data)
                                            : ::_findnext64i32(nativeResource<std::intptr_t>(patternOrHandle), &script_find_data);
        std::uint32_t value = UINT32_MAX;
        if (result != -1)
        {
            if (operation == 19)
            {
                try
                {
                    value = nativeHandle(result);
                    active_process->registerResource(value, SferaMbcRuntimeResourceKind::fileSearch);
                }
                catch (...)
                {
                    forgetNativeResource(result);
                    ::_findclose(result);
                    throw;
                }
            }
            else
                value = SferaNumeric::lowWord(result);
            copyText({destination, 0, 0}, script_find_data.name);
        }
        else
            copyText({destination, 0, 0}, {});
        pushInteger(value);
        return;
    }
    case 21:
    {
        const auto handle = nextWord();
        if (!execution_failed)
        {
            const auto search = nativeResource<std::intptr_t>(handle);
            if (search != -1)
            {
                ::_findclose(search);
                forgetNativeResource(search);
            }
            active_process->unregisterResource(handle, SferaMbcRuntimeResourceKind::fileSearch);
        }
        return;
    }
    case 64:
    {
        const auto track = systemCommandAddress("PLAY_MUSIC");
        if (!execution_failed)
            g_sfera_sound_runtime.requestTrack(track != 0 && !systemCommandText(track).empty() ? std::optional<std::string_view>{systemCommandText(track)} : std::nullopt);
        return;
    }
    case 66:
    case 67:
    {
        const auto destination = systemCommandAddress(operation == 66 ? "GZ_PACK, 1" : "GZ_UNPACK, 1");
        const auto source = systemCommandAddress(operation == 66 ? "GZ_PACK, 2" : "GZ_UNPACK, 2");
        if (!execution_failed)
            pushInteger(g_sfera_files.transformEnvelope(std::string(systemCommandText(destination)), std::string(systemCommandText(source)), operation == 66));
        return;
    }
    case 68:
    {
        auto destination = nextSlice();
        if (execution_failed)
            return;

        constexpr std::size_t map_width = 80u;
        constexpr std::size_t map_height = 80u;
        constexpr std::size_t map_cell_size = 22u;
        constexpr std::size_t map_size = map_width * map_height * map_cell_size;

        if (destination.base == 0u)
        {
            reportError("NULL landscape map destination");
            return;
        }
        if (!destination.contains(map_size))
        {
            destination.diagnoseRange(map_size);
            if (!destination.contains(map_size))
                return;
        }

        const auto map_data = g_sfera_files.readAll("landscape\\map.bin");
        if (map_data.size() != map_size)
        {
            reportError(std::format("Invalid landscape map size for system 68: expected {}, got {}", map_size, map_data.size()));
            return;
        }

        auto output = memoryBytes(destination.base, map_size);
        for (std::size_t map_x = 0u; map_x < map_width; ++map_x)
        {
            for (std::size_t map_z = 0u; map_z < map_height; ++map_z)
            {
                const auto source_index = map_x * map_height + map_z;
                const auto destination_index = map_z * map_width + map_x;
                const auto source_offset = source_index * map_cell_size;
                const auto destination_offset = destination_index * map_cell_size;
                std::copy_n(map_data.begin() + static_cast<std::ptrdiff_t>(source_offset), map_cell_size, output.begin() + static_cast<std::ptrdiff_t>(destination_offset));
            }
        }
        return;
    }
    case 73:
        if (argument_count > 1)
        {
            nextInteger();
            pushInteger(SferaClientApplication::resources_loaded);
        }
        else
            SferaClientApplication::loadResources();
        return;
    case 75:
    {
        const auto detail = nextInteger();
        const auto handle = g_sfera_world_objects.controlled_object_handle;
        if (SferaNumeric::signedWord(handle) <= 0)
            return;
        if (detail != 0)
        {
            auto *effect = g_sfera_effect_manager.createActiveEffect(300, handle);
            g_sfera_effect_manager.pending_effect = effect;
        }
        else if (g_sfera_effect_manager.pending_effect != nullptr)
        {
            g_sfera_effect_manager.removeActiveEffect(g_sfera_effect_manager.pending_effect);
            g_sfera_effect_manager.pending_effect = nullptr;
        }
        return;
    }
    case 92:
        reloadQuickFiles();
        return;
    case 113:
    {
        const auto variable = nextInteger();
        const auto destination = nextWord();
        if (execution_failed)
            return;
        const auto name = systemCommandText(variable);
        std::string value;
        std::size_t required = 0;
        if (::getenv_s(&required, nullptr, 0, name.c_str()) == 0 && required != 0)
        {
            for (unsigned attempt = 0;; ++attempt)
            {
                if (attempt == 8u)
                    throw std::runtime_error("Environment value changed repeatedly while reading");
                value.resize(required);
                const auto status = ::getenv_s(&required, value.data(), value.size(), name.c_str());
                if (status == ERANGE && required > value.size())
                    continue;
                if (status != 0 || required == 0)
                {
                    value.clear();
                    break;
                }
                if (required > value.size() || value[required - 1] != '\0')
                    throw std::out_of_range("Invalid environment value length");
                value.resize(required - 1);
                break;
            }
        }
        copyText({destination, 0, 0}, value);
        return;
    }
    case 115:
    {
        const auto name = nextInteger();
        if (!execution_failed)
            pushInteger(g_sfera_textures.find(systemCommandText(name)) != 0);
        return;
    }
    case 116:
    {
        const auto name = nextInteger();
        if (execution_failed)
            return;
        const auto definition = g_sfera_effect_manager.findDefinitionId(systemCommandText(name));
        pushInteger(definition == UINT32_MAX ? 0 : definition);
        return;
    }
    case 120:
    {
        nextInteger();
        const std::uint32_t effect = nextInteger();
        if (!execution_failed)
            g_sfera_effect_manager.removeActiveEffect(nativeResource<SferaActiveEffect *>(effect));
        return;
    }
    case 136:
    {
        const auto path = nextInteger();
        if (execution_failed)
            return;
        _finddata64i32_t information{};
        const auto handle = ::_findfirst64i32(systemCommandText(path).data(), &information);
        if (handle == -1)
            pushInteger(errno == ENOENT ? 0 : UINT32_MAX);
        else
        {
            ::_findclose(handle);
            pushInteger((information.attrib & _A_SUBDIR) != 0);
        }
        return;
    }
    default:
        return;
    }
}

void SferaMbcRuntime::executeSystemRuntime(std::int32_t operation)
{
    switch (operation)
    {
    case 12:
    {
        const auto destination = systemCommandAddress("G_ERRMSG");
        if (!execution_failed)
            copyText({destination, 0, 0}, diagnostic_context);
        return;
    }
    case 22:
        instruction_step_count = 0;
        return;
    case 24:
        pushInteger(g_sfera_network_runtime.connection_info.round_trip_latency_ms);
        return;
    case 25:
        pushInteger(g_sfera_network_runtime.connection_info.throughputBytesPerSecond());
        return;
    case 26:
        pushInteger(g_sfera_network_runtime.connection_info.sent_bytes_per_second);
        return;
    case 27:
        pushInteger(g_sfera_network_runtime.connection_info.received_bytes_per_second);
        return;
    case 43:
    {
        auto *process = argument_count == 3 ? findProcess(nextInteger()) : active_process;
        const auto index = nextInteger();
        if (execution_failed)
            return;
        pushInteger(process != nullptr && index == -1 ? 0u : UINT32_MAX);
        return; // No subscriber producer; preserve both arities and invalid-process result.
    }
    case 60:
        pushInteger(SferaClientApplication::server_number);
        return;
    case 61:
        active_process->flags |= SferaMbcProcessRecordFlagsmarkedForUnload;
        return;
    case 77:
        ::Sleep(nextInteger());
        return;
    case 86:
        pushInteger(101);
        return;
    case 103:
    {
        const auto destination = systemCommandAddress("G_VERSION");
        if (!execution_failed)
            writeMemory(destination, std::uint32_t{3});
        return;
    }
    case 140:
    {
        const auto name = systemCommandAddress("SYS_SET_USER_NAME, 1");
        g_sfera_error_log_runtime.user_name = systemCommandText(name).substr(0, 127);
        pushInteger(1);
        return;
    }
    case 150:
    {
        g_sfera_network_runtime.connection_lost = nextInteger() != 0;
        pushInteger(0);
        return;
    }
    case 508:
    {
        const auto processIndex = nextInteger();
        const auto first = nextInteger();
        const auto pattern = nextText();
        const auto output = nextSlice();
        if (execution_failed || processIndex < 0 || std::cmp_greater_equal(processIndex, std::size(processes)) || processes[processIndex].functions.empty() || first < 0)
        {
            pushInteger(UINT32_MAX);
            return;
        }
        const auto &process = processes[processIndex];
        for (std::uint32_t index = first; index < process.functions.size(); ++index)
        {
            const auto &name = process.functions[index].name;
            if (!SferaText::matchesWildcard(name, pattern))
                continue;
            if (output.base != 0)
                copyText(output, name);
            pushInteger(index + 1);
            return;
        }
        if (output.base != 0)
            copyText(output, {});
        pushInteger(UINT32_MAX);
        return;
    }
    case 509:
        g_sfera_network_runtime.connection_slot = nextInteger();
        return;
    case 510:
        pushInteger(g_sfera_network_runtime.connection_slot);
        return;
    default:
        return;
    }
}

void SferaMbcRuntime::executeSystemValues(std::int32_t operation)
{
    switch (operation)
    {
    case 121:
    {
        const auto source = nextInteger();
        const auto destination = nextInteger();
        if (!execution_failed)
        {
            writeMemory(destination, ::_atoi64(systemCommandText(source).data()));
            pushInteger(0);
        }
        return;
    }
    case 122:
    {
        const auto source = nextWord();
        const auto destination = nextWord();
        if (!execution_failed)
        {
            const auto value = std::to_string(readMemory<std::uint64_t>(source));
            copyText({destination, 0, 0}, value);
            pushInteger(0);
        }
        return;
    }
    case 123:
    case 124:
    case 127:
    {
        const auto destination = nextInteger();
        const std::int64_t operand = nextInteger();
        if (execution_failed)
            return;
        auto value = readMemory<std::uint64_t>(destination);
        value = operation == 123 ? value + operand : operation == 124 ? value - operand : value * operand;
        writeMemory(destination, value);
        pushInteger(operation == 127 ? SferaNumeric::lowWord(value) : (value >> 63) != 0 ? UINT32_MAX - 1u : 0u);
        return;
    }
    case 125:
    case 128:
    {
        const auto firstAddress = nextInteger();
        const auto argument = nextInteger();
        if (execution_failed)
            return;
        const auto first = readMemory<std::int64_t>(firstAddress);
        const std::int64_t second = operation == 125 ? argument : readMemory<std::int64_t>(argument);
        pushInteger(first < second ? UINT32_MAX : first > second ? 1 : 0);
        return;
    }
    case 126:
    {
        const auto source = nextInteger();
        const float multiplier = nextReal();
        if (!execution_failed)
            pushInteger(readMemory<std::uint32_t>(source) * SferaNumeric::lowWord(SferaMbcValue::truncateReal(multiplier)));
        return;
    }
    case 227:
    {
        const auto x = nextInteger();
        const auto y = nextInteger();
        const auto z = nextInteger();
        const auto result = nextInteger();
        if (execution_failed)
            return;
        const double vx = readMemory<float>(x), vy = readMemory<float>(y), vz = readMemory<float>(z);
        float length = SferaNumeric::real32(vx * vx + vy * vy + vz * vz);
        if (length > 0.00001)
        {
            const double squared_length = length;
            length = SferaNumeric::real32(std::sqrt(squared_length));
            const double source_x = readMemory<float>(x), source_y = readMemory<float>(y), source_z = readMemory<float>(z);
            writeReal(x, source_x / length);
            writeReal(y, source_y / length);
            writeReal(z, source_z / length);
        }
        writeMemory(result, length);
        pushInteger(0);
        return;
    }
    case 228:
    {
        copyText(nextSliceReference(), "");
        pushInteger(0);
        return;
    }
    case 229:
    {
        const auto source = nextSliceReference();
        const auto destination = nextSliceReference();
        const auto capacity = std::min<std::size_t>(textBuffer(destination).size(), destination.end - destination.base);
        if (capacity != 0)
            copyText(destination, SferaText::encodeUri(systemCommandText(source.base), capacity));
        pushInteger(0);
        return;
    }
    default:
        return;
    }
}

bool SferaMbcRuntime::crossesBoundary(float first, float second, float value)
{
    return second < value && value < first;
}

auto SferaMbcRuntime::systemCommandSelectedObject() -> WorldObject *
{
    const auto handle = nextInteger();
    if (handle < 0)
        return nullptr;
    auto *object = g_sfera_world_objects.object(handle, "GetObjectPointer");
    g_sfera_mbc_runtime.current_object = object;
    if (object == nullptr)
        active_tag = UINT32_MAX;
    return object;
}

auto SferaMbcRuntime::systemCommandReadArray(std::int32_t count, const SferaSliceReference32 &reference)
{
    SferaBinaryReader reader(memoryBytes(reference.base, count * sizeof(std::int32_t)));
    std::vector<int> values(count);
    for (auto &value : values)
        value = reader.read<std::int32_t>();
    return values;
}

void SferaMbcRuntime::executeSystemWorld(std::int32_t operation)
{
    switch (operation)
    {
    case 0:
    {
        const auto handle = nextInteger();
        const auto destination = argument_count == 3 ? systemCommandAddress("G_GROUND") : 0;
        if (execution_failed)
            return;
        std::uint32_t surface = 0;
        pushInteger(g_sfera_motion.surfaceInteraction(handle, &surface));
        if (SferaNumeric::signedWord(destination) > 0)
            writeMemory(destination, surface);
        return;
    }
    case 1:
    case 3:
    case 38:
    {
        auto *object = systemCommandSelectedObject();
        if (object == nullptr)
            return;
        const bool enabled = nextInteger() != 0;
        if (execution_failed)
            return;
        if (operation == 38)
            object->visible = enabled;
        else
        {
            auto *extended = SphereRenderCharacterModels::checkedExtended(object);
            if (operation == 1)
                extended->simulation_enabled = enabled;
            else
                extended->gravity_enabled = enabled;
        }
        return;
    }
    case 4:
    {
        const auto handle = nextInteger();
        // A script can bind a handle before its object is recreated during a transition.
        g_sfera_world_objects.controlled_object_handle = execution_failed ? UINT32_MAX : SferaNumeric::word(handle);
        return;
    }
    case 10:
        if (systemCommandSelectedObject() != nullptr)
        {
            nextInteger();
            nextInteger();
            nextInteger();
        }
        return;
    case 29:
    {
        const auto index = nextInteger();
        auto *process = findProcess(index);
        const auto object = nextInteger();
        if (execution_failed)
            return;
        if (process == nullptr)
        {
            if (object > 0)
                g_sfera_world_objects.addExtended(object);
            pushInteger(UINT32_MAX);
        }
        else if (process->field_084 == 0)
            pushInteger(UINT32_MAX);
        else
        {
            if (object > 0)
                g_sfera_world_objects.removeExtended(object);
            pushInteger(0);
        }
        return;
    }
    case 32:
    {
        const auto object = nextInteger();
        const auto distance = nextInteger();
        float value = 0;
        const auto handle = g_sfera_motion.pick(&value, nullptr);
        if (object)
            writeMemory(object, handle);
        if (distance)
            writeMemory(distance, value);
        return;
    }
    case 36:
    {
        const auto destination = systemCommandAddress("G_CURSDIR");
        if (execution_failed)
            return;
        float distance = 0;
        SferaVec3F direction{};
        g_sfera_motion.pick(&distance, &direction);
        writeMemory(destination, direction);
        return;
    }
    case 41:
    {
        const auto value = nextInteger();
        if (!execution_failed)
            g_sfera_motion.orientation_blocked = value;
        return;
    }
    case 44:
    {
        const int handle = g_sfera_world_objects.controlled_object_handle;
        if (handle < 0)
        {
            pushInteger(0);
            return;
        }
        auto *object = g_sfera_world_objects.object(handle, "GetObjectPointer");
        g_sfera_mbc_runtime.current_object = object;
        pushInteger(object != nullptr && SphereRenderCharacterModels::checkedExtended(object)->steep_slope == 1);
        return;
    }
    case 45:
    {
        const auto handle = nextInteger();
        const auto model = systemCommandAddress("LINK_ON");
        const auto slot = nextInteger();
        if (!execution_failed)
            g_sfera_world_objects.linkModel(handle, systemCommandText(model), slot);
        return;
    }
    case 46:
    {
        const auto handle = nextInteger();
        const auto slot = nextInteger();
        if (!execution_failed)
            g_sfera_world_objects.unlink(handle, slot);
        return;
    }
    case 47:
    {
        const auto value = nextInteger();
        if (!execution_failed)
            g_sfera_motion.control_mode = value;
        return;
    }
    case 59:
    {
        const auto value = nextInteger();
        if (!execution_failed)
            g_sfera_camera.controlled_observer_mode = value;
        return;
    }
    case 65:
        g_sfera_world_objects.contours->rebuildServerWall();
        return;
    case 78:
    {
        auto *object = systemCommandSelectedObject();
        if (object == nullptr)
            return;
        const float scale = nextReal();
        if (!execution_failed)
            SphereRenderCharacterModels::checkedExtended(object)->scale = scale;
        return;
    }
    case 80:
    {
        const auto handle = nextInteger();
        if (handle < 0)
        {
            pushInteger(UINT32_MAX);
            return;
        }
        if (execution_failed)
            return;
        auto variant = nextInteger();
        if (argument_count != 3)
        {
            const auto second = nextInteger();
            const auto third = nextInteger();
            if (execution_failed)
                return;
            variant = SphereRenderSceneRenderer::materialVariant(variant, second, third);
        }
        if (!SphereRenderSceneRenderer::hasMaterialVariant(handle, variant))
        {
            pushInteger(UINT32_MAX);
            return;
        }
        SphereRenderSceneRenderer::setMaterialVariant(handle, variant);
        pushInteger(0);
        return;
    }
    case 81:
    {
        const float x = nextReal();
        const float y = nextReal();
        const auto first = nextInteger();
        const auto last = nextInteger();
        pushInteger(g_sfera_world_objects.contours->typeAt(x, y, first, last));
        return;
    }
    case 84:
    {
        auto *object = systemCommandSelectedObject();
        if (object != nullptr && !execution_failed)
            pushInteger(object->spatial_membership);
        return;
    }
    case 87:
    {
        const auto server = nextInteger();
        const float x = nextReal();
        const float y = nextReal();
        if (!execution_failed)
            pushInteger(g_sfera_world_objects.contours->nearServer(x, y, server));
        return;
    }
    case 88:
    {
        const float x = nextReal();
        const float y = nextReal();
        if (!execution_failed)
            pushInteger(g_sfera_world_objects.contours->serverAt(x, y));
        return;
    }
    case 89:
    {
        const auto ids = nextAddress();
        const auto types = nextAddress();
        const auto count = nextInteger();
        if (execution_failed)
            return;
        if (count <= 0 || count > SIZE_MAX / sizeof(std::int32_t))
        {
            reportError("Invalid server map size");
            return;
        }

        const auto identifiers = systemCommandReadArray(count, ids);
        const auto serverTypes = systemCommandReadArray(count, types);
        if (g_sfera_world_objects.contours != nullptr)
            g_sfera_world_objects.contours->setServerMap(identifiers, serverTypes);
        return;
    }
    case 94:
    {
        const float first = nextReal();
        const float second = nextReal();
        if (execution_failed)
            return;
        constexpr std::array<float, 6> boundaries{-742, -492, -242, 7, 257, 507};
        pushInteger(std::fabs(first - second) <= 70 && std::any_of(boundaries.begin(), boundaries.end(), std::bind_front(&SferaMbcRuntime::crossesBoundary, first, second)));
        return;
    }
    case 96:
    {
        const auto handle = nextInteger();
        const float heading = nextReal();
        if (!execution_failed)
            g_sfera_world_objects.approachHeading(handle, heading);
        return;
    }
    case 98:
    {
        auto *models = SphereRenderSceneRenderer::characters.get();
        if (models == nullptr)
            return;
        const auto handle = nextInteger();
        SphereRenderCharacterAppearance appearance{};
        appearance.sex = nextInteger();
        std::array<std::uint8_t, 4> partValues{};
        for (auto &value : partValues)
            value = SferaNumeric::lowByte(nextInteger());
        if (execution_failed)
            return;
        for (const auto index : {0, 1, 2, 4, 5, 6})
            appearance.parts[index] = '0';
        appearance.parts[7] = partValues[0] ? partValues[0] : '0';
        appearance.parts[9] = partValues[1] ? partValues[1] : '1';
        appearance.parts[10] = partValues[2] ? partValues[2] : '0';
        appearance.parts[8] = partValues[3] ? partValues[3] : '0';
        models->setAppearance(handle, appearance);
        return;
    }
    case 99:
    {
        auto *models = SphereRenderSceneRenderer::characters.get();
        if (models == nullptr)
            return;
        const auto handle = nextInteger();
        std::array<int, 9> partValues{};
        for (auto &value : partValues)
            value = nextInteger();
        if (execution_failed)
            return;
        SphereRenderCharacterAppearance appearance{};
        if (!models->getAppearance(handle, appearance))
            return;
        if (partValues[0] > 0)
            appearance.parts[0] = SferaNumeric::lowByte(partValues[0]);
        if (partValues[1] > 0)
            appearance.parts[1] = SferaNumeric::lowByte(partValues[1]);
        if (partValues[2] == 0 && partValues[3] == 0)
            partValues[2] = '0';
        if (partValues[2] == 0 || partValues[2] >= '0')
            appearance.parts[2] = SferaNumeric::lowByte(partValues[2]);
        if (partValues[3] == 0 || partValues[3] >= '0')
            appearance.parts[3] = SferaNumeric::lowByte(partValues[3]);
        if (partValues[4] > 0)
            appearance.parts[6] = SferaNumeric::lowByte(partValues[4]);
        appearance.parts[12] = SferaNumeric::lowByte(partValues[5]);
        appearance.parts[11] = SferaNumeric::lowByte(partValues[8]);
        if (partValues[6] > 0)
            appearance.parts[4] = SferaNumeric::lowByte(partValues[6]);
        if (partValues[7] > 0)
            appearance.parts[5] = SferaNumeric::lowByte(partValues[7]);
        models->setAppearance(handle, appearance);
        return;
    }
    case 100:
    {
        if (SphereRenderSceneRenderer::characters == nullptr)
        {
            pushInteger(0);
            return;
        }
        const auto sex = nextInteger();
        const auto part = nextInteger();
        if (!execution_failed)
            pushInteger(part == 0 || part == 1 ? SphereRenderCharacterModels::textureVariants(sex != 0, part == 0 ? "f" : "r") : part == 2 || part == 3 ? 4 : 0);
        return;
    }
    case 119:
    {
        const auto handle = nextInteger();
        auto *object = g_sfera_world_objects.object(handle, "GetObjectPointer");
        g_sfera_mbc_runtime.current_object = object;
        pushInteger(object == nullptr ? UINT32_MAX : 0);
        return;
    }
    case 224:
    {
        const auto handle = nextInteger();
        if (handle < 0)
            return;
        auto *object = SphereRenderCharacterModels::checkedExtended(g_sfera_world_objects.object(handle, "GetObjectPointer"));
        if (object == nullptr)
            return;
        const SferaVec3F velocity{nextReal(), nextReal(), nextReal()};
        if (!execution_failed)
            object->physical_velocity = velocity;
        return;
    }
    case 230:
        return;
    case 231:
        if (!execution_failed)
        {
            pushInteger(g_sfera_motion.moved_since_query);
            g_sfera_motion.moved_since_query = 0;
        }
        return;
    default:
        return;
    }
}
