#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <format>
#include <limits>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "application/ClientApplication.h"
#include "binary/Binary.h"
#include "diagnostics/ClientDiagnostics.h"
#include "input/Cursors.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "script/MbcCommands.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "script/MbcUiMessageCodec.h"
#include "text/Text.h"
#include "text/TextBuffer.h"
#include "ui/Canvas.h"
#include "ui/GameInterfaceManager.h"
#include "ui/ScriptInterface.h"
#include "ui/UiTypes.h"
#include "ui/Window.h"
#include "ui/widgets/Controls.h"
#include "ui/widgets/Lists.h"
#include "ui/widgets/Popups.h"
#include "ui/widgets/TextEditors.h"

auto SferaMbcRuntime::windowCommandRead(std::array<std::int32_t, 6> &arguments, std::size_t count)
{
    for (std::size_t index = 0; index < count; ++index)
        arguments[index] = nextInteger();
    return !execution_failed;
}

auto SferaMbcRuntime::windowCommandInputText(std::int32_t offset)
{
    return offset == 0 ? std::string{} : textAt(SferaNumeric::word(offset));
}

auto SferaMbcRuntime::windowCommandOptionalInputText(std::int32_t offset) -> std::optional<std::string>
{
    return offset == 0 ? std::nullopt : std::optional<std::string>{windowCommandInputText(offset)};
}

auto SferaMbcRuntime::windowCommandWarnNull(SferaMbcRuntimeWindowOperation operation, std::int32_t offset, std::uint32_t argument)
{
    if (offset == 0)
    {
        std::string message;
        message = std::format("NULL-pointer dereferencing: window, command {}, argument {}\n", SferaNumeric::lowWord(SferaNumeric::enumBits(operation)), argument);
        WorldDiagnostics::warning(message);
    }
}

