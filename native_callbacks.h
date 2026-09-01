#pragma once

#include <winsock2.h>
#include <windows.h>
#include <mmsystem.h>
#include <oleidl.h>
#include <mshtmhst.h>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <string>

using SferaDirectPlayMessageHandler = HRESULT (WINAPI*)(void* context, DWORD message, void* payload);

struct SferaDpnBufferDescRuntime;
class CSoundStream;

inline constexpr std::size_t kTcpReceiveBufferCapacity = 60000u;
inline constexpr std::size_t kCheckFileRecordCount = 100u;
inline constexpr std::size_t kCheckFileTextCapacity = 64u;
inline constexpr std::size_t kUpdateRequestCapacity = 512u;

enum class TcpMessage : std::uint16_t {
    connection_limit = 100u,
    handshake = 200u,
    payload = 300u,
    client_mode = 400u,
    keepalive = 500u,
    sequence_reset = 600u,
    packet_counter = 700u
};

enum class UpdateDownloadState : std::uint32_t {
    idle = 0u,
    send_request = 1u,
    receive_metadata = 2u,
    send_resume = 3u,
    receive_file = 4u,
    failed = 5u,
    acknowledge = 6u
};

enum class SoundEventType : std::uint32_t {
    seek = 1u << 16u,
    wait = 2u << 16u,
    stop = 4u << 16u,
    playlist = 8u << 16u
};

struct SferaDialogEvent;

struct SferaDialogEventQueue {
    std::uint32_t reserved;
    SferaDialogEvent** slots;
    std::uint32_t capacity;
    std::uint32_t begin;
    std::uint32_t count;
};

struct SferaDialogState {
    std::uint8_t reserved[32];
    HWND owner;
    SferaDialogEventQueue events;
    std::uint32_t reserved_after_events;
    std::uint32_t queued_event_count;
};

struct SferaDialogEvent {
    SferaDialogState* dialog;
    std::uint32_t control_id;
    UINT message;
    WPARAM wparam;
    LPARAM lparam;
    std::uint32_t reserved[2];
};

struct SferaTcpConnectionContext {
    std::uint8_t receive_buffer[kTcpReceiveBufferCapacity];
    std::uint32_t receive_size;
    std::uint32_t reserved_after_receive_size;
    SOCKET socket;
    std::uint32_t remote_id;
    std::uint8_t reserved_connection[24];
    std::uint8_t stop_requested;
    std::uint8_t reserved_stop[3];
    std::uint32_t received_bytes_window;
    std::uint32_t sent_bytes_window;
    std::uint32_t sent_bytes_per_second;
    std::uint32_t received_bytes_per_second;
    std::uint8_t* send_buffer;
    std::uint32_t send_size;
    std::uint8_t initialized;
    std::uint8_t connected;
    std::uint8_t reserved_flags[2];
    std::uint32_t round_trip_ms;
    DWORD keepalive_started_at;
    std::uint8_t keepalive_answered;
    std::uint8_t reserved_keepalive;
    std::uint16_t sequence;
    std::uint16_t checksum_seed;
    std::uint16_t reserved_checksum;
    std::uint32_t packet_counter;
};

#pragma pack(push, 1)
struct SferaTcpIncomingHeader {
    std::uint16_t size;
    std::uint16_t message;
};

struct SferaTcpHandshakePacket {
    SferaTcpIncomingHeader header;
    std::uint32_t remote_id;
    std::uint16_t checksum_seed;
};

struct SferaTcpOutgoingHeader {
    std::uint16_t size;
    std::uint16_t checksum;
    std::uint16_t sequence;
    std::uint16_t message;
};
#pragma pack(pop)

struct SferaDirectPlayReceivePayload {
    DWORD size;
    DWORD sender;
    void* player_context;
    const std::uint8_t* data;
    DWORD data_size;
    DWORD buffer_handle;
};

struct SferaDirectPlayConnectResult {
    DWORD size;
    DWORD async_handle;
    void* user_context;
    HRESULT result;
    const void* reply_data;
    DWORD reply_size;
};

struct SferaCheckFileSpec {
    char directory[kCheckFileTextCapacity];
    char masks[kCheckFileTextCapacity];
    std::uint32_t crc;
};

struct SferaCheckFilesContext {
    std::uint32_t crc_table[256];
    std::uint32_t result_crc;
    std::uint32_t reserved_header[4];
    SferaCheckFileSpec records[kCheckFileRecordCount];
    std::int32_t record_count;
    std::int32_t throttle;
    std::uint32_t reserved_control[2];
    std::int32_t stop_requested;
    std::uint8_t running;
    std::uint8_t reserved_running[3];
};

