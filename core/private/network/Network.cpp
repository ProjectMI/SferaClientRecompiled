#include <winsock2.h>
#include <windows.h>
#include <algorithm>
#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iterator>
#include <memory>
#include <mutex>
#include <span>
#include <stdexcept>
#include <stop_token>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>
#include <ws2tcpip.h>

#include "binary/Binary.h"
#include "diagnostics/Diagnostics.h"
#include "network/Network.h"
#include "numeric/Numeric.h"
#include "runtime/Clock.h"
#include "script/MbcBitStream.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"

void SferaNetworkRuntime::updateTcpStatistics()
{
    connection_info = connection ? connection->statistics() : SferaNetworkStatistics{};
}

int SferaNetworkRuntime::tickDifference(std::uint32_t current, std::uint32_t previous)
{
    constexpr int maximumDistance = 14400;
    constexpr std::uint32_t period = 32768;
    const auto difference = current - previous;
    const auto signedDifference = SferaNumeric::signedWord(difference);
    const auto magnitude = signedDifference < 0 ? std::uint32_t{0} - difference : difference;
    if (SferaNumeric::signedWord(magnitude) <= maximumDistance)
        return signedDifference;
    return SferaNumeric::signedWord(signedDifference < 0 ? difference + period : difference - period);
}

void SferaNetworkRuntime::encodePayload(std::uint8_t *data, std::size_t length)
{
    constexpr std::array<std::uint8_t, 9> protocolKey{75, 13, 239, 96, 201, 154, 112, 14, 3};
    std::uint8_t feedback = 0;
    for (std::size_t index = 0; index < length; ++index)
    {
        const auto value = data[index];
        data[index] = value ^ protocolKey[index % protocolKey.size()] ^ feedback;
        feedback = 2u * feedback + SferaNumeric::lowByte(SferaNumeric::lowWord(index)) * value;
    }
}

bool SferaNetworkRuntime::sendPacket(std::uint32_t flags, std::span<const std::uint8_t> payload)
{
    if (initialization_result != 1u || !connection || !connection->isConnected())
        return false;
    if (payload.size() > UINT16_MAX - SferaTcpOutgoingHeader::encodedSize - 1u)
        return false;
    std::vector<std::uint8_t> message(payload.size() + 1u);
    message[0] = SferaNumeric::lowByte(flags);
    std::copy(payload.begin(), payload.end(), message.begin() + 1u);
    encodePayload(message.data() + 1u, payload.size());
    if (!connection->queuePacket(SferaNumeric::lowWord(message.size()), TcpMessage::payload, message.data()))
        return false;
    sent_bytes.fetch_add(payload.size());
    return true;
}

SferaNetworkRuntime::~SferaNetworkRuntime()
{
    connection.reset();
}

int SferaNetworkRuntime::initialize(const std::string &hostname, std::uint32_t mode)
{
    if (connection_lost)
        shutdown();
    const auto result = initialization_result.load();
    if (SferaNumeric::signedWord(result) >= 0)
        return SferaNumeric::signedWord(result);
    if (hostname.empty())
        return 0;
    shutdown();
    client_mode = mode;
    connection_lost = false;
    sent_bytes = 0;
    received_bytes = 0;
    connection_info = {};
    {
        std::lock_guard lock(receive_mutex);
        dropped_messages = 0;
    }
    initialization_result = 0;
    try
    {
        connection = std::make_unique<SferaTcpConnectionContext>(*this);
    }
    catch (...)
    {
        initialization_result = UINT32_MAX;
        return 0;
    }
    if (connection->initialize(hostname, server_port) != 0)
    {
        connection.reset();
        initialization_result = UINT32_MAX;
        g_sfera_log_runtime.write("Network initialize error! \n\n");
        return 0;
    }
    return 1;
}

void SferaNetworkRuntime::shutdown()
{
    connection.reset(); // stops and joins workers before queue storage is changed
    {
        std::lock_guard lock(receive_mutex);
        messages.clear();
    }
    initialization_result = UINT32_MAX;
    connection_slot = UINT32_MAX;
    connection_info = {};
    reset_pending_network_regions();
}

void SferaTcpConnectionContext::fail() noexcept
{
    connected_ = false;
    owner_.connection_lost = true;
    owner_.initialization_result = UINT32_MAX;
    receive_ready_.notify_all();
}

