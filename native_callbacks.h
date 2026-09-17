#pragma once

#include <winsock2.h>
#include <windows.h>
#include <mmsystem.h>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <string>
#include "semantic_classes.h"

int __cdecl sfera_compare_record_key(const void* left, const void* right) noexcept;


LRESULT CALLBACK sfera_main_window_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept;
INT_PTR CALLBACK sfera_dialog_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept;
LONG WINAPI sfera_unhandled_exception_filter(EXCEPTION_POINTERS* exception) noexcept;
LONG WINAPI sfera_cpp_exception_filter(EXCEPTION_POINTERS* exception) noexcept;

DWORD WINAPI sfera_tcp_socket_receive_thread(void* parameter) noexcept;
DWORD WINAPI sfera_tcp_receive_dispatch_thread(void* parameter) noexcept;
DWORD WINAPI sfera_tcp_send_maintenance_thread(void* parameter) noexcept;
DWORD WINAPI sfera_network_probe_thread(void* parameter) noexcept;

DWORD WINAPI sfera_check_files_thread(void* parameter) noexcept;
DWORD WINAPI sfera_update_download_thread(void* parameter) noexcept;

std::uint32_t __fastcall sfera_client_critical_error(const char* message, std::uint32_t critical) noexcept;