struct CheckFileRecord {
    std::string name;
    std::uint32_t crc;
    std::uint32_t size;
};

#pragma pack(push, 1)
struct SferaUpdateMetadata {
    std::uint32_t file_size;
    std::uint32_t crc;
    std::int32_t access_time;
    std::int32_t modify_time;
    std::uint32_t reserved;
};

struct SferaUpdateResumeRequest {
    char command[3];
    std::uint32_t offset;
};

struct SferaUpdateSidecar {
    std::uint32_t crc;
    std::uint32_t file_size;
};
#pragma pack(pop)

struct SferaUpdateDownloadContext {
    std::uint8_t stop_requested;
    std::uint8_t completed;
    std::uint8_t reserved_header[286];
    SOCKET socket;
    std::uint8_t reserved_connection[784];
    UpdateDownloadState state;
    char request[kUpdateRequestCapacity];
    std::uint32_t expected_size;
    std::uint32_t resume_offset;
    FILE* output;
};

struct SoundEventRecord {
    std::uint32_t code;
    float signal;
    std::uint32_t position;
};

struct SoundEventQueue {
    SoundEventRecord* records;
    std::uint32_t capacity;
    std::uint32_t count;
    std::uint32_t growth;
};

struct SferaSoundTiming {
    float seek_time;
    float signal;
};

struct SferaSoundEventList {
    std::uint32_t** event_groups;
    std::uint32_t* group_sizes;
    std::uint32_t item_index;
    std::uint32_t group_index;
    std::uint32_t group_count;
};

struct SferaSoundPlaybackState {
    SoundEventQueue* event_queue;
    SferaSoundTiming* timings;
    std::uint32_t timing_count;
    std::uint32_t playing;
    std::uint32_t pending_track;
    std::uint32_t reserved_14;
    std::uint32_t timer_low;
    std::uint32_t timer_high;
    float play_signal;
    SferaSoundEventList* playlists;
    std::uint32_t playlist_count;
    SferaSoundEventList* current_list;
    std::uint32_t playlist_index;
    CSoundStream* stream;
    void* source;
    std::uint32_t finished;
    std::uint32_t stopped;
    std::uint32_t volume_scale;
    std::uint32_t force_stop;
    std::uint32_t reserved_4c;
};

class SferaBrowserHost final : public IOleClientSite, public IOleInPlaceSite, public IOleInPlaceFrame, public IDocHostUIHandler {
    class Storage final : public IStorage {
    public:
        HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** output) override;
        ULONG STDMETHODCALLTYPE AddRef() override { return 1u; }
        ULONG STDMETHODCALLTYPE Release() override { return 1u; }
        HRESULT STDMETHODCALLTYPE CreateStream(const OLECHAR*, DWORD, DWORD, DWORD, IStream**) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE OpenStream(const OLECHAR*, void*, DWORD, DWORD, IStream**) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE CreateStorage(const OLECHAR*, DWORD, DWORD, DWORD, IStorage**) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE OpenStorage(const OLECHAR*, IStorage*, DWORD, SNB, DWORD, IStorage**) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE CopyTo(DWORD, const IID*, SNB, IStorage*) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE MoveElementTo(const OLECHAR*, IStorage*, const OLECHAR*, DWORD) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE Commit(DWORD) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE Revert() override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE EnumElements(DWORD, void*, DWORD, IEnumSTATSTG**) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE DestroyElement(const OLECHAR*) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE RenameElement(const OLECHAR*, const OLECHAR*) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE SetElementTimes(const OLECHAR*, const FILETIME*, const FILETIME*, const FILETIME*) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE SetClass(REFCLSID) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE SetStateBits(DWORD, DWORD) override { return E_NOTIMPL; }
        HRESULT STDMETHODCALLTYPE Stat(STATSTG*, DWORD) override { return E_NOTIMPL; }
    };

