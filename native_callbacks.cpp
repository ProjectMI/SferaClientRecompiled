#include "native_callbacks.h"
#include "semantic_static.h"

#include <exception>
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

FILE* open_file(const char* path, const char* mode) noexcept {
    FILE* file = nullptr;
    return path && mode && ::fopen_s(&file, path, mode) == 0 ? file : nullptr;
}

}

int __cdecl sfera_compare_record_key(const void* left, const void* right) noexcept {
    return static_cast<int>(*static_cast<const std::uint32_t*>(left) - *static_cast<const std::uint32_t*>(right));
}

LRESULT CALLBACK sfera_main_window_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
    switch (message) {
    case WM_ACTIVATEAPP:
        g_sfera_texture_cache_runtime.cache_enabled = (g_sfera_window_runtime.windowed && g_sfera_client_config_runtime.refresh_rate != 0u) || wparam != 0;
        g_sfera_sound_runtime.refreshMusicVolume();
        g_sfera_client_config_runtime.volume_refresh_frames = 0.0;
        g_sfera_client_config_runtime.volume_refresh_active = true;
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

static void enqueue_tcp_payload(const std::uint8_t* data, std::uint32_t size) noexcept {
    auto& network = g_sfera_network_runtime;
    auto& transport = network.transport;
    auto* critical_section = &network.receive_critical_section;
    ::EnterCriticalSection(critical_section);

    const std::uint32_t write_index = transport.receive_write_index;
    if (transport.receive_busy && write_index == transport.receive_read_index) {
        transport.receive_corrupted = true;
        ::LeaveCriticalSection(critical_section);
        return;
    }

    auto& slot = network.message_slots[write_index];
    if (size > sizeof(slot.data)) {
        transport.receive_corrupted = true;
        ::LeaveCriticalSection(critical_section);
        return;
    }
    slot.data_size = size;
    if (slot.data_size != 0u && data != nullptr) {
        std::memcpy(slot.data, data, slot.data_size);
    }
    transport.received_bytes += size;
    transport.receive_write_index = write_index + 1u < kSferaNetworkMessageSlotCount ? write_index + 1u : 0u;
    transport.receive_busy = true;
    ::LeaveCriticalSection(critical_section);
}

static void dispatch_tcp_receive_packets(SferaTcpConnectionContext& context) noexcept {
    auto* critical_section = &g_sfera_recovered_static_runtime.scene_lock;
    for (;;) {
        ::EnterCriticalSection(critical_section);
        const bool has_header = context.receive_size >= SferaTcpIncomingHeader::encodedSize;
        const auto header = has_header ? SferaTcpIncomingHeader::decode(context.receive_buffer) : SferaTcpIncomingHeader{};
        const std::uint16_t packet_size = header.size;
        if (has_header && (packet_size < SferaTcpIncomingHeader::encodedSize || packet_size > kTcpReceiveBufferCapacity)) {
            context.receive_size = 0u;
            context.connected = 0u;
            g_sfera_network_runtime.transport.connection_lost = true;
            g_sfera_network_runtime.initialization_result = UINT32_MAX;
            ::LeaveCriticalSection(critical_section);
            return;
        }
        const bool complete = has_header && context.receive_size >= packet_size;
        ::LeaveCriticalSection(critical_section);
        if (!complete) {
            return;
        }
        if (header.message == static_cast<std::uint16_t>(TcpMessage::payload)) {
            enqueue_tcp_payload(context.receive_buffer + SferaTcpIncomingHeader::encodedSize, packet_size - SferaTcpIncomingHeader::encodedSize);
        }
        ::EnterCriticalSection(critical_section);
        std::memmove(context.receive_buffer, context.receive_buffer + packet_size, context.receive_size - packet_size);
        context.receive_size -= packet_size;
        ::LeaveCriticalSection(critical_section);
    }
}

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
    DWORD wait_result = WAIT_TIMEOUT;
    while (wait_result == WAIT_TIMEOUT) {
        wait_result = ::WaitForSingleObject(process.hProcess, 100u);
        if (wait_result == WAIT_TIMEOUT && (g_sfera_network_probe_runtime.stop_requested != 0u || ::timeGetTime() - started_at >= 30000u)) {
            ::TerminateProcess(process.hProcess, 1u);
            ::WaitForSingleObject(process.hProcess, INFINITE);
            ::CloseHandle(process.hThread);
            ::CloseHandle(process.hProcess);
            return -1;
        }
    }
    if (wait_result != WAIT_OBJECT_0) {
        ::CloseHandle(process.hThread);
        ::CloseHandle(process.hProcess);
        return -1;
    }
    DWORD exit_code = 0u;
    const BOOL read_exit_code = ::GetExitCodeProcess(process.hProcess, &exit_code);
    ::CloseHandle(process.hThread);
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
    SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", message);
}