void SferaMbcRuntime::windowCommand()
{
    const auto operation = SferaNumeric::enumFromBits<SferaMbcRuntimeWindowOperation>(SferaNumeric::word(nextInteger()));
    std::array<std::int32_t, 6> arguments{};

    switch (operation)
    {
    case SferaMbcRuntimeWindowOperation::Create:
    {
        if (!windowCommandRead(arguments, 6))
            return;
        const auto handle = GameInterface::createWindow(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
        pushInteger(handle);
        if (SferaNumeric::signedWord(handle) < 0)
            reportError("Error creating window");
        else
        {
            try
            {
                active_process->registerResource(handle, SferaMbcRuntimeResourceKind::gameWindow);
            }
            catch (...)
            {
                GameInterface::destroyWindow(handle);
                throw;
            }
        }
        break;
    }
    case SferaMbcRuntimeWindowOperation::Destroy:
    case SferaMbcRuntimeWindowOperation::Close:
    {
        if (!windowCommandRead(arguments, 1))
            return;
        const std::uint32_t handle = arguments[0];
        auto resource = SferaMbcRuntimeResourceKind::gameWindow;
        if (operation == SferaMbcRuntimeWindowOperation::Destroy)
            GameInterface::destroyWindow(handle);
        else
        {
            resource = SferaMbcRuntimeResourceKind::interfaceWindow;
            g_sfera_interface.closeWindow(nativeResource<SphereUIWindow *>(handle), true);
        }
        active_process->unregisterResource(handle, resource);
        break;
    }
    case SferaMbcRuntimeWindowOperation::DisplayWidth:
        pushInteger(g_sfera_graphics_runtime.display_width);
        break;
    case SferaMbcRuntimeWindowOperation::DisplayHeight:
        pushInteger(g_sfera_graphics_runtime.display_height);
        break;
    case SferaMbcRuntimeWindowOperation::TextHeight:
    case SferaMbcRuntimeWindowOperation::FontHeight:
    case SferaMbcRuntimeWindowOperation::LineOffset:
        if (!windowCommandRead(arguments, operation == SferaMbcRuntimeWindowOperation::FontHeight ? 2 : 3))
            return;
        if (operation == SferaMbcRuntimeWindowOperation::TextHeight)
            pushInteger(GameInterface::textHeight(arguments[0], arguments[1], arguments[2]));
        else if (operation == SferaMbcRuntimeWindowOperation::FontHeight)
            pushInteger(GameInterface::fontHeight(arguments[0], arguments[1]));
        else
            pushInteger(GameInterface::lineOffset(arguments[0], arguments[1], arguments[2]));
        break;
    case SferaMbcRuntimeWindowOperation::TakeInput:
    {
        if (!windowCommandRead(arguments, 3))
            return;
        windowCommandWarnNull(operation, arguments[1], 1);
        windowCommandWarnNull(operation, arguments[2], 2);
        std::uint32_t control = UINT32_MAX, message = 0;
        if (auto *window = GameInterface::window(arguments[0], "GetWindowPointer"))
            window->takeInput(control, message);
        writeMemory(arguments[1], control);
        writeMemory(arguments[2], message <= 2 ? message : 0u);
        break;
    }
    case SferaMbcRuntimeWindowOperation::HitTest:
    {
        if (!windowCommandRead(arguments, 2))
            return;
        windowCommandWarnNull(operation, arguments[0], 1);
        windowCommandWarnNull(operation, arguments[1], 2);
        const auto hit = GameInterface::hitTest(CCursorManager::instance().position());
        writeMemory(arguments[0], hit.window);
        writeMemory(arguments[1], hit.control);
        break;
    }
    case SferaMbcRuntimeWindowOperation::Visible:
    case SferaMbcRuntimeWindowOperation::Scrollable:
        if (!windowCommandRead(arguments, 2))
            return;
        if (auto *window = GameInterface::window(arguments[0], "GetWindowPointer"))
        {
            if (operation == SferaMbcRuntimeWindowOperation::Visible)
                window->visible = arguments[1] == 1;
            else
                window->scrollable = arguments[1] == 1;
        }
        break;
    case SferaMbcRuntimeWindowOperation::Bounds:
        if (!windowCommandRead(arguments, 5))
            return;
        if (auto *window = GameInterface::window(arguments[0], "GetWindowPointer"))
        {
            window->left = window->contentLeft + arguments[1];
            window->right = window->contentRight + arguments[3];
            window->top = window->contentTop + arguments[2];
            window->bottom = window->contentBottom + arguments[4];
        }
        break;
    case SferaMbcRuntimeWindowOperation::TextSize:
        if (!windowCommandRead(arguments, 2))
            return;
        windowCommandWarnNull(operation, arguments[0], 1);
        windowCommandWarnNull(operation, arguments[1], 2);
        writeMemory(arguments[0], WorldGuiControls::text_width);
        writeMemory(arguments[1], WorldGuiControls::text_height);
        break;
    case SferaMbcRuntimeWindowOperation::GlyphWidth:
        if (!windowCommandRead(arguments, 2))
            return;
        pushInteger(GameInterface::glyphWidth(arguments[0] < 0 ? arguments[0] + 256 : arguments[0], arguments[1]));
        break;
    case SferaMbcRuntimeWindowOperation::CursorPosition:
    {
        if (!windowCommandRead(arguments, 3))
            return;
        windowCommandWarnNull(operation, arguments[1], 1);
        windowCommandWarnNull(operation, arguments[2], 2);
        const auto *window = GameInterface::window(arguments[0]);
        const auto point = window ? window->contentPosition(CCursorManager::instance().position()) : SferaCursorPosition{-1, -1};
        writeMemory(arguments[1], point.x);
        writeMemory(arguments[2], point.y);
        break;
    }
    case SferaMbcRuntimeWindowOperation::SystemCursorVisible:
    {
        auto *cursor = CCursorManager::instance().activeCursor();
        if (argument_count > 1)
        {
            if (!windowCommandRead(arguments, 1))
                return;
            cursor->setSystemCursorVisible(arguments[0] != 0);
            g_sfera_interface.world_interaction_enabled = arguments[0];
        }
        pushInteger(cursor->isSystemCursorVisible());
        break;
    }
    case SferaMbcRuntimeWindowOperation::SystemCursorKind:
        if (!windowCommandRead(arguments, 1))
            return;
        CCursorManager::instance().activeCursor()->setCursorKind(arguments[0]);
        break;
    case SferaMbcRuntimeWindowOperation::CursorKind:
        if (!windowCommandRead(arguments, argument_count > 2 ? 3 : 1))
            return;
        g_sfera_interface.setCursorKind(arguments[0], argument_count > 2 ? arguments[1] : 8, argument_count > 2 ? arguments[2] : -8);
        break;
    case SferaMbcRuntimeWindowOperation::CursorImage:
    {
        const bool positioned = argument_count > 3;
        const bool imageMode = argument_count == 3 || argument_count == 5;
        if (!windowCommandRead(arguments, 1 + (positioned ? 2 : 0) + (imageMode ? 1 : 0)))
            return;
        const auto mode = imageMode ? arguments[positioned ? 3 : 1] : -1;
        if (arguments[0] != 0 && mode >= 0)
        {
            if (auto *cursor = g_sfera_interface.cursor.get())
            {
                cursor->setImage(2, windowCommandInputText(arguments[0]), 8, 32);
                cursor->setImageSize(2, 16, 16);
            }
            break;
        }
        g_sfera_interface.setCursorImage(windowCommandOptionalInputText(arguments[0]), arguments[0] != 0 ? positioned ? arguments[1] : 8 : 0, arguments[0] != 0 ? positioned ? arguments[2] : 16 : 0);
        if (auto *cursor = g_sfera_interface.cursor.get())
            cursor->setImage(2, std::nullopt, 0, 0);
        break;
    }
    case SferaMbcRuntimeWindowOperation::CursorText:
        if (!windowCommandRead(arguments, argument_count > 3 ? 4 : 2))
            return;
        if (auto *cursor = g_sfera_interface.cursor.get())
            cursor->setText(arguments[0], windowCommandInputText(arguments[1]),
                            argument_count > 3  ? arguments[2]
                            : arguments[0] == 0 ? 6
                            : arguments[0] == 1 ? 16
                                                : 0,
                            argument_count > 3  ? arguments[3]
                            : arguments[0] == 0 ? 40
                            : arguments[0] == 1 ? 6
                                                : 0,
                            1, UINT32_MAX);
        break;
    case SferaMbcRuntimeWindowOperation::Open:
    {
        if (!g_sfera_interface.initialized)
        {
            pushInteger(0);
            return;
        }
        if (!windowCommandRead(arguments, 4))
            return;
        auto *window = g_sfera_interface.openWindow(windowCommandInputText(arguments[0]), arguments[1], arguments[2], arguments[3]);
        const auto handle = nativeHandle(window);
        pushInteger(handle);
        if (window)
            active_process->registerResource(handle, SferaMbcRuntimeResourceKind::interfaceWindow);
        break;
    }
    case SferaMbcRuntimeWindowOperation::PollEvent:
    {
        const auto count = argument_count == 6 ? 5u : argument_count >= 5 ? 4u : 3u;
        if (!windowCommandRead(arguments, count))
            return;
        for (std::uint32_t index = 1; index < count; ++index)
            windowCommandWarnNull(operation, arguments[index], index);
        SphereUIWindowEvent event{};
        auto *window = nativeResource<SphereUIWindow *>(SferaNumeric::word(arguments[0]));
        if (!window || !window->pollEvent(event))
        {
            pushInteger(0);
            return;
        }
        writeMemory(arguments[1], event.control_id);
        writeMemory(arguments[2], event.message);
        if (argument_count == 5)
        {
            if (event.message == SphereUIUiMessage::listItemEvent)
            {
                writeMemory(arguments[1], HIWORD(event.second));
                writeMemory(arguments[2], event.first);
                writeMemory(arguments[3], LOWORD(event.second));
            }
            else
                writeMemory(arguments[3], UINT32_MAX);
        }
        else if (argument_count == 6)
        {
            writeMemory(arguments[3], event.first);
            writeMemory(arguments[4], event.second);
        }
        pushInteger(1);
        break;
    }
    case SferaMbcRuntimeWindowOperation::SetText:
        if (!windowCommandRead(arguments, 2))
            return;
        if (auto *window = nativeResource<SphereUIWindow *>(SferaNumeric::word(arguments[0])))
            window->setText(windowCommandInputText(arguments[1]));
        pushInteger(0);
        break;
    case SferaMbcRuntimeWindowOperation::ControlAt:
    case SferaMbcRuntimeWindowOperation::ItemAt:
    {
        if (!windowCommandRead(arguments, 2))
            return;
        auto *window = nativeResource<SphereUIWindow *>(SferaNumeric::word(arguments[0]));
        SphereUIWindow *result = nullptr;
        if (window)
        {
            if (operation == SferaMbcRuntimeWindowOperation::ControlAt)
                result = window->controlAt(arguments[1]);
            else if (auto *list = window->asListItemCtrl())
                result = list->itemAt(arguments[1]);
        }
        pushInteger(nativeHandle(result));
        break;
    }
    case SferaMbcRuntimeWindowOperation::SendMessage:
    {
        if (!windowCommandRead(arguments, 5))
            return;
        MbcUiMessageCodec codec(*this, SferaNumeric::word(arguments[4]));
        codec.dispatch(nativeResource<SphereUIWindow *>(SferaNumeric::word(arguments[0])), SferaNumeric::enumFromBits<SphereUIUiMessage>(SferaNumeric::word(arguments[1])),
                       SferaNumeric::word(arguments[2]), SferaNumeric::word(arguments[3]));
        pushInteger(0);
        break;
    }
    case SferaMbcRuntimeWindowOperation::GetText:
    {
        if (!windowCommandRead(arguments, 3))
            return;
        windowCommandWarnNull(operation, arguments[1], 1);
        const std::size_t requested_capacity = std::max(arguments[2], 1);
        const auto content_capacity = requested_capacity - 1u;
        if (arguments[1] != 0)
        {
            auto destination = memoryRange(SferaNumeric::word(arguments[1]));
            const auto *window = nativeResource<SphereUIWindow *>(SferaNumeric::word(arguments[0]));
            if (window != nullptr && content_capacity != 0u && !destination.empty())
            {
                const auto capacity = std::min(destination.size(), requested_capacity);
                const std::string_view value{window->text};
                const auto length = std::min(value.size(), capacity - 1u);
                if (length != 0u)
                    std::memcpy(destination.data(), value.data(), length);
                destination[length] = 0u;
            }
        }
        pushInteger(0);
        break;
    }
    case SferaMbcRuntimeWindowOperation::SystemEvent:
    {
        if (!windowCommandRead(arguments, 1))
            return;
        windowCommandWarnNull(operation, arguments[0], 1);
        SphereUIWindowEvent event{};
        pushInteger(g_sfera_interface.pollEvent(event));
        writeMemory(arguments[0], event.message);
        break;
    }
    case SferaMbcRuntimeWindowOperation::WindowUnderCursor:
        pushInteger(nativeHandle(g_sfera_interface.windowUnderCursor()));
        break;
    case SferaMbcRuntimeWindowOperation::SavedPositionsSize:
    {
        const auto size = g_sfera_interface.savedPositionsSize();
        if (!std::in_range<std::uint32_t>(size))
        {
            reportError("Saved window positions exceed the MBC buffer limit");
            break;
        }
        pushInteger(SferaNumeric::lowWord(size));
        break;
    }
    case SferaMbcRuntimeWindowOperation::ReadSavedPositions:
        if (!windowCommandRead(arguments, 2))
            return;
        {
            const std::uint32_t size = SferaNumeric::word(arguments[1]);
            const auto *data = memoryAt(SferaNumeric::word(arguments[0]), size);
            g_sfera_interface.readSavedPositions(std::as_bytes(std::span(data, size)));
        }
        break;
    case SferaMbcRuntimeWindowOperation::WriteSavedPositions:
    {
        if (!windowCommandRead(arguments, 1))
            return;
        const auto size = g_sfera_interface.savedPositionsSize();
        if (!std::in_range<std::uint32_t>(size))
        {
            reportError("Saved window positions exceed the MBC buffer limit");
            break;
        }
        g_sfera_interface.writeSavedPositions(std::as_writable_bytes(std::span(memoryAt(SferaNumeric::word(arguments[0]), size), size)));
        break;
    }
    case SferaMbcRuntimeWindowOperation::Position:
    case SferaMbcRuntimeWindowOperation::Size:
    {
        if (!windowCommandRead(arguments, 3))
            return;
        if (operation == SferaMbcRuntimeWindowOperation::Position)
        {
            windowCommandWarnNull(operation, arguments[1], 1);
            windowCommandWarnNull(operation, arguments[2], 2);
        }
        const auto *window = nativeResource<SphereUIWindow *>(SferaNumeric::word(arguments[0]));
        writeMemory(arguments[1], window ? operation == SferaMbcRuntimeWindowOperation::Position ? window->x : window->width : 0);
        writeMemory(arguments[2], window ? operation == SferaMbcRuntimeWindowOperation::Position ? window->y : window->height : 0);
        break;
    }
    case SferaMbcRuntimeWindowOperation::Description:
        if (!windowCommandRead(arguments, 2))
            return;
        SphereUICDescriptionWindow::instance()->showDescription(windowCommandInputText(arguments[0]), 0, 250, false);
        break;
    case SferaMbcRuntimeWindowOperation::Tooltip:
        if (!windowCommandRead(arguments, 1))
            return;
        g_sfera_interface.setTooltipText(windowCommandOptionalInputText(arguments[0]));
        break;
    case SferaMbcRuntimeWindowOperation::Options:
        if (!SferaClientApplication::resources_loaded)
        {
            pushInteger(0);
            return;
        }
        if (argument_count > 1)
            pushInteger(g_sfera_interface.findWindow("options") != nullptr ? 1 : UINT32_MAX);
        else
        {
            g_sfera_interface.showOptions(g_sfera_interface.findWindow("options") == nullptr);
            pushInteger(1);
        }
        break;
    case SferaMbcRuntimeWindowOperation::EscapeWindow:
        pushInteger(!SferaClientApplication::resources_loaded ? 0 : g_sfera_interface.hasEscapeWindow() ? 1 : UINT32_MAX);
        break;
    case SferaMbcRuntimeWindowOperation::LegacyCreateDialog:
        if (!windowCommandRead(arguments, 2))
            return;
        pushInteger(0);
        break;
    case SferaMbcRuntimeWindowOperation::LegacyDestroyDialog:
        if (!windowCommandRead(arguments, 1))
            return;
        break;
    case SferaMbcRuntimeWindowOperation::LegacyPollDialogEvent:
    {
        const auto count = argument_count == 6 ? 5u : argument_count >= 5 ? 4u : 3u;
        if (!windowCommandRead(arguments, count))
            return;
        for (std::size_t index = 1; index < count; ++index)
        {
            if (arguments[index] != 0)
                writeMemory(arguments[index], std::uint32_t{0});
        }
        pushInteger(0);
        break;
    }
    case SferaMbcRuntimeWindowOperation::LegacySendDialogMessage:
        if (!windowCommandRead(arguments, 5))
            return;
        pushInteger(0);
        break;
    case SferaMbcRuntimeWindowOperation::LegacyDialogItem:
        if (!windowCommandRead(arguments, 2))
            return;
        pushInteger(0);
        break;
    case SferaMbcRuntimeWindowOperation::LegacySetDialogText:
        if (!windowCommandRead(arguments, 2))
            return;
        pushInteger(0);
        break;
    case SferaMbcRuntimeWindowOperation::LegacyGetDialogText:
        if (!windowCommandRead(arguments, 3))
            return;
        if (arguments[1] != 0 && arguments[2] > 0)
            *memoryAt(SferaNumeric::word(arguments[1]), 1u) = 0u;
        pushInteger(0);
        break;
    case SferaMbcRuntimeWindowOperation::Shutdown:
        if (argument_count > 1)
        {
            if (!windowCommandRead(arguments, 1))
                return;
            pushInteger(SferaClientApplication::main_loop_started);
        }
        else
            SferaClientApplication::startup_complete = true;
        break;
    case SferaMbcRuntimeWindowOperation::LegacyPumpMessages:
        break;
    case SferaMbcRuntimeWindowOperation::ActiveWindow:
        pushInteger(GameInterface::active_window);
        break;
    case SferaMbcRuntimeWindowOperation::LoadingProgress:
        if (GameInterface::loading_guard == 0)
            GameInterface::updateLoadingProgress(80);
        break;
    case SferaMbcRuntimeWindowOperation::FinishLoading:
        GameInterface::finishLoading();
        GameInterface::loading_guard = 1;
        break;
    default:
        break;
    }
}

static_assert(sizeof(MbcScrollParameters32) == 28u);
static_assert(sizeof(SphereUIScrollParameters) == sizeof(MbcScrollParameters32));

std::string MbcUiMessageCodec::text(std::uint32_t address) const
{
    return address == 0u ? std::string{} : runtime_.textAt(address);
}

std::optional<std::string> MbcUiMessageCodec::optionalText(std::uint32_t address) const
{
    return address == 0u ? std::nullopt : std::optional<std::string>{text(address)};
}

std::span<std::uint8_t> MbcUiMessageCodec::bytes(std::uint32_t address, std::size_t size) const
{
    if (address == 0u)
        return {};
    return {runtime_.memoryAt(address, size), size};
}

std::vector<std::uint32_t> MbcUiMessageCodec::words(std::uint32_t address, std::size_t count) const
{
    if (count == 0u)
        return {};
    if (address == 0u)
        return {};
    if (count > std::numeric_limits<std::size_t>::max() / sizeof(std::uint32_t))
        throw std::length_error("UI word array is too large");
    const auto source = bytes(address, count * sizeof(std::uint32_t));
    std::vector<std::uint32_t> result(count);
    std::memcpy(result.data(), source.data(), source.size());
    return result;
}

template <class T> T MbcUiMessageCodec::read(std::uint32_t address) const
{
    T result{};
    if (address == 0u)
        return result;
    std::memcpy(&result, runtime_.memoryAt(address, sizeof(result)), sizeof(result));
    return result;
}

template <class T> void MbcUiMessageCodec::write(std::uint32_t address, const T &value) const
{
    if (address != 0u)
        runtime_.writeMemory(address, value);
}

void MbcUiMessageCodec::writeBool(std::uint32_t address, bool value) const
{
    write<std::uint8_t>(address, value ? 1u : 0u);
}

void MbcUiMessageCodec::writeSize(std::uint32_t address, std::size_t value) const
{
    if (!std::in_range<std::uint32_t>(value))
    {
        runtime_.reportError("UI result exceeds an MBC word");
        return;
    }
    write(address, SferaNumeric::lowWord(value));
}

void MbcUiMessageCodec::writeText(std::uint32_t address, std::string_view value, std::size_t explicit_capacity, std::size_t content_limit) const
{
    if (address == 0u || explicit_capacity == 0u)
        return;
    auto destination = runtime_.memoryRange(address);
    const auto capacity = std::min(destination.size(), explicit_capacity);
    if (capacity == 0u)
        return;
    SferaTextBuffer(destination.first(capacity)).write(value.substr(0, content_limit));
}

SphereUIToolTipCtrl *MbcUiMessageCodec::tooltip(SphereUIWindow *window) const
{
    if (window == nullptr)
        return nullptr;
    if (!window->tooltip)
    {
        window->tooltip = std::make_unique<SphereUIToolTipCtrl>();
        window->tooltip->setParent(window);
    }
    return window->tooltip.get();
}

SphereUIImageDescription MbcUiMessageCodec::imageDescription(std::uint32_t address) const
{
    SphereUIImageDescription result{};
    if (address == 0u)
        return result;
    SferaBinaryReader reader(bytes(address, 156u));
    // The on-wire names have 64 bytes; the final byte has always been reserved for NUL.
    result.name = SferaText::prefix(reader.take(64u), 63u);
    result.image.texture_name = SferaText::prefix(reader.take(64u), 63u);
    result.image.width = reader.read<std::int32_t>();
    result.image.height = reader.read<std::int32_t>();
    result.image.rectangle.left = reader.read<std::int32_t>();
    result.image.rectangle.top = reader.read<std::int32_t>();
    result.image.rectangle.right = reader.read<std::int32_t>();
    result.image.rectangle.bottom = reader.read<std::int32_t>();
    result.image.flags = reader.read<std::uint32_t>();
    return result;
}

MbcUiMessageCodec::MbcUiMessageCodec(SferaMbcRuntime &runtime, std::uint32_t flags) : runtime_(runtime), flags_(flags)
{
}

std::uint32_t MbcUiMessageCodec::dispatch(SphereUIWindow *window, SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) const
{
    if (message == SphereUIUiMessage::showHelpPage)
    {
        g_sfera_interface.showHelpPage(optionalText(first));
        return 1u;
    }
    if (message == SphereUIUiMessage::beginModal)
    {
        if (window != nullptr)
            window->beginModal(runtime_.nativeResource<SphereUIWindow *>(first));
        return 1u;
    }

    switch (message)
    {
    case SphereUIUiMessage::getInputEnabled:
        if (window != nullptr)
            writeBool(first, window->input_enabled);
        return 1u;
    case SphereUIUiMessage::getHidden:
        if (window != nullptr)
            writeBool(first, window->hidden);
        return 1u;
    case SphereUIUiMessage::getDisabled:
        if (window != nullptr)
            writeBool(first, window->disabled);
        return 1u;
    case SphereUIUiMessage::getChildUnderCursor:
        if (window != nullptr)
        {
            const auto position = CCursorManager::instance().position();
            write(first, SferaNumeric::word(window->childControlAt(position.x, position.y)));
        }
        return 1u;
    case SphereUIUiMessage::getModal:
        if (window != nullptr)
            writeBool(first, window->modal_owner != nullptr);
        return 1u;
    case SphereUIUiMessage::getChecked:
        if (const auto *control = window != nullptr ? window->asCheckBox() : nullptr)
            writeBool(first, control->checked);
        return 1u;
    case SphereUIUiMessage::setEditText:
        if (auto *control = window != nullptr ? window->asEditCtrl() : nullptr)
            control->setEditText(text(first));
        return 1u;
    case SphereUIUiMessage::getEditText:
        if (const auto *control = window != nullptr ? window->asEditCtrl() : nullptr)
            writeText(first, control->text, std::numeric_limits<std::size_t>::max(), 250u);
        return 1u;
    case SphereUIUiMessage::appendListText:
        if (auto *control = window != nullptr ? window->asListCtrl() : nullptr; control != nullptr && first != 0u)
            control->appendMessageText(text(first), second);
        return 1u;
    case SphereUIUiMessage::setListText:
        if (auto *control = window != nullptr ? window->asListCtrl() : nullptr)
            control->setRowText(first, second == 0u ? std::string_view{" "} : text(second));
        return 1u;
    case SphereUIUiMessage::getListSelection:
        if (const auto *control = window != nullptr ? window->asListCtrl() : nullptr)
            write(first, control->selected_index);
        return 1u;
    case SphereUIUiMessage::getListText:
        if (const auto *control = window != nullptr ? window->asListCtrl() : nullptr; control != nullptr && second < control->rows.size())
            writeText(first, control->rowText(second));
        return 1u;
    case SphereUIUiMessage::getListSize:
        if (const auto *control = window != nullptr ? window->asListCtrl() : nullptr)
            writeSize(first, control->rows.size());
        return 1u;
    case SphereUIUiMessage::getListColor:
        if (const auto *control = window != nullptr ? window->asListCtrl() : nullptr; control != nullptr && second < control->rows.size())
            write(first, control->rows.at(control->physicalIndex(second)).color);
        return 1u;
    case SphereUIUiMessage::getListScroll:
        if (const auto *control = window != nullptr ? window->asListCtrl() : nullptr)
            write(first, control->vertical_offset);
        return 1u;
    case SphereUIUiMessage::appendFilteredListText:
        if (auto *control = window != nullptr ? window->asFilterListCtrl() : nullptr; control != nullptr && first != 0u)
            control->appendFilteredText(text(first), second);
        return 1u;
    case SphereUIUiMessage::getSelectedFont:
        if (const auto *control = window != nullptr ? window->asFontPicker() : nullptr)
            write(first, control->getFont());
        return 1u;
    case SphereUIUiMessage::setImageName:
        if (auto *control = window != nullptr ? window->asImageCtrl() : nullptr)
        {
            if (first == 0u)
                control->setImage(nullptr);
            else
                control->setImageName(text(first));
        }
        return 1u;
    case SphereUIUiMessage::setImageRotation:
        if (auto *control = window != nullptr ? window->asImageCtrl() : nullptr)
            control->setRotationDegrees(SferaBinary::floatFromBits(first));
        return 1u;
    case SphereUIUiMessage::setImageDescription:
        if (auto *control = window != nullptr ? window->asImageCtrl() : nullptr)
        {
            if (first == 0u)
                control->setImage(nullptr);
            else
            {
                const auto description = imageDescription(first);
                control->setImage(&description);
            }
        }
        return 1u;
    case SphereUIUiMessage::getListItemSelection:
        if (const auto *control = window != nullptr ? window->asListItemCtrl() : nullptr)
            write(first, control->selected_index);
        return 1u;
    case SphereUIUiMessage::getListItemCount:
        if (const auto *control = window != nullptr ? window->asListItemCtrl() : nullptr)
            writeSize(first, control->items.size());
        return 1u;
    case SphereUIUiMessage::setTooltipLine:
        if (auto *control = tooltip(window))
            control->setLine(first, optionalText(second));
        return 1u;
    case SphereUIUiMessage::getTooltipLine:
        if (const auto *control = tooltip(window); control != nullptr && second < control->lines.size())
            writeText(first, control->lines.at(second));
        return 1u;
    case SphereUIUiMessage::appendTooltipLine:
        if (auto *control = tooltip(window))
            control->appendLine(text(first));
        return 1u;
    case SphereUIUiMessage::getProgressRange:
        if (const auto *control = window != nullptr ? window->asProgressBar() : nullptr)
        {
            write(first, control->minimum);
            write(second, control->maximum);
        }
        return 1u;
    case SphereUIUiMessage::getProgressValue:
        if (const auto *control = window != nullptr ? window->asProgressBar() : nullptr)
            write(first, control->current);
        return 1u;
    case SphereUIUiMessage::getScrollRange:
        if (const auto *control = window != nullptr ? window->asScrollBar() : nullptr)
        {
            write(first, control->minimum);
            write(second, control->maximum);
        }
        return 1u;
    case SphereUIUiMessage::setScrollParameters:
        if (auto *control = window != nullptr ? window->asScrollBar() : nullptr; control != nullptr && first != 0u)
        {
            const auto wire = read<MbcScrollParameters32>(first);
            control->setParameters({wire.size, wire.mask, wire.minimum, wire.maximum, wire.page_step, wire.current, wire.step});
        }
        return 1u;
    case SphereUIUiMessage::getScrollParameters:
        if (const auto *control = window != nullptr ? window->asScrollBar() : nullptr; control != nullptr && first != 0u)
        {
            auto wire = read<MbcScrollParameters32>(first);
            SphereUIScrollParameters parameters{wire.size, wire.mask, wire.minimum, wire.maximum, wire.page_step, wire.current, wire.step};
            control->getParameters(parameters);
            wire.minimum = parameters.minimum;
            wire.maximum = parameters.maximum;
            wire.page_step = parameters.page_step;
            wire.current = parameters.current;
            wire.step = parameters.step;
            write(first, wire);
        }
        return 1u;
    case SphereUIUiMessage::getScrollValue:
        if (const auto *control = window != nullptr ? window->asScrollBar() : nullptr)
            write(first, control->current);
        return 1u;
    case SphereUIUiMessage::getSpinRange:
        if (const auto *control = window != nullptr ? window->asSpinButton() : nullptr)
        {
            write(first, control->minimum);
            write(second, control->maximum);
        }
        return 1u;
    case SphereUIUiMessage::getSpinStep:
        if (const auto *control = window != nullptr ? window->asSpinButton() : nullptr)
            write(first, control->step);
        return 1u;
    case SphereUIUiMessage::getSpinValue:
        if (const auto *control = window != nullptr ? window->asSpinButton() : nullptr)
            write(first, control->current);
        return 1u;
    case SphereUIUiMessage::appendMenuItem:
        if (auto *control = window != nullptr ? window->asMenuListControl() : nullptr)
            control->addItem(text(first), second != 0u);
        return 1u;
    case SphereUIUiMessage::setMenuItemText:
        if (auto *control = window != nullptr ? window->asMenuListControl() : nullptr; control != nullptr && first < control->items.size())
            control->items.at(first).text.assign(second == 0u ? std::string_view{} : runtime_.textAt(second));
        return 1u;
    case SphereUIUiMessage::setSlotItem:
        if (auto *control = window != nullptr ? window->asSlotCtrl() : nullptr)
            control->setItem(optionalText(first));
        return 1u;
    case SphereUIUiMessage::setSlotDescription:
        if (auto *control = window != nullptr ? window->asSlotCtrl() : nullptr)
            control->description.assign(first == 0u ? std::string_view{} : runtime_.textAt(first));
        return 1u;
    case SphereUIUiMessage::setSlotTopLeftOverlay:
    case SphereUIUiMessage::setSlotBottomRightOverlay:
    case SphereUIUiMessage::setSlotBottomLeftOverlay:
        if (auto *control = window != nullptr ? window->asSlotCtrl() : nullptr)
        {
            auto &target = message == SphereUIUiMessage::setSlotTopLeftOverlay       ? control->top_left_overlay
                           : message == SphereUIUiMessage::setSlotBottomRightOverlay ? control->bottom_right_overlay
                                                                                     : control->bottom_left_overlay;
            control->setOverlay(target, optionalText(first));
        }
        return 1u;
    case SphereUIUiMessage::setRichEditContent:
        if (auto *control = window != nullptr ? window->asRichEditCtrl() : nullptr; control != nullptr && first != 0u)
            control->setContent(runtime_.textAt(first));
        return 1u;
    case SphereUIUiMessage::getRichEditContent:
        if (const auto *control = window != nullptr ? window->asRichEditCtrl() : nullptr; control != nullptr && first != 0u && second != 0u)
        {
            auto destination = runtime_.memoryRange(first);
            const auto capacity = std::min<std::size_t>(destination.size(), second);
            SferaTextBuffer(destination.first(capacity)).write(control->content(capacity == 0 ? 0 : capacity - 1));
        }
        return 1u;
    case SphereUIUiMessage::loadHyperTextPage:
        if (auto *control = window != nullptr ? window->asHyperTextCtrl() : nullptr)
            control->queuePage(text(first), second != 0u);
        return 1u;
    case SphereUIUiMessage::loadHyperTextBuffer:
        if (auto *control = window != nullptr ? window->asHyperTextCtrl() : nullptr; control != nullptr && first != 0u && second != 0u)
        {
            const auto source = bytes(first, second);
            control->queueBuffer(SferaText::fromBytes(source));
        }
        return 1u;
    case SphereUIUiMessage::appendChatMessage:
        if (auto *control = window != nullptr ? window->asHyperTextChatListControl() : nullptr; control != nullptr && first != 0u && second != 0u)
        {
            const auto parameters = words(second, 2u);
            control->addMessage(runtime_.textAt(first), parameters[0], parameters[1]);
        }
        return 1u;
    case SphereUIUiMessage::setChatChannels:
        if (auto *control = window != nullptr ? window->asHyperTextChatListControl() : nullptr)
        {
            if (first == 0u)
                control->setChannels(std::span<const std::uint32_t>{});
            else if (second != 0u)
            {
                const auto values = words(second, first);
                control->setChannels(std::span<const std::uint32_t>(values));
            }
        }
        return 1u;
    case SphereUIUiMessage::getChatPlainText:
    case SphereUIUiMessage::getChatHyperText:
        if (const auto *control = window != nullptr ? window->asHyperTextChatListControl() : nullptr)
            writeText(second, control->messageText(first, message == SphereUIUiMessage::getChatPlainText));
        return 1u;
    case SphereUIUiMessage::getSelectedChatLink:
        if (const auto *control = window != nullptr ? window->asHyperTextChatListControl() : nullptr)
        {
            writeText(first, control->selected_link_text);
            writeText(second, control->selected_link_value);
        }
        return 1u;
    case SphereUIUiMessage::getSelectedChatHyperText:
        if (const auto *control = window != nullptr ? window->asHyperTextChatListControl() : nullptr)
            writeText(first, control->selected_hyper_text);
        return 1u;
    case SphereUIUiMessage::getSelectedChatPlainText:
        if (const auto *control = window != nullptr ? window->asHyperTextChatListControl() : nullptr)
            writeText(first, control->selected_plain_text);
        return 1u;
    case SphereUIUiMessage::setHyperEditContent:
        if (auto *control = window != nullptr ? window->asHyperTextEditControl() : nullptr; control != nullptr && first != 0u)
            control->setContent(runtime_.textAt(first), second);
        return 1u;
    case SphereUIUiMessage::getHyperEditPlainText:
        if (const auto *control = window != nullptr ? window->asHyperTextEditControl() : nullptr)
            writeText(first, control->visible_text);
        return 1u;
    case SphereUIUiMessage::getHyperEditHyperText:
        if (const auto *control = window != nullptr ? window->asHyperTextEditControl() : nullptr)
            writeText(first, control->hyper_text);
        return 1u;
    case SphereUIUiMessage::getHyperEditLengths:
        if (const auto *control = window != nullptr ? window->asHyperTextEditControl() : nullptr)
        {
            writeSize(first, control->visible_text.size());
            writeSize(second, control->hyper_text.size());
        }
        return 1u;
    default:
        break;
    }

    if ((flags_ & 3u) != 0u)
    {
        runtime_.reportError("Unsupported pointer-bearing UI message");
        return 0u;
    }
    return g_sfera_interface.sendMessage(window, message, first, second);
}

void WorldGuiControlSupport::eraseGuiControl(std::uint32_t handle, const GameUiElement &item)
{
    WorldGuiControls::detachFromWindow(item.windowHandle, item.windowSlot);
    WorldGuiControls::elements.at(handle).reset();
}
