#pragma once

#include <array>
#include <atomic>
#include <condition_variable>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <memory>
#include <mutex>
#include <span>
#include <stop_token>
#include <string>
#include <string_view>
#include <thread>
#include <vector>

#include "binary/Binary.h"
#include "platform/WindowsSocket.h"

struct SferaNetworkStatistics;
struct SferaTcpHandshakePacket;
struct SferaTcpIncomingHeader;
struct SferaTcpOutgoingHeader;

struct SferaNetworkStatistics
{
    std::uint32_t round_trip_latency_ms{};
    std::uint32_t sent_bytes_per_second{};
    std::uint32_t received_bytes_per_second{};
    std::uint32_t throughputBytesPerSecond() const noexcept
    {
        return sent_bytes_per_second + received_bytes_per_second;
    }
};

enum class TcpMessage : std::uint16_t
{
    connection_limit = 100u,
    handshake = 200u,
    payload = 300u,
    client_mode = 400u,
    keepalive = 500u,
    sequence_reset = 600u,
    packet_counter = 700u
};

struct SferaTcpIncomingHeader
{
    static constexpr std::uint32_t encodedSize = 4;
    std::uint16_t size;
    std::uint16_t message;
    static SferaTcpIncomingHeader decode(std::span<const std::byte> bytes)
    {
        const auto header = SferaBinary::range(bytes, 0, encodedSize);
        return {SferaBinary::readLittleEndian<std::uint16_t>(header.data()), SferaBinary::readLittleEndian<std::uint16_t>(header.data() + 2)};
    }
};

struct SferaTcpHandshakePacket
{
    static constexpr std::uint32_t encodedSize = SferaTcpIncomingHeader::encodedSize + 6;
    std::uint32_t remote_id;
    std::uint16_t checksum_seed;
    static SferaTcpHandshakePacket decode(std::span<const std::byte> bytes)
    {
        const auto payload = SferaBinary::range(bytes, SferaTcpIncomingHeader::encodedSize, 6);
        return {SferaBinary::readLittleEndian<std::uint32_t>(payload.data()), SferaBinary::readLittleEndian<std::uint16_t>(payload.data() + 4)};
    }
};

struct SferaTcpOutgoingHeader
{
    static constexpr std::uint32_t encodedSize = 8;
    static constexpr std::uint32_t checksumOffset = 2;
    static constexpr std::uint32_t checksumPayloadOffset = 4;
    std::uint16_t size;
    std::uint16_t checksum;
    std::uint16_t sequence;
    std::uint16_t message;
    void encode(std::span<std::byte> bytes) const
    {
        const auto header = SferaBinary::range(bytes, 0, encodedSize);
        SferaBinary::writeLittleEndian(header.data(), size);
        SferaBinary::writeLittleEndian(header.data() + checksumOffset, checksum);
        SferaBinary::writeLittleEndian(header.data() + checksumPayloadOffset, sequence);
        SferaBinary::writeLittleEndian(header.data() + 6, message);
    }
};

inline constexpr std::size_t kSferaNetworkMessageSlotCount = 3048u;
inline constexpr std::size_t kTcpReceiveBufferCapacity = 60000u;

struct SferaNetworkRuntime;
struct SferaTcpConnectionContext;

struct SferaTcpConnectionContext
{
    explicit SferaTcpConnectionContext(SferaNetworkRuntime &owner) noexcept;
    ~SferaTcpConnectionContext();
    SferaTcpConnectionContext(const SferaTcpConnectionContext &) = delete;
    SferaTcpConnectionContext &operator=(const SferaTcpConnectionContext &) = delete;
    int initialize(const std::string &hostname, std::uint16_t port);
    void shutdown() noexcept;
    static constexpr std::uint32_t sendCapacity = 80000;
    bool queuePacket(std::uint32_t payloadSize, TcpMessage message, const void *payload) noexcept;
    void sendPending() noexcept;
    SferaNetworkStatistics statistics() const;
    bool isConnected() const noexcept
    {
        return connected_.load();
    }

  private:
    SferaTcpConnectionContextWinsockSession winsock_;
    SferaTcpConnectionContextSocket socket_;
    SferaNetworkRuntime &owner_;
    std::array<std::jthread, 3> workers_;
    std::atomic<bool> connected_{false};
    std::atomic<bool> handshake_complete_{false};
    // Recursion is intentional: maintenance encodes packets while holding
    // the same lock that serializes sequence/checksum and the send queue.
    std::recursive_mutex send_mutex_;
    // Serialized wire packets use native string storage only as a length-delimited byte buffer.
    // Embedded NUL bytes are data; no text conversion is performed by the transport.
    std::deque<std::string> outgoing_;
    std::size_t outgoing_offset_ = 0;
    std::size_t outgoing_bytes_ = 0;
    std::uint16_t sequence_ = 0;
    std::uint16_t checksum_seed_ = 0;
    std::uint32_t packet_counter_ = 0;
    std::mutex receive_mutex_;
    std::condition_variable_any receive_ready_;
    std::deque<std::vector<std::uint8_t>> incoming_;
    std::size_t incoming_bytes_ = 0;
    mutable std::mutex statistics_mutex_;
    SferaNetworkStatistics statistics_{};
    std::uint32_t received_bytes_window_ = 0;
    std::uint32_t sent_bytes_window_ = 0;
    std::uint32_t keepalive_started_at_ = 0;
    bool keepalive_answered_ = false;
    void fail() noexcept;
    void receive(std::stop_token stop) noexcept;
    void dispatch(std::stop_token stop) noexcept;
    void maintain(std::stop_token stop) noexcept;
    bool acceptPacket(std::string_view packet, std::stop_token stop);

  private:
    bool hasIncomingWork() const
    {
        return !connected_ || (handshake_complete_ && !incoming_.empty());
    }
    static void runWorker(std::stop_token stop, SferaTcpConnectionContext *context, void (SferaTcpConnectionContext::*operation)(std::stop_token) noexcept);
};


struct SferaNetworkRuntime
{
    int statistics_poll_ticks{};

    std::atomic<std::uint32_t> initialization_result{UINT32_MAX};
    std::uint16_t server_port = 25858u;
    std::uint32_t connection_slot = UINT32_MAX;

    std::uint32_t client_mode = 0; // immutable while workers run
    std::atomic<bool> connection_lost{false};
    std::atomic<std::uint64_t> sent_bytes{0}, received_bytes{0};
    SferaNetworkStatistics connection_info{}; // published on the main thread
    std::mutex receive_mutex;
    std::deque<std::vector<std::uint8_t>> messages;
    std::uint64_t dropped_messages = 0; // protected by receive_mutex
    std::unique_ptr<SferaTcpConnectionContext> connection;
    ~SferaNetworkRuntime();
    int initialize(const std::string &hostname, std::uint32_t mode);
    void shutdown();
    void enqueueMessage(std::span<const std::uint8_t> payload) noexcept;
    void receiveMessages();
    void receiveMessage(std::span<const std::uint8_t> message);
    void receiveEvents(std::span<const std::uint8_t> payload);
    bool sendPacket(std::uint32_t flags, std::span<const std::uint8_t> payload);
    static int tickDifference(std::uint32_t current, std::uint32_t previous);
    static void encodePayload(std::uint8_t *data, std::size_t length);
    void updateTcpStatistics();

  private:
    static void reset_pending_network_regions() noexcept;
};

extern SferaNetworkRuntime g_sfera_network_runtime;
