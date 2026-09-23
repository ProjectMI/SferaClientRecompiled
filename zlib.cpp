#include "zlib.h"

#include <algorithm>
#include <climits>
#include <cstring>
#include <limits>
#include <new>
#include <stdexcept>

namespace {
    constexpr std::array<std::uint8_t, 19> codeLengthOrder{16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};

    struct UiDeflateBits {
        std::span<const std::uint8_t> input;
        std::size_t position = 0u;
        unsigned offset = 0u;
        std::uint32_t read(unsigned count) {
            std::uint32_t result = 0u;
            for (unsigned bit = 0u; bit < count; ++bit) {
                if (position == input.size()) throw std::runtime_error("Truncated UI configuration stream");
                result |= ((input[position] >> offset) & 1u) << bit;
                if (++offset == 8u) {
                    offset = 0u;
                    ++position;
                }
            }
            return result;
        }

        void align() {
            if (offset != 0u) {
                offset = 0u;
                ++position;
            }
        }
    };

    struct UiDeflateAlphabet {
        std::array<std::uint16_t, 16> counts{};
        std::array<std::uint16_t, 288> symbols{};
        explicit UiDeflateAlphabet(std::span<const std::uint8_t> lengths, bool require_complete = false) {
            for (const auto length : lengths) {
                if (length > 15u) throw std::runtime_error("Invalid UI Huffman length");
                ++counts[length];
            }
            int available = 1;
            for (unsigned length = 1u; length < 16u; ++length) {
                available = available * 2 - counts[length];
                if (available < 0) throw std::runtime_error("Oversubscribed UI Huffman alphabet");
            }
            if (available != 0 && (require_complete || *std::max_element(lengths.begin(), lengths.end()) > 1u)) throw std::runtime_error("Incomplete UI Huffman alphabet");
            std::array<std::uint16_t, 16> offsets{};
            for (unsigned length = 1u; length < 15u; ++length) offsets[length + 1u] = offsets[length] + counts[length];
            for (std::uint16_t symbol = 0u; symbol < lengths.size(); ++symbol) if (lengths[symbol] != 0u) symbols[offsets[lengths[symbol]]++] = symbol;
        }

        std::uint32_t decode(UiDeflateBits& bits) const {
            unsigned code = 0u, first = 0u, index = 0u;
            for (unsigned length = 1u; length < 16u; ++length) {
                code = (code << 1u) | bits.read(1u);
                if (code >= first && code - first < counts[length]) return symbols[index + code - first];
                index += counts[length];
                first = (first + counts[length]) << 1u;
            }
            throw std::runtime_error("Invalid UI Huffman code");
        }
    };
}

std::vector<std::uint8_t> SferaZStream32::decompressUiConfig(std::span<const std::uint8_t> input, std::size_t limit) {
    if (input.size() < 6u || (input[0] & 15u) != 8u || (input[0] >> 4u) > 7u || ((input[0] * 256u + input[1]) % 31u) != 0u || (input[1] & 32u) != 0u) throw std::runtime_error("Invalid UI configuration zlib header");
    UiDeflateBits bits{input.subspan(2u)};
    std::vector<std::uint8_t> output;
    bool last = false;
    const auto append = [&](std::uint8_t value) {
        if (output.size() == limit) throw std::length_error("UI configuration too large");
        output.push_back(value);
    };
    do {
        last = bits.read(1u) != 0u;
        const auto kind = bits.read(2u);
        if (kind == 0u) {
            bits.align();
            const auto length = bits.read(16u), complement = bits.read(16u);
            if ((length ^ complement) != 65535u) throw std::runtime_error("Invalid UI stored block length");
            for (unsigned index = 0u; index < length; ++index) append(bits.read(8u));
            continue;
        }
        if (kind == 3u) throw std::runtime_error("Invalid UI deflate block");
        std::array<std::uint8_t, 288> literal_lengths{};
        std::array<std::uint8_t, 32> distance_lengths{};
        if (kind == 1u) {
            for (unsigned index = 0u; index < literal_lengths.size(); ++index) literal_lengths[index] = SferaDeflateState32::fixedLiteralLength(index);
            distance_lengths.fill(5u);
        } else {
            const auto literals = bits.read(5u) + 257u, distances = bits.read(5u) + 1u, codes = bits.read(4u) + 4u;
            if (literals > 286u) throw std::runtime_error("Invalid UI literal alphabet");
            std::array<std::uint8_t, 19> code_lengths{};
            for (unsigned index = 0u; index < codes; ++index) code_lengths[codeLengthOrder[index]] = bits.read(3u);
            UiDeflateAlphabet alphabet{code_lengths, true};
            std::vector<std::uint8_t> lengths;
            lengths.reserve(literals + distances);
            while (lengths.size() < literals + distances) {
                const auto code = alphabet.decode(bits);
                if (code < 16u) lengths.push_back(code);
                else {
                    if (code == 16u && lengths.empty()) throw std::runtime_error("UI Huffman repeat without predecessor");
                    const auto count = code == 16u ? bits.read(2u) + 3u : code == 17u ? bits.read(3u) + 3u : bits.read(7u) + 11u;
                    if (count > literals + distances - lengths.size()) throw std::runtime_error("UI Huffman repeat overflow");
                    lengths.insert(lengths.end(), count, code == 16u ? lengths.back() : 0u);
                }
            }
            std::copy_n(lengths.begin(), literals, literal_lengths.begin());
            std::copy_n(lengths.begin() + literals, distances, distance_lengths.begin());
        }
        if (literal_lengths[256] == 0u) throw std::runtime_error("UI deflate block has no terminator");
        UiDeflateAlphabet literals{literal_lengths}, distances{distance_lengths};
        constexpr unsigned length_base[] = {3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 13u, 15u, 17u, 19u, 23u, 27u, 31u, 35u, 43u, 51u, 59u, 67u, 83u, 99u, 115u, 131u, 163u, 195u, 227u, 258u};
        constexpr unsigned distance_base[] = {1u, 2u, 3u, 4u, 5u, 7u, 9u, 13u, 17u, 25u, 33u, 49u, 65u, 97u, 129u, 193u, 257u, 385u, 513u, 769u, 1025u, 1537u, 2049u, 3073u, 4097u, 6145u, 8193u, 12289u, 16385u, 24577u};
        for (;;) {
            const auto symbol = literals.decode(bits);
            if (symbol == 256u) break;
            if (symbol < 256u) {
                append(symbol);
                continue;
            }
            if (symbol > 285u) throw std::runtime_error("Invalid UI length symbol");
            const auto slot = symbol - 257u, length = length_base[slot] + bits.read(slot < 8u || slot == 28u ? 0u : (slot - 4u) / 4u);
            const auto distance_symbol = distances.decode(bits);
            if (distance_symbol >= 30u) throw std::runtime_error("Invalid UI distance symbol");
            const auto distance = distance_base[distance_symbol] + bits.read(distance_symbol < 4u ? 0u : distance_symbol / 2u - 1u);
            if (distance > output.size()) throw std::runtime_error("UI deflate distance before buffer");
            for (unsigned index = 0u; index < length; ++index) append(output[output.size() - distance]);
        }
    } while (!last);
    bits.align();
    std::uint32_t checksum = 0u;
    for (unsigned index = 0u; index < 4u; ++index) checksum = (checksum << 8u) | bits.read(8u);
    std::uint32_t first = 1u, second = 0u;
    for (const auto value : output) {
        first = (first + value) % 65521u;
        second = (second + first) % 65521u;
    }
    if (checksum != ((second << 16u) | first)) throw std::runtime_error("UI configuration checksum mismatch");
    return output;
}