SferaNetworkStatistics SferaTcpConnectionContext::statistics() const
{
    std::lock_guard lock(statistics_mutex_);
    return statistics_;
}

SferaTcpConnectionContext::SferaTcpConnectionContext(SferaNetworkRuntime &owner) noexcept : owner_(owner)
{
}
SferaTcpConnectionContext::~SferaTcpConnectionContext()
{
    shutdown();
}

void SferaTcpConnectionContext::shutdown() noexcept
{
    connected_ = false;
    for (auto &worker : workers_)
        worker.request_stop();
    receive_ready_.notify_all();
    // Socket is nonblocking, select has a finite timeout, and no queue lock is
    // held during join. Never close a SOCKET still being used by another thread.
    for (auto &worker : workers_)
        if (worker.joinable())
            worker.join();
    if (socket_.value != INVALID_SOCKET)
        ::shutdown(socket_.value, SD_BOTH);
    socket_.reset();
    winsock_.reset();
    outgoing_.clear();
    outgoing_offset_ = outgoing_bytes_ = 0;
    incoming_.clear();
    incoming_bytes_ = 0;
    sequence_ = checksum_seed_ = 0;
    packet_counter_ = 0;
    handshake_complete_ = false;
    {
        std::lock_guard lock(statistics_mutex_);
        statistics_ = {};
        received_bytes_window_ = sent_bytes_window_ = 0;
    }
    keepalive_started_at_ = 0;
    keepalive_answered_ = false;
}

int SferaTcpConnectionContext::initialize(const std::string &hostname, std::uint16_t port)
{
    shutdown();
    if (hostname.empty() || !winsock_.start())
        return -1;
    try
    {
        socket_.reset(::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));
        if (socket_.value == INVALID_SOCKET)
        {
            shutdown();
            return -1;
        }
        const int no_delay = 1;
        constexpr int option_size = sizeof(no_delay);
        std::string option(option_size, '\0');
        std::memcpy(option.data(), &no_delay, sizeof(no_delay));
        (void)::setsockopt(socket_.value, IPPROTO_TCP, TCP_NODELAY, option.data(), option_size);
        addrinfo hints{};
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        hints.ai_flags = AI_NUMERICSERV;
        const auto service = std::to_string(port);
        addrinfo *raw = nullptr;
        const auto status = ::getaddrinfo(hostname.c_str(), service.c_str(), &hints, &raw);
        std::unique_ptr<addrinfo, decltype(&::freeaddrinfo)> resolved(raw, &::freeaddrinfo);
        if (status != 0 || !resolved || !std::in_range<int>(resolved->ai_addrlen))
        {
            shutdown();
            return -1;
        }
        // Bounded connect, then all worker send/recv calls remain nonblocking.
        u_long nonblocking = 1;
        if (::ioctlsocket(socket_.value, FIONBIO, &nonblocking) != 0)
        {
            shutdown();
            return -1;
        }
        if (::connect(socket_.value, resolved->ai_addr, SferaNumeric::signedWord(SferaNumeric::lowWord(resolved->ai_addrlen))) != 0)
        {
            if (::WSAGetLastError() != WSAEWOULDBLOCK)
            {
                shutdown();
                return -1;
            }
            fd_set writable{}, failed{};
            FD_SET(socket_.value, &writable);
            FD_SET(socket_.value, &failed);
            timeval timeout{15, 0};
            if (::select(0, nullptr, &writable, &failed, &timeout) <= 0 || FD_ISSET(socket_.value, &failed))
            {
                shutdown();
                return -1;
            }
            int size = option_size;
            if (::getsockopt(socket_.value, SOL_SOCKET, SO_ERROR, option.data(), &size) != 0 || std::cmp_not_equal(size, sizeof(int)))
            {
                shutdown();
                return -1;
            }
            int error = 0;
            std::memcpy(&error, option.data(), sizeof(error));
            if (error != 0)
            {
                shutdown();
                return -1;
            }
        }
        connected_ = true;
        workers_[0] = std::jthread(&SferaTcpConnectionContext::runWorker, this, &SferaTcpConnectionContext::receive);
        workers_[1] = std::jthread(&SferaTcpConnectionContext::runWorker, this, &SferaTcpConnectionContext::maintain);
        workers_[2] = std::jthread(&SferaTcpConnectionContext::runWorker, this, &SferaTcpConnectionContext::dispatch);
        return 0;
    }
    catch (...)
    {
        shutdown();
        return -1;
    }
}

