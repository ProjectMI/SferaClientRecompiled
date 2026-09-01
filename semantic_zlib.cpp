#include "semantic_zlib.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdlib>

uint32_t __cdecl sfera_zlib_adler32_callback(uint32_t adler, uint32_t buffer_address, uint32_t length) noexcept { return sfera_zlib_adler32(adler, buffer_address, length); }
void* __cdecl sfera_zlib_alloc_callback(void*, uint32_t items, uint32_t size) noexcept { return std::calloc(items, size); }
void __cdecl sfera_zlib_free_callback(void*, void* address) noexcept { std::free(address); }

namespace {

struct SferaDeflateStatePrefix32 {
    uint32_t strm;
    int32_t status;
    uint32_t pending_buf;
    uint32_t pending_buf_size;
    uint32_t pending_out;
    int32_t pending;
    int32_t noheader;
    uint8_t data_type;
    uint8_t method;
    uint16_t reserved_1e;
    int32_t last_flush;
    uint32_t w_size;
    uint32_t w_bits;
    uint32_t w_mask;
    uint32_t window;
    uint32_t window_size;
    uint32_t prev;
    uint32_t head;
    uint32_t ins_h;
    uint32_t hash_size;
    uint32_t hash_bits;
    uint32_t hash_mask;
    uint32_t hash_shift;
    int32_t block_start;
    uint32_t match_length;
    uint32_t prev_match;
    int32_t match_available;
    uint32_t strstart;
    uint32_t match_start;
    uint32_t lookahead;
    uint32_t prev_length;
    uint32_t max_chain_length;
    uint32_t max_lazy_match;
    int32_t level;
    int32_t strategy;
    uint32_t good_match;
    int32_t nice_match;
};

struct SferaDeflateConfig {
    uint16_t good_length;
    uint16_t max_lazy;
    uint16_t nice_length;
    uint16_t max_chain;
};

struct SferaInflateHuft32 {
    uint8_t operation;
    uint8_t bits;
    uint16_t reserved;
    uint32_t base;
};


static SferaInflateHuft32 g_sfera_zlib_fixed_literal_pool[512] = {};
static SferaInflateHuft32 g_sfera_zlib_fixed_distance_pool[512] = {};

template <typename T>
static T* sfera_zlib_pointer(uint32_t address) {
    return reinterpret_cast<T*>(static_cast<uintptr_t>(address));
}

static uint32_t sfera_zlib_address(const void* pointer) {
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(pointer));
}

static uint8_t* sfera_zlib_bytes(uint32_t address) {
    return reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(address));
}

static SferaDeflateConfig sfera_zlib_deflate_config(int32_t level) {
    switch (level) {
        case 0: return {0u, 0u, 0u, 0u};
        case 1: return {4u, 4u, 8u, 4u};
        case 2: return {4u, 5u, 16u, 8u};
        case 3: return {4u, 6u, 32u, 32u};
        case 4: return {4u, 4u, 16u, 16u};
        case 5: return {8u, 16u, 32u, 32u};
        case 6: return {8u, 16u, 128u, 128u};
        case 7: return {8u, 32u, 128u, 256u};
        case 8: return {32u, 128u, 258u, 1024u};
        case 9: return {32u, 258u, 258u, 4096u};
        default: return {0u, 0u, 0u, 0u};
    }
}
}

struct SferaCtData32 {
    uint16_t code;
    uint16_t length;
};


struct SferaTreeDesc32 {
    uint32_t dynamic_tree;
    int32_t max_code;
    uint32_t static_descriptor;
};

struct SferaDeflateState32 {
    SferaDeflateStatePrefix32 prefix;
    SferaCtData32 dynamic_literal_tree[573];
    SferaCtData32 dynamic_distance_tree[61];
    SferaCtData32 bit_length_tree[39];
    SferaTreeDesc32 literal_descriptor;
    SferaTreeDesc32 distance_descriptor;
    SferaTreeDesc32 bit_length_descriptor;
    uint16_t bit_length_counts[16];
    uint32_t heap[573];
    int32_t heap_length;
    int32_t heap_max;
    uint8_t depth[573];
    uint8_t depth_padding[3];
    uint32_t literal_buffer;
    uint32_t literal_buffer_size;
    uint32_t last_literal;
    uint32_t distance_buffer;
    uint32_t optimal_length;
    uint32_t static_length;
    uint32_t matches;
    int32_t last_eob_length;
    uint16_t bit_buffer;
    uint16_t bit_buffer_padding;
    int32_t valid_bits;
};

static uint16_t sfera_zlib_reverse_bits(uint32_t value, uint32_t bit_count) {
    uint32_t result = 0u;
    for (uint32_t bit = 0u; bit != bit_count; ++bit) { result = (result << 1u) | ((value >> bit) & 1u); }
    return static_cast<uint16_t>(result);
}

uint32_t sfera_zlib_fixed_literal_length(uint32_t symbol) {
    if (symbol <= 143u) { return 8u; }
    if (symbol <= 255u) { return 9u; }
    if (symbol <= 279u) { return 7u; }
    return symbol <= 287u ? 8u : 0u;
}

uint32_t sfera_zlib_fixed_literal_code(uint32_t symbol) {
    if (symbol <= 143u) { return sfera_zlib_reverse_bits(symbol + 0x30u, 8u); }
    if (symbol <= 255u) { return sfera_zlib_reverse_bits(symbol - 144u + 0x190u, 9u); }
    if (symbol <= 279u) { return sfera_zlib_reverse_bits(symbol - 256u, 7u); }
    if (symbol <= 287u) { return sfera_zlib_reverse_bits(symbol - 280u + 0xC0u, 8u); }
    return 0u;
}

uint32_t sfera_zlib_fixed_distance_code(uint32_t symbol) {
    return symbol < 30u ? sfera_zlib_reverse_bits(symbol, 5u) : 0u;
}

static SferaCtData32 sfera_zlib_tree_entry(uint32_t tree_address, uint32_t symbol, bool distance_tree) {
    if (tree_address != 0u) { return sfera_zlib_pointer<SferaCtData32>(tree_address)[symbol]; }
    SferaCtData32 entry = {};
    entry.code = static_cast<uint16_t>(distance_tree ? sfera_zlib_fixed_distance_code(symbol) : sfera_zlib_fixed_literal_code(symbol));
    entry.length = static_cast<uint16_t>(distance_tree ? 5u : sfera_zlib_fixed_literal_length(symbol));
    return entry;
}

static void sfera_zlib_put_short_le(uint32_t state_address, uint16_t value) {
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* pending = sfera_zlib_bytes(state->pending_buf);
    pending[state->pending++] = static_cast<uint8_t>(value);
    pending[state->pending++] = static_cast<uint8_t>(value >> 8u);
}

static void sfera_zlib_send_bits(uint32_t state_address, uint32_t value, uint32_t length) {
    uint16_t& bit_buffer = *sfera_zlib_pointer<uint16_t>(state_address + 0x16B0u);
    uint32_t& valid_bits = *sfera_zlib_pointer<uint32_t>(state_address + 0x16B4u);
    if (length == 0u) { return; }
    if (valid_bits > 16u - length) {
        bit_buffer = static_cast<uint16_t>(bit_buffer | static_cast<uint16_t>(value << valid_bits));
        sfera_zlib_put_short_le(state_address, bit_buffer);
        bit_buffer = static_cast<uint16_t>(value >> (16u - valid_bits));
        valid_bits += length - 16u;
    }
    else {
        bit_buffer = static_cast<uint16_t>(bit_buffer | static_cast<uint16_t>(value << valid_bits));
        valid_bits += length;
    }
}

static void sfera_zlib_send_tree_code(uint32_t state_address, uint32_t tree_address, uint32_t symbol, bool distance_tree) {
    const SferaCtData32 entry = sfera_zlib_tree_entry(tree_address, symbol, distance_tree);
    sfera_zlib_send_bits(state_address, entry.code, entry.length);
}


uint32_t sfera_zlib_bit_reverse(uint32_t value, uint32_t bit_count) {
    return sfera_zlib_reverse_bits(value, bit_count);
}