DWORD WINAPI sfera_tcp_socket_receive_thread(void* parameter) noexcept {
    auto* context = static_cast<SferaTcpConnectionContext*>(parameter);
    if (!context) {
        return 0u;
    }
    std::vector<std::uint8_t> local_buffer(kTcpReceiveBufferCapacity);
    std::uint32_t buffered = 0u;
    DWORD stats_tick = ::GetTickCount();
    DWORD handshake_started_at = 0u;
    constexpr DWORD handshake_timeout_ms = 15000u;
    bool local_overload_reported = false;
    bool shared_overload_reported = false;
    bool terminate = false;
    while (!context->stop_requested && !terminate) {
        if (!context->connected) {
            handshake_started_at = 0u;
            ::Sleep(10u);
            continue;
        }

        if (context->remote_id == 0u) {
            const DWORD now = ::GetTickCount();
            if (handshake_started_at == 0u) {
                handshake_started_at = now;
            } else if (now - handshake_started_at >= handshake_timeout_ms) {
                SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", "-------------------------ERROR: handshake timeout\n");
                context->connected = 0u;
                g_sfera_network_runtime.transport.connection_lost = true;
                g_sfera_network_runtime.initialization_result = UINT32_MAX;
                break;
            }
        } else {
            handshake_started_at = 0u;
        }
        const std::uint32_t free_space = static_cast<std::uint32_t>(kTcpReceiveBufferCapacity) - buffered;
        if (free_space == 0u) {
            if (!local_overload_reported) {
                SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", "-------------------------ERROR: local rcv buffer overload\n");
                local_overload_reported = true;
            }
        } else {
            fd_set readable{};
            FD_SET(context->socket, &readable);
            timeval timeout{0, 10000};
            const int selected = ::select(0, &readable, nullptr, nullptr, &timeout);
            if (selected == SOCKET_ERROR) {
                if (context->stop_requested) break;
                tcp_log_error("-------------------------ERROR: select, err=%d\n", ::WSAGetLastError());
                g_sfera_network_runtime.transport.connection_lost = true;
                g_sfera_network_runtime.initialization_result = UINT32_MAX;
                break;
            }
            if (FD_ISSET(context->socket, &readable)) {
                const int received = ::recv(context->socket, reinterpret_cast<char*>(local_buffer.data() + buffered), static_cast<int>(free_space), 0);
                const int socket_error = ::WSAGetLastError();
                if (received == SOCKET_ERROR) {
                    context->connected = 0u;
                    if (context->stop_requested) break;
                    tcp_log_error("-------------------------LOST CONNECTION, err=%d\n", socket_error);
                    g_sfera_network_runtime.transport.connection_lost = true;
                    g_sfera_network_runtime.initialization_result = UINT32_MAX;
                    break;
                }
                if (received == 0) {
                    context->connected = 0u;
                    tcp_log_error("-------------------------CLOSE CONNECTION, err=%d\n", socket_error);
                    g_sfera_network_runtime.transport.connection_lost = true;
                    g_sfera_network_runtime.initialization_result = UINT32_MAX;
                    break;
                }
                buffered += static_cast<std::uint32_t>(received);
                context->received_bytes_window += static_cast<std::uint32_t>(received);
            }
        }
        while (buffered >= SferaTcpIncomingHeader::encodedSize) {
            const auto header = SferaTcpIncomingHeader::decode(local_buffer.data());
            const std::uint16_t packet_size = header.size;
            if (packet_size < SferaTcpIncomingHeader::encodedSize || packet_size > kTcpReceiveBufferCapacity) {
                SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", "-------------------------ERROR: invalid packet size\n");
                g_sfera_network_runtime.transport.connection_lost = true;
                g_sfera_network_runtime.initialization_result = UINT32_MAX;
                context->connected = 0u;
                buffered = 0u;
                terminate = true;
                break;
            }
            if (buffered < packet_size) {
                break;
            }
            const auto message = static_cast<TcpMessage>(header.message);
            if (message == TcpMessage::connection_limit) {
                SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", "-------------------------IN(ERROR): (limit connections)\n");
                g_sfera_network_runtime.transport.connection_lost = true;
                g_sfera_network_runtime.initialization_result = UINT32_MAX;
                context->connected = 0u;
                buffered = 0u;
                terminate = true;
                break;
            }
            if (message == TcpMessage::handshake) {
                if (packet_size < SferaTcpHandshakePacket::encodedSize) {
                    SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", "-------------------------ERROR: invalid handshake packet\n");
                    context->connected = 0u;
                    g_sfera_network_runtime.transport.connection_lost = true;
                    g_sfera_network_runtime.initialization_result = UINT32_MAX;
                    buffered = 0u;
                    terminate = true;
                    break;
                }

                const auto handshake = SferaTcpHandshakePacket::decode(local_buffer.data());
                context->checksum_seed = handshake.checksum_seed;
                context->remote_id = handshake.remote_id;
                context->sequence = static_cast<std::uint16_t>(std::rand() % 1000 + 1);
                const std::uint32_t mode = g_sfera_network_runtime.transport.client_mode;
                if (!context->queuePacket(sizeof(mode), TcpMessage::client_mode, &mode)) {
                    buffered = 0u;
                    terminate = true;
                    break;
                }
                while (context->connected && context->send_size != 0u) {
                    context->sendPending();
                }
                if (!context->connected) {
                    buffered = 0u;
                    terminate = true;
                    break;
                }
                g_sfera_network_runtime.initialization_result = 1u;
                char text[96]{};
                std::snprintf(text, sizeof(text), "Create connection: socket=%u\n", context->remote_id);
                SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", text);
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
                    SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", "-------------------------ERROR: rcv buffer overload\n");
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
    SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", "Rcv Thread exit\n");
    context->connected = 0u;
    context->sent_bytes_per_second = 0u;
    context->received_bytes_per_second = 0u;
    g_sfera_network_runtime.initialization_result = UINT32_MAX;
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
        if (context->socket != INVALID_SOCKET) { ::closesocket(context->socket); context->socket = INVALID_SOCKET; }
        ::WSACleanup(); context->output = nullptr; context->state = state; context->completed = true;
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
    std::array<std::uint8_t, SferaUpdateMetadata::encodedSize> response_bytes{};
    std::size_t response_used = 0u;
    std::array<std::uint8_t, 4096u> transfer{};
    while (!context->stop_requested) {
        const __time64_t now = _time64(nullptr);
        if (_difftime64(now, activity) > 15.0) {
            if (output) {
                std::fclose(output);
                output = nullptr;
            }

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

            finish(UpdateDownloadState::failed);
            return 0u;
        }
        bool progressed = false;
        if (context->state == UpdateDownloadState::send_request && FD_ISSET(context->socket, &writable)) {
            const int length = static_cast<int>(std::strlen(context->request) + 1u);
            if (!update_send(context->socket, context->request, length)) {

                finish(UpdateDownloadState::failed);
                return 0u;
            }
            context->state = UpdateDownloadState::receive_metadata;
            progressed = true;
        } else if (context->state == UpdateDownloadState::receive_metadata && FD_ISSET(context->socket, &readable)) {
            const int received = ::recv(context->socket, reinterpret_cast<char*>(response_bytes.data() + response_used), static_cast<int>(response_bytes.size() - response_used), 0);
            if (received <= 0) {

                finish(UpdateDownloadState::failed);
                return 0u;
            }
            response_used += static_cast<std::size_t>(received);
            progressed = true;
            if (response_used == response_bytes.size()) {
                const auto response = SferaUpdateMetadata::decode(response_bytes.data());
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
                    std::array<std::uint8_t, SferaUpdateSidecar::encodedSize> stored_bytes{};
                    const bool valid_metadata = std::fread(stored_bytes.data(), 1u, stored_bytes.size(), metadata) == stored_bytes.size();
                    std::fclose(metadata);
                    const auto stored = SferaUpdateSidecar::decode(stored_bytes.data());
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
            const auto request = SferaUpdateResumeRequest{resume_offset}.encode();
            if (!update_send(context->socket, request.data(), static_cast<int>(request.size()))) {

                finish(UpdateDownloadState::failed);
                return 0u;
            }
            output = open_file(destination.c_str(), resume_offset == 0u ? "w+b" : "a+b");
            if (!output) {

                finish(UpdateDownloadState::failed);
                return 0u;
            }
            context->output = output;
            if (resume_offset == 0u) {
                FILE* metadata = open_file(sidecar.c_str(), "wb");
                if (metadata) {
                    const auto stored = SferaUpdateSidecar{expected_crc, expected_size}.encode();
                    std::fwrite(stored.data(), 1u, stored.size(), metadata);
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
                finish(UpdateDownloadState::failed); return 0u;
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

                finish(UpdateDownloadState::failed);
                return 0u;
            }
            finish(UpdateDownloadState::idle);
            return 0u;
        } else if (context->state == UpdateDownloadState::idle || context->state == UpdateDownloadState::failed) {
            finish(context->state.load());
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

    finish(context->state.load());
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
    SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", "Rnd Thread exit\n");
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
        if (!context->connected || g_sfera_network_runtime.initialization_result != 1u || context->remote_id == 0u) {
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
            context->sendPending();
            if (context->sequence > 50000u) {
                context->sequence = 1u;
                context->queuePacket(0u, TcpMessage::sequence_reset, nullptr);
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
            context->queuePacket(0u, TcpMessage::keepalive, nullptr);
            context->sendPending();
        }
        now = ::GetTickCount();
        if (now - random_tick > random_interval) {
            random_interval = static_cast<DWORD>(std::rand() % 10000 + 3000);
            random_tick = now;
            context->queuePacket(sizeof(context->packet_counter), TcpMessage::packet_counter, &context->packet_counter);
        }
        ::Sleep(4u);
    }
    SferaTcpConnectionContext::writeLog("tcp_ip_connect.log", "Snd Thread exit\n");
    return 0u;
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
        sample.timestamp = static_cast<std::uint64_t>(now);
        sample.probe_result = static_cast<std::uint32_t>(probe_result);
        sample.context_a = context_a;
        sample.context_b = context_b;
        sample.context_c = context_c;
        g_sfera_network_probe_runtime.sample_count = std::min<std::uint32_t>(g_sfera_network_probe_runtime.sample_count + 1u, SferaNetworkProbeRuntime::sample_capacity);
        ::LeaveCriticalSection(critical_section);
    }
}


std::uint32_t __fastcall sfera_client_critical_error(const char* message, std::uint32_t critical) noexcept {
    const int result = ::MessageBoxA(g_sfera_window_runtime.main_window_handle, message, critical ? "Critical" : "Error", critical ? MB_ICONERROR : (MB_ICONERROR | MB_OKCANCEL));
    return critical ? 0u : static_cast<std::uint32_t>(result == IDOK);
}