void SferaTcpConnectionContext::runWorker(std::stop_token stop, SferaTcpConnectionContext *context, void (SferaTcpConnectionContext::*operation)(std::stop_token) noexcept)
{
    std::invoke(operation, context, stop);
}

bool SferaTcpConnectionContext::acceptPacket(std::string_view packet, std::stop_token stop)
{
    const auto header = SferaTcpIncomingHeader::decode(std::as_bytes(std::span(packet)));
    switch (SferaNumeric::enumFromBits<TcpMessage>(header.message))
    {
    case TcpMessage::connection_limit:
        fail();
        return false;
    case TcpMessage::handshake:
    {
        if (packet.size() < SferaTcpHandshakePacket::encodedSize)
        {
            fail();
            return false;
        }
        const auto handshake = SferaTcpHandshakePacket::decode(std::as_bytes(std::span(packet)));
        if (handshake.remote_id == 0)
        {
            fail();
            return false;
        }
        {
            std::lock_guard lock(send_mutex_);
            checksum_seed_ = handshake.checksum_seed;
            sequence_ = std::rand() % 1000 + 1;
            std::array<std::uint8_t, 4> mode{};
            SferaBinary::writeLittleEndian(mode.data(), owner_.client_mode);
            if (!queuePacket(SferaNumeric::lowWord(mode.size()), TcpMessage::client_mode, mode.data()))
                return false;
        }
        const auto started = WorldClock::milliseconds();
        for (;;)
        {
            if (stop.stop_requested() || !connected_)
                return false;
            sendPending();
            {
                std::lock_guard lock(send_mutex_);
                if (outgoing_.empty())
                    break;
            }
            if (WorldClock::milliseconds() - started >= 15000u)
            {
                fail();
                return false;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        handshake_complete_ = true;
        owner_.initialization_result = 1u;
        receive_ready_.notify_all();
        return true;
    }
    case TcpMessage::keepalive:
    {
        std::lock_guard lock(statistics_mutex_);
        statistics_.round_trip_latency_ms = (WorldClock::milliseconds() - keepalive_started_at_) / 3u;
        keepalive_answered_ = true;
        return true;
    }
    case TcpMessage::payload:
    {
        std::lock_guard lock(receive_mutex_);
        // The old staging buffer dropped complete packets that did not fit.
        if (packet.size() > kTcpReceiveBufferCapacity - incoming_bytes_)
            return true;
        incoming_.emplace_back(packet.begin() + SferaTcpIncomingHeader::encodedSize, packet.end());
        incoming_bytes_ += packet.size();
        receive_ready_.notify_one();
        return true;
    }
    default:
        return true; // Unknown framed messages were consumed without dispatch.
    }
}

void SferaTcpConnectionContext::receive(std::stop_token stop) noexcept
{
    try
    {
        std::string bytes;
        bytes.reserve(kTcpReceiveBufferCapacity);
        std::size_t first = 0;
        auto stats_tick = WorldClock::milliseconds();
        const auto handshake_started = stats_tick;
        while (!stop.stop_requested() && connected_)
        {
            const auto now = WorldClock::milliseconds();
            if (!handshake_complete_ && now - handshake_started >= 15000u)
            {
                fail();
                break;
            }
            fd_set readable{};
            FD_SET(socket_.value, &readable);
            timeval timeout{0, 10000};
            const int selected = ::select(0, &readable, nullptr, nullptr, &timeout);
            if (selected == SOCKET_ERROR)
            {
                if (!stop.stop_requested())
                    fail();
                break;
            }
            if (selected > 0)
            {
                const auto available = kTcpReceiveBufferCapacity - (bytes.size() - first);
                if (available == 0)
                {
                    fail();
                    break;
                }
                const int requested = SferaNumeric::signedWord(SferaNumeric::lowWord(std::min<std::size_t>(available, 8192u)));
                if (bytes.size() + requested > kTcpReceiveBufferCapacity && first != 0)
                {
                    bytes.erase(0, first);
                    first = 0;
                }
                const auto previous_size = bytes.size();
                bytes.resize(previous_size + requested);
                const int count = ::recv(socket_.value, bytes.data() + previous_size, requested, 0);
                const int error = count == SOCKET_ERROR ? ::WSAGetLastError() : 0;
                bytes.resize(previous_size + (count > 0 ? count : 0));
                if (count == 0)
                {
                    if (!stop.stop_requested())
                        fail();
                    break;
                }
                if (count == SOCKET_ERROR)
                {
                    if (error != WSAEWOULDBLOCK && error != WSAEINTR)
                    {
                        if (!stop.stop_requested())
                            fail();
                        break;
                    }
                }
                else
                {
                    std::lock_guard lock(statistics_mutex_);
                    received_bytes_window_ += count;
                }
            }
            while (bytes.size() - first >= SferaTcpIncomingHeader::encodedSize)
            {
                const auto header = SferaTcpIncomingHeader::decode(std::as_bytes(std::span(bytes)).subspan(first));
                if (header.size < SferaTcpIncomingHeader::encodedSize || header.size > kTcpReceiveBufferCapacity)
                {
                    fail();
                    break;
                }
                if (bytes.size() - first < header.size)
                    break;
                if (!acceptPacket(std::string_view(bytes).substr(first, header.size), stop))
                    break;
                first += header.size;
            }
            if (first == bytes.size())
            {
                bytes.clear();
                first = 0;
            }
            if (now - stats_tick > 1000u)
            {
                stats_tick = now;
                std::lock_guard lock(statistics_mutex_);
                statistics_.received_bytes_per_second = std::exchange(received_bytes_window_, 0u);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(15));
        }
    }
    catch (...)
    {
        fail();
    }
    connected_ = false;
    receive_ready_.notify_all();
}

void SferaTcpConnectionContext::dispatch(std::stop_token stop) noexcept
{
    try
    {
        while (!stop.stop_requested())
        {
            std::vector<std::uint8_t> message;
            {
                std::unique_lock lock(receive_mutex_);
                if (!receive_ready_.wait_for(lock, stop, std::chrono::milliseconds(6), std::bind(&SferaTcpConnectionContext::hasIncomingWork, this)))
                {
                    if (stop.stop_requested())
                        break;
                    continue;
                }
                if (!connected_)
                    break;
                message = std::move(incoming_.front());
                incoming_.pop_front();
                incoming_bytes_ -= message.size() + SferaTcpIncomingHeader::encodedSize;
            }
            owner_.enqueueMessage(message);
        }
    }
    catch (...)
    {
        fail();
    }
}

void SferaTcpConnectionContext::maintain(std::stop_token stop) noexcept
{
    try
    {
        auto stats_tick = WorldClock::milliseconds();
        auto random_tick = stats_tick, keepalive_tick = stats_tick, send_tick = stats_tick;
        std::uint32_t random_interval = std::rand() % 5000 + 2000;
        while (!stop.stop_requested() && connected_)
        {
            if (!handshake_complete_)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                continue;
            }
            const auto now = WorldClock::milliseconds();
            if (now - stats_tick > 1000u)
            {
                stats_tick = now;
                std::lock_guard lock(statistics_mutex_);
                statistics_.sent_bytes_per_second = std::exchange(sent_bytes_window_, 0u);
            }
            if (now - send_tick > 15u)
            {
                send_tick = now;
                sendPending();
                std::lock_guard lock(send_mutex_);
                if (sequence_ > 50000u)
                {
                    sequence_ = 1u;
                    queuePacket(0u, TcpMessage::sequence_reset, nullptr);
                }
            }
            if (now - keepalive_tick > 3000u)
            {
                keepalive_tick = now;
                {
                    std::lock_guard lock(statistics_mutex_);
                    keepalive_started_at_ = now;
                    if (!keepalive_answered_)
                        statistics_.round_trip_latency_ms += 3000u;
                    keepalive_answered_ = false;
                }
                queuePacket(0u, TcpMessage::keepalive, nullptr);
                sendPending();
            }
            if (now - random_tick > random_interval)
            {
                random_interval = (std::rand() % 10000 + 3000);
                random_tick = now;
                std::lock_guard lock(send_mutex_);
                std::array<std::uint8_t, 4> count{};
                SferaBinary::writeLittleEndian(count.data(), packet_counter_);
                queuePacket(SferaNumeric::lowWord(count.size()), TcpMessage::packet_counter, count.data());
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(4));
        }
    }
    catch (...)
    {
        fail();
    }
}

void SferaTcpConnectionContext::sendPending() noexcept
{
    try
    {
        std::lock_guard lock(send_mutex_);
        while (connected_ && !outgoing_.empty())
        {
            const auto &packet = outgoing_.front();
            if (outgoing_offset_ > packet.size())
                throw std::out_of_range("Invalid outgoing packet offset");
            const auto remaining = packet.size() - outgoing_offset_;
            if (remaining == 0u)
            {
                fail();
                return;
            }
            const int request = SferaNumeric::signedWord(SferaNumeric::lowWord(std::min<std::size_t>(remaining, INT_MAX)));
            const int sent = ::send(socket_.value, packet.data() + outgoing_offset_, request, 0);
            if (sent == SOCKET_ERROR)
            {
                const auto error = ::WSAGetLastError();
                if (error != WSAEWOULDBLOCK && error != WSAEINTR)
                    fail();
                return;
            }
            if (sent == 0)
            {
                fail();
                return;
            }
            outgoing_offset_ += SferaNumeric::lowWord(sent);
            outgoing_bytes_ -= sent;
            {
                std::lock_guard stats_lock(statistics_mutex_);
                sent_bytes_window_ += sent;
            }
            if (outgoing_offset_ == packet.size())
            {
                outgoing_.pop_front();
                outgoing_offset_ = 0;
            }
        }
    }
    catch (...)
    {
        fail();
    }
}

bool SferaTcpConnectionContext::queuePacket(std::uint32_t payloadSize, TcpMessage message, const void *payload) noexcept
{
    try
    {
        std::lock_guard lock(send_mutex_);
        if (!connected_)
            return false;
        if (payloadSize > UINT16_MAX - SferaTcpOutgoingHeader::encodedSize || payloadSize + SferaTcpOutgoingHeader::encodedSize > sendCapacity - outgoing_bytes_ ||
            (payloadSize != 0 && payload == nullptr))
        {
            fail();
            return false;
        }
        const std::uint16_t packet_size = SferaNumeric::lowHalf(payloadSize + SferaTcpOutgoingHeader::encodedSize);
        std::string packet(packet_size, '\0');
        const auto wire = std::as_writable_bytes(std::span(packet));
        const std::uint16_t next_sequence = sequence_ + std::rand() % 4 + 1;
        SferaTcpOutgoingHeader{packet_size, 0u, next_sequence, SferaNumeric::enumBits(message)}.encode(wire);
        if (payloadSize != 0)
            std::memcpy(packet.data() + SferaTcpOutgoingHeader::encodedSize, payload, payloadSize);
        std::uint16_t checksum = 0;
        for (std::size_t i = SferaTcpOutgoingHeader::checksumPayloadOffset; i < packet.size(); ++i)
            checksum = SferaNumeric::lowHalf(SferaNumeric::word(checksum + SferaNumeric::signedByte(wire[i])));
        SferaBinary::writeLittleEndian(wire.data() + SferaTcpOutgoingHeader::checksumOffset, SferaNumeric::lowHalf(checksum_seed_ ^ checksum));
        outgoing_.push_back(std::move(packet));
        outgoing_bytes_ += packet_size;
        sequence_ = next_sequence;
        ++packet_counter_;
        return true;
    }
    catch (...)
    {
        fail();
        return false;
    }
}

void SferaNetworkRuntime::reset_pending_network_regions() noexcept
{
    for (auto &slot : g_sfera_mbc_runtime.world_slots)
    {
        slot.reliable_bit_count = 0u;
        slot.unreliable_bit_count = 0u;
        slot.reliable_process = UINT32_MAX;
        slot.unreliable_process = UINT32_MAX;
        std::fill(std::begin(slot.reliable_payload), std::end(slot.reliable_payload), std::uint8_t{});
        std::fill(std::begin(slot.unreliable_payload), std::end(slot.unreliable_payload), std::uint8_t{});
    }
}

void SferaNetworkRuntime::enqueueMessage(std::span<const std::uint8_t> payload) noexcept
{
    try
    {
        std::lock_guard lock(receive_mutex);
        // Preserve drop-new at the protocol limit, but never confuse full with empty.
        if (payload.size() > 400u || messages.size() >= kSferaNetworkMessageSlotCount)
        {
            ++dropped_messages;
            return;
        }
        messages.emplace_back(payload.begin(), payload.end());
        received_bytes.fetch_add(payload.size());
    }
    catch (...)
    {
        connection_lost = true;
        initialization_result = UINT32_MAX;
    }
}

void SferaNetworkRuntime::receiveEvents(std::span<const std::uint8_t> payload)
{
    if (payload.empty())
        return;
    auto &runtime = g_sfera_mbc_runtime;
    SferaMbcBitStream stream(payload);
    int origin[3]{};
    if (stream.read(1) != 0)
    {
        origin[0] = stream.read(16) - 32768;
        origin[1] = stream.read(13) - 1200;
        origin[2] = stream.read(16) - 32768;
    }
    const auto timestamp = stream.read(15);
    while (stream.valid())
    {
        const auto processId = stream.read(18);
        const auto moduleTag = stream.read(12);
        if (!stream.valid())
            return;
        auto *process = runtime.findProcess(processId);
        if (moduleTag == 0)
        {
            if (process != nullptr)
            {
                runtime.active_process = process;
                if (!process->activateProgram("EKill"))
                {
                    process->flags |= 4;
                    process->programs_queued = true;
                    runtime.enqueueProcess(processId, *process);
                }
                process->flags |= SferaMbcProcessRecordFlagsmarkedForUnload;
            }
            const auto next = stream.read(7);
            if (!stream.valid() || next == 0)
                return;
            if (next == 63)
                continue;
        }
        if (processId >= std::size(runtime.processes) || moduleTag >= std::size(g_sfera_mbc_runtime.modules))
            return;
        if (process == nullptr)
        {
            process = &runtime.processes[processId];
            if (process->process_id != processId)
            {
                const auto loaded = runtime.loadProcess(g_sfera_mbc_runtime.modules[moduleTag].name, processId);
                process = runtime.findProcess(loaded);
                if (process == nullptr)
                    return;
            }
            process->flags |= 4;
            process->programs_queued = true;
            runtime.enqueueProcess(processId, *process);
        }
        runtime.active_process = process;
        while (stream.valid())
        {
            const auto command = stream.read(7);
            if (!stream.valid() || command == 0)
                return;
            if (command == 63)
                break;
            const auto regionIndex = command - 1;
            if (regionIndex > 61)
            {
                if (process->flags & SferaMbcProcessRecordFlagsunloadAfterExecution)
                    runtime.unloadProcess(processId);
                return;
            }
            if (regionIndex == 0 || regionIndex == 61)
            {
                if (process->chain_prev_index == -1 || (process->flags & SferaMbcProcessRecordFlagsmarkedForUnload))
                {
                    if (process->chain_prev_index != -1)
                        runtime.unloadProcess(processId);
                    if (runtime.loadProcess(g_sfera_mbc_runtime.modules[moduleTag].name, processId) == UINT32_MAX)
                        return;
                }
                process->flags &= ~4u;
                process->programs_queued = true;
                runtime.enqueueProcess(processId, *process);
            }
            if (process->regions.empty())
                return;
            const auto &region = process->regions[regionIndex];
            if (region.program_index != UINT16_MAX)
                process->activateProgram(region.program_index);
            if (region.field_count < 0)
            {
                if (process->flags & SferaMbcProcessRecordFlagsunloadAfterExecution)
                    runtime.unloadProcess(processId);
                return;
            }
            const auto firstBit = stream.position();
            if (!stream.skipRegion(region))
                return;
            if (process->flags & SferaMbcProcessRecordFlagsunloadAfterExecution)
                continue;
            if ((region.flags & 1) == 0 && SferaNumeric::signedWord(process->region_timestamps[regionIndex]) >= 0 && tickDifference(timestamp, process->region_timestamps[regionIndex]) < 0)
                continue;
            process->queueRegion(regionIndex, timestamp, origin, payload, firstBit, stream.position() - firstBit, true);
        }
    }
}

void SferaNetworkRuntime::receiveMessage(std::span<const std::uint8_t> message)
{
    if (message.size() <= 1u || message.size() > 400u)
        return;
    receiveEvents(message.subspan(1));
}

void SferaNetworkRuntime::receiveMessages()
{
    if (initialization_result != 1u)
        return;
    // Do not hold a transport lock while scripts run: callbacks may reconnect.
    for (;;)
    {
        std::vector<std::uint8_t> message;
        {
            std::lock_guard lock(receive_mutex);
            if (messages.empty())
                break;
            message = std::move(messages.front());
            messages.pop_front();
        }
        receiveMessage(message);
        if (initialization_result != 1u)
            break;
    }
}