void sfera_zlib_bit_flush(uint32_t state_address) {
    uint16_t& bit_buffer = *sfera_zlib_pointer<uint16_t>(state_address + 0x16B0u);
    uint32_t& valid_bits = *sfera_zlib_pointer<uint32_t>(state_address + 0x16B4u);
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* pending = sfera_zlib_bytes(state->pending_buf);
    if (valid_bits == 16u) { pending[state->pending++] = static_cast<uint8_t>(bit_buffer); pending[state->pending++] = static_cast<uint8_t>(bit_buffer >> 8u); bit_buffer = 0u; valid_bits = 0u; }
    else if (valid_bits >= 8u) { pending[state->pending++] = static_cast<uint8_t>(bit_buffer); bit_buffer = static_cast<uint16_t>(bit_buffer >> 8u); valid_bits -= 8u; }
}

void sfera_zlib_bit_windup(uint32_t state_address) {
    uint16_t& bit_buffer = *sfera_zlib_pointer<uint16_t>(state_address + 0x16B0u);
    uint32_t& valid_bits = *sfera_zlib_pointer<uint32_t>(state_address + 0x16B4u);
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* pending = sfera_zlib_bytes(state->pending_buf);
    if (valid_bits > 8u) { pending[state->pending++] = static_cast<uint8_t>(bit_buffer); pending[state->pending++] = static_cast<uint8_t>(bit_buffer >> 8u); }
    else if (valid_bits != 0u) { pending[state->pending++] = static_cast<uint8_t>(bit_buffer); }
    bit_buffer = 0u;
    valid_bits = 0u;
}

void sfera_zlib_copy_stored_block(uint32_t state_address, uint32_t buffer_address, uint32_t length, uint32_t write_header) {
    sfera_zlib_bit_windup(state_address);
    *sfera_zlib_pointer<uint32_t>(state_address + 0x16ACu) = 8u;
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* pending = sfera_zlib_bytes(state->pending_buf);
    if (write_header != 0u) {
        const uint16_t block_length = static_cast<uint16_t>(length);
        const uint16_t complement = static_cast<uint16_t>(~block_length);
        pending[state->pending++] = static_cast<uint8_t>(block_length);
        pending[state->pending++] = static_cast<uint8_t>(block_length >> 8u);
        pending[state->pending++] = static_cast<uint8_t>(complement);
        pending[state->pending++] = static_cast<uint8_t>(complement >> 8u);
    }
    if (length != 0u) { std::memcpy(pending + state->pending, sfera_zlib_bytes(buffer_address), length); state->pending += static_cast<int32_t>(length); }
}


void sfera_zlib_write_stored_block(uint32_t state_address, uint32_t buffer_address, uint32_t length, uint32_t end_of_file) {
    sfera_zlib_send_bits(state_address, end_of_file & 1u, 3u);
    sfera_zlib_copy_stored_block(state_address, buffer_address, length, 1u);
}

void sfera_zlib_align_static_block(uint32_t state_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    sfera_zlib_send_bits(state_address, 2u, 3u);
    sfera_zlib_send_tree_code(state_address, 0u, 256u, false);
    sfera_zlib_bit_flush(state_address);
    if (1 + state->last_eob_length + 10 - state->valid_bits < 9) {
        sfera_zlib_send_bits(state_address, 2u, 3u);
        sfera_zlib_send_tree_code(state_address, 0u, 256u, false);
        sfera_zlib_bit_flush(state_address);
    }
    state->last_eob_length = 7;
}

void sfera_zlib_set_data_type(uint32_t state_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint32_t binary_frequency = 0u;
    uint32_t ascii_frequency = 0u;
    uint32_t symbol = 0u;
    while (symbol < 7u) { binary_frequency += state->dynamic_literal_tree[symbol++].code; }
    while (symbol < 128u) { ascii_frequency += state->dynamic_literal_tree[symbol++].code; }
    while (symbol < 256u) { binary_frequency += state->dynamic_literal_tree[symbol++].code; }
    state->prefix.data_type = static_cast<uint8_t>(binary_frequency > (ascii_frequency >> 2u) ? 0u : 1u);
}



enum class SferaZlibTreeKind : uint32_t { Literal, Distance, BitLength, Unknown };

static SferaZlibTreeKind sfera_zlib_tree_kind(uint32_t state_address, uint32_t descriptor_address) {
    const uint32_t offset = descriptor_address - state_address;
    if (offset == offsetof(SferaDeflateState32, literal_descriptor)) { return SferaZlibTreeKind::Literal; }
    if (offset == offsetof(SferaDeflateState32, distance_descriptor)) { return SferaZlibTreeKind::Distance; }
    if (offset == offsetof(SferaDeflateState32, bit_length_descriptor)) { return SferaZlibTreeKind::BitLength; }
    return SferaZlibTreeKind::Unknown;
}

static uint32_t sfera_zlib_tree_element_count(SferaZlibTreeKind kind) {
    switch (kind) { case SferaZlibTreeKind::Literal: return 286u; case SferaZlibTreeKind::Distance: return 30u; case SferaZlibTreeKind::BitLength: return 19u; default: return 0u; }
}

static uint32_t sfera_zlib_tree_max_length(SferaZlibTreeKind kind) { return kind == SferaZlibTreeKind::BitLength ? 7u : 15u; }

static uint32_t sfera_zlib_tree_extra_bits(SferaZlibTreeKind kind, uint32_t symbol) {
    if (kind == SferaZlibTreeKind::Literal && symbol >= 257u) { const uint32_t code = symbol - 257u; return code >= 8u && code < 28u ? (code - 4u) >> 2u : 0u; }
    if (kind == SferaZlibTreeKind::Distance) { return symbol >= 4u && symbol < 30u ? (symbol >> 1u) - 1u : 0u; }
    if (kind == SferaZlibTreeKind::BitLength) { if (symbol == 16u) { return 2u; } if (symbol == 17u) { return 3u; } if (symbol == 18u) { return 7u; } }
    return 0u;
}

static uint32_t sfera_zlib_static_symbol_length(SferaZlibTreeKind kind, uint32_t symbol) {
    if (kind == SferaZlibTreeKind::Literal) { return sfera_zlib_fixed_literal_length(symbol); }
    if (kind == SferaZlibTreeKind::Distance) { return 5u; }
    return 0u;
}

static bool sfera_zlib_heap_less(const SferaDeflateState32* state, const SferaCtData32* tree, uint32_t left, uint32_t right) {
    return tree[left].code < tree[right].code || (tree[left].code == tree[right].code && state->depth[left] <= state->depth[right]);
}

static void sfera_zlib_pq_down_heap_impl(SferaDeflateState32* state, SferaCtData32* tree, uint32_t heap_index) {
    const uint32_t value = state->heap[heap_index];
    uint32_t child = heap_index << 1u;
    while (child <= static_cast<uint32_t>(state->heap_length)) {
        if (child < static_cast<uint32_t>(state->heap_length) && sfera_zlib_heap_less(state, tree, state->heap[child + 1u], state->heap[child])) { ++child; }
        if (sfera_zlib_heap_less(state, tree, value, state->heap[child])) { break; }
        state->heap[heap_index] = state->heap[child];
        heap_index = child;
        child <<= 1u;
    }
    state->heap[heap_index] = value;
}

static void sfera_zlib_generate_codes_impl(SferaCtData32* tree, int32_t max_code, const uint16_t* bit_counts) {
    uint16_t next_code[16] = {};
    uint32_t code = 0u;
    for (uint32_t bits = 1u; bits <= 15u; ++bits) { code = (code + bit_counts[bits - 1u]) << 1u; next_code[bits] = static_cast<uint16_t>(code); }
    for (int32_t symbol = 0; symbol <= max_code; ++symbol) { const uint32_t length = tree[symbol].length; if (length != 0u) { tree[symbol].code = sfera_zlib_reverse_bits(next_code[length]++, length); } }
}

