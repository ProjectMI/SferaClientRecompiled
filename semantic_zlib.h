#pragma once

#include <cstdint>

using SferaZCheckCallback = uint32_t (__cdecl*)(uint32_t adler, uint32_t buffer_address, uint32_t length);
using SferaZAllocCallback = void* (__cdecl*)(void* opaque, uint32_t items, uint32_t size);
using SferaZFreeCallback = void (__cdecl*)(void* opaque, void* address);

struct SferaZStream32 {
    uint32_t next_in;
    uint32_t avail_in;
    uint32_t total_in;
    uint32_t next_out;
    uint32_t avail_out;
    uint32_t total_out;
    uint32_t msg;
    uint32_t state;
    SferaZAllocCallback zalloc;
    SferaZFreeCallback zfree;
    void* opaque;
    int32_t data_type;
    uint32_t adler;
    uint32_t reserved;
    uint32_t allocate(uint32_t items, uint32_t size) const noexcept { return zalloc ? static_cast<uint32_t>(reinterpret_cast<uintptr_t>(zalloc(opaque, items, size))) : 0u; }
    void release(uint32_t address) const noexcept { if (zfree && address) zfree(opaque, reinterpret_cast<void*>(static_cast<uintptr_t>(address))); }
};

static_assert(sizeof(SferaZStream32) == 0x38u);

struct SferaInflateBlocksCallbacks32 { uint8_t reserved_000[0x38]; SferaZCheckCallback check; uint32_t check_value; };

uint32_t sfera_zlib_adler32(uint32_t adler, uint32_t buffer_address, uint32_t length);
uint32_t __cdecl sfera_zlib_adler32_callback(uint32_t adler, uint32_t buffer_address, uint32_t length) noexcept;
void* __cdecl sfera_zlib_alloc_callback(void* opaque, uint32_t items, uint32_t size) noexcept;
void __cdecl sfera_zlib_free_callback(void* opaque, void* address) noexcept;
void sfera_zlib_deflate_put_short_msb(uint32_t state_address, uint32_t value);
void sfera_zlib_deflate_flush_pending(uint32_t stream_address);
void sfera_zlib_deflate_lm_init(uint32_t state_address);
void sfera_zlib_deflate_fill_window(uint32_t state_address);
uint32_t sfera_zlib_deflate_read_buf(uint32_t stream_address, uint32_t destination_address, uint32_t size);
uint32_t sfera_zlib_deflate_longest_match(uint32_t state_address, uint32_t current_match);
uint32_t sfera_zlib_fixed_literal_length(uint32_t symbol);
uint32_t sfera_zlib_fixed_literal_code(uint32_t symbol);
uint32_t sfera_zlib_fixed_distance_code(uint32_t symbol);
void sfera_zlib_pq_down_heap(uint32_t state_address, uint32_t tree_address, uint32_t heap_index);
void sfera_zlib_generate_bit_lengths(uint32_t state_address, uint32_t descriptor_address);
void sfera_zlib_generate_codes(uint32_t tree_address, int32_t max_code, uint32_t bit_counts_address);
void sfera_zlib_init_block(uint32_t state_address);
void sfera_zlib_tree_init(uint32_t state_address);
void sfera_zlib_build_tree(uint32_t state_address, uint32_t descriptor_address);
void sfera_zlib_scan_tree(uint32_t state_address, uint32_t tree_address, int32_t max_code);
void sfera_zlib_send_tree(uint32_t state_address, uint32_t tree_address, int32_t max_code);
int32_t sfera_zlib_build_bit_length_tree(uint32_t state_address);
void sfera_zlib_send_all_trees(uint32_t state_address, uint32_t literal_codes, uint32_t distance_codes, uint32_t bit_length_codes);
void sfera_zlib_flush_block(uint32_t state_address, uint32_t buffer_address, uint32_t stored_length, uint32_t end_of_file);
void sfera_zlib_compress_block(uint32_t state_address, uint32_t literal_tree_address, uint32_t distance_tree_address);
uint32_t sfera_zlib_bit_reverse(uint32_t value, uint32_t bit_count);
void sfera_zlib_bit_flush(uint32_t state_address);
void sfera_zlib_bit_windup(uint32_t state_address);
void sfera_zlib_copy_stored_block(uint32_t state_address, uint32_t buffer_address, uint32_t length, uint32_t write_header);
void sfera_zlib_write_stored_block(uint32_t state_address, uint32_t buffer_address, uint32_t length, uint32_t end_of_file);
void sfera_zlib_align_static_block(uint32_t state_address);
void sfera_zlib_set_data_type(uint32_t state_address);
uint32_t sfera_zlib_deflate_reset(uint32_t stream_address);
uint32_t sfera_zlib_deflate(uint32_t stream_address, int32_t flush);
uint32_t sfera_zlib_deflate_stored(uint32_t state_address, int32_t flush);
uint32_t sfera_zlib_deflate_fast(uint32_t state_address, int32_t flush);
uint32_t sfera_zlib_deflate_slow(uint32_t state_address, int32_t flush);
uint32_t sfera_zlib_inflate_fixed(uint32_t literal_bits_address, uint32_t distance_bits_address, uint32_t literal_root_address, uint32_t distance_root_address);
uint32_t sfera_zlib_huft_build(uint32_t lengths_address, uint32_t code_count, uint32_t simple_count, uint32_t base_values_address, uint32_t extra_bits_address, uint32_t root_address, uint32_t root_bits_address, uint32_t pool_address, uint32_t used_address, uint32_t work_address);