public:
    explicit SferaBrowserHost(HWND window) noexcept;
    ~SferaBrowserHost();
    HRESULT create() noexcept;
    void resize(LONG width, LONG height) noexcept;
    HWND documentWindow() noexcept;
    void refresh() noexcept;
    HRESULT draw(HDC target, LONG width, LONG height) noexcept;
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** output) override;
    ULONG STDMETHODCALLTYPE AddRef() override { return 1u; }
    ULONG STDMETHODCALLTYPE Release() override { return 1u; }
    HRESULT STDMETHODCALLTYPE SaveObject() override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE GetMoniker(DWORD, DWORD, IMoniker**) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE GetContainer(IOleContainer** output) override;
    HRESULT STDMETHODCALLTYPE ShowObject() override { return S_OK; }
    HRESULT STDMETHODCALLTYPE OnShowWindow(BOOL) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE RequestNewObjectLayout() override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE GetWindow(HWND* output) override;
    HRESULT STDMETHODCALLTYPE ContextSensitiveHelp(BOOL) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE CanInPlaceActivate() override { return S_OK; }
    HRESULT STDMETHODCALLTYPE OnInPlaceActivate() override { return S_OK; }
    HRESULT STDMETHODCALLTYPE OnUIActivate() override { return S_OK; }
    HRESULT STDMETHODCALLTYPE GetWindowContext(IOleInPlaceFrame** frame, IOleInPlaceUIWindow** document, LPRECT, LPRECT, LPOLEINPLACEFRAMEINFO info) override;
    HRESULT STDMETHODCALLTYPE Scroll(SIZE) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE OnUIDeactivate(BOOL) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE OnInPlaceDeactivate() override { return S_OK; }
    HRESULT STDMETHODCALLTYPE DiscardUndoState() override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE DeactivateAndUndo() override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE OnPosRectChange(LPCRECT rect) override;
    HRESULT STDMETHODCALLTYPE GetBorder(LPRECT) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE RequestBorderSpace(LPCBORDERWIDTHS) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE SetBorderSpace(LPCBORDERWIDTHS) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE SetActiveObject(IOleInPlaceActiveObject*, LPCOLESTR) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE InsertMenus(HMENU, LPOLEMENUGROUPWIDTHS) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE SetMenu(HMENU, HOLEMENU, HWND) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE RemoveMenus(HMENU) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE SetStatusText(LPCOLESTR) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE EnableModeless(BOOL) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE TranslateAccelerator(LPMSG, WORD) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE ShowContextMenu(DWORD, POINT*, IUnknown*, IDispatch*) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE GetHostInfo(DOCHOSTUIINFO* info) override;
    HRESULT STDMETHODCALLTYPE ShowUI(DWORD, IOleInPlaceActiveObject*, IOleCommandTarget*, IOleInPlaceFrame*, IOleInPlaceUIWindow*) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE HideUI() override { return S_OK; }
    HRESULT STDMETHODCALLTYPE UpdateUI() override { return S_OK; }
    HRESULT STDMETHODCALLTYPE OnDocWindowActivate(BOOL) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE OnFrameWindowActivate(BOOL) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE ResizeBorder(LPCRECT, IOleInPlaceUIWindow*, BOOL) override { return S_OK; }
    HRESULT STDMETHODCALLTYPE TranslateAccelerator(LPMSG, const GUID*, DWORD) override { return S_FALSE; }
    HRESULT STDMETHODCALLTYPE GetOptionKeyPath(LPOLESTR* output, DWORD) override;
    HRESULT STDMETHODCALLTYPE GetDropTarget(IDropTarget*, IDropTarget** output) override;
    HRESULT STDMETHODCALLTYPE GetExternal(IDispatch** output) override;
    HRESULT STDMETHODCALLTYPE TranslateUrl(DWORD, OLECHAR*, OLECHAR** output) override;
    HRESULT STDMETHODCALLTYPE FilterDataObject(IDataObject*, IDataObject** output) override;

private:
    HWND window_ = nullptr;
    IOleObject* object_ = nullptr;
    Storage storage_;
};


struct SferaDirectPlayAddressNative {
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** output) = 0;
    virtual ULONG STDMETHODCALLTYPE AddRef() = 0;
    virtual ULONG STDMETHODCALLTYPE Release() = 0;
    virtual HRESULT STDMETHODCALLTYPE BuildFromURLW(const wchar_t* url) = 0;
    virtual HRESULT STDMETHODCALLTYPE BuildFromURLA(const char* url) = 0;
    virtual HRESULT STDMETHODCALLTYPE Duplicate(SferaDirectPlayAddressNative** output) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetEqual(SferaDirectPlayAddressNative* address) = 0;
    virtual HRESULT STDMETHODCALLTYPE IsEqual(SferaDirectPlayAddressNative* address) = 0;
    virtual HRESULT STDMETHODCALLTYPE Clear() = 0;
    virtual HRESULT STDMETHODCALLTYPE GetURLW(wchar_t* url, DWORD* characters) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetURLA(char* url, DWORD* characters) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetSP(GUID* provider) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetUserData(void* data, DWORD* size) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetSP(const GUID* provider) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetUserData(const void* data, DWORD size) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetNumComponents(DWORD* count) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetComponentByName(const wchar_t* name, void* buffer, DWORD* size, DWORD* type) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetComponentByIndex(DWORD index, wchar_t* name, DWORD* name_characters, void* buffer, DWORD* size, DWORD* type) = 0;
    virtual HRESULT STDMETHODCALLTYPE AddComponent(const wchar_t* name, const void* data, DWORD size, DWORD type) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDevice(GUID* device) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetDevice(const GUID* device) = 0;
    virtual HRESULT STDMETHODCALLTYPE BuildFromDirectPlay4Address(void* address, DWORD size) = 0;
};