static void sfera_zlib_generate_bit_lengths_impl(uint32_t state_address, uint32_t descriptor_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    SferaTreeDesc32* descriptor = sfera_zlib_pointer<SferaTreeDesc32>(descriptor_address);
    SferaCtData32* tree = sfera_zlib_pointer<SferaCtData32>(descriptor->dynamic_tree);
    const SferaZlibTreeKind kind = sfera_zlib_tree_kind(state_address, descriptor_address);
    const uint32_t max_length = sfera_zlib_tree_max_length(kind);
    for (uint32_t bits = 0u; bits <= 15u; ++bits) { state->bit_length_counts[bits] = 0u; }
    tree[state->heap[state->heap_max]].length = 0u;
    int32_t overflow = 0;
    for (int32_t heap_index = state->heap_max + 1; heap_index < 573; ++heap_index) {
        const uint32_t symbol = state->heap[heap_index];
        uint32_t bits = static_cast<uint32_t>(tree[tree[symbol].length].length) + 1u;
        if (bits > max_length) { bits = max_length; ++overflow; }
        tree[symbol].length = static_cast<uint16_t>(bits);
        if (symbol > static_cast<uint32_t>(descriptor->max_code)) { continue; }
        ++state->bit_length_counts[bits];
        const uint32_t extra = sfera_zlib_tree_extra_bits(kind, symbol);
        const uint32_t frequency = tree[symbol].code;
        state->optimal_length += frequency * (bits + extra);
        const uint32_t fixed_length = sfera_zlib_static_symbol_length(kind, symbol);
        if (fixed_length != 0u) { state->static_length += frequency * (fixed_length + extra); }
    }
    while (overflow > 0) {
        int32_t bits = static_cast<int32_t>(max_length) - 1;
        while (bits > 0 && state->bit_length_counts[bits] == 0u) { --bits; }
        --state->bit_length_counts[bits];
        state->bit_length_counts[bits + 1] = static_cast<uint16_t>(state->bit_length_counts[bits + 1] + 2u);
        --state->bit_length_counts[max_length];
        overflow -= 2;
    }
    int32_t heap_index = 573;
    for (int32_t bits = static_cast<int32_t>(max_length); bits != 0; --bits) {
        uint32_t remaining = state->bit_length_counts[bits];
        while (remaining != 0u) {
            const uint32_t symbol = state->heap[--heap_index];
            if (symbol > static_cast<uint32_t>(descriptor->max_code)) { continue; }
            if (tree[symbol].length != static_cast<uint32_t>(bits)) { state->optimal_length += static_cast<uint32_t>((static_cast<int32_t>(bits) - static_cast<int32_t>(tree[symbol].length)) * static_cast<int32_t>(tree[symbol].code)); tree[symbol].length = static_cast<uint16_t>(bits); }
            --remaining;
        }
    }
}

void sfera_zlib_pq_down_heap(uint32_t state_address, uint32_t tree_address, uint32_t heap_index) {
    sfera_zlib_pq_down_heap_impl(sfera_zlib_pointer<SferaDeflateState32>(state_address), sfera_zlib_pointer<SferaCtData32>(tree_address), heap_index);
}

void sfera_zlib_generate_bit_lengths(uint32_t state_address, uint32_t descriptor_address) { sfera_zlib_generate_bit_lengths_impl(state_address, descriptor_address); }

void sfera_zlib_generate_codes(uint32_t tree_address, int32_t max_code, uint32_t bit_counts_address) { sfera_zlib_generate_codes_impl(sfera_zlib_pointer<SferaCtData32>(tree_address), max_code, sfera_zlib_pointer<uint16_t>(bit_counts_address)); }

void sfera_zlib_init_block(uint32_t state_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    for (uint32_t symbol = 0u; symbol != 286u; ++symbol) { state->dynamic_literal_tree[symbol].code = 0u; }
    for (uint32_t symbol = 0u; symbol != 30u; ++symbol) { state->dynamic_distance_tree[symbol].code = 0u; }
    for (uint32_t symbol = 0u; symbol != 19u; ++symbol) { state->bit_length_tree[symbol].code = 0u; }
    state->dynamic_literal_tree[256].code = 1u;
    state->optimal_length = 0u;
    state->static_length = 0u;
    state->matches = 0u;
    state->last_literal = 0u;
}

void sfera_zlib_tree_init(uint32_t state_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    state->literal_descriptor.dynamic_tree = state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, dynamic_literal_tree));
    state->literal_descriptor.max_code = -1;
    state->literal_descriptor.static_descriptor = 0u;
    state->distance_descriptor.dynamic_tree = state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, dynamic_distance_tree));
    state->distance_descriptor.max_code = -1;
    state->distance_descriptor.static_descriptor = 0u;
    state->bit_length_descriptor.dynamic_tree = state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, bit_length_tree));
    state->bit_length_descriptor.max_code = -1;
    state->bit_length_descriptor.static_descriptor = 0u;
    state->bit_buffer = 0u;
    state->valid_bits = 0;
    state->last_eob_length = 8;
    sfera_zlib_init_block(state_address);
}

void sfera_zlib_build_tree(uint32_t state_address, uint32_t descriptor_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    SferaTreeDesc32* descriptor = sfera_zlib_pointer<SferaTreeDesc32>(descriptor_address);
    const SferaZlibTreeKind kind = sfera_zlib_tree_kind(state_address, descriptor_address);
    const uint32_t element_count = sfera_zlib_tree_element_count(kind);
    SferaCtData32* tree = sfera_zlib_pointer<SferaCtData32>(descriptor->dynamic_tree);
    int32_t max_code = -1;
    state->heap_length = 0;
    state->heap_max = 573;
    for (uint32_t symbol = 0u; symbol != element_count; ++symbol) {
        if (tree[symbol].code != 0u) { state->heap[++state->heap_length] = symbol; max_code = static_cast<int32_t>(symbol); state->depth[symbol] = 0u; }
        else { tree[symbol].length = 0u; }
    }
    while (state->heap_length < 2) {
        const uint32_t symbol = max_code < 2 ? static_cast<uint32_t>(++max_code) : 0u;
        state->heap[++state->heap_length] = symbol;
        tree[symbol].code = 1u;
        state->depth[symbol] = 0u;
        --state->optimal_length;
        const uint32_t fixed_length = sfera_zlib_static_symbol_length(kind, symbol);
        if (fixed_length != 0u) { state->static_length -= fixed_length; }
    }
    descriptor->max_code = max_code;
    for (int32_t heap_index = state->heap_length / 2; heap_index >= 1; --heap_index) { sfera_zlib_pq_down_heap_impl(state, tree, static_cast<uint32_t>(heap_index)); }
    uint32_t node = element_count;
    do {
        const uint32_t first = state->heap[1];
        state->heap[1] = state->heap[state->heap_length--];
        sfera_zlib_pq_down_heap_impl(state, tree, 1u);
        const uint32_t second = state->heap[1];
        state->heap[--state->heap_max] = first;
        state->heap[--state->heap_max] = second;
        tree[node].code = static_cast<uint16_t>(tree[first].code + tree[second].code);
        state->depth[node] = static_cast<uint8_t>((state->depth[first] > state->depth[second] ? state->depth[first] : state->depth[second]) + 1u);
        tree[first].length = static_cast<uint16_t>(node);
        tree[second].length = static_cast<uint16_t>(node);
        state->heap[1] = node++;
        sfera_zlib_pq_down_heap_impl(state, tree, 1u);
    } while (state->heap_length >= 2);
    state->heap[--state->heap_max] = state->heap[1];
    sfera_zlib_generate_bit_lengths_impl(state_address, descriptor_address);
    sfera_zlib_generate_codes_impl(tree, max_code, state->bit_length_counts);
}

void sfera_zlib_scan_tree(uint32_t state_address, uint32_t tree_address, int32_t max_code) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    SferaCtData32* tree = sfera_zlib_pointer<SferaCtData32>(tree_address);
    int32_t previous_length = -1;
    int32_t next_length = tree[0].length;
    uint32_t count = 0u;
    uint32_t maximum_count = next_length == 0 ? 138u : 7u;
    uint32_t minimum_count = next_length == 0 ? 3u : 4u;
    tree[max_code + 1].length = 0xFFFFu;
    for (int32_t symbol = 0; symbol <= max_code; ++symbol) {
        const int32_t current_length = next_length;
        next_length = tree[symbol + 1].length;
        ++count;
        if (count < maximum_count && current_length == next_length) { continue; }
        if (count < minimum_count) { state->bit_length_tree[current_length].code = static_cast<uint16_t>(state->bit_length_tree[current_length].code + count); }
        else if (current_length != 0) { if (current_length != previous_length) { ++state->bit_length_tree[current_length].code; } ++state->bit_length_tree[16].code; }
        else if (count <= 10u) { ++state->bit_length_tree[17].code; }
        else { ++state->bit_length_tree[18].code; }
        count = 0u;
        previous_length = current_length;
        if (next_length == 0) { maximum_count = 138u; minimum_count = 3u; }
        else if (current_length == next_length) { maximum_count = 6u; minimum_count = 3u; }
        else { maximum_count = 7u; minimum_count = 4u; }
    }
}

