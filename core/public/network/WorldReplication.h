#pragma once

#include <cstddef>
#include <cstdint>

struct SferaWorldSlotRecord;

struct SferaWorldSlotRecord
{
    static constexpr std::size_t packetPayloadCapacity = 400;
    uint32_t object_handle;
    uint32_t state;
    uint32_t linked_handle;
    uint32_t primary_state;
    uint32_t reliable_bit_count;
    uint8_t reliable_payload[packetPayloadCapacity];
    uint32_t reliable_process;
    uint32_t unreliable_bit_count;
    uint8_t unreliable_payload[packetPayloadCapacity];
    uint32_t unreliable_process;
    int origin[3];
};