struct SferaDirectPlayClientNative {
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** output) = 0;
    virtual ULONG STDMETHODCALLTYPE AddRef() = 0;
    virtual ULONG STDMETHODCALLTYPE Release() = 0;
    virtual HRESULT STDMETHODCALLTYPE Initialize(void* context, SferaDirectPlayMessageHandler handler, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE EnumServiceProviders(const GUID*, const GUID*, void*, DWORD*, DWORD*, DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE EnumHosts(const void*, SferaDirectPlayAddressNative*, SferaDirectPlayAddressNative*, const void*, DWORD, DWORD, DWORD, DWORD, void*, DWORD*, DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE CancelAsyncOperation(DWORD handle, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE Connect(const void* application, SferaDirectPlayAddressNative* host, SferaDirectPlayAddressNative* device, const void* security, const void* credentials, const void* user_data, DWORD user_data_size, void* async_context, DWORD* async_handle, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE Send(const SferaDpnBufferDescRuntime* buffers, DWORD buffer_count, DWORD timeout, void* async_context, DWORD* async_handle, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetSendQueueInfo(DWORD* messages, DWORD* bytes, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetApplicationDesc(void* description, DWORD* size, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetClientInfo(const void* info, void* async_context, DWORD* async_handle, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetServerInfo(void* info, DWORD* size, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetServerAddress(SferaDirectPlayAddressNative** address, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE Close(DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE ReturnBuffer(DWORD handle, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetCaps(void* caps, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetCaps(const void* caps, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetSPCaps(const GUID* provider, const void* caps, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetSPCaps(const GUID* provider, void* caps, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetConnectionInfo(void* info, DWORD flags) = 0;
    virtual HRESULT STDMETHODCALLTYPE RegisterLobby(DWORD handle, void* application, DWORD flags) = 0;
};

int __cdecl sfera_compare_record_key(const void* left, const void* right) noexcept;

LRESULT CALLBACK sfera_browser_subclass_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept;
LRESULT CALLBACK sfera_browser_host_window_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept;
HWND sfera_browser_document_window(HWND window) noexcept;
void sfera_browser_refresh(HWND window) noexcept;
HRESULT sfera_browser_draw(HWND window, HDC target, LONG width, LONG height) noexcept;

LRESULT CALLBACK sfera_main_window_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept;
INT_PTR CALLBACK sfera_dialog_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept;
LONG WINAPI sfera_unhandled_exception_filter(EXCEPTION_POINTERS* exception) noexcept;
LONG WINAPI sfera_cpp_exception_filter(EXCEPTION_POINTERS* exception) noexcept;

HRESULT WINAPI sfera_directplay_message_handler(void* context, DWORD message, void* payload) noexcept;
DWORD WINAPI sfera_tcp_socket_receive_thread(void* parameter) noexcept;
DWORD WINAPI sfera_tcp_receive_dispatch_thread(void* parameter) noexcept;
DWORD WINAPI sfera_tcp_send_maintenance_thread(void* parameter) noexcept;
DWORD WINAPI sfera_network_probe_thread(void* parameter) noexcept;
DWORD WINAPI sfera_directplay_heartbeat_thread(void* parameter) noexcept;

DWORD WINAPI sfera_check_files_thread(void* parameter) noexcept;
DWORD WINAPI sfera_update_download_thread(void* parameter) noexcept;

std::uint32_t __fastcall sfera_sound_decode_callback(CSoundStream* stream, void* state) noexcept;
std::uint32_t __fastcall sfera_sound_play_callback(CSoundStream* stream, void* state) noexcept;
std::uint32_t __fastcall sfera_client_critical_error(const char* message, std::uint32_t critical) noexcept;