void sfera_zlib_send_tree(uint32_t state_address, uint32_t tree_address, int32_t max_code) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    SferaCtData32* tree = sfera_zlib_pointer<SferaCtData32>(tree_address);
    const uint32_t bit_tree_address = state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, bit_length_tree));
    int32_t previous_length = -1;
    int32_t next_length = tree[0].length;
    uint32_t count = 0u;
    uint32_t maximum_count = next_length == 0 ? 138u : 7u;
    uint32_t minimum_count = next_length == 0 ? 3u : 4u;
    for (int32_t symbol = 0; symbol <= max_code; ++symbol) {
        const int32_t current_length = next_length;
        next_length = tree[symbol + 1].length;
        ++count;
        if (count < maximum_count && current_length == next_length) { continue; }
        if (count < minimum_count) { while (count-- != 0u) { sfera_zlib_send_tree_code(state_address, bit_tree_address, static_cast<uint32_t>(current_length), false); } }
        else if (current_length != 0) {
            if (current_length != previous_length) { sfera_zlib_send_tree_code(state_address, bit_tree_address, static_cast<uint32_t>(current_length), false); --count; }
            sfera_zlib_send_tree_code(state_address, bit_tree_address, 16u, false);
            sfera_zlib_send_bits(state_address, count - 3u, 2u);
        }
        else if (count <= 10u) { sfera_zlib_send_tree_code(state_address, bit_tree_address, 17u, false); sfera_zlib_send_bits(state_address, count - 3u, 3u); }
        else { sfera_zlib_send_tree_code(state_address, bit_tree_address, 18u, false); sfera_zlib_send_bits(state_address, count - 11u, 7u); }
        count = 0u;
        previous_length = current_length;
        if (next_length == 0) { maximum_count = 138u; minimum_count = 3u; }
        else if (current_length == next_length) { maximum_count = 6u; minimum_count = 3u; }
        else { maximum_count = 7u; minimum_count = 4u; }
    }
}

int32_t sfera_zlib_build_bit_length_tree(uint32_t state_address) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    sfera_zlib_scan_tree(state_address, state->literal_descriptor.dynamic_tree, state->literal_descriptor.max_code);
    sfera_zlib_scan_tree(state_address, state->distance_descriptor.dynamic_tree, state->distance_descriptor.max_code);
    sfera_zlib_build_tree(state_address, state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, bit_length_descriptor)));
    int32_t last_rank = 18;
    while (last_rank >= 3) { const uint32_t rank = static_cast<uint32_t>(last_rank); const uint32_t order = rank == 3u ? 0u : (rank < 3u ? 16u + rank : 8u + ((rank - 4u) & 1u ? -static_cast<int32_t>((rank - 3u) >> 1u) : static_cast<int32_t>((rank - 4u) >> 1u))); if (state->bit_length_tree[order].length != 0u) { break; } --last_rank; }
    state->optimal_length += static_cast<uint32_t>(3 * (last_rank + 1) + 14);
    return last_rank;
}

void sfera_zlib_send_all_trees(uint32_t state_address, uint32_t literal_codes, uint32_t distance_codes, uint32_t bit_length_codes) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    sfera_zlib_send_bits(state_address, literal_codes - 257u, 5u);
    sfera_zlib_send_bits(state_address, distance_codes - 1u, 5u);
    sfera_zlib_send_bits(state_address, bit_length_codes - 4u, 4u);
    for (uint32_t rank = 0u; rank != bit_length_codes; ++rank) { const uint32_t order = rank < 3u ? 16u + rank : (rank == 3u ? 0u : 8u + ((rank - 4u) & 1u ? -static_cast<int32_t>((rank - 3u) >> 1u) : static_cast<int32_t>((rank - 4u) >> 1u))); sfera_zlib_send_bits(state_address, state->bit_length_tree[order].length, 3u); }
    sfera_zlib_send_tree(state_address, state->literal_descriptor.dynamic_tree, static_cast<int32_t>(literal_codes - 1u));
    sfera_zlib_send_tree(state_address, state->distance_descriptor.dynamic_tree, static_cast<int32_t>(distance_codes - 1u));
}

void sfera_zlib_flush_block(uint32_t state_address, uint32_t buffer_address, uint32_t stored_length, uint32_t end_of_file) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint32_t optimal_bytes = 0u;
    uint32_t static_bytes = 0u;
    int32_t last_bit_length_rank = 0;
    if (state->prefix.level > 0) {
        if (state->prefix.data_type == 2u) { sfera_zlib_set_data_type(state_address); }
        sfera_zlib_build_tree(state_address, state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, literal_descriptor)));
        sfera_zlib_build_tree(state_address, state_address + static_cast<uint32_t>(offsetof(SferaDeflateState32, distance_descriptor)));
        last_bit_length_rank = sfera_zlib_build_bit_length_tree(state_address);
        optimal_bytes = (state->optimal_length + 10u) >> 3u;
        static_bytes = (state->static_length + 10u) >> 3u;
        if (static_bytes <= optimal_bytes) { optimal_bytes = static_bytes; }
    }
    else { optimal_bytes = static_bytes = stored_length + 5u; }
    if (buffer_address != 0u && stored_length + 4u <= optimal_bytes) { sfera_zlib_write_stored_block(state_address, buffer_address, stored_length, end_of_file); }
    else if (static_bytes == optimal_bytes) { sfera_zlib_send_bits(state_address, 2u + (end_of_file & 1u), 3u); sfera_zlib_compress_block(state_address, 0u, 0u); }
    else {
        sfera_zlib_send_bits(state_address, 4u + (end_of_file & 1u), 3u);
        sfera_zlib_send_all_trees(state_address, static_cast<uint32_t>(state->literal_descriptor.max_code + 1), static_cast<uint32_t>(state->distance_descriptor.max_code + 1), static_cast<uint32_t>(last_bit_length_rank + 1));
        sfera_zlib_compress_block(state_address, state->literal_descriptor.dynamic_tree, state->distance_descriptor.dynamic_tree);
    }
    sfera_zlib_init_block(state_address);
    if (end_of_file != 0u) { sfera_zlib_bit_windup(state_address); }
}
void sfera_zlib_compress_block(uint32_t state_address, uint32_t literal_tree_address, uint32_t distance_tree_address) {
    const uint32_t literal_buffer_address = *sfera_zlib_pointer<uint32_t>(state_address + 0x1690u);
    const uint32_t literal_count = *sfera_zlib_pointer<uint32_t>(state_address + 0x1698u);
    const uint32_t distance_buffer_address = *sfera_zlib_pointer<uint32_t>(state_address + 0x169Cu);
    uint8_t* literals = sfera_zlib_pointer<uint8_t>(literal_buffer_address);
    uint16_t* distances = sfera_zlib_pointer<uint16_t>(distance_buffer_address);
    for (uint32_t index = 0u; index != literal_count; ++index) {
        uint32_t distance = distances[index];
        const uint32_t literal_or_length = literals[index];
        if (distance == 0u) { sfera_zlib_send_tree_code(state_address, literal_tree_address, literal_or_length, false); continue; }
        uint32_t length_code = literal_or_length;
        if (literal_or_length >= 255u) { length_code = 28u; } else if (literal_or_length >= 8u) { uint32_t highest_bit = 0u; for (uint32_t value = literal_or_length; value > 1u; value >>= 1u) { ++highest_bit; } const uint32_t extra = highest_bit - 2u; const uint32_t base = 1u << (extra + 2u); length_code = 4u * extra + 4u + ((literal_or_length - base) >> extra); }
        sfera_zlib_send_tree_code(state_address, literal_tree_address, length_code + 257u, false);
        const uint32_t length_extra = length_code >= 8u && length_code < 28u ? (length_code - 4u) >> 2u : 0u;
        if (length_extra != 0u) { const uint32_t group_begin = 4u * length_extra + 4u; const uint32_t base = (1u << (length_extra + 2u)) + ((length_code - group_begin) << length_extra); sfera_zlib_send_bits(state_address, literal_or_length - base, length_extra); }
        --distance;
        uint32_t distance_code = distance;
        if (distance >= 4u) { uint32_t highest_bit = 0u; for (uint32_t value = distance; value > 1u; value >>= 1u) { ++highest_bit; } const uint32_t extra = highest_bit - 1u; distance_code = (highest_bit << 1u) + ((distance >> extra) & 1u); }
        sfera_zlib_send_tree_code(state_address, distance_tree_address, distance_code, true);
        const uint32_t distance_extra = distance_code >= 4u ? (distance_code >> 1u) - 1u : 0u;
        if (distance_extra != 0u) { const uint32_t base = (1u << (distance_extra + 1u)) + ((distance_code & 1u) << distance_extra); sfera_zlib_send_bits(state_address, distance - base, distance_extra); }
    }
    sfera_zlib_send_tree_code(state_address, literal_tree_address, 256u, false);
    *sfera_zlib_pointer<uint32_t>(state_address + 0x16ACu) = sfera_zlib_tree_entry(literal_tree_address, 256u, false).length;
}