SferaDeflateConfig SferaDeflateState32::deflateConfig(int32_t level) {
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

uint16_t SferaDeflateState32::reverseBits(uint32_t value, uint32_t bit_count) {
    uint32_t result = 0u;
    for (uint32_t bit = 0u; bit != bit_count; ++bit) { result = (result << 1u) | ((value >> bit) & 1u); }
    return result & 65535u;
}

uint8_t SferaDeflateState32::fixedLiteralLength(uint32_t symbol) {
    if (symbol <= 143u) { return 8u; }
    if (symbol <= 255u) { return 9u; }
    if (symbol <= 279u) { return 7u; }
    return symbol <= 287u ? 8u : 0u;
}

uint16_t SferaDeflateState32::fixedLiteralCode(uint32_t symbol) {
    if (symbol <= 143u) { return reverseBits(symbol + fixed_literal_start, 8u); }
    if (symbol <= 255u) { return reverseBits(symbol - 144u + fixed_high_start, 9u); }
    if (symbol <= 279u) { return reverseBits(symbol - 256u, 7u); }
    if (symbol <= 287u) { return reverseBits(symbol - 280u + fixed_tail_start, 8u); }
    return 0u;
}

uint16_t SferaDeflateState32::fixedDistanceCode(uint32_t symbol) {
    return symbol < 30u ? reverseBits(symbol, 5u) : 0u;
}

SferaCtData32 SferaDeflateState32::treeEntry(SferaCtData32* tree, uint32_t symbol, bool distance_tree) {
    if (tree != nullptr) { return tree[symbol]; }
    SferaCtData32 entry = {};
    entry.code = distance_tree ? fixedDistanceCode(symbol) : fixedLiteralCode(symbol);
    entry.length = distance_tree ? 5u : fixedLiteralLength(symbol);
    return entry;
}

void SferaDeflateState32::putShortLe(uint16_t value) {
    uint8_t* pending_bytes = this->pending_buf.data();
    pending_bytes[this->pending++] = value & 255u;
    pending_bytes[this->pending++] = (value >> 8u) & 255u;
}

void SferaDeflateState32::sendBits(uint32_t value, uint32_t length) {
    if (length == 0u) return;
    bit_buffer |= (value << valid_bits) & 65535u;
    if (valid_bits > 16u - length) {
        putShortLe(bit_buffer);
        bit_buffer = (value >> (16u - valid_bits)) & 65535u;
        valid_bits += length - 16u;
    } else {
        valid_bits += length;
    }
}

void SferaDeflateState32::sendTreeCode(SferaCtData32* tree, uint32_t symbol, bool distance_tree) {
    const SferaCtData32 entry = treeEntry(tree, symbol, distance_tree);
    sendBits(entry.code, entry.length);
}

void SferaDeflateState32::bitFlush() {
    if (valid_bits == 16u) {
        putShortLe(bit_buffer);
        bit_buffer = 0u;
        valid_bits = 0u;
    } else if (valid_bits >= 8u) {
        pending_buf[pending++] = bit_buffer & 255u;
        bit_buffer >>= 8u;
        valid_bits -= 8u;
    }
}

void SferaDeflateState32::bitWindup() {
    if (valid_bits > 8u) putShortLe(bit_buffer);
    else if (valid_bits != 0u) pending_buf[pending++] = bit_buffer & 255u;
    bit_buffer = 0u;
    valid_bits = 0u;
}

void SferaDeflateState32::copyStoredBlock(const uint8_t* buffer, uint32_t length, uint32_t write_header) {
    bitWindup();
    last_eob_length = 8u;
    if (write_header != 0u) {
        const uint16_t block_length = length & 65535u;
        putShortLe(block_length);
        putShortLe(65535u - block_length);
    }
    if (length != 0u) {
        std::memcpy(pending_buf.data() + pending, buffer, length);
        pending += length;
    }
}

void SferaDeflateState32::writeStoredBlock(const uint8_t* buffer, uint32_t length, uint32_t end_of_file) {
    sendBits(end_of_file & 1u, 3u);
    copyStoredBlock(buffer, length, 1u);
}

void SferaDeflateState32::alignStaticBlock() {
    sendBits(2u, 3u);
    sendTreeCode(nullptr, 256u, false);
    bitFlush();
    if (1 + this->last_eob_length + 10 - this->valid_bits < 9) {
        sendBits(2u, 3u);
        sendTreeCode(nullptr, 256u, false);
        bitFlush();
    }
    this->last_eob_length = 7;
}

void SferaDeflateState32::setDataType() {
    uint32_t binary_frequency = 0u;
    uint32_t ascii_frequency = 0u;
    uint32_t symbol = 0u;
    while (symbol < 7u) { binary_frequency += this->dynamic_literal_tree[symbol++].code; }
    while (symbol < 128u) { ascii_frequency += this->dynamic_literal_tree[symbol++].code; }
    while (symbol < 256u) { binary_frequency += this->dynamic_literal_tree[symbol++].code; }
    this->data_type = binary_frequency > (ascii_frequency >> 2u) ? 0u : 1u;
}

uint32_t SferaDeflateState32::treeElementCount(SferaZlibTreeKind kind) {
    switch (kind) { case SferaZlibTreeKind::Literal: return 286u; case SferaZlibTreeKind::Distance: return 30u; case SferaZlibTreeKind::BitLength: return 19u; default: return 0u; }
}

uint32_t SferaDeflateState32::treeMaxLength(SferaZlibTreeKind kind) { return kind == SferaZlibTreeKind::BitLength ? 7u : 15u; }

uint32_t SferaDeflateState32::treeExtraBits(SferaZlibTreeKind kind, uint32_t symbol) {
    if (kind == SferaZlibTreeKind::Literal && symbol >= 257u) { const uint32_t code = symbol - 257u; return code >= 8u && code < 28u ? (code - 4u) >> 2u : 0u; }
    if (kind == SferaZlibTreeKind::Distance) { return symbol >= 4u && symbol < 30u ? (symbol >> 1u) - 1u : 0u; }
    if (kind == SferaZlibTreeKind::BitLength) { if (symbol == 16u) { return 2u; } if (symbol == 17u) { return 3u; } if (symbol == 18u) { return 7u; } }
    return 0u;
}

uint32_t SferaDeflateState32::staticSymbolLength(SferaZlibTreeKind kind, uint32_t symbol) {
    if (kind == SferaZlibTreeKind::Literal) { return fixedLiteralLength(symbol); }
    if (kind == SferaZlibTreeKind::Distance) { return 5u; }
    return 0u;
}

bool SferaDeflateState32::heapLess(const SferaCtData32* tree, uint32_t left, uint32_t right) {
    return tree[left].code < tree[right].code || (tree[left].code == tree[right].code && this->depth[left] <= this->depth[right]);
}

void SferaDeflateState32::pqDownHeap(SferaCtData32* tree, uint32_t heap_index) {
    const uint32_t value = this->heap[heap_index];
    uint32_t child = heap_index << 1u;
    while (child <= this->heap_length) {
        if (child < this->heap_length && heapLess(tree, this->heap[child + 1u], this->heap[child])) { ++child; }
        if (heapLess(tree, value, this->heap[child])) { break; }
        this->heap[heap_index] = this->heap[child];
        heap_index = child;
        child <<= 1u;
    }
    this->heap[heap_index] = value;
}

void SferaDeflateState32::generateCodes(SferaCtData32* tree, uint32_t symbol_count, const uint16_t* bit_counts) {
    uint16_t next_code[16] = {};
    uint32_t code = 0u;
    for (uint32_t bits = 1u; bits <= 15u; ++bits) { code = (code + bit_counts[bits - 1u]) << 1u; next_code[bits] = code & 65535u; }
    for (uint32_t symbol = 0; symbol < symbol_count; ++symbol) { const uint32_t length = tree[symbol].length; if (length != 0u) { tree[symbol].code = reverseBits(next_code[length]++, length); } }
}

void SferaDeflateState32::generateBitLengths(SferaTreeDesc32* descriptor) {
    SferaCtData32* tree = descriptor->dynamic_tree;
    const SferaZlibTreeKind kind = descriptor->kind;
    const uint32_t max_length = treeMaxLength(kind);
    for (uint32_t bits = 0u; bits <= 15u; ++bits) { this->bit_length_counts[bits] = 0u; }
    tree[this->heap[this->heap_max]].length = 0u;
    int32_t overflow = 0;
    for (uint32_t heap_index = this->heap_max + 1u; heap_index < 573u; ++heap_index) {
        const uint32_t symbol = this->heap[heap_index];
        uint32_t bits = tree[tree[symbol].length].length + 1u;
        if (bits > max_length) { bits = max_length; ++overflow; }
        tree[symbol].length = bits;
        if (symbol >= descriptor->symbol_count) { continue; }
        ++this->bit_length_counts[bits];
        const uint32_t extra = treeExtraBits(kind, symbol);
        const uint32_t frequency = tree[symbol].code;
        this->optimal_length += frequency * (bits + extra);
        const uint32_t fixed_length = staticSymbolLength(kind, symbol);
        if (fixed_length != 0u) { this->static_length += frequency * (fixed_length + extra); }
    }
    while (overflow > 0) {
        uint32_t bits = max_length - 1u;
        while (bits > 0 && this->bit_length_counts[bits] == 0u) { --bits; }
        --this->bit_length_counts[bits];
        this->bit_length_counts[bits + 1] += 2u;
        --this->bit_length_counts[max_length];
        overflow -= 2;
    }
    uint32_t heap_index = 573u;
    for (uint32_t bits = max_length; bits != 0; --bits) {
        uint32_t remaining = this->bit_length_counts[bits];
        while (remaining != 0u) {
            const uint32_t symbol = this->heap[--heap_index];
            if (symbol >= descriptor->symbol_count) { continue; }
            if (tree[symbol].length != bits) { this->optimal_length += (bits - tree[symbol].length) * tree[symbol].code; tree[symbol].length = bits; }
            --remaining;
        }
    }
}

void SferaDeflateState32::initBlock() {
    for (uint32_t symbol = 0u; symbol != 286u; ++symbol) { this->dynamic_literal_tree[symbol].code = 0u; }
    for (uint32_t symbol = 0u; symbol != 30u; ++symbol) { this->dynamic_distance_tree[symbol].code = 0u; }
    for (uint32_t symbol = 0u; symbol != 19u; ++symbol) { this->bit_length_tree[symbol].code = 0u; }
    this->dynamic_literal_tree[256].code = 1u;
    this->optimal_length = 0u;
    this->static_length = 0u;
    this->matches = 0u;
    this->last_literal = 0u;
}

void SferaDeflateState32::treeInit() {
    this->literal_descriptor.dynamic_tree = this->dynamic_literal_tree;
    this->literal_descriptor.symbol_count = 0u;
    this->literal_descriptor.kind = SferaZlibTreeKind::Literal;
    this->distance_descriptor.dynamic_tree = this->dynamic_distance_tree;
    this->distance_descriptor.symbol_count = 0u;
    this->distance_descriptor.kind = SferaZlibTreeKind::Distance;
    this->bit_length_descriptor.dynamic_tree = this->bit_length_tree;
    this->bit_length_descriptor.symbol_count = 0u;
    this->bit_length_descriptor.kind = SferaZlibTreeKind::BitLength;
    this->bit_buffer = 0u;
    this->valid_bits = 0;
    this->last_eob_length = 8;
    initBlock();
}

void SferaDeflateState32::buildTree(SferaTreeDesc32* descriptor) {
    const SferaZlibTreeKind kind = descriptor->kind;
    const uint32_t element_count = treeElementCount(kind);
    SferaCtData32* tree = descriptor->dynamic_tree;
    uint32_t symbol_count = 0u;
    this->heap_length = 0;
    this->heap_max = 573;
    for (uint32_t symbol = 0u; symbol != element_count; ++symbol) {
        if (tree[symbol].code != 0u) { this->heap[++this->heap_length] = symbol; symbol_count = symbol + 1u; this->depth[symbol] = 0u; }
        else { tree[symbol].length = 0u; }
    }
    while (this->heap_length < 2) {
        const uint32_t symbol = symbol_count < 3u ? symbol_count++ : 0u;
        this->heap[++this->heap_length] = symbol;
        tree[symbol].code = 1u;
        this->depth[symbol] = 0u;
        --this->optimal_length;
        const uint32_t fixed_length = staticSymbolLength(kind, symbol);
        if (fixed_length != 0u) { this->static_length -= fixed_length; }
    }
    descriptor->symbol_count = symbol_count;
    for (uint32_t heap_index = this->heap_length / 2; heap_index >= 1; --heap_index) { pqDownHeap(tree, heap_index); }
    uint32_t node = element_count;
    do {
        const uint32_t first = this->heap[1];
        this->heap[1] = this->heap[this->heap_length--];
        pqDownHeap(tree, 1u);
        const uint32_t second = this->heap[1];
        this->heap[--this->heap_max] = first;
        this->heap[--this->heap_max] = second;
        tree[node].code = (tree[first].code + tree[second].code) & 65535u;
        this->depth[node] = (std::max(this->depth[first], this->depth[second]) + 1u) & 255u;
        tree[first].length = node;
        tree[second].length = node;
        this->heap[1] = node++;
        pqDownHeap(tree, 1u);
    } while (this->heap_length >= 2);
    this->heap[--this->heap_max] = this->heap[1];
    generateBitLengths(descriptor);
    generateCodes(tree, symbol_count, this->bit_length_counts);
}

void SferaDeflateState32::scanTree(SferaCtData32* tree, uint32_t symbol_count) {
    
    int32_t previous_length = -1;
    int32_t next_length = tree[0].length;
    uint32_t count = 0u;
    uint32_t maximum_count = next_length == 0 ? 138u : 7u;
    uint32_t minimum_count = next_length == 0 ? 3u : 4u;
    tree[symbol_count].length = std::numeric_limits<uint16_t>::max();
    for (uint32_t symbol = 0; symbol < symbol_count; ++symbol) {
        const int32_t current_length = next_length;
        next_length = tree[symbol + 1].length;
        ++count;
        if (count < maximum_count && current_length == next_length) { continue; }
        if (count < minimum_count) { this->bit_length_tree[current_length].code += count; }
        else if (current_length != 0) { if (current_length != previous_length) { ++this->bit_length_tree[current_length].code; } ++this->bit_length_tree[16].code; }
        else if (count <= 10u) { ++this->bit_length_tree[17].code; }
        else { ++this->bit_length_tree[18].code; }
        count = 0u;
        previous_length = current_length;
        if (next_length == 0) { maximum_count = 138u; minimum_count = 3u; }
        else if (current_length == next_length) { maximum_count = 6u; minimum_count = 3u; }
        else { maximum_count = 7u; minimum_count = 4u; }
    }
}

void SferaDeflateState32::sendTree(SferaCtData32* tree, uint32_t symbol_count) {
    
    SferaCtData32* bit_tree = this->bit_length_tree;
    int32_t previous_length = -1;
    int32_t next_length = tree[0].length;
    uint32_t count = 0u;
    uint32_t maximum_count = next_length == 0 ? 138u : 7u;
    uint32_t minimum_count = next_length == 0 ? 3u : 4u;
    for (uint32_t symbol = 0; symbol < symbol_count; ++symbol) {
        const int32_t current_length = next_length;
        next_length = tree[symbol + 1].length;
        ++count;
        if (count < maximum_count && current_length == next_length) { continue; }
        if (count < minimum_count) { while (count-- != 0u) { sendTreeCode(bit_tree, current_length, false); } }
        else if (current_length != 0) {
            if (current_length != previous_length) { sendTreeCode(bit_tree, current_length, false); --count; }
            sendTreeCode(bit_tree, 16u, false);
            sendBits(count - 3u, 2u);
        }
        else if (count <= 10u) { sendTreeCode(bit_tree, 17u, false); sendBits(count - 3u, 3u); }
        else { sendTreeCode(bit_tree, 18u, false); sendBits(count - 11u, 7u); }
        count = 0u;
        previous_length = current_length;
        if (next_length == 0) { maximum_count = 138u; minimum_count = 3u; }
        else if (current_length == next_length) { maximum_count = 6u; minimum_count = 3u; }
        else { maximum_count = 7u; minimum_count = 4u; }
    }
}

uint32_t SferaDeflateState32::buildBitLengthTree() {
    scanTree(literal_descriptor.dynamic_tree, literal_descriptor.symbol_count);
    scanTree(distance_descriptor.dynamic_tree, distance_descriptor.symbol_count);
    buildTree(&bit_length_descriptor);
    uint32_t last_rank = 18u;
    while (last_rank >= 3u && bit_length_tree[codeLengthOrder[last_rank]].length == 0u) --last_rank;
    optimal_length += 3u * (last_rank + 1u) + 14u;
    return last_rank;
}

void SferaDeflateState32::sendAllTrees(uint32_t literal_codes, uint32_t distance_codes, uint32_t bit_length_codes) {
    sendBits(literal_codes - 257u, 5u);
    sendBits(distance_codes - 1u, 5u);
    sendBits(bit_length_codes - 4u, 4u);
    for (uint32_t rank = 0u; rank < bit_length_codes; ++rank) sendBits(bit_length_tree[codeLengthOrder[rank]].length, 3u);
    sendTree(literal_descriptor.dynamic_tree, literal_codes);
    sendTree(distance_descriptor.dynamic_tree, distance_codes);
}

void SferaDeflateState32::flushBlock(const uint8_t* buffer, uint32_t stored_length, uint32_t end_of_file) {
    uint32_t optimal_bytes = 0u;
    uint32_t static_bytes = 0u;
    uint32_t last_bit_length_rank = 0u;
    if (this->level > 0) {
        if (this->data_type == 2u) { setDataType(); }
        buildTree(&this->literal_descriptor);
        buildTree(&this->distance_descriptor);
        last_bit_length_rank = buildBitLengthTree();
        optimal_bytes = (this->optimal_length + 10u) >> 3u;
        static_bytes = (this->static_length + 10u) >> 3u;
        if (static_bytes <= optimal_bytes) { optimal_bytes = static_bytes; }
    }
    else { optimal_bytes = static_bytes = stored_length + 5u; }
    if (buffer != nullptr && stored_length + 4u <= optimal_bytes) { writeStoredBlock(buffer, stored_length, end_of_file); }
    else if (static_bytes == optimal_bytes) { sendBits(2u + (end_of_file & 1u), 3u); compressBlock(nullptr, nullptr); }
    else {
        sendBits(4u + (end_of_file & 1u), 3u);
        sendAllTrees(literal_descriptor.symbol_count, distance_descriptor.symbol_count, last_bit_length_rank + 1u);
        compressBlock(this->literal_descriptor.dynamic_tree, this->distance_descriptor.dynamic_tree);
    }
    initBlock();
    if (end_of_file != 0u) { bitWindup(); }
}

void SferaDeflateState32::compressBlock(SferaCtData32* literal_tree, SferaCtData32* distance_tree) {
    
    const uint32_t literal_count = this->last_literal;
    
    uint8_t* literals = this->literal_buffer.data();
    uint16_t* distances = this->distance_buffer.data();
    for (uint32_t index = 0u; index != literal_count; ++index) {
        uint32_t distance = distances[index];
        const uint32_t literal_or_length = literals[index];
        if (distance == 0u) { sendTreeCode(literal_tree, literal_or_length, false); continue; }
        uint32_t length_code = literal_or_length;
        if (literal_or_length >= 255u) { length_code = 28u; } else if (literal_or_length >= 8u) { uint32_t highest_bit = 0u; for (uint32_t value = literal_or_length; value > 1u; value >>= 1u) { ++highest_bit; } const uint32_t extra = highest_bit - 2u; const uint32_t base = 1u << (extra + 2u); length_code = 4u * extra + 4u + ((literal_or_length - base) >> extra); }
        sendTreeCode(literal_tree, length_code + 257u, false);
        const uint32_t length_extra = length_code >= 8u && length_code < 28u ? (length_code - 4u) >> 2u : 0u;
        if (length_extra != 0u) { const uint32_t group_begin = 4u * length_extra + 4u; const uint32_t base = (1u << (length_extra + 2u)) + ((length_code - group_begin) << length_extra); sendBits(literal_or_length - base, length_extra); }
        --distance;
        uint32_t distance_code = distance;
        if (distance >= 4u) { uint32_t highest_bit = 0u; for (uint32_t value = distance; value > 1u; value >>= 1u) { ++highest_bit; } const uint32_t extra = highest_bit - 1u; distance_code = (highest_bit << 1u) + ((distance >> extra) & 1u); }
        sendTreeCode(distance_tree, distance_code, true);
        const uint32_t distance_extra = distance_code >= 4u ? (distance_code >> 1u) - 1u : 0u;
        if (distance_extra != 0u) { const uint32_t base = (1u << (distance_extra + 1u)) + ((distance_code & 1u) << distance_extra); sendBits(distance - base, distance_extra); }
    }
    sendTreeCode(literal_tree, 256u, false);
    this->last_eob_length = treeEntry(literal_tree, 256u, false).length;
}

bool SferaDeflateState32::tally(uint32_t distance, uint32_t literal_or_length) {
    uint8_t* literals = this->literal_buffer.data();
    uint16_t* distances = this->distance_buffer.data();
    const uint32_t index = this->last_literal++;
    distances[index] = distance & 65535u;
    literals[index] = literal_or_length & 255u;
    if (distance == 0u) { ++this->dynamic_literal_tree[literal_or_length].code; }
    else {
        ++this->matches;
        const uint32_t normalized_distance = distance - 1u;
        uint32_t distance_code = normalized_distance;
        if (normalized_distance >= 4u) { uint32_t highest_bit = 0u; for (uint32_t value = normalized_distance; value > 1u; value >>= 1u) { ++highest_bit; } distance_code = (highest_bit << 1u) + ((normalized_distance >> (highest_bit - 1u)) & 1u); }
        uint32_t length_code = literal_or_length;
        if (literal_or_length >= 255u) { length_code = 28u; } else if (literal_or_length >= 8u) { uint32_t highest_bit = 0u; for (uint32_t value = literal_or_length; value > 1u; value >>= 1u) { ++highest_bit; } const uint32_t extra = highest_bit - 2u; length_code = 4u * extra + 4u + ((literal_or_length - (1u << (extra + 2u))) >> extra); }
        ++this->dynamic_literal_tree[length_code + 257u].code;
        ++this->dynamic_distance_tree[distance_code].code;
    }
    return this->last_literal == this->literal_buffer_size - 1u;
}

uint32_t SferaDeflateState32::insertString(uint8_t* window, uint16_t* previous, uint16_t* heads) {
    this->ins_h = ((this->ins_h << this->hash_shift) ^ window[this->strstart + 2u]) & this->hash_mask;
    const uint16_t hash_head = heads[this->ins_h];
    previous[this->strstart & this->w_mask] = hash_head;
    heads[this->ins_h] = this->strstart & 65535u;
    return hash_head;
}

std::optional<SferaDeflateState32::BlockState> SferaDeflateState32::flushCurrentBlock(bool end_of_file) {
    const uint8_t* buffer = block_start >= 0 ? window.data() + block_start : nullptr;
    const uint32_t stored_length = strstart - block_start;
    flushBlock(buffer, stored_length, end_of_file ? 1u : 0u);
    block_start = strstart;
    strm->deflateFlushPending();
    if (strm->avail_out == 0u) return end_of_file ? BlockState::FinalNeedOutput : BlockState::NeedOutput;
    return std::nullopt;
}

int SferaZStream32::deflateReset() {
    
    if (this->state == nullptr) { return -2; }
    this->total_in = 0u;
    this->total_out = 0u;
    this->msg.reset();
    this->data_type = 2;
    state->pending = 0;
    state->pending_offset = 0u;
    if (state->noheader < 0) { state->noheader = 0; }
    state->phase = state->noheader != 0 ? SferaDeflateState32::Phase::Blocks : SferaDeflateState32::Phase::Header;
    this->adler = 1u;
    state->last_flush = 0;
    state->treeInit();
    state->deflateLmInit();
    return 0u;
}

int SferaZStream32::deflate(int32_t flush) {
    if (flush < 0 || flush > 4) { return -2; }
    if (this->state == nullptr) { return -2; }
    if (this->next_out == nullptr || (this->next_in == nullptr && this->avail_in != 0u) || (state->phase == SferaDeflateState32::Phase::Complete && flush != 4)) { this->msg = "stream error"; return -2; }
    if (this->avail_out == 0u) { this->msg = "buffer error"; return -5; }
    state->strm = this;
    const int32_t previous_flush = state->last_flush;
    state->last_flush = flush;
    if (state->phase == SferaDeflateState32::Phase::Header) {
        uint32_t header = (state->method + ((state->w_bits - 8u) << 4u)) << 8u;
        const int level_hint = (state->level - 1) >> 1;
        const uint32_t level_flags = level_hint < 0 ? 3 : std::min(level_hint, 3);
        header |= level_flags << 6u;
        if (state->strstart != 0u) { header |= preset_dictionary_flag; }
        header += 31u - header % 31u;
        state->phase = SferaDeflateState32::Phase::Blocks;
        state->deflatePutShortMsb(header);
        if (state->strstart != 0u) { state->deflatePutShortMsb(this->adler >> 16u); state->deflatePutShortMsb(this->adler & std::numeric_limits<uint16_t>::max()); }
        this->adler = 1u;
    }
    if (state->pending != 0) {
        deflateFlushPending();
        if (this->avail_out == 0u) { state->last_flush = -1; return 0u; }
    }
    else if (this->avail_in == 0u && flush <= previous_flush && flush != 4) { this->msg = "buffer error"; return -5; }
    if (state->phase == SferaDeflateState32::Phase::Complete && this->avail_in != 0u) { this->msg = "buffer error"; return -5; }
    if (this->avail_in != 0u || state->lookahead != 0u || (flush != 0 && state->phase != SferaDeflateState32::Phase::Complete)) {
        using BlockState = SferaDeflateState32::BlockState;
        BlockState block_state;
        if (state->level == 0) { block_state = state->deflateStored(flush); }
        else if (state->level <= 3) { block_state = state->deflateFast(flush); }
        else { block_state = state->deflateSlow(flush); }
        if (block_state == BlockState::FinalNeedOutput || block_state == BlockState::Complete) { state->phase = SferaDeflateState32::Phase::Complete; }
        if (block_state == BlockState::NeedOutput || block_state == BlockState::FinalNeedOutput) { if (this->avail_out == 0u) { state->last_flush = -1; } return 0u; }
        if (block_state == BlockState::BlockDone) {
            if (flush == 1) { state->alignStaticBlock(); }
            else {
                state->writeStoredBlock(nullptr, 0u, 0u);
                if (flush == 3) { std::fill(state->head.begin(), state->head.end(), std::uint16_t{}); }
            }
            deflateFlushPending();
            if (this->avail_out == 0u) { state->last_flush = -1; return 0u; }
        }
    }
    if (flush != 4) { return 0u; }
    if (state->noheader != 0) { return 1u; }
    state->deflatePutShortMsb(this->adler >> 16u);
    state->deflatePutShortMsb(this->adler & std::numeric_limits<uint16_t>::max());
    deflateFlushPending();
    state->noheader = -1;
    return state->pending != 0 ? 0u : 1u;
}

SferaDeflateState32::BlockState SferaDeflateState32::deflateStored(int32_t flush) {
    uint32_t max_block_size = std::numeric_limits<uint16_t>::max();
    if (max_block_size > this->pending_buf_size - 5u) { max_block_size = this->pending_buf_size - 5u; }
    for (;;) {
        if (this->lookahead <= 1u) {
            deflateFillWindow();
            if (this->lookahead == 0u && flush == 0) { return BlockState::NeedOutput; }
            if (this->lookahead == 0u) { break; }
        }
        this->strstart += this->lookahead;
        this->lookahead = 0u;
        const uint32_t max_start = this->block_start + max_block_size;
        if (this->strstart == 0u || this->strstart >= max_start) {
            this->lookahead = this->strstart - max_start;
            this->strstart = max_start;
            const auto result = flushCurrentBlock(false);
            if (result) return *result;
        }
        if (this->strstart - this->block_start >= this->w_size - 262u) {
            const auto result = flushCurrentBlock(false);
            if (result) return *result;
        }
    }
    const bool finishing = flush == 4;
    return flushCurrentBlock(finishing).value_or(finishing ? BlockState::Complete : BlockState::BlockDone);
}

SferaDeflateState32::BlockState SferaDeflateState32::deflateFast(int32_t flush) {
    uint8_t* window = this->window.data();
    uint16_t* previous = this->prev.data();
    uint16_t* heads = this->head.data();
    for (;;) {
        if (this->lookahead < 262u) {
            deflateFillWindow();
            if (this->lookahead < 262u && flush == 0) { return BlockState::NeedOutput; }
            if (this->lookahead == 0u) { break; }
        }
        uint32_t hash_head = 0u;
        if (this->lookahead >= 3u) { hash_head = insertString(window, previous, heads); }
        if (hash_head != 0u && this->strstart - hash_head <= this->w_size - 262u && this->strategy != 2) { this->match_length = deflateLongestMatch(hash_head); }
        bool flush_block = false;
        if (this->match_length >= 3u) {
            flush_block = tally(this->strstart - this->match_start, this->match_length - 3u);
            this->lookahead -= this->match_length;
            if (this->match_length <= this->max_lazy_match && this->lookahead >= 3u) {
                --this->match_length;
                do { ++this->strstart; hash_head = insertString(window, previous, heads); } while (--this->match_length != 0u);
                ++this->strstart;
            }
            else {
                this->strstart += this->match_length;
                this->match_length = 0u;
                this->ins_h = window[this->strstart];
                this->ins_h = ((this->ins_h << this->hash_shift) ^ window[this->strstart + 1u]) & this->hash_mask;
            }
        }
        else {
            flush_block = tally(0u, window[this->strstart]);
            --this->lookahead;
            ++this->strstart;
        }
        if (flush_block) { const auto result = flushCurrentBlock(false); if (result) return *result; }
    }
    const bool finishing = flush == 4;
    return flushCurrentBlock(finishing).value_or(finishing ? BlockState::Complete : BlockState::BlockDone);
}

SferaDeflateState32::BlockState SferaDeflateState32::deflateSlow(int32_t flush) {
    uint8_t* window = this->window.data();
    uint16_t* previous = this->prev.data();
    uint16_t* heads = this->head.data();
    for (;;) {
        if (this->lookahead < 262u) {
            deflateFillWindow();
            if (this->lookahead < 262u && flush == 0) { return BlockState::NeedOutput; }
            if (this->lookahead == 0u) { break; }
        }
        uint32_t hash_head = 0u;
        if (this->lookahead >= 3u) { hash_head = insertString(window, previous, heads); }
        this->prev_length = this->match_length;
        this->prev_match = this->match_start;
        this->match_length = 2u;
        if (hash_head != 0u && this->prev_length < this->max_lazy_match && this->strstart - hash_head <= this->w_size - 262u && this->strategy != 2) {
            this->match_length = deflateLongestMatch(hash_head);
            if (this->match_length <= 5u && (this->strategy == 1 || (this->match_length == 3u && this->strstart - this->match_start > 4096u))) { this->match_length = 2u; }
        }
        if (this->prev_length >= 3u && this->match_length <= this->prev_length) {
            const uint32_t max_insert = this->strstart + this->lookahead - 3u;
            const bool flush_block = tally(this->strstart - 1u - this->prev_match, this->prev_length - 3u);
            this->lookahead -= this->prev_length - 1u;
            this->prev_length -= 2u;
            do { if (++this->strstart <= max_insert) { hash_head = insertString(window, previous, heads); } } while (--this->prev_length != 0u);
            this->match_available = 0;
            this->match_length = 2u;
            ++this->strstart;
            if (flush_block) { const auto result = flushCurrentBlock(false); if (result) return *result; }
        }
        else if (this->match_available != 0) {
            const bool flush_block = tally(0u, window[this->strstart - 1u]);
            if (flush_block) { flushCurrentBlock(false); }
            ++this->strstart;
            --this->lookahead;
            if (this->strm->avail_out == 0u) { return BlockState::NeedOutput; }
        }
        else { this->match_available = 1; ++this->strstart; --this->lookahead; }
    }
    if (this->match_available != 0) { tally(0u, window[this->strstart - 1u]); this->match_available = 0; }
    const bool finishing = flush == 4;
    return flushCurrentBlock(finishing).value_or(finishing ? BlockState::Complete : BlockState::BlockDone);
}

uint32_t SferaZStream32::adler32(uint32_t adler, const uint8_t* buffer, uint32_t length) {
    if (buffer == nullptr) { return 1u; }
    uint32_t low = adler & std::numeric_limits<uint16_t>::max();
    uint32_t high = (adler >> 16u) & std::numeric_limits<uint16_t>::max();
    uint32_t offset = 0u;
    while (offset != length) {
        uint32_t chunk = length - offset;
        if (chunk > 5552u) { chunk = 5552u; }
        const uint8_t* input = buffer + offset;
        for (uint32_t index = 0u; index != chunk; ++index) { low += input[index]; high += low; }
        low %= 65521u;
        high %= 65521u;
        offset += chunk;
    }
    return (high << 16u) | low;
}

void SferaDeflateState32::deflatePutShortMsb(uint32_t value) {
    uint8_t* pending_bytes = this->pending_buf.data();
    pending_bytes[this->pending++] = (value >> 8u) & 255u;
    pending_bytes[this->pending++] = value & 255u;
}

void SferaZStream32::deflateFlushPending() {
    uint32_t length = state->pending;
    if (length > this->avail_out) { length = this->avail_out; }
    if (length == 0u) { return; }
    std::memcpy(this->next_out, state->pending_buf.data() + state->pending_offset, length);
    this->next_out += length;
    state->pending_offset += length;
    this->total_out += length;
    this->avail_out -= length;
    state->pending -= length;
    if (state->pending == 0) { state->pending_offset = 0u; }
}

void SferaDeflateState32::deflateLmInit() {
    this->window_size = this->w_size * 2u;
    std::fill(head.begin(), head.end(), std::uint16_t{});
    const SferaDeflateConfig config = deflateConfig(this->level);
    this->max_lazy_match = config.max_lazy;
    this->good_match = config.good_length;
    this->nice_match = config.nice_length;
    this->max_chain_length = config.max_chain;
    this->strstart = 0u;
    this->block_start = 0;
    this->lookahead = 0u;
    this->match_length = 2u;
    this->prev_length = 2u;
    this->match_available = 0;
    this->ins_h = 0u;
}

uint32_t SferaZStream32::deflateReadBuf(uint8_t* destination, uint32_t size) {
    uint32_t length = this->avail_in;
    if (length > size) { length = size; }
    if (length == 0u) { return 0u; }
    this->avail_in -= length;
    if (state->noheader == 0) { this->adler = adler32(this->adler, this->next_in, length); }
    std::memcpy(destination, this->next_in, length);
    this->next_in += length;
    this->total_in += length;
    return length;
}

uint32_t SferaDeflateState32::deflateLongestMatch(uint32_t current_match) {
    uint8_t* window = this->window.data();
    uint16_t* previous = this->prev.data();
    uint32_t chain_left = this->max_chain_length;
    uint32_t best_length = this->prev_length;
    uint32_t nice_length = this->nice_match;
    if (nice_length > this->lookahead) { nice_length = this->lookahead; }
    if (this->prev_length >= this->good_match) { chain_left >>= 2u; }
    const uint32_t max_distance = this->w_size - 262u;
    const uint32_t limit = this->strstart > max_distance ? this->strstart - max_distance : 0u;
    const uint32_t compare_limit = this->lookahead < 258u ? this->lookahead : 258u;
    if (best_length >= compare_limit || chain_left == 0u) { return best_length < this->lookahead ? best_length : this->lookahead; }
    while (true) {
        if (current_match >= this->strstart) { break; }
        if (window[current_match] == window[this->strstart] && window[current_match + 1u] == window[this->strstart + 1u] && window[current_match + best_length] == window[this->strstart + best_length]) {
            uint32_t length = 2u;
            while (length < compare_limit && window[current_match + length] == window[this->strstart + length]) { ++length; }
            if (length > best_length) {
                this->match_start = current_match;
                best_length = length;
                if (best_length >= nice_length) { break; }
            }
        }
        const uint32_t next_match = previous[current_match & this->w_mask];
        if (next_match <= limit) { break; }
        if (--chain_left == 0u) { break; }
        current_match = next_match;
    }
    return best_length < this->lookahead ? best_length : this->lookahead;
}

void SferaDeflateState32::deflateFillWindow() {
    uint8_t* window = this->window.data();
    uint16_t* heads = this->head.data();
    uint16_t* previous = this->prev.data();
    const uint32_t window_size = this->w_size;
    while (true) {
        uint32_t more = this->window_size - this->lookahead - this->strstart;
        if (more == 0u && this->strstart == 0u && this->lookahead == 0u) { more = window_size; }
        else if (more == UINT32_MAX) { --more; }
        else if (this->strstart >= window_size + (window_size - 262u)) {
            std::memcpy(window, window + window_size, window_size);
            this->match_start -= window_size;
            this->strstart -= window_size;
            this->block_start -= window_size;
            for (uint32_t index = 0u; index != this->hash_size; ++index) { const uint32_t value = heads[index]; heads[index] = value >= window_size ? value - window_size : 0u; }
            for (uint32_t index = 0u; index != window_size; ++index) { const uint32_t value = previous[index]; previous[index] = value >= window_size ? value - window_size : 0u; }
            more += window_size;
        }
        if (this->strm->avail_in == 0u) { return; }
        uint8_t* destination = this->window.data() + this->strstart + this->lookahead;
        this->lookahead += strm->deflateReadBuf(destination, more);
        if (this->lookahead >= 3u) {
            this->ins_h = window[this->strstart];
            this->ins_h = ((this->ins_h << this->hash_shift) ^ window[this->strstart + 1u]) & this->hash_mask;
        }
        if (this->lookahead >= 262u || this->strm->avail_in == 0u) { return; }
    }
}
SferaDeflateState32::SferaDeflateState32(SferaZStream32& stream, int compressionLevel) {
    strm = &stream;
    level = compressionLevel;
    window.resize(window_size);
    prev.resize(w_size);
    head.resize(hash_size);
    literal_buffer.resize(literal_buffer_size);
    distance_buffer.resize(literal_buffer_size);
    pending_buf_size = literal_buffer_size * 4;
    pending_buf.resize(pending_buf_size);
    stream.state = this;
    stream.deflateReset();
}
int SferaZStream32::compress(std::uint8_t* output, std::uint32_t& outputSize, std::span<const std::uint8_t> input, int level) {
    if (level == -1) level = 6;
    if (level < 0 || level > 9 || input.size() > std::numeric_limits<std::uint32_t>::max() || output == nullptr) return -2;
    try {
        SferaZStream32 stream;
        stream.next_in = input.data();
        stream.avail_in = input.size();
        stream.next_out = output;
        stream.avail_out = outputSize;
        SferaDeflateState32 state(stream, level);
        const int status = stream.deflate(4);
        if (status != 1) return status == 0 ? -5 : status;
        outputSize = stream.total_out;
        return 0;
    } catch (const std::bad_alloc&) { return -4; }
}
bool SferaZStream32::readBits(std::uint32_t count, std::uint32_t& value) {
    while (input_bit_count < count) {
        if (avail_in == 0) return false;
        const std::uint32_t byte = *next_in++;
        input_bits |= byte << input_bit_count;
        input_bit_count += 8;
        --avail_in;
        ++total_in;
    }
    value = input_bits & ((1u << count) - 1u);
    input_bits >>= count;
    input_bit_count -= count;
    return true;
}
bool SferaInflateHuft32::build(std::span<const std::uint8_t> lengths, bool codeLengths) {
    counts.fill(0);
    symbols.fill(0);
    maximum_length = 0;
    if (lengths.size() > symbols.size()) return false;
    for (const auto length : lengths) {
        if (length >= counts.size()) return false;
        ++counts[length];
        maximum_length = std::max(maximum_length, length);
    }
    if (maximum_length == 0) return !codeLengths;
    int unused = 1;
    for (std::size_t bits = 1; bits < counts.size(); ++bits) {
        unused = unused * 2 - counts[bits];
        if (unused < 0) return false;
    }
    if (unused != 0 && (codeLengths || maximum_length != 1)) return false;
    std::array<std::uint16_t, 16> offsets{};
    for (std::size_t bits = 1; bits + 1 < offsets.size(); ++bits) offsets[bits + 1] = offsets[bits] + counts[bits];
    for (std::size_t symbol = 0; symbol < lengths.size(); ++symbol) {
        if (lengths[symbol] != 0) symbols[offsets[lengths[symbol]]++] = symbol;
    }
    return true;
}
int SferaInflateHuft32::decode(SferaZStream32& stream) const {
    std::uint32_t code = 0;
    std::uint32_t first = 0;
    std::uint32_t index = 0;
    for (std::size_t length = 1; length <= maximum_length; ++length) {
        std::uint32_t bit;
        if (!stream.readBits(1, bit)) return -5;
        code = code * 2 + bit;
        if (code >= first && code - first < counts[length]) return symbols[index + code - first];
        index += counts[length];
        first = (first + counts[length]) * 2;
    }
    return -3;
}
int SferaZStream32::inflate() {
    std::uint32_t methodByte, flags;
    if (!readBits(8, methodByte) || !readBits(8, flags)) return -5;
    const auto method = methodByte & 15u;
    const auto windowBits = (methodByte >> 4u) + 8u;
    if (method != 8 || windowBits > 15 || (methodByte * 256u + flags) % 31u != 0) return -3;
    if ((flags & preset_dictionary_flag) != 0) {
        std::uint32_t byte;
        for (int index = 0; index != 4; ++index) if (!readBits(8, byte)) return -5;
        return 2;
    }
    auto* outputStart = next_out;
    std::uint32_t finalBlock = 0;
    do {
        std::uint32_t blockType;
        if (!readBits(1, finalBlock) || !readBits(2, blockType)) return -5;
        if (blockType == 0) {
            const auto padding = input_bit_count % 8;
            input_bits >>= padding;
            input_bit_count -= padding;
            std::uint32_t length, complement;
            if (!readBits(16, length) || !readBits(16, complement)) return -5;
            if ((length ^ complement) != std::numeric_limits<std::uint16_t>::max()) return -3;
            for (std::uint32_t i = 0; i < length; ++i) {
                std::uint32_t value;
                if (avail_out == 0 || !readBits(8, value)) return -5;
                *next_out++ = value;
                --avail_out;
                ++total_out;
            }
            continue;
        }
        if (blockType == 3) return -3;
        std::array<std::uint8_t, 320> lengths{};
        std::uint32_t literalCount = 288;
        std::uint32_t distanceCount = 32;
        SferaInflateHuft32 literalTree, distanceTree;
        if (blockType == 1) {
            for (std::uint32_t symbol = 0; symbol < literalCount; ++symbol) lengths[symbol] = SferaDeflateState32::fixedLiteralLength(symbol);
            std::fill(lengths.begin() + literalCount, lengths.end(), 5);
        } else {
            std::uint32_t codeCount;
            if (!readBits(5, literalCount) || !readBits(5, distanceCount) || !readBits(4, codeCount)) return -5;
            literalCount += 257;
            distanceCount += 1;
            codeCount += 4;
            if (literalCount > 286 || distanceCount > 32) return -3;
            std::array<std::uint8_t, 19> codeLengths{};
            for (std::uint32_t i = 0; i < codeCount; ++i) {
                std::uint32_t length;
                if (!readBits(3, length)) return -5;
                codeLengths[codeLengthOrder[i]] = length;
            }
            SferaInflateHuft32 codeTree;
            if (!codeTree.build(codeLengths, true)) return -3;
            std::uint32_t index = 0;
            const auto count = literalCount + distanceCount;
            while (index < count) {
                const int symbol = codeTree.decode(*this);
                if (symbol < 0) return symbol;
                if (symbol < 16) { lengths[index++] = symbol; continue; }
                if (symbol > 18 || (symbol == 16 && index == 0)) return -3;
                const auto extraBits = SferaDeflateState32::treeExtraBits(SferaZlibTreeKind::BitLength, symbol);
                std::uint32_t repetitions;
                if (!readBits(extraBits, repetitions)) return -5;
                repetitions += symbol == 18 ? 11 : 3;
                if (repetitions > count - index) return -3;
                const std::uint8_t value = symbol == 16 ? lengths[index - 1] : 0;
                std::fill_n(lengths.begin() + index, repetitions, value);
                index += repetitions;
            }
        }
        if (lengths[256] == 0 || !literalTree.build(std::span(lengths).first(literalCount)) || !distanceTree.build(std::span(lengths).subspan(literalCount, distanceCount))) return -3;
        for (;;) {
            const int symbol = literalTree.decode(*this);
            if (symbol < 0) return symbol;
            if (symbol == 256) break;
            if (symbol < 256) {
                if (avail_out == 0) return -5;
                *next_out++ = symbol;
                --avail_out;
                ++total_out;
                continue;
            }
            if (symbol > 285) return -3;
            const std::uint32_t lengthCode = symbol - 257;
            const auto lengthBits = SferaDeflateState32::treeExtraBits(SferaZlibTreeKind::Literal, symbol);
            std::uint32_t lengthExtra;
            if (!readBits(lengthBits, lengthExtra)) return -5;
            const std::uint32_t lengthBase = lengthCode < 8 ? lengthCode + 3 : lengthCode == 28 ? 258 : (1u << (lengthBits + 2u)) + ((lengthCode - 4u * lengthBits - 4u) << lengthBits) + 3u;
            const auto length = lengthBase + lengthExtra;
            const int distanceCode = distanceTree.decode(*this);
            if (distanceCode < 0) return distanceCode;
            if (distanceCode > 29) return -3;
            const auto distanceBits = SferaDeflateState32::treeExtraBits(SferaZlibTreeKind::Distance, distanceCode);
            std::uint32_t distanceExtra;
            if (!readBits(distanceBits, distanceExtra)) return -5;
            const std::uint32_t distanceBase = distanceCode < 4 ? distanceCode + 1 : (1u << (distanceBits + 1u)) + ((distanceCode & 1u) << distanceBits) + 1u;
            const auto distance = distanceBase + distanceExtra;
            if (distance > total_out || distance > (1u << windowBits)) return -3;
            if (length > avail_out) return -5;
            for (std::uint32_t i = 0; i < length; ++i) { *next_out = *(next_out - distance); ++next_out; }
            avail_out -= length;
            total_out += length;
        }
    } while (finalBlock == 0);
    const auto padding = input_bit_count % 8;
    input_bits >>= padding;
    input_bit_count -= padding;
    std::uint32_t expectedAdler = 0;
    for (int i = 0; i < 4; ++i) {
        std::uint32_t value;
        if (!readBits(8, value)) return -5;
        expectedAdler = (expectedAdler << 8u) | value;
    }
    adler = adler32(1, outputStart, total_out);
    return adler == expectedAdler ? 1 : -3;
}
int SferaZStream32::decompress(std::uint8_t* output, std::uint32_t& outputSize, std::span<const std::uint8_t> input) {
    if (output == nullptr || input.size() > std::numeric_limits<std::uint32_t>::max()) return -2;
    SferaZStream32 stream;
    stream.next_in = input.data();
    stream.avail_in = input.size();
    stream.next_out = output;
    stream.avail_out = outputSize;
    const auto status = stream.inflate();
    if (status != 1) return status;
    outputSize = stream.total_out;
    return 0;
}
bool SferaZStream32::hasEnvelope(std::span<const std::uint8_t> input) {
    static constexpr std::array<std::uint8_t, 4> signature{'S', 'P', 'H', 'R'};
    return input.size() >= 14 && std::equal(signature.begin(), signature.end(), input.begin());
}
int SferaZStream32::compressEnvelope(std::uint8_t* output, std::uint32_t& outputSize, std::span<const std::uint8_t> input) {
    if (output == nullptr || outputSize < envelope_header_size || input.size() > std::numeric_limits<std::uint32_t>::max()) return -1;
    std::uint32_t payloadSize = outputSize - envelope_header_size;
    auto* payload = output + envelope_header_size;
    if (compress(payload, payloadSize, input, 1) != 0) return -1;
    if (payloadSize <= envelope_length_mask_index) return -1;
    for (const auto index : envelope_encoded_positions) {
        if (index < payloadSize) payload[index] ^= payload[0];
    }
    const std::uint32_t originalSize = input.size();
    for (std::size_t i = 0; i < sizeof(originalSize); ++i) output[4 + i] = ((originalSize >> (8u * i)) & 255u) ^ payload[envelope_length_mask_index];
    std::copy_n("SPHR", 4, output);
    outputSize = payloadSize + envelope_header_size;
    return 0;
}
int SferaZStream32::decompressEnvelope(std::uint8_t* output, std::uint32_t& outputSize, std::span<std::uint8_t> input) {
    if (!hasEnvelope(input) || input.size() <= envelope_header_size + envelope_length_mask_index) return -2;
    auto payload = input.subspan(envelope_header_size);
    if (outputSize == 0) {
        for (std::size_t i = 0; i < sizeof(outputSize); ++i) {
            const std::uint32_t byte = input[4 + i] ^ payload[envelope_length_mask_index];
            outputSize |= byte << (8u * i);
        }
        return 0;
    }
    for (const auto index : envelope_encoded_positions) {
        if (index < payload.size()) payload[index] ^= payload[0];
    }
    for (std::size_t i = 0; i < sizeof(outputSize); ++i) input[4 + i] ^= payload[envelope_length_mask_index];
    return decompress(output, outputSize, payload) == 0 ? 0 : -1;
}


