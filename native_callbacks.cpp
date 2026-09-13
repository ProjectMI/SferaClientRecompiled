#include "native_callbacks.h"
#include "semantic_static.h"
#include "import_bridge.h"

#include <exception>
#include <exdisp.h>
#include <mshtml.h>
#include <algorithm>
#include <array>
#include <cctype>
#include <cstddef>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <io.h>
#include <iterator>
#include <new>
#include <sys/stat.h>
#include <sys/utime.h>
#include <string>
#include <vector>

namespace {
constexpr std::size_t kTcpSendBufferCapacity = 80000u;
constexpr std::size_t kPathBufferCapacity = 1024u;
constexpr std::size_t kFileCrcBufferCapacity = 16384u;
constexpr std::uint32_t kNetworkProbeIntervalSlices = 20u;
constexpr DWORD kNetworkProbeIntervalSliceMs = 200u;
constexpr WPARAM kSystemCommandMask = 0xFFF0u;
constexpr DWORD kMsvcCppExceptionCode = 0xE06D7363u;
constexpr ULONG_PTR kMsvcCppExceptionMagic19930520 = 0x19930520u;
constexpr ULONG_PTR kMsvcCppExceptionMagic19930521 = 0x19930521u;
constexpr ULONG_PTR kMsvcCppExceptionMagic19930522 = 0x19930522u;
constexpr ULONG_PTR kMsvcCppExceptionMagicPure = 0x01994000u;


constexpr DWORD kDirectPlayConnectComplete = 0xFFFF0005u;
constexpr DWORD kDirectPlayCreatePlayer = 0xFFFF0007u;
constexpr DWORD kDirectPlayDestroyPlayer = 0xFFFF0009u;
constexpr DWORD kDirectPlayIndicateConnect = 0xFFFF000Eu;
constexpr DWORD kDirectPlayConnectAborted = 0xFFFF000Fu;
constexpr DWORD kDirectPlayReceive = 0xFFFF0011u;
constexpr DWORD kDirectPlayTerminateSession = 0xFFFF0016u;
constexpr DWORD kDirectPlayHeartbeatTimeoutMs = 180000u;
constexpr DWORD kDirectPlayHeartbeatSendFlags = 184u;

FILE* open_file(const char* path, const char* mode) noexcept {
    FILE* file = nullptr;
    return path && mode && ::fopen_s(&file, path, mode) == 0 ? file : nullptr;
}

}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::Storage::QueryInterface(REFIID iid, void** output) {
    if (!output) {
        return E_POINTER;
    }
    *output = nullptr;
    if (InlineIsEqualGUID(iid, __uuidof(IUnknown)) || InlineIsEqualGUID(iid, __uuidof(IStorage))) {
        *output = static_cast<IStorage*>(this);
    } else {
        return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
}

SferaBrowserHost::SferaBrowserHost(HWND window) noexcept : window_(window) {
}

SferaBrowserHost::~SferaBrowserHost() {
    if (!object_) {
        return;
    }
    object_->Close(OLECLOSE_NOSAVE);
    object_->Release();
}

HRESULT SferaBrowserHost::create() noexcept {
    HRESULT result = ::OleCreate(CLSID_WebBrowser, __uuidof(IOleObject), OLERENDER_DRAW, nullptr, static_cast<IOleClientSite*>(this), &storage_, reinterpret_cast<void**>(&object_));
    if (FAILED(result) || !object_) {
        return FAILED(result) ? result : E_FAIL;
    }
    object_->SetHostNames(L"My Host Name", nullptr);
    RECT bounds{};
    ::GetClientRect(window_, &bounds);
    result = ::OleSetContainedObject(object_, TRUE);
    if (SUCCEEDED(result)) {
        result = object_->DoVerb(OLEIVERB_SHOW, nullptr, static_cast<IOleClientSite*>(this), -1, window_, &bounds);
    }
    if (FAILED(result)) {
        return result;
    }
    IWebBrowser2* browser = nullptr;
    result = object_->QueryInterface(__uuidof(IWebBrowser2), reinterpret_cast<void**>(&browser));
    if (FAILED(result) || !browser) {
        return FAILED(result) ? result : E_NOINTERFACE;
    }
    browser->put_Left(0);
    browser->put_Top(0);
    browser->put_Width(bounds.right);
    browser->put_Height(bounds.bottom);
    browser->Release();
    return S_OK;
}

void SferaBrowserHost::resize(LONG width, LONG height) noexcept {
    if (!object_) {
        return;
    }
    IWebBrowser2* browser = nullptr;
    if (SUCCEEDED(object_->QueryInterface(__uuidof(IWebBrowser2), reinterpret_cast<void**>(&browser))) && browser) {
        browser->put_Width(width);
        browser->put_Height(height);
        browser->Release();
    }
}

HWND SferaBrowserHost::documentWindow() noexcept {
    if (!object_) {
        return nullptr;
    }
    IWebBrowser2* browser = nullptr;
    if (FAILED(object_->QueryInterface(__uuidof(IWebBrowser2), reinterpret_cast<void**>(&browser))) || !browser) {
        return nullptr;
    }
    IDispatch* document = nullptr;
    const HRESULT document_result = browser->get_Document(&document);
    browser->Release();
    if (FAILED(document_result) || !document) {
        return nullptr;
    }
    IHTMLDocument2* html_document = nullptr;
    const HRESULT html_result = document->QueryInterface(__uuidof(IHTMLDocument2), reinterpret_cast<void**>(&html_document));
    document->Release();
    if (FAILED(html_result) || !html_document) {
        return nullptr;
    }
    IOleWindow* ole_window = nullptr;
    const HRESULT window_result = html_document->QueryInterface(__uuidof(IOleWindow), reinterpret_cast<void**>(&ole_window));
    html_document->Release();
    if (FAILED(window_result) || !ole_window) {
        return nullptr;
    }
    HWND result = nullptr;
    ole_window->GetWindow(&result);
    ole_window->Release();
    return result;
}

void SferaBrowserHost::refresh() noexcept {
    if (!object_) {
        return;
    }
    IWebBrowser2* browser = nullptr;
    if (SUCCEEDED(object_->QueryInterface(__uuidof(IWebBrowser2), reinterpret_cast<void**>(&browser))) && browser) {
        browser->Refresh();
        browser->Release();
    }
}

HRESULT SferaBrowserHost::draw(HDC target, LONG width, LONG height) noexcept {
    if (!object_) {
        return E_FAIL;
    }
    IViewObject2* view = nullptr;
    const HRESULT query_result = object_->QueryInterface(__uuidof(IViewObject2), reinterpret_cast<void**>(&view));
    if (FAILED(query_result) || !view) {
        return FAILED(query_result) ? query_result : E_NOINTERFACE;
    }
    const RECTL bounds{0, 0, width, height};
    const HRESULT result = view->Draw(DVASPECT_CONTENT, -1, nullptr, nullptr, nullptr, target, &bounds, nullptr, nullptr, 0u);
    view->Release();
    return result;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::QueryInterface(REFIID iid, void** output) {
    if (!output) {
        return E_POINTER;
    }
    *output = nullptr;
    if (InlineIsEqualGUID(iid, __uuidof(IUnknown)) || InlineIsEqualGUID(iid, __uuidof(IOleClientSite))) {
        *output = static_cast<IOleClientSite*>(this);
    } else if (InlineIsEqualGUID(iid, __uuidof(IOleWindow)) || InlineIsEqualGUID(iid, __uuidof(IOleInPlaceSite))) {
        *output = static_cast<IOleInPlaceSite*>(this);
    } else if (InlineIsEqualGUID(iid, __uuidof(IOleInPlaceUIWindow)) || InlineIsEqualGUID(iid, __uuidof(IOleInPlaceFrame))) {
        *output = static_cast<IOleInPlaceFrame*>(this);
    } else if (InlineIsEqualGUID(iid, __uuidof(IDocHostUIHandler))) {
        *output = static_cast<IDocHostUIHandler*>(this);
    } else {
        return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::GetContainer(IOleContainer** output) {
    if (output) {
        *output = nullptr;
    }
    return E_NOINTERFACE;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::GetWindow(HWND* output) {
    if (!output) {
        return E_POINTER;
    }
    *output = window_;
    return S_OK;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::GetWindowContext(IOleInPlaceFrame** frame, IOleInPlaceUIWindow** document, LPRECT, LPRECT, LPOLEINPLACEFRAMEINFO info) {
    if (frame) {
        *frame = static_cast<IOleInPlaceFrame*>(this);
    }
    if (document) {
        *document = nullptr;
    }
    if (info) {
        info->cb = sizeof(*info);
        info->fMDIApp = FALSE;
        info->hwndFrame = window_;
        info->haccel = nullptr;
        info->cAccelEntries = 0u;
    }
    return S_OK;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::OnPosRectChange(LPCRECT rect) {
    if (!object_ || !rect) {
        return S_OK;
    }
    IOleInPlaceObject* inplace = nullptr;
    if (SUCCEEDED(object_->QueryInterface(__uuidof(IOleInPlaceObject), reinterpret_cast<void**>(&inplace))) && inplace) {
        inplace->SetObjectRects(rect, rect);
        inplace->Release();
    }
    return S_OK;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::GetHostInfo(DOCHOSTUIINFO* info) {
    if (!info) {
        return E_POINTER;
    }
    info->cbSize = sizeof(*info);
    info->dwFlags = DOCHOSTUIFLAG_NO3DBORDER;
    info->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;
    return S_OK;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::GetOptionKeyPath(LPOLESTR* output, DWORD) {
    if (output) {
        *output = nullptr;
    }
    return S_FALSE;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::GetDropTarget(IDropTarget*, IDropTarget** output) {
    if (output) {
        *output = nullptr;
    }
    return S_FALSE;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::GetExternal(IDispatch** output) {
    if (output) {
        *output = nullptr;
    }
    return S_FALSE;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::TranslateUrl(DWORD, OLECHAR*, OLECHAR** output) {
    if (output) {
        *output = nullptr;
    }
    return S_FALSE;
}

HRESULT STDMETHODCALLTYPE SferaBrowserHost::FilterDataObject(IDataObject*, IDataObject** output) {
    if (output) {
        *output = nullptr;
    }
    return S_FALSE;
}

namespace {

void append_net_log(const char* message) noexcept {
    if (!message) {
        return;
    }
    FILE* file = open_file("Net.log", "at");
    if (!file) {
        return;
    }
    __time64_t now = 0;
    _time64(&now);
    tm local{};
    char timestamp[128]{};
    if (_localtime64_s(&local, &now) == 0) {
        std::strftime(timestamp, sizeof(timestamp), "%d/%m %H:%M:%S ", &local);
    }
    std::fputs(timestamp, file);
    std::fputs(message, file);
    std::fclose(file);
}

void log_directplay_message(DWORD message) noexcept {
    switch (message) {
    case kDirectPlayConnectComplete:
    case kDirectPlayTerminateSession:
    case kDirectPlayDestroyPlayer:
    case kDirectPlayIndicateConnect:
    case kDirectPlayConnectAborted:
    case kDirectPlayCreatePlayer:
        break;
    default:
        return;
    }
    char text[36]{};
    std::snprintf(text, sizeof(text), "MessID: %u\n", static_cast<unsigned>(LOWORD(message)));
    append_net_log(text);
}

SferaNetworkMessageSlot* acquire_directplay_receive_slot() noexcept {
    auto* critical_section = &g_sfera_directplay_runtime.critical_section;
    ::EnterCriticalSection(critical_section);
    auto& transport = g_sfera_directplay_runtime.transport;
    const std::uint32_t write_index = transport.receive_write_index;
    if (transport.receive_busy != 0u) {
        transport.receive_corrupted = 1u;
        if (write_index != transport.receive_read_index) {
            transport.receive_corrupted = 0u;
        }
    } else {
        transport.receive_corrupted = 0u;
    }
    auto* slot = &g_sfera_network_runtime.message_slots[write_index];
    transport.receive_write_index = write_index + 1u < kSferaNetworkMessageSlotCount ? write_index + 1u : 0u;
    transport.receive_busy = 1u;
    ::LeaveCriticalSection(critical_section);
    return slot;
}

}

int __cdecl sfera_compare_record_key(const void* left, const void* right) noexcept {
    return static_cast<int>(*static_cast<const std::uint32_t*>(left) - *static_cast<const std::uint32_t*>(right));
}

static std::int32_t create_browser_control(HWND window) noexcept {
    auto* host = new (std::nothrow) SferaBrowserHost(window);
    if (!host) {
        return -1;
    }
    const HRESULT result = host->create();
    if (FAILED(result)) {
        delete host;
        return -2;
    }
    ::SetWindowLongPtrA(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(host));
    return 0;
}
static void resize_browser_control(HWND window, LONG width, LONG height) noexcept {
    auto* host = reinterpret_cast<SferaBrowserHost*>(::GetWindowLongPtrA(window, GWLP_USERDATA));
    if (host) {
        host->resize(width, height);
    }
}
static void destroy_browser_control(HWND window) noexcept {
    auto* host = reinterpret_cast<SferaBrowserHost*>(::GetWindowLongPtrA(window, GWLP_USERDATA));
    ::SetWindowLongPtrA(window, GWLP_USERDATA, 0);
    delete host;
}
HWND sfera_browser_document_window(HWND window) noexcept {
    auto* host = reinterpret_cast<SferaBrowserHost*>(::GetWindowLongPtrA(window, GWLP_USERDATA));
    return host ? host->documentWindow() : nullptr;
}
void sfera_browser_refresh(HWND window) noexcept {
    auto* host = reinterpret_cast<SferaBrowserHost*>(::GetWindowLongPtrA(window, GWLP_USERDATA));
    if (host) {
        host->refresh();
    }
}
HRESULT sfera_browser_draw(HWND window, HDC target, LONG width, LONG height) noexcept {
    auto* host = reinterpret_cast<SferaBrowserHost*>(::GetWindowLongPtrA(window, GWLP_USERDATA));
    return host ? host->draw(target, width, height) : E_FAIL;
}

LRESULT CALLBACK sfera_browser_host_window_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
    switch (message) {
    case WM_CREATE: return create_browser_control(window) == 0 ? 0 : -1;
    case WM_DESTROY: destroy_browser_control(window); return 1;
    case WM_SIZE: resize_browser_control(window, LOWORD(lparam), HIWORD(lparam)); return 0;
    default: return ::DefWindowProcA(window, message, wparam, lparam);
    }
}

LRESULT CALLBACK sfera_browser_subclass_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
    if (message == WM_LBUTTONDOWN || message == WM_LBUTTONUP) {
        return 0;
    }
    if ((message == WM_KEYDOWN || message == WM_KEYUP) && wparam == VK_ESCAPE) {
        ::SendMessageA(reinterpret_cast<HWND>(static_cast<std::uintptr_t>(g_sfera_window_runtime.main_window)), message, wparam, lparam);
    }
    if (g_sfera_browser_window_runtime.original_window_proc) {
        return ::CallWindowProcA(g_sfera_browser_window_runtime.original_window_proc, window, message, wparam, lparam);
    }
    return ::DefWindowProcA(window, message, wparam, lparam);
}

LRESULT CALLBACK sfera_main_window_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
    switch (message) {
    case WM_ACTIVATEAPP:
        g_sfera_texture_cache_runtime.cache_enabled = g_sfera_window_runtime.windowed != 0u && g_sfera_client_config_runtime.state_23 != 0u ? 1u : static_cast<std::uint32_t>(wparam);
        ::SI_SetStreamVolume(::SI_GetStreamVolume());
        g_sfera_client_config_runtime.scalar_01 = 0.0;
        g_sfera_client_config_runtime.state_10 = 1u;
        return 0;
    case WM_QUERYENDSESSION:
        ::PostQuitMessage(0);
        return 0;
    case WM_CLOSE:
        ::PostQuitMessage(0);
        return 0;
    case WM_SETCURSOR:
        if (CCursorManager::hasActiveCursor()) {
            return TRUE;
        }
        return 0;
    case WM_KEYDOWN:
        if (g_sfera_client_process_runtime.ui_bridge != 0u) {
            g_sfera_main_command_state_runtime.command_state = static_cast<std::uint32_t>(wparam);
            return 0;
        }
        if (g_sfera_texture_cache_runtime.render_gate != 0u) {
            const std::uint32_t key = static_cast<std::uint32_t>(wparam);
            if (key < 256u && g_sfera_font_runtime.glyphs[key].defined != 0u && g_sfera_static_render_lookup_runtime.glyph_presence[key] == 0u) {
                return 0;
            }
        }
        if (g_sfera_scene_control_runtime.context_count < 30u) {
            g_sfera_scene_control_runtime.context_queue[g_sfera_scene_control_runtime.context_count++] = static_cast<std::uint32_t>(wparam);
        }
        return 0;
    case WM_CHAR: {
        const std::uint32_t ch = static_cast<std::uint32_t>(wparam);
        if (ch < 256u && g_sfera_font_runtime.glyphs[ch].defined == 1u && g_sfera_pending_key_runtime.count < 30u) {
            g_sfera_pending_key_runtime.key_codes[g_sfera_pending_key_runtime.count++] = ch;
        }
        return 0;
    }
    case WM_SYSCOMMAND: {
        const WPARAM command = wparam & kSystemCommandMask;
        if (command == SC_SCREENSAVE || command == SC_MONITORPOWER) {
            return 0;
        }
        return ::DefWindowProcA(window, message, wparam, lparam);
    }
    default: return ::DefWindowProcA(window, message, wparam, lparam);
    }
}

INT_PTR CALLBACK sfera_dialog_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
    auto* dialog = reinterpret_cast<SferaDialogState*>(::GetWindowLongPtrA(window, GWLP_USERDATA));
    if (dialog != nullptr) dialog->recordMessage(window, message, wparam, lparam);
    return 0;
}

LONG WINAPI sfera_unhandled_exception_filter(EXCEPTION_POINTERS* exception) noexcept {
    const char* path = g_sfera_crash_report_runtime.error_log_path[0] ? g_sfera_crash_report_runtime.error_log_path : "sphere_error.log";
    HANDLE file = ::CreateFileA(path, GENERIC_WRITE, 0u, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        return EXCEPTION_EXECUTE_HANDLER;
    }
    g_sfera_crash_report_runtime.error_log_handle = file;
    char line[1024]{};
    const DWORD code = exception && exception->ExceptionRecord ? exception->ExceptionRecord->ExceptionCode : 0u;
    const void* address = exception && exception->ExceptionRecord ? exception->ExceptionRecord->ExceptionAddress : nullptr;
    SYSTEMTIME time{};
    ::GetLocalTime(&time);
    const int length = std::snprintf(line, sizeof(line), "Exception!\r\n%02u:%02u:%02u\r\ncode=0x%08lX address=%p\r\nEnd of exception\r\n", time.wHour, time.wMinute, time.wSecond, static_cast<unsigned long>(code), address);
    DWORD written = 0u;
    if (length > 0) {
        ::WriteFile(file, line, static_cast<DWORD>(std::min<int>(length, static_cast<int>(sizeof(line) - 1u))), &written, nullptr);
    }
    if (exception && exception->ContextRecord) {
    }
    ::CloseHandle(file);
    g_sfera_crash_report_runtime.error_log_handle = nullptr;
    return EXCEPTION_EXECUTE_HANDLER;
}

LONG WINAPI sfera_cpp_exception_filter(EXCEPTION_POINTERS* exception) noexcept {
    if (!exception || !exception->ExceptionRecord) {
        return EXCEPTION_CONTINUE_SEARCH;
    }
    const EXCEPTION_RECORD& record = *exception->ExceptionRecord;
    if (record.ExceptionCode != kMsvcCppExceptionCode || record.NumberParameters != 3u) {
        return EXCEPTION_CONTINUE_SEARCH;
    }
    const ULONG_PTR magic = record.ExceptionInformation[0];
    if (magic == kMsvcCppExceptionMagic19930520 || magic == kMsvcCppExceptionMagic19930521 || magic == kMsvcCppExceptionMagic19930522 || magic == kMsvcCppExceptionMagicPure) {
        std::terminate();
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

static void tcp_log_line(const char* suffix, const char* message) noexcept {
    if (!suffix || !message) {
        return;
    }
    char path[kPathBufferCapacity]{};
    std::snprintf(path, sizeof(path), "logs\\%u%s", g_sfera_recovered_static_runtime.server_number, suffix);
    FILE* file = open_file(path, "at");
    if (!file) {
        return;
    }
    std::fseek(file, 0, SEEK_END);
    if (std::ftell(file) > 10000000L) {
        std::fclose(file);
        file = open_file(path, "w");
        if (file) {
            std::fclose(file);
        }
        file = open_file(path, "at");
        if (!file) {
            return;
        }
    }
    SYSTEMTIME time{};
    ::GetLocalTime(&time);
    std::fprintf(file, "%02u.%02u.%04u %02u:%02u:%02u %s", time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute, time.wSecond, message);
    std::fclose(file);
}

static void send_pending_tcp(SferaTcpConnectionContext& context) noexcept {
    if (!context.connected || !context.send_buffer) {
        return;
    }
    auto* critical_section = &g_sfera_network_send_runtime.critical_section;
    ::EnterCriticalSection(critical_section);
    if (context.send_size != 0u) {
        const int sent = ::send(context.socket, reinterpret_cast<const char*>(context.send_buffer), static_cast<int>(context.send_size), 0);
        if (sent >= 0) {
            if (static_cast<std::uint32_t>(sent) < context.send_size) {
                std::memmove(context.send_buffer, context.send_buffer + sent, context.send_size - static_cast<std::uint32_t>(sent));
            }
            context.send_size -= static_cast<std::uint32_t>(sent);
            context.sent_bytes_window += static_cast<std::uint32_t>(sent);
        }
    }
    ::LeaveCriticalSection(critical_section);
}

static bool queue_tcp_packet(SferaTcpConnectionContext& context, std::uint32_t payload_size, TcpMessage message, const void* payload) noexcept {
    auto* critical_section = &g_sfera_network_send_runtime.critical_section;
    ::EnterCriticalSection(critical_section);
    const std::uint32_t packet_size = payload_size + sizeof(SferaTcpOutgoingHeader);
    if (!context.send_buffer || kTcpSendBufferCapacity - context.send_size < packet_size) {
        tcp_log_line("tcp_ip_connect.log", "-------------------------ERROR: send buffer overload\n");
        g_sfera_network_runtime.initialization_result = UINT32_MAX;
        if (context.socket != 0u && context.socket != INVALID_SOCKET) {
            ::closesocket(context.socket);
        }
        ::WSACleanup();
        context.connected = 0u;
        ::LeaveCriticalSection(critical_section);
        return false;
    }
    context.sequence = static_cast<std::uint16_t>(context.sequence + static_cast<std::uint16_t>(std::rand() % 4 + 1));
    auto* packet = reinterpret_cast<SferaTcpOutgoingHeader*>(context.send_buffer + context.send_size);
    packet->size = static_cast<std::uint16_t>(packet_size);
    packet->checksum = 0u;
    packet->sequence = context.sequence;
    packet->message = static_cast<std::uint16_t>(message);
    if (payload_size != 0u && payload) {
        std::memcpy(packet + 1, payload, payload_size);
    }
    std::uint16_t checksum = 0u;
    const auto* bytes = reinterpret_cast<const std::int8_t*>(&packet->sequence);
    for (std::uint32_t index = 0u; index < packet_size - offsetof(SferaTcpOutgoingHeader, sequence); ++index) {
        checksum = static_cast<std::uint16_t>(checksum + bytes[index]);
    }
    packet->checksum = static_cast<std::uint16_t>(context.checksum_seed ^ checksum);
    context.send_size += packet_size;
    ++context.packet_counter;
    ::LeaveCriticalSection(critical_section);
    return true;
}

static void enqueue_directplay_receive(const SferaDirectPlayReceivePayload& payload) noexcept {
    SferaNetworkMessageSlot* slot = acquire_directplay_receive_slot();
    auto& transport = g_sfera_directplay_runtime.transport;
    ++transport.sent_packet_count;
    slot->message = kDirectPlayReceive;
    slot->sender = payload.sender;
    slot->buffer_handle = UINT32_MAX;
    const std::uint32_t previous_low = transport.sent_bytes.low;
    transport.sent_bytes.low += payload.data_size;
    transport.sent_bytes.high += transport.sent_bytes.low < previous_low ? 1u : 0u;
    slot->data_size = std::min<std::uint32_t>(payload.data_size, static_cast<std::uint32_t>(sizeof(slot->data) - 1u));
    if (slot->data_size != 0u && payload.data) {
        std::memcpy(slot->data, payload.data, slot->data_size);
    }
}

static void dispatch_tcp_receive_packets(SferaTcpConnectionContext& context) noexcept {
    auto* critical_section = &g_sfera_recovered_static_runtime.scene_lock;
    for (;;) {
        ::EnterCriticalSection(critical_section);
        const auto* header = reinterpret_cast<const SferaTcpIncomingHeader*>(context.receive_buffer);
        const std::uint16_t packet_size = context.receive_size >= sizeof(SferaTcpIncomingHeader) ? header->size : 0u;
        const bool complete = context.receive_size >= sizeof(SferaTcpIncomingHeader) && context.receive_size >= packet_size;
        ::LeaveCriticalSection(critical_section);
        if (!complete) {
            return;
        }
        if (header->message == static_cast<std::uint16_t>(TcpMessage::payload)) {
            const SferaDirectPlayReceivePayload payload{sizeof(SferaDirectPlayReceivePayload), context.remote_id, nullptr, context.receive_buffer + sizeof(SferaTcpIncomingHeader), packet_size - sizeof(SferaTcpIncomingHeader), UINT32_MAX};
            enqueue_directplay_receive(payload);
        }
        ::EnterCriticalSection(critical_section);
        std::memmove(context.receive_buffer, context.receive_buffer + packet_size, context.receive_size - packet_size);
        context.receive_size -= packet_size;
        ::LeaveCriticalSection(critical_section);
    }
}

static bool append_sound_event(SoundEventQueue* queue, const SoundEventRecord& event, float signal, std::uint32_t position) noexcept {
    if (!queue) {
        return false;
    }
    if (!queue->records || queue->count >= queue->capacity) {
        const std::uint32_t next_capacity = queue->capacity == 0u ? queue->growth : queue->capacity + queue->growth;
        if (next_capacity == 0u) {
            return false;
        }
        void* memory = queue->records ? std::realloc(queue->records, sizeof(SoundEventRecord) * next_capacity) : std::malloc(sizeof(SoundEventRecord) * next_capacity);
        if (!memory) {
            return false;
        }
        queue->records = static_cast<SoundEventRecord*>(memory);
        queue->capacity = next_capacity;
    }
    queue->records[queue->count++] = SoundEventRecord{event.type, event.argument, signal, position};
    return true;
}

static bool pop_sound_event(SoundEventQueue* queue, SoundEventRecord& record) noexcept {
    if (!queue || !queue->records || queue->count == 0u) {
        return false;
    }
    record = queue->records[0];
    --queue->count;
    if (queue->count != 0u) {
        std::move(queue->records + 1u, queue->records + queue->count + 1u, queue->records);
    }
    return true;
}

static SoundEventRecord next_sound_event(SferaSoundPlaybackState& state) noexcept { return state.nextEvent(); }

static std::int32_t run_network_probe() noexcept {
    std::array<char, kPathBufferCapacity> system_directory{};
    STARTUPINFOA startup{};
    startup.cb = sizeof(startup);
    PROCESS_INFORMATION process{};
    const DWORD started_at = ::timeGetTime();
    const UINT directory_length = ::GetSystemDirectoryA(system_directory.data(), static_cast<UINT>(system_directory.size()));
    if (directory_length == 0u || directory_length >= system_directory.size()) {
        return -1;
    }
    std::string command_line(system_directory.data(), directory_length);
    command_line += "\\ping.exe -n 1 ";
    command_line += g_sfera_network_probe_runtime.host;
    if (!::CreateProcessA(nullptr, command_line.data(), nullptr, nullptr, FALSE, CREATE_NO_WINDOW, nullptr, nullptr, &startup, &process)) {
        return -1;
    }
    const DWORD wait_result = ::WaitForSingleObject(process.hProcess, 30000u);
    if (wait_result == WAIT_TIMEOUT) {
        ::TerminateProcess(process.hProcess, 1u);
        ::CloseHandle(process.hProcess);
        return -1;
    }
    DWORD exit_code = 0u;
    const BOOL read_exit_code = ::GetExitCodeProcess(process.hProcess, &exit_code);
    ::CloseHandle(process.hProcess);
    if (!read_exit_code) {
        return -1;
    }
    if (exit_code == 1u) {
        return -2;
    }
    return static_cast<std::int32_t>(::timeGetTime() - started_at);
}

static void tcp_log_error(const char* format, int value) noexcept {
    char message[256]{};
    std::snprintf(message, sizeof(message), format, value);
    tcp_log_line("tcp_ip_connect.log", message);
}

DWORD WINAPI sfera_tcp_socket_receive_thread(void* parameter) noexcept {
    auto* context = static_cast<SferaTcpConnectionContext*>(parameter);
    if (!context) {
        return 0u;
    }
    std::vector<std::uint8_t> local_buffer(kTcpReceiveBufferCapacity);
    std::uint32_t buffered = 0u;
    DWORD stats_tick = ::GetTickCount();
    bool local_overload_reported = false;
    bool shared_overload_reported = false;
    bool terminate = false;
    while (!context->stop_requested && !terminate) {
        if (!context->connected) {
            ::Sleep(10u);
            continue;
        }
        const std::uint32_t free_space = static_cast<std::uint32_t>(kTcpReceiveBufferCapacity) - buffered;
        if (free_space == 0u) {
            if (!local_overload_reported) {
                tcp_log_line("tcp_ip_connect.log", "-------------------------ERROR: local rcv buffer overload\n");
                local_overload_reported = true;
            }
        } else {
            fd_set readable{};
            FD_SET(context->socket, &readable);
            timeval timeout{0, 10000};
            const int selected = ::select(0, &readable, nullptr, nullptr, &timeout);
            if (selected == SOCKET_ERROR) {
                tcp_log_error("-------------------------ERROR: select, err=%d\n", ::WSAGetLastError());
                g_sfera_network_runtime.initialization_result = UINT32_MAX;
                break;
            }
            if (FD_ISSET(context->socket, &readable)) {
                const int received = ::recv(context->socket, reinterpret_cast<char*>(local_buffer.data() + buffered), static_cast<int>(free_space), 0);
                const int socket_error = ::WSAGetLastError();
                if (received == SOCKET_ERROR) {
                    context->connected = 0u;
                    tcp_log_error("-------------------------LOST CONNECTION, err=%d\n", socket_error);
                    g_sfera_network_runtime.initialization_result = UINT32_MAX;
                    break;
                }
                if (received == 0) {
                    context->connected = 0u;
                    tcp_log_error("-------------------------CLOSE CONNECTION, err=%d\n", socket_error);
                    g_sfera_network_runtime.initialization_result = UINT32_MAX;
                    break;
                }
                buffered += static_cast<std::uint32_t>(received);
                context->received_bytes_window += static_cast<std::uint32_t>(received);
            }
        }
        while (buffered >= sizeof(SferaTcpIncomingHeader)) {
            const auto* header = reinterpret_cast<const SferaTcpIncomingHeader*>(local_buffer.data());
            const std::uint16_t packet_size = header->size;
            if (packet_size < sizeof(SferaTcpIncomingHeader) || packet_size > kTcpReceiveBufferCapacity) {
                tcp_log_line("tcp_ip_connect.log", "-------------------------ERROR: invalid packet size\n");
                g_sfera_network_runtime.initialization_result = UINT32_MAX;
                context->connected = 0u;
                buffered = 0u;
                terminate = true;
                break;
            }
            if (buffered < packet_size) {
                break;
            }
            const auto message = static_cast<TcpMessage>(header->message);
            if (message == TcpMessage::connection_limit) {
                tcp_log_line("tcp_ip_connect.log", "-------------------------IN(ERROR): (limit connections)\n");
                g_sfera_network_runtime.initialization_result = UINT32_MAX;
                context->connected = 0u;
                buffered = 0u;
                terminate = true;
                break;
            }
            if (message == TcpMessage::handshake && packet_size >= sizeof(SferaTcpHandshakePacket)) {
                const auto* handshake = reinterpret_cast<const SferaTcpHandshakePacket*>(local_buffer.data());
                context->checksum_seed = handshake->checksum_seed;
                context->remote_id = handshake->remote_id;
                const std::uint32_t mode = g_sfera_directplay_runtime.transport.mode;
                queue_tcp_packet(*context, sizeof(mode), TcpMessage::client_mode, &mode);
                g_sfera_network_runtime.initialization_result = 1u;
                context->sequence = static_cast<std::uint16_t>(std::rand() % 1000 + 1);
                char text[96]{};
                std::snprintf(text, sizeof(text), "Create connection: socket=%u\n", context->remote_id);
                tcp_log_line("tcp_ip_connect.log", text);
            } else if (message == TcpMessage::keepalive) {
                auto* timing = &g_sfera_window_runtime.timing_critical_section;
                ::EnterCriticalSection(timing);
                context->round_trip_ms = (::GetTickCount() - context->keepalive_started_at) / 3u;
                context->keepalive_answered = 1u;
                ::LeaveCriticalSection(timing);
            } else {
                auto* scene_lock = &g_sfera_recovered_static_runtime.scene_lock;
                ::EnterCriticalSection(scene_lock);
                if (kTcpReceiveBufferCapacity - context->receive_size >= packet_size) {
                    std::memcpy(context->receive_buffer + context->receive_size, local_buffer.data(), packet_size);
                    context->receive_size += packet_size;
                } else if (!shared_overload_reported) {
                    tcp_log_line("tcp_ip_connect.log", "-------------------------ERROR: rcv buffer overload\n");
                    shared_overload_reported = true;
                }
                ::LeaveCriticalSection(scene_lock);
            }
            std::memmove(local_buffer.data(), local_buffer.data() + packet_size, buffered - packet_size);
            buffered -= packet_size;
        }
        const DWORD now = ::GetTickCount();
        if (now - stats_tick > 1000u) {
            stats_tick = now;
            context->received_bytes_per_second = context->received_bytes_window;
            context->received_bytes_window = 0u;
        }
        ::Sleep(15u);
    }
    tcp_log_line("tcp_ip_connect.log", "Rcv Thread exit\n");
    context->sent_bytes_per_second = 0u;
    context->received_bytes_per_second = 0u;
    g_sfera_network_runtime.initialization_result = UINT32_MAX;
    if (context->socket != 0u && context->socket != INVALID_SOCKET) {
        ::closesocket(context->socket);
    }
    context->socket = 0u;
    ::WSACleanup();
    return 0u;
}

DWORD WINAPI sfera_check_files_thread(void* parameter) noexcept {
    auto* context = static_cast<SferaCheckFilesContext*>(parameter);
    if (context == nullptr) return 0u;
    try { context->run(); } catch (...) { context->running = false; }
    return 0u;
}

static std::uint32_t update_file_crc(FILE* file, std::uint32_t size) noexcept {
    if (!file) {
        return 0u;
    }
    std::vector<std::uint8_t> buffer(kFileCrcBufferCapacity);
    std::uint32_t crc = 0u;
    std::uint32_t remaining = size;
    std::rewind(file);
    while (remaining != 0u) {
        const std::size_t request = std::min<std::size_t>(buffer.size(), remaining);
        const std::size_t count = std::fread(buffer.data(), 1u, request, file);
        if (count == 0u) {
            break;
        }
        crc = g_sfera_crc32_runtime.calculate(buffer.data(), count, crc);
        remaining -= static_cast<std::uint32_t>(count);
    }
    g_sfera_crc32_runtime.current = crc;
    return crc;
}

static bool update_send(SOCKET socket, const void* data, int size) noexcept {
    const int sent = ::send(socket, static_cast<const char*>(data), size, 0);
    return sent == size;
}

static std::string update_destination_path(const char* request) {
    const char* name = request ? std::strrchr(request, '\\') : nullptr;
    if (name) {
        ++name;
    } else {
        name = request ? request : "";
    }
    return std::string("inbox\\") + name;
}

DWORD WINAPI sfera_update_download_thread(void* parameter) noexcept {
    auto* context = static_cast<SferaUpdateDownloadContext*>(parameter);
    if (!context) {
        return 0u;
    }
    auto finish = [context](UpdateDownloadState state) noexcept {
        context->state = state;
        context->completed = 1u;
    };
    g_sfera_crc32_runtime.initialize();
    __time64_t activity = _time64(nullptr);
    std::uint32_t expected_crc = 0u;
    std::uint32_t expected_size = 0u;
    std::uint32_t resume_offset = 0u;
    std::int32_t access_time = 0;
    std::int32_t modify_time = 0;
    std::string destination;
    std::string sidecar;
    FILE* output = nullptr;
    SferaUpdateMetadata response{};
    std::size_t response_used = 0u;
    std::array<std::uint8_t, 4096u> transfer{};
    while (!context->stop_requested) {
        const __time64_t now = _time64(nullptr);
        if (_difftime64(now, activity) > 15.0) {
            if (output) {
                std::fclose(output);
                output = nullptr;
            }
            ::WSACleanup();
            finish(UpdateDownloadState::failed);
            return 0u;
        }
        fd_set readable{};
        fd_set writable{};
        FD_SET(context->socket, &readable);
        FD_SET(context->socket, &writable);
        timeval timeout{0, 50000};
        const int selected = ::select(0, &readable, &writable, nullptr, &timeout);
        if (selected == SOCKET_ERROR) {
            if (output) {
                std::fclose(output);
            }
            ::WSACleanup();
            finish(UpdateDownloadState::failed);
            return 0u;
        }
        bool progressed = false;
        if (context->state == UpdateDownloadState::send_request && FD_ISSET(context->socket, &writable)) {
            const int length = static_cast<int>(std::strlen(context->request) + 1u);
            if (!update_send(context->socket, context->request, length)) {
                ::WSACleanup();
                finish(UpdateDownloadState::failed);
                return 0u;
            }
            context->state = UpdateDownloadState::receive_metadata;
            progressed = true;
        } else if (context->state == UpdateDownloadState::receive_metadata && FD_ISSET(context->socket, &readable)) {
            const int received = ::recv(context->socket, reinterpret_cast<char*>(&response) + response_used, static_cast<int>(sizeof(response) - response_used), 0);
            if (received <= 0) {
                ::WSACleanup();
                finish(UpdateDownloadState::failed);
                return 0u;
            }
            response_used += static_cast<std::size_t>(received);
            progressed = true;
            if (response_used == sizeof(response)) {
                expected_size = response.file_size;
                expected_crc = response.crc;
                access_time = response.access_time;
                modify_time = response.modify_time;
                context->expected_size = expected_size;
                destination = update_destination_path(context->request);
                sidecar = destination + ".crc";
                resume_offset = 0u;
                FILE* metadata = open_file(sidecar.c_str(), "rb");
                if (metadata) {
                    SferaUpdateSidecar stored{};
                    const bool valid_metadata = std::fread(&stored, sizeof(stored), 1u, metadata) == 1u;
                    std::fclose(metadata);
                    if (valid_metadata && stored.crc == expected_crc && stored.file_size == expected_size) {
                        struct _stat64i32 file_info{};
                        if (_stat64i32(destination.c_str(), &file_info) == 0 && file_info.st_size > 0) {
                            resume_offset = static_cast<std::uint32_t>(std::min<__int64>(file_info.st_size, expected_size));
                        }
                    } else {
                        std::remove(sidecar.c_str());
                    }
                }
                context->resume_offset = resume_offset;
                context->state = UpdateDownloadState::send_resume;
            }
        } else if (context->state == UpdateDownloadState::send_resume && FD_ISSET(context->socket, &writable)) {
            const SferaUpdateResumeRequest request{{'R', 'S', 'A'}, resume_offset};
            if (!update_send(context->socket, &request, static_cast<int>(sizeof(request)))) {
                ::WSACleanup();
                finish(UpdateDownloadState::failed);
                return 0u;
            }
            output = open_file(destination.c_str(), resume_offset == 0u ? "w+b" : "a+b");
            if (!output) {
                ::WSACleanup();
                finish(UpdateDownloadState::failed);
                return 0u;
            }
            context->output = output;
            if (resume_offset == 0u) {
                FILE* metadata = open_file(sidecar.c_str(), "wb");
                if (metadata) {
                    const SferaUpdateSidecar stored{expected_crc, expected_size};
                    std::fwrite(&stored, sizeof(stored), 1u, metadata);
                    std::fclose(metadata);
                }
            }
            context->state = UpdateDownloadState::receive_file;
            progressed = true;
        } else if (context->state == UpdateDownloadState::receive_file && FD_ISSET(context->socket, &readable)) {
            const int received = ::recv(context->socket, reinterpret_cast<char*>(transfer.data()), static_cast<int>(transfer.size()), 0);
            if (received <= 0 || !output || std::fwrite(transfer.data(), 1u, static_cast<std::size_t>(received), output) != static_cast<std::size_t>(received)) {
                if (output) {
                    std::fclose(output);
                    output = nullptr;
                    context->output = nullptr;
                }
                ::WSACleanup(); finish(UpdateDownloadState::failed); return 0u;
            }
            resume_offset += static_cast<std::uint32_t>(received);
            context->resume_offset = resume_offset;
            progressed = true;
            if (resume_offset >= expected_size) {
                std::remove(sidecar.c_str());
                const std::uint32_t crc = update_file_crc(output, resume_offset);
                if (crc != expected_crc) {
                    std::fclose(output);
                    output = nullptr;
                    context->output = nullptr;
                    ::WSACleanup();
                    finish(UpdateDownloadState::failed);
                    return 0u;
                }
                std::fclose(output);
                output = nullptr;
                context->output = nullptr;
                struct __utimbuf64 times{};
                times.actime = static_cast<__time64_t>(access_time);
                times.modtime = static_cast<__time64_t>(modify_time);
                _utime64(destination.c_str(), &times);
                context->state = UpdateDownloadState::acknowledge;
            }
        } else if (context->state == UpdateDownloadState::acknowledge && FD_ISSET(context->socket, &writable)) {
            if (!update_send(context->socket, "DA", 2)) {
                ::WSACleanup();
                finish(UpdateDownloadState::failed);
                return 0u;
            }
            context->state = UpdateDownloadState::idle;
            context->completed = 1u;
            return 0u;
        } else if (context->state == UpdateDownloadState::idle || context->state == UpdateDownloadState::failed) {
            context->completed = 1u;
            return 0u;
        }
        if (progressed) {
            activity = _time64(nullptr);
        }
    }
    if (output) {
        std::fclose(output);
        context->output = nullptr;
    }
    ::WSACleanup();
    finish(context->state);
    return 0u;
}

DWORD WINAPI sfera_tcp_receive_dispatch_thread(void* parameter) noexcept {
    auto* context = static_cast<SferaTcpConnectionContext*>(parameter);
    if (!context) {
        return 0u;
    }
    while (!context->stop_requested) {
        if (context->connected && context->remote_id != 0u) {
            if (context->receive_size != 0u) {
            dispatch_tcp_receive_packets(*context);
        }
            ::Sleep(6u);
        } else {
            ::Sleep(10u);
        }
    }
    tcp_log_line("tcp_ip_connect.log", "Rnd Thread exit\n");
    return 0u;
}

DWORD WINAPI sfera_tcp_send_maintenance_thread(void* parameter) noexcept {
    auto* context = static_cast<SferaTcpConnectionContext*>(parameter);
    if (!context) {
        return 0u;
    }
    DWORD stats_tick = ::GetTickCount();
    DWORD random_tick = ::GetTickCount();
    DWORD keepalive_tick = ::GetTickCount();
    DWORD send_tick = ::GetTickCount();
    DWORD random_interval = static_cast<DWORD>(std::rand() % 5000 + 2000);
    while (!context->stop_requested) {
        if (!context->connected) {
            ::Sleep(10u);
            continue;
        }
        DWORD now = ::GetTickCount();
        if (now - stats_tick > 1000u) {
            stats_tick = now;
            auto* critical_section = &g_sfera_network_send_runtime.critical_section;
            ::EnterCriticalSection(critical_section);
            context->sent_bytes_per_second = context->sent_bytes_window;
            context->sent_bytes_window = 0u;
            ::LeaveCriticalSection(critical_section);
        }
        now = ::GetTickCount();
        if (now - send_tick > 15u) {
            send_tick = now;
            send_pending_tcp(*context);
            if (context->sequence > 50000u) {
            context->sequence = 1u;
            queue_tcp_packet(*context, 0u, TcpMessage::sequence_reset, nullptr);
        }
        }
        now = ::GetTickCount();
        if (now - keepalive_tick > 3000u) {
            keepalive_tick = now;
            auto* timing = &g_sfera_window_runtime.timing_critical_section;
            ::EnterCriticalSection(timing);
            context->keepalive_started_at = ::GetTickCount();
            if (!context->keepalive_answered) {
            context->round_trip_ms += 3000u;
        }
            context->keepalive_answered = 0u;
            ::LeaveCriticalSection(timing);
            queue_tcp_packet(*context, 0u, TcpMessage::keepalive, nullptr);
            send_pending_tcp(*context);
        }
        now = ::GetTickCount();
        if (now - random_tick > random_interval) {
            random_interval = static_cast<DWORD>(std::rand() % 10000 + 3000);
            random_tick = now;
            queue_tcp_packet(*context, sizeof(context->packet_counter), TcpMessage::packet_counter, &context->packet_counter);
        }
        ::Sleep(4u);
    }
    tcp_log_line("tcp_ip_connect.log", "Snd Thread exit\n");
    return 0u;
}

std::uint32_t __fastcall sfera_sound_decode_callback(CSoundStream* sound_stream, void* state) noexcept {
    auto* playback = static_cast<SferaSoundPlaybackState*>(state);
    if (!playback) {
        return 0u;
    }
    const auto event = next_sound_event(*playback);
    if (event.type == SoundEventType::end) {
        if (sound_stream) {
            sound_stream->Stop();
        }
        playback->finished = 1u;
        playback->playing = 0u;
        return 0u;
    }
    const auto type = event.type;
    const std::uint32_t index = event.argument;
    if (playback->force_stop) {
        append_sound_event(playback->event_queue, event, -1.0f, UINT32_MAX);
        if (sound_stream) {
            sound_stream->decode_event_position = UINT32_MAX;
        }
        if (sound_stream) {
            sound_stream->SetPlaySignal(playback->play_signal - 1.0f);
        }
        return 1u;
    }
    if (type == SoundEventType::seek && index != 0u) {
        const auto* format = sound_stream ? sound_stream->Format() : nullptr;
        if (playback->timings && index <= playback->timing_count && format) {
            const SferaSoundTiming& timing = playback->timings[index - 1u];
            const std::uint32_t byte_position = static_cast<std::uint32_t>(static_cast<std::int32_t>(std::trunc(static_cast<double>(format->nSamplesPerSec) * timing.seek_time))) * format->nBlockAlign;
            append_sound_event(playback->event_queue, event, timing.signal, byte_position);
            if (sound_stream) {
            sound_stream->SeekToTime(timing.seek_time);
            sound_stream->SetDecodeSignal(timing.signal);
        }
        }
        return 1u;
    }
    if (type == SoundEventType::stop || (type == SoundEventType::wait && index != 0u)) {
        append_sound_event(playback->event_queue, event, -1.0f, UINT32_MAX);
        if (sound_stream) {
            sound_stream->decode_event_position = UINT32_MAX;
        }
    }
    return 1u;
}

std::uint32_t __fastcall sfera_sound_play_callback(CSoundStream* sound_stream, void* state) noexcept {
    auto* playback = static_cast<SferaSoundPlaybackState*>(state);
    if (!playback) {
        return 0u;
    }
    SoundEventRecord record{};
    if (!pop_sound_event(playback->event_queue, record)) {
        if (sound_stream) {
            sound_stream->play_event_position = UINT32_MAX;
        }
        return 1u;
    }
    const auto* format = sound_stream ? sound_stream->Format() : nullptr;
    if (sound_stream && record.position != UINT32_MAX && format) {
        const std::uint32_t signal_position = static_cast<std::uint32_t>(static_cast<std::int32_t>(std::trunc(static_cast<double>(format->nSamplesPerSec) * playback->play_signal))) * format->nBlockAlign;
        sound_stream->playback_position_adjustment += record.position - signal_position;
    }
    if (record.signal != -1.0f) {
        playback->play_signal = record.signal;
        if (sound_stream) {
            sound_stream->SetPlaySignal(record.signal);
        }
    } else if (sound_stream) {
        sound_stream->play_event_position = UINT32_MAX;
    }
    const auto type = record.type;
    if (type == SoundEventType::wait && !playback->force_stop) {
        if (sound_stream) {
            sound_stream->Stop();
        }
        playback->pending_track = record.argument;
        playback->timer_low = UINT32_MAX;
        playback->timer_high = UINT32_MAX;
        playback->playing = 0u;
        return 1u;
    }
    if (type == SoundEventType::stop || playback->force_stop) {
        if (sound_stream) {
            sound_stream->Stop();
        }
        playback->finished = 1u;
        playback->playing = 0u;
    }
    return 1u;
}

DWORD WINAPI sfera_network_probe_thread(void*) noexcept {
    for (;;) {
        for (std::uint32_t iteration = 0u; iteration < kNetworkProbeIntervalSlices; ++iteration) {
            ::Sleep(kNetworkProbeIntervalSliceMs);
            if (g_sfera_network_probe_runtime.stop_requested == 1u) {
                return 0u;
            }
        }
        const std::int32_t probe_result = run_network_probe();
        const __time64_t now = _time64(nullptr);
        const std::uint32_t context_a = g_sfera_network_probe_runtime.context_a;
        const std::uint32_t context_b = g_sfera_network_probe_runtime.context_b;
        const std::uint32_t context_c = g_sfera_network_probe_runtime.context_c;
        auto* critical_section = &g_sfera_network_probe_runtime.critical_section;
        ::EnterCriticalSection(critical_section);
        std::move_backward(std::begin(g_sfera_network_probe_runtime.samples), std::end(g_sfera_network_probe_runtime.samples) - 1, std::end(g_sfera_network_probe_runtime.samples));
        SferaNetworkProbeSample& sample = g_sfera_network_probe_runtime.samples[0];
        sample.timestamp.low = static_cast<std::uint32_t>(now);
        sample.timestamp.high = static_cast<std::uint32_t>(static_cast<std::uint64_t>(now) >> 32u);
        sample.probe_result = static_cast<std::uint32_t>(probe_result);
        sample.context_a = context_a;
        sample.context_b = context_b;
        sample.context_c = context_c;
        g_sfera_network_probe_runtime.sample_count = std::min<std::uint32_t>(g_sfera_network_probe_runtime.sample_count + 1u, kNetworkProbeSampleCount);
        ::LeaveCriticalSection(critical_section);
    }
}

DWORD WINAPI sfera_directplay_heartbeat_thread(void*) noexcept {
    for (;;) {
        auto* client = g_sfera_directplay_runtime.peer;
        if (client) {
            std::uint8_t payload = 5u;
            DWORD async_handle = 0u;
            const SferaDpnBufferDescRuntime buffer{1u, &payload};
            client->Send(&buffer, 1u, kDirectPlayHeartbeatTimeoutMs, nullptr, &async_handle, kDirectPlayHeartbeatSendFlags);
        }
        ::Sleep(2000u);
    }
}

HRESULT WINAPI sfera_directplay_message_handler(void*, DWORD message, void* payload) noexcept {
    if (g_sfera_client_config_runtime.connect_type_enabled == 1u) {
        return S_OK;
    }
    log_directplay_message(message);
    if (message == kDirectPlayTerminateSession) {
        g_sfera_network_runtime.initialization_result = UINT32_MAX;
        g_sfera_network_runtime.timeout_marker_pending = 1u;
        return S_OK;
    }
    if (message == kDirectPlayConnectComplete) {
        const auto* result = static_cast<const SferaDirectPlayConnectResult*>(payload);
        g_sfera_network_runtime.initialization_result = result && SUCCEEDED(result->result) ? 1u : UINT32_MAX;
        return S_OK;
    }
    if (message == kDirectPlayReceive && payload) {
        enqueue_directplay_receive(*static_cast<const SferaDirectPlayReceivePayload*>(payload));
    }
    return S_OK;
}

std::uint32_t __fastcall sfera_client_critical_error(const char* message, std::uint32_t critical) noexcept {
    const int result = ::MessageBoxA(reinterpret_cast<HWND>(static_cast<std::uintptr_t>(g_sfera_window_runtime.main_window)), message, critical ? "Critical" : "Error", critical ? MB_ICONERROR : (MB_ICONERROR | MB_OKCANCEL));
    return critical ? 0u : static_cast<std::uint32_t>(result == IDOK);
}