static bool sfera_zlib_tally(uint32_t state_address, uint32_t distance, uint32_t literal_or_length) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint8_t* literals = sfera_zlib_pointer<uint8_t>(state->literal_buffer);
    uint16_t* distances = sfera_zlib_pointer<uint16_t>(state->distance_buffer);
    const uint32_t index = state->last_literal++;
    distances[index] = static_cast<uint16_t>(distance);
    literals[index] = static_cast<uint8_t>(literal_or_length);
    if (distance == 0u) { ++state->dynamic_literal_tree[literal_or_length].code; }
    else {
        ++state->matches;
        const uint32_t normalized_distance = distance - 1u;
        uint32_t distance_code = normalized_distance;
        if (normalized_distance >= 4u) { uint32_t highest_bit = 0u; for (uint32_t value = normalized_distance; value > 1u; value >>= 1u) { ++highest_bit; } distance_code = (highest_bit << 1u) + ((normalized_distance >> (highest_bit - 1u)) & 1u); }
        uint32_t length_code = literal_or_length;
        if (literal_or_length >= 255u) { length_code = 28u; } else if (literal_or_length >= 8u) { uint32_t highest_bit = 0u; for (uint32_t value = literal_or_length; value > 1u; value >>= 1u) { ++highest_bit; } const uint32_t extra = highest_bit - 2u; length_code = 4u * extra + 4u + ((literal_or_length - (1u << (extra + 2u))) >> extra); }
        ++state->dynamic_literal_tree[length_code + 257u].code;
        ++state->dynamic_distance_tree[distance_code].code;
    }
    return state->last_literal == state->literal_buffer_size - 1u;
}

static uint32_t sfera_zlib_insert_string(SferaDeflateState32* state, uint8_t* window, uint16_t* previous, uint16_t* heads) {
    state->prefix.ins_h = ((state->prefix.ins_h << state->prefix.hash_shift) ^ window[state->prefix.strstart + 2u]) & state->prefix.hash_mask;
    const uint32_t hash_head = heads[state->prefix.ins_h];
    previous[state->prefix.strstart & state->prefix.w_mask] = static_cast<uint16_t>(hash_head);
    heads[state->prefix.ins_h] = static_cast<uint16_t>(state->prefix.strstart);
    return hash_head;
}

static int32_t sfera_zlib_flush_current_block(uint32_t state_address, bool end_of_file) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    const uint32_t buffer_address = state->prefix.block_start >= 0 ? state->prefix.window + static_cast<uint32_t>(state->prefix.block_start) : 0u;
    const uint32_t stored_length = static_cast<uint32_t>(static_cast<int64_t>(state->prefix.strstart) - static_cast<int64_t>(state->prefix.block_start));
    sfera_zlib_flush_block(state_address, buffer_address, stored_length, end_of_file ? 1u : 0u);
    state->prefix.block_start = static_cast<int32_t>(state->prefix.strstart);
    sfera_zlib_deflate_flush_pending(state->prefix.strm);
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(state->prefix.strm);
    if (stream->avail_out == 0u) { return end_of_file ? 2 : 0; }
    return -1;
}




uint32_t sfera_zlib_deflate_reset(uint32_t stream_address) {
    if (stream_address == 0u) { return static_cast<uint32_t>(-2); }
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(stream_address);
    if (stream->state == 0u || !stream->zalloc || !stream->zfree) { return static_cast<uint32_t>(-2); }
    stream->total_in = 0u;
    stream->total_out = 0u;
    stream->msg = 0u;
    stream->data_type = 2;
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(stream->state);
    state->prefix.pending = 0;
    state->prefix.pending_out = state->prefix.pending_buf;
    if (state->prefix.noheader < 0) { state->prefix.noheader = 0; }
    state->prefix.status = state->prefix.noheader != 0 ? 113 : 42;
    stream->adler = 1u;
    state->prefix.last_flush = 0;
    sfera_zlib_tree_init(stream->state);
    sfera_zlib_deflate_lm_init(stream->state);
    return 0u;
}

uint32_t sfera_zlib_deflate(uint32_t stream_address, int32_t flush) {
    if (stream_address == 0u || flush < 0 || flush > 4) { return static_cast<uint32_t>(-2); }
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(stream_address);
    if (stream->state == 0u) { return static_cast<uint32_t>(-2); }
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(stream->state);
    if (stream->next_out == 0u || (stream->next_in == 0u && stream->avail_in != 0u) || (state->prefix.status == 666 && flush != 4)) { stream->msg = static_cast<uint32_t>(reinterpret_cast<uintptr_t>("stream error")); return static_cast<uint32_t>(-2); }
    if (stream->avail_out == 0u) { stream->msg = static_cast<uint32_t>(reinterpret_cast<uintptr_t>("buffer error")); return static_cast<uint32_t>(-5); }
    state->prefix.strm = stream_address;
    const int32_t previous_flush = state->prefix.last_flush;
    state->prefix.last_flush = flush;
    if (state->prefix.status == 42) {
        uint32_t header = (static_cast<uint32_t>(state->prefix.method) + ((state->prefix.w_bits - 8u) << 4u)) << 8u;
        uint32_t level_flags = static_cast<uint32_t>((state->prefix.level - 1) >> 1);
        if (level_flags > 3u) { level_flags = 3u; }
        header |= level_flags << 6u;
        if (state->prefix.strstart != 0u) { header |= 0x20u; }
        header += 31u - header % 31u;
        state->prefix.status = 113;
        sfera_zlib_deflate_put_short_msb(stream->state, header);
        if (state->prefix.strstart != 0u) { sfera_zlib_deflate_put_short_msb(stream->state, stream->adler >> 16u); sfera_zlib_deflate_put_short_msb(stream->state, stream->adler & 0xFFFFu); }
        stream->adler = 1u;
    }
    if (state->prefix.pending != 0) {
        sfera_zlib_deflate_flush_pending(stream_address);
        if (stream->avail_out == 0u) { state->prefix.last_flush = -1; return 0u; }
    }
    else if (stream->avail_in == 0u && flush <= previous_flush && flush != 4) { stream->msg = static_cast<uint32_t>(reinterpret_cast<uintptr_t>("buffer error")); return static_cast<uint32_t>(-5); }
    if (state->prefix.status == 666 && stream->avail_in != 0u) { stream->msg = static_cast<uint32_t>(reinterpret_cast<uintptr_t>("buffer error")); return static_cast<uint32_t>(-5); }
    if (stream->avail_in != 0u || state->prefix.lookahead != 0u || (flush != 0 && state->prefix.status != 666)) {
        uint32_t block_state = 0u;
        if (state->prefix.level == 0) { block_state = sfera_zlib_deflate_stored(stream->state, flush); }
        else if (state->prefix.level <= 3) { block_state = sfera_zlib_deflate_fast(stream->state, flush); }
        else { block_state = sfera_zlib_deflate_slow(stream->state, flush); }
        if (block_state == 2u || block_state == 3u) { state->prefix.status = 666; }
        if (block_state == 0u || block_state == 2u) { if (stream->avail_out == 0u) { state->prefix.last_flush = -1; } return 0u; }
        if (block_state == 1u) {
            if (flush == 1) { sfera_zlib_align_static_block(stream->state); }
            else {
                sfera_zlib_write_stored_block(stream->state, 0u, 0u, 0u);
                if (flush == 3) { std::memset(sfera_zlib_pointer<uint16_t>(state->prefix.head), 0, state->prefix.hash_size * sizeof(uint16_t)); }
            }
            sfera_zlib_deflate_flush_pending(stream_address);
            if (stream->avail_out == 0u) { state->prefix.last_flush = -1; return 0u; }
        }
    }
    if (flush != 4) { return 0u; }
    if (state->prefix.noheader != 0) { return 1u; }
    sfera_zlib_deflate_put_short_msb(stream->state, stream->adler >> 16u);
    sfera_zlib_deflate_put_short_msb(stream->state, stream->adler & 0xFFFFu);
    sfera_zlib_deflate_flush_pending(stream_address);
    state->prefix.noheader = -1;
    return state->prefix.pending != 0 ? 0u : 1u;
}


uint32_t sfera_zlib_deflate_stored(uint32_t state_address, int32_t flush) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint32_t max_block_size = 0xFFFFu;
    if (max_block_size > state->prefix.pending_buf_size - 5u) { max_block_size = state->prefix.pending_buf_size - 5u; }
    for (;;) {
        if (state->prefix.lookahead <= 1u) {
            sfera_zlib_deflate_fill_window(state_address);
            if (state->prefix.lookahead == 0u && flush == 0) { return 0u; }
            if (state->prefix.lookahead == 0u) { break; }
        }
        state->prefix.strstart += state->prefix.lookahead;
        state->prefix.lookahead = 0u;
        const uint32_t max_start = static_cast<uint32_t>(state->prefix.block_start) + max_block_size;
        if (state->prefix.strstart == 0u || state->prefix.strstart >= max_start) {
            state->prefix.lookahead = state->prefix.strstart - max_start;
            state->prefix.strstart = max_start;
            const int32_t result = sfera_zlib_flush_current_block(state_address, false);
            if (result >= 0) { return static_cast<uint32_t>(result); }
        }
        if (state->prefix.strstart - static_cast<uint32_t>(state->prefix.block_start) >= state->prefix.w_size - 262u) {
            const int32_t result = sfera_zlib_flush_current_block(state_address, false);
            if (result >= 0) { return static_cast<uint32_t>(result); }
        }
    }
    const bool finishing = flush == 4;
    const int32_t result = sfera_zlib_flush_current_block(state_address, finishing);
    return result >= 0 ? static_cast<uint32_t>(result) : (finishing ? 3u : 1u);
}

uint32_t sfera_zlib_deflate_fast(uint32_t state_address, int32_t flush) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint8_t* window = sfera_zlib_pointer<uint8_t>(state->prefix.window);
    uint16_t* previous = sfera_zlib_pointer<uint16_t>(state->prefix.prev);
    uint16_t* heads = sfera_zlib_pointer<uint16_t>(state->prefix.head);
    for (;;) {
        if (state->prefix.lookahead < 262u) {
            sfera_zlib_deflate_fill_window(state_address);
            if (state->prefix.lookahead < 262u && flush == 0) { return 0u; }
            if (state->prefix.lookahead == 0u) { break; }
        }
        uint32_t hash_head = 0u;
        if (state->prefix.lookahead >= 3u) { hash_head = sfera_zlib_insert_string(state, window, previous, heads); }
        if (hash_head != 0u && state->prefix.strstart - hash_head <= state->prefix.w_size - 262u && state->prefix.strategy != 2) { state->prefix.match_length = sfera_zlib_deflate_longest_match(state_address, hash_head); }
        bool flush_block = false;
        if (state->prefix.match_length >= 3u) {
            flush_block = sfera_zlib_tally(state_address, state->prefix.strstart - state->prefix.match_start, state->prefix.match_length - 3u);
            state->prefix.lookahead -= state->prefix.match_length;
            if (state->prefix.match_length <= state->prefix.max_lazy_match && state->prefix.lookahead >= 3u) {
                --state->prefix.match_length;
                do { ++state->prefix.strstart; hash_head = sfera_zlib_insert_string(state, window, previous, heads); } while (--state->prefix.match_length != 0u);
                ++state->prefix.strstart;
            }
            else {
                state->prefix.strstart += state->prefix.match_length;
                state->prefix.match_length = 0u;
                state->prefix.ins_h = window[state->prefix.strstart];
                state->prefix.ins_h = ((state->prefix.ins_h << state->prefix.hash_shift) ^ window[state->prefix.strstart + 1u]) & state->prefix.hash_mask;
            }
        }
        else {
            flush_block = sfera_zlib_tally(state_address, 0u, window[state->prefix.strstart]);
            --state->prefix.lookahead;
            ++state->prefix.strstart;
        }
        if (flush_block) { const int32_t result = sfera_zlib_flush_current_block(state_address, false); if (result >= 0) { return static_cast<uint32_t>(result); } }
    }
    const bool finishing = flush == 4;
    const int32_t result = sfera_zlib_flush_current_block(state_address, finishing);
    return result >= 0 ? static_cast<uint32_t>(result) : (finishing ? 3u : 1u);
}

uint32_t sfera_zlib_deflate_slow(uint32_t state_address, int32_t flush) {
    SferaDeflateState32* state = sfera_zlib_pointer<SferaDeflateState32>(state_address);
    uint8_t* window = sfera_zlib_pointer<uint8_t>(state->prefix.window);
    uint16_t* previous = sfera_zlib_pointer<uint16_t>(state->prefix.prev);
    uint16_t* heads = sfera_zlib_pointer<uint16_t>(state->prefix.head);
    for (;;) {
        if (state->prefix.lookahead < 262u) {
            sfera_zlib_deflate_fill_window(state_address);
            if (state->prefix.lookahead < 262u && flush == 0) { return 0u; }
            if (state->prefix.lookahead == 0u) { break; }
        }
        uint32_t hash_head = 0u;
        if (state->prefix.lookahead >= 3u) { hash_head = sfera_zlib_insert_string(state, window, previous, heads); }
        state->prefix.prev_length = state->prefix.match_length;
        state->prefix.prev_match = state->prefix.match_start;
        state->prefix.match_length = 2u;
        if (hash_head != 0u && state->prefix.prev_length < state->prefix.max_lazy_match && state->prefix.strstart - hash_head <= state->prefix.w_size - 262u && state->prefix.strategy != 2) {
            state->prefix.match_length = sfera_zlib_deflate_longest_match(state_address, hash_head);
            if (state->prefix.match_length <= 5u && (state->prefix.strategy == 1 || (state->prefix.match_length == 3u && state->prefix.strstart - state->prefix.match_start > 4096u))) { state->prefix.match_length = 2u; }
        }
        if (state->prefix.prev_length >= 3u && state->prefix.match_length <= state->prefix.prev_length) {
            const uint32_t max_insert = state->prefix.strstart + state->prefix.lookahead - 3u;
            const bool flush_block = sfera_zlib_tally(state_address, state->prefix.strstart - 1u - state->prefix.prev_match, state->prefix.prev_length - 3u);
            state->prefix.lookahead -= state->prefix.prev_length - 1u;
            state->prefix.prev_length -= 2u;
            do { if (++state->prefix.strstart <= max_insert) { hash_head = sfera_zlib_insert_string(state, window, previous, heads); } } while (--state->prefix.prev_length != 0u);
            state->prefix.match_available = 0;
            state->prefix.match_length = 2u;
            ++state->prefix.strstart;
            if (flush_block) { const int32_t result = sfera_zlib_flush_current_block(state_address, false); if (result >= 0) { return static_cast<uint32_t>(result); } }
        }
        else if (state->prefix.match_available != 0) {
            const bool flush_block = sfera_zlib_tally(state_address, 0u, window[state->prefix.strstart - 1u]);
            if (flush_block) { sfera_zlib_flush_current_block(state_address, false); }
            ++state->prefix.strstart;
            --state->prefix.lookahead;
            SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(state->prefix.strm);
            if (stream->avail_out == 0u) { return 0u; }
        }
        else { state->prefix.match_available = 1; ++state->prefix.strstart; --state->prefix.lookahead; }
    }
    if (state->prefix.match_available != 0) { sfera_zlib_tally(state_address, 0u, window[state->prefix.strstart - 1u]); state->prefix.match_available = 0; }
    const bool finishing = flush == 4;
    const int32_t result = sfera_zlib_flush_current_block(state_address, finishing);
    return result >= 0 ? static_cast<uint32_t>(result) : (finishing ? 3u : 1u);
}
uint32_t sfera_zlib_inflate_fixed(uint32_t literal_bits_address, uint32_t distance_bits_address, uint32_t literal_root_address, uint32_t distance_root_address) {
    uint32_t literal_lengths[288];
    uint32_t literal_work[288];
    uint32_t distance_lengths[30];
    uint32_t distance_work[30];
    for (uint32_t symbol = 0u; symbol < 288u; ++symbol) { literal_lengths[symbol] = symbol < 144u ? 8u : symbol < 256u ? 9u : symbol < 280u ? 7u : 8u; }
    for (uint32_t symbol = 0u; symbol < 30u; ++symbol) { distance_lengths[symbol] = 5u; }
    uint32_t literal_bits = 9u;
    uint32_t distance_bits = 5u;
    uint32_t literal_root = 0u;
    uint32_t distance_root = 0u;
    uint32_t used = 0u;
    uint32_t status = sfera_zlib_huft_build(sfera_zlib_address(literal_lengths), 288u, 257u, 0u, 0u, sfera_zlib_address(&literal_root), sfera_zlib_address(&literal_bits), sfera_zlib_address(g_sfera_zlib_fixed_literal_pool), sfera_zlib_address(&used), sfera_zlib_address(literal_work));
    if (status != 0u) { return status; }
    used = 0u;
    status = sfera_zlib_huft_build(sfera_zlib_address(distance_lengths), 30u, 0u, 0u, 0u, sfera_zlib_address(&distance_root), sfera_zlib_address(&distance_bits), sfera_zlib_address(g_sfera_zlib_fixed_distance_pool), sfera_zlib_address(&used), sfera_zlib_address(distance_work));
    const bool canonical_incomplete_distance_tree = status == static_cast<uint32_t>(-5);
    if (status != 0u && !canonical_incomplete_distance_tree) { return status; }
    *sfera_zlib_pointer<uint32_t>(literal_bits_address) = literal_bits;
    *sfera_zlib_pointer<uint32_t>(distance_bits_address) = distance_bits;
    *sfera_zlib_pointer<uint32_t>(literal_root_address) = literal_root;
    *sfera_zlib_pointer<uint32_t>(distance_root_address) = distance_root;
    return 0u;
}

uint32_t sfera_zlib_huft_build(uint32_t lengths_address, uint32_t code_count, uint32_t simple_count, uint32_t base_values_address, uint32_t extra_bits_address, uint32_t root_address, uint32_t root_bits_address, uint32_t pool_address, uint32_t used_address, uint32_t work_address) {
    uint32_t* lengths = sfera_zlib_pointer<uint32_t>(lengths_address);
    uint32_t* root = sfera_zlib_pointer<uint32_t>(root_address);
    uint32_t* root_bits = sfera_zlib_pointer<uint32_t>(root_bits_address);
    SferaInflateHuft32* pool = sfera_zlib_pointer<SferaInflateHuft32>(pool_address);
    uint32_t* used = sfera_zlib_pointer<uint32_t>(used_address);
    uint32_t* values = sfera_zlib_pointer<uint32_t>(work_address);
    uint32_t counts[16] = {};
    for (uint32_t index = 0u; index != code_count; ++index) {
        if (lengths[index] > 15u) { return static_cast<uint32_t>(-3); }
        ++counts[lengths[index]];
    }
    if (counts[0] == code_count) { *root = 0u; *root_bits = 0u; return 0u; }
    uint32_t minimum_bits = 1u;
    while (minimum_bits <= 15u && counts[minimum_bits] == 0u) { ++minimum_bits; }
    uint32_t maximum_bits = 15u;
    while (maximum_bits != 0u && counts[maximum_bits] == 0u) { --maximum_bits; }
    uint32_t table_bits = *root_bits;
    if (table_bits < minimum_bits) { table_bits = minimum_bits; }
    if (table_bits > maximum_bits) { table_bits = maximum_bits; }
    *root_bits = table_bits;
    int32_t unused_patterns = 1 << minimum_bits;
    for (uint32_t bits = minimum_bits; bits < maximum_bits; ++bits) {
        unused_patterns -= static_cast<int32_t>(counts[bits]);
        if (unused_patterns < 0) { return static_cast<uint32_t>(-3); }
        unused_patterns <<= 1;
    }
    unused_patterns -= static_cast<int32_t>(counts[maximum_bits]);
    if (unused_patterns < 0) { return static_cast<uint32_t>(-3); }
    counts[maximum_bits] += static_cast<uint32_t>(unused_patterns);
    uint32_t offsets[16] = {};
    offsets[1] = 0u;
    uint32_t cumulative = 0u;
    for (uint32_t bits = 1u; bits < maximum_bits; ++bits) { cumulative += counts[bits]; offsets[bits + 1u] = cumulative; }
    uint32_t positions[16];
    std::memcpy(positions, offsets, sizeof(positions));
    for (uint32_t symbol = 0u; symbol != code_count; ++symbol) { const uint32_t bits = lengths[symbol]; if (bits != 0u) { values[positions[bits]++] = symbol; } }
    const uint32_t real_value_count = positions[maximum_bits];
    uint32_t code = 0u;
    uint32_t value_index = 0u;
    SferaInflateHuft32 entry = {};
    int32_t level = -1;
    int32_t bits_before_table = -static_cast<int32_t>(table_bits);
    SferaInflateHuft32* table_stack[15] = {};
    SferaInflateHuft32* current_table = nullptr;
    uint32_t current_entries = 0u;
    offsets[0] = 0u;
    for (uint32_t code_bits = minimum_bits; code_bits <= maximum_bits; ++code_bits) {
        uint32_t remaining = counts[code_bits];
        while (remaining-- != 0u) {
            while (static_cast<int32_t>(code_bits) > bits_before_table + static_cast<int32_t>(table_bits)) {
                ++level;
                bits_before_table += static_cast<int32_t>(table_bits);
                uint32_t candidate_bits = maximum_bits - static_cast<uint32_t>(bits_before_table);
                if (candidate_bits > table_bits) { candidate_bits = table_bits; }
                uint32_t selected_bits = code_bits - static_cast<uint32_t>(bits_before_table);
                uint32_t patterns = 1u << selected_bits;
                if (patterns > remaining + 1u) {
                    patterns -= remaining + 1u;
                    uint32_t probe_bits = code_bits;
                    while (selected_bits < candidate_bits) {
                        ++selected_bits;
                        ++probe_bits;
                        patterns <<= 1u;
                        if (patterns <= counts[probe_bits]) { break; }
                        patterns -= counts[probe_bits];
                    }
                }
                current_entries = 1u << selected_bits;
                if (*used + current_entries > 1440u) { return static_cast<uint32_t>(-4); }
                current_table = pool + *used;
                *used += current_entries;
                table_stack[level] = current_table;
                if (level == 0) { *root = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(current_table)); }
                else {
                    offsets[level] = code;
                    entry.bits = static_cast<uint8_t>(table_bits);
                    entry.operation = static_cast<uint8_t>(selected_bits);
                    const uint32_t parent_index = code >> static_cast<uint32_t>(bits_before_table - static_cast<int32_t>(table_bits));
                    entry.base = static_cast<uint32_t>(current_table - table_stack[level - 1]) - parent_index;
                    table_stack[level - 1][parent_index] = entry;
                }
            }
            entry.bits = static_cast<uint8_t>(code_bits - static_cast<uint32_t>(bits_before_table));
            if (value_index >= real_value_count) { entry.operation = 192u; }
            else {
                const uint32_t symbol = values[value_index++];
                if (symbol < simple_count) { entry.operation = static_cast<uint8_t>(symbol < 256u ? 0u : 96u); entry.base = symbol; }
                else {
                    const uint32_t index = symbol - simple_count;
                    if (base_values_address != 0u && extra_bits_address != 0u) {
                        const uint32_t* base_values = sfera_zlib_pointer<uint32_t>(base_values_address);
                        const uint32_t* extra_bits = sfera_zlib_pointer<uint32_t>(extra_bits_address);
                        entry.operation = static_cast<uint8_t>(extra_bits[index] + 80u);
                        entry.base = base_values[index];
                    } else if (simple_count == 257u && index < 31u) {
                        const uint32_t extra = index < 8u ? 0u : (index < 28u ? (index - 4u) >> 2u : (index == 28u ? 0u : 112u));
                        entry.operation = static_cast<uint8_t>(extra + 80u);
                        if (index < 8u) { entry.base = index + 3u; } else if (index < 28u) { const uint32_t group_begin = 4u * extra + 4u; entry.base = (1u << (extra + 2u)) + ((index - group_begin) << extra) + 3u; } else { entry.base = index == 28u ? 258u : 0u; }
                    } else if (simple_count == 0u && code_count <= 30u && index < 30u) {
                        const uint32_t extra = index >= 4u ? (index >> 1u) - 1u : 0u;
                        entry.operation = static_cast<uint8_t>(extra + 80u);
                        entry.base = (index < 4u ? index : (1u << (extra + 1u)) + ((index & 1u) << extra)) + 1u;
                    } else {
                        return static_cast<uint32_t>(-3);
                    }
                }
            }
            const uint32_t stride = 1u << (code_bits - static_cast<uint32_t>(bits_before_table));
            for (uint32_t index = code >> static_cast<uint32_t>(bits_before_table); index < current_entries; index += stride) { current_table[index] = entry; }
            uint32_t bit = 1u << (code_bits - 1u);
            while ((code & bit) != 0u) { code ^= bit; bit >>= 1u; }
            code ^= bit;
            uint32_t mask = bits_before_table == 0 ? 0u : (1u << static_cast<uint32_t>(bits_before_table)) - 1u;
            while (level > 0 && (code & mask) != offsets[level]) { --level; bits_before_table -= static_cast<int32_t>(table_bits); mask = bits_before_table == 0 ? 0u : (1u << static_cast<uint32_t>(bits_before_table)) - 1u; }
        }
    }
    return unused_patterns != 0 && maximum_bits != 1u ? static_cast<uint32_t>(-5) : 0u;
}

uint32_t sfera_zlib_adler32(uint32_t adler, uint32_t buffer_address, uint32_t length) {
    if (buffer_address == 0u) { return 1u; }
    uint32_t low = adler & 0xFFFFu;
    uint32_t high = (adler >> 16u) & 0xFFFFu;
    uint32_t offset = 0u;
    while (offset != length) {
        uint32_t chunk = length - offset;
        if (chunk > 5552u) { chunk = 5552u; }
        uint8_t* input = sfera_zlib_bytes(buffer_address + offset);
        for (uint32_t index = 0u; index != chunk; ++index) { low += input[index]; high += low; }
        low %= 65521u;
        high %= 65521u;
        offset += chunk;
    }
    return (high << 16u) | low;
}

void sfera_zlib_deflate_put_short_msb(uint32_t state_address, uint32_t value) {
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* pending = sfera_zlib_bytes(state->pending_buf);
    pending[state->pending++] = static_cast<uint8_t>(value >> 8u);
    pending[state->pending++] = static_cast<uint8_t>(value);
}

void sfera_zlib_deflate_flush_pending(uint32_t stream_address) {
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(stream_address);
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(stream->state);
    uint32_t length = static_cast<uint32_t>(state->pending);
    if (length > stream->avail_out) { length = stream->avail_out; }
    if (length == 0u) { return; }
    std::memcpy(sfera_zlib_bytes(stream->next_out), sfera_zlib_bytes(state->pending_out), length);
    stream->next_out += length;
    state->pending_out += length;
    stream->total_out += length;
    stream->avail_out -= length;
    state->pending -= static_cast<int32_t>(length);
    if (state->pending == 0) { state->pending_out = state->pending_buf; }
}

void sfera_zlib_deflate_lm_init(uint32_t state_address) {
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    state->window_size = state->w_size * 2u;
    uint16_t* heads = sfera_zlib_pointer<uint16_t>(state->head);
    std::memset(heads, 0, state->hash_size * sizeof(uint16_t));
    const SferaDeflateConfig config = sfera_zlib_deflate_config(state->level);
    state->max_lazy_match = config.max_lazy;
    state->good_match = config.good_length;
    state->nice_match = config.nice_length;
    state->max_chain_length = config.max_chain;
    state->strstart = 0u;
    state->block_start = 0;
    state->lookahead = 0u;
    state->match_length = 2u;
    state->prev_length = 2u;
    state->match_available = 0;
    state->ins_h = 0u;
}

uint32_t sfera_zlib_deflate_read_buf(uint32_t stream_address, uint32_t destination_address, uint32_t size) {
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(stream_address);
    uint32_t length = stream->avail_in;
    if (length > size) { length = size; }
    if (length == 0u) { return 0u; }
    stream->avail_in -= length;
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(stream->state);
    if (state->noheader == 0) { stream->adler = sfera_zlib_adler32(stream->adler, stream->next_in, length); }
    std::memcpy(sfera_zlib_bytes(destination_address), sfera_zlib_bytes(stream->next_in), length);
    stream->next_in += length;
    stream->total_in += length;
    return length;
}

uint32_t sfera_zlib_deflate_longest_match(uint32_t state_address, uint32_t current_match) {
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    uint8_t* window = sfera_zlib_pointer<uint8_t>(state->window);
    uint16_t* previous = sfera_zlib_pointer<uint16_t>(state->prev);
    uint32_t chain_left = state->max_chain_length;
    uint32_t best_length = state->prev_length;
    uint32_t nice_length = state->nice_match > 0 ? static_cast<uint32_t>(state->nice_match) : 0u;
    if (nice_length > state->lookahead) { nice_length = state->lookahead; }
    if (state->prev_length >= state->good_match) { chain_left >>= 2u; }
    const uint32_t max_distance = state->w_size - 262u;
    const uint32_t limit = state->strstart > max_distance ? state->strstart - max_distance : 0u;
    const uint32_t compare_limit = state->lookahead < 258u ? state->lookahead : 258u;
    if (best_length >= compare_limit || chain_left == 0u) { return best_length < state->lookahead ? best_length : state->lookahead; }
    while (true) {
        if (current_match >= state->strstart) { break; }
        if (window[current_match] == window[state->strstart] && window[current_match + 1u] == window[state->strstart + 1u] && window[current_match + best_length] == window[state->strstart + best_length]) {
            uint32_t length = 2u;
            while (length < compare_limit && window[current_match + length] == window[state->strstart + length]) { ++length; }
            if (length > best_length) {
                state->match_start = current_match;
                best_length = length;
                if (best_length >= nice_length) { break; }
            }
        }
        const uint32_t next_match = previous[current_match & state->w_mask];
        if (next_match <= limit) { break; }
        if (--chain_left == 0u) { break; }
        current_match = next_match;
    }
    return best_length < state->lookahead ? best_length : state->lookahead;
}

void sfera_zlib_deflate_fill_window(uint32_t state_address) {
    SferaDeflateStatePrefix32* state = sfera_zlib_pointer<SferaDeflateStatePrefix32>(state_address);
    SferaZStream32* stream = sfera_zlib_pointer<SferaZStream32>(state->strm);
    uint8_t* window = sfera_zlib_pointer<uint8_t>(state->window);
    uint16_t* heads = sfera_zlib_pointer<uint16_t>(state->head);
    uint16_t* previous = sfera_zlib_pointer<uint16_t>(state->prev);
    const uint32_t window_size = state->w_size;
    while (true) {
        uint32_t more = state->window_size - state->lookahead - state->strstart;
        if (more == 0u && state->strstart == 0u && state->lookahead == 0u) { more = window_size; }
        else if (more == UINT32_MAX) { --more; }
        else if (state->strstart >= window_size + (window_size - 262u)) {
            std::memcpy(window, window + window_size, window_size);
            state->match_start -= window_size;
            state->strstart -= window_size;
            state->block_start -= static_cast<int32_t>(window_size);
            for (uint32_t index = 0u; index != state->hash_size; ++index) { const uint32_t value = heads[index]; heads[index] = static_cast<uint16_t>(value >= window_size ? value - window_size : 0u); }
            for (uint32_t index = 0u; index != window_size; ++index) { const uint32_t value = previous[index]; previous[index] = static_cast<uint16_t>(value >= window_size ? value - window_size : 0u); }
            more += window_size;
        }
        if (stream->avail_in == 0u) { return; }
        const uint32_t destination = state->window + state->strstart + state->lookahead;
        state->lookahead += sfera_zlib_deflate_read_buf(state->strm, destination, more);
        if (state->lookahead >= 3u) {
            state->ins_h = window[state->strstart];
            state->ins_h = ((state->ins_h << state->hash_shift) ^ window[state->strstart + 1u]) & state->hash_mask;
        }
        if (state->lookahead >= 262u || stream->avail_in == 0u) { return; }
    }
}
