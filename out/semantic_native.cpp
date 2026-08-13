#include "semantic_native.h"

#include <algorithm>
#include <array>
#include <bit>
#include <chrono>
#include <cmath>
#include <charconv>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <set>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

namespace sfera::semantic {
namespace {

static_assert(sizeof(Vec3) == 12);
static_assert(sizeof(BoxCorners) == 96);
#if UINTPTR_MAX == UINT32_MAX
static_assert(sizeof(BitSlice) == 12);
static_assert(sizeof(ByteView) == 8);
#endif

RuntimeServices g_runtime{};

ConfigurationStorage& configuration() {
    ConfigurationStorage& storage = g_runtime.configuration;
    if (!storage.active_text || !storage.active_length || !storage.owned_text || storage.owned_capacity == 0) { throw std::logic_error("Semantic configuration storage is not attached"); }
    return storage;
}

void report_bit_overflow(const char* kind, std::uint32_t position, std::int32_t count, std::int32_t size) {
    if (!g_runtime.diagnostic) { return; }
    std::string message = "putbitstream overflow (";
    message += kind;
    message += "): position=" + std::to_string(position) + ", count=" + std::to_string(count) + ", size=" + std::to_string(size);
    g_runtime.diagnostic(message);
}

void transfer_bits(std::uint8_t* destination, std::uint32_t& destination_bit, const std::uint8_t* source, std::uint32_t& source_bit, std::int32_t bit_count) noexcept {
    for (std::int32_t index = 0; index < bit_count; ++index, ++source_bit, ++destination_bit) {
        const std::uint8_t source_mask = static_cast<std::uint8_t>(1u << (source_bit & 7u));
        const std::uint8_t destination_mask = static_cast<std::uint8_t>(1u << (destination_bit & 7u));
        std::uint8_t& output = destination[destination_bit >> 3u];
        output = (source[source_bit >> 3u] & source_mask) != 0 ? static_cast<std::uint8_t>(output | destination_mask) : static_cast<std::uint8_t>(output & static_cast<std::uint8_t>(~destination_mask));
    }
}

} // namespace

void attach_runtime(RuntimeServices services) noexcept {
    g_runtime = services;
}

char* filename_component(char* path) {
    if (!path) { return nullptr; }
    char* separator = std::strrchr(path, '\\');
    return separator ? separator + 1 : path;
}

BoxCorners* build_box_corners(BoxCorners* destination, const Vec3* minimum, const Vec3* maximum) {
    destination->vertices = {{{minimum->x, minimum->y, minimum->z}, {maximum->x, minimum->y, minimum->z}, {maximum->x, maximum->y, minimum->z}, {minimum->x, maximum->y, minimum->z}, {minimum->x, maximum->y, maximum->z}, {minimum->x, minimum->y, maximum->z}, {maximum->x, minimum->y, maximum->z}, {maximum->x, maximum->y, maximum->z}}};
    return destination;
}

BitSlice* construct_bit_slice(BitSlice* destination, std::uint8_t* bytes, std::uint32_t* bit_position, std::uint32_t byte_count) {
    destination->bytes = bytes;
    destination->bit_position = bit_position;
    destination->byte_count = byte_count;
    return destination;
}

void copy_bits(std::uint8_t* destination, std::uint32_t* destination_bit, const std::uint8_t* source, std::uint32_t* source_bit, std::int32_t bit_count, std::int32_t destination_bytes) {
    std::uint32_t read_position = source_bit ? *source_bit : 0u;
    std::uint32_t write_position = destination_bit ? *destination_bit : 0u;
    if (bit_count > 0) {
        const std::uint32_t capacity_bits = static_cast<std::uint32_t>(destination_bytes) << 3u;
        const std::uint32_t end_position = write_position + static_cast<std::uint32_t>(bit_count);
        if (destination_bit ? static_cast<std::int32_t>(end_position) > static_cast<std::int32_t>(capacity_bits) : bit_count > static_cast<std::int32_t>(capacity_bits)) { report_bit_overflow(destination_bit ? "offset" : "start", write_position, bit_count, destination_bytes); }
        transfer_bits(destination, write_position, source, read_position, bit_count);
    } else if (bit_count < 0) {
        read_position += static_cast<std::uint32_t>(bit_count);
        write_position += static_cast<std::uint32_t>(bit_count);
    }
    if (source_bit) { *source_bit = read_position; }
    if (destination_bit) { *destination_bit = write_position; }
}

bool token_equals(const char* expected, const char* token_begin, const char* token_end) {
    if (!expected || !token_begin || !token_end || token_end < token_begin) { return false; }
    const std::size_t token_length = static_cast<std::size_t>(token_end - token_begin);
    return std::char_traits<char>::length(expected) == token_length && std::char_traits<char>::compare(expected, token_begin, token_length) == 0;
}

void copy_c_string(char* destination, const char* source) {
    const std::size_t length = std::char_traits<char>::length(source);
    std::copy_n(source, length + 1u, destination);
}

std::uint32_t install_config_text(char* status, const char* text, std::uint32_t length) {
    ConfigurationStorage& storage = configuration();
    const std::size_t bounded_length = std::min<std::size_t>(length, storage.owned_capacity - 1u);
    if (bounded_length != 0) { std::memcpy(storage.owned_text, text, bounded_length); }
    storage.owned_text[bounded_length] = '\0';
    *storage.active_text = storage.owned_text;
    *storage.active_length = static_cast<std::uint32_t>(bounded_length);
    if (status) { status[0] = '\0'; }
    return static_cast<std::uint32_t>(bounded_length);
}

std::uint32_t config_text_length() {
    return *configuration().active_length;
}

const char* find_config_value(const char* key) {
    ConfigurationStorage& storage = configuration();
    const char* text = *storage.active_text;
    if (!text || !key) { return nullptr; }
    const char* key_end = std::find(key, key + 4096u, '\0');
    if (key_end == key + 4096u) { return nullptr; }
    const std::size_t key_length = static_cast<std::size_t>(key_end - key);
    const std::size_t scan_limit = std::min<std::size_t>(*storage.active_length, storage.owned_capacity - 1u) + 1u;
    std::size_t line = 0;
    while (line < scan_limit) {
        std::size_t token_end = line;
        while (token_end < scan_limit && text[token_end] != ' ' && text[token_end] != '\t' && text[token_end] != '\r' && text[token_end] != '\0') { ++token_end; }
        if (token_end - line == key_length && std::char_traits<char>::compare(text + line, key, key_length) == 0) {
            std::size_t value = token_end;
            while (value < scan_limit && (text[value] == ' ' || text[value] == '\t')) { ++value; }
            return value < scan_limit ? text + value : nullptr;
        }
        std::size_t next_line = token_end;
        while (next_line < scan_limit && text[next_line] != '\n' && text[next_line] != '\0') { ++next_line; }
        if (next_line == scan_limit || text[next_line] == '\0') { return nullptr; }
        line = next_line + 1u;
    }
    return nullptr;
}

bool write_binary_file(const char* path, const void* data, std::uint32_t size) {
    std::error_code permission_error;
    std::filesystem::permissions(path, std::filesystem::perms::owner_read | std::filesystem::perms::owner_write, std::filesystem::perm_options::replace, permission_error);
    std::ofstream output(path, std::ios::binary | std::ios::trunc);
    if (!output.is_open()) { return false; }
    output.write(static_cast<const char*>(data), static_cast<std::streamsize>(size));
    output.close();
    return true;
}

void reset_config_text(char* status, const char* status_value) {
    ConfigurationStorage& storage = configuration();
    *storage.active_length = 0;
    *storage.active_text = storage.owned_text;
    storage.owned_text[0] = '\0';
    copy_c_string(status, status_value);
}

void attach_config_text(char* status, char* text) {
    ConfigurationStorage& storage = configuration();
    *storage.active_text = text;
    *storage.active_length = static_cast<std::uint32_t>(std::char_traits<char>::length(text));
    if (status) { status[0] = '\0'; }
}

bool read_config_int(const char* key, std::int32_t* value) {
    const char* text = find_config_value(key);
    if (!text) { return false; }
    char* end = nullptr;
    const long parsed = std::strtol(text, &end, 10);
    if (end != text) { *value = static_cast<std::int32_t>(parsed); }
    return true;
}

bool read_config_float(const char* key, float* value) {
    const char* text = find_config_value(key);
    if (!text) { return false; }
    char* end = nullptr;
    const float parsed = std::strtof(text, &end);
    if (end != text) { *value = parsed; }
    return true;
}

bool read_config_string(const char* key, char* destination, std::uint32_t capacity) {
    const char* text = find_config_value(key);
    if (!text || *text++ != '"' || capacity == 0) { return false; }
    while (capacity != 0) {
        const char value = *text;
        if (value == '"' || value == '\0') { *destination = '\0'; return true; }
        ++text;
        if (value == '\r') { *destination = ' '; }
        else if (value != '\n') { *destination = value; }
        ++destination;
        --capacity;
    }
    return false;
}

bool read_config_bits(const char* key, std::uint8_t* destination, std::int32_t destination_bytes) {
    const char* text = find_config_value(key);
    if (!text) { return false; }
    std::uint32_t written_bits = 0;
    while (*text != '\0' && *text != '#') {
        if (destination_bytes < 0 || static_cast<std::uint64_t>(written_bits) + 6u > static_cast<std::uint64_t>(destination_bytes) * 8u) { return false; }
        const std::uint8_t encoded = static_cast<std::uint8_t>(*text++ - '0');
        std::uint32_t source_bit = 0;
        transfer_bits(destination, written_bits, &encoded, source_bit, 6);
    }
    if (*text != '#') { return true; }
    const std::int32_t tail_bits = static_cast<std::int8_t>(text[1]) - '0';
    if (tail_bits <= 0) { return true; }
    if (destination_bytes < 0 || static_cast<std::uint64_t>(written_bits) + static_cast<std::uint32_t>(tail_bits) > static_cast<std::uint64_t>(destination_bytes) * 8u) { return false; }
    std::array<std::uint8_t, 16> encoded{};
    encoded[0] = static_cast<std::uint8_t>(text[2] - '0');
    encoded[1] = static_cast<std::uint8_t>(static_cast<std::uint32_t>(destination_bytes) >> 8u);
    encoded[2] = static_cast<std::uint8_t>(static_cast<std::uint32_t>(destination_bytes) >> 16u);
    encoded[3] = static_cast<std::uint8_t>(static_cast<std::uint32_t>(destination_bytes) >> 24u);
    std::uint32_t source_bit = 0;
    transfer_bits(destination, written_bits, encoded.data(), source_bit, tail_bits);
    return true;
}

std::uint32_t copy_config_text(void* destination, std::uint32_t capacity) {
    ConfigurationStorage& storage = configuration();
    const std::uint32_t copied = std::min(capacity, *storage.active_length);
    if (copied != 0) { std::memcpy(destination, *storage.active_text, copied); }
    return copied;
}

std::int32_t compare_bytes(const void* left, const void* right, std::uint32_t size) {
    if (size == 0) { return 0; }
    const int result = std::memcmp(left, right, size);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

bool equal_byte_views(const ByteView* left, const ByteView* right) {
    if (!left->data || !right->data) { return left->data == right->data; }
    return left->size == right->size && compare_bytes(left->data, right->data, left->size) == 0;
}

std::string decimal_string(std::uint32_t value) {
    std::array<char, 10> buffer{};
    const auto result = std::to_chars(buffer.data(), buffer.data() + buffer.size(), value);
    if (result.ec != std::errc{}) { throw std::runtime_error("Unable to format decimal value"); }
    return std::string(buffer.data(), result.ptr);
}

void transform_point(Vec3* destination, const Matrix3x4* transform, const Vec3* source) {
    const Vec3 input = *source;
    destination->x = input.x * transform->values[0] + input.y * transform->values[1] + input.z * transform->values[2] + transform->values[3];
    destination->y = input.x * transform->values[4] + input.y * transform->values[5] + input.z * transform->values[6] + transform->values[7];
    destination->z = input.x * transform->values[8] + input.y * transform->values[9] + input.z * transform->values[10] + transform->values[11];
}

std::uint32_t is_model_file(const char* path) {
    if (!path) { return 0u; }
    const std::string_view name(path);
    if (name.size() < 5u || name[name.size() - 4u] != '.') { return 0u; }
    const auto equal_ascii = [](char value, char expected) { return static_cast<char>(std::tolower(static_cast<unsigned char>(value))) == expected; };
    return equal_ascii(name[name.size() - 3u], 'm') && equal_ascii(name[name.size() - 2u], 'd') && equal_ascii(name[name.size() - 1u], 'l') ? 1u : 0u;
}

namespace script {
namespace {

template <typename ValueType>
int ordered_compare(const ValueType& left, const ValueType& right) {
    if (left < right) { return -1; }
    if (right < left) { return 1; }
    return 0;
}

int compare_floats(float left, float right) noexcept {
    if (std::isnan(left) || std::isnan(right)) { return ordered_compare(std::bit_cast<std::uint32_t>(left), std::bit_cast<std::uint32_t>(right)); }
    return ordered_compare(left, right);
}

int compare_values(const Value& left, const Value& right);

template <typename Range>
int compare_ranges(const Range& left, const Range& right) {
    auto left_item = left.begin();
    auto right_item = right.begin();
    while (left_item != left.end() && right_item != right.end()) {
        const int comparison = compare_values(*left_item, *right_item);
        if (comparison != 0) { return comparison; }
        ++left_item;
        ++right_item;
    }
    return ordered_compare(left.size(), right.size());
}

int compare_values(const Value& left, const Value& right) {
    if (left.is_number() && right.is_number()) { return compare_floats(static_cast<float>(left.number()), static_cast<float>(right.number())); }
    const int kind_comparison = ordered_compare(left.kind(), right.kind());
    if (kind_comparison != 0) { return kind_comparison; }
    const Value::Storage& left_storage = left.storage();
    const Value::Storage& right_storage = right.storage();
    switch (left.kind()) {
    case ScalarKind::null_value: return 0;
    case ScalarKind::signed_integer: return ordered_compare(std::get<std::int32_t>(left_storage), std::get<std::int32_t>(right_storage));
    case ScalarKind::unsigned_integer: return ordered_compare(std::get<std::uint32_t>(left_storage), std::get<std::uint32_t>(right_storage));
    case ScalarKind::floating_point: return compare_floats(std::get<float>(left_storage), std::get<float>(right_storage));
    case ScalarKind::boolean: return ordered_compare(std::get<bool>(left_storage), std::get<bool>(right_storage));
    case ScalarKind::text: return ordered_compare(std::get<std::string>(left_storage), std::get<std::string>(right_storage));
    case ScalarKind::vector3: {
        const Vec3& left_value = std::get<Vec3>(left_storage);
        const Vec3& right_value = std::get<Vec3>(right_storage);
        if (const int comparison = compare_floats(left_value.x, right_value.x); comparison != 0) { return comparison; }
        if (const int comparison = compare_floats(left_value.y, right_value.y); comparison != 0) { return comparison; }
        return compare_floats(left_value.z, right_value.z);
    }
    case ScalarKind::sequence: return compare_ranges(std::get<std::shared_ptr<Sequence>>(left_storage)->values, std::get<std::shared_ptr<Sequence>>(right_storage)->values);
    case ScalarKind::linked_sequence: return compare_ranges(std::get<std::shared_ptr<LinkedSequence>>(left_storage)->values, std::get<std::shared_ptr<LinkedSequence>>(right_storage)->values);
    case ScalarKind::ordered_map: {
        const auto& left_values = std::get<std::shared_ptr<OrderedMap>>(left_storage)->values;
        const auto& right_values = std::get<std::shared_ptr<OrderedMap>>(right_storage)->values;
        auto left_item = left_values.begin();
        auto right_item = right_values.begin();
        while (left_item != left_values.end() && right_item != right_values.end()) {
            if (const int comparison = compare_values(left_item->first, right_item->first); comparison != 0) { return comparison; }
            if (const int comparison = compare_values(left_item->second, right_item->second); comparison != 0) { return comparison; }
            ++left_item;
            ++right_item;
        }
        return ordered_compare(left_values.size(), right_values.size());
    }
    case ScalarKind::ordered_set: return compare_ranges(std::get<std::shared_ptr<OrderedSet>>(left_storage)->values, std::get<std::shared_ptr<OrderedSet>>(right_storage)->values);
    }
    throw std::logic_error("Unknown script value kind");
}

Value number_result(const Value& left, const Value& right, double value) {
    if (left.kind() == ScalarKind::floating_point || right.kind() == ScalarKind::floating_point) { return Value(static_cast<float>(value)); }
    if (left.kind() == ScalarKind::unsigned_integer && right.kind() == ScalarKind::unsigned_integer) { return Value(static_cast<std::uint32_t>(value)); }
    return Value(static_cast<std::int32_t>(value));
}

std::size_t checked_index(const Value& key, std::size_t collection_size) {
    const std::int64_t index = key.integer();
    if (index < 0 || static_cast<std::uint64_t>(index) >= collection_size) { throw std::out_of_range("Script collection index is out of range"); }
    return static_cast<std::size_t>(index);
}

} // namespace

Value::Value(std::int32_t value) : storage_(value) {}
Value::Value(std::uint32_t value) : storage_(value) {}
Value::Value(float value) : storage_(value) {}
Value::Value(bool value) : storage_(value) {}
Value::Value(std::string value) : storage_(std::move(value)) {}
Value::Value(std::string_view value) : storage_(std::string(value)) {}
Value::Value(const char* value) : storage_(std::string(value ? value : "")) {}
Value::Value(Vec3 value) : storage_(value) {}
Value::Value(Storage storage) : storage_(std::move(storage)) {}

Value Value::sequence() { return Value(std::make_shared<Sequence>()); }
Value Value::linked_sequence() { return Value(std::make_shared<LinkedSequence>()); }
Value Value::ordered_map() { return Value(std::make_shared<OrderedMap>()); }
Value Value::ordered_set() { return Value(std::make_shared<OrderedSet>()); }

ScalarKind Value::kind() const noexcept {
    return static_cast<ScalarKind>(storage_.index());
}

bool Value::is_number() const noexcept {
    return kind() == ScalarKind::signed_integer || kind() == ScalarKind::unsigned_integer || kind() == ScalarKind::floating_point || kind() == ScalarKind::boolean;
}

double Value::number() const {
    switch (kind()) {
    case ScalarKind::signed_integer: return std::get<std::int32_t>(storage_);
    case ScalarKind::unsigned_integer: return std::get<std::uint32_t>(storage_);
    case ScalarKind::floating_point: return std::get<float>(storage_);
    case ScalarKind::boolean: return std::get<bool>(storage_) ? 1.0 : 0.0;
    default: throw std::invalid_argument("Script value is not numeric");
    }
}

std::int64_t Value::integer() const {
    switch (kind()) {
    case ScalarKind::signed_integer: return std::get<std::int32_t>(storage_);
    case ScalarKind::unsigned_integer: return std::get<std::uint32_t>(storage_);
    case ScalarKind::floating_point: return static_cast<std::int64_t>(std::get<float>(storage_));
    case ScalarKind::boolean: return std::get<bool>(storage_) ? 1 : 0;
    default: throw std::invalid_argument("Script value is not integral");
    }
}

bool Value::truthy() const noexcept {
    switch (kind()) {
    case ScalarKind::null_value: return false;
    case ScalarKind::signed_integer: return std::get<std::int32_t>(storage_) != 0;
    case ScalarKind::unsigned_integer: return std::get<std::uint32_t>(storage_) != 0u;
    case ScalarKind::floating_point: return std::get<float>(storage_) != 0.0f;
    case ScalarKind::boolean: return std::get<bool>(storage_);
    case ScalarKind::text: return !std::get<std::string>(storage_).empty();
    case ScalarKind::vector3: {
        const Vec3& value = std::get<Vec3>(storage_);
        return value.x != 0.0f || value.y != 0.0f || value.z != 0.0f;
    }
    case ScalarKind::sequence: return !std::get<std::shared_ptr<Sequence>>(storage_)->values.empty();
    case ScalarKind::linked_sequence: return !std::get<std::shared_ptr<LinkedSequence>>(storage_)->values.empty();
    case ScalarKind::ordered_map: return !std::get<std::shared_ptr<OrderedMap>>(storage_)->values.empty();
    case ScalarKind::ordered_set: return !std::get<std::shared_ptr<OrderedSet>>(storage_)->values.empty();
    }
    return false;
}

std::string Value::text() const {
    switch (kind()) {
    case ScalarKind::null_value: return {};
    case ScalarKind::signed_integer: return std::to_string(std::get<std::int32_t>(storage_));
    case ScalarKind::unsigned_integer: return std::to_string(std::get<std::uint32_t>(storage_));
    case ScalarKind::floating_point: {
        std::ostringstream output;
        output << std::get<float>(storage_);
        return output.str();
    }
    case ScalarKind::boolean: return std::get<bool>(storage_) ? "true" : "false";
    case ScalarKind::text: return std::get<std::string>(storage_);
    case ScalarKind::vector3: {
        const Vec3& value = std::get<Vec3>(storage_);
        std::ostringstream output;
        output << value.x << ',' << value.y << ',' << value.z;
        return output.str();
    }
    case ScalarKind::sequence: return "sequence[" + std::to_string(std::get<std::shared_ptr<Sequence>>(storage_)->values.size()) + ']';
    case ScalarKind::linked_sequence: return "list[" + std::to_string(std::get<std::shared_ptr<LinkedSequence>>(storage_)->values.size()) + ']';
    case ScalarKind::ordered_map: return "map[" + std::to_string(std::get<std::shared_ptr<OrderedMap>>(storage_)->values.size()) + ']';
    case ScalarKind::ordered_set: return "set[" + std::to_string(std::get<std::shared_ptr<OrderedSet>>(storage_)->values.size()) + ']';
    }
    return {};
}

const Value::Storage& Value::storage() const noexcept { return storage_; }
Value::Storage& Value::storage() noexcept { return storage_; }

bool ValueLess::operator()(const Value& left, const Value& right) const {
    return compare_values(left, right) < 0;
}

Value apply(Operator operation, const Value& left, const Value& right) {
    if (operation == Operator::equal || operation == Operator::not_equal) {
        const bool equal = compare_values(left, right) == 0;
        return Value(operation == Operator::equal ? equal : !equal);
    }
    if (operation == Operator::less || operation == Operator::less_equal || operation == Operator::greater || operation == Operator::greater_equal) {
        const int comparison = compare_values(left, right);
        if (operation == Operator::less) { return Value(comparison < 0); }
        if (operation == Operator::less_equal) { return Value(comparison <= 0); }
        if (operation == Operator::greater) { return Value(comparison > 0); }
        return Value(comparison >= 0);
    }
    if (operation == Operator::logical_and) { return Value(left.truthy() && right.truthy()); }
    if (operation == Operator::logical_or) { return Value(left.truthy() || right.truthy()); }
    if (operation == Operator::add && (left.kind() == ScalarKind::text || right.kind() == ScalarKind::text)) { return Value(left.text() + right.text()); }
    if (operation == Operator::add && left.kind() == ScalarKind::sequence && right.kind() == ScalarKind::sequence) {
        Value result = Value::sequence();
        auto& destination = std::get<std::shared_ptr<Sequence>>(result.storage())->values;
        const auto& left_values = std::get<std::shared_ptr<Sequence>>(left.storage())->values;
        const auto& right_values = std::get<std::shared_ptr<Sequence>>(right.storage())->values;
        destination.reserve(left_values.size() + right_values.size());
        destination.insert(destination.end(), left_values.begin(), left_values.end());
        destination.insert(destination.end(), right_values.begin(), right_values.end());
        return result;
    }
    if ((operation == Operator::add || operation == Operator::subtract) && left.kind() == ScalarKind::vector3 && right.kind() == ScalarKind::vector3) {
        const Vec3& left_value = std::get<Vec3>(left.storage());
        const Vec3& right_value = std::get<Vec3>(right.storage());
        const float direction = operation == Operator::add ? 1.0f : -1.0f;
        return Value(Vec3{left_value.x + direction * right_value.x, left_value.y + direction * right_value.y, left_value.z + direction * right_value.z});
    }
    if (!left.is_number() || !right.is_number()) { throw std::invalid_argument("Script operator is not defined for these value kinds"); }
    const double left_number = left.number();
    const double right_number = right.number();
    switch (operation) {
    case Operator::add: return number_result(left, right, left_number + right_number);
    case Operator::subtract: return number_result(left, right, left_number - right_number);
    case Operator::multiply: return number_result(left, right, left_number * right_number);
    case Operator::divide:
        if (right_number == 0.0) { throw std::domain_error("Script division by zero"); }
        return number_result(left, right, left_number / right_number);
    case Operator::remainder: {
        const std::int64_t divisor = right.integer();
        if (divisor == 0) { throw std::domain_error("Script remainder by zero"); }
        return Value(static_cast<std::int32_t>(left.integer() % divisor));
    }
    case Operator::bit_and: return Value(static_cast<std::int32_t>(left.integer() & right.integer()));
    case Operator::bit_or: return Value(static_cast<std::int32_t>(left.integer() | right.integer()));
    case Operator::bit_xor: return Value(static_cast<std::int32_t>(left.integer() ^ right.integer()));
    case Operator::shift_left: return Value(static_cast<std::int32_t>(left.integer() << (right.integer() & 31)));
    case Operator::shift_right: return Value(static_cast<std::int32_t>(left.integer() >> (right.integer() & 31)));
    default: break;
    }
    throw std::invalid_argument("Unsupported script operator");
}

Value negate(const Value& value) {
    if (value.kind() == ScalarKind::vector3) {
        const Vec3& vector = std::get<Vec3>(value.storage());
        return Value(Vec3{-vector.x, -vector.y, -vector.z});
    }
    if (!value.is_number()) { throw std::invalid_argument("Script negation requires a number or vector"); }
    if (value.kind() == ScalarKind::floating_point) { return Value(-std::get<float>(value.storage())); }
    return Value(static_cast<std::int32_t>(-value.integer()));
}

Value logical_not(const Value& value) { return Value(!value.truthy()); }

std::optional<Value> find(const Value& collection, const Value& key) {
    switch (collection.kind()) {
    case ScalarKind::sequence: {
        const auto& values = std::get<std::shared_ptr<Sequence>>(collection.storage())->values;
        return values[checked_index(key, values.size())];
    }
    case ScalarKind::linked_sequence: {
        const auto& values = std::get<std::shared_ptr<LinkedSequence>>(collection.storage())->values;
        auto found = values.begin();
        std::advance(found, checked_index(key, values.size()));
        return *found;
    }
    case ScalarKind::ordered_map: {
        const auto& values = std::get<std::shared_ptr<OrderedMap>>(collection.storage())->values;
        const auto found = values.find(key);
        return found == values.end() ? std::nullopt : std::optional<Value>(found->second);
    }
    case ScalarKind::ordered_set: {
        const auto& values = std::get<std::shared_ptr<OrderedSet>>(collection.storage())->values;
        const auto found = values.find(key);
        return found == values.end() ? std::nullopt : std::optional<Value>(*found);
    }
    default: return std::nullopt;
    }
}

void assign(Value& collection, Value key, Value value) {
    switch (collection.kind()) {
    case ScalarKind::sequence: {
        auto& values = std::get<std::shared_ptr<Sequence>>(collection.storage())->values;
        const std::int64_t index = key.integer();
        if (index < 0) { throw std::out_of_range("Negative script sequence index"); }
        if (static_cast<std::size_t>(index) >= values.size()) { values.resize(static_cast<std::size_t>(index) + 1u); }
        values[static_cast<std::size_t>(index)] = std::move(value);
        return;
    }
    case ScalarKind::linked_sequence: {
        auto& values = std::get<std::shared_ptr<LinkedSequence>>(collection.storage())->values;
        const std::int64_t index = key.integer();
        if (index < 0 || static_cast<std::size_t>(index) > values.size()) { throw std::out_of_range("Script list index is out of range"); }
        auto position = values.begin();
        std::advance(position, static_cast<std::size_t>(index));
        if (position == values.end()) { values.push_back(std::move(value)); }
        else { *position = std::move(value); }
        return;
    }
    case ScalarKind::ordered_map: std::get<std::shared_ptr<OrderedMap>>(collection.storage())->values.insert_or_assign(std::move(key), std::move(value)); return;
    case ScalarKind::ordered_set: std::get<std::shared_ptr<OrderedSet>>(collection.storage())->values.insert(std::move(value)); return;
    default: throw std::invalid_argument("Script assignment requires a collection");
    }
}

bool erase(Value& collection, const Value& key) {
    switch (collection.kind()) {
    case ScalarKind::sequence: {
        auto& values = std::get<std::shared_ptr<Sequence>>(collection.storage())->values;
        const std::size_t index = checked_index(key, values.size());
        values.erase(values.begin() + static_cast<std::ptrdiff_t>(index));
        return true;
    }
    case ScalarKind::linked_sequence: {
        auto& values = std::get<std::shared_ptr<LinkedSequence>>(collection.storage())->values;
        auto position = values.begin();
        std::advance(position, checked_index(key, values.size()));
        values.erase(position);
        return true;
    }
    case ScalarKind::ordered_map: return std::get<std::shared_ptr<OrderedMap>>(collection.storage())->values.erase(key) != 0u;
    case ScalarKind::ordered_set: return std::get<std::shared_ptr<OrderedSet>>(collection.storage())->values.erase(key) != 0u;
    default: return false;
    }
}

std::size_t size(const Value& collection) noexcept {
    switch (collection.kind()) {
    case ScalarKind::text: return std::get<std::string>(collection.storage()).size();
    case ScalarKind::sequence: return std::get<std::shared_ptr<Sequence>>(collection.storage())->values.size();
    case ScalarKind::linked_sequence: return std::get<std::shared_ptr<LinkedSequence>>(collection.storage())->values.size();
    case ScalarKind::ordered_map: return std::get<std::shared_ptr<OrderedMap>>(collection.storage())->values.size();
    case ScalarKind::ordered_set: return std::get<std::shared_ptr<OrderedSet>>(collection.storage())->values.size();
    default: return 0u;
    }
}

void VirtualMachine::set_program(std::vector<Instruction> program, std::vector<Value> constants) {
    program_ = std::move(program);
    constants_ = std::move(constants);
    stack_.clear();
    instruction_pointer_ = 0u;
    halted_ = program_.empty();
}

void VirtualMachine::register_procedure(std::uint32_t identifier, Procedure procedure) { procedures_.insert_or_assign(identifier, std::move(procedure)); }
void VirtualMachine::set_variable(std::uint32_t identifier, Value value) { variables_.insert_or_assign(identifier, std::move(value)); }

const Value* VirtualMachine::variable(std::uint32_t identifier) const noexcept {
    const auto found = variables_.find(identifier);
    return found == variables_.end() ? nullptr : &found->second;
}

void VirtualMachine::push(Value value) { stack_.push_back(std::move(value)); }

Value VirtualMachine::pop() {
    if (stack_.empty()) { throw std::underflow_error("Script operand stack is empty"); }
    Value value = std::move(stack_.back());
    stack_.pop_back();
    return value;
}

bool VirtualMachine::step() {
    if (halted_) { return false; }
    if (instruction_pointer_ >= program_.size()) { halted_ = true; return false; }
    const Instruction instruction = program_[instruction_pointer_++];
    switch (instruction.opcode) {
    case OpCode::push_constant:
        if (instruction.operand >= constants_.size()) { throw std::out_of_range("Script constant index is out of range"); }
        push(constants_[instruction.operand]);
        break;
    case OpCode::load_variable: {
        const Value* value = variable(instruction.operand);
        if (!value) { throw std::out_of_range("Script variable is not defined"); }
        push(*value);
        break;
    }
    case OpCode::store_variable: set_variable(instruction.operand, pop()); break;
    case OpCode::binary: {
        Value right = pop();
        Value left = pop();
        push(apply(instruction.operation, left, right));
        break;
    }
    case OpCode::unary_negate: push(negate(pop())); break;
    case OpCode::unary_not: push(logical_not(pop())); break;
    case OpCode::call: {
        const std::uint32_t identifier = instruction.operand & 0x00ffffffu;
        const std::size_t argument_count = instruction.operand >> 24u;
        if (argument_count > stack_.size()) { throw std::underflow_error("Script call has too few arguments"); }
        const auto found = procedures_.find(identifier);
        if (found == procedures_.end()) { throw std::out_of_range("Script procedure is not registered"); }
        const std::size_t first_argument = stack_.size() - argument_count;
        Value result = found->second(std::span<const Value>(stack_.data() + first_argument, argument_count));
        stack_.resize(first_argument);
        push(std::move(result));
        break;
    }
    case OpCode::jump:
        if (instruction.operand >= program_.size()) { throw std::out_of_range("Script jump target is out of range"); }
        instruction_pointer_ = instruction.operand;
        break;
    case OpCode::jump_if_false: {
        const bool condition = pop().truthy();
        if (!condition) {
            if (instruction.operand >= program_.size()) { throw std::out_of_range("Script branch target is out of range"); }
            instruction_pointer_ = instruction.operand;
        }
        break;
    }
    case OpCode::discard: static_cast<void>(pop()); break;
    case OpCode::halt: halted_ = true; break;
    }
    return !halted_;
}

void VirtualMachine::run(std::size_t instruction_budget) {
    while (!halted_ && instruction_budget-- != 0u) { step(); }
    if (!halted_) { throw std::runtime_error("Script instruction budget exhausted"); }
}

bool VirtualMachine::halted() const noexcept { return halted_; }
std::size_t VirtualMachine::instruction_pointer() const noexcept { return instruction_pointer_; }
const std::vector<Value>& VirtualMachine::stack() const noexcept { return stack_; }

} // namespace script

namespace network {
namespace {

void append_u16(std::vector<std::uint8_t>& bytes, std::uint16_t value) {
    bytes.push_back(static_cast<std::uint8_t>(value));
    bytes.push_back(static_cast<std::uint8_t>(value >> 8u));
}

std::uint16_t read_u16(const std::uint8_t* bytes) noexcept {
    return static_cast<std::uint16_t>(bytes[0]) | static_cast<std::uint16_t>(bytes[1]) << 8u;
}

} // namespace

PacketQueue::PacketQueue(std::size_t capacity) : capacity_(capacity) { bytes_.reserve(capacity); }

bool PacketQueue::enqueue(std::uint16_t opcode, std::span<const std::uint8_t> payload, std::uint16_t sequence_increment, std::uint16_t checksum_seed) {
    if (payload.size() > std::numeric_limits<std::uint16_t>::max() - sizeof(PacketHeader)) { return false; }
    const std::uint16_t packet_size = static_cast<std::uint16_t>(payload.size() + sizeof(PacketHeader));
    if (packet_size > capacity_ - std::min(capacity_, bytes_.size())) { return false; }
    sequence_ = static_cast<std::uint16_t>(sequence_ + sequence_increment);
    const std::size_t packet_begin = bytes_.size();
    append_u16(bytes_, packet_size);
    append_u16(bytes_, 0u);
    append_u16(bytes_, sequence_);
    append_u16(bytes_, opcode);
    bytes_.insert(bytes_.end(), payload.begin(), payload.end());
    std::uint16_t sum = 0u;
    for (std::size_t index = packet_begin + 4u; index < bytes_.size(); ++index) { sum = static_cast<std::uint16_t>(sum + bytes_[index]); }
    const std::uint16_t checksum = static_cast<std::uint16_t>(checksum_seed ^ sum);
    bytes_[packet_begin + 2u] = static_cast<std::uint8_t>(checksum);
    bytes_[packet_begin + 3u] = static_cast<std::uint8_t>(checksum >> 8u);
    ++packet_count_;
    return true;
}

std::span<const std::uint8_t> PacketQueue::pending() const noexcept { return bytes_; }

void PacketQueue::consume(std::size_t byte_count) {
    byte_count = std::min(byte_count, bytes_.size());
    std::size_t consumed_packets = 0u;
    std::size_t cursor = 0u;
    while (cursor + sizeof(PacketHeader) <= byte_count) {
        const std::uint16_t packet_size = read_u16(bytes_.data() + cursor);
        if (packet_size < sizeof(PacketHeader) || cursor + packet_size > byte_count) { break; }
        cursor += packet_size;
        ++consumed_packets;
    }
    bytes_.erase(bytes_.begin(), bytes_.begin() + static_cast<std::ptrdiff_t>(byte_count));
    packet_count_ -= std::min(packet_count_, consumed_packets);
}

void PacketQueue::clear() noexcept { bytes_.clear(); packet_count_ = 0u; }
std::size_t PacketQueue::packet_count() const noexcept { return packet_count_; }

PacketStream::PacketStream(std::size_t capacity) : capacity_(capacity) { bytes_.reserve(capacity); }

bool PacketStream::append(std::span<const std::uint8_t> bytes) {
    if (bytes.size() > capacity_ - std::min(capacity_, bytes_.size())) { return false; }
    bytes_.insert(bytes_.end(), bytes.begin(), bytes.end());
    return true;
}

std::optional<Packet> PacketStream::next() {
    if (bytes_.size() < sizeof(PacketHeader)) { return std::nullopt; }
    Packet packet;
    packet.header.size = read_u16(bytes_.data());
    packet.header.checksum = read_u16(bytes_.data() + 2u);
    packet.header.sequence = read_u16(bytes_.data() + 4u);
    packet.header.opcode = read_u16(bytes_.data() + 6u);
    if (packet.header.size < sizeof(PacketHeader) || packet.header.size > capacity_) { throw std::runtime_error("Invalid network packet size"); }
    if (bytes_.size() < packet.header.size) { return std::nullopt; }
    packet.payload.assign(bytes_.begin() + static_cast<std::ptrdiff_t>(sizeof(PacketHeader)), bytes_.begin() + packet.header.size);
    bytes_.erase(bytes_.begin(), bytes_.begin() + packet.header.size);
    return packet;
}

void PacketStream::clear() noexcept { bytes_.clear(); }

void ConnectionSession::begin(std::string host, std::uint16_t port) {
    if (host.empty() || port == 0u) { throw std::invalid_argument("Connection endpoint is incomplete"); }
    host_ = std::move(host);
    port_ = port;
    peer_identifier_ = 0u;
    checksum_seed_ = 0u;
    error_.clear();
    state_ = ConnectionState::connecting;
}

void ConnectionSession::accept_handshake(std::uint32_t peer_identifier, std::uint16_t checksum_seed) {
    if (state_ != ConnectionState::connecting && state_ != ConnectionState::handshaking) { throw std::logic_error("Handshake arrived in an invalid connection state"); }
    peer_identifier_ = peer_identifier;
    checksum_seed_ = checksum_seed;
    state_ = ConnectionState::handshaking;
}

void ConnectionSession::mark_connected() noexcept { if (state_ == ConnectionState::handshaking || state_ == ConnectionState::connecting) { state_ = ConnectionState::connected; } }
void ConnectionSession::fail(std::string reason) { error_ = std::move(reason); state_ = ConnectionState::failed; }
void ConnectionSession::close() noexcept { state_ = ConnectionState::stopped; peer_identifier_ = 0u; checksum_seed_ = 0u; }
ConnectionState ConnectionSession::state() const noexcept { return state_; }
const std::string& ConnectionSession::host() const noexcept { return host_; }
std::uint16_t ConnectionSession::port() const noexcept { return port_; }
std::uint32_t ConnectionSession::peer_identifier() const noexcept { return peer_identifier_; }
std::uint16_t ConnectionSession::checksum_seed() const noexcept { return checksum_seed_; }
const std::string& ConnectionSession::error() const noexcept { return error_; }

} // namespace network

namespace assets {
namespace {

constexpr std::array<std::uint32_t, 256> build_crc_table() noexcept {
    std::array<std::uint32_t, 256> table{};
    for (std::uint32_t index = 0; index < table.size(); ++index) {
        std::uint32_t value = index;
        for (unsigned bit = 0; bit < 8u; ++bit) { value = (value >> 1u) ^ (0xedb88320u & (0u - (value & 1u))); }
        table[index] = value;
    }
    return table;
}

constexpr auto kCrcTable = build_crc_table();

void crc_append_u32(std::uint32_t& checksum, std::uint32_t value) noexcept {
    for (unsigned byte = 0; byte < 4u; ++byte) {
        checksum = checksum >> 8u ^ kCrcTable[(checksum ^ value) & 0xffu];
        value >>= 8u;
    }
}

bool wildcard_match(std::string_view pattern, std::string_view text) noexcept {
    std::size_t pattern_index = 0u;
    std::size_t text_index = 0u;
    std::size_t star = std::string_view::npos;
    std::size_t retry = 0u;
    const auto equal_ascii = [](char left, char right) { return std::tolower(static_cast<unsigned char>(left)) == std::tolower(static_cast<unsigned char>(right)); };
    while (text_index < text.size()) {
        if (pattern_index < pattern.size() && (pattern[pattern_index] == '?' || equal_ascii(pattern[pattern_index], text[text_index]))) { ++pattern_index; ++text_index; continue; }
        if (pattern_index < pattern.size() && pattern[pattern_index] == '*') { star = pattern_index++; retry = text_index; continue; }
        if (star != std::string_view::npos) { pattern_index = star + 1u; text_index = ++retry; continue; }
        return false;
    }
    while (pattern_index < pattern.size() && pattern[pattern_index] == '*') { ++pattern_index; }
    return pattern_index == pattern.size();
}

std::uint32_t file_timestamp(const std::filesystem::directory_entry& entry) noexcept {
    std::error_code error;
    const auto value = entry.last_write_time(error);
    if (error) { return 0u; }
    const auto ticks = value.time_since_epoch().count();
    return static_cast<std::uint32_t>(static_cast<std::uint64_t>(ticks));
}

} // namespace

std::uint32_t crc32(std::span<const std::uint8_t> bytes, std::uint32_t initial) noexcept {
    std::uint32_t checksum = initial;
    for (const std::uint8_t value : bytes) { checksum = checksum >> 8u ^ kCrcTable[(checksum ^ value) & 0xffu]; }
    return checksum;
}

std::uint32_t manifest_checksum(std::string_view relative_path, std::uint32_t size, std::uint32_t timestamp) noexcept {
    std::uint32_t checksum = 0u;
    for (char value : relative_path) {
        const auto lower = static_cast<std::uint8_t>(std::tolower(static_cast<unsigned char>(value)));
        checksum = checksum >> 8u ^ kCrcTable[(checksum ^ lower) & 0xffu];
    }
    crc_append_u32(checksum, size);
    crc_append_u32(checksum, timestamp);
    return checksum;
}

std::vector<std::filesystem::path> split_search_path(std::string_view search_path) {
    std::vector<std::filesystem::path> result;
    std::size_t begin = 0u;
    while (begin <= search_path.size()) {
        const std::size_t end = search_path.find(';', begin);
        const std::string_view item = search_path.substr(begin, end == std::string_view::npos ? search_path.size() - begin : end - begin);
        if (!item.empty()) { result.emplace_back(item); }
        if (end == std::string_view::npos) { break; }
        begin = end + 1u;
    }
    return result;
}

std::vector<ManifestEntry> scan_manifest(const std::filesystem::path& root, std::string_view wildcard, std::size_t pause_after, const std::function<void()>& pause) {
    std::vector<ManifestEntry> result;
    std::error_code error;
    if (!std::filesystem::is_directory(root, error)) { return result; }
    std::size_t since_pause = 0u;
    for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(root, error)) {
        if (error) { break; }
        if (!entry.is_regular_file(error) || !wildcard_match(wildcard, entry.path().filename().string())) { continue; }
        const std::uint64_t size64 = entry.file_size(error);
        if (error) { error.clear(); continue; }
        const std::uint32_t size = static_cast<std::uint32_t>(std::min<std::uint64_t>(size64, std::numeric_limits<std::uint32_t>::max()));
        const std::uint32_t timestamp = file_timestamp(entry);
        const std::filesystem::path relative = entry.path().lexically_relative(root);
        result.push_back({relative, size, timestamp, manifest_checksum(relative.generic_string(), size, timestamp)});
        if (pause_after != 0u && ++since_pause >= pause_after) { if (pause) { pause(); } since_pause = 0u; }
    }
    std::sort(result.begin(), result.end(), [](const ManifestEntry& left, const ManifestEntry& right) { return left.path.generic_string() < right.path.generic_string(); });
    return result;
}

} // namespace assets

namespace character {
namespace {

std::string normalized_bone_name(std::string_view name) {
    std::string result(name);
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char value) { return static_cast<char>(std::tolower(value)); });
    return result;
}

float quaternion_dot(Quaternion left, Quaternion right) noexcept {
    return left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w;
}

} // namespace

Quaternion normalize(Quaternion value) noexcept {
    const float magnitude_squared = quaternion_dot(value, value);
    if (!(magnitude_squared > std::numeric_limits<float>::epsilon())) { return {}; }
    const float inverse_magnitude = 1.0f / std::sqrt(magnitude_squared);
    value.x *= inverse_magnitude;
    value.y *= inverse_magnitude;
    value.z *= inverse_magnitude;
    value.w *= inverse_magnitude;
    return value;
}

Quaternion interpolate(Quaternion from, Quaternion to, float amount) noexcept {
    amount = std::clamp(amount, 0.0f, 1.0f);
    from = normalize(from);
    to = normalize(to);
    float cosine = quaternion_dot(from, to);
    if (cosine < 0.0f) { cosine = -cosine; to = {-to.x, -to.y, -to.z, -to.w}; }
    if (cosine > 0.9995f) {
        return normalize({from.x + amount * (to.x - from.x), from.y + amount * (to.y - from.y), from.z + amount * (to.z - from.z), from.w + amount * (to.w - from.w)});
    }
    const float angle = std::acos(std::clamp(cosine, -1.0f, 1.0f));
    const float sine = std::sin(angle);
    const float from_weight = std::sin((1.0f - amount) * angle) / sine;
    const float to_weight = std::sin(amount * angle) / sine;
    return {from.x * from_weight + to.x * to_weight, from.y * from_weight + to.y * to_weight, from.z * from_weight + to.z * to_weight, from.w * from_weight + to.w * to_weight};
}

BonePose interpolate(const BonePose& from, const BonePose& to, float amount) noexcept {
    amount = std::clamp(amount, 0.0f, 1.0f);
    return {{from.translation.x + amount * (to.translation.x - from.translation.x), from.translation.y + amount * (to.translation.y - from.translation.y), from.translation.z + amount * (to.translation.z - from.translation.z)}, interpolate(from.rotation, to.rotation, amount)};
}

Matrix3x4 compose(const BonePose& pose) noexcept {
    const Quaternion rotation = normalize(pose.rotation);
    const float xx = rotation.x * rotation.x;
    const float yy = rotation.y * rotation.y;
    const float zz = rotation.z * rotation.z;
    const float xy = rotation.x * rotation.y;
    const float xz = rotation.x * rotation.z;
    const float yz = rotation.y * rotation.z;
    const float wx = rotation.w * rotation.x;
    const float wy = rotation.w * rotation.y;
    const float wz = rotation.w * rotation.z;
    return {{{1.0f - 2.0f * (yy + zz), 2.0f * (xy - wz), 2.0f * (xz + wy), pose.translation.x, 2.0f * (xy + wz), 1.0f - 2.0f * (xx + zz), 2.0f * (yz - wx), pose.translation.y, 2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (xx + yy), pose.translation.z}}};
}

Matrix3x4 multiply(const Matrix3x4& left, const Matrix3x4& right) noexcept {
    Matrix3x4 result;
    for (std::size_t row = 0; row < 3u; ++row) {
        for (std::size_t column = 0; column < 3u; ++column) {
            result.values[row * 4u + column] = left.values[row * 4u] * right.values[column] + left.values[row * 4u + 1u] * right.values[4u + column] + left.values[row * 4u + 2u] * right.values[8u + column];
        }
        result.values[row * 4u + 3u] = left.values[row * 4u] * right.values[3u] + left.values[row * 4u + 1u] * right.values[7u] + left.values[row * 4u + 2u] * right.values[11u] + left.values[row * 4u + 3u];
    }
    return result;
}

std::size_t Skeleton::add_bone(Bone bone) {
    if (bone.parent >= static_cast<std::int32_t>(bones_.size())) { throw std::out_of_range("Skeleton parent bone is not available"); }
    const std::string key = normalized_bone_name(bone.name);
    if (by_name_.contains(key)) { throw std::invalid_argument("Duplicate skeleton bone name"); }
    const std::size_t index = bones_.size();
    bones_.push_back(std::move(bone));
    by_name_.emplace(key, index);
    return index;
}

std::optional<std::size_t> Skeleton::find_bone(std::string_view name) const noexcept {
    const auto found = by_name_.find(normalized_bone_name(name));
    return found == by_name_.end() ? std::nullopt : std::optional<std::size_t>(found->second);
}

std::vector<Matrix3x4> Skeleton::build_matrices(std::span<const BonePose> pose) const {
    if (pose.size() != bones_.size()) { throw std::invalid_argument("Skeleton pose does not match its bone count"); }
    std::vector<Matrix3x4> result(bones_.size());
    for (std::size_t index = 0; index < bones_.size(); ++index) {
        const Matrix3x4 local = compose(pose[index]);
        result[index] = bones_[index].parent < 0 ? local : multiply(result[static_cast<std::size_t>(bones_[index].parent)], local);
    }
    return result;
}

const std::vector<Bone>& Skeleton::bones() const noexcept { return bones_; }

} // namespace character

namespace effects {

BloodEffect::BloodEffect(std::size_t maximum_marks) : maximum_marks_(maximum_marks) {}

bool BloodEffect::add(std::span<const Vec3> polygon, const Matrix3x4& transform, float lifetime, float texture_scale, float texture_offset_u, float texture_offset_v) {
    if (polygon.size() < 3u || lifetime <= 0.0f || maximum_marks_ == 0u) { return false; }
    while (marks_.size() >= maximum_marks_) { marks_.pop_front(); }
    BloodMark mark;
    mark.lifetime = lifetime;
    mark.vertices.reserve(polygon.size());
    for (const Vec3& point : polygon) {
        Vec3 transformed{};
        transform_point(&transformed, &transform, &point);
        mark.vertices.push_back({transformed, transformed.x * texture_scale + texture_offset_u, transformed.z * texture_scale + texture_offset_v});
    }
    marks_.push_back(std::move(mark));
    return true;
}

void BloodEffect::update(float elapsed_seconds) noexcept {
    if (elapsed_seconds <= 0.0f) { return; }
    for (BloodMark& mark : marks_) { mark.lifetime -= elapsed_seconds; }
    std::erase_if(marks_, [](const BloodMark& mark) { return mark.lifetime <= 0.0f; });
}

void BloodEffect::clear() noexcept { marks_.clear(); }
const std::deque<BloodMark>& BloodEffect::marks() const noexcept { return marks_; }

std::size_t BloodEffect::vertex_count() const noexcept {
    std::size_t result = 0u;
    for (const BloodMark& mark : marks_) { result += mark.vertices.size(); }
    return result;
}

} // namespace effects

namespace render {

ResourceHandle ResourceRegistry::add(ResourceDescription description) {
    if (description.name.empty()) { throw std::invalid_argument("Render resource requires a name"); }
    const ResourceHandle handle{next_identifier_++};
    resources_.emplace(handle.value, std::move(description));
    return handle;
}

bool ResourceRegistry::remove(ResourceHandle handle) noexcept { return resources_.erase(handle.value) != 0u; }

const ResourceDescription* ResourceRegistry::find(ResourceHandle handle) const noexcept {
    const auto found = resources_.find(handle.value);
    return found == resources_.end() ? nullptr : &found->second;
}

std::vector<ResourceHandle> ResourceRegistry::unmanaged_resources() const {
    std::vector<ResourceHandle> result;
    for (const auto& [identifier, resource] : resources_) { if (!resource.managed) { result.push_back({identifier}); } }
    std::sort(result.begin(), result.end(), [](ResourceHandle left, ResourceHandle right) { return left.value < right.value; });
    return result;
}

void ResourceRegistry::clear_unmanaged() {
    std::erase_if(resources_, [](const auto& item) { return !item.second.managed; });
}

std::size_t ResourceRegistry::size() const noexcept { return resources_.size(); }

std::size_t RenderStateKeyHash::operator()(RenderStateKey key) const noexcept {
    return static_cast<std::size_t>(key.category) << 16u | key.slot;
}

StateCache::StateCache(Apply apply) : apply_(std::move(apply)) {}

bool StateCache::set(RenderStateKey key, std::uint32_t value) {
    const auto found = values_.find(key);
    if (found != values_.end() && found->second == value) { return false; }
    values_.insert_or_assign(key, value);
    if (apply_) { apply_(key, value); }
    return true;
}

std::optional<std::uint32_t> StateCache::get(RenderStateKey key) const noexcept {
    const auto found = values_.find(key);
    return found == values_.end() ? std::nullopt : std::optional<std::uint32_t>(found->second);
}

void StateCache::invalidate() noexcept { values_.clear(); }

ShaderProgram::ShaderProgram(std::string name) : name_(std::move(name)) {}

void ShaderProgram::set(std::string name, std::span<const float> values) {
    ShaderConstant value{std::move(name), std::vector<float>(values.begin(), values.end())};
    constants_.insert_or_assign(value.name, std::move(value));
}

const ShaderConstant* ShaderProgram::constant(std::string_view name) const noexcept {
    const auto found = constants_.find(std::string(name));
    return found == constants_.end() ? nullptr : &found->second;
}

const std::string& ShaderProgram::name() const noexcept { return name_; }

void PostEffects::append(PostEffectPass pass) {
    if (pass.shader.empty()) { throw std::invalid_argument("Post-effect pass requires a shader"); }
    passes_.push_back(std::move(pass));
}

std::optional<PostEffectPass> PostEffects::take_next() {
    if (passes_.empty()) { return std::nullopt; }
    PostEffectPass result = std::move(passes_.front());
    passes_.pop_front();
    return result;
}

void PostEffects::clear() noexcept { passes_.clear(); }
std::size_t PostEffects::size() const noexcept { return passes_.size(); }

} // namespace render

namespace service {

void MemoryTracker::register_allocation(void* pointer, Record record) {
    if (!pointer) { throw std::invalid_argument("Cannot track a null allocation"); }
    std::lock_guard lock(mutex_);
    if (allocations_.contains(pointer)) { throw std::logic_error("Allocation is already tracked"); }
    allocated_bytes_ += record.size;
    allocations_.emplace(pointer, std::move(record));
}

std::optional<MemoryTracker::Record> MemoryTracker::release(void* pointer) {
    if (!pointer) { return std::nullopt; }
    std::lock_guard lock(mutex_);
    const auto found = allocations_.find(pointer);
    if (found == allocations_.end()) { return std::nullopt; }
    Record result = std::move(found->second);
    allocated_bytes_ -= result.size;
    allocations_.erase(found);
    return result;
}

std::optional<MemoryTracker::Record> MemoryTracker::find(const void* pointer) const {
    std::lock_guard lock(mutex_);
    const auto found = allocations_.find(pointer);
    return found == allocations_.end() ? std::nullopt : std::optional<Record>(found->second);
}

std::size_t MemoryTracker::allocation_count() const noexcept {
    std::lock_guard lock(mutex_);
    return allocations_.size();
}

std::size_t MemoryTracker::allocated_bytes() const noexcept {
    std::lock_guard lock(mutex_);
    return allocated_bytes_;
}

bool FileImage::open(const std::filesystem::path& path) {
    close();
    std::ifstream input(path, std::ios::binary);
    if (!input.is_open()) { return false; }
    input.seekg(0, std::ios::end);
    const std::streamoff length = input.tellg();
    if (length < 0) { return false; }
    input.seekg(0, std::ios::beg);
    std::vector<std::uint8_t> bytes(static_cast<std::size_t>(length));
    if (!bytes.empty()) { input.read(reinterpret_cast<char*>(bytes.data()), static_cast<std::streamsize>(bytes.size())); }
    if (!input && !bytes.empty()) { return false; }
    path_ = path;
    bytes_ = std::move(bytes);
    return true;
}

void FileImage::close() noexcept { path_.clear(); bytes_.clear(); }
bool FileImage::is_open() const noexcept { return !path_.empty(); }
std::span<const std::uint8_t> FileImage::bytes() const noexcept { return bytes_; }
const std::filesystem::path& FileImage::path() const noexcept { return path_; }

AntifloodQueue::AntifloodQueue(std::chrono::milliseconds interval) : interval_(interval) {
    if (interval_ < std::chrono::milliseconds::zero()) { throw std::invalid_argument("Antiflood interval cannot be negative"); }
}

bool AntifloodQueue::accept(std::string_view message, std::chrono::steady_clock::time_point now) {
    Entry& entry = entries_[std::string(message)];
    if (entry.last != std::chrono::steady_clock::time_point{} && now - entry.last < interval_) { ++entry.suppressed; return false; }
    entry.last = now;
    return true;
}

std::size_t AntifloodQueue::suppressed(std::string_view message) const noexcept {
    const auto found = entries_.find(std::string(message));
    return found == entries_.end() ? 0u : found->second.suppressed;
}

void AntifloodQueue::clear() noexcept { entries_.clear(); }

} // namespace service

namespace {

std::string canonical_name(std::string_view value) {
    std::string result(value);
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char character) { return static_cast<char>(std::tolower(character)); });
    return result;
}

float squared_distance(Vec3 left, Vec3 right) noexcept {
    const float x = left.x - right.x;
    const float y = left.y - right.y;
    const float z = left.z - right.z;
    return x * x + y * y + z * z;
}

} // namespace

namespace effect_runtime {

bool TimeRange::contains(float time) const noexcept { return time >= begin && time < end; }
float TimeRange::duration() const noexcept { return std::max(0.0f, end - begin); }

bool ScriptedEffectDefinition::valid() const noexcept {
    if (name.empty() || !std::isfinite(time_limit) || time_limit < 0.0f) { return false; }
    return std::all_of(parts.begin(), parts.end(), [this](const PartDefinition& part) {
        return !part.resource.empty() && std::isfinite(part.time.begin) && std::isfinite(part.time.end) && part.time.begin >= 0.0f && part.time.end >= part.time.begin && (time_limit == 0.0f || part.time.end <= time_limit) && std::isfinite(part.scale) && part.scale > 0.0f;
    });
}

float ScriptedEffectDefinition::duration() const noexcept {
    float result = time_limit;
    for (const PartDefinition& part : parts) { result = std::max(result, part.time.end); }
    return result;
}

bool EffectLibrary::store(ScriptedEffectDefinition definition, bool replace) {
    if (!definition.valid()) { return false; }
    const std::string key = canonical_name(definition.name);
    if (!replace && definitions_.contains(key)) { return false; }
    definitions_.insert_or_assign(key, std::make_shared<const ScriptedEffectDefinition>(std::move(definition)));
    return true;
}

bool EffectLibrary::erase(std::string_view name) { return definitions_.erase(canonical_name(name)) != 0u; }

std::shared_ptr<const ScriptedEffectDefinition> EffectLibrary::resolve(std::string_view name) const noexcept {
    const auto found = definitions_.find(canonical_name(name));
    return found == definitions_.end() ? nullptr : found->second;
}

std::vector<std::string> EffectLibrary::names() const {
    std::vector<std::string> result;
    result.reserve(definitions_.size());
    for (const auto& [key, definition] : definitions_) { result.push_back(definition->name); }
    std::sort(result.begin(), result.end());
    return result;
}

std::size_t EffectLibrary::size() const noexcept { return definitions_.size(); }

EffectInstance::EffectInstance(std::uint64_t identifier, std::shared_ptr<const ScriptedEffectDefinition> definition, Vec3 origin) : identifier_(identifier), definition_(std::move(definition)), origin_(origin) {
    if (!definition_) { throw std::invalid_argument("Effect instance requires a definition"); }
}

void EffectInstance::update(float elapsed_seconds) noexcept { elapsed_ += std::max(0.0f, elapsed_seconds); }
void EffectInstance::move(Vec3 origin) noexcept { origin_ = origin; }
bool EffectInstance::finished() const noexcept { return elapsed_ >= definition_->duration(); }
std::uint64_t EffectInstance::identifier() const noexcept { return identifier_; }
std::string_view EffectInstance::name() const noexcept { return definition_->name; }

std::vector<ActivePart> EffectInstance::active_parts() const {
    std::vector<ActivePart> result;
    for (const PartDefinition& part : definition_->parts) {
        if (!part.time.contains(elapsed_)) { continue; }
        const float progress = part.time.duration() == 0.0f ? 1.0f : std::clamp((elapsed_ - part.time.begin) / part.time.duration(), 0.0f, 1.0f);
        result.push_back({part.kind, part.resource, part.attachment, {origin_.x + part.offset.x, origin_.y + part.offset.y, origin_.z + part.offset.z}, elapsed_ - part.time.begin, progress, part.scale});
    }
    return result;
}

EffectScheduler::EffectScheduler(const EffectLibrary& library) : library_(&library) {}

std::optional<std::uint64_t> EffectScheduler::spawn(std::string_view name, Vec3 origin) {
    const auto definition = library_->resolve(name);
    if (!definition) { return std::nullopt; }
    const std::uint64_t identifier = next_identifier_++;
    instances_.emplace_back(identifier, definition, origin);
    return identifier;
}

bool EffectScheduler::move(std::uint64_t identifier, Vec3 origin) noexcept {
    const auto found = std::find_if(instances_.begin(), instances_.end(), [identifier](const EffectInstance& instance) { return instance.identifier() == identifier; });
    if (found == instances_.end()) { return false; }
    found->move(origin);
    return true;
}

bool EffectScheduler::cancel(std::uint64_t identifier) noexcept {
    const auto previous = instances_.size();
    std::erase_if(instances_, [identifier](const EffectInstance& instance) { return instance.identifier() == identifier; });
    return instances_.size() != previous;
}

void EffectScheduler::update(float elapsed_seconds) noexcept {
    for (EffectInstance& instance : instances_) { instance.update(elapsed_seconds); }
    std::erase_if(instances_, [](const EffectInstance& instance) { return instance.finished(); });
}

std::vector<ActivePart> EffectScheduler::active_parts() const {
    std::vector<ActivePart> result;
    for (const EffectInstance& instance : instances_) {
        std::vector<ActivePart> parts = instance.active_parts();
        result.insert(result.end(), std::make_move_iterator(parts.begin()), std::make_move_iterator(parts.end()));
    }
    return result;
}

std::size_t EffectScheduler::size() const noexcept { return instances_.size(); }

BladeTrail::BladeTrail(float point_lifetime, std::size_t maximum_points) : point_lifetime_(point_lifetime), maximum_points_(maximum_points) {
    if (!(point_lifetime_ > 0.0f) || maximum_points_ == 0u) { throw std::invalid_argument("Blade trail limits must be positive"); }
}

void BladeTrail::append(Vec3 point) {
    while (points_.size() >= maximum_points_) { points_.pop_front(); }
    points_.push_back({point, point_lifetime_});
}

void BladeTrail::update(float elapsed_seconds) noexcept {
    if (elapsed_seconds <= 0.0f) { return; }
    for (TrailPoint& point : points_) { point.lifetime -= elapsed_seconds; }
    std::erase_if(points_, [](const TrailPoint& point) { return point.lifetime <= 0.0f; });
}

const std::deque<TrailPoint>& BladeTrail::points() const noexcept { return points_; }

RainField::RainField(Vec3 minimum, Vec3 maximum, float drops_per_second, float fall_speed, std::uint32_t seed) : minimum_(minimum), maximum_(maximum), drops_per_second_(drops_per_second), fall_speed_(fall_speed), random_state_(seed == 0u ? 1u : seed) {
    if (maximum_.x < minimum_.x || maximum_.y < minimum_.y || maximum_.z < minimum_.z || drops_per_second_ < 0.0f || fall_speed_ < 0.0f) { throw std::invalid_argument("Invalid rain field bounds or rate"); }
}

float RainField::random_unit() noexcept {
    random_state_ = random_state_ * 1664525u + 1013904223u;
    return static_cast<float>(random_state_ >> 8u) / static_cast<float>(UINT32_C(0x01000000));
}

void RainField::update(float elapsed_seconds) {
    if (elapsed_seconds <= 0.0f) { return; }
    for (RainDrop& drop : drops_) { drop.position.y -= drop.speed * elapsed_seconds; }
    std::erase_if(drops_, [this](const RainDrop& drop) { return drop.position.y < minimum_.y; });
    spawn_credit_ += drops_per_second_ * elapsed_seconds;
    const std::size_t spawn_count = static_cast<std::size_t>(std::min(spawn_credit_, 100000.0f));
    spawn_credit_ -= static_cast<float>(spawn_count);
    drops_.reserve(drops_.size() + spawn_count);
    for (std::size_t index = 0; index < spawn_count; ++index) {
        const float x = minimum_.x + random_unit() * (maximum_.x - minimum_.x);
        const float z = minimum_.z + random_unit() * (maximum_.z - minimum_.z);
        drops_.push_back({{x, maximum_.y, z}, fall_speed_});
    }
}

void RainField::clear() noexcept { drops_.clear(); spawn_credit_ = 0.0f; }
const std::vector<RainDrop>& RainField::drops() const noexcept { return drops_; }

} // namespace effect_runtime

namespace audio_runtime {

float SoundCue::duration() const noexcept {
    float result = 0.0f;
    for (const CueEvent& event : events) { result = std::max(result, event.time); }
    return result;
}

bool SoundLibrary::store(SoundDefinition definition, bool replace) {
    const bool valid = !definition.name.empty() && !definition.file.empty() && definition.gain >= 0.0f && definition.pitch > 0.0f && definition.duration >= 0.0f && definition.minimum_distance >= 0.0f && definition.maximum_distance >= definition.minimum_distance;
    if (!valid) { return false; }
    const std::string key = canonical_name(definition.name);
    if (!replace && sounds_.contains(key)) { return false; }
    sounds_.insert_or_assign(key, std::move(definition));
    return true;
}

bool SoundLibrary::store(SoundCue cue, bool replace) {
    if (cue.name.empty() || std::any_of(cue.events.begin(), cue.events.end(), [](const CueEvent& event) { return event.time < 0.0f || event.sound.empty(); })) { return false; }
    std::sort(cue.events.begin(), cue.events.end(), [](const CueEvent& left, const CueEvent& right) { return left.time < right.time; });
    const std::string key = canonical_name(cue.name);
    if (!replace && cues_.contains(key)) { return false; }
    cues_.insert_or_assign(key, std::move(cue));
    return true;
}

const SoundDefinition* SoundLibrary::sound(std::string_view name) const noexcept {
    const auto found = sounds_.find(canonical_name(name));
    return found == sounds_.end() ? nullptr : &found->second;
}

const SoundCue* SoundLibrary::cue(std::string_view name) const noexcept {
    const auto found = cues_.find(canonical_name(name));
    return found == cues_.end() ? nullptr : &found->second;
}

std::size_t SoundLibrary::sound_count() const noexcept { return sounds_.size(); }
std::size_t SoundLibrary::cue_count() const noexcept { return cues_.size(); }

Mixer::Mixer(const SoundLibrary& library) : library_(&library) {}

std::optional<std::uint64_t> Mixer::play(std::string_view sound, Vec3 position, float delay) {
    const SoundDefinition* definition = library_->sound(sound);
    if (!definition) { return std::nullopt; }
    const std::uint64_t identifier = next_identifier_++;
    voices_.push_back({identifier, *definition, delay > 0.0f ? VoiceState::scheduled : VoiceState::playing, position, std::max(0.0f, delay), 0.0f});
    return identifier;
}

std::vector<std::uint64_t> Mixer::play_cue(std::string_view cue, Vec3 position) {
    std::vector<std::uint64_t> result;
    const SoundCue* definition = library_->cue(cue);
    if (!definition) { return result; }
    for (const CueEvent& event : definition->events) {
        const auto identifier = play(event.sound, position, event.time);
        if (identifier) { result.push_back(*identifier); }
    }
    return result;
}

bool Mixer::stop(std::uint64_t identifier) noexcept {
    const auto found = std::find_if(voices_.begin(), voices_.end(), [identifier](const Voice& voice) { return voice.identifier == identifier; });
    if (found == voices_.end()) { return false; }
    found->state = VoiceState::stopped;
    return true;
}

bool Mixer::pause(std::uint64_t identifier, bool paused) noexcept {
    const auto found = std::find_if(voices_.begin(), voices_.end(), [identifier](const Voice& voice) { return voice.identifier == identifier; });
    if (found == voices_.end() || found->state == VoiceState::scheduled || found->state == VoiceState::stopped) { return false; }
    found->state = paused ? VoiceState::paused : VoiceState::playing;
    return true;
}

void Mixer::set_master_gain(float gain) noexcept { master_gain_ = std::max(0.0f, gain); }
void Mixer::set_group_gain(std::string group, float gain) { group_gains_.insert_or_assign(canonical_name(group), std::max(0.0f, gain)); }

void Mixer::update(float elapsed_seconds) noexcept {
    if (elapsed_seconds <= 0.0f) { return; }
    for (Voice& voice : voices_) {
        float available = elapsed_seconds;
        if (voice.state == VoiceState::scheduled) {
            voice.delay -= elapsed_seconds;
            if (voice.delay > 0.0f) { continue; }
            available = -voice.delay;
            voice.delay = 0.0f;
            voice.state = VoiceState::playing;
        }
        if (voice.state != VoiceState::playing) { continue; }
        voice.playback_time += available;
        if (voice.sound.duration <= 0.0f || voice.playback_time < voice.sound.duration) { continue; }
        if (voice.sound.loop) { voice.playback_time = std::fmod(voice.playback_time, voice.sound.duration); }
        else { voice.state = VoiceState::stopped; }
    }
    std::erase_if(voices_, [](const Voice& voice) { return voice.state == VoiceState::stopped; });
}

float Mixer::effective_gain(const Voice& voice) const noexcept {
    const auto group = group_gains_.find(canonical_name(voice.sound.group));
    return master_gain_ * voice.sound.gain * (group == group_gains_.end() ? 1.0f : group->second);
}

std::vector<VoiceSnapshot> Mixer::voices() const {
    std::vector<VoiceSnapshot> result;
    result.reserve(voices_.size());
    for (const Voice& voice : voices_) { result.push_back({voice.identifier, voice.sound.name, voice.state, voice.position, voice.playback_time, effective_gain(voice)}); }
    return result;
}

std::size_t Mixer::active_voice_count() const noexcept { return voices_.size(); }

} // namespace audio_runtime

namespace log_runtime {
namespace {

const char* severity_name(Severity severity) noexcept {
    switch (severity) {
    case Severity::trace: return "trace";
    case Severity::information: return "info";
    case Severity::warning: return "warning";
    case Severity::error: return "error";
    case Severity::critical: return "critical";
    }
    return "unknown";
}

} // namespace

std::string format(const Record& record) {
    const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(record.time.time_since_epoch()).count();
    std::ostringstream output;
    output << '[' << milliseconds << "] [" << severity_name(record.severity) << "] [" << record.channel << "] " << record.message;
    return output.str();
}

void MemorySink::write(const Record& record) { std::lock_guard lock(mutex_); records_.push_back(record); }
std::vector<Record> MemorySink::records() const { std::lock_guard lock(mutex_); return records_; }
void MemorySink::clear() noexcept { std::lock_guard lock(mutex_); records_.clear(); }

FileSink::FileSink(std::filesystem::path path) : path_(std::move(path)) {
    if (path_.empty()) { throw std::invalid_argument("Log file path cannot be empty"); }
}

void FileSink::write(const Record& record) {
    std::lock_guard lock(mutex_);
    std::ofstream output(path_, std::ios::app);
    if (!output.is_open()) { throw std::runtime_error("Cannot open log file"); }
    output << format(record) << '\n';
}

const std::filesystem::path& FileSink::path() const noexcept { return path_; }

Logger::Logger(std::string channel) : channel_(std::move(channel)) {}

void Logger::add_sink(std::shared_ptr<Sink> sink) {
    if (!sink) { throw std::invalid_argument("Logger sink cannot be null"); }
    std::lock_guard lock(mutex_);
    sinks_.push_back(std::move(sink));
}

void Logger::set_minimum_severity(Severity severity) noexcept { minimum_severity_ = severity; }

void Logger::write(Severity severity, std::string message) {
    if (severity < minimum_severity_) { return; }
    const Record record{std::chrono::system_clock::now(), severity, channel_, std::move(message)};
    std::vector<std::shared_ptr<Sink>> sinks;
    { std::lock_guard lock(mutex_); sinks = sinks_; }
    for (const std::shared_ptr<Sink>& sink : sinks) { sink->write(record); }
}

const std::string& Logger::channel() const noexcept { return channel_; }

std::shared_ptr<Logger> Registry::logger(std::string channel) {
    const std::string key = canonical_name(channel);
    std::lock_guard lock(mutex_);
    const auto found = loggers_.find(key);
    if (found != loggers_.end()) { return found->second; }
    auto result = std::make_shared<Logger>(std::move(channel));
    for (const std::shared_ptr<Sink>& sink : shared_sinks_) { result->add_sink(sink); }
    loggers_.emplace(key, result);
    return result;
}

void Registry::attach_to_all(std::shared_ptr<Sink> sink) {
    if (!sink) { throw std::invalid_argument("Shared log sink cannot be null"); }
    std::lock_guard lock(mutex_);
    shared_sinks_.push_back(sink);
    for (auto& [name, logger] : loggers_) { logger->add_sink(sink); }
}

std::size_t Registry::size() const noexcept { std::lock_guard lock(mutex_); return loggers_.size(); }

} // namespace log_runtime

namespace shared_runtime {
namespace {

void append_le16(std::vector<std::uint8_t>& bytes, std::uint16_t value) {
    bytes.push_back(static_cast<std::uint8_t>(value));
    bytes.push_back(static_cast<std::uint8_t>(value >> 8u));
}

void append_le32(std::vector<std::uint8_t>& bytes, std::uint32_t value) {
    append_le16(bytes, static_cast<std::uint16_t>(value));
    append_le16(bytes, static_cast<std::uint16_t>(value >> 16u));
}

std::uint16_t read_le16(std::span<const std::uint8_t> bytes, std::size_t offset) noexcept {
    return static_cast<std::uint16_t>(bytes[offset]) | static_cast<std::uint16_t>(bytes[offset + 1u]) << 8u;
}

std::uint32_t read_le32(std::span<const std::uint8_t> bytes, std::size_t offset) noexcept {
    return static_cast<std::uint32_t>(read_le16(bytes, offset)) | static_cast<std::uint32_t>(read_le16(bytes, offset + 2u)) << 16u;
}

} // namespace

std::string normalize_key(std::string_view value) { return canonical_name(value); }

std::uint32_t hash_key(std::string_view value) noexcept {
    std::uint32_t result = UINT32_C(2166136261);
    for (const unsigned char character : value) { result = (result ^ static_cast<std::uint8_t>(std::tolower(character))) * UINT32_C(16777619); }
    return result;
}

std::uint32_t wildcard_match(const char* text, const char* pattern) {
    if (!text || !pattern) { return 0u; }
    const char* star = nullptr;
    const char* retry = nullptr;
    while (*text != '\0') {
        if (*pattern == '?' || *pattern == *text) { ++pattern; ++text; continue; }
        if (*pattern == '*') { star = pattern++; retry = text; continue; }
        if (!star) { return 0u; }
        pattern = star + 1;
        text = ++retry;
    }
    while (*pattern == '*') { ++pattern; }
    return *pattern == '\0' ? 1u : 0u;
}

std::uint32_t is_transport_mode(std::int32_t mode) { return mode == 4 || mode == 5 ? 1u : 0u; }
std::uint8_t interop_storage_class(std::uint32_t kind) { return kind == 0u ? 1u : static_cast<std::uint8_t>((kind & 0x0fu) != 0u ? 12u : 4u); }

std::int32_t wrapped_heading_delta(std::int32_t left, std::int32_t right) {
    const std::uint32_t difference_bits = static_cast<std::uint32_t>(left) - static_cast<std::uint32_t>(right);
    const std::int32_t difference = std::bit_cast<std::int32_t>(difference_bits);
    const std::uint32_t magnitude = difference < 0 ? 0u - difference_bits : difference_bits;
    if (magnitude < UINT32_C(0x3841)) { return difference; }
    return difference < 0 ? difference + 0x8000 : difference - 0x8000;
}

StringIndex::StringIndex(std::size_t maximum_key_length) : maximum_key_length_(maximum_key_length) {
    if (maximum_key_length_ == 0u) { throw std::invalid_argument("String index key length must be positive"); }
}

std::optional<std::uint32_t> StringIndex::insert(std::string key, bool replace) {
    if (key.empty() || key.size() > maximum_key_length_) { return std::nullopt; }
    key = normalize_key(key);
    const auto existing = by_key_.find(key);
    if (existing != by_key_.end()) { return replace ? std::optional<std::uint32_t>(existing->second) : std::nullopt; }
    const std::uint32_t index = next_index_++;
    by_key_.emplace(key, index);
    by_index_.emplace(index, std::move(key));
    return index;
}

bool StringIndex::erase(std::string_view key) noexcept {
    const auto found = by_key_.find(normalize_key(key));
    if (found == by_key_.end()) { return false; }
    by_index_.erase(found->second);
    by_key_.erase(found);
    return true;
}

std::optional<std::uint32_t> StringIndex::find(std::string_view key) const noexcept {
    const auto found = by_key_.find(normalize_key(key));
    return found == by_key_.end() ? std::nullopt : std::optional<std::uint32_t>(found->second);
}

std::optional<std::string> StringIndex::key(std::uint32_t index) const {
    const auto found = by_index_.find(index);
    return found == by_index_.end() ? std::nullopt : std::optional<std::string>(found->second);
}

std::size_t StringIndex::size() const noexcept { return by_key_.size(); }
void StringIndex::clear() noexcept { by_key_.clear(); by_index_.clear(); next_index_ = 0u; }

bool ItemList::add(ItemRecord item, InsertMode mode) {
    if (item.name.empty() || item.quantity < 0) { return false; }
    const std::string key = normalize_key(item.name);
    const auto found = items_.find(key);
    if (found == items_.end()) { items_.emplace(key, std::move(item)); return true; }
    if (mode == InsertMode::reject_existing) { return false; }
    if (mode == InsertMode::replace_existing) { found->second = std::move(item); return true; }
    found->second.quantity += item.quantity;
    for (auto& [attribute, value] : item.attributes) { found->second.attributes.insert_or_assign(std::move(attribute), std::move(value)); }
    return true;
}

std::optional<ItemRecord> ItemList::remove(std::string_view name) {
    const auto found = items_.find(normalize_key(name));
    if (found == items_.end()) { return std::nullopt; }
    ItemRecord result = std::move(found->second);
    items_.erase(found);
    return result;
}

ItemRecord* ItemList::find(std::string_view name) noexcept {
    const auto found = items_.find(normalize_key(name));
    return found == items_.end() ? nullptr : &found->second;
}

const ItemRecord* ItemList::find(std::string_view name) const noexcept {
    const auto found = items_.find(normalize_key(name));
    return found == items_.end() ? nullptr : &found->second;
}

const ItemRecord* ItemList::first() const noexcept { return items_.empty() ? nullptr : &items_.begin()->second; }

const ItemRecord* ItemList::next(std::string_view current_name) const noexcept {
    const auto found = items_.upper_bound(normalize_key(current_name));
    return found == items_.end() ? nullptr : &found->second;
}

std::vector<std::string> ItemList::names() const {
    std::vector<std::string> result;
    result.reserve(items_.size());
    for (const auto& [key, item] : items_) { result.push_back(item.name); }
    return result;
}

std::int64_t ItemList::total_quantity() const noexcept {
    std::int64_t result = 0;
    for (const auto& [key, item] : items_) { result += item.quantity; }
    return result;
}

std::size_t ItemList::size() const noexcept { return items_.size(); }
void ItemList::clear() noexcept { items_.clear(); }

bool ServerDirectory::update(ServerInfo server) {
    if (server.identifier == 0u || server.name.empty() || server.host.empty() || server.port == 0u) { return false; }
    servers_.insert_or_assign(server.identifier, std::move(server));
    return true;
}

bool ServerDirectory::remove(std::uint32_t identifier) noexcept { return servers_.erase(identifier) != 0u; }

const ServerInfo* ServerDirectory::find(std::uint32_t identifier) const noexcept {
    const auto found = servers_.find(identifier);
    return found == servers_.end() ? nullptr : &found->second;
}

const ServerInfo* ServerDirectory::find(std::string_view name) const noexcept {
    const std::string key = normalize_key(name);
    const auto found = std::find_if(servers_.begin(), servers_.end(), [&key](const auto& item) { return normalize_key(item.second.name) == key; });
    return found == servers_.end() ? nullptr : &found->second;
}

std::vector<ServerInfo> ServerDirectory::online_servers() const {
    std::vector<ServerInfo> result;
    for (const auto& [identifier, server] : servers_) { if (server.online) { result.push_back(server); } }
    std::sort(result.begin(), result.end(), [](const ServerInfo& left, const ServerInfo& right) { return left.population != right.population ? left.population < right.population : left.identifier < right.identifier; });
    return result;
}

std::size_t ServerDirectory::size() const noexcept { return servers_.size(); }

bool BytecodeModule::load(std::string name, std::vector<std::uint8_t> bytecode, std::vector<ModuleArray> arrays) {
    valid_ = false;
    if (name.empty()) { return false; }
    std::sort(arrays.begin(), arrays.end(), [](const ModuleArray& left, const ModuleArray& right) { return left.offset != right.offset ? left.offset < right.offset : left.tag < right.tag; });
    std::set<std::uint32_t> tags;
    std::uint64_t previous_end = 0u;
    for (const ModuleArray& array : arrays) {
        const std::uint64_t end = static_cast<std::uint64_t>(array.offset) + array.size;
        if (!tags.insert(array.tag).second || end > bytecode.size() || array.offset < previous_end) { return false; }
        previous_end = end;
    }
    name_ = std::move(name);
    bytecode_ = std::move(bytecode);
    arrays_ = std::move(arrays);
    valid_ = true;
    return true;
}

std::span<const std::uint8_t> BytecodeModule::array(std::uint32_t tag) const noexcept {
    const auto found = std::find_if(arrays_.begin(), arrays_.end(), [tag](const ModuleArray& array) { return array.tag == tag; });
    return found == arrays_.end() ? std::span<const std::uint8_t>{} : std::span<const std::uint8_t>(bytecode_).subspan(found->offset, found->size);
}

std::span<const std::uint8_t> BytecodeModule::bytes() const noexcept { return bytecode_; }
std::string_view BytecodeModule::name() const noexcept { return name_; }
bool BytecodeModule::valid() const noexcept { return valid_; }

bool ModuleRegistry::store(BytecodeModule module, bool replace) {
    if (!module.valid()) { return false; }
    const std::string key = normalize_key(module.name());
    if (!replace && modules_.contains(key)) { return false; }
    modules_.insert_or_assign(key, std::move(module));
    return true;
}

bool ModuleRegistry::erase(std::string_view name) noexcept { return modules_.erase(normalize_key(name)) != 0u; }

const BytecodeModule* ModuleRegistry::find(std::string_view name) const noexcept {
    const auto found = modules_.find(normalize_key(name));
    return found == modules_.end() ? nullptr : &found->second;
}

std::vector<std::string> ModuleRegistry::names() const {
    std::vector<std::string> result;
    result.reserve(modules_.size());
    for (const auto& [key, module] : modules_) { result.emplace_back(module.name()); }
    std::sort(result.begin(), result.end());
    return result;
}

std::size_t ModuleRegistry::size() const noexcept { return modules_.size(); }

bool CommandRegistry::register_handler(std::string name, Handler handler, bool replace) {
    if (name.empty() || !handler) { return false; }
    const std::string key = normalize_key(name);
    if (!replace && handlers_.contains(key)) { return false; }
    handlers_.insert_or_assign(key, std::move(handler));
    return true;
}

bool CommandRegistry::erase(std::string_view name) noexcept { return handlers_.erase(normalize_key(name)) != 0u; }

script::Value CommandRegistry::invoke(std::string_view name, std::span<const script::Value> arguments) const {
    const auto found = handlers_.find(normalize_key(name));
    if (found == handlers_.end()) { throw std::out_of_range("Shared command is not registered"); }
    return found->second(arguments);
}

bool CommandRegistry::contains(std::string_view name) const noexcept { return handlers_.contains(normalize_key(name)); }
std::size_t CommandRegistry::size() const noexcept { return handlers_.size(); }

WorldMapImage::WorldMapImage(std::uint32_t width, std::uint32_t height, std::uint32_t color) { resize(width, height, color); }

void WorldMapImage::resize(std::uint32_t width, std::uint32_t height, std::uint32_t color) {
    if (width != 0u && height > std::numeric_limits<std::size_t>::max() / width) { throw std::length_error("World map dimensions are too large"); }
    width_ = width;
    height_ = height;
    pixels_.assign(static_cast<std::size_t>(width) * height, color);
}

std::size_t WorldMapImage::index(std::uint32_t x, std::uint32_t y) const {
    if (x >= width_ || y >= height_) { throw std::out_of_range("World map pixel is out of range"); }
    return static_cast<std::size_t>(y) * width_ + x;
}

std::uint32_t WorldMapImage::pixel(std::uint32_t x, std::uint32_t y) const { return pixels_[index(x, y)]; }
void WorldMapImage::set_pixel(std::uint32_t x, std::uint32_t y, std::uint32_t color) { pixels_[index(x, y)] = color; }

std::vector<std::uint8_t> WorldMapImage::encode_bmp() const {
    const std::uint64_t pixel_bytes = static_cast<std::uint64_t>(width_) * height_ * 4u;
    if (pixel_bytes > std::numeric_limits<std::uint32_t>::max() - 54u) { throw std::length_error("World map bitmap is too large"); }
    std::vector<std::uint8_t> result;
    result.reserve(static_cast<std::size_t>(pixel_bytes) + 54u);
    append_le16(result, UINT16_C(0x4d42));
    append_le32(result, static_cast<std::uint32_t>(pixel_bytes) + 54u);
    append_le32(result, 0u);
    append_le32(result, 54u);
    append_le32(result, 40u);
    append_le32(result, width_);
    append_le32(result, height_);
    append_le16(result, 1u);
    append_le16(result, 32u);
    append_le32(result, 0u);
    append_le32(result, static_cast<std::uint32_t>(pixel_bytes));
    append_le32(result, 0u);
    append_le32(result, 0u);
    append_le32(result, 0u);
    append_le32(result, 0u);
    for (std::uint32_t row = 0u; row < height_; ++row) {
        const std::uint32_t source_y = height_ - row - 1u;
        for (std::uint32_t x = 0u; x < width_; ++x) {
            const std::uint32_t color = pixels_[static_cast<std::size_t>(source_y) * width_ + x];
            append_le32(result, color);
        }
    }
    return result;
}

bool WorldMapImage::decode_bmp(std::span<const std::uint8_t> bytes) {
    if (bytes.size() < 54u || read_le16(bytes, 0u) != UINT16_C(0x4d42) || read_le32(bytes, 14u) < 40u || read_le16(bytes, 26u) != 1u || read_le32(bytes, 30u) != 0u) { return false; }
    const std::uint32_t data_offset = read_le32(bytes, 10u);
    const std::uint32_t width = read_le32(bytes, 18u);
    const std::int32_t signed_height = std::bit_cast<std::int32_t>(read_le32(bytes, 22u));
    const std::uint16_t bits = read_le16(bytes, 28u);
    if (width == 0u || signed_height == 0 || signed_height == std::numeric_limits<std::int32_t>::min() || (bits != 24u && bits != 32u)) { return false; }
    const std::uint32_t height = static_cast<std::uint32_t>(signed_height < 0 ? -signed_height : signed_height);
    const std::uint64_t row_bytes = (static_cast<std::uint64_t>(width) * (bits / 8u) + 3u) & ~UINT64_C(3);
    if (row_bytes * height > bytes.size() || data_offset > bytes.size() - row_bytes * height) { return false; }
    std::vector<std::uint32_t> pixels(static_cast<std::size_t>(width) * height);
    for (std::uint32_t row = 0u; row < height; ++row) {
        const std::uint32_t destination_y = signed_height < 0 ? row : height - row - 1u;
        const std::size_t source = data_offset + static_cast<std::size_t>(row_bytes) * row;
        for (std::uint32_t x = 0u; x < width; ++x) {
            const std::size_t offset = source + static_cast<std::size_t>(x) * (bits / 8u);
            const std::uint32_t alpha = bits == 32u ? static_cast<std::uint32_t>(bytes[offset + 3u]) << 24u : UINT32_C(0xff000000);
            pixels[static_cast<std::size_t>(destination_y) * width + x] = alpha | static_cast<std::uint32_t>(bytes[offset + 2u]) << 16u | static_cast<std::uint32_t>(bytes[offset + 1u]) << 8u | bytes[offset];
        }
    }
    width_ = width;
    height_ = height;
    pixels_ = std::move(pixels);
    return true;
}

std::uint32_t WorldMapImage::width() const noexcept { return width_; }
std::uint32_t WorldMapImage::height() const noexcept { return height_; }
std::span<const std::uint32_t> WorldMapImage::pixels() const noexcept { return pixels_; }

TransportSession::TransportSession(std::size_t send_capacity, std::size_t receive_capacity) : outgoing_(send_capacity), incoming_(receive_capacity) {}

void TransportSession::begin(Endpoint endpoint, std::uint16_t checksum_seed) {
    if (endpoint.host.empty() || endpoint.port == 0u) { throw std::invalid_argument("Transport endpoint is incomplete"); }
    endpoint_ = std::move(endpoint);
    checksum_seed_ = checksum_seed;
    error_.clear();
    outgoing_.clear();
    incoming_.clear();
    state_ = TransportState::connecting;
}

void TransportSession::mark_connected() noexcept { if (state_ == TransportState::connecting) { state_ = TransportState::connected; } }
void TransportSession::fail(std::string reason) { error_ = std::move(reason); state_ = TransportState::failed; }
void TransportSession::close() noexcept { outgoing_.clear(); incoming_.clear(); state_ = TransportState::stopped; }

bool TransportSession::send(std::uint16_t opcode, std::span<const std::uint8_t> payload) {
    return state_ == TransportState::connected && outgoing_.enqueue(opcode, payload, 1u, checksum_seed_);
}

bool TransportSession::receive(std::span<const std::uint8_t> bytes) { return state_ == TransportState::connected && incoming_.append(bytes); }

std::optional<network::Packet> TransportSession::next_packet() {
    if (state_ != TransportState::connected) { return std::nullopt; }
    std::optional<network::Packet> packet = incoming_.next();
    if (!packet) { return std::nullopt; }
    std::uint16_t sum = static_cast<std::uint16_t>((packet->header.sequence & 0xffu) + (packet->header.sequence >> 8u) + (packet->header.opcode & 0xffu) + (packet->header.opcode >> 8u));
    for (const std::uint8_t value : packet->payload) { sum = static_cast<std::uint16_t>(sum + value); }
    if (packet->header.checksum != static_cast<std::uint16_t>(checksum_seed_ ^ sum)) { fail("Network packet checksum mismatch"); return std::nullopt; }
    return packet;
}

std::span<const std::uint8_t> TransportSession::outgoing() const noexcept { return outgoing_.pending(); }
void TransportSession::consume_outgoing(std::size_t byte_count) { outgoing_.consume(byte_count); }
TransportState TransportSession::state() const noexcept { return state_; }
const Endpoint& TransportSession::endpoint() const noexcept { return endpoint_; }
const std::string& TransportSession::error() const noexcept { return error_; }

std::uint32_t NetworkManager::create_session(Endpoint endpoint, std::uint16_t checksum_seed) {
    const std::uint32_t identifier = next_identifier_++;
    auto [position, inserted] = sessions_.try_emplace(identifier);
    position->second.begin(std::move(endpoint), checksum_seed);
    return identifier;
}

bool NetworkManager::remove_session(std::uint32_t identifier) noexcept { return sessions_.erase(identifier) != 0u; }

TransportSession* NetworkManager::session(std::uint32_t identifier) noexcept {
    const auto found = sessions_.find(identifier);
    return found == sessions_.end() ? nullptr : &found->second;
}

const TransportSession* NetworkManager::session(std::uint32_t identifier) const noexcept {
    const auto found = sessions_.find(identifier);
    return found == sessions_.end() ? nullptr : &found->second;
}

std::size_t NetworkManager::size() const noexcept { return sessions_.size(); }
void NetworkManager::close_all() noexcept { for (auto& [identifier, session] : sessions_) { session.close(); } }

} // namespace shared_runtime

namespace world_runtime {

void inverse_transform_point(Vec3* destination, const TransformReference* transform, const Vec3* source) {
    const Matrix3x4& matrix = *transform->matrix;
    const Vec3 relative{source->x - matrix.values[3], source->y - matrix.values[7], source->z - matrix.values[11]};
    destination->x = relative.x * matrix.values[0] + relative.y * matrix.values[4] + relative.z * matrix.values[8];
    destination->y = relative.x * matrix.values[1] + relative.y * matrix.values[5] + relative.z * matrix.values[9];
    destination->z = relative.x * matrix.values[2] + relative.y * matrix.values[6] + relative.z * matrix.values[10];
}

void inverse_transform_in_place(const TransformReference* transform, Vec3* point) {
    Vec3 result{};
    inverse_transform_point(&result, transform, point);
    *point = result;
}

void quaternion_matrix(const PackedQuaternion* quaternion, Matrix3x3* destination) {
    const float twice_x = quaternion->x * 2.0f;
    const float twice_y = quaternion->y * 2.0f;
    const float twice_z = quaternion->z * 2.0f;
    const float xx = quaternion->x * twice_x;
    const float xy = quaternion->x * twice_y;
    const float xz = quaternion->x * twice_z;
    const float yy = quaternion->y * twice_y;
    const float yz = quaternion->y * twice_z;
    const float zz = quaternion->z * twice_z;
    const float wx = quaternion->w * twice_x;
    const float wy = quaternion->w * twice_y;
    const float wz = quaternion->w * twice_z;
    destination->values = {{1.0f - yy - zz, xy - wz, xz + wy, xy + wz, 1.0f - xx - zz, yz - wx, xz - wy, yz + wx, 1.0f - xx - yy}};
}

Vec3* cross_product(Vec3* destination, const Vec3* left, const Vec3* right) {
    *destination = {left->y * right->z - left->z * right->y, left->z * right->x - left->x * right->z, left->x * right->y - left->y * right->x};
    return destination;
}

std::uint32_t contains_substring(const char* text, const char* fragment) {
    if (!text || !fragment) { return 0u; }
    return std::string_view(text).find(fragment) == std::string_view::npos ? 0u : 1u;
}

float scaled_effect_time(float time, float scale) {
    constexpr float duration = 0.4f;
    return std::clamp(time / duration, 0.0f, 1.0f) * scale;
}

bool snap_near_zero(Vec3* value) {
    constexpr float epsilon = 0.0001f;
    bool result = true;
    for (float* component : {&value->x, &value->y, &value->z}) {
        if (std::fabs(*component) < epsilon) { *component = 0.0f; }
        else { result = false; }
    }
    return result;
}

std::int32_t grid_index(std::int32_t layer, std::int32_t row, std::int32_t column) { return column + (row + layer * 2) * 2; }

std::int32_t intersect_plane_segment(const Plane* plane, const Vec3* begin, const Vec3* end, Vec3* intersection) {
    const Vec3 direction{end->x - begin->x, end->y - begin->y, end->z - begin->z};
    const float denominator = plane->normal.x * direction.x + plane->normal.y * direction.y + plane->normal.z * direction.z;
    if (std::fabs(denominator) < std::numeric_limits<float>::min()) { return 0; }
    const float begin_distance = plane->normal.x * begin->x + plane->normal.y * begin->y + plane->normal.z * begin->z + plane->distance;
    std::int32_t result = begin_distance < 0.0f ? -2 : 1;
    if (denominator > 0.0f) { ++result; }
    const float amount = begin_distance / denominator;
    *intersection = {begin->x - amount * direction.x, begin->y - amount * direction.y, begin->z - amount * direction.z};
    return result;
}

bool AnimationClip::valid() const noexcept {
    if (name.empty() || duration < 0.0f || frames.empty()) { return false; }
    const std::size_t bone_count = frames.front().bones.size();
    float previous_time = -1.0f;
    for (const AnimationFrame& frame : frames) {
        if (frame.time < previous_time || frame.time < 0.0f || frame.time > duration || frame.bones.size() != bone_count) { return false; }
        previous_time = frame.time;
    }
    return true;
}

bool AnimationLibrary::store(AnimationClip clip, bool replace) {
    std::sort(clip.frames.begin(), clip.frames.end(), [](const AnimationFrame& left, const AnimationFrame& right) { return left.time < right.time; });
    if (!clip.valid()) { return false; }
    const std::string key = canonical_name(clip.name);
    if (!replace && clips_.contains(key)) { return false; }
    clips_.insert_or_assign(key, std::move(clip));
    return true;
}

bool AnimationLibrary::erase(std::string_view name) noexcept { return clips_.erase(canonical_name(name)) != 0u; }

const AnimationClip* AnimationLibrary::find(std::string_view name) const noexcept {
    const auto found = clips_.find(canonical_name(name));
    return found == clips_.end() ? nullptr : &found->second;
}

std::vector<character::BonePose> AnimationLibrary::sample(std::string_view name, float time) const {
    const AnimationClip* clip = find(name);
    if (!clip) { return {}; }
    if (clip->loop && clip->duration > 0.0f) { time = std::fmod(time, clip->duration); if (time < 0.0f) { time += clip->duration; } }
    else { time = std::clamp(time, 0.0f, clip->duration); }
    const auto right = std::upper_bound(clip->frames.begin(), clip->frames.end(), time, [](float value, const AnimationFrame& frame) { return value < frame.time; });
    if (right == clip->frames.begin()) { return right->bones; }
    if (right == clip->frames.end()) { return clip->frames.back().bones; }
    const AnimationFrame& left_frame = *std::prev(right);
    const float span = right->time - left_frame.time;
    const float amount = span > 0.0f ? (time - left_frame.time) / span : 0.0f;
    std::vector<character::BonePose> result(left_frame.bones.size());
    for (std::size_t index = 0u; index < result.size(); ++index) { result[index] = character::interpolate(left_frame.bones[index], right->bones[index], amount); }
    return result;
}

std::size_t AnimationLibrary::size() const noexcept { return clips_.size(); }

ObjectHandle ObjectManager::create(SceneObject object) {
    std::uint32_t index = 0u;
    if (free_slots_.empty()) { index = static_cast<std::uint32_t>(slots_.size()); slots_.push_back({}); }
    else { index = free_slots_.back(); free_slots_.pop_back(); }
    Slot& slot = slots_[index];
    object.handle = {index, slot.generation};
    object.parent.reset();
    object.children.clear();
    slot.object = std::move(object);
    return slot.object->handle;
}

bool ObjectManager::destroy(ObjectHandle handle) noexcept {
    SceneObject* object = find(handle);
    if (!object) { return false; }
    if (object->parent) {
        if (SceneObject* parent = find(*object->parent)) { std::erase(parent->children, handle); }
    }
    for (ObjectHandle child_handle : object->children) { if (SceneObject* child = find(child_handle)) { child->parent.reset(); } }
    Slot& slot = slots_[handle.index];
    slot.object.reset();
    if (++slot.generation == 0u) { ++slot.generation; }
    free_slots_.push_back(handle.index);
    return true;
}

SceneObject* ObjectManager::find(ObjectHandle handle) noexcept {
    if (!handle || handle.index >= slots_.size()) { return nullptr; }
    Slot& slot = slots_[handle.index];
    return slot.generation == handle.generation && slot.object ? &*slot.object : nullptr;
}

const SceneObject* ObjectManager::find(ObjectHandle handle) const noexcept {
    if (!handle || handle.index >= slots_.size()) { return nullptr; }
    const Slot& slot = slots_[handle.index];
    return slot.generation == handle.generation && slot.object ? &*slot.object : nullptr;
}

ObjectHandle ObjectManager::find(std::string_view name) const noexcept {
    const std::string key = canonical_name(name);
    for (const Slot& slot : slots_) { if (slot.object && canonical_name(slot.object->name) == key) { return slot.object->handle; } }
    return {};
}

bool ObjectManager::creates_cycle(ObjectHandle child, ObjectHandle parent) const noexcept {
    ObjectHandle cursor = parent;
    for (std::size_t depth = 0u; depth <= slots_.size(); ++depth) {
        if (cursor == child) { return true; }
        const SceneObject* object = find(cursor);
        if (!object || !object->parent) { return false; }
        cursor = *object->parent;
    }
    return true;
}

bool ObjectManager::link(ObjectHandle child_handle, ObjectHandle parent_handle) {
    SceneObject* child = find(child_handle);
    SceneObject* parent = find(parent_handle);
    if (!child || !parent || child_handle == parent_handle || creates_cycle(child_handle, parent_handle)) { return false; }
    unlink(child_handle);
    child = find(child_handle);
    parent = find(parent_handle);
    child->parent = parent_handle;
    parent->children.push_back(child_handle);
    return true;
}

bool ObjectManager::unlink(ObjectHandle child_handle) noexcept {
    SceneObject* child = find(child_handle);
    if (!child) { return false; }
    if (child->parent) { if (SceneObject* parent = find(*child->parent)) { std::erase(parent->children, child_handle); } }
    child->parent.reset();
    return true;
}

bool ObjectManager::move(ObjectHandle handle, Vec3 position) noexcept {
    SceneObject* object = find(handle);
    if (!object) { return false; }
    object->position = position;
    return true;
}

bool ObjectManager::rotate(ObjectHandle handle, character::Quaternion orientation) noexcept {
    SceneObject* object = find(handle);
    if (!object) { return false; }
    object->orientation = character::normalize(orientation);
    return true;
}

Matrix3x4 ObjectManager::world_transform(ObjectHandle handle) const {
    std::vector<const SceneObject*> chain;
    const SceneObject* object = find(handle);
    if (!object) { throw std::out_of_range("Scene object handle is invalid"); }
    while (object) {
        chain.push_back(object);
        if (!object->parent) { break; }
        object = find(*object->parent);
        if (!object || chain.size() > slots_.size()) { throw std::logic_error("Scene object hierarchy is invalid"); }
    }
    Matrix3x4 result = character::compose({});
    for (auto position = chain.rbegin(); position != chain.rend(); ++position) {
        Matrix3x4 local = character::compose({(*position)->position, (*position)->orientation});
        for (std::size_t row = 0u; row < 3u; ++row) {
            local.values[row * 4u] *= (*position)->scale.x;
            local.values[row * 4u + 1u] *= (*position)->scale.y;
            local.values[row * 4u + 2u] *= (*position)->scale.z;
        }
        result = character::multiply(result, local);
    }
    return result;
}

std::vector<ObjectHandle> ObjectManager::handles() const {
    std::vector<ObjectHandle> result;
    result.reserve(size());
    for (const Slot& slot : slots_) { if (slot.object) { result.push_back(slot.object->handle); } }
    return result;
}

void ObjectManager::update_animations(float elapsed_seconds, const AnimationLibrary& animations) noexcept {
    if (elapsed_seconds <= 0.0f) { return; }
    for (Slot& slot : slots_) {
        if (!slot.object || slot.object->animation.empty()) { continue; }
        const AnimationClip* clip = animations.find(slot.object->animation);
        if (!clip) { continue; }
        slot.object->animation_time += elapsed_seconds * slot.object->animation_rate;
        if (clip->loop && clip->duration > 0.0f) { slot.object->animation_time = std::fmod(slot.object->animation_time, clip->duration); }
        else { slot.object->animation_time = std::clamp(slot.object->animation_time, 0.0f, clip->duration); }
    }
}

std::size_t ObjectManager::size() const noexcept { return slots_.size() - free_slots_.size(); }

std::uint64_t LightManager::add(Light light) {
    if (light.radius < 0.0f || light.intensity < 0.0f) { throw std::invalid_argument("Light radius and intensity cannot be negative"); }
    if (light.identifier == 0u) { light.identifier = next_identifier_++; }
    else { next_identifier_ = std::max(next_identifier_, light.identifier + 1u); }
    const std::uint64_t identifier = light.identifier;
    lights_.insert_or_assign(identifier, std::move(light));
    return identifier;
}

bool LightManager::remove(std::uint64_t identifier) noexcept { return lights_.erase(identifier) != 0u; }

Light* LightManager::find(std::uint64_t identifier) noexcept {
    const auto found = lights_.find(identifier);
    return found == lights_.end() ? nullptr : &found->second;
}

std::vector<Light> LightManager::active(Vec3 observer, std::size_t maximum) const {
    std::vector<Light> result;
    for (const auto& [identifier, light] : lights_) { if (light.enabled && light.intensity > 0.0f && squared_distance(light.position, observer) <= light.radius * light.radius) { result.push_back(light); } }
    std::sort(result.begin(), result.end(), [observer](const Light& left, const Light& right) { return squared_distance(left.position, observer) < squared_distance(right.position, observer); });
    if (result.size() > maximum) { result.resize(maximum); }
    return result;
}

std::size_t LightManager::size() const noexcept { return lights_.size(); }

bool HeightField::reset(std::uint32_t width, std::uint32_t height, float cell_size, std::vector<float> heights) {
    if (width < 2u || height < 2u || !(cell_size > 0.0f) || heights.size() != static_cast<std::size_t>(width) * height) { return false; }
    width_ = width;
    height_ = height;
    cell_size_ = cell_size;
    heights_ = std::move(heights);
    return true;
}

float HeightField::sample(std::uint32_t x, std::uint32_t z) const noexcept {
    if (heights_.empty()) { return 0.0f; }
    x = std::min(x, width_ - 1u);
    z = std::min(z, height_ - 1u);
    return heights_[static_cast<std::size_t>(z) * width_ + x];
}

float HeightField::height(float x, float z) const noexcept {
    if (heights_.empty()) { return 0.0f; }
    const float grid_x = std::clamp(x / cell_size_, 0.0f, static_cast<float>(width_ - 1u));
    const float grid_z = std::clamp(z / cell_size_, 0.0f, static_cast<float>(height_ - 1u));
    const std::uint32_t x0 = static_cast<std::uint32_t>(grid_x);
    const std::uint32_t z0 = static_cast<std::uint32_t>(grid_z);
    const std::uint32_t x1 = std::min(x0 + 1u, width_ - 1u);
    const std::uint32_t z1 = std::min(z0 + 1u, height_ - 1u);
    const float horizontal = grid_x - static_cast<float>(x0);
    const float vertical = grid_z - static_cast<float>(z0);
    const float top = sample(x0, z0) + horizontal * (sample(x1, z0) - sample(x0, z0));
    const float bottom = sample(x0, z1) + horizontal * (sample(x1, z1) - sample(x0, z1));
    return top + vertical * (bottom - top);
}

Vec3 HeightField::normal(float x, float z) const noexcept {
    if (heights_.empty()) { return {0.0f, 1.0f, 0.0f}; }
    const float left = height(x - cell_size_, z);
    const float right = height(x + cell_size_, z);
    const float back = height(x, z - cell_size_);
    const float front = height(x, z + cell_size_);
    const Vec3 value{left - right, 2.0f * cell_size_, back - front};
    const float length = std::sqrt(value.x * value.x + value.y * value.y + value.z * value.z);
    return length > 0.0f ? Vec3{value.x / length, value.y / length, value.z / length} : Vec3{0.0f, 1.0f, 0.0f};
}

std::uint32_t HeightField::width() const noexcept { return width_; }
std::uint32_t HeightField::height_count() const noexcept { return height_; }

bool PlantingMap::load(std::string_view text) {
    std::vector<PlantInstance> parsed;
    std::istringstream input{std::string(text)};
    std::string line;
    while (std::getline(input, line)) {
        const std::size_t first = line.find_first_not_of(" \t\r");
        if (first == std::string::npos || line[first] == '#') { continue; }
        std::istringstream fields(line.substr(first));
        PlantInstance plant;
        if (!(fields >> plant.model >> plant.position.x >> plant.position.y >> plant.position.z >> plant.scale >> plant.rotation) || plant.model.empty() || !(plant.scale > 0.0f)) { return false; }
        parsed.push_back(std::move(plant));
    }
    plants_ = std::move(parsed);
    return true;
}

std::vector<PlantInstance> PlantingMap::in_radius(Vec3 center, float radius) const {
    std::vector<PlantInstance> result;
    const float limit = std::max(0.0f, radius) * std::max(0.0f, radius);
    for (const PlantInstance& plant : plants_) { if (squared_distance(plant.position, center) <= limit) { result.push_back(plant); } }
    return result;
}

const std::vector<PlantInstance>& PlantingMap::plants() const noexcept { return plants_; }
void PlantingMap::clear() noexcept { plants_.clear(); }

bool WeatherTimeline::set(std::vector<WeatherKeyframe> keyframes, float duration) {
    if (!(duration > 0.0f) || keyframes.empty()) { return false; }
    std::sort(keyframes.begin(), keyframes.end(), [](const WeatherKeyframe& left, const WeatherKeyframe& right) { return left.time < right.time; });
    if (keyframes.front().time < 0.0f || keyframes.back().time > duration) { return false; }
    keyframes_ = std::move(keyframes);
    duration_ = duration;
    return true;
}

WeatherKeyframe WeatherTimeline::sample(float time) const noexcept {
    if (keyframes_.empty()) { return {}; }
    time = std::fmod(time, duration_);
    if (time < 0.0f) { time += duration_; }
    const auto right = std::upper_bound(keyframes_.begin(), keyframes_.end(), time, [](float value, const WeatherKeyframe& frame) { return value < frame.time; });
    if (right == keyframes_.begin()) { return *right; }
    if (right == keyframes_.end()) { return keyframes_.back(); }
    const WeatherKeyframe& left = *std::prev(right);
    const float amount = right->time > left.time ? (time - left.time) / (right->time - left.time) : 0.0f;
    const auto interpolate_scalar = [amount](float from, float to) { return from + amount * (to - from); };
    return {time, {interpolate_scalar(left.fog_color.x, right->fog_color.x), interpolate_scalar(left.fog_color.y, right->fog_color.y), interpolate_scalar(left.fog_color.z, right->fog_color.z)}, interpolate_scalar(left.fog_density, right->fog_density), interpolate_scalar(left.rain, right->rain), interpolate_scalar(left.wind, right->wind)};
}

float WeatherTimeline::duration() const noexcept { return duration_; }

bool ModelCatalog::store(ModelDefinition model, bool replace) {
    if (model.name.empty() || model.file.empty() || model.bounding_radius < 0.0f) { return false; }
    const std::string key = canonical_name(model.name);
    if (!replace && models_.contains(key)) { return false; }
    models_.insert_or_assign(key, std::move(model));
    return true;
}

bool ModelCatalog::erase(std::string_view name) noexcept { return models_.erase(canonical_name(name)) != 0u; }

const ModelDefinition* ModelCatalog::find(std::string_view name) const noexcept {
    const auto found = models_.find(canonical_name(name));
    return found == models_.end() ? nullptr : &found->second;
}

std::vector<std::string> ModelCatalog::names() const {
    std::vector<std::string> result;
    result.reserve(models_.size());
    for (const auto& [key, model] : models_) { result.push_back(model.name); }
    std::sort(result.begin(), result.end());
    return result;
}

std::size_t ModelCatalog::size() const noexcept { return models_.size(); }

std::vector<DrawCommand> SceneRenderer::build(const ObjectManager& objects, const ModelCatalog& models, Vec3 observer) const {
    std::vector<DrawCommand> result;
    for (ObjectHandle handle : objects.handles()) {
        const SceneObject* object = objects.find(handle);
        if (!object || !object->visible || !models.find(object->model)) { continue; }
        const Matrix3x4 transform = objects.world_transform(handle);
        const Vec3 position{transform.values[3], transform.values[7], transform.values[11]};
        result.push_back({handle, object->model, transform, squared_distance(position, observer), object->animation, object->animation_time});
    }
    std::sort(result.begin(), result.end(), [](const DrawCommand& left, const DrawCommand& right) { return left.distance_squared != right.distance_squared ? left.distance_squared < right.distance_squared : left.object < right.object; });
    return result;
}

void World::update(float elapsed_seconds) noexcept {
    elapsed_seconds = std::max(0.0f, elapsed_seconds);
    time_ += elapsed_seconds;
    objects_.update_animations(elapsed_seconds, animations_);
}

ObjectManager& World::objects() noexcept { return objects_; }
const ObjectManager& World::objects() const noexcept { return objects_; }
AnimationLibrary& World::animations() noexcept { return animations_; }
LightManager& World::lights() noexcept { return lights_; }
HeightField& World::terrain() noexcept { return terrain_; }
PlantingMap& World::planting() noexcept { return planting_; }
WeatherTimeline& World::weather() noexcept { return weather_; }
ModelCatalog& World::models() noexcept { return models_; }
float World::time() const noexcept { return time_; }

} // namespace world_runtime


namespace container_runtime {

IndexStatus check_index(std::ptrdiff_t index, std::size_t size, std::size_t maximum) noexcept {
    if (index < 0) { return IndexStatus::negative; }
    const auto converted = static_cast<std::size_t>(index);
    if (converted >= maximum) { return IndexStatus::maximum_exceeded; }
    return converted < size ? IndexStatus::valid : IndexStatus::out_of_range;
}

void require_index(std::ptrdiff_t index, std::size_t size, std::size_t maximum) {
    const IndexStatus status = check_index(index, size, maximum);
    if (status == IndexStatus::valid) { return; }
    if (status == IndexStatus::negative) { throw std::out_of_range("container index is negative"); }
    if (status == IndexStatus::maximum_exceeded) { throw std::length_error("container index exceeds configured maximum"); }
    throw std::out_of_range("container index is outside the current range");
}

} // namespace container_runtime

namespace content_runtime {
namespace {
std::string lowercase(std::string_view value) { std::string result(value); std::transform(result.begin(), result.end(), result.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); }); return result; }
std::string trim_text(std::string_view value) { std::size_t first = 0; while (first < value.size() && std::isspace(static_cast<unsigned char>(value[first]))) { ++first; } std::size_t last = value.size(); while (last > first && std::isspace(static_cast<unsigned char>(value[last - 1u]))) { --last; } return std::string(value.substr(first, last - first)); }
std::optional<std::string> cfg_value(std::string_view text, std::string_view key) { std::size_t cursor = 0; while (cursor < text.size()) { const std::size_t end = text.find_first_of("\r\n", cursor); const std::string_view line = text.substr(cursor, end == std::string_view::npos ? text.size() - cursor : end - cursor); const std::size_t equal = line.find('='); if (equal != std::string_view::npos && lowercase(trim_text(line.substr(0, equal))) == lowercase(key)) { return trim_text(line.substr(equal + 1u)); } if (end == std::string_view::npos) { break; } cursor = end + 1u; } return std::nullopt; }
ConnectionType parse_connection_type(std::string_view value) { const std::string text = lowercase(value); if (text == "direct" || text == "1") { return ConnectionType::direct; } if (text == "proxy" || text == "2") { return ConnectionType::proxy; } if (text.empty() || text == "auto" || text == "automatic" || text == "0") { return ConnectionType::automatic; } return ConnectionType::unknown; }
script::Value parse_scalar(std::string_view value) { const std::string text = trim_text(value); if (text == "true") { return script::Value(true); } if (text == "false") { return script::Value(false); } char* end = nullptr; const long integer = std::strtol(text.c_str(), &end, 10); if (end && *end == '\0') { return script::Value(static_cast<std::int32_t>(integer)); } end = nullptr; const float floating = std::strtof(text.c_str(), &end); if (end && *end == '\0') { return script::Value(floating); } if (text.size() >= 2u && ((text.front() == '"' && text.back() == '"') || (text.front() == '\'' && text.back() == '\''))) { return script::Value(text.substr(1u, text.size() - 2u)); } return script::Value(text); }
float point_segment_distance_squared(Vec3 point, const WallSegment& segment) noexcept { const float dx = segment.end.x - segment.begin.x; const float dz = segment.end.z - segment.begin.z; const float px = point.x - segment.begin.x; const float pz = point.z - segment.begin.z; const float length = dx * dx + dz * dz; const float t = length > 0.0f ? std::clamp((px * dx + pz * dz) / length, 0.0f, 1.0f) : 0.0f; const float ox = point.x - (segment.begin.x + dx * t); const float oz = point.z - (segment.begin.z + dz * t); return ox * ox + oz * oz; }
}

ConnectionArguments parse_connection_arguments(std::span<const std::string_view> arguments, std::string_view config_text) { ConnectionArguments result; if (const auto value = cfg_value(config_text, "LOCALE")) { result.locale = *value; } if (const auto value = cfg_value(config_text, "LOGIN")) { result.login = *value; } if (const auto value = cfg_value(config_text, "GAMEXP_SID")) { result.gamexp_sid = *value; } if (const auto value = cfg_value(config_text, "CONNECT_TYPE")) { result.type = parse_connection_type(*value); } for (std::size_t index = 0; index < arguments.size(); ++index) { const std::string key = lowercase(arguments[index]); const auto next = [&]() -> std::string_view { return index + 1u < arguments.size() ? arguments[++index] : std::string_view{}; }; if (key == "/locale" || key == "-locale") { result.locale = std::string(next()); } else if (key == "/login" || key == "-login") { result.login = std::string(next()); } else if (key == "/gamexp_sid" || key == "-gamexp_sid") { result.gamexp_sid = std::string(next()); } else if (key == "/connect" || key == "-connect") { result.config_file = std::filesystem::path(next()); } else if (key == "/connect_type" || key == "-connect_type") { result.type = parse_connection_type(next()); } } return result; }
void MaterialFilter::set_base_path(std::filesystem::path path) { base_path_ = std::move(path); }
void MaterialFilter::set_words(std::vector<std::string> words) { words_ = std::move(words); for (std::string& word : words_) { word = lowercase(word); } }
bool MaterialFilter::accepts(std::string_view value) const noexcept { if (words_.empty()) { return true; } const std::string text = lowercase(value); return std::any_of(words_.begin(), words_.end(), [&](const std::string& word) { return text.find(word) != std::string::npos; }); }
const std::filesystem::path& MaterialFilter::base_path() const noexcept { return base_path_; }
const std::vector<std::string>& MaterialFilter::words() const noexcept { return words_; }
std::uint32_t ModelPathRegistry::register_folder(std::filesystem::path folder) { folders_.push_back(std::move(folder)); return static_cast<std::uint32_t>(folders_.size() - 1u); }
std::uint32_t ModelPathRegistry::register_model(std::filesystem::path model_path) { const std::string key = lowercase(model_path.filename().string()); if (const auto found = by_name_.find(key); found != by_name_.end()) { return found->second; } const std::uint32_t identifier = static_cast<std::uint32_t>(models_.size()); models_.push_back(std::move(model_path)); by_name_.emplace(key, identifier); return identifier; }
const std::filesystem::path* ModelPathRegistry::model(std::uint32_t identifier) const noexcept { return identifier < models_.size() ? &models_[identifier] : nullptr; }
std::optional<std::uint32_t> ModelPathRegistry::find(std::string_view name) const noexcept { const auto found = by_name_.find(lowercase(name)); return found == by_name_.end() ? std::nullopt : std::optional<std::uint32_t>(found->second); }
std::size_t ModelPathRegistry::size() const noexcept { return models_.size(); }
void ModelPathRegistry::clear() noexcept { folders_.clear(); models_.clear(); by_name_.clear(); }
bool ObjectConfig::parse(std::string_view text) { values_.clear(); std::size_t cursor = 0; while (cursor < text.size()) { const std::size_t end = text.find_first_of("\r\n", cursor); const std::string line = trim_text(text.substr(cursor, end == std::string_view::npos ? text.size() - cursor : end - cursor)); if (!line.empty() && line.front() != '#' && line.front() != ';') { const std::size_t equal = line.find('='); if (equal != std::string::npos) { const std::string key = trim_text(std::string_view(line).substr(0, equal)); const std::string raw = trim_text(std::string_view(line).substr(equal + 1u)); if (!key.empty()) { if (raw.size() >= 2u && raw.front() == '[' && raw.back() == ']') { script::Value sequence = script::Value::sequence(); std::string_view inner(raw.data() + 1u, raw.size() - 2u); std::size_t item_cursor = 0; while (item_cursor <= inner.size()) { const std::size_t comma = inner.find(',', item_cursor); const std::string_view item = inner.substr(item_cursor, comma == std::string_view::npos ? inner.size() - item_cursor : comma - item_cursor); sequence.storage(); script::assign(sequence, script::Value(static_cast<std::uint32_t>(script::size(sequence))), parse_scalar(item)); if (comma == std::string_view::npos) { break; } item_cursor = comma + 1u; } values_[key] = std::move(sequence); } else { values_[key] = parse_scalar(raw); } } } } if (end == std::string_view::npos) { break; } cursor = end + 1u; } return true; }
const script::Value* ObjectConfig::get(std::string_view name) const noexcept { const auto found = values_.find(std::string(name)); return found == values_.end() ? nullptr : &found->second; }
std::size_t ObjectConfig::array_size(std::string_view name) const noexcept { const script::Value* value = get(name); return value ? script::size(*value) : 0u; }
const script::Value* ObjectConfig::at(std::string_view name, std::size_t index) const noexcept { const script::Value* value = get(name); if (!value) { return nullptr; } const auto item = script::find(*value, script::Value(static_cast<std::uint32_t>(index))); if (!item) { return nullptr; } static thread_local script::Value scratch; scratch = *item; return &scratch; }
void ObjectConfig::clear() noexcept { values_.clear(); }
bool QuickFileIndex::add(QuickFileRecord record) { if (record.name.empty()) { return false; } return records_.insert_or_assign(lowercase(record.name), std::move(record)).second; }
const QuickFileRecord* QuickFileIndex::find(std::string_view name) const noexcept { const auto found = records_.find(lowercase(name)); return found == records_.end() ? nullptr : &found->second; }
std::size_t QuickFileIndex::size() const noexcept { return records_.size(); }
void QuickFileIndex::clear() noexcept { records_.clear(); }
void ServerWall::set_segments(std::vector<WallSegment> segments) { segments_ = std::move(segments); }
bool ServerWall::blocks(Vec3 point, float radius) const noexcept { const float radius_squared = std::max(radius, 0.0f) * std::max(radius, 0.0f); return std::any_of(segments_.begin(), segments_.end(), [&](const WallSegment& segment) { return point.y <= std::max(segment.begin.y, segment.end.y) + segment.height && point_segment_distance_squared(point, segment) <= radius_squared; }); }
const std::vector<WallSegment>& ServerWall::segments() const noexcept { return segments_; }
void SpatialIndex::rebuild(std::vector<SpatialEntry> entries) { entries_ = std::move(entries); }
std::vector<std::uint32_t> SpatialIndex::query(Vec3 minimum, Vec3 maximum) const { std::vector<std::uint32_t> result; for (const SpatialEntry& entry : entries_) { const bool overlap = entry.maximum.x >= minimum.x && entry.minimum.x <= maximum.x && entry.maximum.y >= minimum.y && entry.minimum.y <= maximum.y && entry.maximum.z >= minimum.z && entry.minimum.z <= maximum.z; if (overlap) { result.push_back(entry.identifier); } } return result; }
std::vector<std::uint32_t> SpatialIndex::query_radius(Vec3 center, float radius) const { const float safe_radius = std::max(radius, 0.0f); return query({center.x - safe_radius, center.y - safe_radius, center.z - safe_radius}, {center.x + safe_radius, center.y + safe_radius, center.z + safe_radius}); }
std::size_t SpatialIndex::size() const noexcept { return entries_.size(); }
bool TextureSet::assign(std::string name, render::ResourceHandle texture) { if (name.empty() || !texture) { return false; } textures_.insert_or_assign(lowercase(name), texture); return true; }
render::ResourceHandle TextureSet::find(std::string_view name) const noexcept { const auto found = textures_.find(lowercase(name)); return found == textures_.end() ? render::ResourceHandle{} : found->second; }
bool TextureSet::erase(std::string_view name) noexcept { return textures_.erase(lowercase(name)) != 0u; }
std::size_t TextureSet::size() const noexcept { return textures_.size(); }

} // namespace content_runtime

namespace particle_runtime {
namespace {
float cosine_blend(float amount) noexcept { return (1.0f - std::cos(std::clamp(amount, 0.0f, 1.0f) * 3.14159265358979323846f)) * 0.5f; }
float interpolation_amount(float amount, Interpolation mode) noexcept { if (mode == Interpolation::step) { return 0.0f; } return mode == Interpolation::cosine ? cosine_blend(amount) : std::clamp(amount, 0.0f, 1.0f); }
template <typename Key> std::pair<const Key*, const Key*> curve_pair(const std::vector<Key>& keys, float time) noexcept { if (keys.empty()) { return {nullptr, nullptr}; } if (time <= keys.front().time) { return {&keys.front(), &keys.front()}; } if (time >= keys.back().time) { return {&keys.back(), &keys.back()}; } const auto upper = std::upper_bound(keys.begin(), keys.end(), time, [](float value, const Key& key) { return value < key.time; }); return {&*(upper - 1), &*upper}; }
Vec3 add(Vec3 left, Vec3 right) noexcept { return {left.x + right.x, left.y + right.y, left.z + right.z}; }
Vec3 scale(Vec3 value, float amount) noexcept { return {value.x * amount, value.y * amount, value.z * amount}; }
Vec3 interpolate(Vec3 left, Vec3 right, float amount) noexcept { return add(left, scale({right.x - left.x, right.y - left.y, right.z - left.z}, amount)); }
}
void ScalarCurve::set(std::vector<ScalarKey> keys, Interpolation interpolation) { std::sort(keys.begin(), keys.end(), [](const ScalarKey& left, const ScalarKey& right) { return left.time < right.time; }); keys_ = std::move(keys); interpolation_ = interpolation; }
float ScalarCurve::sample(float time, float fallback) const noexcept { const auto [left, right] = curve_pair(keys_, time); if (!left) { return fallback; } if (left == right || right->time <= left->time) { return left->value; } const float amount = interpolation_amount((time - left->time) / (right->time - left->time), interpolation_); return left->value + (right->value - left->value) * amount; }
bool ScalarCurve::empty() const noexcept { return keys_.empty(); }
void VectorCurve::set(std::vector<VectorKey> keys, Interpolation interpolation) { std::sort(keys.begin(), keys.end(), [](const VectorKey& left, const VectorKey& right) { return left.time < right.time; }); keys_ = std::move(keys); interpolation_ = interpolation; }
Vec3 VectorCurve::sample(float time, Vec3 fallback) const noexcept { const auto [left, right] = curve_pair(keys_, time); if (!left) { return fallback; } if (left == right || right->time <= left->time) { return left->value; } return interpolate(left->value, right->value, interpolation_amount((time - left->time) / (right->time - left->time), interpolation_)); }
bool VectorCurve::empty() const noexcept { return keys_.empty(); }
ParticleSystem::ParticleSystem(ParticleSystemDefinition definition, std::uint32_t seed) : definition_(std::move(definition)), random_state_(seed == 0u ? 1u : seed) { particles_.reserve(definition_.maximum_particles); }
void ParticleSystem::set_origin(Vec3 origin) noexcept { origin_ = origin; }
float ParticleSystem::random_unit() noexcept { random_state_ ^= random_state_ << 13u; random_state_ ^= random_state_ >> 17u; random_state_ ^= random_state_ << 5u; return static_cast<float>(random_state_ & 0x00ffffffu) / static_cast<float>(0x01000000u); }
Vec3 ParticleSystem::random_direction() noexcept { const float z = random_unit() * 2.0f - 1.0f; const float angle = random_unit() * 6.28318530717958647692f; const float radius = std::sqrt(std::max(0.0f, 1.0f - z * z)); return {radius * std::cos(angle), z, radius * std::sin(angle)}; }
Vec3 ParticleSystem::spawn_offset() noexcept { const float x = random_unit() * 2.0f - 1.0f; const float y = random_unit() * 2.0f - 1.0f; const float z = random_unit() * 2.0f - 1.0f; if (definition_.emit_shape == EmitShape::line) { return {definition_.emit_extent.x * x, definition_.emit_extent.y * x, definition_.emit_extent.z * x}; } if (definition_.emit_shape == EmitShape::disk || definition_.emit_shape == EmitShape::ring) { const float angle = random_unit() * 6.28318530717958647692f; const float radius = definition_.emit_shape == EmitShape::ring ? 1.0f : std::sqrt(random_unit()); return {std::cos(angle) * definition_.emit_extent.x * radius, 0.0f, std::sin(angle) * definition_.emit_extent.z * radius}; } if (definition_.emit_shape == EmitShape::box) { return {definition_.emit_extent.x * x, definition_.emit_extent.y * y, definition_.emit_extent.z * z}; } if (definition_.emit_shape == EmitShape::cylinder) { const float angle = random_unit() * 6.28318530717958647692f; const float radius = std::sqrt(random_unit()); return {std::cos(angle) * definition_.emit_extent.x * radius, definition_.emit_extent.y * y, std::sin(angle) * definition_.emit_extent.z * radius}; } if (definition_.emit_shape == EmitShape::sphere) { const Vec3 direction = random_direction(); const float radius = std::cbrt(random_unit()); return {direction.x * definition_.emit_extent.x * radius, direction.y * definition_.emit_extent.y * radius, direction.z * definition_.emit_extent.z * radius}; } return {}; }
void ParticleSystem::spawn_one() { if (particles_.size() >= definition_.maximum_particles) { return; } Particle particle; particle.position = add(origin_, spawn_offset()); const Vec3 direction = random_direction(); particle.velocity = scale(direction, definition_.speed * (1.0f + (random_unit() * 2.0f - 1.0f) * definition_.spread)); particle.lifetime = std::max(definition_.lifetime, 0.001f); particle.scale = definition_.scale.sample(0.0f, 1.0f); particle.alpha = definition_.alpha.sample(0.0f, 1.0f); particles_.push_back(particle); }
void ParticleSystem::update(float elapsed_seconds) { if (!(elapsed_seconds > 0.0f)) { return; } emission_credit_ += std::max(definition_.emission_rate, 0.0f) * elapsed_seconds; const std::size_t spawn_count = static_cast<std::size_t>(emission_credit_); emission_credit_ -= static_cast<float>(spawn_count); for (std::size_t index = 0; index < spawn_count; ++index) { spawn_one(); } for (Particle& particle : particles_) { particle.age += elapsed_seconds; const Vec3 acceleration = definition_.acceleration.sample(particle.age, {}); particle.velocity = add(particle.velocity, scale(acceleration, elapsed_seconds)); particle.position = add(particle.position, scale(particle.velocity, elapsed_seconds)); particle.scale = definition_.scale.sample(particle.age, particle.scale); particle.alpha = definition_.alpha.sample(particle.age, particle.alpha); } std::erase_if(particles_, [](const Particle& particle) { return particle.age >= particle.lifetime; }); }
void ParticleSystem::clear() noexcept { particles_.clear(); emission_credit_ = 0.0f; }
bool ParticleSystem::finished() const noexcept { return definition_.emission_rate <= 0.0f && particles_.empty(); }
const ParticleSystemDefinition& ParticleSystem::definition() const noexcept { return definition_; }
const std::vector<Particle>& ParticleSystem::particles() const noexcept { return particles_; }

} // namespace particle_runtime

namespace markup_runtime {
namespace {
std::string trim_markup(std::string_view value) { std::size_t first = 0; while (first < value.size() && std::isspace(static_cast<unsigned char>(value[first]))) { ++first; } std::size_t last = value.size(); while (last > first && std::isspace(static_cast<unsigned char>(value[last - 1u]))) { --last; } return std::string(value.substr(first, last - first)); }
std::vector<std::string> split_words(std::string_view value) { std::vector<std::string> result; std::size_t cursor = 0; while (cursor < value.size()) { while (cursor < value.size() && std::isspace(static_cast<unsigned char>(value[cursor]))) { ++cursor; } if (cursor >= value.size()) { break; } const std::size_t begin = cursor; bool quoted = false; char quote = 0; while (cursor < value.size()) { const char ch = value[cursor]; if (!quoted && (ch == '"' || ch == '\'')) { quoted = true; quote = ch; } else if (quoted && ch == quote) { quoted = false; } else if (!quoted && std::isspace(static_cast<unsigned char>(ch))) { break; } ++cursor; } result.emplace_back(value.substr(begin, cursor - begin)); } return result; }
void collect_nodes(const Node& node, std::string_view tag, std::vector<const Node*>& result) { if (node.tag == tag) { result.push_back(&node); } for (const Node& child : node.children) { collect_nodes(child, tag, result); } }
void collect_text(const Node& node, std::string& result) { if (!node.text.empty()) { if (!result.empty() && !std::isspace(static_cast<unsigned char>(result.back()))) { result.push_back(' '); } result += node.text; } for (const Node& child : node.children) { collect_text(child, result); } }
}
const Attribute* Node::attribute(std::string_view name) const noexcept { const auto found = std::find_if(attributes.begin(), attributes.end(), [&](const Attribute& item) { return item.name == name; }); return found == attributes.end() ? nullptr : &*found; }
bool Document::parse(std::string_view text) { root_ = Node{"document", {}, {}, {}}; std::vector<Node*> stack{&root_}; std::size_t cursor = 0; while (cursor < text.size()) { const std::size_t open = text.find('<', cursor); if (open == std::string_view::npos) { const std::string trailing = trim_markup(text.substr(cursor)); if (!trailing.empty()) { stack.back()->children.push_back(Node{"text", trailing, {}, {}}); } break; } const std::string before = trim_markup(text.substr(cursor, open - cursor)); if (!before.empty()) { stack.back()->children.push_back(Node{"text", before, {}, {}}); } const std::size_t close = text.find('>', open + 1u); if (close == std::string_view::npos) { return false; } std::string token = trim_markup(text.substr(open + 1u, close - open - 1u)); if (!token.empty() && token.front() == '!') { cursor = close + 1u; continue; } if (!token.empty() && token.front() == '/') { if (stack.size() > 1u) { stack.pop_back(); } cursor = close + 1u; continue; } const bool self_closing = !token.empty() && token.back() == '/'; if (self_closing) { token.pop_back(); token = trim_markup(token); } const std::vector<std::string> words = split_words(token); if (!words.empty()) { Node node; node.tag = words.front(); for (std::size_t index = 1; index < words.size(); ++index) { const std::size_t equal = words[index].find('='); if (equal == std::string::npos) { node.attributes.push_back({words[index], {}}); continue; } std::string value = words[index].substr(equal + 1u); if (value.size() >= 2u && ((value.front() == '"' && value.back() == '"') || (value.front() == '\'' && value.back() == '\''))) { value = value.substr(1u, value.size() - 2u); } node.attributes.push_back({words[index].substr(0, equal), std::move(value)}); } stack.back()->children.push_back(std::move(node)); if (!self_closing) { stack.push_back(&stack.back()->children.back()); } } cursor = close + 1u; } return true; }
const Node& Document::root() const noexcept { return root_; }
std::vector<const Node*> Document::find(std::string_view tag) const { std::vector<const Node*> result; collect_nodes(root_, tag, result); return result; }
std::string Document::plain_text() const { std::string result; collect_text(root_, result); return result; }
bool SimpleParser::parse(std::string_view text) { values_.clear(); std::size_t cursor = 0; while (cursor < text.size()) { const std::size_t end = text.find_first_of("\r\n", cursor); const std::string line = trim_markup(text.substr(cursor, end == std::string_view::npos ? text.size() - cursor : end - cursor)); if (!line.empty() && line.front() != '#' && line.front() != ';') { const std::size_t separator = line.find_first_of("=:"); if (separator != std::string::npos) { values_[trim_markup(std::string_view(line).substr(0, separator))].push_back(trim_markup(std::string_view(line).substr(separator + 1u))); } else { const std::vector<std::string> words = split_words(line); if (words.size() > 1u) { values_[words.front()].emplace_back(line.substr(words.front().size() + 1u)); } } } if (end == std::string_view::npos) { break; } cursor = end + 1u; } return true; }
std::optional<std::string_view> SimpleParser::value(std::string_view key) const noexcept { const auto found = values_.find(std::string(key)); return found == values_.end() || found->second.empty() ? std::nullopt : std::optional<std::string_view>(found->second.front()); }
std::span<const std::string> SimpleParser::values(std::string_view key) const noexcept { const auto found = values_.find(std::string(key)); return found == values_.end() ? std::span<const std::string>{} : std::span<const std::string>(found->second); }
void SimpleParser::clear() noexcept { values_.clear(); }

} // namespace markup_runtime

namespace environment_runtime {
namespace {
float wrap_time(float value, float period) noexcept { if (!(period > 0.0f)) { return 0.0f; } value = std::fmod(value, period); return value < 0.0f ? value + period : value; }
SkyState blend_sky(const SkyState& left, const SkyState& right, float amount) noexcept { const auto blend = [amount](float a, float b) { return a + (b - a) * amount; }; SkyState result; result.time = blend(left.time, right.time); result.sun_color = {blend(left.sun_color.x, right.sun_color.x), blend(left.sun_color.y, right.sun_color.y), blend(left.sun_color.z, right.sun_color.z)}; result.sky_color = {blend(left.sky_color.x, right.sky_color.x), blend(left.sky_color.y, right.sky_color.y), blend(left.sky_color.z, right.sky_color.z)}; result.fog_color = {blend(left.fog_color.x, right.fog_color.x), blend(left.fog_color.y, right.fog_color.y), blend(left.fog_color.z, right.fog_color.z)}; result.fog_density = blend(left.fog_density, right.fog_density); result.sun_intensity = blend(left.sun_intensity, right.sun_intensity); return result; }
}
bool SkyTimeline::set(std::vector<SkyState> states, float day_length) { if (states.empty() || !(day_length > 0.0f)) { return false; } std::sort(states.begin(), states.end(), [](const SkyState& left, const SkyState& right) { return left.time < right.time; }); states_ = std::move(states); day_length_ = day_length; return true; }
SkyState SkyTimeline::sample(float time) const noexcept { if (states_.empty()) { return {}; } if (states_.size() == 1u) { return states_.front(); } const float local = wrap_time(time, day_length_); auto upper = std::upper_bound(states_.begin(), states_.end(), local, [](float value, const SkyState& state) { return value < state.time; }); const SkyState* right = upper == states_.end() ? &states_.front() : &*upper; const SkyState* left = upper == states_.begin() ? &states_.back() : &*(upper - 1); float left_time = left->time; float right_time = right->time; float sample_time = local; if (right_time <= left_time) { right_time += day_length_; if (sample_time < left_time) { sample_time += day_length_; } } const float amount = right_time > left_time ? (sample_time - left_time) / (right_time - left_time) : 0.0f; return blend_sky(*left, *right, std::clamp(amount, 0.0f, 1.0f)); }
float SkyTimeline::day_length() const noexcept { return day_length_; }
SnowField::SnowField(Vec3 minimum, Vec3 maximum, float rate, std::uint32_t seed) : minimum_(minimum), maximum_(maximum), rate_(std::max(rate, 0.0f)), random_state_(seed == 0u ? 1u : seed) {}
float SnowField::random_unit() noexcept { random_state_ ^= random_state_ << 13u; random_state_ ^= random_state_ >> 17u; random_state_ ^= random_state_ << 5u; return static_cast<float>(random_state_ & 0x00ffffffu) / static_cast<float>(0x01000000u); }
void SnowField::update(float elapsed_seconds) { if (!(elapsed_seconds > 0.0f)) { return; } credit_ += rate_ * elapsed_seconds; const std::size_t count = static_cast<std::size_t>(credit_); credit_ -= static_cast<float>(count); for (std::size_t index = 0; index < count; ++index) { const float x = minimum_.x + (maximum_.x - minimum_.x) * random_unit(); const float z = minimum_.z + (maximum_.z - minimum_.z) * random_unit(); const float speed = 0.5f + random_unit() * 1.5f; flakes_.push_back({{x, maximum_.y, z}, speed, 0.0f}); } for (SnowFlake& flake : flakes_) { flake.position.y -= flake.speed * elapsed_seconds; flake.lifetime += elapsed_seconds; } std::erase_if(flakes_, [&](const SnowFlake& flake) { return flake.position.y < minimum_.y; }); }
void SnowField::set_rate(float rate) noexcept { rate_ = std::max(rate, 0.0f); }
void SnowField::clear() noexcept { flakes_.clear(); credit_ = 0.0f; }
const std::vector<SnowFlake>& SnowField::flakes() const noexcept { return flakes_; }

} // namespace environment_runtime

namespace media_runtime {
bool SoundEffectCatalog::store(SoundEffectProfile profile, bool replace) { if (profile.name.empty() || profile.files.empty()) { return false; } if (!replace && profiles_.contains(profile.name)) { return false; } profiles_.insert_or_assign(profile.name, std::move(profile)); return true; }
const SoundEffectProfile* SoundEffectCatalog::find(std::string_view name) const noexcept { const auto found = profiles_.find(std::string(name)); return found == profiles_.end() ? nullptr : &found->second; }
std::optional<std::string> SoundEffectCatalog::choose(std::string_view name, std::uint32_t selector) const { const SoundEffectProfile* profile = find(name); if (!profile || profile->files.empty()) { return std::nullopt; } if (profile->playback == SoundPlayback::single || profile->playback == SoundPlayback::looped) { return profile->files.front(); } return profile->files[selector % profile->files.size()]; }
void Playlist::set(std::vector<Track> tracks) { tracks_ = std::move(tracks); index_ = 0u; }
const Track* Playlist::current() const noexcept { return tracks_.empty() ? nullptr : &tracks_[std::min(index_, tracks_.size() - 1u)]; }
const Track* Playlist::next() noexcept { if (tracks_.empty()) { return nullptr; } index_ = (index_ + 1u) % tracks_.size(); return &tracks_[index_]; }
const Track* Playlist::previous() noexcept { if (tracks_.empty()) { return nullptr; } index_ = index_ == 0u ? tracks_.size() - 1u : index_ - 1u; return &tracks_[index_]; }
void Playlist::reset() noexcept { index_ = 0u; }
std::size_t Playlist::size() const noexcept { return tracks_.size(); }

} // namespace media_runtime

namespace client_runtime {
void NetworkConnectionChecker::begin(std::string host) { host_ = std::move(host); running_ = !host_.empty(); reachable_ = false; latency_ = {}; }
void NetworkConnectionChecker::complete(bool reachable, std::chrono::milliseconds latency) { reachable_ = reachable; latency_ = reachable ? std::max(latency, std::chrono::milliseconds::zero()) : std::chrono::milliseconds::zero(); running_ = false; }
const std::string& NetworkConnectionChecker::host() const noexcept { return host_; }
bool NetworkConnectionChecker::running() const noexcept { return running_; }
bool NetworkConnectionChecker::reachable() const noexcept { return reachable_; }
std::chrono::milliseconds NetworkConnectionChecker::latency() const noexcept { return latency_; }
void UpdateManager::begin(std::vector<UpdatePackage> packages) { packages_ = std::move(packages); downloaded_.clear(); error_.clear(); state_ = packages_.empty() ? UpdateState::ready : UpdateState::downloading; }
void UpdateManager::mark_downloaded(std::string_view name) { if (state_ != UpdateState::downloading) { return; } downloaded_.insert(std::string(name)); if (downloaded_.size() >= packages_.size()) { state_ = UpdateState::ready; } }
void UpdateManager::fail(std::string reason) { error_ = std::move(reason); state_ = UpdateState::failed; }
UpdateState UpdateManager::state() const noexcept { return state_; }
float UpdateManager::progress() const noexcept { return packages_.empty() ? 1.0f : static_cast<float>(downloaded_.size()) / static_cast<float>(packages_.size()); }
const std::string& UpdateManager::error() const noexcept { return error_; }

} // namespace client_runtime

namespace ui_runtime {
namespace {
std::string trim_ui(std::string_view value) { std::size_t first = 0; while (first < value.size() && std::isspace(static_cast<unsigned char>(value[first]))) { ++first; } std::size_t last = value.size(); while (last > first && std::isspace(static_cast<unsigned char>(value[last - 1u]))) { --last; } return std::string(value.substr(first, last - first)); }
std::optional<long> parse_long(std::string_view value) noexcept { const std::string text = trim_ui(value); char* end = nullptr; const long result = std::strtol(text.c_str(), &end, 0); return end && *end == '\0' ? std::optional<long>(result) : std::nullopt; }
std::optional<float> parse_float(std::string_view value) noexcept { const std::string text = trim_ui(value); char* end = nullptr; const float result = std::strtof(text.c_str(), &end); return end && *end == '\0' ? std::optional<float>(result) : std::nullopt; }
}
std::int32_t Rect::width() const noexcept { return right - left; }
std::int32_t Rect::height() const noexcept { return bottom - top; }
bool Rect::contains(Point point) const noexcept { return point.x >= left && point.y >= top && point.x < right && point.y < bottom; }
void PropertyBag::set(std::string key, std::string value) { values_.insert_or_assign(std::move(key), std::move(value)); }
std::optional<std::string_view> PropertyBag::get(std::string_view key) const noexcept { const auto found = values_.find(std::string(key)); return found == values_.end() ? std::nullopt : std::optional<std::string_view>(found->second); }
std::optional<std::int32_t> PropertyBag::integer(std::string_view key) const noexcept { const auto raw = get(key); if (!raw) { return std::nullopt; } const auto value = parse_long(*raw); return value ? std::optional<std::int32_t>(static_cast<std::int32_t>(*value)) : std::nullopt; }
std::optional<float> PropertyBag::floating(std::string_view key) const noexcept { const auto raw = get(key); return raw ? parse_float(*raw) : std::nullopt; }
bool PropertyBag::boolean(std::string_view key, bool fallback) const noexcept { const auto raw = get(key); if (!raw) { return fallback; } std::string value(*raw); std::transform(value.begin(), value.end(), value.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); }); return value == "1" || value == "true" || value == "yes" || value == "on"; }
bool HyperText::parse(std::string_view text) { runs_.clear(); markup_runtime::Document document; if (!document.parse(text)) { return false; } std::function<void(const markup_runtime::Node&, bool, std::string)> visit = [&](const markup_runtime::Node& node, bool inherited_link, std::string inherited_target) { bool link = inherited_link; std::string target = std::move(inherited_target); if (node.tag == "a" || node.tag == "hts" || node.tag == "mailto" || node.tag == "item" || node.tag == "player") { link = true; if (const auto* href = node.attribute("href")) { target = href->value; } else if (const auto* value = node.attribute("value")) { target = value->value; } } if (node.tag == "text" && !node.text.empty()) { runs_.push_back({node.text, {}, link, target}); } for (const auto& child : node.children) { visit(child, link, target); } }; visit(document.root(), false, {}); return true; }
const std::vector<TextRun>& HyperText::runs() const noexcept { return runs_; }
std::string HyperText::plain_text() const { std::string result; for (const TextRun& run : runs_) { result += run.text; } return result; }
void ListModel::set(std::vector<std::string> items) { items_ = std::move(items); if (selection_ && *selection_ >= items_.size()) { selection_.reset(); } }
void ListModel::append(std::string item) { items_.push_back(std::move(item)); }
bool ListModel::erase(std::size_t index) noexcept { if (index >= items_.size()) { return false; } items_.erase(items_.begin() + static_cast<std::ptrdiff_t>(index)); if (selection_) { if (*selection_ == index) { selection_.reset(); } else if (*selection_ > index) { --*selection_; } } return true; }
bool ListModel::select(std::size_t index) noexcept { if (index >= items_.size()) { return false; } selection_ = index; return true; }
std::optional<std::size_t> ListModel::selection() const noexcept { return selection_; }
std::span<const std::string> ListModel::items() const noexcept { return items_; }
void RangeModel::set_range(float minimum, float maximum) noexcept { if (maximum < minimum) { std::swap(minimum, maximum); } minimum_ = minimum; maximum_ = maximum; set_value(value_); }
void RangeModel::set_value(float value) noexcept { value_ = std::clamp(value, minimum_, maximum_); }
void RangeModel::set_step(float step) noexcept { step_ = std::max(step, 0.0f); }
float RangeModel::minimum() const noexcept { return minimum_; }
float RangeModel::maximum() const noexcept { return maximum_; }
float RangeModel::value() const noexcept { return value_; }
float RangeModel::step() const noexcept { return step_; }
float RangeModel::ratio() const noexcept { return maximum_ > minimum_ ? (value_ - minimum_) / (maximum_ - minimum_) : 0.0f; }
void RangeModel::increment() noexcept { set_value(value_ + step_); }
void RangeModel::decrement() noexcept { set_value(value_ - step_); }
void HelpIndex::set(std::string control, std::string topic) { if (!control.empty()) { topics_.insert_or_assign(std::move(control), std::move(topic)); } }
std::optional<std::string_view> HelpIndex::find(std::string_view control) const noexcept { const auto found = topics_.find(std::string(control)); return found == topics_.end() ? std::nullopt : std::optional<std::string_view>(found->second); }
bool HelpIndex::erase(std::string_view control) noexcept { return topics_.erase(std::string(control)) != 0u; }
void HelpIndex::clear() noexcept { topics_.clear(); }
std::size_t HelpIndex::size() const noexcept { return topics_.size(); }
bool InterfaceModel::add(Control control) { if (control.id == 0u || controls_.contains(control.id) || (!control.name.empty() && by_name_.contains(control.name))) { return false; } if (!control.name.empty()) { by_name_[control.name] = control.id; } controls_.emplace(control.id, std::move(control)); return true; }
bool InterfaceModel::remove(std::uint32_t id) noexcept { const auto found = controls_.find(id); if (found == controls_.end()) { return false; } if (!found->second.name.empty()) { by_name_.erase(found->second.name); } if (focus_ == id) { focus_ = 0u; } controls_.erase(found); return true; }
Control* InterfaceModel::find(std::uint32_t id) noexcept { const auto found = controls_.find(id); return found == controls_.end() ? nullptr : &found->second; }
const Control* InterfaceModel::find(std::uint32_t id) const noexcept { const auto found = controls_.find(id); return found == controls_.end() ? nullptr : &found->second; }
Control* InterfaceModel::find(std::string_view name) noexcept { const auto found = by_name_.find(std::string(name)); return found == by_name_.end() ? nullptr : find(found->second); }
void InterfaceModel::set_focus(std::uint32_t id) noexcept { if (Control* current = find(focus_)) { current->focused = false; } focus_ = find(id) ? id : 0u; if (Control* next = find(focus_)) { next->focused = true; } }
std::uint32_t InterfaceModel::focus() const noexcept { return focus_; }
void InterfaceModel::set_cursor(std::string cursor) { cursor_ = std::move(cursor); }
const std::string& InterfaceModel::cursor() const noexcept { return cursor_; }
void InterfaceModel::register_sprite(SpriteDefinition sprite_definition) { if (!sprite_definition.name.empty()) { sprites_.insert_or_assign(sprite_definition.name, std::move(sprite_definition)); } }
void InterfaceModel::register_font(FontDefinition font_definition) { if (!font_definition.name.empty()) { fonts_.insert_or_assign(font_definition.name, std::move(font_definition)); } }
const SpriteDefinition* InterfaceModel::sprite(std::string_view name) const noexcept { const auto found = sprites_.find(std::string(name)); return found == sprites_.end() ? nullptr : &found->second; }
const FontDefinition* InterfaceModel::font(std::string_view name) const noexcept { const auto found = fonts_.find(std::string(name)); return found == fonts_.end() ? nullptr : &found->second; }
std::vector<std::uint32_t> InterfaceModel::hit_test(Point point) const { std::vector<std::uint32_t> result; for (const auto& [id, control] : controls_) { if (control.visible && control.enabled && control.bounds.contains(point)) { result.push_back(id); } } std::sort(result.begin(), result.end()); return result; }
std::size_t InterfaceModel::size() const noexcept { return controls_.size(); }
InterfaceOptions& InterfaceModel::options() noexcept { return options_; }
const InterfaceOptions& InterfaceModel::options() const noexcept { return options_; }

} // namespace ui_runtime

namespace compiler_runtime {
namespace {

std::uint64_t signed_magnitude(std::int64_t value) noexcept {
    const std::uint64_t bits = std::bit_cast<std::uint64_t>(value);
    return value < 0 ? 0u - bits : bits;
}

std::int64_t signed_bits(std::uint64_t magnitude, bool negative) noexcept {
    const std::uint64_t bits = negative ? 0u - magnitude : magnitude;
    return std::bit_cast<std::int64_t>(bits);
}

} // namespace

void* copy_memory(void* destination, const void* source, std::uint32_t size) {
    return g_runtime.copy_memory ? g_runtime.copy_memory(destination, source, size) : std::memcpy(destination, source, size);
}

void* fill_memory(void* destination, std::int32_t value, std::uint32_t size) {
    return std::memset(destination, value, size);
}

std::int64_t signed_divide(std::int64_t dividend, std::int64_t divisor) {
    if (divisor == 0) { throw std::domain_error("Signed division by zero"); }
    const std::uint64_t quotient = signed_magnitude(dividend) / signed_magnitude(divisor);
    return signed_bits(quotient, (dividend < 0) != (divisor < 0));
}

std::int64_t signed_remainder(std::int64_t dividend, std::int64_t divisor) {
    if (divisor == 0) { throw std::domain_error("Signed remainder by zero"); }
    const std::uint64_t remainder = signed_magnitude(dividend) % signed_magnitude(divisor);
    return signed_bits(remainder, dividend < 0);
}

std::uint64_t unsigned_divide(std::uint64_t dividend, std::uint64_t divisor) {
    if (divisor == 0u) { throw std::domain_error("Unsigned division by zero"); }
    return dividend / divisor;
}

std::uint64_t multiply(std::uint64_t left, std::uint64_t right) {
    return left * right;
}

} // namespace compiler_runtime

// <verified-semantic-components>

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#endif
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4244)
#endif
namespace zlib113 {

using Byte = std::uint8_t;
using uInt = std::uint32_t;
using uLong = std::uint32_t;
using Bytef = Byte;
using uLongf = uLong;

constexpr int ok = 0;
constexpr int stream_end = 1;
constexpr int stream_error = -2;
constexpr int data_error = -3;
constexpr int memory_error = -4;
constexpr int buffer_error = -5;
constexpr int version_error = -6;
constexpr int default_compression = -1;

uLong adler32(uLong checksum, const Bytef* bytes, uInt size) {
    constexpr uLong modulus = 65521u;
    constexpr uInt maximum_chunk = 5552u;
    uLong first = checksum & 0xffffu;
    uLong second = checksum >> 16u;
    if (!bytes) { return 1u; }
    while (size != 0u) {
        uInt chunk = std::min(size, maximum_chunk);
        size -= chunk;
        while (chunk-- != 0u) {
            first += *bytes++;
            second += first;
        }
        first %= modulus;
        second %= modulus;
    }
    return second << 16u | first;
}

} // namespace zlib113

#define ZLIB_VERSION "1.1.3"
#define Z_NO_FLUSH 0
#define Z_PARTIAL_FLUSH 1
#define Z_SYNC_FLUSH 2
#define Z_FULL_FLUSH 3
#define Z_FINISH 4
#define Z_OK 0
#define Z_STREAM_END 1
#define Z_NEED_DICT 2
#define Z_ERRNO (-1)
#define Z_STREAM_ERROR (-2)
#define Z_DATA_ERROR (-3)
#define Z_MEM_ERROR (-4)
#define Z_BUF_ERROR (-5)
#define Z_VERSION_ERROR (-6)
#define Z_NO_COMPRESSION 0
#define Z_BEST_SPEED 1
#define Z_BEST_COMPRESSION 9
#define Z_DEFAULT_COMPRESSION (-1)
#define Z_FILTERED 1
#define Z_HUFFMAN_ONLY 2
#define Z_DEFAULT_STRATEGY 0
#define Z_BINARY 0
#define Z_ASCII 1
#define Z_UNKNOWN 2
#define Z_DEFLATED 8
#define Z_NULL 0
#define MAX_MEM_LEVEL 9
#define MAX_WBITS 15
#define DEF_WBITS MAX_WBITS
#define DEF_MEM_LEVEL 8
#define STORED_BLOCK 0
#define STATIC_TREES 1
#define DYN_TREES 2
#define MIN_MATCH 3
#define MAX_MATCH 258
#define PRESET_DICT 0x20
#define OS_CODE 0x0b
#define FAR
#define ZEXPORT
#define OF(args) args
#define local static
#define HAVE_MEMCPY
#define NO_DUMMY_DECL
#define Assert(condition, message)
#define Trace(arguments)
#define Tracev(arguments)
#define Tracevv(arguments)
#define Tracec(condition, arguments)
#define Tracecv(condition, arguments)
#define zmemcpy(destination, source, size) ::sfera::semantic::compiler_runtime::copy_memory((destination), (source), (size))
#define zmemcmp(left, right, size) std::memcmp((left), (right), (size))
#define zmemzero(destination, size) std::memset((destination), 0, (size))

namespace zlib113::compression {
using Byte = zlib113::Byte;
using uInt = zlib113::uInt;
using uLong = zlib113::uLong;
using Bytef = Byte;
using charf = char;
using intf = int;
using uIntf = uInt;
using uLongf = uLong;
using voidpf = void*;
using voidp = void*;
using uch = unsigned char;
using uchf = uch;
using ush = unsigned short;
using ushf = ush;
using ulg = uLong;

struct internal_state;

using alloc_func = voidpf (*)(voidpf opaque, uInt items, uInt size);
using free_func = void (*)(voidpf opaque, voidpf address);

struct z_stream {
    Bytef* next_in{};
    uInt avail_in{};
    uLong total_in{};
    Bytef* next_out{};
    uInt avail_out{};
    uLong total_out{};
    char* msg{};
    internal_state* state{};
    alloc_func zalloc{};
    free_func zfree{};
    voidpf opaque{};
    int data_type{};
    uLong adler{};
    uLong reserved{};
};

using z_streamp = z_stream*;
using check_func = uLong (*)(uLong check, const Bytef* bytes, uInt size);

constexpr const char* z_errmsg[10] = {
    "need dictionary", "stream end", "", "file error", "stream error",
    "data error", "insufficient memory", "buffer error", "incompatible version", ""
};

voidpf zcalloc(voidpf, unsigned items, unsigned size) { return std::calloc(items, size); }
void zcfree(voidpf, voidpf address) { std::free(address); }
using zlib113::adler32;

#define ERR_MSG(error) z_errmsg[Z_NEED_DICT - (error)]
#define ERR_RETURN(stream, error) return ((stream)->msg = const_cast<char*>(ERR_MSG(error)), (error))
#define ZALLOC(stream, items, size) (*((stream)->zalloc))((stream)->opaque, (items), (size))
#define ZFREE(stream, address) (*((stream)->zfree))((stream)->opaque, static_cast<voidpf>(address))
#define TRY_FREE(stream, pointer) do { if (pointer) { ZFREE((stream), (pointer)); } } while (false)

/* deflate.h -- internal compression state
 * Copyright (C) 1995-1998 Jean-loup Gailly
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */

/* WARNING: this file should *not* be used by applications. It is
   part of the implementation of the compression library and is
   subject to change. Applications should only use zlib.h.
 */

/* @(#) $Id$ */

#ifndef _DEFLATE_H
#define _DEFLATE_H

/* ===========================================================================
 * Internal compression state.
 */

#define LENGTH_CODES 29
/* number of length codes, not counting the special END_BLOCK code */

#define LITERALS  256
/* number of literal bytes 0..255 */

#define L_CODES (LITERALS+1+LENGTH_CODES)
/* number of Literal or Length codes, including the END_BLOCK code */

#define D_CODES   30
/* number of distance codes */

#define BL_CODES  19
/* number of codes used to transfer the bit lengths */

#define HEAP_SIZE (2*L_CODES+1)
/* maximum heap size */

#define MAX_BITS 15
/* All codes must not exceed MAX_BITS bits */

#define INIT_STATE    42
#define BUSY_STATE   113
#define FINISH_STATE 666
/* Stream status */


/* Data structure describing a single value and its code string. */
typedef struct ct_data_s {
    union {
        ush  freq;       /* frequency count */
        ush  code;       /* bit string */
    } fc;
    union {
        ush  dad;        /* father node in Huffman tree */
        ush  len;        /* length of bit string */
    } dl;
} FAR ct_data;

#define Freq fc.freq
#define Code fc.code
#define Dad  dl.dad
#define Len  dl.len

typedef struct static_tree_desc_s  static_tree_desc;

typedef struct tree_desc_s {
    ct_data *dyn_tree;           /* the dynamic tree */
    int     max_code;            /* largest code with non zero frequency */
    static_tree_desc *stat_desc; /* the corresponding static tree */
} FAR tree_desc;

typedef ush Pos;
typedef Pos FAR Posf;
typedef unsigned IPos;

/* A Pos is an index in the character window. We use short instead of int to
 * save space in the various tables. IPos is used only for parameter passing.
 */

typedef struct internal_state {
    z_streamp strm;      /* pointer back to this zlib stream */
    int   status;        /* as the name implies */
    Bytef *pending_buf;  /* output still pending */
    ulg   pending_buf_size; /* size of pending_buf */
    Bytef *pending_out;  /* next pending byte to output to the stream */
    int   pending;       /* nb of bytes in the pending buffer */
    int   noheader;      /* suppress zlib header and adler32 */
    Byte  data_type;     /* UNKNOWN, BINARY or ASCII */
    Byte  method;        /* STORED (for zip only) or DEFLATED */
    int   last_flush;    /* value of flush param for previous deflate call */

                /* used by deflate.c: */

    uInt  w_size;        /* LZ77 window size (32K by default) */
    uInt  w_bits;        /* log2(w_size)  (8..16) */
    uInt  w_mask;        /* w_size - 1 */

    Bytef *window;
    /* Sliding window. Input bytes are read into the second half of the window,
     * and move to the first half later to keep a dictionary of at least wSize
     * bytes. With this organization, matches are limited to a distance of
     * wSize-MAX_MATCH bytes, but this ensures that IO is always
     * performed with a length multiple of the block size. Also, it limits
     * the window size to 64K, which is quite useful on MSDOS.
     * To do: use the user input buffer as sliding window.
     */

    ulg window_size;
    /* Actual size of window: 2*wSize, except when the user input buffer
     * is directly used as sliding window.
     */

    Posf *prev;
    /* Link to older string with same hash index. To limit the size of this
     * array to 64K, this link is maintained only for the last 32K strings.
     * An index in this array is thus a window index modulo 32K.
     */

    Posf *head; /* Heads of the hash chains or NIL. */

    uInt  ins_h;          /* hash index of string to be inserted */
    uInt  hash_size;      /* number of elements in hash table */
    uInt  hash_bits;      /* log2(hash_size) */
    uInt  hash_mask;      /* hash_size-1 */

    uInt  hash_shift;
    /* Number of bits by which ins_h must be shifted at each input
     * step. It must be such that after MIN_MATCH steps, the oldest
     * byte no longer takes part in the hash key, that is:
     *   hash_shift * MIN_MATCH >= hash_bits
     */

    long block_start;
    /* Window position at the beginning of the current output block. Gets
     * negative when the window is moved backwards.
     */

    uInt match_length;           /* length of best match */
    IPos prev_match;             /* previous match */
    int match_available;         /* set if previous match exists */
    uInt strstart;               /* start of string to insert */
    uInt match_start;            /* start of matching string */
    uInt lookahead;              /* number of valid bytes ahead in window */

    uInt prev_length;
    /* Length of the best match at previous step. Matches not greater than this
     * are discarded. This is used in the lazy match evaluation.
     */

    uInt max_chain_length;
    /* To speed up deflation, hash chains are never searched beyond this
     * length.  A higher limit improves compression ratio but degrades the
     * speed.
     */

    uInt max_lazy_match;
    /* Attempt to find a better match only when the current match is strictly
     * smaller than this value. This mechanism is used only for compression
     * levels >= 4.
     */
#   define max_insert_length  max_lazy_match
    /* Insert new strings in the hash table only if the match length is not
     * greater than this length. This saves time but degrades compression.
     * max_insert_length is used only for compression levels <= 3.
     */

    int level;    /* compression level (1..9) */
    int strategy; /* favor or force Huffman coding*/

    uInt good_match;
    /* Use a faster search when the previous match is longer than this */

    int nice_match; /* Stop searching when current match exceeds this */

                /* used by trees.c: */
    /* Didn't use ct_data typedef below to supress compiler warning */
    struct ct_data_s dyn_ltree[HEAP_SIZE];   /* literal and length tree */
    struct ct_data_s dyn_dtree[2*D_CODES+1]; /* distance tree */
    struct ct_data_s bl_tree[2*BL_CODES+1];  /* Huffman tree for bit lengths */

    struct tree_desc_s l_desc;               /* desc. for literal tree */
    struct tree_desc_s d_desc;               /* desc. for distance tree */
    struct tree_desc_s bl_desc;              /* desc. for bit length tree */

    ush bl_count[MAX_BITS+1];
    /* number of codes at each bit length for an optimal tree */

    int heap[2*L_CODES+1];      /* heap used to build the Huffman trees */
    int heap_len;               /* number of elements in the heap */
    int heap_max;               /* element of largest frequency */
    /* The sons of heap[n] are heap[2*n] and heap[2*n+1]. heap[0] is not used.
     * The same heap array is used to build all trees.
     */

    uch depth[2*L_CODES+1];
    /* Depth of each subtree used as tie breaker for trees of equal frequency
     */

    uchf *l_buf;          /* buffer for literals or lengths */

    uInt  lit_bufsize;
    /* Size of match buffer for literals/lengths.  There are 4 reasons for
     * limiting lit_bufsize to 64K:
     *   - frequencies can be kept in 16 bit counters
     *   - if compression is not successful for the first block, all input
     *     data is still in the window so we can still emit a stored block even
     *     when input comes from standard input.  (This can also be done for
     *     all blocks if lit_bufsize is not greater than 32K.)
     *   - if compression is not successful for a file smaller than 64K, we can
     *     even emit a stored file instead of a stored block (saving 5 bytes).
     *     This is applicable only for zip (not gzip or zlib).
     *   - creating new Huffman trees less frequently may not provide fast
     *     adaptation to changes in the input data statistics. (Take for
     *     example a binary file with poorly compressible code followed by
     *     a highly compressible string table.) Smaller buffer sizes give
     *     fast adaptation but have of course the overhead of transmitting
     *     trees more frequently.
     *   - I can't count above 4
     */

    uInt last_lit;      /* running index in l_buf */

    ushf *d_buf;
    /* Buffer for distances. To simplify the code, d_buf and l_buf have
     * the same number of elements. To use different lengths, an extra flag
     * array would be necessary.
     */

    ulg opt_len;        /* bit length of current block with optimal trees */
    ulg static_len;     /* bit length of current block with static trees */
    uInt matches;       /* number of string matches in current block */
    int last_eob_len;   /* bit length of EOB code for last block */

#ifdef DEBUG
    ulg compressed_len; /* total bit length of compressed file mod 2^32 */
    ulg bits_sent;      /* bit length of compressed data sent mod 2^32 */
#endif

    ush bi_buf;
    /* Output buffer. bits are inserted starting at the bottom (least
     * significant bits).
     */
    int bi_valid;
    /* Number of valid bits in bi_buf.  All bits above the last valid bit
     * are always zero.
     */

} FAR deflate_state;

/* Output a byte on the stream.
 * IN assertion: there is enough room in pending_buf.
 */
#define put_byte(s, c) {s->pending_buf[s->pending++] = (c);}


#define MIN_LOOKAHEAD (MAX_MATCH+MIN_MATCH+1)
/* Minimum amount of lookahead, except at the end of the input file.
 * See deflate.c for comments about the MIN_MATCH+1.
 */

#define MAX_DIST(s)  ((s)->w_size-MIN_LOOKAHEAD)
/* In order to simplify the code, particularly on 16 bit machines, match
 * distances are limited to MAX_DIST instead of WSIZE.
 */

        /* in trees.c */
void _tr_init         OF((deflate_state *s));
int  _tr_tally        OF((deflate_state *s, unsigned dist, unsigned lc));
void _tr_flush_block  OF((deflate_state *s, charf *buf, ulg stored_len,
			  int eof));
void _tr_align        OF((deflate_state *s));
void _tr_stored_block OF((deflate_state *s, charf *buf, ulg stored_len,
                          int eof));

#define d_code(dist) \
   ((dist) < 256 ? _dist_code[dist] : _dist_code[256+((dist)>>7)])
/* Mapping from a distance to a distance code. dist is the distance - 1 and
 * must not have side effects. _dist_code[256] and _dist_code[257] are never
 * used.
 */

#ifndef DEBUG
/* Inline versions of _tr_tally for speed: */

#if defined(GEN_TREES_H) || !defined(STDC)
  extern uch _length_code[];
  extern uch _dist_code[];
#else
  extern const uch _length_code[];
  extern const uch _dist_code[];
#endif

# define _tr_tally_lit(s, c, flush) \
  { uch cc = (c); \
    s->d_buf[s->last_lit] = 0; \
    s->l_buf[s->last_lit++] = cc; \
    s->dyn_ltree[cc].Freq++; \
    flush = (s->last_lit == s->lit_bufsize-1); \
   }
# define _tr_tally_dist(s, distance, length, flush) \
  { uch len = (length); \
    ush dist = (distance); \
    s->d_buf[s->last_lit] = dist; \
    s->l_buf[s->last_lit++] = len; \
    dist--; \
    s->dyn_ltree[_length_code[len]+LITERALS+1].Freq++; \
    s->dyn_dtree[d_code(dist)].Freq++; \
    flush = (s->last_lit == s->lit_bufsize-1); \
  }
#else
# define _tr_tally_lit(s, c, flush) flush = _tr_tally(s, 0, c)
# define _tr_tally_dist(s, distance, length, flush) \
              flush = _tr_tally(s, distance, length) 
#endif

#endif

int deflateInit2_(z_streamp stream, int level, int method, int window_bits, int memory_level, int strategy, const char* version, int stream_size);
int deflateReset(z_streamp stream);
int deflate(z_streamp stream, int flush);
int deflateEnd(z_streamp stream);

/* deflate.c -- compress data using the deflation algorithm
 * Copyright (C) 1995-1998 Jean-loup Gailly.
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */

/*
 *  ALGORITHM
 *
 *      The "deflation" process depends on being able to identify portions
 *      of the input text which are identical to earlier input (within a
 *      sliding window trailing behind the input currently being processed).
 *
 *      The most straightforward technique turns out to be the fastest for
 *      most input files: try all possible matches and select the longest.
 *      The key feature of this algorithm is that insertions into the string
 *      dictionary are very simple and thus fast, and deletions are avoided
 *      completely. Insertions are performed at each input character, whereas
 *      string matches are performed only when the previous match ends. So it
 *      is preferable to spend more time in matches to allow very fast string
 *      insertions and avoid deletions. The matching algorithm for small
 *      strings is inspired from that of Rabin & Karp. A brute force approach
 *      is used to find longer strings when a small match has been found.
 *      A similar algorithm is used in comic (by Jan-Mark Wams) and freeze
 *      (by Leonid Broukhis).
 *         A previous version of this file used a more sophisticated algorithm
 *      (by Fiala and Greene) which is guaranteed to run in linear amortized
 *      time, but has a larger average cost, uses more memory and is patented.
 *      However the F&G algorithm may be faster for some highly redundant
 *      files if the parameter max_chain_length (described below) is too large.
 *
 *  ACKNOWLEDGEMENTS
 *
 *      The idea of lazy evaluation of matches is due to Jan-Mark Wams, and
 *      I found it in 'freeze' written by Leonid Broukhis.
 *      Thanks to many people for bug reports and testing.
 *
 *  REFERENCES
 *
 *      Deutsch, L.P.,"DEFLATE Compressed Data Format Specification".
 *      Available in ftp://ds.internic.net/rfc/rfc1951.txt
 *
 *      A description of the Rabin and Karp algorithm is given in the book
 *         "Algorithms" by R. Sedgewick, Addison-Wesley, p252.
 *
 *      Fiala,E.R., and Greene,D.H.
 *         Data Compression with Finite Windows, Comm.ACM, 32,4 (1989) 490-595
 *
 */

/* @(#) $Id$ */

const char deflate_copyright[] =
   " deflate 1.1.3 Copyright 1995-1998 Jean-loup Gailly ";
/*
  If you use the zlib library in a product, an acknowledgment is welcome
  in the documentation of your product. If for some reason you cannot
  include such an acknowledgment, I would appreciate that you keep this
  copyright string in the executable of your product.
 */

/* ===========================================================================
 *  Function prototypes.
 */
typedef enum {
    need_more,      /* block not completed, need more input or more output */
    block_done,     /* block flush performed */
    finish_started, /* finish started, need only more output at next deflate */
    finish_done     /* finish done, accept no more input or output */
} block_state;

typedef block_state (*compress_func) OF((deflate_state *s, int flush));
/* Compression function. Returns the block state after the call. */

local void fill_window    OF((deflate_state *s));
local block_state deflate_stored OF((deflate_state *s, int flush));
local block_state deflate_fast   OF((deflate_state *s, int flush));
local block_state deflate_slow   OF((deflate_state *s, int flush));
local void lm_init        OF((deflate_state *s));
local void putShortMSB    OF((deflate_state *s, uInt b));
local void flush_pending  OF((z_streamp strm));
local int read_buf        OF((z_streamp strm, Bytef *buf, unsigned size));
#ifdef ASMV
      void match_init OF((void)); /* asm code initialization */
      uInt longest_match  OF((deflate_state *s, IPos cur_match));
#else
local uInt longest_match  OF((deflate_state *s, IPos cur_match));
#endif

#ifdef DEBUG
local  void check_match OF((deflate_state *s, IPos start, IPos match,
                            int length));
#endif

/* ===========================================================================
 * Local data
 */

#define NIL 0
/* Tail of hash chains */

#ifndef TOO_FAR
#  define TOO_FAR 4096
#endif
/* Matches of length 3 are discarded if their distance exceeds TOO_FAR */

#define MIN_LOOKAHEAD (MAX_MATCH+MIN_MATCH+1)
/* Minimum amount of lookahead, except at the end of the input file.
 * See deflate.c for comments about the MIN_MATCH+1.
 */

/* Values for max_lazy_match, good_match and max_chain_length, depending on
 * the desired pack level (0..9). The values given below have been tuned to
 * exclude worst case performance for pathological files. Better values may be
 * found for specific files.
 */
typedef struct config_s {
   ush good_length; /* reduce lazy search above this match length */
   ush max_lazy;    /* do not perform lazy search above this match length */
   ush nice_length; /* quit search above this match length */
   ush max_chain;
   compress_func func;
} config;

local const config configuration_table[10] = {
/*      good lazy nice chain */
/* 0 */ {0,    0,  0,    0, deflate_stored},  /* store only */
/* 1 */ {4,    4,  8,    4, deflate_fast}, /* maximum speed, no lazy matches */
/* 2 */ {4,    5, 16,    8, deflate_fast},
/* 3 */ {4,    6, 32,   32, deflate_fast},

/* 4 */ {4,    4, 16,   16, deflate_slow},  /* lazy matches */
/* 5 */ {8,   16, 32,   32, deflate_slow},
/* 6 */ {8,   16, 128, 128, deflate_slow},
/* 7 */ {8,   32, 128, 256, deflate_slow},
/* 8 */ {32, 128, 258, 1024, deflate_slow},
/* 9 */ {32, 258, 258, 4096, deflate_slow}}; /* maximum compression */

/* Note: the deflate() code requires max_lazy >= MIN_MATCH and max_chain >= 4
 * For deflate_fast() (levels <= 3) good is ignored and lazy has a different
 * meaning.
 */

#define EQUAL 0
/* result of memcmp for equal strings */


/* ===========================================================================
 * Update a hash value with the given input byte
 * IN  assertion: all calls to to UPDATE_HASH are made with consecutive
 *    input characters, so that a running hash key can be computed from the
 *    previous key instead of complete recalculation each time.
 */
#define UPDATE_HASH(s,h,c) (h = (((h)<<s->hash_shift) ^ (c)) & s->hash_mask)


/* ===========================================================================
 * Insert string str in the dictionary and set match_head to the previous head
 * of the hash chain (the most recent string with same hash key). Return
 * the previous length of the hash chain.
 * If this file is compiled with -DFASTEST, the compression level is forced
 * to 1, and no hash chains are maintained.
 * IN  assertion: all calls to to INSERT_STRING are made with consecutive
 *    input characters and the first MIN_MATCH bytes of str are valid
 *    (except for the last MIN_MATCH-1 bytes of the input file).
 */
#ifdef FASTEST
#define INSERT_STRING(s, str, match_head) \
   (UPDATE_HASH(s, s->ins_h, s->window[(str) + (MIN_MATCH-1)]), \
    match_head = s->head[s->ins_h], \
    s->head[s->ins_h] = (Pos)(str))
#else
#define INSERT_STRING(s, str, match_head) \
   (UPDATE_HASH(s, s->ins_h, s->window[(str) + (MIN_MATCH-1)]), \
    s->prev[(str) & s->w_mask] = match_head = s->head[s->ins_h], \
    s->head[s->ins_h] = (Pos)(str))
#endif

/* ===========================================================================
 * Initialize the hash table (avoiding 64K overflow for 16 bit systems).
 * prev[] will be initialized on the fly.
 */
#define CLEAR_HASH(s) \
    s->head[s->hash_size-1] = NIL; \
    zmemzero((Bytef *)s->head, (unsigned)(s->hash_size-1)*sizeof(*s->head));

/* ========================================================================= */
int ZEXPORT deflateInit_(z_streamp strm, int level, const char *version, int stream_size)
{
    return deflateInit2_(strm, level, Z_DEFLATED, MAX_WBITS, DEF_MEM_LEVEL,
			 Z_DEFAULT_STRATEGY, version, stream_size);
    /* To do: ignore strm->next_in if we use it as window */
}

/* ========================================================================= */
int ZEXPORT deflateInit2_(z_streamp strm, int level, int method, int windowBits, int memLevel, int strategy, const char *version, int stream_size)
{
    deflate_state *s;
    int noheader = 0;
    static const char* my_version = ZLIB_VERSION;

    ushf *overlay;
    /* We overlay pending_buf and d_buf+l_buf. This works since the average
     * output size for (length,distance) codes is <= 24 bits.
     */

    if (version == Z_NULL || version[0] != my_version[0] ||
        stream_size != sizeof(z_stream)) {
	return Z_VERSION_ERROR;
    }
    if (strm == Z_NULL) return Z_STREAM_ERROR;

    strm->msg = Z_NULL;
    if (strm->zalloc == Z_NULL) {
	strm->zalloc = zcalloc;
	strm->opaque = (voidpf)0;
    }
    if (strm->zfree == Z_NULL) strm->zfree = zcfree;

    if (level == Z_DEFAULT_COMPRESSION) level = 6;
#ifdef FASTEST
    level = 1;
#endif

    if (windowBits < 0) { /* undocumented feature: suppress zlib header */
        noheader = 1;
        windowBits = -windowBits;
    }
    if (memLevel < 1 || memLevel > MAX_MEM_LEVEL || method != Z_DEFLATED ||
        windowBits < 8 || windowBits > 15 || level < 0 || level > 9 ||
	strategy < 0 || strategy > Z_HUFFMAN_ONLY) {
        return Z_STREAM_ERROR;
    }
    s = (deflate_state *) ZALLOC(strm, 1, sizeof(deflate_state));
    if (s == Z_NULL) return Z_MEM_ERROR;
    strm->state = (struct internal_state FAR *)s;
    s->strm = strm;

    s->noheader = noheader;
    s->w_bits = windowBits;
    s->w_size = 1 << s->w_bits;
    s->w_mask = s->w_size - 1;

    s->hash_bits = memLevel + 7;
    s->hash_size = 1 << s->hash_bits;
    s->hash_mask = s->hash_size - 1;
    s->hash_shift =  ((s->hash_bits+MIN_MATCH-1)/MIN_MATCH);

    s->window = (Bytef *) ZALLOC(strm, s->w_size, 2*sizeof(Byte));
    s->prev   = (Posf *)  ZALLOC(strm, s->w_size, sizeof(Pos));
    s->head   = (Posf *)  ZALLOC(strm, s->hash_size, sizeof(Pos));

    s->lit_bufsize = 1 << (memLevel + 6); /* 16K elements by default */

    overlay = (ushf *) ZALLOC(strm, s->lit_bufsize, sizeof(ush)+2);
    s->pending_buf = (uchf *) overlay;
    s->pending_buf_size = (ulg)s->lit_bufsize * (sizeof(ush)+2L);

    if (s->window == Z_NULL || s->prev == Z_NULL || s->head == Z_NULL ||
        s->pending_buf == Z_NULL) {
        strm->msg = (char*)ERR_MSG(Z_MEM_ERROR);
        deflateEnd (strm);
        return Z_MEM_ERROR;
    }
    s->d_buf = overlay + s->lit_bufsize/sizeof(ush);
    s->l_buf = s->pending_buf + (1+sizeof(ush))*s->lit_bufsize;

    s->level = level;
    s->strategy = strategy;
    s->method = (Byte)method;

    return deflateReset(strm);
}

/* ========================================================================= */
int ZEXPORT deflateSetDictionary(z_streamp strm, const Bytef *dictionary, uInt dictLength)
{
    deflate_state *s;
    uInt length = dictLength;
    uInt n;
    IPos hash_head = 0;

    if (strm == Z_NULL || strm->state == Z_NULL || dictionary == Z_NULL ||
        strm->state->status != INIT_STATE) return Z_STREAM_ERROR;

    s = strm->state;
    strm->adler = adler32(strm->adler, dictionary, dictLength);

    if (length < MIN_MATCH) return Z_OK;
    if (length > MAX_DIST(s)) {
	length = MAX_DIST(s);
#ifndef USE_DICT_HEAD
	dictionary += dictLength - length; /* use the tail of the dictionary */
#endif
    }
    zmemcpy(s->window, dictionary, length);
    s->strstart = length;
    s->block_start = (long)length;

    /* Insert all strings in the hash table (except for the last two bytes).
     * s->lookahead stays null, so s->ins_h will be recomputed at the next
     * call of fill_window.
     */
    s->ins_h = s->window[0];
    UPDATE_HASH(s, s->ins_h, s->window[1]);
    for (n = 0; n <= length - MIN_MATCH; n++) {
	INSERT_STRING(s, n, hash_head);
    }
    if (hash_head) hash_head = 0;  /* to make compiler happy */
    return Z_OK;
}

/* ========================================================================= */
int ZEXPORT deflateReset(z_streamp strm)
{
    deflate_state *s;
    
    if (strm == Z_NULL || strm->state == Z_NULL ||
        strm->zalloc == Z_NULL || strm->zfree == Z_NULL) return Z_STREAM_ERROR;

    strm->total_in = strm->total_out = 0;
    strm->msg = Z_NULL; /* use zfree if we ever allocate msg dynamically */
    strm->data_type = Z_UNKNOWN;

    s = (deflate_state *)strm->state;
    s->pending = 0;
    s->pending_out = s->pending_buf;

    if (s->noheader < 0) {
        s->noheader = 0; /* was set to -1 by deflate(..., Z_FINISH); */
    }
    s->status = s->noheader ? BUSY_STATE : INIT_STATE;
    strm->adler = 1;
    s->last_flush = Z_NO_FLUSH;

    _tr_init(s);
    lm_init(s);

    return Z_OK;
}

/* ========================================================================= */
int ZEXPORT deflateParams(z_streamp strm, int level, int strategy)
{
    deflate_state *s;
    compress_func func;
    int err = Z_OK;

    if (strm == Z_NULL || strm->state == Z_NULL) return Z_STREAM_ERROR;
    s = strm->state;

    if (level == Z_DEFAULT_COMPRESSION) {
	level = 6;
    }
    if (level < 0 || level > 9 || strategy < 0 || strategy > Z_HUFFMAN_ONLY) {
	return Z_STREAM_ERROR;
    }
    func = configuration_table[s->level].func;

    if (func != configuration_table[level].func && strm->total_in != 0) {
	/* Flush the last buffer: */
	err = deflate(strm, Z_PARTIAL_FLUSH);
    }
    if (s->level != level) {
	s->level = level;
	s->max_lazy_match   = configuration_table[level].max_lazy;
	s->good_match       = configuration_table[level].good_length;
	s->nice_match       = configuration_table[level].nice_length;
	s->max_chain_length = configuration_table[level].max_chain;
    }
    s->strategy = strategy;
    return err;
}

/* =========================================================================
 * Put a short in the pending buffer. The 16-bit value is put in MSB order.
 * IN assertion: the stream state is correct and there is enough room in
 * pending_buf.
 */
local void putShortMSB(deflate_state *s, uInt b)
{
    put_byte(s, (Byte)(b >> 8));
    put_byte(s, (Byte)(b & 0xff));
}   

/* =========================================================================
 * Flush as much pending output as possible. All deflate() output goes
 * through this function so some applications may wish to modify it
 * to avoid allocating a large strm->next_out buffer and copying into it.
 * (See also read_buf()).
 */
local void flush_pending(z_streamp strm)
{
    unsigned len = strm->state->pending;

    if (len > strm->avail_out) len = strm->avail_out;
    if (len == 0) return;

    zmemcpy(strm->next_out, strm->state->pending_out, len);
    strm->next_out  += len;
    strm->state->pending_out  += len;
    strm->total_out += len;
    strm->avail_out  -= len;
    strm->state->pending -= len;
    if (strm->state->pending == 0) {
        strm->state->pending_out = strm->state->pending_buf;
    }
}

/* ========================================================================= */
int ZEXPORT deflate(z_streamp strm, int flush)
{
    int old_flush; /* value of flush param for previous deflate call */
    deflate_state *s;

    if (strm == Z_NULL || strm->state == Z_NULL ||
	flush > Z_FINISH || flush < 0) {
        return Z_STREAM_ERROR;
    }
    s = strm->state;

    if (strm->next_out == Z_NULL ||
        (strm->next_in == Z_NULL && strm->avail_in != 0) ||
	(s->status == FINISH_STATE && flush != Z_FINISH)) {
        ERR_RETURN(strm, Z_STREAM_ERROR);
    }
    if (strm->avail_out == 0) ERR_RETURN(strm, Z_BUF_ERROR);

    s->strm = strm; /* just in case */
    old_flush = s->last_flush;
    s->last_flush = flush;

    /* Write the zlib header */
    if (s->status == INIT_STATE) {

        uInt header = (Z_DEFLATED + ((s->w_bits-8)<<4)) << 8;
        uInt level_flags = (s->level-1) >> 1;

        if (level_flags > 3) level_flags = 3;
        header |= (level_flags << 6);
	if (s->strstart != 0) header |= PRESET_DICT;
        header += 31 - (header % 31);

        s->status = BUSY_STATE;
        putShortMSB(s, header);

	/* Save the adler32 of the preset dictionary: */
	if (s->strstart != 0) {
	    putShortMSB(s, (uInt)(strm->adler >> 16));
	    putShortMSB(s, (uInt)(strm->adler & 0xffff));
	}
	strm->adler = 1L;
    }

    /* Flush as much pending output as possible */
    if (s->pending != 0) {
        flush_pending(strm);
        if (strm->avail_out == 0) {
	    /* Since avail_out is 0, deflate will be called again with
	     * more output space, but possibly with both pending and
	     * avail_in equal to zero. There won't be anything to do,
	     * but this is not an error situation so make sure we
	     * return OK instead of BUF_ERROR at next call of deflate:
             */
	    s->last_flush = -1;
	    return Z_OK;
	}

    /* Make sure there is something to do and avoid duplicate consecutive
     * flushes. For repeated and useless calls with Z_FINISH, we keep
     * returning Z_STREAM_END instead of Z_BUFF_ERROR.
     */
    } else if (strm->avail_in == 0 && flush <= old_flush &&
	       flush != Z_FINISH) {
        ERR_RETURN(strm, Z_BUF_ERROR);
    }

    /* User must not provide more input after the first FINISH: */
    if (s->status == FINISH_STATE && strm->avail_in != 0) {
        ERR_RETURN(strm, Z_BUF_ERROR);
    }

    /* Start a new block or continue the current one.
     */
    if (strm->avail_in != 0 || s->lookahead != 0 ||
        (flush != Z_NO_FLUSH && s->status != FINISH_STATE)) {
        block_state bstate;

	bstate = (*(configuration_table[s->level].func))(s, flush);

        if (bstate == finish_started || bstate == finish_done) {
            s->status = FINISH_STATE;
        }
        if (bstate == need_more || bstate == finish_started) {
	    if (strm->avail_out == 0) {
	        s->last_flush = -1; /* avoid BUF_ERROR next call, see above */
	    }
	    return Z_OK;
	    /* If flush != Z_NO_FLUSH && avail_out == 0, the next call
	     * of deflate should use the same flush parameter to make sure
	     * that the flush is complete. So we don't have to output an
	     * empty block here, this will be done at next call. This also
	     * ensures that for a very small output buffer, we emit at most
	     * one empty block.
	     */
	}
        if (bstate == block_done) {
            if (flush == Z_PARTIAL_FLUSH) {
                _tr_align(s);
            } else { /* FULL_FLUSH or SYNC_FLUSH */
                _tr_stored_block(s, (char*)0, 0L, 0);
                /* For a full flush, this empty block will be recognized
                 * as a special marker by inflate_sync().
                 */
                if (flush == Z_FULL_FLUSH) {
                    CLEAR_HASH(s);             /* forget history */
                }
            }
            flush_pending(strm);
	    if (strm->avail_out == 0) {
	      s->last_flush = -1; /* avoid BUF_ERROR at next call, see above */
	      return Z_OK;
	    }
        }
    }
    Assert(strm->avail_out > 0, "bug2");

    if (flush != Z_FINISH) return Z_OK;
    if (s->noheader) return Z_STREAM_END;

    /* Write the zlib trailer (adler32) */
    putShortMSB(s, (uInt)(strm->adler >> 16));
    putShortMSB(s, (uInt)(strm->adler & 0xffff));
    flush_pending(strm);
    /* If avail_out is zero, the application will call deflate again
     * to flush the rest.
     */
    s->noheader = -1; /* write the trailer only once! */
    return s->pending != 0 ? Z_OK : Z_STREAM_END;
}

/* ========================================================================= */
int ZEXPORT deflateEnd(z_streamp strm)
{
    int status;

    if (strm == Z_NULL || strm->state == Z_NULL) return Z_STREAM_ERROR;

    status = strm->state->status;
    if (status != INIT_STATE && status != BUSY_STATE &&
	status != FINISH_STATE) {
      return Z_STREAM_ERROR;
    }

    /* Deallocate in reverse order of allocations: */
    TRY_FREE(strm, strm->state->pending_buf);
    TRY_FREE(strm, strm->state->head);
    TRY_FREE(strm, strm->state->prev);
    TRY_FREE(strm, strm->state->window);

    ZFREE(strm, strm->state);
    strm->state = Z_NULL;

    return status == BUSY_STATE ? Z_DATA_ERROR : Z_OK;
}

/* =========================================================================
 * Copy the source state to the destination state.
 * To simplify the source, this is not supported for 16-bit MSDOS (which
 * doesn't have enough memory anyway to duplicate compression states).
 */
int ZEXPORT deflateCopy(z_streamp dest, z_streamp source)
{
#ifdef MAXSEG_64K
    return Z_STREAM_ERROR;
#else
    deflate_state *ds;
    deflate_state *ss;
    ushf *overlay;


    if (source == Z_NULL || dest == Z_NULL || source->state == Z_NULL) {
        return Z_STREAM_ERROR;
    }

    ss = source->state;

    *dest = *source;

    ds = (deflate_state *) ZALLOC(dest, 1, sizeof(deflate_state));
    if (ds == Z_NULL) return Z_MEM_ERROR;
    dest->state = (struct internal_state FAR *) ds;
    *ds = *ss;
    ds->strm = dest;

    ds->window = (Bytef *) ZALLOC(dest, ds->w_size, 2*sizeof(Byte));
    ds->prev   = (Posf *)  ZALLOC(dest, ds->w_size, sizeof(Pos));
    ds->head   = (Posf *)  ZALLOC(dest, ds->hash_size, sizeof(Pos));
    overlay = (ushf *) ZALLOC(dest, ds->lit_bufsize, sizeof(ush)+2);
    ds->pending_buf = (uchf *) overlay;

    if (ds->window == Z_NULL || ds->prev == Z_NULL || ds->head == Z_NULL ||
        ds->pending_buf == Z_NULL) {
        deflateEnd (dest);
        return Z_MEM_ERROR;
    }
    /* following zmemcpy do not work for 16-bit MSDOS */
    zmemcpy(ds->window, ss->window, ds->w_size * 2 * sizeof(Byte));
    zmemcpy(ds->prev, ss->prev, ds->w_size * sizeof(Pos));
    zmemcpy(ds->head, ss->head, ds->hash_size * sizeof(Pos));
    zmemcpy(ds->pending_buf, ss->pending_buf, (uInt)ds->pending_buf_size);

    ds->pending_out = ds->pending_buf + (ss->pending_out - ss->pending_buf);
    ds->d_buf = overlay + ds->lit_bufsize/sizeof(ush);
    ds->l_buf = ds->pending_buf + (1+sizeof(ush))*ds->lit_bufsize;

    ds->l_desc.dyn_tree = ds->dyn_ltree;
    ds->d_desc.dyn_tree = ds->dyn_dtree;
    ds->bl_desc.dyn_tree = ds->bl_tree;

    return Z_OK;
#endif
}

/* ===========================================================================
 * Read a new buffer from the current input stream, update the adler32
 * and total number of bytes read.  All deflate() input goes through
 * this function so some applications may wish to modify it to avoid
 * allocating a large strm->next_in buffer and copying from it.
 * (See also flush_pending()).
 */
local int read_buf(z_streamp strm, Bytef *buf, unsigned size)
{
    unsigned len = strm->avail_in;

    if (len > size) len = size;
    if (len == 0) return 0;

    strm->avail_in  -= len;

    if (!strm->state->noheader) {
        strm->adler = adler32(strm->adler, strm->next_in, len);
    }
    zmemcpy(buf, strm->next_in, len);
    strm->next_in  += len;
    strm->total_in += len;

    return (int)len;
}

/* ===========================================================================
 * Initialize the "longest match" routines for a new zlib stream
 */
local void lm_init(deflate_state *s)
{
    s->window_size = (ulg)2L*s->w_size;

    CLEAR_HASH(s);

    /* Set the default configuration parameters:
     */
    s->max_lazy_match   = configuration_table[s->level].max_lazy;
    s->good_match       = configuration_table[s->level].good_length;
    s->nice_match       = configuration_table[s->level].nice_length;
    s->max_chain_length = configuration_table[s->level].max_chain;

    s->strstart = 0;
    s->block_start = 0L;
    s->lookahead = 0;
    s->match_length = s->prev_length = MIN_MATCH-1;
    s->match_available = 0;
    s->ins_h = 0;
#ifdef ASMV
    match_init(); /* initialize the asm code */
#endif
}

/* ===========================================================================
 * Set match_start to the longest match starting at the given string and
 * return its length. Matches shorter or equal to prev_length are discarded,
 * in which case the result is equal to prev_length and match_start is
 * garbage.
 * IN assertions: cur_match is the head of the hash chain for the current
 *   string (strstart) and its distance is <= MAX_DIST, and prev_length >= 1
 * OUT assertion: the match length is not greater than s->lookahead.
 */
#ifndef ASMV
/* For 80x86 and 680x0, an optimized version will be provided in match.asm or
 * match.S. The code will be functionally equivalent.
 */
#ifndef FASTEST
local uInt longest_match(deflate_state *s, IPos cur_match)
{
    unsigned chain_length = s->max_chain_length;/* max hash chain length */
    Bytef *scan = s->window + s->strstart; /* current string */
    Bytef *match;                       /* matched string */
    int len;                           /* length of current match */
    int best_len = s->prev_length;              /* best match length so far */
    int nice_match = s->nice_match;             /* stop if match long enough */
    IPos limit = s->strstart > (IPos)MAX_DIST(s) ?
        s->strstart - (IPos)MAX_DIST(s) : NIL;
    /* Stop when cur_match becomes <= limit. To simplify the code,
     * we prevent matches with the string of window index 0.
     */
    Posf *prev = s->prev;
    uInt wmask = s->w_mask;

#ifdef UNALIGNED_OK
    /* Compare two bytes at a time. Note: this is not always beneficial.
     * Try with and without -DUNALIGNED_OK to check.
     */
    Bytef *strend = s->window + s->strstart + MAX_MATCH - 1;
    ush scan_start = *(ushf*)scan;
    ush scan_end   = *(ushf*)(scan+best_len-1);
#else
    Bytef *strend = s->window + s->strstart + MAX_MATCH;
    Byte scan_end1  = scan[best_len-1];
    Byte scan_end   = scan[best_len];
#endif

    /* The code is optimized for HASH_BITS >= 8 and MAX_MATCH-2 multiple of 16.
     * It is easy to get rid of this optimization if necessary.
     */
    Assert(s->hash_bits >= 8 && MAX_MATCH == 258, "Code too clever");

    /* Do not waste too much time if we already have a good match: */
    if (s->prev_length >= s->good_match) {
        chain_length >>= 2;
    }
    /* Do not look for matches beyond the end of the input. This is necessary
     * to make deflate deterministic.
     */
    if ((uInt)nice_match > s->lookahead) nice_match = s->lookahead;

    Assert((ulg)s->strstart <= s->window_size-MIN_LOOKAHEAD, "need lookahead");

    do {
        Assert(cur_match < s->strstart, "no future");
        match = s->window + cur_match;

        /* Skip to next match if the match length cannot increase
         * or if the match length is less than 2:
         */
#if (defined(UNALIGNED_OK) && MAX_MATCH == 258)
        /* This code assumes sizeof(unsigned short) == 2. Do not use
         * UNALIGNED_OK if your compiler uses a different size.
         */
        if (*(ushf*)(match+best_len-1) != scan_end ||
            *(ushf*)match != scan_start) continue;

        /* It is not necessary to compare scan[2] and match[2] since they are
         * always equal when the other bytes match, given that the hash keys
         * are equal and that HASH_BITS >= 8. Compare 2 bytes at a time at
         * strstart+3, +5, ... up to strstart+257. We check for insufficient
         * lookahead only every 4th comparison; the 128th check will be made
         * at strstart+257. If MAX_MATCH-2 is not a multiple of 8, it is
         * necessary to put more guard bytes at the end of the window, or
         * to check more often for insufficient lookahead.
         */
        Assert(scan[2] == match[2], "scan[2]?");
        scan++, match++;
        do {
        } while (*(ushf*)(scan+=2) == *(ushf*)(match+=2) &&
                 *(ushf*)(scan+=2) == *(ushf*)(match+=2) &&
                 *(ushf*)(scan+=2) == *(ushf*)(match+=2) &&
                 *(ushf*)(scan+=2) == *(ushf*)(match+=2) &&
                 scan < strend);
        /* The funny "do {}" generates better code on most compilers */

        /* Here, scan <= window+strstart+257 */
        Assert(scan <= s->window+(unsigned)(s->window_size-1), "wild scan");
        if (*scan == *match) scan++;

        len = (MAX_MATCH - 1) - (int)(strend-scan);
        scan = strend - (MAX_MATCH-1);

#else /* UNALIGNED_OK */

        if (match[best_len]   != scan_end  ||
            match[best_len-1] != scan_end1 ||
            *match            != *scan     ||
            *++match          != scan[1])      continue;

        /* The check at best_len-1 can be removed because it will be made
         * again later. (This heuristic is not always a win.)
         * It is not necessary to compare scan[2] and match[2] since they
         * are always equal when the other bytes match, given that
         * the hash keys are equal and that HASH_BITS >= 8.
         */
        scan += 2, match++;
        Assert(*scan == *match, "match[2]?");

        /* We check for insufficient lookahead only every 8th comparison;
         * the 256th check will be made at strstart+258.
         */
        do {
        } while (*++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match &&
                 scan < strend);

        Assert(scan <= s->window+(unsigned)(s->window_size-1), "wild scan");

        len = MAX_MATCH - (int)(strend - scan);
        scan = strend - MAX_MATCH;

#endif /* UNALIGNED_OK */

        if (len > best_len) {
            s->match_start = cur_match;
            best_len = len;
            if (len >= nice_match) break;
#ifdef UNALIGNED_OK
            scan_end = *(ushf*)(scan+best_len-1);
#else
            scan_end1  = scan[best_len-1];
            scan_end   = scan[best_len];
#endif
        }
    } while ((cur_match = prev[cur_match & wmask]) > limit
             && --chain_length != 0);

    if ((uInt)best_len <= s->lookahead) return (uInt)best_len;
    return s->lookahead;
}

#else /* FASTEST */
/* ---------------------------------------------------------------------------
 * Optimized version for level == 1 only
 */
local uInt longest_match(deflate_state *s, IPos cur_match)
{
    Bytef *scan = s->window + s->strstart; /* current string */
    Bytef *match;                       /* matched string */
    int len;                           /* length of current match */
    Bytef *strend = s->window + s->strstart + MAX_MATCH;

    /* The code is optimized for HASH_BITS >= 8 and MAX_MATCH-2 multiple of 16.
     * It is easy to get rid of this optimization if necessary.
     */
    Assert(s->hash_bits >= 8 && MAX_MATCH == 258, "Code too clever");

    Assert((ulg)s->strstart <= s->window_size-MIN_LOOKAHEAD, "need lookahead");

    Assert(cur_match < s->strstart, "no future");

    match = s->window + cur_match;

    /* Return failure if the match length is less than 2:
     */
    if (match[0] != scan[0] || match[1] != scan[1]) return MIN_MATCH-1;

    /* The check at best_len-1 can be removed because it will be made
     * again later. (This heuristic is not always a win.)
     * It is not necessary to compare scan[2] and match[2] since they
     * are always equal when the other bytes match, given that
     * the hash keys are equal and that HASH_BITS >= 8.
     */
    scan += 2, match += 2;
    Assert(*scan == *match, "match[2]?");

    /* We check for insufficient lookahead only every 8th comparison;
     * the 256th check will be made at strstart+258.
     */
    do {
    } while (*++scan == *++match && *++scan == *++match &&
	     *++scan == *++match && *++scan == *++match &&
	     *++scan == *++match && *++scan == *++match &&
	     *++scan == *++match && *++scan == *++match &&
	     scan < strend);

    Assert(scan <= s->window+(unsigned)(s->window_size-1), "wild scan");

    len = MAX_MATCH - (int)(strend - scan);

    if (len < MIN_MATCH) return MIN_MATCH - 1;

    s->match_start = cur_match;
    return len <= s->lookahead ? len : s->lookahead;
}
#endif /* FASTEST */
#endif /* ASMV */

#ifdef DEBUG
/* ===========================================================================
 * Check that the match at match_start is indeed a match.
 */
local void check_match(deflate_state *s, IPos start, IPos match, int length)
{
    /* check that the match is indeed a match */
    if (zmemcmp(s->window + match,
                s->window + start, length) != EQUAL) {
        fprintf(stderr, " start %u, match %u, length %d\n",
		start, match, length);
        do {
	    fprintf(stderr, "%c%c", s->window[match++], s->window[start++]);
	} while (--length != 0);
        z_error("invalid match");
    }
    if (z_verbose > 1) {
        fprintf(stderr,"\\[%d,%d]", start-match, length);
        do { putc(s->window[start++], stderr); } while (--length != 0);
    }
}
#else
#  define check_match(s, start, match, length)
#endif

/* ===========================================================================
 * Fill the window when the lookahead becomes insufficient.
 * Updates strstart and lookahead.
 *
 * IN assertion: lookahead < MIN_LOOKAHEAD
 * OUT assertions: strstart <= window_size-MIN_LOOKAHEAD
 *    At least one byte has been read, or avail_in == 0; reads are
 *    performed for at least two bytes (required for the zip translate_eol
 *    option -- not supported here).
 */
local void fill_window(deflate_state *s)
{
    unsigned n, m;
    Posf *p;
    unsigned more;    /* Amount of free space at the end of the window. */
    uInt wsize = s->w_size;

    do {
        more = (unsigned)(s->window_size -(ulg)s->lookahead -(ulg)s->strstart);

        /* Deal with !@#$% 64K limit: */
        if (more == 0 && s->strstart == 0 && s->lookahead == 0) {
            more = wsize;

        } else if (more == (unsigned)(-1)) {
            /* Very unlikely, but possible on 16 bit machine if strstart == 0
             * and lookahead == 1 (input done one byte at time)
             */
            more--;

        /* If the window is almost full and there is insufficient lookahead,
         * move the upper half to the lower one to make room in the upper half.
         */
        } else if (s->strstart >= wsize+MAX_DIST(s)) {

            zmemcpy(s->window, s->window+wsize, (unsigned)wsize);
            s->match_start -= wsize;
            s->strstart    -= wsize; /* we now have strstart >= MAX_DIST */
            s->block_start -= (long) wsize;

            /* Slide the hash table (could be avoided with 32 bit values
               at the expense of memory usage). We slide even when level == 0
               to keep the hash table consistent if we switch back to level > 0
               later. (Using level 0 permanently is not an optimal usage of
               zlib, so we don't care about this pathological case.)
             */
	    n = s->hash_size;
	    p = &s->head[n];
	    do {
		m = *--p;
		*p = (Pos)(m >= wsize ? m-wsize : NIL);
	    } while (--n);

	    n = wsize;
#ifndef FASTEST
	    p = &s->prev[n];
	    do {
		m = *--p;
		*p = (Pos)(m >= wsize ? m-wsize : NIL);
		/* If n is not on any hash chain, prev[n] is garbage but
		 * its value will never be used.
		 */
	    } while (--n);
#endif
            more += wsize;
        }
        if (s->strm->avail_in == 0) return;

        /* If there was no sliding:
         *    strstart <= WSIZE+MAX_DIST-1 && lookahead <= MIN_LOOKAHEAD - 1 &&
         *    more == window_size - lookahead - strstart
         * => more >= window_size - (MIN_LOOKAHEAD-1 + WSIZE + MAX_DIST-1)
         * => more >= window_size - 2*WSIZE + 2
         * In the BIG_MEM or MMAP case (not yet supported),
         *   window_size == input_size + MIN_LOOKAHEAD  &&
         *   strstart + s->lookahead <= input_size => more >= MIN_LOOKAHEAD.
         * Otherwise, window_size == 2*WSIZE so more >= 2.
         * If there was sliding, more >= WSIZE. So in all cases, more >= 2.
         */
        Assert(more >= 2, "more < 2");

        n = read_buf(s->strm, s->window + s->strstart + s->lookahead, more);
        s->lookahead += n;

        /* Initialize the hash value now that we have some input: */
        if (s->lookahead >= MIN_MATCH) {
            s->ins_h = s->window[s->strstart];
            UPDATE_HASH(s, s->ins_h, s->window[s->strstart+1]);
#if MIN_MATCH != 3
            Call UPDATE_HASH() MIN_MATCH-3 more times
#endif
        }
        /* If the whole input has less than MIN_MATCH bytes, ins_h is garbage,
         * but this is not important since only literal bytes will be emitted.
         */

    } while (s->lookahead < MIN_LOOKAHEAD && s->strm->avail_in != 0);
}

/* ===========================================================================
 * Flush the current block, with given end-of-file flag.
 * IN assertion: strstart is set to the end of the current match.
 */
#define FLUSH_BLOCK_ONLY(s, eof) { \
   _tr_flush_block(s, (s->block_start >= 0L ? \
                   (charf *)&s->window[(unsigned)s->block_start] : \
                   (charf *)Z_NULL), \
		(ulg)((long)s->strstart - s->block_start), \
		(eof)); \
   s->block_start = s->strstart; \
   flush_pending(s->strm); \
   Tracev((stderr,"[FLUSH]")); \
}

/* Same but force premature exit if necessary. */
#define FLUSH_BLOCK(s, eof) { \
   FLUSH_BLOCK_ONLY(s, eof); \
   if (s->strm->avail_out == 0) return (eof) ? finish_started : need_more; \
}

/* ===========================================================================
 * Copy without compression as much as possible from the input stream, return
 * the current block state.
 * This function does not insert new strings in the dictionary since
 * uncompressible data is probably not useful. This function is used
 * only for the level=0 compression option.
 * NOTE: this function should be optimized to avoid extra copying from
 * window to pending_buf.
 */
local block_state deflate_stored(deflate_state *s, int flush)
{
    /* Stored blocks are limited to 0xffff bytes, pending_buf is limited
     * to pending_buf_size, and each stored block has a 5 byte header:
     */
    ulg max_block_size = 0xffff;
    ulg max_start;

    if (max_block_size > s->pending_buf_size - 5) {
        max_block_size = s->pending_buf_size - 5;
    }

    /* Copy as much as possible from input to output: */
    for (;;) {
        /* Fill the window as much as possible: */
        if (s->lookahead <= 1) {

            Assert(s->strstart < s->w_size+MAX_DIST(s) ||
		   s->block_start >= (long)s->w_size, "slide too late");

            fill_window(s);
            if (s->lookahead == 0 && flush == Z_NO_FLUSH) return need_more;

            if (s->lookahead == 0) break; /* flush the current block */
        }
	Assert(s->block_start >= 0L, "block gone");

	s->strstart += s->lookahead;
	s->lookahead = 0;

	/* Emit a stored block if pending_buf will be full: */
 	max_start = s->block_start + max_block_size;
        if (s->strstart == 0 || (ulg)s->strstart >= max_start) {
	    /* strstart == 0 is possible when wraparound on 16-bit machine */
	    s->lookahead = (uInt)(s->strstart - max_start);
	    s->strstart = (uInt)max_start;
            FLUSH_BLOCK(s, 0);
	}
	/* Flush if we may have to slide, otherwise block_start may become
         * negative and the data will be gone:
         */
        if (s->strstart - (uInt)s->block_start >= MAX_DIST(s)) {
            FLUSH_BLOCK(s, 0);
	}
    }
    FLUSH_BLOCK(s, flush == Z_FINISH);
    return flush == Z_FINISH ? finish_done : block_done;
}

/* ===========================================================================
 * Compress as much as possible from the input stream, return the current
 * block state.
 * This function does not perform lazy evaluation of matches and inserts
 * new strings in the dictionary only for unmatched strings or for short
 * matches. It is used only for the fast compression options.
 */
local block_state deflate_fast(deflate_state *s, int flush)
{
    IPos hash_head = NIL; /* head of the hash chain */
    int bflush;           /* set if current block must be flushed */

    for (;;) {
        /* Make sure that we always have enough lookahead, except
         * at the end of the input file. We need MAX_MATCH bytes
         * for the next match, plus MIN_MATCH bytes to insert the
         * string following the next match.
         */
        if (s->lookahead < MIN_LOOKAHEAD) {
            fill_window(s);
            if (s->lookahead < MIN_LOOKAHEAD && flush == Z_NO_FLUSH) {
	        return need_more;
	    }
            if (s->lookahead == 0) break; /* flush the current block */
        }

        /* Insert the string window[strstart .. strstart+2] in the
         * dictionary, and set hash_head to the head of the hash chain:
         */
        if (s->lookahead >= MIN_MATCH) {
            INSERT_STRING(s, s->strstart, hash_head);
        }

        /* Find the longest match, discarding those <= prev_length.
         * At this point we have always match_length < MIN_MATCH
         */
        if (hash_head != NIL && s->strstart - hash_head <= MAX_DIST(s)) {
            /* To simplify the code, we prevent matches with the string
             * of window index 0 (in particular we have to avoid a match
             * of the string with itself at the start of the input file).
             */
            if (s->strategy != Z_HUFFMAN_ONLY) {
                s->match_length = longest_match (s, hash_head);
            }
            /* longest_match() sets match_start */
        }
        if (s->match_length >= MIN_MATCH) {
            check_match(s, s->strstart, s->match_start, s->match_length);

            _tr_tally_dist(s, s->strstart - s->match_start,
                           s->match_length - MIN_MATCH, bflush);

            s->lookahead -= s->match_length;

            /* Insert new strings in the hash table only if the match length
             * is not too large. This saves time but degrades compression.
             */
#ifndef FASTEST
            if (s->match_length <= s->max_insert_length &&
                s->lookahead >= MIN_MATCH) {
                s->match_length--; /* string at strstart already in hash table */
                do {
                    s->strstart++;
                    INSERT_STRING(s, s->strstart, hash_head);
                    /* strstart never exceeds WSIZE-MAX_MATCH, so there are
                     * always MIN_MATCH bytes ahead.
                     */
                } while (--s->match_length != 0);
                s->strstart++; 
            } else
#endif
	    {
                s->strstart += s->match_length;
                s->match_length = 0;
                s->ins_h = s->window[s->strstart];
                UPDATE_HASH(s, s->ins_h, s->window[s->strstart+1]);
#if MIN_MATCH != 3
                Call UPDATE_HASH() MIN_MATCH-3 more times
#endif
                /* If lookahead < MIN_MATCH, ins_h is garbage, but it does not
                 * matter since it will be recomputed at next deflate call.
                 */
            }
        } else {
            /* No match, output a literal byte */
            Tracevv((stderr,"%c", s->window[s->strstart]));
            _tr_tally_lit (s, s->window[s->strstart], bflush);
            s->lookahead--;
            s->strstart++; 
        }
        if (bflush) FLUSH_BLOCK(s, 0);
    }
    FLUSH_BLOCK(s, flush == Z_FINISH);
    return flush == Z_FINISH ? finish_done : block_done;
}

/* ===========================================================================
 * Same as above, but achieves better compression. We use a lazy
 * evaluation for matches: a match is finally adopted only if there is
 * no better match at the next window position.
 */
local block_state deflate_slow(deflate_state *s, int flush)
{
    IPos hash_head = NIL;    /* head of hash chain */
    int bflush;              /* set if current block must be flushed */

    /* Process the input block. */
    for (;;) {
        /* Make sure that we always have enough lookahead, except
         * at the end of the input file. We need MAX_MATCH bytes
         * for the next match, plus MIN_MATCH bytes to insert the
         * string following the next match.
         */
        if (s->lookahead < MIN_LOOKAHEAD) {
            fill_window(s);
            if (s->lookahead < MIN_LOOKAHEAD && flush == Z_NO_FLUSH) {
	        return need_more;
	    }
            if (s->lookahead == 0) break; /* flush the current block */
        }

        /* Insert the string window[strstart .. strstart+2] in the
         * dictionary, and set hash_head to the head of the hash chain:
         */
        if (s->lookahead >= MIN_MATCH) {
            INSERT_STRING(s, s->strstart, hash_head);
        }

        /* Find the longest match, discarding those <= prev_length.
         */
        s->prev_length = s->match_length, s->prev_match = s->match_start;
        s->match_length = MIN_MATCH-1;

        if (hash_head != NIL && s->prev_length < s->max_lazy_match &&
            s->strstart - hash_head <= MAX_DIST(s)) {
            /* To simplify the code, we prevent matches with the string
             * of window index 0 (in particular we have to avoid a match
             * of the string with itself at the start of the input file).
             */
            if (s->strategy != Z_HUFFMAN_ONLY) {
                s->match_length = longest_match (s, hash_head);
            }
            /* longest_match() sets match_start */

            if (s->match_length <= 5 && (s->strategy == Z_FILTERED ||
                 (s->match_length == MIN_MATCH &&
                  s->strstart - s->match_start > TOO_FAR))) {

                /* If prev_match is also MIN_MATCH, match_start is garbage
                 * but we will ignore the current match anyway.
                 */
                s->match_length = MIN_MATCH-1;
            }
        }
        /* If there was a match at the previous step and the current
         * match is not better, output the previous match:
         */
        if (s->prev_length >= MIN_MATCH && s->match_length <= s->prev_length) {
            uInt max_insert = s->strstart + s->lookahead - MIN_MATCH;
            /* Do not insert strings in hash table beyond this. */

            check_match(s, s->strstart-1, s->prev_match, s->prev_length);

            _tr_tally_dist(s, s->strstart -1 - s->prev_match,
			   s->prev_length - MIN_MATCH, bflush);

            /* Insert in hash table all strings up to the end of the match.
             * strstart-1 and strstart are already inserted. If there is not
             * enough lookahead, the last two strings are not inserted in
             * the hash table.
             */
            s->lookahead -= s->prev_length-1;
            s->prev_length -= 2;
            do {
                if (++s->strstart <= max_insert) {
                    INSERT_STRING(s, s->strstart, hash_head);
                }
            } while (--s->prev_length != 0);
            s->match_available = 0;
            s->match_length = MIN_MATCH-1;
            s->strstart++;

            if (bflush) FLUSH_BLOCK(s, 0);

        } else if (s->match_available) {
            /* If there was no match at the previous position, output a
             * single literal. If there was a match but the current match
             * is longer, truncate the previous match to a single literal.
             */
            Tracevv((stderr,"%c", s->window[s->strstart-1]));
	    _tr_tally_lit(s, s->window[s->strstart-1], bflush);
	    if (bflush) {
                FLUSH_BLOCK_ONLY(s, 0);
            }
            s->strstart++;
            s->lookahead--;
            if (s->strm->avail_out == 0) return need_more;
        } else {
            /* There is no previous match to compare with, wait for
             * the next step to decide.
             */
            s->match_available = 1;
            s->strstart++;
            s->lookahead--;
        }
    }
    Assert (flush != Z_NO_FLUSH, "no flush?");
    if (s->match_available) {
        Tracevv((stderr,"%c", s->window[s->strstart-1]));
        _tr_tally_lit(s, s->window[s->strstart-1], bflush);
        s->match_available = 0;
    }
    FLUSH_BLOCK(s, flush == Z_FINISH);
    return flush == Z_FINISH ? finish_done : block_done;
}

/* trees.c -- output deflated data using Huffman coding
 * Copyright (C) 1995-1998 Jean-loup Gailly
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */

/*
 *  ALGORITHM
 *
 *      The "deflation" process uses several Huffman trees. The more
 *      common source values are represented by shorter bit sequences.
 *
 *      Each code tree is stored in a compressed form which is itself
 * a Huffman encoding of the lengths of all the code strings (in
 * ascending order by source values).  The actual code strings are
 * reconstructed from the lengths in the inflate process, as described
 * in the deflate specification.
 *
 *  REFERENCES
 *
 *      Deutsch, L.P.,"'Deflate' Compressed Data Format Specification".
 *      Available in ftp.uu.net:/pub/archiving/zip/doc/deflate-1.1.doc
 *
 *      Storer, James A.
 *          Data Compression:  Methods and Theory, pp. 49-50.
 *          Computer Science Press, 1988.  ISBN 0-7167-8156-5.
 *
 *      Sedgewick, R.
 *          Algorithms, p290.
 *          Addison-Wesley, 1983. ISBN 0-201-06672-6.
 */

/* @(#) $Id$ */

/* #define GEN_TREES_H */

#ifdef DEBUG

#endif

/* ===========================================================================
 * Constants
 */

#define MAX_BL_BITS 7
/* Bit length codes must not exceed MAX_BL_BITS bits */

#define END_BLOCK 256
/* end of block literal code */

#define REP_3_6      16
/* repeat previous bit length 3-6 times (2 bits of repeat count) */

#define REPZ_3_10    17
/* repeat a zero length 3-10 times  (3 bits of repeat count) */

#define REPZ_11_138  18
/* repeat a zero length 11-138 times  (7 bits of repeat count) */

local const int extra_lbits[LENGTH_CODES] /* extra bits for each length code */
   = {0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,0};

local const int extra_dbits[D_CODES] /* extra bits for each distance code */
   = {0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13};

local const int extra_blbits[BL_CODES]/* extra bits for each bit length code */
   = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,7};

local const uch bl_order[BL_CODES]
   = {16,17,18,0,8,7,9,6,10,5,11,4,12,3,13,2,14,1,15};
/* The lengths of the bit length codes are sent in order of decreasing
 * probability, to avoid transmitting the lengths for unused bit length codes.
 */

#define Buf_size (8 * 2*sizeof(char))
/* Number of bits used within bi_buf. (bi_buf might be implemented on
 * more than 16 bits on some systems.)
 */

/* ===========================================================================
 * Local data. These are initialized only once.
 */

#define DIST_CODE_LEN  512 /* see definition of array dist_code below */

#if defined(GEN_TREES_H) || !defined(STDC)
/* non ANSI compilers may not accept trees.h */

local ct_data static_ltree[L_CODES+2];
/* The static literal tree. Since the bit lengths are imposed, there is no
 * need for the L_CODES extra codes used during heap construction. However
 * The codes 286 and 287 are needed to build a canonical tree (see _tr_init
 * below).
 */

local ct_data static_dtree[D_CODES];
/* The static distance tree. (Actually a trivial tree since all codes use
 * 5 bits.)
 */

uch _dist_code[DIST_CODE_LEN];
/* Distance codes. The first 256 values correspond to the distances
 * 3 .. 258, the last 256 values correspond to the top 8 bits of
 * the 15 bit distances.
 */

uch _length_code[MAX_MATCH-MIN_MATCH+1];
/* length code for each normalized match length (0 == MIN_MATCH) */

local int base_length[LENGTH_CODES];
/* First normalized length for each code (0 = MIN_MATCH) */

local int base_dist[D_CODES];
/* First normalized distance for each code (0 = distance of 1) */

#else
/* header created automatically with -DGEN_TREES_H */

local const ct_data static_ltree[L_CODES+2] = {
{{ 12},{  8}}, {{140},{  8}}, {{ 76},{  8}}, {{204},{  8}}, {{ 44},{  8}},
{{172},{  8}}, {{108},{  8}}, {{236},{  8}}, {{ 28},{  8}}, {{156},{  8}},
{{ 92},{  8}}, {{220},{  8}}, {{ 60},{  8}}, {{188},{  8}}, {{124},{  8}},
{{252},{  8}}, {{  2},{  8}}, {{130},{  8}}, {{ 66},{  8}}, {{194},{  8}},
{{ 34},{  8}}, {{162},{  8}}, {{ 98},{  8}}, {{226},{  8}}, {{ 18},{  8}},
{{146},{  8}}, {{ 82},{  8}}, {{210},{  8}}, {{ 50},{  8}}, {{178},{  8}},
{{114},{  8}}, {{242},{  8}}, {{ 10},{  8}}, {{138},{  8}}, {{ 74},{  8}},
{{202},{  8}}, {{ 42},{  8}}, {{170},{  8}}, {{106},{  8}}, {{234},{  8}},
{{ 26},{  8}}, {{154},{  8}}, {{ 90},{  8}}, {{218},{  8}}, {{ 58},{  8}},
{{186},{  8}}, {{122},{  8}}, {{250},{  8}}, {{  6},{  8}}, {{134},{  8}},
{{ 70},{  8}}, {{198},{  8}}, {{ 38},{  8}}, {{166},{  8}}, {{102},{  8}},
{{230},{  8}}, {{ 22},{  8}}, {{150},{  8}}, {{ 86},{  8}}, {{214},{  8}},
{{ 54},{  8}}, {{182},{  8}}, {{118},{  8}}, {{246},{  8}}, {{ 14},{  8}},
{{142},{  8}}, {{ 78},{  8}}, {{206},{  8}}, {{ 46},{  8}}, {{174},{  8}},
{{110},{  8}}, {{238},{  8}}, {{ 30},{  8}}, {{158},{  8}}, {{ 94},{  8}},
{{222},{  8}}, {{ 62},{  8}}, {{190},{  8}}, {{126},{  8}}, {{254},{  8}},
{{  1},{  8}}, {{129},{  8}}, {{ 65},{  8}}, {{193},{  8}}, {{ 33},{  8}},
{{161},{  8}}, {{ 97},{  8}}, {{225},{  8}}, {{ 17},{  8}}, {{145},{  8}},
{{ 81},{  8}}, {{209},{  8}}, {{ 49},{  8}}, {{177},{  8}}, {{113},{  8}},
{{241},{  8}}, {{  9},{  8}}, {{137},{  8}}, {{ 73},{  8}}, {{201},{  8}},
{{ 41},{  8}}, {{169},{  8}}, {{105},{  8}}, {{233},{  8}}, {{ 25},{  8}},
{{153},{  8}}, {{ 89},{  8}}, {{217},{  8}}, {{ 57},{  8}}, {{185},{  8}},
{{121},{  8}}, {{249},{  8}}, {{  5},{  8}}, {{133},{  8}}, {{ 69},{  8}},
{{197},{  8}}, {{ 37},{  8}}, {{165},{  8}}, {{101},{  8}}, {{229},{  8}},
{{ 21},{  8}}, {{149},{  8}}, {{ 85},{  8}}, {{213},{  8}}, {{ 53},{  8}},
{{181},{  8}}, {{117},{  8}}, {{245},{  8}}, {{ 13},{  8}}, {{141},{  8}},
{{ 77},{  8}}, {{205},{  8}}, {{ 45},{  8}}, {{173},{  8}}, {{109},{  8}},
{{237},{  8}}, {{ 29},{  8}}, {{157},{  8}}, {{ 93},{  8}}, {{221},{  8}},
{{ 61},{  8}}, {{189},{  8}}, {{125},{  8}}, {{253},{  8}}, {{ 19},{  9}},
{{275},{  9}}, {{147},{  9}}, {{403},{  9}}, {{ 83},{  9}}, {{339},{  9}},
{{211},{  9}}, {{467},{  9}}, {{ 51},{  9}}, {{307},{  9}}, {{179},{  9}},
{{435},{  9}}, {{115},{  9}}, {{371},{  9}}, {{243},{  9}}, {{499},{  9}},
{{ 11},{  9}}, {{267},{  9}}, {{139},{  9}}, {{395},{  9}}, {{ 75},{  9}},
{{331},{  9}}, {{203},{  9}}, {{459},{  9}}, {{ 43},{  9}}, {{299},{  9}},
{{171},{  9}}, {{427},{  9}}, {{107},{  9}}, {{363},{  9}}, {{235},{  9}},
{{491},{  9}}, {{ 27},{  9}}, {{283},{  9}}, {{155},{  9}}, {{411},{  9}},
{{ 91},{  9}}, {{347},{  9}}, {{219},{  9}}, {{475},{  9}}, {{ 59},{  9}},
{{315},{  9}}, {{187},{  9}}, {{443},{  9}}, {{123},{  9}}, {{379},{  9}},
{{251},{  9}}, {{507},{  9}}, {{  7},{  9}}, {{263},{  9}}, {{135},{  9}},
{{391},{  9}}, {{ 71},{  9}}, {{327},{  9}}, {{199},{  9}}, {{455},{  9}},
{{ 39},{  9}}, {{295},{  9}}, {{167},{  9}}, {{423},{  9}}, {{103},{  9}},
{{359},{  9}}, {{231},{  9}}, {{487},{  9}}, {{ 23},{  9}}, {{279},{  9}},
{{151},{  9}}, {{407},{  9}}, {{ 87},{  9}}, {{343},{  9}}, {{215},{  9}},
{{471},{  9}}, {{ 55},{  9}}, {{311},{  9}}, {{183},{  9}}, {{439},{  9}},
{{119},{  9}}, {{375},{  9}}, {{247},{  9}}, {{503},{  9}}, {{ 15},{  9}},
{{271},{  9}}, {{143},{  9}}, {{399},{  9}}, {{ 79},{  9}}, {{335},{  9}},
{{207},{  9}}, {{463},{  9}}, {{ 47},{  9}}, {{303},{  9}}, {{175},{  9}},
{{431},{  9}}, {{111},{  9}}, {{367},{  9}}, {{239},{  9}}, {{495},{  9}},
{{ 31},{  9}}, {{287},{  9}}, {{159},{  9}}, {{415},{  9}}, {{ 95},{  9}},
{{351},{  9}}, {{223},{  9}}, {{479},{  9}}, {{ 63},{  9}}, {{319},{  9}},
{{191},{  9}}, {{447},{  9}}, {{127},{  9}}, {{383},{  9}}, {{255},{  9}},
{{511},{  9}}, {{  0},{  7}}, {{ 64},{  7}}, {{ 32},{  7}}, {{ 96},{  7}},
{{ 16},{  7}}, {{ 80},{  7}}, {{ 48},{  7}}, {{112},{  7}}, {{  8},{  7}},
{{ 72},{  7}}, {{ 40},{  7}}, {{104},{  7}}, {{ 24},{  7}}, {{ 88},{  7}},
{{ 56},{  7}}, {{120},{  7}}, {{  4},{  7}}, {{ 68},{  7}}, {{ 36},{  7}},
{{100},{  7}}, {{ 20},{  7}}, {{ 84},{  7}}, {{ 52},{  7}}, {{116},{  7}},
{{  3},{  8}}, {{131},{  8}}, {{ 67},{  8}}, {{195},{  8}}, {{ 35},{  8}},
{{163},{  8}}, {{ 99},{  8}}, {{227},{  8}}
};

local const ct_data static_dtree[D_CODES] = {
{{ 0},{ 5}}, {{16},{ 5}}, {{ 8},{ 5}}, {{24},{ 5}}, {{ 4},{ 5}},
{{20},{ 5}}, {{12},{ 5}}, {{28},{ 5}}, {{ 2},{ 5}}, {{18},{ 5}},
{{10},{ 5}}, {{26},{ 5}}, {{ 6},{ 5}}, {{22},{ 5}}, {{14},{ 5}},
{{30},{ 5}}, {{ 1},{ 5}}, {{17},{ 5}}, {{ 9},{ 5}}, {{25},{ 5}},
{{ 5},{ 5}}, {{21},{ 5}}, {{13},{ 5}}, {{29},{ 5}}, {{ 3},{ 5}},
{{19},{ 5}}, {{11},{ 5}}, {{27},{ 5}}, {{ 7},{ 5}}, {{23},{ 5}}
};

const uch _dist_code[DIST_CODE_LEN] = {
 0,  1,  2,  3,  4,  4,  5,  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  8,
 8,  8,  8,  8,  9,  9,  9,  9,  9,  9,  9,  9, 10, 10, 10, 10, 10, 10, 10, 10,
10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13,
13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  0,  0, 16, 17,
18, 18, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22,
23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 27,
27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
27, 27, 27, 27, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
28, 28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29
};

const uch _length_code[MAX_MATCH-MIN_MATCH+1]= {
 0,  1,  2,  3,  4,  5,  6,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 12, 12,
13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16,
17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19,
19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22,
22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 23,
23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 26, 26,
26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 28
};

local const int base_length[LENGTH_CODES] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 14, 16, 20, 24, 28, 32, 40, 48, 56,
64, 80, 96, 112, 128, 160, 192, 224, 0
};

local const int base_dist[D_CODES] = {
    0,     1,     2,     3,     4,     6,     8,    12,    16,    24,
   32,    48,    64,    96,   128,   192,   256,   384,   512,   768,
 1024,  1536,  2048,  3072,  4096,  6144,  8192, 12288, 16384, 24576
};


#endif /* GEN_TREES_H */

struct static_tree_desc_s {
    const ct_data *static_tree;  /* static tree or NULL */
    const intf *extra_bits;      /* extra bits for each code or NULL */
    int     extra_base;          /* base index for extra_bits */
    int     elems;               /* max number of elements in the tree */
    int     max_length;          /* max bit length for the codes */
};

local static_tree_desc  static_l_desc =
{static_ltree, extra_lbits, LITERALS+1, L_CODES, MAX_BITS};

local static_tree_desc  static_d_desc =
{static_dtree, extra_dbits, 0,          D_CODES, MAX_BITS};

local static_tree_desc  static_bl_desc =
{(const ct_data *)0, extra_blbits, 0,   BL_CODES, MAX_BL_BITS};

/* ===========================================================================
 * Local (static) routines in this file.
 */

local void tr_static_init OF((void));
local void init_block     OF((deflate_state *s));
local void pqdownheap     OF((deflate_state *s, ct_data *tree, int k));
local void gen_bitlen     OF((deflate_state *s, tree_desc *desc));
local void gen_codes      OF((ct_data *tree, int max_code, ushf *bl_count));
local void build_tree     OF((deflate_state *s, tree_desc *desc));
local void scan_tree      OF((deflate_state *s, ct_data *tree, int max_code));
local void send_tree      OF((deflate_state *s, ct_data *tree, int max_code));
local int  build_bl_tree  OF((deflate_state *s));
local void send_all_trees OF((deflate_state *s, int lcodes, int dcodes,
                              int blcodes));
local void compress_block OF((deflate_state *s, ct_data *ltree,
                              ct_data *dtree));
local void set_data_type  OF((deflate_state *s));
local unsigned bi_reverse OF((unsigned value, int length));
local void bi_windup      OF((deflate_state *s));
local void bi_flush       OF((deflate_state *s));
local void copy_block     OF((deflate_state *s, charf *buf, unsigned len,
                              int header));

#ifdef GEN_TREES_H
local void gen_trees_header OF((void));
#endif

#ifndef DEBUG
#  define send_code(s, c, tree) send_bits(s, tree[c].Code, tree[c].Len)
   /* Send a code of the given tree. c and tree must not have side effects */

#else /* DEBUG */
#  define send_code(s, c, tree) \
     { if (z_verbose>2) fprintf(stderr,"\ncd %3d ",(c)); \
       send_bits(s, tree[c].Code, tree[c].Len); }
#endif

/* ===========================================================================
 * Output a short LSB first on the stream.
 * IN assertion: there is enough room in pendingBuf.
 */
#define put_short(s, w) { \
    put_byte(s, (uch)((w) & 0xff)); \
    put_byte(s, (uch)((ush)(w) >> 8)); \
}

/* ===========================================================================
 * Send a value on a given number of bits.
 * IN assertion: length <= 16 and value fits in length bits.
 */
#ifdef DEBUG
local void send_bits      OF((deflate_state *s, int value, int length));

local void send_bits(deflate_state *s, int value, int length)
{
    Tracevv((stderr," l %2d v %4x ", length, value));
    Assert(length > 0 && length <= 15, "invalid length");
    s->bits_sent += (ulg)length;

    /* If not enough room in bi_buf, use (valid) bits from bi_buf and
     * (16 - bi_valid) bits from value, leaving (width - (16-bi_valid))
     * unused bits in value.
     */
    if (s->bi_valid > (int)Buf_size - length) {
        s->bi_buf |= (value << s->bi_valid);
        put_short(s, s->bi_buf);
        s->bi_buf = (ush)value >> (Buf_size - s->bi_valid);
        s->bi_valid += length - Buf_size;
    } else {
        s->bi_buf |= value << s->bi_valid;
        s->bi_valid += length;
    }
}
#else /* !DEBUG */

#define send_bits(s, value, length) \
{ int len = length;\
  if (s->bi_valid > (int)Buf_size - len) {\
    int val = value;\
    s->bi_buf |= (val << s->bi_valid);\
    put_short(s, s->bi_buf);\
    s->bi_buf = (ush)val >> (Buf_size - s->bi_valid);\
    s->bi_valid += len - Buf_size;\
  } else {\
    s->bi_buf |= (value) << s->bi_valid;\
    s->bi_valid += len;\
  }\
}
#endif /* DEBUG */


#define MAX(a,b) (a >= b ? a : b)
/* the arguments must not have side effects */

/* ===========================================================================
 * Initialize the various 'constant' tables.
 */
local void tr_static_init()
{
#if defined(GEN_TREES_H) || !defined(STDC)
    static int static_init_done = 0;
    int n;        /* iterates over tree elements */
    int bits;     /* bit counter */
    int length;   /* length value */
    int code;     /* code value */
    int dist;     /* distance index */
    ush bl_count[MAX_BITS+1];
    /* number of codes at each bit length for an optimal tree */

    if (static_init_done) return;

    /* For some embedded targets, global variables are not initialized: */
    static_l_desc.static_tree = static_ltree;
    static_l_desc.extra_bits = extra_lbits;
    static_d_desc.static_tree = static_dtree;
    static_d_desc.extra_bits = extra_dbits;
    static_bl_desc.extra_bits = extra_blbits;

    /* Initialize the mapping length (0..255) -> length code (0..28) */
    length = 0;
    for (code = 0; code < LENGTH_CODES-1; code++) {
        base_length[code] = length;
        for (n = 0; n < (1<<extra_lbits[code]); n++) {
            _length_code[length++] = (uch)code;
        }
    }
    Assert (length == 256, "tr_static_init: length != 256");
    /* Note that the length 255 (match length 258) can be represented
     * in two different ways: code 284 + 5 bits or code 285, so we
     * overwrite length_code[255] to use the best encoding:
     */
    _length_code[length-1] = (uch)code;

    /* Initialize the mapping dist (0..32K) -> dist code (0..29) */
    dist = 0;
    for (code = 0 ; code < 16; code++) {
        base_dist[code] = dist;
        for (n = 0; n < (1<<extra_dbits[code]); n++) {
            _dist_code[dist++] = (uch)code;
        }
    }
    Assert (dist == 256, "tr_static_init: dist != 256");
    dist >>= 7; /* from now on, all distances are divided by 128 */
    for ( ; code < D_CODES; code++) {
        base_dist[code] = dist << 7;
        for (n = 0; n < (1<<(extra_dbits[code]-7)); n++) {
            _dist_code[256 + dist++] = (uch)code;
        }
    }
    Assert (dist == 256, "tr_static_init: 256+dist != 512");

    /* Construct the codes of the static literal tree */
    for (bits = 0; bits <= MAX_BITS; bits++) bl_count[bits] = 0;
    n = 0;
    while (n <= 143) static_ltree[n++].Len = 8, bl_count[8]++;
    while (n <= 255) static_ltree[n++].Len = 9, bl_count[9]++;
    while (n <= 279) static_ltree[n++].Len = 7, bl_count[7]++;
    while (n <= 287) static_ltree[n++].Len = 8, bl_count[8]++;
    /* Codes 286 and 287 do not exist, but we must include them in the
     * tree construction to get a canonical Huffman tree (longest code
     * all ones)
     */
    gen_codes((ct_data *)static_ltree, L_CODES+1, bl_count);

    /* The static distance tree is trivial: */
    for (n = 0; n < D_CODES; n++) {
        static_dtree[n].Len = 5;
        static_dtree[n].Code = bi_reverse((unsigned)n, 5);
    }
    static_init_done = 1;

#  ifdef GEN_TREES_H
    gen_trees_header();
#  endif
#endif /* defined(GEN_TREES_H) || !defined(STDC) */
}

/* ===========================================================================
 * Genererate the file trees.h describing the static trees.
 */
#ifdef GEN_TREES_H
#  ifndef DEBUG

#  endif

#  define SEPARATOR(i, last, width) \
      ((i) == (last)? "\n};\n\n" :    \
       ((i) % (width) == (width)-1 ? ",\n" : ", "))

void gen_trees_header()
{
    FILE *header = fopen("trees.h", "w");
    int i;

    Assert (header != NULL, "Can't open trees.h");
    fprintf(header,
	    "/* header created automatically with -DGEN_TREES_H */\n\n");

    fprintf(header, "local const ct_data static_ltree[L_CODES+2] = {\n");
    for (i = 0; i < L_CODES+2; i++) {
	fprintf(header, "{{%3u},{%3u}}%s", static_ltree[i].Code,
		static_ltree[i].Len, SEPARATOR(i, L_CODES+1, 5));
    }

    fprintf(header, "local const ct_data static_dtree[D_CODES] = {\n");
    for (i = 0; i < D_CODES; i++) {
	fprintf(header, "{{%2u},{%2u}}%s", static_dtree[i].Code,
		static_dtree[i].Len, SEPARATOR(i, D_CODES-1, 5));
    }

    fprintf(header, "const uch _dist_code[DIST_CODE_LEN] = {\n");
    for (i = 0; i < DIST_CODE_LEN; i++) {
	fprintf(header, "%2u%s", _dist_code[i],
		SEPARATOR(i, DIST_CODE_LEN-1, 20));
    }

    fprintf(header, "const uch _length_code[MAX_MATCH-MIN_MATCH+1]= {\n");
    for (i = 0; i < MAX_MATCH-MIN_MATCH+1; i++) {
	fprintf(header, "%2u%s", _length_code[i],
		SEPARATOR(i, MAX_MATCH-MIN_MATCH, 20));
    }

    fprintf(header, "local const int base_length[LENGTH_CODES] = {\n");
    for (i = 0; i < LENGTH_CODES; i++) {
	fprintf(header, "%1u%s", base_length[i],
		SEPARATOR(i, LENGTH_CODES-1, 20));
    }

    fprintf(header, "local const int base_dist[D_CODES] = {\n");
    for (i = 0; i < D_CODES; i++) {
	fprintf(header, "%5u%s", base_dist[i],
		SEPARATOR(i, D_CODES-1, 10));
    }

    fclose(header);
}
#endif /* GEN_TREES_H */

/* ===========================================================================
 * Initialize the tree data structures for a new zlib stream.
 */
void _tr_init(deflate_state *s)
{
    tr_static_init();

    s->l_desc.dyn_tree = s->dyn_ltree;
    s->l_desc.stat_desc = &static_l_desc;

    s->d_desc.dyn_tree = s->dyn_dtree;
    s->d_desc.stat_desc = &static_d_desc;

    s->bl_desc.dyn_tree = s->bl_tree;
    s->bl_desc.stat_desc = &static_bl_desc;

    s->bi_buf = 0;
    s->bi_valid = 0;
    s->last_eob_len = 8; /* enough lookahead for inflate */
#ifdef DEBUG
    s->compressed_len = 0L;
    s->bits_sent = 0L;
#endif

    /* Initialize the first block of the first file: */
    init_block(s);
}

/* ===========================================================================
 * Initialize a new block.
 */
local void init_block(deflate_state *s)
{
    int n; /* iterates over tree elements */

    /* Initialize the trees. */
    for (n = 0; n < L_CODES;  n++) s->dyn_ltree[n].Freq = 0;
    for (n = 0; n < D_CODES;  n++) s->dyn_dtree[n].Freq = 0;
    for (n = 0; n < BL_CODES; n++) s->bl_tree[n].Freq = 0;

    s->dyn_ltree[END_BLOCK].Freq = 1;
    s->opt_len = s->static_len = 0L;
    s->last_lit = s->matches = 0;
}

#define SMALLEST 1
/* Index within the heap array of least frequent node in the Huffman tree */


/* ===========================================================================
 * Remove the smallest element from the heap and recreate the heap with
 * one less element. Updates heap and heap_len.
 */
#define pqremove(s, tree, top) \
{\
    top = s->heap[SMALLEST]; \
    s->heap[SMALLEST] = s->heap[s->heap_len--]; \
    pqdownheap(s, tree, SMALLEST); \
}

/* ===========================================================================
 * Compares to subtrees, using the tree depth as tie breaker when
 * the subtrees have equal frequency. This minimizes the worst case length.
 */
#define smaller(tree, n, m, depth) \
   (tree[n].Freq < tree[m].Freq || \
   (tree[n].Freq == tree[m].Freq && depth[n] <= depth[m]))

/* ===========================================================================
 * Restore the heap property by moving down the tree starting at node k,
 * exchanging a node with the smallest of its two sons if necessary, stopping
 * when the heap property is re-established (each father smaller than its
 * two sons).
 */
local void pqdownheap(deflate_state *s, ct_data *tree, int k)
{
    int v = s->heap[k];
    int j = k << 1;  /* left son of k */
    while (j <= s->heap_len) {
        /* Set j to the smallest of the two sons: */
        if (j < s->heap_len &&
            smaller(tree, s->heap[j+1], s->heap[j], s->depth)) {
            j++;
        }
        /* Exit if v is smaller than both sons */
        if (smaller(tree, v, s->heap[j], s->depth)) break;

        /* Exchange v with the smallest son */
        s->heap[k] = s->heap[j];  k = j;

        /* And continue down the tree, setting j to the left son of k */
        j <<= 1;
    }
    s->heap[k] = v;
}

/* ===========================================================================
 * Compute the optimal bit lengths for a tree and update the total bit length
 * for the current block.
 * IN assertion: the fields freq and dad are set, heap[heap_max] and
 *    above are the tree nodes sorted by increasing frequency.
 * OUT assertions: the field len is set to the optimal bit length, the
 *     array bl_count contains the frequencies for each bit length.
 *     The length opt_len is updated; static_len is also updated if stree is
 *     not null.
 */
local void gen_bitlen(deflate_state *s, tree_desc *desc)
{
    ct_data *tree        = desc->dyn_tree;
    int max_code         = desc->max_code;
    const ct_data *stree = desc->stat_desc->static_tree;
    const intf *extra    = desc->stat_desc->extra_bits;
    int base             = desc->stat_desc->extra_base;
    int max_length       = desc->stat_desc->max_length;
    int h;              /* heap index */
    int n, m;           /* iterate over the tree elements */
    int bits;           /* bit length */
    int xbits;          /* extra bits */
    ush f;              /* frequency */
    int overflow = 0;   /* number of elements with bit length too large */

    for (bits = 0; bits <= MAX_BITS; bits++) s->bl_count[bits] = 0;

    /* In a first pass, compute the optimal bit lengths (which may
     * overflow in the case of the bit length tree).
     */
    tree[s->heap[s->heap_max]].Len = 0; /* root of the heap */

    for (h = s->heap_max+1; h < HEAP_SIZE; h++) {
        n = s->heap[h];
        bits = tree[tree[n].Dad].Len + 1;
        if (bits > max_length) bits = max_length, overflow++;
        tree[n].Len = (ush)bits;
        /* We overwrite tree[n].Dad which is no longer needed */

        if (n > max_code) continue; /* not a leaf node */

        s->bl_count[bits]++;
        xbits = 0;
        if (n >= base) xbits = extra[n-base];
        f = tree[n].Freq;
        s->opt_len += (ulg)f * (bits + xbits);
        if (stree) s->static_len += (ulg)f * (stree[n].Len + xbits);
    }
    if (overflow == 0) return;

    Trace((stderr,"\nbit length overflow\n"));
    /* This happens for example on obj2 and pic of the Calgary corpus */

    /* Find the first bit length which could increase: */
    do {
        bits = max_length-1;
        while (s->bl_count[bits] == 0) bits--;
        s->bl_count[bits]--;      /* move one leaf down the tree */
        s->bl_count[bits+1] += 2; /* move one overflow item as its brother */
        s->bl_count[max_length]--;
        /* The brother of the overflow item also moves one step up,
         * but this does not affect bl_count[max_length]
         */
        overflow -= 2;
    } while (overflow > 0);

    /* Now recompute all bit lengths, scanning in increasing frequency.
     * h is still equal to HEAP_SIZE. (It is simpler to reconstruct all
     * lengths instead of fixing only the wrong ones. This idea is taken
     * from 'ar' written by Haruhiko Okumura.)
     */
    for (bits = max_length; bits != 0; bits--) {
        n = s->bl_count[bits];
        while (n != 0) {
            m = s->heap[--h];
            if (m > max_code) continue;
            if (tree[m].Len != (unsigned) bits) {
                Trace((stderr,"code %d bits %d->%d\n", m, tree[m].Len, bits));
                s->opt_len += ((long)bits - (long)tree[m].Len)
                              *(long)tree[m].Freq;
                tree[m].Len = (ush)bits;
            }
            n--;
        }
    }
}

/* ===========================================================================
 * Generate the codes for a given tree and bit counts (which need not be
 * optimal).
 * IN assertion: the array bl_count contains the bit length statistics for
 * the given tree and the field len is set for all tree elements.
 * OUT assertion: the field code is set for all tree elements of non
 *     zero code length.
 */
local void gen_codes(ct_data *tree, int max_code, ushf *bl_count)
{
    ush next_code[MAX_BITS+1]; /* next code value for each bit length */
    ush code = 0;              /* running code value */
    int bits;                  /* bit index */
    int n;                     /* code index */

    /* The distribution counts are first used to generate the code values
     * without bit reversal.
     */
    for (bits = 1; bits <= MAX_BITS; bits++) {
        next_code[bits] = code = (code + bl_count[bits-1]) << 1;
    }
    /* Check that the bit counts in bl_count are consistent. The last code
     * must be all ones.
     */
    Assert (code + bl_count[MAX_BITS]-1 == (1<<MAX_BITS)-1,
            "inconsistent bit counts");
    Tracev((stderr,"\ngen_codes: max_code %d ", max_code));

    for (n = 0;  n <= max_code; n++) {
        int len = tree[n].Len;
        if (len == 0) continue;
        /* Now reverse the bits */
        tree[n].Code = bi_reverse(next_code[len]++, len);

        Tracecv(tree != static_ltree, (stderr,"\nn %3d %c l %2d c %4x (%x) ",
             n, (isgraph(n) ? n : ' '), len, tree[n].Code, next_code[len]-1));
    }
}

/* ===========================================================================
 * Construct one Huffman tree and assigns the code bit strings and lengths.
 * Update the total bit length for the current block.
 * IN assertion: the field freq is set for all tree elements.
 * OUT assertions: the fields len and code are set to the optimal bit length
 *     and corresponding code. The length opt_len is updated; static_len is
 *     also updated if stree is not null. The field max_code is set.
 */
local void build_tree(deflate_state *s, tree_desc *desc)
{
    ct_data *tree         = desc->dyn_tree;
    const ct_data *stree  = desc->stat_desc->static_tree;
    int elems             = desc->stat_desc->elems;
    int n, m;          /* iterate over heap elements */
    int max_code = -1; /* largest code with non zero frequency */
    int node;          /* new node being created */

    /* Construct the initial heap, with least frequent element in
     * heap[SMALLEST]. The sons of heap[n] are heap[2*n] and heap[2*n+1].
     * heap[0] is not used.
     */
    s->heap_len = 0, s->heap_max = HEAP_SIZE;

    for (n = 0; n < elems; n++) {
        if (tree[n].Freq != 0) {
            s->heap[++(s->heap_len)] = max_code = n;
            s->depth[n] = 0;
        } else {
            tree[n].Len = 0;
        }
    }

    /* The pkzip format requires that at least one distance code exists,
     * and that at least one bit should be sent even if there is only one
     * possible code. So to avoid special checks later on we force at least
     * two codes of non zero frequency.
     */
    while (s->heap_len < 2) {
        node = s->heap[++(s->heap_len)] = (max_code < 2 ? ++max_code : 0);
        tree[node].Freq = 1;
        s->depth[node] = 0;
        s->opt_len--; if (stree) s->static_len -= stree[node].Len;
        /* node is 0 or 1 so it does not have extra bits */
    }
    desc->max_code = max_code;

    /* The elements heap[heap_len/2+1 .. heap_len] are leaves of the tree,
     * establish sub-heaps of increasing lengths:
     */
    for (n = s->heap_len/2; n >= 1; n--) pqdownheap(s, tree, n);

    /* Construct the Huffman tree by repeatedly combining the least two
     * frequent nodes.
     */
    node = elems;              /* next internal node of the tree */
    do {
        pqremove(s, tree, n);  /* n = node of least frequency */
        m = s->heap[SMALLEST]; /* m = node of next least frequency */

        s->heap[--(s->heap_max)] = n; /* keep the nodes sorted by frequency */
        s->heap[--(s->heap_max)] = m;

        /* Create a new node father of n and m */
        tree[node].Freq = tree[n].Freq + tree[m].Freq;
        s->depth[node] = (uch) (MAX(s->depth[n], s->depth[m]) + 1);
        tree[n].Dad = tree[m].Dad = (ush)node;
#ifdef DUMP_BL_TREE
        if (tree == s->bl_tree) {
            fprintf(stderr,"\nnode %d(%d), sons %d(%d) %d(%d)",
                    node, tree[node].Freq, n, tree[n].Freq, m, tree[m].Freq);
        }
#endif
        /* and insert the new node in the heap */
        s->heap[SMALLEST] = node++;
        pqdownheap(s, tree, SMALLEST);

    } while (s->heap_len >= 2);

    s->heap[--(s->heap_max)] = s->heap[SMALLEST];

    /* At this point, the fields freq and dad are set. We can now
     * generate the bit lengths.
     */
    gen_bitlen(s, (tree_desc *)desc);

    /* The field len is now set, we can generate the bit codes */
    gen_codes ((ct_data *)tree, max_code, s->bl_count);
}

/* ===========================================================================
 * Scan a literal or distance tree to determine the frequencies of the codes
 * in the bit length tree.
 */
local void scan_tree(deflate_state *s, ct_data *tree, int max_code)
{
    int n;                     /* iterates over all tree elements */
    int prevlen = -1;          /* last emitted length */
    int curlen;                /* length of current code */
    int nextlen = tree[0].Len; /* length of next code */
    int count = 0;             /* repeat count of the current code */
    int max_count = 7;         /* max repeat count */
    int min_count = 4;         /* min repeat count */

    if (nextlen == 0) max_count = 138, min_count = 3;
    tree[max_code+1].Len = (ush)0xffff; /* guard */

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen; nextlen = tree[n+1].Len;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            s->bl_tree[curlen].Freq += count;
        } else if (curlen != 0) {
            if (curlen != prevlen) s->bl_tree[curlen].Freq++;
            s->bl_tree[REP_3_6].Freq++;
        } else if (count <= 10) {
            s->bl_tree[REPZ_3_10].Freq++;
        } else {
            s->bl_tree[REPZ_11_138].Freq++;
        }
        count = 0; prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

/* ===========================================================================
 * Send a literal or distance tree in compressed form, using the codes in
 * bl_tree.
 */
local void send_tree(deflate_state *s, ct_data *tree, int max_code)
{
    int n;                     /* iterates over all tree elements */
    int prevlen = -1;          /* last emitted length */
    int curlen;                /* length of current code */
    int nextlen = tree[0].Len; /* length of next code */
    int count = 0;             /* repeat count of the current code */
    int max_count = 7;         /* max repeat count */
    int min_count = 4;         /* min repeat count */

    /* tree[max_code+1].Len = -1; */  /* guard already set */
    if (nextlen == 0) max_count = 138, min_count = 3;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen; nextlen = tree[n+1].Len;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            do { send_code(s, curlen, s->bl_tree); } while (--count != 0);

        } else if (curlen != 0) {
            if (curlen != prevlen) {
                send_code(s, curlen, s->bl_tree); count--;
            }
            Assert(count >= 3 && count <= 6, " 3_6?");
            send_code(s, REP_3_6, s->bl_tree); send_bits(s, count-3, 2);

        } else if (count <= 10) {
            send_code(s, REPZ_3_10, s->bl_tree); send_bits(s, count-3, 3);

        } else {
            send_code(s, REPZ_11_138, s->bl_tree); send_bits(s, count-11, 7);
        }
        count = 0; prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

/* ===========================================================================
 * Construct the Huffman tree for the bit lengths and return the index in
 * bl_order of the last bit length code to send.
 */
local int build_bl_tree(deflate_state *s)
{
    int max_blindex;  /* index of last bit length code of non zero freq */

    /* Determine the bit length frequencies for literal and distance trees */
    scan_tree(s, (ct_data *)s->dyn_ltree, s->l_desc.max_code);
    scan_tree(s, (ct_data *)s->dyn_dtree, s->d_desc.max_code);

    /* Build the bit length tree: */
    build_tree(s, (tree_desc *)(&(s->bl_desc)));
    /* opt_len now includes the length of the tree representations, except
     * the lengths of the bit lengths codes and the 5+5+4 bits for the counts.
     */

    /* Determine the number of bit length codes to send. The pkzip format
     * requires that at least 4 bit length codes be sent. (appnote.txt says
     * 3 but the actual value used is 4.)
     */
    for (max_blindex = BL_CODES-1; max_blindex >= 3; max_blindex--) {
        if (s->bl_tree[bl_order[max_blindex]].Len != 0) break;
    }
    /* Update opt_len to include the bit length tree and counts */
    s->opt_len += 3*(max_blindex+1) + 5+5+4;
    Tracev((stderr, "\ndyn trees: dyn %ld, stat %ld",
            s->opt_len, s->static_len));

    return max_blindex;
}

/* ===========================================================================
 * Send the header for a block using dynamic Huffman trees: the counts, the
 * lengths of the bit length codes, the literal tree and the distance tree.
 * IN assertion: lcodes >= 257, dcodes >= 1, blcodes >= 4.
 */
local void send_all_trees(deflate_state *s, int lcodes, int dcodes, int blcodes)
{
    int rank;                    /* index in bl_order */

    Assert (lcodes >= 257 && dcodes >= 1 && blcodes >= 4, "not enough codes");
    Assert (lcodes <= L_CODES && dcodes <= D_CODES && blcodes <= BL_CODES,
            "too many codes");
    Tracev((stderr, "\nbl counts: "));
    send_bits(s, lcodes-257, 5); /* not +255 as stated in appnote.txt */
    send_bits(s, dcodes-1,   5);
    send_bits(s, blcodes-4,  4); /* not -3 as stated in appnote.txt */
    for (rank = 0; rank < blcodes; rank++) {
        Tracev((stderr, "\nbl code %2d ", bl_order[rank]));
        send_bits(s, s->bl_tree[bl_order[rank]].Len, 3);
    }
    Tracev((stderr, "\nbl tree: sent %ld", s->bits_sent));

    send_tree(s, (ct_data *)s->dyn_ltree, lcodes-1); /* literal tree */
    Tracev((stderr, "\nlit tree: sent %ld", s->bits_sent));

    send_tree(s, (ct_data *)s->dyn_dtree, dcodes-1); /* distance tree */
    Tracev((stderr, "\ndist tree: sent %ld", s->bits_sent));
}

/* ===========================================================================
 * Send a stored block
 */
void _tr_stored_block(deflate_state *s, charf *buf, ulg stored_len, int eof)
{
    send_bits(s, (STORED_BLOCK<<1)+eof, 3);  /* send block type */
#ifdef DEBUG
    s->compressed_len = (s->compressed_len + 3 + 7) & (ulg)~7L;
    s->compressed_len += (stored_len + 4) << 3;
#endif
    copy_block(s, buf, (unsigned)stored_len, 1); /* with header */
}

/* ===========================================================================
 * Send one empty static block to give enough lookahead for inflate.
 * This takes 10 bits, of which 7 may remain in the bit buffer.
 * The current inflate code requires 9 bits of lookahead. If the
 * last two codes for the previous block (real code plus EOB) were coded
 * on 5 bits or less, inflate may have only 5+3 bits of lookahead to decode
 * the last real code. In this case we send two empty static blocks instead
 * of one. (There are no problems if the previous block is stored or fixed.)
 * To simplify the code, we assume the worst case of last real code encoded
 * on one bit only.
 */
void _tr_align(deflate_state *s)
{
    send_bits(s, STATIC_TREES<<1, 3);
    send_code(s, END_BLOCK, static_ltree);
#ifdef DEBUG
    s->compressed_len += 10L; /* 3 for block type, 7 for EOB */
#endif
    bi_flush(s);
    /* Of the 10 bits for the empty block, we have already sent
     * (10 - bi_valid) bits. The lookahead for the last real code (before
     * the EOB of the previous block) was thus at least one plus the length
     * of the EOB plus what we have just sent of the empty static block.
     */
    if (1 + s->last_eob_len + 10 - s->bi_valid < 9) {
        send_bits(s, STATIC_TREES<<1, 3);
        send_code(s, END_BLOCK, static_ltree);
#ifdef DEBUG
        s->compressed_len += 10L;
#endif
        bi_flush(s);
    }
    s->last_eob_len = 7;
}

/* ===========================================================================
 * Determine the best encoding for the current block: dynamic trees, static
 * trees or store, and output the encoded block to the zip file.
 */
void _tr_flush_block(deflate_state *s, charf *buf, ulg stored_len, int eof)
{
    ulg opt_lenb, static_lenb; /* opt_len and static_len in bytes */
    int max_blindex = 0;  /* index of last bit length code of non zero freq */

    /* Build the Huffman trees unless a stored block is forced */
    if (s->level > 0) {

	 /* Check if the file is ascii or binary */
	if (s->data_type == Z_UNKNOWN) set_data_type(s);

	/* Construct the literal and distance trees */
	build_tree(s, (tree_desc *)(&(s->l_desc)));
	Tracev((stderr, "\nlit data: dyn %ld, stat %ld", s->opt_len,
		s->static_len));

	build_tree(s, (tree_desc *)(&(s->d_desc)));
	Tracev((stderr, "\ndist data: dyn %ld, stat %ld", s->opt_len,
		s->static_len));
	/* At this point, opt_len and static_len are the total bit lengths of
	 * the compressed block data, excluding the tree representations.
	 */

	/* Build the bit length tree for the above two trees, and get the index
	 * in bl_order of the last bit length code to send.
	 */
	max_blindex = build_bl_tree(s);

	/* Determine the best encoding. Compute first the block length in bytes*/
	opt_lenb = (s->opt_len+3+7)>>3;
	static_lenb = (s->static_len+3+7)>>3;

	Tracev((stderr, "\nopt %lu(%lu) stat %lu(%lu) stored %lu lit %u ",
		opt_lenb, s->opt_len, static_lenb, s->static_len, stored_len,
		s->last_lit));

	if (static_lenb <= opt_lenb) opt_lenb = static_lenb;

    } else {
        Assert(buf != (char*)0, "lost buf");
	opt_lenb = static_lenb = stored_len + 5; /* force a stored block */
    }

#ifdef FORCE_STORED
    if (buf != (char*)0) { /* force stored block */
#else
    if (stored_len+4 <= opt_lenb && buf != (char*)0) {
                       /* 4: two words for the lengths */
#endif
        /* The test buf != NULL is only necessary if LIT_BUFSIZE > WSIZE.
         * Otherwise we can't have processed more than WSIZE input bytes since
         * the last block flush, because compression would have been
         * successful. If LIT_BUFSIZE <= WSIZE, it is never too late to
         * transform a block into a stored block.
         */
        _tr_stored_block(s, buf, stored_len, eof);

#ifdef FORCE_STATIC
    } else if (static_lenb >= 0) { /* force static trees */
#else
    } else if (static_lenb == opt_lenb) {
#endif
        send_bits(s, (STATIC_TREES<<1)+eof, 3);
        compress_block(s, (ct_data *)static_ltree, (ct_data *)static_dtree);
#ifdef DEBUG
        s->compressed_len += 3 + s->static_len;
#endif
    } else {
        send_bits(s, (DYN_TREES<<1)+eof, 3);
        send_all_trees(s, s->l_desc.max_code+1, s->d_desc.max_code+1,
                       max_blindex+1);
        compress_block(s, (ct_data *)s->dyn_ltree, (ct_data *)s->dyn_dtree);
#ifdef DEBUG
        s->compressed_len += 3 + s->opt_len;
#endif
    }
    Assert (s->compressed_len == s->bits_sent, "bad compressed size");
    /* The above check is made mod 2^32, for files larger than 512 MB
     * and uLong implemented on 32 bits.
     */
    init_block(s);

    if (eof) {
        bi_windup(s);
#ifdef DEBUG
        s->compressed_len += 7;  /* align on byte boundary */
#endif
    }
    Tracev((stderr,"\ncomprlen %lu(%lu) ", s->compressed_len>>3,
           s->compressed_len-7*eof));
}

/* ===========================================================================
 * Save the match info and tally the frequency counts. Return true if
 * the current block must be flushed.
 */
int _tr_tally(deflate_state *s, unsigned dist, unsigned lc)
{
    s->d_buf[s->last_lit] = (ush)dist;
    s->l_buf[s->last_lit++] = (uch)lc;
    if (dist == 0) {
        /* lc is the unmatched char */
        s->dyn_ltree[lc].Freq++;
    } else {
        s->matches++;
        /* Here, lc is the match length - MIN_MATCH */
        dist--;             /* dist = match distance - 1 */
        Assert((ush)dist < (ush)MAX_DIST(s) &&
               (ush)lc <= (ush)(MAX_MATCH-MIN_MATCH) &&
               (ush)d_code(dist) < (ush)D_CODES,  "_tr_tally: bad match");

        s->dyn_ltree[_length_code[lc]+LITERALS+1].Freq++;
        s->dyn_dtree[d_code(dist)].Freq++;
    }

#ifdef TRUNCATE_BLOCK
    /* Try to guess if it is profitable to stop the current block here */
    if ((s->last_lit & 0x1fff) == 0 && s->level > 2) {
        /* Compute an upper bound for the compressed length */
        ulg out_length = (ulg)s->last_lit*8L;
        ulg in_length = (ulg)((long)s->strstart - s->block_start);
        int dcode;
        for (dcode = 0; dcode < D_CODES; dcode++) {
            out_length += (ulg)s->dyn_dtree[dcode].Freq *
                (5L+extra_dbits[dcode]);
        }
        out_length >>= 3;
        Tracev((stderr,"\nlast_lit %u, in %ld, out ~%ld(%ld%%) ",
               s->last_lit, in_length, out_length,
               100L - out_length*100L/in_length));
        if (s->matches < s->last_lit/2 && out_length < in_length/2) return 1;
    }
#endif
    return (s->last_lit == s->lit_bufsize-1);
    /* We avoid equality with lit_bufsize because of wraparound at 64K
     * on 16 bit machines and because stored blocks are restricted to
     * 64K-1 bytes.
     */
}

/* ===========================================================================
 * Send the block data compressed using the given Huffman trees
 */
local void compress_block(deflate_state *s, ct_data *ltree, ct_data *dtree)
{
    unsigned dist;      /* distance of matched string */
    int lc;             /* match length or unmatched char (if dist == 0) */
    unsigned lx = 0;    /* running index in l_buf */
    unsigned code;      /* the code to send */
    int extra;          /* number of extra bits to send */

    if (s->last_lit != 0) do {
        dist = s->d_buf[lx];
        lc = s->l_buf[lx++];
        if (dist == 0) {
            send_code(s, lc, ltree); /* send a literal byte */
            Tracecv(isgraph(lc), (stderr," '%c' ", lc));
        } else {
            /* Here, lc is the match length - MIN_MATCH */
            code = _length_code[lc];
            send_code(s, code+LITERALS+1, ltree); /* send the length code */
            extra = extra_lbits[code];
            if (extra != 0) {
                lc -= base_length[code];
                send_bits(s, lc, extra);       /* send the extra length bits */
            }
            dist--; /* dist is now the match distance - 1 */
            code = d_code(dist);
            Assert (code < D_CODES, "bad d_code");

            send_code(s, code, dtree);       /* send the distance code */
            extra = extra_dbits[code];
            if (extra != 0) {
                dist -= base_dist[code];
                send_bits(s, dist, extra);   /* send the extra distance bits */
            }
        } /* literal or match pair ? */

        /* Check that the overlay between pending_buf and d_buf+l_buf is ok: */
        Assert(s->pending < s->lit_bufsize + 2*lx, "pendingBuf overflow");

    } while (lx < s->last_lit);

    send_code(s, END_BLOCK, ltree);
    s->last_eob_len = ltree[END_BLOCK].Len;
}

/* ===========================================================================
 * Set the data type to ASCII or BINARY, using a crude approximation:
 * binary if more than 20% of the bytes are <= 6 or >= 128, ascii otherwise.
 * IN assertion: the fields freq of dyn_ltree are set and the total of all
 * frequencies does not exceed 64K (to fit in an int on 16 bit machines).
 */
local void set_data_type(deflate_state *s)
{
    int n = 0;
    unsigned ascii_freq = 0;
    unsigned bin_freq = 0;
    while (n < 7)        bin_freq += s->dyn_ltree[n++].Freq;
    while (n < 128)    ascii_freq += s->dyn_ltree[n++].Freq;
    while (n < LITERALS) bin_freq += s->dyn_ltree[n++].Freq;
    s->data_type = (Byte)(bin_freq > (ascii_freq >> 2) ? Z_BINARY : Z_ASCII);
}

/* ===========================================================================
 * Reverse the first len bits of a code, using straightforward code (a faster
 * method would use a table)
 * IN assertion: 1 <= len <= 15
 */
local unsigned bi_reverse(unsigned code, int len)
{
    unsigned res = 0;
    do {
        res |= code & 1;
        code >>= 1, res <<= 1;
    } while (--len > 0);
    return res >> 1;
}

/* ===========================================================================
 * Flush the bit buffer, keeping at most 7 bits in it.
 */
local void bi_flush(deflate_state *s)
{
    if (s->bi_valid == 16) {
        put_short(s, s->bi_buf);
        s->bi_buf = 0;
        s->bi_valid = 0;
    } else if (s->bi_valid >= 8) {
        put_byte(s, (Byte)s->bi_buf);
        s->bi_buf >>= 8;
        s->bi_valid -= 8;
    }
}

/* ===========================================================================
 * Flush the bit buffer and align the output on a byte boundary
 */
local void bi_windup(deflate_state *s)
{
    if (s->bi_valid > 8) {
        put_short(s, s->bi_buf);
    } else if (s->bi_valid > 0) {
        put_byte(s, (Byte)s->bi_buf);
    }
    s->bi_buf = 0;
    s->bi_valid = 0;
#ifdef DEBUG
    s->bits_sent = (s->bits_sent+7) & ~7;
#endif
}

/* ===========================================================================
 * Copy a stored block, storing first the length and its
 * one's complement if requested.
 */
local void copy_block(deflate_state *s, charf *buf, unsigned len, int header)
{
    bi_windup(s);        /* align on byte boundary */
    s->last_eob_len = 8; /* enough lookahead for inflate */

    if (header) {
        put_short(s, (ush)len);   
        put_short(s, (ush)~len);
#ifdef DEBUG
        s->bits_sent += 2*16;
#endif
    }
#ifdef DEBUG
    s->bits_sent += (ulg)len<<3;
#endif
    while (len--) {
        put_byte(s, *buf++);
    }
}

#undef ERR_MSG
#undef ERR_RETURN
#undef ZALLOC
#undef ZFREE
#undef TRY_FREE

} // namespace zlib113::compression
namespace zlib113::decompression {
using Byte = zlib113::Byte;
using uInt = zlib113::uInt;
using uLong = zlib113::uLong;
using Bytef = Byte;
using charf = char;
using intf = int;
using uIntf = uInt;
using uLongf = uLong;
using voidpf = void*;
using voidp = void*;
using uch = unsigned char;
using uchf = uch;
using ush = unsigned short;
using ushf = ush;
using ulg = uLong;

struct internal_state;

using alloc_func = voidpf (*)(voidpf opaque, uInt items, uInt size);
using free_func = void (*)(voidpf opaque, voidpf address);

struct z_stream {
    Bytef* next_in{};
    uInt avail_in{};
    uLong total_in{};
    Bytef* next_out{};
    uInt avail_out{};
    uLong total_out{};
    char* msg{};
    internal_state* state{};
    alloc_func zalloc{};
    free_func zfree{};
    voidpf opaque{};
    int data_type{};
    uLong adler{};
    uLong reserved{};
};

using z_streamp = z_stream*;
using check_func = uLong (*)(uLong check, const Bytef* bytes, uInt size);

constexpr const char* z_errmsg[10] = {
    "need dictionary", "stream end", "", "file error", "stream error",
    "data error", "insufficient memory", "buffer error", "incompatible version", ""
};

voidpf zcalloc(voidpf, unsigned items, unsigned size) { return std::calloc(items, size); }
void zcfree(voidpf, voidpf address) { std::free(address); }
using zlib113::adler32;

#define ERR_MSG(error) z_errmsg[Z_NEED_DICT - (error)]
#define ERR_RETURN(stream, error) return ((stream)->msg = const_cast<char*>(ERR_MSG(error)), (error))
#define ZALLOC(stream, items, size) (*((stream)->zalloc))((stream)->opaque, (items), (size))
#define ZFREE(stream, address) (*((stream)->zfree))((stream)->opaque, static_cast<voidpf>(address))
#define TRY_FREE(stream, pointer) do { if (pointer) { ZFREE((stream), (pointer)); } } while (false)

/* inftrees.h -- header to use inftrees.c
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */

/* WARNING: this file should *not* be used by applications. It is
   part of the implementation of the compression library and is
   subject to change. Applications should only use zlib.h.
 */

/* Huffman code lookup table entry--this entry is four bytes for machines
   that have 16-bit pointers (e.g. PC's in the small or medium model). */

typedef struct inflate_huft_s FAR inflate_huft;

struct inflate_huft_s {
  union {
    struct {
      Byte Exop;        /* number of extra bits or operation */
      Byte Bits;        /* number of bits in this code or subcode */
    } what;
    uInt pad;           /* pad structure to a power of 2 (4 bytes for */
  } word;               /*  16-bit, 8 bytes for 32-bit int's) */
  uInt base;            /* literal, length base, distance base,
                           or table offset */
};

/* Maximum size of dynamic tree.  The maximum found in a long but non-
   exhaustive search was 1004 huft structures (850 for length/literals
   and 154 for distances, the latter actually the result of an
   exhaustive search).  The actual maximum is not known, but the
   value below is more than safe. */
#define MANY 1440

extern int inflate_trees_bits OF((
    uIntf *,                    /* 19 code lengths */
    uIntf *,                    /* bits tree desired/actual depth */
    inflate_huft * FAR *,       /* bits tree result */
    inflate_huft *,             /* space for trees */
    z_streamp));                /* for messages */

extern int inflate_trees_dynamic OF((
    uInt,                       /* number of literal/length codes */
    uInt,                       /* number of distance codes */
    uIntf *,                    /* that many (total) code lengths */
    uIntf *,                    /* literal desired/actual bit depth */
    uIntf *,                    /* distance desired/actual bit depth */
    inflate_huft * FAR *,       /* literal/length tree result */
    inflate_huft * FAR *,       /* distance tree result */
    inflate_huft *,             /* space for trees */
    z_streamp));                /* for messages */

extern int inflate_trees_fixed OF((
    uIntf *,                    /* literal desired/actual bit depth */
    uIntf *,                    /* distance desired/actual bit depth */
    inflate_huft * FAR *,       /* literal/length tree result */
    inflate_huft * FAR *,       /* distance tree result */
    z_streamp));                /* for memory allocation */

/* infblock.h -- header to use infblock.c
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */

/* WARNING: this file should *not* be used by applications. It is
   part of the implementation of the compression library and is
   subject to change. Applications should only use zlib.h.
 */

struct inflate_blocks_state;
typedef struct inflate_blocks_state FAR inflate_blocks_statef;

extern inflate_blocks_statef * inflate_blocks_new OF((
    z_streamp z,
    check_func c,               /* check function */
    uInt w));                   /* window size */

extern int inflate_blocks OF((
    inflate_blocks_statef *,
    z_streamp ,
    int));                      /* initial return code */

extern void inflate_blocks_reset OF((
    inflate_blocks_statef *,
    z_streamp ,
    uLongf *));                  /* check value on output */

extern int inflate_blocks_free OF((
    inflate_blocks_statef *,
    z_streamp));

extern void inflate_set_dictionary OF((
    inflate_blocks_statef *s,
    const Bytef *d,  /* dictionary */
    uInt  n));       /* dictionary length */

extern int inflate_blocks_sync_point OF((
    inflate_blocks_statef *s));

/* infcodes.h -- header to use infcodes.c
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */

/* WARNING: this file should *not* be used by applications. It is
   part of the implementation of the compression library and is
   subject to change. Applications should only use zlib.h.
 */

struct inflate_codes_state;
typedef struct inflate_codes_state FAR inflate_codes_statef;

extern inflate_codes_statef *inflate_codes_new OF((
    uInt, uInt,
    inflate_huft *, inflate_huft *,
    z_streamp ));

extern int inflate_codes OF((
    inflate_blocks_statef *,
    z_streamp ,
    int));

extern void inflate_codes_free OF((
    inflate_codes_statef *,
    z_streamp ));


/* inffast.h -- header to use inffast.c
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */

/* WARNING: this file should *not* be used by applications. It is
   part of the implementation of the compression library and is
   subject to change. Applications should only use zlib.h.
 */

extern int inflate_fast OF((
    uInt,
    uInt,
    inflate_huft *,
    inflate_huft *,
    inflate_blocks_statef *,
    z_streamp ));

/* infutil.h -- types and macros common to blocks and codes
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */

/* WARNING: this file should *not* be used by applications. It is
   part of the implementation of the compression library and is
   subject to change. Applications should only use zlib.h.
 */

#ifndef _INFUTIL_H
#define _INFUTIL_H

typedef enum {
      TYPE,     /* get type bits (3, including end bit) */
      LENS,     /* get lengths for stored */
      STORED,   /* processing stored block */
      TABLE,    /* get table lengths */
      BTREE,    /* get bit lengths tree for a dynamic block */
      DTREE,    /* get length, distance trees for a dynamic block */
      CODES,    /* processing fixed or dynamic block */
      DRY,      /* output remaining window bytes */
      DONE,     /* finished last block, done */
      BAD}      /* got a data error--stuck here */
inflate_block_mode;

/* inflate blocks semi-private state */
struct inflate_blocks_state {

  /* mode */
  inflate_block_mode  mode;     /* current inflate_block mode */

  /* mode dependent information */
  union {
    uInt left;          /* if STORED, bytes left to copy */
    struct {
      uInt table;               /* table lengths (14 bits) */
      uInt index;               /* index into blens (or border) */
      uIntf *blens;             /* bit lengths of codes */
      uInt bb;                  /* bit length tree depth */
      inflate_huft *tb;         /* bit length decoding tree */
    } trees;            /* if DTREE, decoding info for trees */
    struct {
      inflate_codes_statef 
         *codes;
    } decode;           /* if CODES, current state */
  } sub;                /* submode */
  uInt last;            /* true if this block is the last block */

  /* mode independent information */
  uInt bitk;            /* bits in bit buffer */
  uLong bitb;           /* bit buffer */
  inflate_huft *hufts;  /* single malloc for tree space */
  Bytef *window;        /* sliding window */
  Bytef *end;           /* one byte after sliding window */
  Bytef *read;          /* window read pointer */
  Bytef *write;         /* window write pointer */
  check_func checkfn;   /* check function */
  uLong check;          /* check on output */

};


/* defines for inflate input/output */
/*   update pointers and return */
#define UPDBITS {s->bitb=b;s->bitk=k;}
#define UPDIN {z->avail_in=n;z->total_in+=p-z->next_in;z->next_in=p;}
#define UPDOUT {s->write=q;}
#define UPDATE {UPDBITS UPDIN UPDOUT}
#define LEAVE {UPDATE return inflate_flush(s,z,r);}
/*   get bytes and bits */
#define LOADIN {p=z->next_in;n=z->avail_in;b=s->bitb;k=s->bitk;}
#define NEEDBYTE {if(n)r=Z_OK;else LEAVE}
#define NEXTBYTE (n--,*p++)
#define NEEDBITS(j) {while(k<(j)){NEEDBYTE;b|=((uLong)NEXTBYTE)<<k;k+=8;}}
#define DUMPBITS(j) {b>>=(j);k-=(j);}
/*   output bytes */
#define WAVAIL (uInt)(q<s->read?s->read-q-1:s->end-q)
#define LOADOUT {q=s->write;m=(uInt)WAVAIL;}
#define WRAP {if(q==s->end&&s->read!=s->window){q=s->window;m=(uInt)WAVAIL;}}
#define FLUSH {UPDOUT r=inflate_flush(s,z,r); LOADOUT}
#define NEEDOUT {if(m==0){WRAP if(m==0){FLUSH WRAP if(m==0) LEAVE}}r=Z_OK;}
#define OUTBYTE(a) {*q++=(Byte)(a);m--;}
/*   load local pointers */
#define LOAD {LOADIN LOADOUT}

/* masks for lower bits (size given to avoid silly warnings with Visual C++) */
extern uInt inflate_mask[17];

/* copy as much as possible from the sliding window to the output area */
extern int inflate_flush OF((
    inflate_blocks_statef *,
    z_streamp ,
    int));


#endif

/* infblock.c -- interpret and process block types to last block
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */


/* simplify the use of the inflate_huft type with some defines */
#define exop word.what.Exop
#define bits word.what.Bits

/* Table for deflate from PKZIP's appnote.txt. */
local const uInt border[] = { /* Order of the bit length code lengths */
        16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};

/*
   Notes beyond the 1.93a appnote.txt:

   1. Distance pointers never point before the beginning of the output
      stream.
   2. Distance pointers can point back across blocks, up to 32k away.
   3. There is an implied maximum of 7 bits for the bit length table and
      15 bits for the actual data.
   4. If only one code exists, then it is encoded using one bit.  (Zero
      would be more efficient, but perhaps a little confusing.)  If two
      codes exist, they are coded using one bit each (0 and 1).
   5. There is no way of sending zero distance codes--a dummy must be
      sent if there are none.  (History: a pre 2.0 version of PKZIP would
      store blocks with no distance codes, but this was discovered to be
      too harsh a criterion.)  Valid only for 1.93a.  2.04c does allow
      zero distance codes, which is sent as one code of zero bits in
      length.
   6. There are up to 286 literal/length codes.  Code 256 represents the
      end-of-block.  Note however that the static length tree defines
      288 codes just to fill out the Huffman codes.  Codes 286 and 287
      cannot be used though, since there is no length base or extra bits
      defined for them.  Similarily, there are up to 30 distance codes.
      However, static trees define 32 codes (all 5 bits) to fill out the
      Huffman codes, but the last two had better not show up in the data.
   7. Unzip can check dynamic Huffman blocks for complete code sets.
      The exception is that a single code would not be complete (see #4).
   8. The five bits following the block type is really the number of
      literal codes sent minus 257.
   9. Length codes 8,16,16 are interpreted as 13 length codes of 8 bits
      (1+6+6).  Therefore, to output three times the length, you output
      three codes (1+1+1), whereas to output four times the same length,
      you only need two codes (1+3).  Hmm.
  10. In the tree reconstruction algorithm, Code = Code + Increment
      only if BitLength(i) is not zero.  (Pretty obvious.)
  11. Correction: 4 Bits: # of Bit Length codes - 4     (4 - 19)
  12. Note: length code 284 can represent 227-258, but length code 285
      really is 258.  The last length deserves its own, short code
      since it gets used a lot in very redundant files.  The length
      258 is special since 258 - 3 (the min match length) is 255.
  13. The literal/length and distance code bit lengths are read as a
      single stream of lengths.  It is possible (and advantageous) for
      a repeat code (16, 17, or 18) to go across the boundary between
      the two sets of lengths.
 */


void inflate_blocks_reset(inflate_blocks_statef *s, z_streamp z, uLongf *c)
{
  if (c != Z_NULL)
    *c = s->check;
  if (s->mode == BTREE || s->mode == DTREE)
    ZFREE(z, s->sub.trees.blens);
  if (s->mode == CODES)
    inflate_codes_free(s->sub.decode.codes, z);
  s->mode = TYPE;
  s->bitk = 0;
  s->bitb = 0;
  s->read = s->write = s->window;
  if (s->checkfn != Z_NULL)
    z->adler = s->check = (*s->checkfn)(0L, (const Bytef *)Z_NULL, 0);
  Tracev((stderr, "inflate:   blocks reset\n"));
}


inflate_blocks_statef *inflate_blocks_new(z_streamp z, check_func c, uInt w)
{
  inflate_blocks_statef *s;

  if ((s = (inflate_blocks_statef *)ZALLOC
       (z,1,sizeof(struct inflate_blocks_state))) == Z_NULL)
    return s;
  if ((s->hufts =
       (inflate_huft *)ZALLOC(z, sizeof(inflate_huft), MANY)) == Z_NULL)
  {
    ZFREE(z, s);
    return Z_NULL;
  }
  if ((s->window = (Bytef *)ZALLOC(z, 1, w)) == Z_NULL)
  {
    ZFREE(z, s->hufts);
    ZFREE(z, s);
    return Z_NULL;
  }
  s->end = s->window + w;
  s->checkfn = c;
  s->mode = TYPE;
  Tracev((stderr, "inflate:   blocks allocated\n"));
  inflate_blocks_reset(s, z, Z_NULL);
  return s;
}


int inflate_blocks(inflate_blocks_statef *s, z_streamp z, int r)
{
  uInt t;               /* temporary storage */
  uLong b;              /* bit buffer */
  uInt k;               /* bits in bit buffer */
  Bytef *p;             /* input data pointer */
  uInt n;               /* bytes available there */
  Bytef *q;             /* output window write pointer */
  uInt m;               /* bytes to end of window or read pointer */

  /* copy input/output information to locals (UPDATE macro restores) */
  LOAD

  /* process input based on current state */
  while (1) switch (s->mode)
  {
    case TYPE:
      NEEDBITS(3)
      t = (uInt)b & 7;
      s->last = t & 1;
      switch (t >> 1)
      {
        case 0:                         /* stored */
          Tracev((stderr, "inflate:     stored block%s\n",
                 s->last ? " (last)" : ""));
          DUMPBITS(3)
          t = k & 7;                    /* go to byte boundary */
          DUMPBITS(t)
          s->mode = LENS;               /* get length of stored block */
          break;
        case 1:                         /* fixed */
          Tracev((stderr, "inflate:     fixed codes block%s\n",
                 s->last ? " (last)" : ""));
          {
            uInt bl, bd;
            inflate_huft *tl, *td;

            inflate_trees_fixed(&bl, &bd, &tl, &td, z);
            s->sub.decode.codes = inflate_codes_new(bl, bd, tl, td, z);
            if (s->sub.decode.codes == Z_NULL)
            {
              r = Z_MEM_ERROR;
              LEAVE
            }
          }
          DUMPBITS(3)
          s->mode = CODES;
          break;
        case 2:                         /* dynamic */
          Tracev((stderr, "inflate:     dynamic codes block%s\n",
                 s->last ? " (last)" : ""));
          DUMPBITS(3)
          s->mode = TABLE;
          break;
        case 3:                         /* illegal */
          DUMPBITS(3)
          s->mode = BAD;
          z->msg = (char*)"invalid block type";
          r = Z_DATA_ERROR;
          LEAVE
      }
      break;
    case LENS:
      NEEDBITS(32)
      if ((((~b) >> 16) & 0xffff) != (b & 0xffff))
      {
        s->mode = BAD;
        z->msg = (char*)"invalid stored block lengths";
        r = Z_DATA_ERROR;
        LEAVE
      }
      s->sub.left = (uInt)b & 0xffff;
      b = k = 0;                      /* dump bits */
      Tracev((stderr, "inflate:       stored length %u\n", s->sub.left));
      s->mode = s->sub.left ? STORED : (s->last ? DRY : TYPE);
      break;
    case STORED:
      if (n == 0)
        LEAVE
      NEEDOUT
      t = s->sub.left;
      if (t > n) t = n;
      if (t > m) t = m;
      zmemcpy(q, p, t);
      p += t;  n -= t;
      q += t;  m -= t;
      if ((s->sub.left -= t) != 0)
        break;
      Tracev((stderr, "inflate:       stored end, %lu total out\n",
              z->total_out + (q >= s->read ? q - s->read :
              (s->end - s->read) + (q - s->window))));
      s->mode = s->last ? DRY : TYPE;
      break;
    case TABLE:
      NEEDBITS(14)
      s->sub.trees.table = t = (uInt)b & 0x3fff;
#ifndef PKZIP_BUG_WORKAROUND
      if ((t & 0x1f) > 29 || ((t >> 5) & 0x1f) > 29)
      {
        s->mode = BAD;
        z->msg = (char*)"too many length or distance symbols";
        r = Z_DATA_ERROR;
        LEAVE
      }
#endif
      t = 258 + (t & 0x1f) + ((t >> 5) & 0x1f);
      if ((s->sub.trees.blens = (uIntf*)ZALLOC(z, t, sizeof(uInt))) == Z_NULL)
      {
        r = Z_MEM_ERROR;
        LEAVE
      }
      DUMPBITS(14)
      s->sub.trees.index = 0;
      Tracev((stderr, "inflate:       table sizes ok\n"));
      s->mode = BTREE;
    case BTREE:
      while (s->sub.trees.index < 4 + (s->sub.trees.table >> 10))
      {
        NEEDBITS(3)
        s->sub.trees.blens[border[s->sub.trees.index++]] = (uInt)b & 7;
        DUMPBITS(3)
      }
      while (s->sub.trees.index < 19)
        s->sub.trees.blens[border[s->sub.trees.index++]] = 0;
      s->sub.trees.bb = 7;
      t = inflate_trees_bits(s->sub.trees.blens, &s->sub.trees.bb,
                             &s->sub.trees.tb, s->hufts, z);
      if (t != Z_OK)
      {
        ZFREE(z, s->sub.trees.blens);
        r = t;
        if (r == Z_DATA_ERROR)
          s->mode = BAD;
        LEAVE
      }
      s->sub.trees.index = 0;
      Tracev((stderr, "inflate:       bits tree ok\n"));
      s->mode = DTREE;
    case DTREE:
      while (t = s->sub.trees.table,
             s->sub.trees.index < 258 + (t & 0x1f) + ((t >> 5) & 0x1f))
      {
        inflate_huft *h;
        uInt i, j, c;

        t = s->sub.trees.bb;
        NEEDBITS(t)
        h = s->sub.trees.tb + ((uInt)b & inflate_mask[t]);
        t = h->bits;
        c = h->base;
        if (c < 16)
        {
          DUMPBITS(t)
          s->sub.trees.blens[s->sub.trees.index++] = c;
        }
        else /* c == 16..18 */
        {
          i = c == 18 ? 7 : c - 14;
          j = c == 18 ? 11 : 3;
          NEEDBITS(t + i)
          DUMPBITS(t)
          j += (uInt)b & inflate_mask[i];
          DUMPBITS(i)
          i = s->sub.trees.index;
          t = s->sub.trees.table;
          if (i + j > 258 + (t & 0x1f) + ((t >> 5) & 0x1f) ||
              (c == 16 && i < 1))
          {
            ZFREE(z, s->sub.trees.blens);
            s->mode = BAD;
            z->msg = (char*)"invalid bit length repeat";
            r = Z_DATA_ERROR;
            LEAVE
          }
          c = c == 16 ? s->sub.trees.blens[i - 1] : 0;
          do {
            s->sub.trees.blens[i++] = c;
          } while (--j);
          s->sub.trees.index = i;
        }
      }
      s->sub.trees.tb = Z_NULL;
      {
        uInt bl, bd;
        inflate_huft *tl, *td;
        inflate_codes_statef *c;

        bl = 9;         /* must be <= 9 for lookahead assumptions */
        bd = 6;         /* must be <= 9 for lookahead assumptions */
        t = s->sub.trees.table;
        t = inflate_trees_dynamic(257 + (t & 0x1f), 1 + ((t >> 5) & 0x1f),
                                  s->sub.trees.blens, &bl, &bd, &tl, &td,
                                  s->hufts, z);
        ZFREE(z, s->sub.trees.blens);
        if (t != Z_OK)
        {
          if (t == (uInt)Z_DATA_ERROR)
            s->mode = BAD;
          r = t;
          LEAVE
        }
        Tracev((stderr, "inflate:       trees ok\n"));
        if ((c = inflate_codes_new(bl, bd, tl, td, z)) == Z_NULL)
        {
          r = Z_MEM_ERROR;
          LEAVE
        }
        s->sub.decode.codes = c;
      }
      s->mode = CODES;
    case CODES:
      UPDATE
      if ((r = inflate_codes(s, z, r)) != Z_STREAM_END)
        return inflate_flush(s, z, r);
      r = Z_OK;
      inflate_codes_free(s->sub.decode.codes, z);
      LOAD
      Tracev((stderr, "inflate:       codes end, %lu total out\n",
              z->total_out + (q >= s->read ? q - s->read :
              (s->end - s->read) + (q - s->window))));
      if (!s->last)
      {
        s->mode = TYPE;
        break;
      }
      s->mode = DRY;
    case DRY:
      FLUSH
      if (s->read != s->write)
        LEAVE
      s->mode = DONE;
    case DONE:
      r = Z_STREAM_END;
      LEAVE
    case BAD:
      r = Z_DATA_ERROR;
      LEAVE
    default:
      r = Z_STREAM_ERROR;
      LEAVE
  }
}


int inflate_blocks_free(inflate_blocks_statef *s, z_streamp z)
{
  inflate_blocks_reset(s, z, Z_NULL);
  ZFREE(z, s->window);
  ZFREE(z, s->hufts);
  ZFREE(z, s);
  Tracev((stderr, "inflate:   blocks freed\n"));
  return Z_OK;
}


void inflate_set_dictionary(inflate_blocks_statef *s, const Bytef *d, uInt n)
{
  zmemcpy(s->window, d, n);
  s->read = s->write = s->window + n;
}


/* Returns true if inflate is currently at the end of a block generated
 * by Z_SYNC_FLUSH or Z_FULL_FLUSH. 
 * IN assertion: s != Z_NULL
 */
int inflate_blocks_sync_point(inflate_blocks_statef *s)
{
  return s->mode == LENS;
}

/* infcodes.c -- process literals and length/distance pairs
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */






/* simplify the use of the inflate_huft type with some defines */
#define exop word.what.Exop
#define bits word.what.Bits

typedef enum {        /* waiting for "i:"=input, "o:"=output, "x:"=nothing */
      START,    /* x: set up for LEN */
      LEN,      /* i: get length/literal/eob next */
      LENEXT,   /* i: getting length extra (have base) */
      DIST,     /* i: get distance next */
      DISTEXT,  /* i: getting distance extra */
      COPY,     /* o: copying bytes in window, waiting for space */
      LIT,      /* o: got literal, waiting for output space */
      WASH,     /* o: got eob, possibly still output waiting */
      END,      /* x: got eob and all data flushed */
      BADCODE}  /* x: got error */
inflate_codes_mode;

/* inflate codes private state */
struct inflate_codes_state {

  /* mode */
  inflate_codes_mode mode;      /* current inflate_codes mode */

  /* mode dependent information */
  uInt len;
  union {
    struct {
      inflate_huft *tree;       /* pointer into tree */
      uInt need;                /* bits needed */
    } code;             /* if LEN or DIST, where in tree */
    uInt lit;           /* if LIT, literal */
    struct {
      uInt get;                 /* bits to get for extra */
      uInt dist;                /* distance back to copy from */
    } copy;             /* if EXT or COPY, where and how much */
  } sub;                /* submode */

  /* mode independent information */
  Byte lbits;           /* ltree bits decoded per branch */
  Byte dbits;           /* dtree bits decoder per branch */
  inflate_huft *ltree;          /* literal/length/eob tree */
  inflate_huft *dtree;          /* distance tree */

};


inflate_codes_statef *inflate_codes_new(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, z_streamp z)
{
  inflate_codes_statef *c;

  if ((c = (inflate_codes_statef *)
       ZALLOC(z,1,sizeof(struct inflate_codes_state))) != Z_NULL)
  {
    c->mode = START;
    c->lbits = (Byte)bl;
    c->dbits = (Byte)bd;
    c->ltree = tl;
    c->dtree = td;
    Tracev((stderr, "inflate:       codes new\n"));
  }
  return c;
}


int inflate_codes(inflate_blocks_statef *s, z_streamp z, int r)
{
  uInt j;               /* temporary storage */
  inflate_huft *t;      /* temporary pointer */
  uInt e;               /* extra bits or operation */
  uLong b;              /* bit buffer */
  uInt k;               /* bits in bit buffer */
  Bytef *p;             /* input data pointer */
  uInt n;               /* bytes available there */
  Bytef *q;             /* output window write pointer */
  uInt m;               /* bytes to end of window or read pointer */
  Bytef *f;             /* pointer to copy strings from */
  inflate_codes_statef *c = s->sub.decode.codes;  /* codes state */

  /* copy input/output information to locals (UPDATE macro restores) */
  LOAD

  /* process input and output based on current state */
  while (1) switch (c->mode)
  {             /* waiting for "i:"=input, "o:"=output, "x:"=nothing */
    case START:         /* x: set up for LEN */
#ifndef SLOW
      if (m >= 258 && n >= 10)
      {
        UPDATE
        r = inflate_fast(c->lbits, c->dbits, c->ltree, c->dtree, s, z);
        LOAD
        if (r != Z_OK)
        {
          c->mode = r == Z_STREAM_END ? WASH : BADCODE;
          break;
        }
      }
#endif /* !SLOW */
      c->sub.code.need = c->lbits;
      c->sub.code.tree = c->ltree;
      c->mode = LEN;
    case LEN:           /* i: get length/literal/eob next */
      j = c->sub.code.need;
      NEEDBITS(j)
      t = c->sub.code.tree + ((uInt)b & inflate_mask[j]);
      DUMPBITS(t->bits)
      e = (uInt)(t->exop);
      if (e == 0)               /* literal */
      {
        c->sub.lit = t->base;
        Tracevv((stderr, t->base >= 0x20 && t->base < 0x7f ?
                 "inflate:         literal '%c'\n" :
                 "inflate:         literal 0x%02x\n", t->base));
        c->mode = LIT;
        break;
      }
      if (e & 16)               /* length */
      {
        c->sub.copy.get = e & 15;
        c->len = t->base;
        c->mode = LENEXT;
        break;
      }
      if ((e & 64) == 0)        /* next table */
      {
        c->sub.code.need = e;
        c->sub.code.tree = t + t->base;
        break;
      }
      if (e & 32)               /* end of block */
      {
        Tracevv((stderr, "inflate:         end of block\n"));
        c->mode = WASH;
        break;
      }
      c->mode = BADCODE;        /* invalid code */
      z->msg = (char*)"invalid literal/length code";
      r = Z_DATA_ERROR;
      LEAVE
    case LENEXT:        /* i: getting length extra (have base) */
      j = c->sub.copy.get;
      NEEDBITS(j)
      c->len += (uInt)b & inflate_mask[j];
      DUMPBITS(j)
      c->sub.code.need = c->dbits;
      c->sub.code.tree = c->dtree;
      Tracevv((stderr, "inflate:         length %u\n", c->len));
      c->mode = DIST;
    case DIST:          /* i: get distance next */
      j = c->sub.code.need;
      NEEDBITS(j)
      t = c->sub.code.tree + ((uInt)b & inflate_mask[j]);
      DUMPBITS(t->bits)
      e = (uInt)(t->exop);
      if (e & 16)               /* distance */
      {
        c->sub.copy.get = e & 15;
        c->sub.copy.dist = t->base;
        c->mode = DISTEXT;
        break;
      }
      if ((e & 64) == 0)        /* next table */
      {
        c->sub.code.need = e;
        c->sub.code.tree = t + t->base;
        break;
      }
      c->mode = BADCODE;        /* invalid code */
      z->msg = (char*)"invalid distance code";
      r = Z_DATA_ERROR;
      LEAVE
    case DISTEXT:       /* i: getting distance extra */
      j = c->sub.copy.get;
      NEEDBITS(j)
      c->sub.copy.dist += (uInt)b & inflate_mask[j];
      DUMPBITS(j)
      Tracevv((stderr, "inflate:         distance %u\n", c->sub.copy.dist));
      c->mode = COPY;
    case COPY:          /* o: copying bytes in window, waiting for space */
#ifndef __TURBOC__ /* Turbo C bug for following expression */
      f = (uInt)(q - s->window) < c->sub.copy.dist ?
          s->end - (c->sub.copy.dist - (q - s->window)) :
          q - c->sub.copy.dist;
#else
      f = q - c->sub.copy.dist;
      if ((uInt)(q - s->window) < c->sub.copy.dist)
        f = s->end - (c->sub.copy.dist - (uInt)(q - s->window));
#endif
      while (c->len)
      {
        NEEDOUT
        OUTBYTE(*f++)
        if (f == s->end)
          f = s->window;
        c->len--;
      }
      c->mode = START;
      break;
    case LIT:           /* o: got literal, waiting for output space */
      NEEDOUT
      OUTBYTE(c->sub.lit)
      c->mode = START;
      break;
    case WASH:          /* o: got eob, possibly more output */
      if (k > 7)        /* return unused byte, if any */
      {
        Assert(k < 16, "inflate_codes grabbed too many bytes")
        k -= 8;
        n++;
        p--;            /* can always return one */
      }
      FLUSH
      if (s->read != s->write)
        LEAVE
      c->mode = END;
    case END:
      r = Z_STREAM_END;
      LEAVE
    case BADCODE:       /* x: got error */
      r = Z_DATA_ERROR;
      LEAVE
    default:
      r = Z_STREAM_ERROR;
      LEAVE
  }
#ifdef NEED_DUMMY_RETURN
  return Z_STREAM_ERROR;  /* Some dumb compilers complain without this */
#endif
}


void inflate_codes_free(inflate_codes_statef *c, z_streamp z)
{
  ZFREE(z, c);
  Tracev((stderr, "inflate:       codes free\n"));
}

/* inffast.c -- process literals and length/distance pairs fast
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */


/* simplify the use of the inflate_huft type with some defines */
#define exop word.what.Exop
#define bits word.what.Bits

/* macros for bit input with no checking and for returning unused bytes */
#define GRABBITS(j) {while(k<(j)){b|=((uLong)NEXTBYTE)<<k;k+=8;}}
#define UNGRAB {c=z->avail_in-n;c=(k>>3)<c?k>>3:c;n+=c;p-=c;k-=c<<3;}

/* Called with number of bytes left to write in window at least 258
   (the maximum string length) and number of input bytes available
   at least ten.  The ten bytes are six bytes for the longest length/
   distance pair plus four bytes for overloading the bit buffer. */

int inflate_fast(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, inflate_blocks_statef *s, z_streamp z)
{
  inflate_huft *t;      /* temporary pointer */
  uInt e;               /* extra bits or operation */
  uLong b;              /* bit buffer */
  uInt k;               /* bits in bit buffer */
  Bytef *p;             /* input data pointer */
  uInt n;               /* bytes available there */
  Bytef *q;             /* output window write pointer */
  uInt m;               /* bytes to end of window or read pointer */
  uInt ml;              /* mask for literal/length tree */
  uInt md;              /* mask for distance tree */
  uInt c;               /* bytes to copy */
  uInt d;               /* distance back to copy from */
  Bytef *r;             /* copy source pointer */

  /* load input, output, bit values */
  LOAD

  /* initialize masks */
  ml = inflate_mask[bl];
  md = inflate_mask[bd];

  /* do until not enough input or output space for fast loop */
  do {                          /* assume called with m >= 258 && n >= 10 */
    /* get literal/length code */
    GRABBITS(20)                /* max bits for literal/length code */
    if ((e = (t = tl + ((uInt)b & ml))->exop) == 0)
    {
      DUMPBITS(t->bits)
      Tracevv((stderr, t->base >= 0x20 && t->base < 0x7f ?
                "inflate:         * literal '%c'\n" :
                "inflate:         * literal 0x%02x\n", t->base));
      *q++ = (Byte)t->base;
      m--;
      continue;
    }
    do {
      DUMPBITS(t->bits)
      if (e & 16)
      {
        /* get extra bits for length */
        e &= 15;
        c = t->base + ((uInt)b & inflate_mask[e]);
        DUMPBITS(e)
        Tracevv((stderr, "inflate:         * length %u\n", c));

        /* decode distance base of block to copy */
        GRABBITS(15);           /* max bits for distance code */
        e = (t = td + ((uInt)b & md))->exop;
        do {
          DUMPBITS(t->bits)
          if (e & 16)
          {
            /* get extra bits to add to distance base */
            e &= 15;
            GRABBITS(e)         /* get extra bits (up to 13) */
            d = t->base + ((uInt)b & inflate_mask[e]);
            DUMPBITS(e)
            Tracevv((stderr, "inflate:         * distance %u\n", d));

            /* do the copy */
            m -= c;
            if ((uInt)(q - s->window) >= d)     /* offset before dest */
            {                                   /*  just copy */
              r = q - d;
              *q++ = *r++;  c--;        /* minimum count is three, */
              *q++ = *r++;  c--;        /*  so unroll loop a little */
            }
            else                        /* else offset after destination */
            {
              e = d - (uInt)(q - s->window); /* bytes from offset to end */
              r = s->end - e;           /* pointer to offset */
              if (c > e)                /* if source crosses, */
              {
                c -= e;                 /* copy to end of window */
                do {
                  *q++ = *r++;
                } while (--e);
                r = s->window;          /* copy rest from start of window */
              }
            }
            do {                        /* copy all or what's left */
              *q++ = *r++;
            } while (--c);
            break;
          }
          else if ((e & 64) == 0)
          {
            t += t->base;
            e = (t += ((uInt)b & inflate_mask[e]))->exop;
          }
          else
          {
            z->msg = (char*)"invalid distance code";
            UNGRAB
            UPDATE
            return Z_DATA_ERROR;
          }
        } while (1);
        break;
      }
      if ((e & 64) == 0)
      {
        t += t->base;
        if ((e = (t += ((uInt)b & inflate_mask[e]))->exop) == 0)
        {
          DUMPBITS(t->bits)
          Tracevv((stderr, t->base >= 0x20 && t->base < 0x7f ?
                    "inflate:         * literal '%c'\n" :
                    "inflate:         * literal 0x%02x\n", t->base));
          *q++ = (Byte)t->base;
          m--;
          break;
        }
      }
      else if (e & 32)
      {
        Tracevv((stderr, "inflate:         * end of block\n"));
        UNGRAB
        UPDATE
        return Z_STREAM_END;
      }
      else
      {
        z->msg = (char*)"invalid literal/length code";
        UNGRAB
        UPDATE
        return Z_DATA_ERROR;
      }
    } while (1);
  } while (m >= 258 && n >= 10);

  /* not enough input or output--restore pointers and return */
  UNGRAB
  UPDATE
  return Z_OK;
}

/* inftrees.c -- generate Huffman trees for efficient decoding
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */


#if !defined(BUILDFIXED) && !defined(STDC)
#  define BUILDFIXED   /* non ANSI compilers may not accept inffixed.h */
#endif

const char inflate_copyright[] =
   " inflate 1.1.3 Copyright 1995-1998 Mark Adler ";
/*
  If you use the zlib library in a product, an acknowledgment is welcome
  in the documentation of your product. If for some reason you cannot
  include such an acknowledgment, I would appreciate that you keep this
  copyright string in the executable of your product.
 */


/* simplify the use of the inflate_huft type with some defines */
#define exop word.what.Exop
#define bits word.what.Bits


local int huft_build OF((
    uIntf *,            /* code lengths in bits */
    uInt,               /* number of codes */
    uInt,               /* number of "simple" codes */
    const uIntf *,      /* list of base values for non-simple codes */
    const uIntf *,      /* list of extra bits for non-simple codes */
    inflate_huft * FAR*,/* result: starting table */
    uIntf *,            /* maximum lookup bits (returns actual) */
    inflate_huft *,     /* space for trees */
    uInt *,             /* hufts used in space */
    uIntf * ));         /* space for values */

/* Tables for deflate from PKZIP's appnote.txt. */
local const uInt cplens[31] = { /* Copy lengths for literal codes 257..285 */
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
        35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};
        /* see note #13 above about 258 */
local const uInt cplext[31] = { /* Extra bits for literal codes 257..285 */
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 112, 112}; /* 112==invalid */
local const uInt cpdist[30] = { /* Copy offsets for distance codes 0..29 */
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
        257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
        8193, 12289, 16385, 24577};
local const uInt cpdext[30] = { /* Extra bits for distance codes */
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
        12, 12, 13, 13};

/*
   Huffman code decoding is performed using a multi-level table lookup.
   The fastest way to decode is to simply build a lookup table whose
   size is determined by the longest code.  However, the time it takes
   to build this table can also be a factor if the data being decoded
   is not very long.  The most common codes are necessarily the
   shortest codes, so those codes dominate the decoding time, and hence
   the speed.  The idea is you can have a shorter table that decodes the
   shorter, more probable codes, and then point to subsidiary tables for
   the longer codes.  The time it costs to decode the longer codes is
   then traded against the time it takes to make longer tables.

   This results of this trade are in the variables lbits and dbits
   below.  lbits is the number of bits the first level table for literal/
   length codes can decode in one step, and dbits is the same thing for
   the distance codes.  Subsequent tables are also less than or equal to
   those sizes.  These values may be adjusted either when all of the
   codes are shorter than that, in which case the longest code length in
   bits is used, or when the shortest code is *longer* than the requested
   table size, in which case the length of the shortest code in bits is
   used.

   There are two different values for the two tables, since they code a
   different number of possibilities each.  The literal/length table
   codes 286 possible values, or in a flat code, a little over eight
   bits.  The distance table codes 30 possible values, or a little less
   than five bits, flat.  The optimum values for speed end up being
   about one bit more than those, so lbits is 8+1 and dbits is 5+1.
   The optimum values may differ though from machine to machine, and
   possibly even between compilers.  Your mileage may vary.
 */


/* If BMAX needs to be larger than 16, then h and x[] should be uLong. */
#define BMAX 15         /* maximum bit length of any code */

local int huft_build(uIntf *b, uInt n, uInt s, const uIntf *d, const uIntf *e, inflate_huft * FAR *t, uIntf *m, inflate_huft *hp, uInt *hn, uIntf *v)
/* Given a list of code lengths and a maximum table size, make a set of
   tables to decode that set of codes.  Return Z_OK on success, Z_BUF_ERROR
   if the given code set is incomplete (the tables are still built in this
   case), Z_DATA_ERROR if the input is invalid (an over-subscribed set of
   lengths), or Z_MEM_ERROR if not enough memory. */
{

  uInt a;                       /* counter for codes of length k */
  uInt c[BMAX+1];               /* bit length count table */
  uInt f;                       /* i repeats in table every f entries */
  int g;                        /* maximum code length */
  int h;                        /* table level */
  uInt i;              /* counter, current code */
  uInt j;              /* counter */
  int k;               /* number of bits in current code */
  int l;                        /* bits per table (returned in m) */
  uInt mask;                    /* (1 << w) - 1, to avoid cc -O bug on HP */
  uIntf *p;            /* pointer into c[], b[], or v[] */
  inflate_huft *q;              /* points to current table */
  struct inflate_huft_s r;      /* table entry for structure assignment */
  inflate_huft *u[BMAX];        /* table stack */
  int w;               /* bits before this table == (l * h) */
  uInt x[BMAX+1];               /* bit offsets, then code stack */
  uIntf *xp;                    /* pointer into x */
  int y;                        /* number of dummy codes added */
  uInt z;                       /* number of entries in current table */


  /* Generate counts for each bit length */
  p = c;
#define C0 *p++ = 0;
#define C2 C0 C0 C0 C0
#define C4 C2 C2 C2 C2
  C4                            /* clear c[]--assume BMAX+1 is 16 */
  p = b;  i = n;
  do {
    c[*p++]++;                  /* assume all entries <= BMAX */
  } while (--i);
  if (c[0] == n)                /* null input--all zero length codes */
  {
    *t = (inflate_huft *)Z_NULL;
    *m = 0;
    return Z_OK;
  }


  /* Find minimum and maximum length, bound *m by those */
  l = *m;
  for (j = 1; j <= BMAX; j++)
    if (c[j])
      break;
  k = j;                        /* minimum code length */
  if ((uInt)l < j)
    l = j;
  for (i = BMAX; i; i--)
    if (c[i])
      break;
  g = i;                        /* maximum code length */
  if ((uInt)l > i)
    l = i;
  *m = l;


  /* Adjust last length count to fill out codes, if needed */
  for (y = 1 << j; j < i; j++, y <<= 1)
    if ((y -= c[j]) < 0)
      return Z_DATA_ERROR;
  if ((y -= c[i]) < 0)
    return Z_DATA_ERROR;
  c[i] += y;


  /* Generate starting offsets into the value table for each length */
  x[1] = j = 0;
  p = c + 1;  xp = x + 2;
  while (--i) {                 /* note that i == g from above */
    *xp++ = (j += *p++);
  }


  /* Make a table of values in order of bit lengths */
  p = b;  i = 0;
  do {
    if ((j = *p++) != 0)
      v[x[j]++] = i;
  } while (++i < n);
  n = x[g];                     /* set n to length of v */


  /* Generate the Huffman codes and for each, make the table entries */
  x[0] = i = 0;                 /* first Huffman code is zero */
  p = v;                        /* grab values in bit order */
  h = -1;                       /* no tables yet--level -1 */
  w = -l;                       /* bits decoded == (l * h) */
  u[0] = (inflate_huft *)Z_NULL;        /* just to keep compilers happy */
  q = (inflate_huft *)Z_NULL;   /* ditto */
  z = 0;                        /* ditto */

  /* go through the bit lengths (k already is bits in shortest code) */
  for (; k <= g; k++)
  {
    a = c[k];
    while (a--)
    {
      /* here i is the Huffman code of length k bits for value *p */
      /* make tables up to required level */
      while (k > w + l)
      {
        h++;
        w += l;                 /* previous table always l bits */

        /* compute minimum size table less than or equal to l bits */
        z = g - w;
        z = z > (uInt)l ? l : z;        /* table size upper limit */
        if ((f = 1 << (j = k - w)) > a + 1)     /* try a k-w bit table */
        {                       /* too few codes for k-w bit table */
          f -= a + 1;           /* deduct codes from patterns left */
          xp = c + k;
          if (j < z)
            while (++j < z)     /* try smaller tables up to z bits */
            {
              if ((f <<= 1) <= *++xp)
                break;          /* enough codes to use up j bits */
              f -= *xp;         /* else deduct codes from patterns */
            }
        }
        z = 1 << j;             /* table entries for j-bit table */

        /* allocate new table */
        if (*hn + z > MANY)     /* (note: doesn't matter for fixed) */
          return Z_MEM_ERROR;   /* not enough memory */
        u[h] = q = hp + *hn;
        *hn += z;

        /* connect to last table, if there is one */
        if (h)
        {
          x[h] = i;             /* save pattern for backing up */
          r.bits = (Byte)l;     /* bits to dump before this table */
          r.exop = (Byte)j;     /* bits in this table */
          j = i >> (w - l);
          r.base = (uInt)(q - u[h-1] - j);   /* offset to this table */
          u[h-1][j] = r;        /* connect to last table */
        }
        else
          *t = q;               /* first table is returned result */
      }

      /* set up table entry in r */
      r.bits = (Byte)(k - w);
      if (p >= v + n)
        r.exop = 128 + 64;      /* out of values--invalid code */
      else if (*p < s)
      {
        r.exop = (Byte)(*p < 256 ? 0 : 32 + 64);     /* 256 is end-of-block */
        r.base = *p++;          /* simple code is just the value */
      }
      else
      {
        r.exop = (Byte)(e[*p - s] + 16 + 64);/* non-simple--look up in lists */
        r.base = d[*p++ - s];
      }

      /* fill code-like entries with r */
      f = 1 << (k - w);
      for (j = i >> w; j < z; j += f)
        q[j] = r;

      /* backwards increment the k-bit code i */
      for (j = 1 << (k - 1); i & j; j >>= 1)
        i ^= j;
      i ^= j;

      /* backup over finished tables */
      mask = (1 << w) - 1;      /* needed on HP, cc -O bug */
      while ((i & mask) != x[h])
      {
        h--;                    /* don't need to update q */
        w -= l;
        mask = (1 << w) - 1;
      }
    }
  }


  /* Return Z_BUF_ERROR if we were given an incomplete table */
  return y != 0 && g != 1 ? Z_BUF_ERROR : Z_OK;
}


int inflate_trees_bits(uIntf *c, uIntf *bb, inflate_huft * FAR *tb, inflate_huft *hp, z_streamp z)
{
  int r;
  uInt hn = 0;          /* hufts used in space */
  uIntf *v;             /* work area for huft_build */

  if ((v = (uIntf*)ZALLOC(z, 19, sizeof(uInt))) == Z_NULL)
    return Z_MEM_ERROR;
  r = huft_build(c, 19, 19, (uIntf*)Z_NULL, (uIntf*)Z_NULL,
                 tb, bb, hp, &hn, v);
  if (r == Z_DATA_ERROR)
    z->msg = (char*)"oversubscribed dynamic bit lengths tree";
  else if (r == Z_BUF_ERROR || *bb == 0)
  {
    z->msg = (char*)"incomplete dynamic bit lengths tree";
    r = Z_DATA_ERROR;
  }
  ZFREE(z, v);
  return r;
}


int inflate_trees_dynamic(uInt nl, uInt nd, uIntf *c, uIntf *bl, uIntf *bd, inflate_huft * FAR *tl, inflate_huft * FAR *td, inflate_huft *hp, z_streamp z)
{
  int r;
  uInt hn = 0;          /* hufts used in space */
  uIntf *v;             /* work area for huft_build */

  /* allocate work area */
  if ((v = (uIntf*)ZALLOC(z, 288, sizeof(uInt))) == Z_NULL)
    return Z_MEM_ERROR;

  /* build literal/length tree */
  r = huft_build(c, nl, 257, cplens, cplext, tl, bl, hp, &hn, v);
  if (r != Z_OK || *bl == 0)
  {
    if (r == Z_DATA_ERROR)
      z->msg = (char*)"oversubscribed literal/length tree";
    else if (r != Z_MEM_ERROR)
    {
      z->msg = (char*)"incomplete literal/length tree";
      r = Z_DATA_ERROR;
    }
    ZFREE(z, v);
    return r;
  }

  /* build distance tree */
  r = huft_build(c + nl, nd, 0, cpdist, cpdext, td, bd, hp, &hn, v);
  if (r != Z_OK || (*bd == 0 && nl > 257))
  {
    if (r == Z_DATA_ERROR)
      z->msg = (char*)"oversubscribed distance tree";
    else if (r == Z_BUF_ERROR) {
#ifdef PKZIP_BUG_WORKAROUND
      r = Z_OK;
    }
#else
      z->msg = (char*)"incomplete distance tree";
      r = Z_DATA_ERROR;
    }
    else if (r != Z_MEM_ERROR)
    {
      z->msg = (char*)"empty distance tree with lengths";
      r = Z_DATA_ERROR;
    }
    ZFREE(z, v);
    return r;
#endif
  }

  /* done */
  ZFREE(z, v);
  return Z_OK;
}


/* build fixed tables only once--keep them here */
#ifdef BUILDFIXED
local int fixed_built = 0;
#define FIXEDH 544      /* number of hufts used by fixed tables */
local inflate_huft fixed_mem[FIXEDH];
local uInt fixed_bl;
local uInt fixed_bd;
local inflate_huft *fixed_tl;
local inflate_huft *fixed_td;
#else
/* inffixed.h -- table for decoding fixed codes
 * Generated automatically by the maketree.c program
 */

/* WARNING: this file should *not* be used by applications. It is
   part of the implementation of the compression library and is
   subject to change. Applications should only use zlib.h.
 */

local uInt fixed_bl = 9;
local uInt fixed_bd = 5;
local inflate_huft fixed_tl[] = {
    {{{96,7}},256}, {{{0,8}},80}, {{{0,8}},16}, {{{84,8}},115},
    {{{82,7}},31}, {{{0,8}},112}, {{{0,8}},48}, {{{0,9}},192},
    {{{80,7}},10}, {{{0,8}},96}, {{{0,8}},32}, {{{0,9}},160},
    {{{0,8}},0}, {{{0,8}},128}, {{{0,8}},64}, {{{0,9}},224},
    {{{80,7}},6}, {{{0,8}},88}, {{{0,8}},24}, {{{0,9}},144},
    {{{83,7}},59}, {{{0,8}},120}, {{{0,8}},56}, {{{0,9}},208},
    {{{81,7}},17}, {{{0,8}},104}, {{{0,8}},40}, {{{0,9}},176},
    {{{0,8}},8}, {{{0,8}},136}, {{{0,8}},72}, {{{0,9}},240},
    {{{80,7}},4}, {{{0,8}},84}, {{{0,8}},20}, {{{85,8}},227},
    {{{83,7}},43}, {{{0,8}},116}, {{{0,8}},52}, {{{0,9}},200},
    {{{81,7}},13}, {{{0,8}},100}, {{{0,8}},36}, {{{0,9}},168},
    {{{0,8}},4}, {{{0,8}},132}, {{{0,8}},68}, {{{0,9}},232},
    {{{80,7}},8}, {{{0,8}},92}, {{{0,8}},28}, {{{0,9}},152},
    {{{84,7}},83}, {{{0,8}},124}, {{{0,8}},60}, {{{0,9}},216},
    {{{82,7}},23}, {{{0,8}},108}, {{{0,8}},44}, {{{0,9}},184},
    {{{0,8}},12}, {{{0,8}},140}, {{{0,8}},76}, {{{0,9}},248},
    {{{80,7}},3}, {{{0,8}},82}, {{{0,8}},18}, {{{85,8}},163},
    {{{83,7}},35}, {{{0,8}},114}, {{{0,8}},50}, {{{0,9}},196},
    {{{81,7}},11}, {{{0,8}},98}, {{{0,8}},34}, {{{0,9}},164},
    {{{0,8}},2}, {{{0,8}},130}, {{{0,8}},66}, {{{0,9}},228},
    {{{80,7}},7}, {{{0,8}},90}, {{{0,8}},26}, {{{0,9}},148},
    {{{84,7}},67}, {{{0,8}},122}, {{{0,8}},58}, {{{0,9}},212},
    {{{82,7}},19}, {{{0,8}},106}, {{{0,8}},42}, {{{0,9}},180},
    {{{0,8}},10}, {{{0,8}},138}, {{{0,8}},74}, {{{0,9}},244},
    {{{80,7}},5}, {{{0,8}},86}, {{{0,8}},22}, {{{192,8}},0},
    {{{83,7}},51}, {{{0,8}},118}, {{{0,8}},54}, {{{0,9}},204},
    {{{81,7}},15}, {{{0,8}},102}, {{{0,8}},38}, {{{0,9}},172},
    {{{0,8}},6}, {{{0,8}},134}, {{{0,8}},70}, {{{0,9}},236},
    {{{80,7}},9}, {{{0,8}},94}, {{{0,8}},30}, {{{0,9}},156},
    {{{84,7}},99}, {{{0,8}},126}, {{{0,8}},62}, {{{0,9}},220},
    {{{82,7}},27}, {{{0,8}},110}, {{{0,8}},46}, {{{0,9}},188},
    {{{0,8}},14}, {{{0,8}},142}, {{{0,8}},78}, {{{0,9}},252},
    {{{96,7}},256}, {{{0,8}},81}, {{{0,8}},17}, {{{85,8}},131},
    {{{82,7}},31}, {{{0,8}},113}, {{{0,8}},49}, {{{0,9}},194},
    {{{80,7}},10}, {{{0,8}},97}, {{{0,8}},33}, {{{0,9}},162},
    {{{0,8}},1}, {{{0,8}},129}, {{{0,8}},65}, {{{0,9}},226},
    {{{80,7}},6}, {{{0,8}},89}, {{{0,8}},25}, {{{0,9}},146},
    {{{83,7}},59}, {{{0,8}},121}, {{{0,8}},57}, {{{0,9}},210},
    {{{81,7}},17}, {{{0,8}},105}, {{{0,8}},41}, {{{0,9}},178},
    {{{0,8}},9}, {{{0,8}},137}, {{{0,8}},73}, {{{0,9}},242},
    {{{80,7}},4}, {{{0,8}},85}, {{{0,8}},21}, {{{80,8}},258},
    {{{83,7}},43}, {{{0,8}},117}, {{{0,8}},53}, {{{0,9}},202},
    {{{81,7}},13}, {{{0,8}},101}, {{{0,8}},37}, {{{0,9}},170},
    {{{0,8}},5}, {{{0,8}},133}, {{{0,8}},69}, {{{0,9}},234},
    {{{80,7}},8}, {{{0,8}},93}, {{{0,8}},29}, {{{0,9}},154},
    {{{84,7}},83}, {{{0,8}},125}, {{{0,8}},61}, {{{0,9}},218},
    {{{82,7}},23}, {{{0,8}},109}, {{{0,8}},45}, {{{0,9}},186},
    {{{0,8}},13}, {{{0,8}},141}, {{{0,8}},77}, {{{0,9}},250},
    {{{80,7}},3}, {{{0,8}},83}, {{{0,8}},19}, {{{85,8}},195},
    {{{83,7}},35}, {{{0,8}},115}, {{{0,8}},51}, {{{0,9}},198},
    {{{81,7}},11}, {{{0,8}},99}, {{{0,8}},35}, {{{0,9}},166},
    {{{0,8}},3}, {{{0,8}},131}, {{{0,8}},67}, {{{0,9}},230},
    {{{80,7}},7}, {{{0,8}},91}, {{{0,8}},27}, {{{0,9}},150},
    {{{84,7}},67}, {{{0,8}},123}, {{{0,8}},59}, {{{0,9}},214},
    {{{82,7}},19}, {{{0,8}},107}, {{{0,8}},43}, {{{0,9}},182},
    {{{0,8}},11}, {{{0,8}},139}, {{{0,8}},75}, {{{0,9}},246},
    {{{80,7}},5}, {{{0,8}},87}, {{{0,8}},23}, {{{192,8}},0},
    {{{83,7}},51}, {{{0,8}},119}, {{{0,8}},55}, {{{0,9}},206},
    {{{81,7}},15}, {{{0,8}},103}, {{{0,8}},39}, {{{0,9}},174},
    {{{0,8}},7}, {{{0,8}},135}, {{{0,8}},71}, {{{0,9}},238},
    {{{80,7}},9}, {{{0,8}},95}, {{{0,8}},31}, {{{0,9}},158},
    {{{84,7}},99}, {{{0,8}},127}, {{{0,8}},63}, {{{0,9}},222},
    {{{82,7}},27}, {{{0,8}},111}, {{{0,8}},47}, {{{0,9}},190},
    {{{0,8}},15}, {{{0,8}},143}, {{{0,8}},79}, {{{0,9}},254},
    {{{96,7}},256}, {{{0,8}},80}, {{{0,8}},16}, {{{84,8}},115},
    {{{82,7}},31}, {{{0,8}},112}, {{{0,8}},48}, {{{0,9}},193},
    {{{80,7}},10}, {{{0,8}},96}, {{{0,8}},32}, {{{0,9}},161},
    {{{0,8}},0}, {{{0,8}},128}, {{{0,8}},64}, {{{0,9}},225},
    {{{80,7}},6}, {{{0,8}},88}, {{{0,8}},24}, {{{0,9}},145},
    {{{83,7}},59}, {{{0,8}},120}, {{{0,8}},56}, {{{0,9}},209},
    {{{81,7}},17}, {{{0,8}},104}, {{{0,8}},40}, {{{0,9}},177},
    {{{0,8}},8}, {{{0,8}},136}, {{{0,8}},72}, {{{0,9}},241},
    {{{80,7}},4}, {{{0,8}},84}, {{{0,8}},20}, {{{85,8}},227},
    {{{83,7}},43}, {{{0,8}},116}, {{{0,8}},52}, {{{0,9}},201},
    {{{81,7}},13}, {{{0,8}},100}, {{{0,8}},36}, {{{0,9}},169},
    {{{0,8}},4}, {{{0,8}},132}, {{{0,8}},68}, {{{0,9}},233},
    {{{80,7}},8}, {{{0,8}},92}, {{{0,8}},28}, {{{0,9}},153},
    {{{84,7}},83}, {{{0,8}},124}, {{{0,8}},60}, {{{0,9}},217},
    {{{82,7}},23}, {{{0,8}},108}, {{{0,8}},44}, {{{0,9}},185},
    {{{0,8}},12}, {{{0,8}},140}, {{{0,8}},76}, {{{0,9}},249},
    {{{80,7}},3}, {{{0,8}},82}, {{{0,8}},18}, {{{85,8}},163},
    {{{83,7}},35}, {{{0,8}},114}, {{{0,8}},50}, {{{0,9}},197},
    {{{81,7}},11}, {{{0,8}},98}, {{{0,8}},34}, {{{0,9}},165},
    {{{0,8}},2}, {{{0,8}},130}, {{{0,8}},66}, {{{0,9}},229},
    {{{80,7}},7}, {{{0,8}},90}, {{{0,8}},26}, {{{0,9}},149},
    {{{84,7}},67}, {{{0,8}},122}, {{{0,8}},58}, {{{0,9}},213},
    {{{82,7}},19}, {{{0,8}},106}, {{{0,8}},42}, {{{0,9}},181},
    {{{0,8}},10}, {{{0,8}},138}, {{{0,8}},74}, {{{0,9}},245},
    {{{80,7}},5}, {{{0,8}},86}, {{{0,8}},22}, {{{192,8}},0},
    {{{83,7}},51}, {{{0,8}},118}, {{{0,8}},54}, {{{0,9}},205},
    {{{81,7}},15}, {{{0,8}},102}, {{{0,8}},38}, {{{0,9}},173},
    {{{0,8}},6}, {{{0,8}},134}, {{{0,8}},70}, {{{0,9}},237},
    {{{80,7}},9}, {{{0,8}},94}, {{{0,8}},30}, {{{0,9}},157},
    {{{84,7}},99}, {{{0,8}},126}, {{{0,8}},62}, {{{0,9}},221},
    {{{82,7}},27}, {{{0,8}},110}, {{{0,8}},46}, {{{0,9}},189},
    {{{0,8}},14}, {{{0,8}},142}, {{{0,8}},78}, {{{0,9}},253},
    {{{96,7}},256}, {{{0,8}},81}, {{{0,8}},17}, {{{85,8}},131},
    {{{82,7}},31}, {{{0,8}},113}, {{{0,8}},49}, {{{0,9}},195},
    {{{80,7}},10}, {{{0,8}},97}, {{{0,8}},33}, {{{0,9}},163},
    {{{0,8}},1}, {{{0,8}},129}, {{{0,8}},65}, {{{0,9}},227},
    {{{80,7}},6}, {{{0,8}},89}, {{{0,8}},25}, {{{0,9}},147},
    {{{83,7}},59}, {{{0,8}},121}, {{{0,8}},57}, {{{0,9}},211},
    {{{81,7}},17}, {{{0,8}},105}, {{{0,8}},41}, {{{0,9}},179},
    {{{0,8}},9}, {{{0,8}},137}, {{{0,8}},73}, {{{0,9}},243},
    {{{80,7}},4}, {{{0,8}},85}, {{{0,8}},21}, {{{80,8}},258},
    {{{83,7}},43}, {{{0,8}},117}, {{{0,8}},53}, {{{0,9}},203},
    {{{81,7}},13}, {{{0,8}},101}, {{{0,8}},37}, {{{0,9}},171},
    {{{0,8}},5}, {{{0,8}},133}, {{{0,8}},69}, {{{0,9}},235},
    {{{80,7}},8}, {{{0,8}},93}, {{{0,8}},29}, {{{0,9}},155},
    {{{84,7}},83}, {{{0,8}},125}, {{{0,8}},61}, {{{0,9}},219},
    {{{82,7}},23}, {{{0,8}},109}, {{{0,8}},45}, {{{0,9}},187},
    {{{0,8}},13}, {{{0,8}},141}, {{{0,8}},77}, {{{0,9}},251},
    {{{80,7}},3}, {{{0,8}},83}, {{{0,8}},19}, {{{85,8}},195},
    {{{83,7}},35}, {{{0,8}},115}, {{{0,8}},51}, {{{0,9}},199},
    {{{81,7}},11}, {{{0,8}},99}, {{{0,8}},35}, {{{0,9}},167},
    {{{0,8}},3}, {{{0,8}},131}, {{{0,8}},67}, {{{0,9}},231},
    {{{80,7}},7}, {{{0,8}},91}, {{{0,8}},27}, {{{0,9}},151},
    {{{84,7}},67}, {{{0,8}},123}, {{{0,8}},59}, {{{0,9}},215},
    {{{82,7}},19}, {{{0,8}},107}, {{{0,8}},43}, {{{0,9}},183},
    {{{0,8}},11}, {{{0,8}},139}, {{{0,8}},75}, {{{0,9}},247},
    {{{80,7}},5}, {{{0,8}},87}, {{{0,8}},23}, {{{192,8}},0},
    {{{83,7}},51}, {{{0,8}},119}, {{{0,8}},55}, {{{0,9}},207},
    {{{81,7}},15}, {{{0,8}},103}, {{{0,8}},39}, {{{0,9}},175},
    {{{0,8}},7}, {{{0,8}},135}, {{{0,8}},71}, {{{0,9}},239},
    {{{80,7}},9}, {{{0,8}},95}, {{{0,8}},31}, {{{0,9}},159},
    {{{84,7}},99}, {{{0,8}},127}, {{{0,8}},63}, {{{0,9}},223},
    {{{82,7}},27}, {{{0,8}},111}, {{{0,8}},47}, {{{0,9}},191},
    {{{0,8}},15}, {{{0,8}},143}, {{{0,8}},79}, {{{0,9}},255}
  };
local inflate_huft fixed_td[] = {
    {{{80,5}},1}, {{{87,5}},257}, {{{83,5}},17}, {{{91,5}},4097},
    {{{81,5}},5}, {{{89,5}},1025}, {{{85,5}},65}, {{{93,5}},16385},
    {{{80,5}},3}, {{{88,5}},513}, {{{84,5}},33}, {{{92,5}},8193},
    {{{82,5}},9}, {{{90,5}},2049}, {{{86,5}},129}, {{{192,5}},24577},
    {{{80,5}},2}, {{{87,5}},385}, {{{83,5}},25}, {{{91,5}},6145},
    {{{81,5}},7}, {{{89,5}},1537}, {{{85,5}},97}, {{{93,5}},24577},
    {{{80,5}},4}, {{{88,5}},769}, {{{84,5}},49}, {{{92,5}},12289},
    {{{82,5}},13}, {{{90,5}},3073}, {{{86,5}},193}, {{{192,5}},24577}
  };

#endif


int inflate_trees_fixed(uIntf *bl, uIntf *bd, inflate_huft * FAR *tl, inflate_huft * FAR *td, z_streamp z)
{
#ifdef BUILDFIXED
  /* build fixed tables if not already */
  if (!fixed_built)
  {
    int k;              /* temporary variable */
    uInt f = 0;         /* number of hufts used in fixed_mem */
    uIntf *c;           /* length list for huft_build */
    uIntf *v;           /* work area for huft_build */

    /* allocate memory */
    if ((c = (uIntf*)ZALLOC(z, 288, sizeof(uInt))) == Z_NULL)
      return Z_MEM_ERROR;
    if ((v = (uIntf*)ZALLOC(z, 288, sizeof(uInt))) == Z_NULL)
    {
      ZFREE(z, c);
      return Z_MEM_ERROR;
    }

    /* literal table */
    for (k = 0; k < 144; k++)
      c[k] = 8;
    for (; k < 256; k++)
      c[k] = 9;
    for (; k < 280; k++)
      c[k] = 7;
    for (; k < 288; k++)
      c[k] = 8;
    fixed_bl = 9;
    huft_build(c, 288, 257, cplens, cplext, &fixed_tl, &fixed_bl,
               fixed_mem, &f, v);

    /* distance table */
    for (k = 0; k < 30; k++)
      c[k] = 5;
    fixed_bd = 5;
    huft_build(c, 30, 0, cpdist, cpdext, &fixed_td, &fixed_bd,
               fixed_mem, &f, v);

    /* done */
    ZFREE(z, v);
    ZFREE(z, c);
    fixed_built = 1;
  }
#endif
  *bl = fixed_bl;
  *bd = fixed_bd;
  *tl = fixed_tl;
  *td = fixed_td;
  return Z_OK;
}

/* inflate_util.c -- data and routines common to blocks and codes
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */


/* And'ing with mask[n] masks the lower n bits */
uInt inflate_mask[17] = {
    0x0000,
    0x0001, 0x0003, 0x0007, 0x000f, 0x001f, 0x003f, 0x007f, 0x00ff,
    0x01ff, 0x03ff, 0x07ff, 0x0fff, 0x1fff, 0x3fff, 0x7fff, 0xffff
};


/* copy as much as possible from the sliding window to the output area */
int inflate_flush(inflate_blocks_statef *s, z_streamp z, int r)
{
  uInt n;
  Bytef *p;
  Bytef *q;

  /* local copies of source and destination pointers */
  p = z->next_out;
  q = s->read;

  /* compute number of bytes to copy as far as end of window */
  n = (uInt)((q <= s->write ? s->write : s->end) - q);
  if (n > z->avail_out) n = z->avail_out;
  if (n && r == Z_BUF_ERROR) r = Z_OK;

  /* update counters */
  z->avail_out -= n;
  z->total_out += n;

  /* update check information */
  if (s->checkfn != Z_NULL)
    z->adler = s->check = (*s->checkfn)(s->check, q, n);

  /* copy as far as end of window */
  zmemcpy(p, q, n);
  p += n;
  q += n;

  /* see if more to copy at beginning of window */
  if (q == s->end)
  {
    /* wrap pointers */
    q = s->window;
    if (s->write == s->end)
      s->write = s->window;

    /* compute bytes to copy */
    n = (uInt)(s->write - q);
    if (n > z->avail_out) n = z->avail_out;
    if (n && r == Z_BUF_ERROR) r = Z_OK;

    /* update counters */
    z->avail_out -= n;
    z->total_out += n;

    /* update check information */
    if (s->checkfn != Z_NULL)
      z->adler = s->check = (*s->checkfn)(s->check, q, n);

    /* copy */
    zmemcpy(p, q, n);
    p += n;
    q += n;
  }

  /* update pointers */
  z->next_out = p;
  s->read = q;

  /* done */
  return r;
}

#undef NEEDBYTE
#undef NEXTBYTE
/* inflate.c -- zlib interface to inflate modules
 * Copyright (C) 1995-1998 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h 
 */


typedef enum {
      METHOD,   /* waiting for method byte */
      FLAG,     /* waiting for flag byte */
      DICT4,    /* four dictionary check bytes to go */
      DICT3,    /* three dictionary check bytes to go */
      DICT2,    /* two dictionary check bytes to go */
      DICT1,    /* one dictionary check byte to go */
      DICT0,    /* waiting for inflateSetDictionary */
      BLOCKS,   /* decompressing blocks */
      CHECK4,   /* four check bytes to go */
      CHECK3,   /* three check bytes to go */
      CHECK2,   /* two check bytes to go */
      CHECK1,   /* one check byte to go */
      STREAM_DONE,     /* finished check, done */
      STREAM_BAD}      /* got an error--stay here */
inflate_mode;

/* inflate private state */
struct internal_state {

  /* mode */
  inflate_mode  mode;   /* current inflate mode */

  /* mode dependent information */
  union {
    uInt method;        /* if FLAGS, method byte */
    struct {
      uLong was;                /* computed check value */
      uLong need;               /* stream check value */
    } check;            /* if CHECK, check values to compare */
    uInt marker;        /* if STREAM_BAD, inflateSync's marker bytes count */
  } sub;        /* submode */

  /* mode independent information */
  int  nowrap;          /* flag for no wrapper */
  uInt wbits;           /* log2(window size)  (8..15, defaults to 15) */
  inflate_blocks_statef 
    *blocks;            /* current inflate_blocks state */

};


int ZEXPORT inflateReset(z_streamp z)
{
  if (z == Z_NULL || z->state == Z_NULL)
    return Z_STREAM_ERROR;
  z->total_in = z->total_out = 0;
  z->msg = Z_NULL;
  z->state->mode = z->state->nowrap ? BLOCKS : METHOD;
  inflate_blocks_reset(z->state->blocks, z, Z_NULL);
  Tracev((stderr, "inflate: reset\n"));
  return Z_OK;
}


int ZEXPORT inflateEnd(z_streamp z)
{
  if (z == Z_NULL || z->state == Z_NULL || z->zfree == Z_NULL)
    return Z_STREAM_ERROR;
  if (z->state->blocks != Z_NULL)
    inflate_blocks_free(z->state->blocks, z);
  ZFREE(z, z->state);
  z->state = Z_NULL;
  Tracev((stderr, "inflate: end\n"));
  return Z_OK;
}


int ZEXPORT inflateInit2_(z_streamp z, int w, const char *version, int stream_size)
{
  if (version == Z_NULL || version[0] != ZLIB_VERSION[0] ||
      stream_size != sizeof(z_stream))
      return Z_VERSION_ERROR;

  /* initialize state */
  if (z == Z_NULL)
    return Z_STREAM_ERROR;
  z->msg = Z_NULL;
  if (z->zalloc == Z_NULL)
  {
    z->zalloc = zcalloc;
    z->opaque = (voidpf)0;
  }
  if (z->zfree == Z_NULL) z->zfree = zcfree;
  if ((z->state = (struct internal_state FAR *)
       ZALLOC(z,1,sizeof(struct internal_state))) == Z_NULL)
    return Z_MEM_ERROR;
  z->state->blocks = Z_NULL;

  /* handle undocumented nowrap option (no zlib header or check) */
  z->state->nowrap = 0;
  if (w < 0)
  {
    w = - w;
    z->state->nowrap = 1;
  }

  /* set window size */
  if (w < 8 || w > 15)
  {
    inflateEnd(z);
    return Z_STREAM_ERROR;
  }
  z->state->wbits = (uInt)w;

  /* create inflate_blocks state */
  if ((z->state->blocks =
      inflate_blocks_new(z, z->state->nowrap ? Z_NULL : adler32, (uInt)1 << w))
      == Z_NULL)
  {
    inflateEnd(z);
    return Z_MEM_ERROR;
  }
  Tracev((stderr, "inflate: allocated\n"));

  /* reset state */
  inflateReset(z);
  return Z_OK;
}


int ZEXPORT inflateInit_(z_streamp z, const char *version, int stream_size)
{
  return inflateInit2_(z, DEF_WBITS, version, stream_size);
}


#define NEEDBYTE {if(z->avail_in==0)return r;r=f;}
#define NEXTBYTE (z->avail_in--,z->total_in++,*z->next_in++)

int ZEXPORT inflate(z_streamp z, int f)
{
  int r;
  uInt b;

  if (z == Z_NULL || z->state == Z_NULL || z->next_in == Z_NULL)
    return Z_STREAM_ERROR;
  f = f == Z_FINISH ? Z_BUF_ERROR : Z_OK;
  r = Z_BUF_ERROR;
  while (1) switch (z->state->mode)
  {
    case METHOD:
      NEEDBYTE
      if (((z->state->sub.method = NEXTBYTE) & 0xf) != Z_DEFLATED)
      {
        z->state->mode = STREAM_BAD;
        z->msg = (char*)"unknown compression method";
        z->state->sub.marker = 5;       /* can't try inflateSync */
        break;
      }
      if ((z->state->sub.method >> 4) + 8 > z->state->wbits)
      {
        z->state->mode = STREAM_BAD;
        z->msg = (char*)"invalid window size";
        z->state->sub.marker = 5;       /* can't try inflateSync */
        break;
      }
      z->state->mode = FLAG;
    case FLAG:
      NEEDBYTE
      b = NEXTBYTE;
      if (((z->state->sub.method << 8) + b) % 31)
      {
        z->state->mode = STREAM_BAD;
        z->msg = (char*)"incorrect header check";
        z->state->sub.marker = 5;       /* can't try inflateSync */
        break;
      }
      Tracev((stderr, "inflate: zlib header ok\n"));
      if (!(b & PRESET_DICT))
      {
        z->state->mode = BLOCKS;
        break;
      }
      z->state->mode = DICT4;
    case DICT4:
      NEEDBYTE
      z->state->sub.check.need = (uLong)NEXTBYTE << 24;
      z->state->mode = DICT3;
    case DICT3:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE << 16;
      z->state->mode = DICT2;
    case DICT2:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE << 8;
      z->state->mode = DICT1;
    case DICT1:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE;
      z->adler = z->state->sub.check.need;
      z->state->mode = DICT0;
      return Z_NEED_DICT;
    case DICT0:
      z->state->mode = STREAM_BAD;
      z->msg = (char*)"need dictionary";
      z->state->sub.marker = 0;       /* can try inflateSync */
      return Z_STREAM_ERROR;
    case BLOCKS:
      r = inflate_blocks(z->state->blocks, z, r);
      if (r == Z_DATA_ERROR)
      {
        z->state->mode = STREAM_BAD;
        z->state->sub.marker = 0;       /* can try inflateSync */
        break;
      }
      if (r == Z_OK)
        r = f;
      if (r != Z_STREAM_END)
        return r;
      r = f;
      inflate_blocks_reset(z->state->blocks, z, &z->state->sub.check.was);
      if (z->state->nowrap)
      {
        z->state->mode = STREAM_DONE;
        break;
      }
      z->state->mode = CHECK4;
    case CHECK4:
      NEEDBYTE
      z->state->sub.check.need = (uLong)NEXTBYTE << 24;
      z->state->mode = CHECK3;
    case CHECK3:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE << 16;
      z->state->mode = CHECK2;
    case CHECK2:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE << 8;
      z->state->mode = CHECK1;
    case CHECK1:
      NEEDBYTE
      z->state->sub.check.need += (uLong)NEXTBYTE;

      if (z->state->sub.check.was != z->state->sub.check.need)
      {
        z->state->mode = STREAM_BAD;
        z->msg = (char*)"incorrect data check";
        z->state->sub.marker = 5;       /* can't try inflateSync */
        break;
      }
      Tracev((stderr, "inflate: zlib check ok\n"));
      z->state->mode = STREAM_DONE;
    case STREAM_DONE:
      return Z_STREAM_END;
    case STREAM_BAD:
      return Z_DATA_ERROR;
    default:
      return Z_STREAM_ERROR;
  }
#ifdef NEED_DUMMY_RETURN
  return Z_STREAM_ERROR;  /* Some dumb compilers complain without this */
#endif
}


int ZEXPORT inflateSetDictionary(z_streamp z, const Bytef *dictionary, uInt dictLength)
{
  uInt length = dictLength;

  if (z == Z_NULL || z->state == Z_NULL || z->state->mode != DICT0)
    return Z_STREAM_ERROR;

  if (adler32(1L, dictionary, dictLength) != z->adler) return Z_DATA_ERROR;
  z->adler = 1L;

  if (length >= ((uInt)1<<z->state->wbits))
  {
    length = (1<<z->state->wbits)-1;
    dictionary += dictLength - length;
  }
  inflate_set_dictionary(z->state->blocks, dictionary, length);
  z->state->mode = BLOCKS;
  return Z_OK;
}


int ZEXPORT inflateSync(z_streamp z)
{
  uInt n;       /* number of bytes to look at */
  Bytef *p;     /* pointer to bytes */
  uInt m;       /* number of marker bytes found in a row */
  uLong r, w;   /* temporaries to save total_in and total_out */

  /* set up */
  if (z == Z_NULL || z->state == Z_NULL)
    return Z_STREAM_ERROR;
  if (z->state->mode != STREAM_BAD)
  {
    z->state->mode = STREAM_BAD;
    z->state->sub.marker = 0;
  }
  if ((n = z->avail_in) == 0)
    return Z_BUF_ERROR;
  p = z->next_in;
  m = z->state->sub.marker;

  /* search */
  while (n && m < 4)
  {
    static const Byte mark[4] = {0, 0, 0xff, 0xff};
    if (*p == mark[m])
      m++;
    else if (*p)
      m = 0;
    else
      m = 4 - m;
    p++, n--;
  }

  /* restore */
  z->total_in += p - z->next_in;
  z->next_in = p;
  z->avail_in = n;
  z->state->sub.marker = m;

  /* return no joy or set up to restart on a new block */
  if (m != 4)
    return Z_DATA_ERROR;
  r = z->total_in;  w = z->total_out;
  inflateReset(z);
  z->total_in = r;  z->total_out = w;
  z->state->mode = BLOCKS;
  return Z_OK;
}


/* Returns true if inflate is currently at the end of a block generated
 * by Z_SYNC_FLUSH or Z_FULL_FLUSH. This function is used by one PPP
 * implementation to provide an additional safety check. PPP uses Z_SYNC_FLUSH
 * but removes the length bytes of the resulting empty stored block. When
 * decompressing, PPP checks that at the end of input packet, inflate is
 * waiting for these length bytes.
 */
int ZEXPORT inflateSyncPoint(z_streamp z)
{
  if (z == Z_NULL || z->state == Z_NULL || z->state->blocks == Z_NULL)
    return Z_STREAM_ERROR;
  return inflate_blocks_sync_point(z->state->blocks);
}

#undef ERR_MSG
#undef ERR_RETURN
#undef ZALLOC
#undef ZFREE
#undef TRY_FREE

} // namespace zlib113::decompression
namespace zlib113 {
int compress(Bytef* destination, uLongf* destination_size, const Bytef* source, uLong source_size, int level) {
    compression::z_stream stream{};
    stream.next_in = const_cast<Bytef*>(source);
    stream.avail_in = source_size;
    stream.next_out = destination;
    stream.avail_out = *destination_size;
    int result = compression::deflateInit_(&stream, level, ZLIB_VERSION, sizeof(stream));
    if (result != Z_OK) { return result; }
    result = compression::deflate(&stream, Z_FINISH);
    if (result != Z_STREAM_END) {
        compression::deflateEnd(&stream);
        return result == Z_OK ? Z_BUF_ERROR : result;
    }
    *destination_size = stream.total_out;
    return compression::deflateEnd(&stream);
}

int decompress(Bytef* destination, uLongf* destination_size, const Bytef* source, uLong source_size) {
    decompression::z_stream stream{};
    stream.next_in = const_cast<Bytef*>(source);
    stream.avail_in = source_size;
    stream.next_out = destination;
    stream.avail_out = *destination_size;
    int result = decompression::inflateInit_(&stream, ZLIB_VERSION, sizeof(stream));
    if (result != Z_OK) { return result; }
    result = decompression::inflate(&stream, Z_FINISH);
    if (result != Z_STREAM_END) {
        decompression::inflateEnd(&stream);
        return result == Z_OK ? Z_BUF_ERROR : result;
    }
    *destination_size = stream.total_out;
    return decompression::inflateEnd(&stream);
}

} // namespace zlib113
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
namespace directx {
namespace {
struct ErrorDescription {
    std::int32_t result;
    const char* text;
};

constexpr std::array<ErrorDescription, 704> kErrorDescriptions{{
    {-2147483638, "The data necessary to complete this operation is not yet available."},
    {-2147467263, "The function called is not supported at this time"},
    {-2147467262, "The requested COM interface is not available"},
    {-2147467261, "Invalid pointer"},
    {-2147467260, "Operation aborted"},
    {-2147467259, "An undetermined error occurred"},
    {-2147418113, "Catastrophic failure"},
    {-2147221232, "This object does not support aggregation"},
    {-2147221164, "Class not registered"},
    {-2147221008, "CoInitialize has not been called."},
    {-2147221007, "CoInitialize has already been called."},
    {-2147220992, "Unable to IDirectInputJoyConfig_Acquire because the user does not have sufficient privileges to change the joystick configuration. & An invalid media type was specified"},
    {-2147220991, "The device is full. & An invalid media subtype was specified."},
    {-2147220990, "Not all the requested information fit into the buffer. & This object can only be created as an aggregated object."},
    {-2147220989, "The effect is not downloaded. & The enumerator has become invalid."},
    {-2147220988, "The device cannot be reinitialized because there are still effects attached to it. & At least one of the pins involved in the operation is already connected."},
    {-2147220987, "The operation cannot be performed unless the device is acquired in DISCL_EXCLUSIVE mode. & This operation cannot be performed because the filter is active."},
    {-2147220986, "The effect could not be downloaded because essential information is missing.  For example, no axes have been associated with the effect, or no type-specific information has been created. & One of the specified pins supports no media types."},
    {-2147220985, "Attempted to read buffered device data from a device that is not buffered. & There is no common media type between these pins."},
    {-2147220984, "An attempt was made to modify parameters of an effect while it is playing.  Not all hardware devices support altering the parameters of an effect while it is playing. & Two pins of the same direction cannot be connected together."},
    {-2147220983, "The operation could not be completed because the device is not plugged in. & The operation cannot be performed because the pins are not connected."},
    {-2147220982, "SendDeviceData failed because more information was requested to be sent than can be sent to the device.  Some devices have restrictions on how much data can be sent to them.  (For example, there might be a limit on the number of buttons that can be pressed at once.) & No sample buffer allocator is available."},
    {-2147220981, "A mapper file function failed because reading or writing the user or IHV settings file failed. & A run-time error occurred."},
    {-2147220980, "No buffer space has been set"},
    {-2147220979, "The buffer is not big enough."},
    {-2147220978, "An invalid alignment was specified."},
    {-2147220977, "Cannot change allocated memory while the filter is active."},
    {-2147220976, "One or more buffers are still active."},
    {-2147220975, "Cannot allocate a sample when the allocator is not active."},
    {-2147220974, "Cannot allocate memory because no size has been set."},
    {-2147220973, "Cannot lock for synchronization because no clock has been defined."},
    {-2147220972, "Quality messages could not be sent because no quality sink has been defined."},
    {-2147220971, "A required interface has not been implemented."},
    {-2147220970, "An object or name was not found."},
    {-2147220969, "No combination of intermediate filters could be found to make the connection."},
    {-2147220968, "No combination of filters could be found to render the stream."},
    {-2147220967, "Could not change formats dynamically."},
    {-2147220966, "No color key has been set."},
    {-2147220965, "Current pin connection is not using the IOverlay transport."},
    {-2147220964, "Current pin connection is not using the IMemInputPin transport."},
    {-2147220963, "Setting a color key would conflict with the palette already set."},
    {-2147220962, "Setting a palette would conflict with the color key already set."},
    {-2147220961, "No matching color key is available."},
    {-2147220960, "No palette is available."},
    {-2147220959, "Display does not use a palette."},
    {-2147220958, "Too many colors for the current display settings."},
    {-2147220957, "The state changed while waiting to process the sample."},
    {-2147220956, "The operation could not be performed because the filter is not stopped."},
    {-2147220955, "The operation could not be performed because the filter is not paused."},
    {-2147220954, "The operation could not be performed because the filter is not running."},
    {-2147220953, "The operation could not be performed because the filter is in the wrong state."},
    {-2147220952, "The sample start time is after the sample end time."},
    {-2147220951, "The supplied rectangle is invalid."},
    {-2147220950, "This pin cannot use the supplied media type."},
    {-2147220949, "This sample cannot be rendered."},
    {-2147220948, "This sample cannot be rendered because the end of the stream has been reached."},
    {-2147220947, "An attempt to add a filter with a duplicate name failed."},
    {-2147220946, "A time-out has expired."},
    {-2147220945, "The file format is invalid."},
    {-2147220944, "The list has already been exhausted."},
    {-2147220943, "The filter graph is circular."},
    {-2147220942, "Updates are not allowed in this state."},
    {-2147220941, "An attempt was made to queue a command for a time in the past."},
    {-2147220940, "The queued command has already been canceled."},
    {-2147220939, "Cannot render the file because it is corrupt."},
    {-2147220938, "An overlay advise link already exists."},
    {-2147220936, "No full-screen modes are available."},
    {-2147220935, "This Advise cannot be canceled because it was not successfully set."},
    {-2147220934, "A full-screen mode is not available."},
    {-2147220933, "Cannot call IVideoWindow methods while in full-screen mode."},
    {-2147220928, "The media type of this file is not recognized."},
    {-2147220927, "The source filter for this file could not be loaded."},
    {-2147220925, "A file appeared to be incomplete."},
    {-2147220924, "The version number of the file is invalid."},
    {-2147220921, "This file is corrupt: it contains an invalid class identifier."},
    {-2147220920, "This file is corrupt: it contains an invalid media type."},
    {-2147220919, "No time stamp has been set for this sample."},
    {-2147220911, "No media time stamp has been set for this sample."},
    {-2147220910, "No media time format has been selected."},
    {-2147220909, "Cannot change balance because audio device is mono only."},
    {-2147220907, "Cannot play back the video stream: no suitable decompressor could be found."},
    {-2147220906, "Cannot play back the audio stream: no audio hardware is available, or the hardware is not responding."},
    {-2147220903, "Cannot play back the video stream: format 'RPZA' is not supported."},
    {-2147220901, "ActiveMovie cannot play MPEG movies on this processor."},
    {-2147220900, "Cannot play back the audio stream: the audio format is not supported."},
    {-2147220899, "Cannot play back the video stream: the video format is not supported."},
    {-2147220898, "ActiveMovie cannot play this video stream because it falls outside the constrained standard."},
    {-2147220897, "Cannot perform the requested function on an object that is not in the filter graph."},
    {-2147220895, "Cannot get or set time related information on an object that is using a time format of TIME_FORMAT_NONE."},
    {-2147220894, "The connection cannot be made because the stream is read only and the filter alters the data."},
    {-2147220892, "The buffer is not full enough."},
    {-2147220891, "Cannot play back the file.  The format is not supported."},
    {-2147220890, "Pins cannot connect due to not supporting the same transport."},
    {-2147220887, "The Video CD can't be read correctly by the device or is the data is corrupt."},
    {-2147220879, "There is not enough Video Memory at this display resolution and number of colors. Reducing resolution might help."},
    {-2147220878, "The VideoPort connection negotiation process has failed."},
    {-2147220877, "Either DirectDraw has not been installed or the Video Card capabilities are not suitable. Make sure the display is not in 16 color mode."},
    {-2147220876, "No VideoPort hardware is available, or the hardware is not responding."},
    {-2147220875, "No Capture hardware is available, or the hardware is not responding."},
    {-2147220874, "This User Operation is inhibited by DVD Content at this time."},
    {-2147220873, "This Operation is not permitted in the current domain."},
    {-2147220872, "The specified button is invalid or is not present at the current time, or there is no button present at the specified location."},
    {-2147220871, "DVD-Video playback graph has not been built yet."},
    {-2147220870, "DVD-Video playback graph building failed."},
    {-2147220869, "DVD-Video playback graph could not be built due to insufficient decoders."},
    {-2147220868, "Version number of DirectDraw not suitable. Make sure to install dx5 or higher version."},
    {-2147220867, "Copy protection cannot be enabled. Please make sure any other copy protected content is not being shown now."},
    {-2147220865, "This object cannot be used anymore as its time has expired."},
    {-2147220863, "The operation cannot be performed at the current playback speed."},
    {-2147220862, "The specified menu doesn't exist."},
    {-2147220861, "The specified command was either cancelled or no longer exists."},
    {-2147220860, "The data did not contain a recognized version."},
    {-2147220859, "The state data was corrupt."},
    {-2147220858, "The state data is from a different disc."},
    {-2147220857, "The region was not compatible with the current drive."},
    {-2147220856, "The requested DVD stream attribute does not exist."},
    {-2147220855, "Currently there is no GoUp (Annex J user function) program chain (PGC)."},
    {-2147220854, "The current parental level was too low."},
    {-2147220853, "The current audio is not karaoke content."},
    {-2147220850, "Frame step is not supported on this configuration."},
    {-2147220849, "The specified stream is disabled and cannot be selected."},
    {-2147220848, "The operation depends on the current title number, however the navigator has not yet entered the VTSM or the title domains, so the 'current' title index is unknown."},
    {-2147220847, "The specified path does not point to a valid DVD disc."},
    {-2147220846, "There is currently no resume information."},
    {-2147220845, "This thread has already blocked this output pin.  There is no need to call IPinFlowControl::Block() again."},
    {-2147220844, "IPinFlowControl::Block() has been called on another thread.  The current thread cannot make any assumptions about this pin's block state."},
    {-2147220843, "An operation failed due to a certification failure."},
    {-2147220736, "Device driver-specific codes. Unless the specific driver has been precisely identified, no meaning should be attributed to these values other than that the driver originated the error."},
    {-2147220735, "DIERR_DRIVERFIRST+1"},
    {-2147220734, "DIERR_DRIVERFIRST+2"},
    {-2147220733, "DIERR_DRIVERFIRST+3"},
    {-2147220732, "DIERR_DRIVERFIRST+4"},
    {-2147220731, "DIERR_DRIVERFIRST+5"},
    {-2147220494, "A registry entry is corrupt."},
    {-2147220481, "Device installer errors."},
    {-2147220480, "Registry entry or DLL for class installer invalid or class installer not found."},
    {-2147220479, "The user cancelled the install operation. & The stream already has allocated samples and the surface doesn't match the sample format."},
    {-2147220478, "The INF file for the selected device could not be found or is invalid or is damaged. & The specified purpose ID can't be used for the call."},
    {-2147220477, "No stream can be found with the specified attributes."},
    {-2147220476, "Seeking not supported for this object."},
    {-2147220475, "The stream formats are not compatible."},
    {-2147220474, "The sample is busy."},
    {-2147220473, "The object can't accept the call because its initialize function or equivalent has not been called."},
    {-2147220472, "MS_E_SOURCEALREADYDEFINED"},
    {-2147220471, "The stream type is not valid for this operation."},
    {-2147220470, "The object is not in running state."},
    {-2147219199, "Could not initialize Direct3D."},
    {-2147219198, "No device could be found with the specified device settings."},
    {-2147219197, "A media file could not be found."},
    {-2147219196, "The device interface has a non-zero reference count, meaning that some objects were not released."},
    {-2147219195, "An error occurred when attempting to create a device."},
    {-2147219194, "An error occurred when attempting to reset a device."},
    {-2147219193, "An error occurred in the device create callback function."},
    {-2147219192, "An error occurred in the device reset callback function."},
    {-2147219191, "Incorrect version of Direct3D or D3DX."},
    {-2147219190, "The device was removed."},
    {-2147024894, "The system cannot find the file specified."},
    {-2147024893, "The system cannot find the path specified."},
    {-2147024892, "The system cannot open the file."},
    {-2147024891, "Access is denied"},
    {-2147024890, "Invalid handle"},
    {-2147024888, "Not enough storage is available to process this command."},
    {-2147024887, "The storage control block address is invalid."},
    {-2147024886, "The environment is incorrect."},
    {-2147024885, "An attempt was made to load a program with an incorrect format."},
    {-2147024884, "The operation cannot be performed unless the device is acquired."},
    {-2147024882, "Ran out of memory"},
    {-2147024875, "This object has not been initialized"},
    {-2147024866, "Access to the device has been lost.  It must be re-acquired."},
    {-2147024809, "An invalid parameter was passed to the returning function"},
    {-2147024777, "The object could not be created due to an incompatible driver version or mismatched or incomplete driver components."},
    {-2147024726, "The operation cannot be performed while the device is acquired."},
    {-2147024637, "No more items."},
    {-2147023746, "The application requires a newer version of DirectInput."},
    {-2147023743, "The application was written for an unsupported prerelease version of DirectInput."},
    {-2147023728, "The specified property ID is not supported for the specified property set."},
    {-2147023726, "The specified property set is not supported."},
    {-2147023649, "This object is already initialized"},
    {-2146107362, "Buffer too small"},
    {-2146107318, "Exception"},
    {-2146107272, "Invalid flags"},
    {-2146107262, "Invalid object"},
    {-2146107257, "Invalid player"},
    {-2146107247, "Invalid group"},
    {-2146107242, "Invalid handle"},
    {-2146107092, "Session lost"},
    {-2146107090, "No voice session"},
    {-2146107032, "Connection lost"},
    {-2146107031, "Not initialized"},
    {-2146107030, "Connected"},
    {-2146107029, "Not connected"},
    {-2146107026, "Connect aborting"},
    {-2146107025, "Not allowed"},
    {-2146107024, "Invalid target"},
    {-2146107023, "Transport not host"},
    {-2146107022, "Compression not supported"},
    {-2146107021, "Already pending"},
    {-2146107020, "Sound init failure"},
    {-2146107019, "Time out"},
    {-2146107018, "Connect aborted"},
    {-2146107017, "No 3d sound"},
    {-2146107016, "Already buffered"},
    {-2146107015, "Not buffered"},
    {-2146107014, "Hosting"},
    {-2146107013, "Not hosting"},
    {-2146107012, "Invalid device"},
    {-2146107011, "Record system error"},
    {-2146107010, "Playback system error"},
    {-2146107009, "Send error"},
    {-2146107008, "User cancel"},
    {-2146107005, "Run setup"},
    {-2146107004, "Incompatible version"},
    {-2146107001, "Initialized"},
    {-2146107000, "No transport"},
    {-2146106999, "No callback"},
    {-2146106998, "Transport not init"},
    {-2146106997, "Transport no session"},
    {-2146106996, "Transport no player"},
    {-2146106995, "User back"},
    {-2146106994, "No rec vol available"},
    {-2146106993, "Invalid buffer"},
    {-2146106992, "Locked buffer"},
    {-2146074576, "Aborted"},
    {-2146074560, "Addressing"},
    {-2146074544, "Already closing"},
    {-2146074528, "Already connected"},
    {-2146074512, "Already disconnecting"},
    {-2146074496, "Already initialized"},
    {-2146074480, "Already registered"},
    {-2146074368, "Buffer too small"},
    {-2146074352, "Can not cancel"},
    {-2146074336, "Cant create group"},
    {-2146074320, "Cant create player"},
    {-2146074304, "Cant launch application"},
    {-2146074288, "Connecting"},
    {-2146074272, "Connection lost"},
    {-2146074256, "Conversion"},
    {-2146074251, "Data too large"},
    {-2146074240, "Does not exist"},
    {-2146074235, "dpnsvr not available"},
    {-2146074224, "Duplicate command"},
    {-2146074112, "End point not receiving"},
    {-2146074096, "Enum query too large"},
    {-2146074080, "Enum response too large"},
    {-2146074064, "Exception"},
    {-2146074048, "Group not empty"},
    {-2146074032, "Hosting"},
    {-2146074016, "Host rejected connection"},
    {-2146074000, "Host terminated session"},
    {-2146073984, "Incomplete address"},
    {-2146073968, "Invalid address format"},
    {-2146073856, "Invalid application"},
    {-2146073840, "Invalid command"},
    {-2146073824, "Invalid device address"},
    {-2146073808, "Invalid end point"},
    {-2146073792, "Invalid flags"},
    {-2146073776, "Invalid group"},
    {-2146073760, "Invalid handle"},
    {-2146073744, "Invalid host address"},
    {-2146073728, "Invalid instance"},
    {-2146073712, "Invalid interface"},
    {-2146073600, "Invalid object"},
    {-2146073584, "Invalid password"},
    {-2146073568, "Invalid player"},
    {-2146073552, "Invalid priority"},
    {-2146073536, "Invalid string"},
    {-2146073520, "Invalid url"},
    {-2146073504, "Invalid version"},
    {-2146073488, "No caps"},
    {-2146073472, "No connection"},
    {-2146073456, "No host player"},
    {-2146073344, "No more address components"},
    {-2146073328, "No response"},
    {-2146073312, "Not allowed"},
    {-2146073296, "Not host"},
    {-2146073280, "Not ready"},
    {-2146073264, "Not registered"},
    {-2146073248, "Player already in group"},
    {-2146073232, "Player lost"},
    {-2146073216, "Player not in group"},
    {-2146073200, "Player not reachable"},
    {-2146073088, "Send too large"},
    {-2146073072, "Session full"},
    {-2146073056, "Table full"},
    {-2146073040, "Timed out"},
    {-2146073024, "Uninitialized"},
    {-2146073008, "User cancel"},
    {-2005532667, "This object is already initialized"},
    {-2005532662, "This surface can not be attached to the requested surface."},
    {-2005532652, "This surface can not be detached from the requested surface."},
    {-2005532632, "Support is currently not available."},
    {-2005532617, "An exception was encountered while performing the requested operation"},
    {-2005532582, "Height of rectangle provided is not a multiple of reqd alignment"},
    {-2005532577, "Unable to match primary surface creation request with existing primary surface."},
    {-2005532572, "One or more of the caps bits passed to the callback are incorrect."},
    {-2005532562, "DirectDraw does not support provided Cliplist."},
    {-2005532552, "DirectDraw does not support the requested mode"},
    {-2005532542, "DirectDraw received a pointer that was an invalid DIRECTDRAW object."},
    {-2005532527, "pixel format was invalid as specified"},
    {-2005532522, "Rectangle provided was invalid."},
    {-2005532512, "Operation could not be carried out because one or more surfaces are locked"},
    {-2005532502, "There is no 3D present."},
    {-2005532492, "Operation could not be carried out because there is no alpha accleration hardware present or available."},
    {-2005532491, "Operation could not be carried out because there is no stereo hardware present or available."},
    {-2005532490, "Operation could not be carried out because there is no hardware present which supports stereo surfaces"},
    {-2005532467, "no clip list available"},
    {-2005532462, "Operation could not be carried out because there is no color conversion hardware present or available."},
    {-2005532460, "Create function called without DirectDraw object method SetCooperativeLevel being called."},
    {-2005532457, "Surface doesn't currently have a color key"},
    {-2005532452, "Operation could not be carried out because there is no hardware support of the dest color key."},
    {-2005532450, "No DirectDraw support possible with current display driver"},
    {-2005532447, "Operation requires the application to have exclusive mode but the application does not have exclusive mode."},
    {-2005532442, "Flipping visible surfaces is not supported."},
    {-2005532432, "There is no GDI present."},
    {-2005532422, "Operation could not be carried out because there is no hardware present or available."},
    {-2005532417, "Requested item was not found"},
    {-2005532412, "Operation could not be carried out because there is no overlay hardware present or available."},
    {-2005532402, "Operation could not be carried out because the source and destination rectangles are on the same surface and overlap each other."},
    {-2005532392, "Operation could not be carried out because there is no appropriate raster op hardware present or available."},
    {-2005532382, "Operation could not be carried out because there is no rotation hardware present or available."},
    {-2005532362, "Operation could not be carried out because there is no hardware support for stretching"},
    {-2005532356, "DirectDrawSurface is not in 4 bit color palette and the requested operation requires 4 bit color palette."},
    {-2005532355, "DirectDrawSurface is not in 4 bit color index palette and the requested operation requires 4 bit color index palette."},
    {-2005532352, "DirectDraw Surface is not in 8 bit color mode and the requested operation requires 8 bit color."},
    {-2005532342, "Operation could not be carried out because there is no texture mapping hardware present or available."},
    {-2005532337, "Operation could not be carried out because there is no hardware support for vertical blank synchronized operations."},
    {-2005532332, "Operation could not be carried out because there is no hardware support for zbuffer blting."},
    {-2005532322, "Overlay surfaces could not be z layered based on their BltOrder because the hardware does not support z layering of overlays."},
    {-2005532312, "The hardware needed for the requested operation has already been allocated."},
    {-2005532292, "Out of video memory"},
    {-2005532290, "hardware does not support clipped overlays"},
    {-2005532288, "Can only have ony color key active at one time for overlays"},
    {-2005532285, "Access to this palette is being refused because the palette is already locked by another thread."},
    {-2005532272, "No src color key specified for this operation."},
    {-2005532262, "This surface is already attached to the surface it is being attached to."},
    {-2005532252, "This surface is already a dependency of the surface it is being made a dependency of."},
    {-2005532242, "Access to this surface is being refused because the surface is already locked by another thread."},
    {-2005532237, "Access to this surface is being refused because no driver exists which can supply a pointer to the surface. This is most likely to happen when attempting to lock the primary surface when no DCI provider is present. Will also happen on attempts to lock an optimized surface."},
    {-2005532232, "Access to Surface refused because Surface is obscured."},
    {-2005532222, "Access to this surface is being refused because the surface is gone. The DIRECTDRAWSURFACE object representing this surface should have Restore called on it."},
    {-2005532212, "The requested surface is not attached."},
    {-2005532202, "Height requested by DirectDraw is too large."},
    {-2005532192, "Size requested by DirectDraw is too large --  The individual height and width are OK."},
    {-2005532182, "Width requested by DirectDraw is too large."},
    {-2005532162, "Pixel format requested is unsupported by DirectDraw"},
    {-2005532152, "Bitmask in the pixel format requested is unsupported by DirectDraw"},
    {-2005532151, "The specified stream contains invalid data"},
    {-2005532135, "vertical blank is in progress"},
    {-2005532132, "Was still drawing"},
    {-2005532130, "The specified surface type requires specification of the COMPLEX flag"},
    {-2005532112, "Rectangle provided was not horizontally aligned on reqd. boundary"},
    {-2005532111, "The GUID passed to DirectDrawCreate is not a valid DirectDraw driver identifier."},
    {-2005532110, "A DirectDraw object representing this driver has already been created for this process."},
    {-2005532109, "A hardware only DirectDraw object creation was attempted but the driver did not support any hardware."},
    {-2005532108, "this process already has created a primary surface"},
    {-2005532107, "software emulation not available."},
    {-2005532106, "region passed to Clipper::GetClipList is too small."},
    {-2005532105, "an attempt was made to set a clip list for a clipper objec that is already monitoring an hwnd."},
    {-2005532104, "No clipper object attached to surface object"},
    {-2005532103, "Clipper notification requires an HWND or no HWND has previously been set as the CooperativeLevel HWND."},
    {-2005532102, "HWND used by DirectDraw CooperativeLevel has been subclassed, this prevents DirectDraw from restoring state."},
    {-2005532101, "The CooperativeLevel HWND has already been set. It can not be reset while the process has surfaces or palettes created."},
    {-2005532100, "No palette object attached to this surface."},
    {-2005532099, "No hardware support for 16 or 256 color palettes."},
    {-2005532098, "If a clipper object is attached to the source surface passed into a BltFast call."},
    {-2005532097, "No blter."},
    {-2005532096, "No DirectDraw ROP hardware."},
    {-2005532095, "returned when GetOverlayPosition is called on a hidden overlay"},
    {-2005532094, "returned when GetOverlayPosition is called on a overlay that UpdateOverlay has never been called on to establish a destionation."},
    {-2005532093, "returned when the position of the overlay on the destionation is no longer legal for that destionation."},
    {-2005532092, "returned when an overlay member is called for a non-overlay surface"},
    {-2005532091, "An attempt was made to set the cooperative level when it was already set to exclusive."},
    {-2005532090, "An attempt has been made to flip a surface that is not flippable."},
    {-2005532089, "Can't duplicate primary & 3D surfaces, or surfaces that are implicitly created."},
    {-2005532088, "Surface was not locked.  An attempt to unlock a surface that was not locked at all, or by this process, has been attempted."},
    {-2005532087, "Windows can not create any more DCs, or a DC was requested for a paltte-indexed surface when the surface had no palette AND the display mode was not palette-indexed (in this case DirectDraw cannot select a proper palette into the DC)"},
    {-2005532086, "No DC was ever created for this surface."},
    {-2005532085, "This surface can not be restored because it was created in a different mode."},
    {-2005532084, "This surface can not be restored because it is an implicitly created surface."},
    {-2005532083, "The surface being used is not a palette-based surface"},
    {-2005532082, "The display is currently in an unsupported mode"},
    {-2005532081, "Operation could not be carried out because there is no mip-map texture mapping hardware present or available."},
    {-2005532080, "The requested action could not be performed because the surface was of the wrong type."},
    {-2005532072, "Device does not support optimized surfaces, therefore no video memory optimized surfaces"},
    {-2005532071, "Surface is an optimized surface, but has not yet been allocated any memory"},
    {-2005532070, "Attempt was made to create or set a device window without first setting the focus window"},
    {-2005532069, "Attempt was made to set a palette on a mipmap sublevel"},
    {-2005532052, "A DC has already been returned for this surface. Only one DC can be retrieved per surface."},
    {-2005532042, "An attempt was made to allocate non-local video memory from a device that does not support non-local video memory."},
    {-2005532032, "The attempt to page lock a surface failed."},
    {-2005532012, "The attempt to page unlock a surface failed."},
    {-2005531992, "An attempt was made to page unlock a surface with no outstanding page locks."},
    {-2005531982, "There is more data available than the specified buffer size could hold"},
    {-2005531981, "The data has expired and is therefore no longer valid."},
    {-2005531980, "The mode test has finished executing."},
    {-2005531979, "The mode test has switched to a new mode."},
    {-2005531978, "D3D has not yet been initialized."},
    {-2005531977, "The video port is not active"},
    {-2005531976, "The monitor does not have EDID data."},
    {-2005531975, "The driver does not enumerate display mode refresh rates."},
    {-2005531973, "Surfaces created by one direct draw device cannot be used directly by another direct draw device."},
    {-2005531804, "Bad array size"},
    {-2005531803, "Bad data reference"},
    {-2005531802, "Internal error"},
    {-2005531801, "No more objects"},
    {-2005531800, "Bad intrinsics"},
    {-2005531799, "No more stream handles"},
    {-2005531798, "No more data"},
    {-2005531796, "No internet"},
    {-2005531772, "Bad object"},
    {-2005531771, "Bad value"},
    {-2005531770, "Bad type"},
    {-2005531769, "Not found"},
    {-2005531768, "Not done yet"},
    {-2005531767, "File not found"},
    {-2005531766, "Resource not found"},
    {-2005531765, "Bad resource"},
    {-2005531764, "Bad file type"},
    {-2005531763, "Bad file version"},
    {-2005531762, "Bad file float size"},
    {-2005531761, "Bad file"},
    {-2005531760, "Parse error"},
    {-2005531759, "Bad array size"},
    {-2005531758, "Bad data reference"},
    {-2005531757, "No more objects"},
    {-2005531756, "No more data"},
    {-2005530600, "Wrong texture format"},
    {-2005530599, "Unsupported color operation"},
    {-2005530598, "Unsupported color arg"},
    {-2005530597, "Unsupported alpha operation"},
    {-2005530596, "Unsupported alpha arg"},
    {-2005530595, "Too many operations"},
    {-2005530594, "Conflicting texture filter"},
    {-2005530593, "Unsupported factor value"},
    {-2005530591, "Conflicting render state"},
    {-2005530590, "Unsupported texture filter"},
    {-2005530586, "Conflicting texture palette"},
    {-2005530585, "Driver internal error"},
    {-2005530522, "Not found"},
    {-2005530521, "More data"},
    {-2005530520, "Device lost"},
    {-2005530519, "Device not reset"},
    {-2005530518, "Not available"},
    {-2005530517, "Invalid device"},
    {-2005530516, "Invalid call"},
    {-2005530515, "Driver invalid call"},
    {-2005529772, "Can not modify index buffer"},
    {-2005529771, "Invalid mesh"},
    {-2005529770, "Cannot attr sort"},
    {-2005529769, "Skinning not supported"},
    {-2005529768, "Too many influences"},
    {-2005529767, "Invalid data"},
    {-2005529766, "Loaded mesh has no data"},
    {-2005529765, "Duplicate named fragment"},
    {-2005529764, "Can Not remove last item"},
    {-2005401590, "The call failed because resources (such as a priority level) were already being used by another caller"},
    {-2005401570, "The control (vol, pan, etc.) requested by the caller is not available"},
    {-2005401550, "This call is not valid for the current state of this object"},
    {-2005401530, "The caller does not have the priority level required for the function to succeed"},
    {-2005401500, "The specified WAVE format is not supported"},
    {-2005401480, "No sound driver is available for use"},
    {-2005401470, "This object is already initialized"},
    {-2005401450, "The buffer memory has been lost, and must be restored"},
    {-2005401440, "Another app has a higher priority level, preventing this call from succeeding"},
    {-2005401430, "This object has not been initialized"},
    {-2005401420, "Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds"},
    {-2005401410, "Attempt to use DirectSound 8 functionality on an older DirectSound object"},
    {-2005401400, "A circular loop of send effects was detected"},
    {-2005401390, "The GUID specified in an audiopath file does not match a valid MIXIN buffer"},
    {-2005397247, "An unexpected error was returned from a device driver, indicating possible failure of the driver or hardware."},
    {-2005397246, "The requested operation cannot be performed while there are  instantiated ports in any process in the system."},
    {-2005397245, "The requested device is already in use (possibly by a non-DirectMusic client) and cannot be opened again."},
    {-2005397244, "Buffer is not large enough for requested operation."},
    {-2005397243, "No buffer was prepared for the download data."},
    {-2005397242, "Download failed due to inability to access or create download buffer."},
    {-2005397240, "Error parsing DLS collection. File is corrupt."},
    {-2005397239, "Wave chunks in DLS collection file are at incorrect offsets."},
    {-2005397231, "Second attempt to load a DLS collection that is currently open. "},
    {-2005397229, "Error reading wave data from DLS collection. Indicates bad file."},
    {-2005397228, "There is no instrument in the collection that matches patch number."},
    {-2005397227, "The IStream* doesn't support Seek()."},
    {-2005397226, "The IStream* doesn't support Write()."},
    {-2005397225, "The RIFF parser doesn't contain a required chunk while parsing file."},
    {-2005397223, "Invalid download id was used in the process of creating a download buffer."},
    {-2005397216, "Tried to unload an object that was not downloaded or previously unloaded."},
    {-2005397215, "Buffer was already downloaded to synth."},
    {-2005397214, "The specified property item was not recognized by the target object."},
    {-2005397213, "The specified property item may not be set on the target object."},
    {-2005397212, "* The specified property item may not be retrieved from the target object."},
    {-2005397211, "Wave chunk has more than one interleaved channel. DLS format requires MONO."},
    {-2005397210, "Invalid articulation chunk in DLS collection."},
    {-2005397209, "Invalid instrument chunk in DLS collection."},
    {-2005397208, "Wavelink chunk in DLS collection points to invalid wave."},
    {-2005397207, "Articulation missing from instrument in DLS collection."},
    {-2005397206, "Downoaded DLS wave is not in PCM format. "},
    {-2005397205, "Bad wave chunk in DLS collection"},
    {-2005397204, "Offset Table for download buffer has errors. "},
    {-2005397203, "Attempted to download unknown data type."},
    {-2005397202, "The operation could not be completed because no sink was connected to the synthesizer."},
    {-2005397201, "An attempt was made to open the software synthesizer while it was already  open."},
    {-2005397200, "An attempt was made to close the software synthesizer while it was already  open."},
    {-2005397199, "The operation could not be completed because the software synth has not  yet been fully configured."},
    {-2005397198, "The operation cannot be carried out while the synthesizer is active."},
    {-2005397197, "An error occurred while attempting to read from the IStream* object."},
    {-2005397196, "The operation cannot be performed because the final instance of the DirectMusic object was released. Ports cannot be used after final  release of the DirectMusic object."},
    {-2005397195, "There was no data in the referenced buffer."},
    {-2005397194, "There is insufficient space to insert the given event into the buffer."},
    {-2005397193, "The given operation could not be carried out because the port is a capture port."},
    {-2005397192, "The given operation could not be carried out because the port is a render port."},
    {-2005397191, "The port could not be created because no DirectSound has been specified. Specify a DirectSound interface via the IDirectMusic::SetDirectSound method; pass NULL to have DirectMusic manage usage of DirectSound."},
    {-2005397190, "The operation cannot be carried out while the port is active."},
    {-2005397189, "Invalid DirectSound buffer was handed to port. "},
    {-2005397188, "Invalid buffer format was handed to the synth sink."},
    {-2005397187, "The operation cannot be carried out while the synthesizer is inactive."},
    {-2005397186, "IDirectMusic::SetDirectSound has already been called. It may not be changed while in use."},
    {-2005397185, "The given event is invalid (either it is not a valid MIDI message or it makes use of running status). The event cannot be packed into the buffer."},
    {-2005397168, "The IStream* object does not contain data supported by the loading object."},
    {-2005397167, "The object has already been initialized."},
    {-2005397166, "The file does not contain a valid band."},
    {-2005397163, "The IStream* object's data does not have a track header as the first chunk, and therefore can not be read by the segment object."},
    {-2005397162, "The IStream* object's data does not have a tool header as the first chunk, and therefore can not be read by the graph object."},
    {-2005397161, "The IStream* object's data contains an invalid track header (ckid is 0 and fccType is NULL,) and therefore can not be read by the segment object."},
    {-2005397160, "The IStream* object's data contains an invalid tool header (ckid is 0 and fccType is NULL,) and therefore can not be read by the graph object."},
    {-2005397159, "The graph object was unable to load all tools from the IStream* object data. This may be due to errors in the stream, or the tools being incorrectly registered on the client."},
    {-2005397152, "The segment object was unable to load all tracks from the IStream* object data. This may be due to errors in the stream, or the tracks being incorrectly registered on the client."},
    {-2005397151, "The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)"},
    {-2005397150, "A required object is not initialized or failed to initialize."},
    {-2005397149, "The requested parameter type is currently disabled. Parameter types may be enabled and disabled by certain calls to SetParam()."},
    {-2005397148, "The requested parameter type is not supported on the object."},
    {-2005397147, "The time is in the past, and the operation can not succeed."},
    {-2005397146, "The requested track is not contained by the segment."},
    {-2005397145, "The track does not support clock time playback or getparam."},
    {-2005397136, "There is no master clock in the performance. Be sure to call IDirectMusicPerformance::Init()."},
    {-2005397120, "The class id field is required and missing in the DMUS_OBJECTDESC."},
    {-2005397119, "The requested file path is invalid."},
    {-2005397118, "File open failed - either file doesn't exist or is locked."},
    {-2005397117, "Search data type is not supported."},
    {-2005397116, "Unable to find or create object."},
    {-2005397115, "Object was not found."},
    {-2005397114, "The file name is missing from the DMUS_OBJECTDESC."},
    {-2005396992, "The file requested is not a valid file."},
    {-2005396991, "The tool is already contained in the graph. Create a new instance."},
    {-2005396990, "Value is out of range, for instance the requested length is longer than the segment."},
    {-2005396989, "Segment initialization failed, most likely due to a critical memory situation."},
    {-2005396988, "The DMUS_PMSG has already been sent to the performance object via IDirectMusicPerformance::SendPMsg()."},
    {-2005396987, "The DMUS_PMSG was either not allocated by the performance via IDirectMusicPerformance::AllocPMsg(), or it was already freed via IDirectMusicPerformance::FreePMsg()."},
    {-2005396986, "The default system port could not be opened."},
    {-2005396985, "A call to MIDIToMusic() or MusicToMIDI() resulted in an error because the requested conversion could not happen. This usually occurs when the provided DMUS_CHORD_KEY structure has an invalid chord or scale pattern."},
    {-2005396976, "DMUS_E_DESCEND_CHUNK_FAIL is returned when the end of the file  was reached before the desired chunk was found."},
    {-2005396975, "An attempt to use this object failed because it first needs to be loaded."},
    {-2005396973, "The activeX scripting engine for the script's language is not compatible with DirectMusic."},
    {-2005396972, "A varient was used that had a type that is not supported by DirectMusic."},
    {-2005396971, "An error was encountered while parsing or executing the script. The pErrorInfo parameter (if supplied) was filled with information about the error."},
    {-2005396970, "Loading of oleaut32.dll failed.  VBScript and other activeX scripting languages require use of oleaut32.dll.  On platforms where oleaut32.dll is not present, only the DirectMusicScript language, which doesn't require oleaut32.dll can be used."},
    {-2005396969, "An error occured while parsing a script loaded using LoadScript.  The script that was loaded contains an error."},
    {-2005396968, "The script file is invalid."},
    {-2005396967, "The file contains an invalid script track."},
    {-2005396966, "The script does not contain a variable with the specified name."},
    {-2005396965, "The script does not contain a routine with the specified name."},
    {-2005396964, "Scripts variables for content referenced or embedded in a script cannot be set."},
    {-2005396963, "Attempt was made to set a script's variable by reference to a value that was not an object type."},
    {-2005396962, "Attempt was made to set a script's variable by value to an object that does not support a default value property."},
    {-2005396960, "The file contains an invalid segment trigger track."},
    {-2005396959, "The file contains an invalid lyrics track."},
    {-2005396958, "The file contains an invalid parameter control track."},
    {-2005396957, "A script written in AudioVBScript could not be read because it contained a statement that is not allowed by the AudioVBScript language."},
    {-2005396956, "A script routine written in AudioVBScript failed because an invalid operation occurred.  For example, adding the number 3 to a segment object would produce this error.  So would attempting to call a routine that doesn't exist."},
    {-2005396955, "A script routine written in AudioVBScript failed because a function outside of a script failed to complete. For example, a call to PlaySegment that fails to play because of low memory would return this error."},
    {-2005396954, "The Performance has set up some PChannels using the AssignPChannel command, which makes it not capable of supporting audio paths."},
    {-2005396953, "This is the inverse of the previous error. The Performance has set up some audio paths, which makes is incompatible with the calls to allocate pchannels, etc. "},
    {-2005396952, "A segment or song was asked for its embedded audio path configuration, but there isn't any. "},
    {-2005396951, "An audiopath is inactive, perhaps because closedown was called."},
    {-2005396950, "An audiopath failed to create because a requested buffer could not be created."},
    {-2005396949, "An audiopath could not be used for playback because it lacked port assignments."},
    {-2005396948, "Attempt was made to play segment in audiopath mode and there was no audiopath."},
    {-2005396947, "Invalid data was found in a RIFF file chunk."},
    {-2005396946, "Attempt was made to create an audiopath that sends to a global effects buffer which did not exist."},
    {-2005396945, "The file does not contain a valid container object."},
    {-2005336063, "There are too many unique state objects."},
    {-2005270527, "The application has made an erroneous API call that it had enough information to avoid. This error is intended to denote that the application should be altered to avoid the error. Use of the debug version of the DXGI.DLL will provide run-time debug output with further information."},
    {-2005270526, "The item requested was not found. For GetPrivateData calls, this means that the specified GUID had not been previously associated with the object."},
    {-2005270525, "The specified size of the destination buffer is too small to hold the requested data."},
    {-2005270524, "Unsupported."},
    {-2005270523, "Device removed."},
    {-2005270522, "Device hung."},
    {-2005270521, "Device reset."},
    {-2005270518, "Was still drawing."},
    {-2005270496, "An internal driver error occurred."},
    {-2005270495, "The application attempted to perform an operation on an DXGI output that is only legal after the output has been claimed for exclusive owenership."},
    {-1966669823, "The engine is already initialized."},
    {-1966669822, "The engine has not been initialized."},
    {-1966669821, "The engine has expired (demo or pre-release version)."},
    {-1966669820, "No notification callback."},
    {-1966669819, "Notification already registered."},
    {-1966669818, "Invalid usage."},
    {-1966669817, "Invalid data."},
    {-1966669816, "Fail to play due to instance limit."},
    {-1966669815, "Global Settings not loaded."},
    {-1966669814, "Invalid variable index."},
    {-1966669813, "Invalid category."},
    {-1966669812, "Invalid cue index."},
    {-1966669811, "Invalid wave index."},
    {-1966669810, "Invalid track index."},
    {-1966669809, "Invalid sound offset or index."},
    {-1966669808, "Error reading a file."},
    {-1966669807, "Unknown event type."},
    {-1966669806, "Invalid call of method of function from callback."},
    {-1966669805, "No wavebank exists for desired operation."},
    {-1966669804, "Unable to select a variation."},
    {-1966669803, "There can be only one audition engine."},
    {-1966669802, "The wavebank is not prepared."},
    {-1966669567, "Error writing a file during auditioning."},
    {-1966669566, "Missing a soundbank."},
    {-1966669565, "Missing an RPC curve."},
    {-1966669564, "Missing data for an audition command."},
    {-1966669563, "Unknown command."},
    {-1966669562, "Missing a DSP parameter."},
    {-931722312, "Out of memory"},
    {-931722311, "A NULL pointer was passed as a parameter"},
    {-931722310, "The Device Index passed in is invalid"},
    {-931722309, "DirectDraw has not been created"},
    {-931722308, "Direct3D has not been created"},
    {-931722307, "Direct3D device has not been created"},
    {-931722306, "Primary surface has not been created"},
    {-931722305, "Z buffer has not been created"},
    {-931722304, "Backbuffer has not been created"},
    {-931722303, "Failed to update caps database after changing display mode"},
    {-931722302, "Could not create Z buffer"},
    {-931722301, "Display mode is not valid"},
    {-931722300, "One or more of the parameters passed is invalid"},
    {-931722299, "D3DX failed to initialize itself"},
    {-931722298, "D3DX failed to start up"},
    {-931722297, "D3DXInitialize() must be called first"},
    {-931722296, "D3DX is not initialized yet"},
    {-931722295, "Failed to render text to the surface"},
    {-931722294, "Bad D3DX context"},
    {-931722293, "The requested device capabilities are not supported"},
    {-931722292, "The image file format is unrecognized"},
    {-931722291, "The image file loading library error"},
    {-931722290, "Could not obtain device caps"},
    {-931722289, "Resize does not work for full-screen"},
    {-931722288, "Resize does not work for non-windowed contexts"},
    {-931722287, "Front buffer already exists"},
    {-931722286, "The app is using the primary in full-screen mode"},
    {-931722285, "Could not get device context"},
    {-931722284, "Could not bitBlt"},
    {-931722283, "There is no surface backing up this texture"},
    {-931722282, "There is no such miplevel for this surface"},
    {-931722281, "The surface is not paletted"},
    {-931722280, "An error occured while enumerating surface formats"},
    {-931722279, "D3DX only supports color depths of 16 bit or greater"},
    {-931722278, "The file format is invalid"},
    {-931722277, "No suitable match found"},
    {0, "The function completed successfully"},
    {1, "Call successful, but returned FALSE"},
    {2, "The system cannot find the file specified."},
    {3, "The system cannot find the path specified."},
    {4, "The system cannot open the file."},
    {5, "Access is denied."},
    {6, "The handle is invalid."},
    {8, "Not enough storage is available to process this command."},
    {9, "The storage control block address is invalid."},
    {10, "The environment is incorrect."},
    {11, "An attempt was made to load a program with an incorrect format."},
    {14, "The system cannot find the drive specified."},
    {262147, "End of stream. Sample not updated."},
    {262403, "The end of the list has been reached."},
    {262701, "An attempt to add a filter with a duplicate name succeeded with a modified name."},
    {262711, "The state transition has not completed."},
    {262722, "Some of the streams in this movie are in an unsupported format."},
    {262725, "The file contained some property settings that were not used."},
    {262726, "Some connections have failed and have been deferred."},
    {262736, "The resource specified is no longer needed."},
    {262740, "A connection could not be made with the media type in the persistent graph, but has been made with a negotiated media type."},
    {262743, "Cannot play back the video stream: no suitable decompressor could be found."},
    {262744, "Cannot play back the audio stream: no audio hardware is available."},
    {262746, "Cannot play back the video stream: format 'RPZA' is not supported."},
    {262752, "The value returned had to be estimated.  It's accuracy can not be guaranteed."},
    {262755, "This success code is reserved for internal purposes within ActiveMovie."},
    {262759, "The stream has been turned off."},
    {262760, "The graph can't be cued because of lack of or corrupt data."},
    {262768, "The stop time for the sample was not set."},
    {262782, "There was no preview pin available, so the capture pin output is being split to provide both capture and preview."},
    {262784, "The current title was not a sequential set of chapters (PGC), and the returned timing information might not be continuous."},
    {262796, "The audio stream did not contain sufficient information to determine the contents of each channel."},
    {262797, "The seek into the movie was not frame accurate."},
    {1376261, "Full duplex"},
    {1376266, "Half duplex"},
    {1376272, "Pending"},
    {141953135, "The call succeeded but there won't be any mipmaps generated"},
    {142082058, "The call succeeded, but we had to substitute the 3D algorithm"},
    {142086289, "The object could only load partially. This can happen if some components are not registered properly, such as embedded tracks and tools. This can also happen if some content is missing. For example, if a segment uses a DLS collection that is not in the loader's current search directory."},
    {142086290, "Return value from IDirectMusicBand::Download() which indicates that some of the instruments safely downloaded, but others failed. This usually occurs when some instruments are on PChannels not supported by the performance or port."},
    {142086656, "Return value from IDirectMusicTool::ProcessPMsg() which indicates to the performance that it should cue the PMsg again automatically."},
    {142086657, "Return value from IDirectMusicTool::ProcessPMsg() which indicates to the performance that it should free the PMsg automatically."},
    {142086658, "Return value from IDirectMusicTrack::Play() which indicates to the segment that the track has no more data after mtEnd."},
    {142086672, "Returned string has been truncated to fit the buffer size."},
    {142086673, "Returned from IDirectMusicGraph::StampPMsg(), this indicates that the PMsg is already stamped with the last tool in the graph. The returned PMsg's tool pointer is now NULL."},
    {142086674, "Returned from IDirectMusicPerformance::MusicToMIDI(), this indicates  that no note has been calculated because the music value has the note  at a position higher than the top note of the chord. This applies only to DMUS_PLAYMODE_NORMALCHORD play mode. This success code indicates that the caller should not do anything with the note. It is not meant to be played against this chord."},
    {142086675, "Returned from IDirectMusicPerformance::MIDIToMusic(),  and IDirectMusicPerformance::MusicToMIDI(), this indicates  that the note conversion generated a note value that is below 0,  so it has been bumped up one or more octaves to be in the proper MIDI range of 0 through 127.  Note that this is valid for MIDIToMusic() when using play modes DMUS_PLAYMODE_FIXEDTOCHORD and DMUS_PLAYMODE_FIXEDTOKEY, both of which store MIDI values in wMusicValue. With MusicToMIDI(), it is valid for all play modes. Ofcourse, DMUS_PLAYMODE_FIXED will never return this success code."},
    {142086676, "Returned from IDirectMusicPerformance::MIDIToMusic(),  and IDirectMusicPerformance::MusicToMIDI(), this indicates  that the note conversion generated a note value that is above 127, so it has been bumped down one or more octaves to be in the proper MIDI range of 0 through 127.  Note that this is valid for MIDIToMusic() when using play modes DMUS_PLAYMODE_FIXEDTOCHORD and DMUS_PLAYMODE_FIXEDTOKEY, both of which store MIDI values in wMusicValue. With MusicToMIDI(), it is valid for all play modes. Ofcourse, DMUS_PLAYMODE_FIXED will never return this success code."},
    {142086677, "Although the audio output from the port will be routed to the same device as the given DirectSound buffer, buffer controls such as pan and volume will not affect the output."},
    {142086678, "The requested operation was not performed because during CollectGarbage the loader determined that the object had been released."},
    {142213121, "The target window or output has been occluded. The application should suspend rendering operations if possible."},
}};
} // namespace

const char* error_description(std::int32_t result) {
    const auto found = std::lower_bound(kErrorDescriptions.begin(), kErrorDescriptions.end(), result, [](const ErrorDescription& entry, std::int32_t value) { return entry.result < value; });
    return found != kErrorDescriptions.end() && found->result == result ? found->text : "n/a";
}
} // namespace directx
namespace native_binding {
namespace {

template <typename Value>
Value decode_argument(const NativeArgument& argument) noexcept {
    using Plain = std::remove_cv_t<Value>;
    if constexpr (std::is_pointer_v<Plain>) { return reinterpret_cast<Plain>(static_cast<std::uintptr_t>(argument.word)); }
    else if constexpr (std::is_floating_point_v<Plain>) {
        if (argument.kind == NativeValueKind::floating) { return static_cast<Plain>(argument.floating); }
        if constexpr (sizeof(Plain) == 4u) { return std::bit_cast<float>(static_cast<std::uint32_t>(argument.word)); }
        else { return static_cast<Plain>(std::bit_cast<double>(argument.word)); }
    } else { return static_cast<Plain>(argument.word); }
}

template <typename Value>
NativeResult encode_result(Value value) noexcept {
    using Plain = std::remove_cv_t<Value>;
    if constexpr (std::is_pointer_v<Plain>) { return {reinterpret_cast<std::uintptr_t>(value), 0.0L, NativeValueKind::word, 4u}; }
    else if constexpr (std::is_floating_point_v<Plain>) {
        if constexpr (sizeof(Plain) == 4u) { return {std::bit_cast<std::uint32_t>(static_cast<float>(value)), static_cast<long double>(value), NativeValueKind::floating, 4u}; }
        else { return {std::bit_cast<std::uint64_t>(static_cast<double>(value)), static_cast<long double>(value), NativeValueKind::floating, 8u}; }
    } else { return {static_cast<std::uint64_t>(value), 0.0L, NativeValueKind::word, static_cast<std::uint8_t>(std::min<std::size_t>(sizeof(Plain), 8u))}; }
}

template <typename Value>
consteval NativeValueKind value_kind() noexcept {
    if constexpr (std::is_void_v<Value>) { return NativeValueKind::none; }
    return std::is_floating_point_v<std::remove_cv_t<Value>> ? NativeValueKind::floating : NativeValueKind::word;
}

template <typename Value>
consteval std::uint8_t abi_width() noexcept {
    using Plain = std::remove_cv_t<Value>;
    return std::is_pointer_v<Plain> ? 4u : static_cast<std::uint8_t>(sizeof(Plain));
}

template <NativeCallingConvention Convention, typename... Arguments>
consteval auto build_parameter_layout() {
    std::array<NativeParameter, sizeof...(Arguments)> result{};
    std::size_t index = 0;
    std::uint16_t stack_offset = 0;
    std::uint8_t register_index = 0;
    [[maybe_unused]] auto append = [&]<typename Argument>() {
        const std::uint8_t width = abi_width<Argument>();
        NativeParameterStorage storage = NativeParameterStorage::stack;
        if constexpr (Convention == NativeCallingConvention::thiscall_call) {
            if (index == 0u) { storage = NativeParameterStorage::ecx; }
        } else if constexpr (Convention == NativeCallingConvention::fastcall_call) {
            if (register_index < 2u && width <= 4u && value_kind<Argument>() == NativeValueKind::word) {
                storage = register_index == 0u ? NativeParameterStorage::ecx : NativeParameterStorage::edx;
                ++register_index;
            }
        }
        result[index] = {value_kind<Argument>(), storage, stack_offset, width};
        if (storage == NativeParameterStorage::stack) { stack_offset = static_cast<std::uint16_t>(stack_offset + ((width + 3u) & ~3u)); }
        ++index;
    };
    (append.template operator()<Arguments>(), ...);
    return result;
}

template <NativeCallingConvention Convention, auto Function>
struct TypedInvoker;

template <NativeCallingConvention Convention, auto Function, typename Result, typename... Arguments>
struct TypedInvokerImplementation {
    inline static constexpr auto parameters = build_parameter_layout<Convention, Arguments...>();
    inline static constexpr NativeValueKind result_kind = value_kind<Result>();
    inline static constexpr std::uint16_t stack_bytes = [] {
        std::uint16_t size = 0;
        for (const NativeParameter& parameter : parameters) {
            if (parameter.storage == NativeParameterStorage::stack) { size = std::max<std::uint16_t>(size, static_cast<std::uint16_t>(parameter.stack_offset + ((parameter.width + 3u) & ~3u))); }
        }
        return size;
    }();

    template <std::size_t... Indexes>
    static NativeResult call(const NativeArgument* arguments, std::index_sequence<Indexes...>) {
        if constexpr (std::is_void_v<Result>) {
            Function(decode_argument<Arguments>(arguments[Indexes])...);
            return {0u, 0.0L, NativeValueKind::none, 0u};
        } else { return encode_result(Function(decode_argument<Arguments>(arguments[Indexes])...)); }
    }

    static NativeResult invoke(const NativeArgument* arguments, std::size_t argument_count) {
        if (argument_count < sizeof...(Arguments)) { throw std::invalid_argument("Semantic call has too few arguments"); }
        return call(arguments, std::index_sequence_for<Arguments...>{});
    }
};

template <NativeCallingConvention Convention, typename Result, typename... Arguments, Result (*Function)(Arguments...)>
struct TypedInvoker<Convention, Function> : TypedInvokerImplementation<Convention, Function, Result, Arguments...> {};

template <std::uint32_t SourceVa, NativeCallingConvention Convention, auto Function>
consteval NativeEntry bind(const char* name, std::uint32_t source_lines) {
    using Invoker = TypedInvoker<Convention, Function>;
    return {SourceVa, Convention, Invoker::parameters.data(), static_cast<std::uint16_t>(Invoker::parameters.size()), Invoker::stack_bytes, Invoker::result_kind, &Invoker::invoke, name, source_lines};
}

struct AbiHint {
    std::uint32_t source_va;
    NativeCallingConvention convention;
};

} // namespace
} // namespace native_binding

namespace native_binding {
namespace {
constexpr std::array<NativeEntry, 98> kNativeEntries{{
    bind<0x00401000u, NativeCallingConvention::thiscall_call, &filename_component>("filename_component", 23u),
    bind<0x00401250u, NativeCallingConvention::thiscall_call, &build_box_corners>("build_box_corners", 107u),
    bind<0x004013B0u, NativeCallingConvention::thiscall_call, &construct_bit_slice>("construct_bit_slice", 11u),
    bind<0x004013D0u, NativeCallingConvention::fastcall_call, &copy_bits>("copy_bits", 110u),
    bind<0x00401500u, NativeCallingConvention::fastcall_call, &token_equals>("token_equals", 52u),
    bind<0x00401570u, NativeCallingConvention::thiscall_call, &copy_c_string>("copy_c_string", 13u),
    bind<0x00401590u, NativeCallingConvention::thiscall_call, &install_config_text>("install_config_text", 31u),
    bind<0x004015F0u, NativeCallingConvention::stdcall_call, &config_text_length>("config_text_length", 5u),
    bind<0x00401600u, NativeCallingConvention::stdcall_call, &find_config_value>("find_config_value", 0u),
    bind<0x00401680u, NativeCallingConvention::thiscall_call, &write_binary_file>("write_binary_file", 25u),
    bind<0x00401700u, NativeCallingConvention::thiscall_call, &reset_config_text>("reset_config_text", 16u),
    bind<0x00401730u, NativeCallingConvention::thiscall_call, &attach_config_text>("attach_config_text", 26u),
    bind<0x00401770u, NativeCallingConvention::stdcall_call, &read_config_int>("read_config_int", 17u),
    bind<0x004017A0u, NativeCallingConvention::stdcall_call, &read_config_float>("read_config_float", 17u),
    bind<0x004017D0u, NativeCallingConvention::stdcall_call, &read_config_string>("read_config_string", 52u),
    bind<0x00401840u, NativeCallingConvention::stdcall_call, &read_config_bits>("read_config_bits", 156u),
    bind<0x00401B70u, NativeCallingConvention::stdcall_call, &copy_config_text>("copy_config_text", 17u),
    bind<0x00401BE0u, NativeCallingConvention::cdecl_call, &compare_bytes>("compare_bytes", 53u),
    bind<0x00401D30u, NativeCallingConvention::thiscall_call, &equal_byte_views>("equal_byte_views", 86u),
    bind<0x00419F70u, NativeCallingConvention::fastcall_call, &transform_point>("transform_point", 56u),
    bind<0x0041E350u, NativeCallingConvention::stdcall_call, &is_model_file>("is_model_file", 45u),
    bind<0x0042F730u, NativeCallingConvention::fastcall_call, &world_runtime::inverse_transform_point>("world_runtime::inverse_transform_point", 59u),
    bind<0x004312C0u, NativeCallingConvention::fastcall_call, &shared_runtime::is_transport_mode>("shared_runtime::is_transport_mode", 12u),
    bind<0x00431850u, NativeCallingConvention::fastcall_call, &shared_runtime::wrapped_heading_delta>("shared_runtime::wrapped_heading_delta", 20u),
    bind<0x00433BB0u, NativeCallingConvention::fastcall_call, &shared_runtime::interop_storage_class>("shared_runtime::interop_storage_class", 13u),
    bind<0x00434080u, NativeCallingConvention::fastcall_call, &shared_runtime::wildcard_match>("shared_runtime::wildcard_match", 47u),
    bind<0x0044B5A0u, NativeCallingConvention::fastcall_call, &world_runtime::inverse_transform_in_place>("world_runtime::inverse_transform_in_place", 45u),
    bind<0x0044BB80u, NativeCallingConvention::fastcall_call, &world_runtime::quaternion_matrix>("world_runtime::quaternion_matrix", 79u),
    bind<0x0044C1D0u, NativeCallingConvention::fastcall_call, &world_runtime::cross_product>("world_runtime::cross_product", 26u),
    bind<0x0044CB00u, NativeCallingConvention::fastcall_call, &world_runtime::contains_substring>("world_runtime::contains_substring", 58u),
    bind<0x0044E400u, NativeCallingConvention::stdcall_call, &world_runtime::scaled_effect_time>("world_runtime::scaled_effect_time", 43u),
    bind<0x0044F800u, NativeCallingConvention::fastcall_call, &world_runtime::snap_near_zero>("world_runtime::snap_near_zero", 51u),
    bind<0x00451570u, NativeCallingConvention::fastcall_call, &world_runtime::grid_index>("world_runtime::grid_index", 7u),
    bind<0x00451A40u, NativeCallingConvention::stdcall_call, &world_runtime::intersect_plane_segment>("world_runtime::intersect_plane_segment", 89u),
    bind<0x004DD810u, NativeCallingConvention::cdecl_call, &zlib113::decompress>("zlib113::decompress", 76u),
    bind<0x004DD8E0u, NativeCallingConvention::cdecl_call, &zlib113::compress>("zlib113::compress", 73u),
    bind<0x004DD9D0u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflateReset>("zlib113::decompression::inflateReset", 41u),
    bind<0x004DDA3Bu, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflateEnd>("zlib113::decompression::inflateEnd", 45u),
    bind<0x004DDAA4u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflateInit2_>("zlib113::decompression::inflateInit2_", 123u),
    bind<0x004DDC0Au, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflateInit_>("zlib113::decompression::inflateInit_", 14u),
    bind<0x004DDC25u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate>("zlib113::decompression::inflate", 595u),
    bind<0x004DE540u, NativeCallingConvention::cdecl_call, &zlib113::compression::deflateInit_>("zlib113::compression::deflateInit_", 16u),
    bind<0x004DE565u, NativeCallingConvention::cdecl_call, &zlib113::compression::deflateInit2_>("zlib113::compression::deflateInit2_", 254u),
    bind<0x004DE9F1u, NativeCallingConvention::cdecl_call, &zlib113::compression::deflateReset>("zlib113::compression::deflateReset", 68u),
    bind<0x004DEBDEu, NativeCallingConvention::cdecl_call, &zlib113::compression::deflate>("zlib113::compression::deflate", 305u),
    bind<0x004DEF60u, NativeCallingConvention::cdecl_call, &zlib113::compression::putShortMSB>("zlib113::compression::putShortMSB", 30u),
    bind<0x004DEFB0u, NativeCallingConvention::cdecl_call, &zlib113::compression::flush_pending>("zlib113::compression::flush_pending", 75u),
    bind<0x004DF075u, NativeCallingConvention::cdecl_call, &zlib113::compression::deflateEnd>("zlib113::compression::deflateEnd", 112u),
    bind<0x004DF3D2u, NativeCallingConvention::cdecl_call, &zlib113::compression::lm_init>("zlib113::compression::lm_init", 67u),
    bind<0x004DF4C0u, NativeCallingConvention::cdecl_call, &zlib113::compression::deflate_stored>("zlib113::compression::deflate_stored", 212u),
    bind<0x004DF700u, NativeCallingConvention::cdecl_call, &zlib113::compression::fill_window>("zlib113::compression::fill_window", 206u),
    bind<0x004DF93Bu, NativeCallingConvention::cdecl_call, &zlib113::compression::read_buf>("zlib113::compression::read_buf", 65u),
    bind<0x004DF9D3u, NativeCallingConvention::cdecl_call, &zlib113::compression::deflate_fast>("zlib113::compression::deflate_fast", 435u),
    bind<0x004DFF2Au, NativeCallingConvention::cdecl_call, &zlib113::compression::longest_match>("zlib113::compression::longest_match", 298u),
    bind<0x004E0259u, NativeCallingConvention::cdecl_call, &zlib113::compression::deflate_slow>("zlib113::compression::deflate_slow", 554u),
    bind<0x004E0950u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_blocks_reset>("zlib113::decompression::inflate_blocks_reset", 71u),
    bind<0x004E0A07u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_blocks_new>("zlib113::decompression::inflate_blocks_new", 101u),
    bind<0x004E0AFFu, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_blocks>("zlib113::decompression::inflate_blocks", 1749u),
    bind<0x004E1E72u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_blocks_free>("zlib113::decompression::inflate_blocks_free", 43u),
    bind<0x004E1F20u, NativeCallingConvention::cdecl_call, &zlib113::adler32>("zlib113::adler32", 227u),
    bind<0x004E21BEu, NativeCallingConvention::cdecl_call, &zlib113::compression::zcalloc>("zlib113::compression::zcalloc", 20u),
    bind<0x004E21E7u, NativeCallingConvention::cdecl_call, &zlib113::compression::zcfree>("zlib113::compression::zcfree", 10u),
    bind<0x004E2200u, NativeCallingConvention::cdecl_call, &zlib113::compression::_tr_init>("zlib113::compression::_tr_init", 35u),
    bind<0x004E2296u, NativeCallingConvention::cdecl_call, &zlib113::compression::tr_static_init>("zlib113::compression::tr_static_init", 6u),
    bind<0x004E229Bu, NativeCallingConvention::cdecl_call, &zlib113::compression::init_block>("zlib113::compression::init_block", 60u),
    bind<0x004E2364u, NativeCallingConvention::cdecl_call, &zlib113::compression::_tr_stored_block>("zlib113::compression::_tr_stored_block", 94u),
    bind<0x004E24A3u, NativeCallingConvention::cdecl_call, &zlib113::compression::_tr_align>("zlib113::compression::_tr_align", 340u),
    bind<0x004E2992u, NativeCallingConvention::cdecl_call, &zlib113::compression::_tr_flush_block>("zlib113::compression::_tr_flush_block", 287u),
    bind<0x004E2D4Eu, NativeCallingConvention::cdecl_call, &zlib113::compression::build_tree>("zlib113::compression::build_tree", 280u),
    bind<0x004E30EEu, NativeCallingConvention::cdecl_call, &zlib113::compression::pqdownheap>("zlib113::compression::pqdownheap", 129u),
    bind<0x004E328Du, NativeCallingConvention::cdecl_call, &zlib113::compression::gen_bitlen>("zlib113::compression::gen_bitlen", 254u),
    bind<0x004E35C0u, NativeCallingConvention::cdecl_call, &zlib113::compression::gen_codes>("zlib113::compression::gen_codes", 73u),
    bind<0x004E3685u, NativeCallingConvention::cdecl_call, &zlib113::compression::build_bl_tree>("zlib113::compression::build_bl_tree", 65u),
    bind<0x004E373Cu, NativeCallingConvention::cdecl_call, &zlib113::compression::scan_tree>("zlib113::compression::scan_tree", 120u),
    bind<0x004E38D9u, NativeCallingConvention::cdecl_call, &zlib113::compression::send_all_trees>("zlib113::compression::send_all_trees", 363u),
    bind<0x004E3DFCu, NativeCallingConvention::cdecl_call, &zlib113::compression::send_tree>("zlib113::compression::send_tree", 753u),
    bind<0x004E4A02u, NativeCallingConvention::cdecl_call, &zlib113::compression::compress_block>("zlib113::compression::compress_block", 580u),
    bind<0x004E524Au, NativeCallingConvention::cdecl_call, &zlib113::compression::set_data_type>("zlib113::compression::set_data_type", 61u),
    bind<0x004E52FCu, NativeCallingConvention::cdecl_call, &zlib113::compression::bi_reverse>("zlib113::compression::bi_reverse", 28u),
    bind<0x004E533Du, NativeCallingConvention::cdecl_call, &zlib113::compression::bi_flush>("zlib113::compression::bi_flush", 69u),
    bind<0x004E5426u, NativeCallingConvention::cdecl_call, &zlib113::compression::bi_windup>("zlib113::compression::bi_windup", 59u),
    bind<0x004E54E2u, NativeCallingConvention::cdecl_call, &zlib113::compression::copy_block>("zlib113::compression::copy_block", 92u),
    bind<0x004E5600u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_codes_new>("zlib113::decompression::inflate_codes_new", 34u),
    bind<0x004E5655u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_codes>("zlib113::decompression::inflate_codes", 1217u),
    bind<0x004E63BDu, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_codes_free>("zlib113::decompression::inflate_codes_free", 15u),
    bind<0x004E63E0u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_trees_bits>("zlib113::decompression::inflate_trees_bits", 65u),
    bind<0x004E6488u, NativeCallingConvention::cdecl_call, &zlib113::decompression::huft_build>("zlib113::decompression::huft_build", 574u),
    bind<0x004E6D56u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_trees_dynamic>("zlib113::decompression::inflate_trees_dynamic", 139u),
    bind<0x004E6EDBu, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_trees_fixed>("zlib113::decompression::inflate_trees_fixed", 17u),
    bind<0x004E6F10u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_flush>("zlib113::decompression::inflate_flush", 177u),
    bind<0x004E70F0u, NativeCallingConvention::cdecl_call, &zlib113::decompression::inflate_fast>("zlib113::decompression::inflate_fast", 631u),
    bind<0x004E787Cu, NativeCallingConvention::cdecl_call, &directx::error_description>("directx::error_description", 3848u),
    bind<0x004EE804u, NativeCallingConvention::cdecl_call, &compiler_runtime::copy_memory>("compiler_runtime::copy_memory", 5u),
    bind<0x004EE80Au, NativeCallingConvention::cdecl_call, &compiler_runtime::fill_memory>("compiler_runtime::fill_memory", 5u),
    bind<0x004EEA40u, NativeCallingConvention::stdcall_call, &compiler_runtime::signed_divide>("compiler_runtime::signed_divide", 76u),
    bind<0x004EEC60u, NativeCallingConvention::stdcall_call, &compiler_runtime::signed_remainder>("compiler_runtime::signed_remainder", 82u),
    bind<0x004EED20u, NativeCallingConvention::stdcall_call, &compiler_runtime::multiply>("compiler_runtime::multiply", 22u),
    bind<0x004EED80u, NativeCallingConvention::stdcall_call, &compiler_runtime::unsigned_divide>("compiler_runtime::unsigned_divide", 48u),
}};

constexpr std::array<AbiHint, 4892> kAbiHints{{
    {0x00401000u, NativeCallingConvention::fastcall_call},
    {0x00401030u, NativeCallingConvention::fastcall_call},
    {0x004010F0u, NativeCallingConvention::fastcall_call},
    {0x00401120u, NativeCallingConvention::fastcall_call},
    {0x00401150u, NativeCallingConvention::fastcall_call},
    {0x00401250u, NativeCallingConvention::thiscall_call},
    {0x004013B0u, NativeCallingConvention::thiscall_call},
    {0x004013D0u, NativeCallingConvention::fastcall_call},
    {0x00401500u, NativeCallingConvention::fastcall_call},
    {0x00401570u, NativeCallingConvention::thiscall_call},
    {0x00401590u, NativeCallingConvention::thiscall_call},
    {0x004015F0u, NativeCallingConvention::cdecl_call},
    {0x00401680u, NativeCallingConvention::thiscall_call},
    {0x00401700u, NativeCallingConvention::thiscall_call},
    {0x00401730u, NativeCallingConvention::thiscall_call},
    {0x00401770u, NativeCallingConvention::cdecl_call},
    {0x004017A0u, NativeCallingConvention::cdecl_call},
    {0x004017D0u, NativeCallingConvention::cdecl_call},
    {0x00401840u, NativeCallingConvention::cdecl_call},
    {0x00401990u, NativeCallingConvention::thiscall_call},
    {0x00401AC0u, NativeCallingConvention::thiscall_call},
    {0x00401B70u, NativeCallingConvention::cdecl_call},
    {0x00401BA0u, NativeCallingConvention::fastcall_call},
    {0x00401BB0u, NativeCallingConvention::thiscall_call},
    {0x00401BE0u, NativeCallingConvention::cdecl_call},
    {0x00401C60u, NativeCallingConvention::thiscall_call},
    {0x00401C90u, NativeCallingConvention::thiscall_call},
    {0x00401CD0u, NativeCallingConvention::fastcall_call},
    {0x00401D30u, NativeCallingConvention::fastcall_call},
    {0x00401DF0u, NativeCallingConvention::cdecl_call},
    {0x00401E00u, NativeCallingConvention::cdecl_call},
    {0x00401E10u, NativeCallingConvention::cdecl_call},
    {0x00401E20u, NativeCallingConvention::cdecl_call},
    {0x00401E30u, NativeCallingConvention::cdecl_call},
    {0x00401E40u, NativeCallingConvention::fastcall_call},
    {0x00401E50u, NativeCallingConvention::fastcall_call},
    {0x00401F10u, NativeCallingConvention::fastcall_call},
    {0x00402040u, NativeCallingConvention::cdecl_call},
    {0x004020B0u, NativeCallingConvention::fastcall_call},
    {0x004020C0u, NativeCallingConvention::thiscall_call},
    {0x004020E0u, NativeCallingConvention::fastcall_call},
    {0x00402100u, NativeCallingConvention::fastcall_call},
    {0x00402120u, NativeCallingConvention::fastcall_call},
    {0x00402140u, NativeCallingConvention::fastcall_call},
    {0x004021A0u, NativeCallingConvention::fastcall_call},
    {0x00402200u, NativeCallingConvention::fastcall_call},
    {0x00402220u, NativeCallingConvention::fastcall_call},
    {0x00402270u, NativeCallingConvention::fastcall_call},
    {0x00402290u, NativeCallingConvention::fastcall_call},
    {0x004022B0u, NativeCallingConvention::fastcall_call},
    {0x004022D0u, NativeCallingConvention::fastcall_call},
    {0x00402320u, NativeCallingConvention::fastcall_call},
    {0x00402340u, NativeCallingConvention::fastcall_call},
    {0x00402360u, NativeCallingConvention::fastcall_call},
    {0x004023B0u, NativeCallingConvention::fastcall_call},
    {0x004023D0u, NativeCallingConvention::fastcall_call},
    {0x004023F0u, NativeCallingConvention::fastcall_call},
    {0x00402440u, NativeCallingConvention::fastcall_call},
    {0x00402460u, NativeCallingConvention::fastcall_call},
    {0x00402480u, NativeCallingConvention::fastcall_call},
    {0x004024D0u, NativeCallingConvention::fastcall_call},
    {0x00402540u, NativeCallingConvention::fastcall_call},
    {0x004025A0u, NativeCallingConvention::fastcall_call},
    {0x00402600u, NativeCallingConvention::fastcall_call},
    {0x00402660u, NativeCallingConvention::fastcall_call},
    {0x004026C0u, NativeCallingConvention::fastcall_call},
    {0x00402720u, NativeCallingConvention::fastcall_call},
    {0x004027A0u, NativeCallingConvention::thiscall_call},
    {0x00402810u, NativeCallingConvention::thiscall_call},
    {0x004028A0u, NativeCallingConvention::cdecl_call},
    {0x00402900u, NativeCallingConvention::thiscall_call},
    {0x00402930u, NativeCallingConvention::thiscall_call},
    {0x00402970u, NativeCallingConvention::thiscall_call},
    {0x004029A0u, NativeCallingConvention::thiscall_call},
    {0x004029E0u, NativeCallingConvention::thiscall_call},
    {0x00402A10u, NativeCallingConvention::thiscall_call},
    {0x00402A50u, NativeCallingConvention::thiscall_call},
    {0x00402AC0u, NativeCallingConvention::thiscall_call},
    {0x00402AF0u, NativeCallingConvention::fastcall_call},
    {0x00402B40u, NativeCallingConvention::cdecl_call},
    {0x00402BB0u, NativeCallingConvention::cdecl_call},
    {0x00402C10u, NativeCallingConvention::thiscall_call},
    {0x00402C60u, NativeCallingConvention::thiscall_call},
    {0x00402CF0u, NativeCallingConvention::fastcall_call},
    {0x00402D20u, NativeCallingConvention::fastcall_call},
    {0x00402DB0u, NativeCallingConvention::thiscall_call},
    {0x00402E00u, NativeCallingConvention::thiscall_call},
    {0x00402E60u, NativeCallingConvention::thiscall_call},
    {0x00402EC0u, NativeCallingConvention::thiscall_call},
    {0x00402F10u, NativeCallingConvention::thiscall_call},
    {0x00402F60u, NativeCallingConvention::thiscall_call},
    {0x00402FC0u, NativeCallingConvention::thiscall_call},
    {0x00403010u, NativeCallingConvention::thiscall_call},
    {0x00403070u, NativeCallingConvention::thiscall_call},
    {0x004030C0u, NativeCallingConvention::thiscall_call},
    {0x00403120u, NativeCallingConvention::fastcall_call},
    {0x00403150u, NativeCallingConvention::fastcall_call},
    {0x00403170u, NativeCallingConvention::cdecl_call},
    {0x004031C0u, NativeCallingConvention::fastcall_call},
    {0x00403230u, NativeCallingConvention::thiscall_call},
    {0x004032E4u, NativeCallingConvention::cdecl_call},
    {0x00403307u, NativeCallingConvention::cdecl_call},
    {0x0040336Cu, NativeCallingConvention::cdecl_call},
    {0x004033A0u, NativeCallingConvention::thiscall_call},
    {0x004033F0u, NativeCallingConvention::thiscall_call},
    {0x00403480u, NativeCallingConvention::thiscall_call},
    {0x004034C0u, NativeCallingConvention::thiscall_call},
    {0x00403500u, NativeCallingConvention::thiscall_call},
    {0x00403590u, NativeCallingConvention::thiscall_call},
    {0x00403620u, NativeCallingConvention::thiscall_call},
    {0x004036B0u, NativeCallingConvention::cdecl_call},
    {0x00403720u, NativeCallingConvention::cdecl_call},
    {0x004037A0u, NativeCallingConvention::thiscall_call},
    {0x004039D0u, NativeCallingConvention::thiscall_call},
    {0x00403A60u, NativeCallingConvention::thiscall_call},
    {0x00403AF0u, NativeCallingConvention::thiscall_call},
    {0x00403B80u, NativeCallingConvention::thiscall_call},
    {0x00403C10u, NativeCallingConvention::fastcall_call},
    {0x00403CA0u, NativeCallingConvention::thiscall_call},
    {0x00403D50u, NativeCallingConvention::thiscall_call},
    {0x00403D90u, NativeCallingConvention::thiscall_call},
    {0x00403DE0u, NativeCallingConvention::fastcall_call},
    {0x00403E10u, NativeCallingConvention::fastcall_call},
    {0x00403E60u, NativeCallingConvention::cdecl_call},
    {0x00403F00u, NativeCallingConvention::thiscall_call},
    {0x004040B0u, NativeCallingConvention::thiscall_call},
    {0x00404140u, NativeCallingConvention::thiscall_call},
    {0x00404180u, NativeCallingConvention::thiscall_call},
    {0x004041C0u, NativeCallingConvention::thiscall_call},
    {0x004041F0u, NativeCallingConvention::thiscall_call},
    {0x00404230u, NativeCallingConvention::fastcall_call},
    {0x00404270u, NativeCallingConvention::fastcall_call},
    {0x004042B0u, NativeCallingConvention::thiscall_call},
    {0x004042F0u, NativeCallingConvention::thiscall_call},
    {0x00404330u, NativeCallingConvention::thiscall_call},
    {0x00404370u, NativeCallingConvention::fastcall_call},
    {0x004043B0u, NativeCallingConvention::fastcall_call},
    {0x004043F0u, NativeCallingConvention::thiscall_call},
    {0x004044D0u, NativeCallingConvention::cdecl_call},
    {0x00404510u, NativeCallingConvention::thiscall_call},
    {0x00404750u, NativeCallingConvention::thiscall_call},
    {0x00404900u, NativeCallingConvention::thiscall_call},
    {0x00404990u, NativeCallingConvention::thiscall_call},
    {0x00404B40u, NativeCallingConvention::thiscall_call},
    {0x00404BD0u, NativeCallingConvention::thiscall_call},
    {0x00404D80u, NativeCallingConvention::thiscall_call},
    {0x00404E10u, NativeCallingConvention::thiscall_call},
    {0x00404EF0u, NativeCallingConvention::thiscall_call},
    {0x00404F80u, NativeCallingConvention::thiscall_call},
    {0x00405010u, NativeCallingConvention::fastcall_call},
    {0x00405050u, NativeCallingConvention::fastcall_call},
    {0x00405080u, NativeCallingConvention::fastcall_call},
    {0x004050B0u, NativeCallingConvention::cdecl_call},
    {0x00405120u, NativeCallingConvention::cdecl_call},
    {0x00405190u, NativeCallingConvention::cdecl_call},
    {0x00405210u, NativeCallingConvention::thiscall_call},
    {0x00405300u, NativeCallingConvention::thiscall_call},
    {0x00405340u, NativeCallingConvention::thiscall_call},
    {0x00405380u, NativeCallingConvention::thiscall_call},
    {0x004053C0u, NativeCallingConvention::thiscall_call},
    {0x00405400u, NativeCallingConvention::thiscall_call},
    {0x00405440u, NativeCallingConvention::thiscall_call},
    {0x004054B0u, NativeCallingConvention::thiscall_call},
    {0x004054F0u, NativeCallingConvention::thiscall_call},
    {0x00405580u, NativeCallingConvention::thiscall_call},
    {0x00405600u, NativeCallingConvention::thiscall_call},
    {0x00405630u, NativeCallingConvention::thiscall_call},
    {0x00405770u, NativeCallingConvention::fastcall_call},
    {0x00405800u, NativeCallingConvention::fastcall_call},
    {0x00405A00u, NativeCallingConvention::fastcall_call},
    {0x00405A80u, NativeCallingConvention::fastcall_call},
    {0x00405B00u, NativeCallingConvention::thiscall_call},
    {0x00405B50u, NativeCallingConvention::thiscall_call},
    {0x00405BB0u, NativeCallingConvention::thiscall_call},
    {0x00405C00u, NativeCallingConvention::thiscall_call},
    {0x00405C60u, NativeCallingConvention::thiscall_call},
    {0x00405CB0u, NativeCallingConvention::thiscall_call},
    {0x00405D10u, NativeCallingConvention::thiscall_call},
    {0x00405D60u, NativeCallingConvention::thiscall_call},
    {0x00405DC0u, NativeCallingConvention::thiscall_call},
    {0x00405E10u, NativeCallingConvention::thiscall_call},
    {0x00405E70u, NativeCallingConvention::fastcall_call},
    {0x00405EB0u, NativeCallingConvention::fastcall_call},
    {0x00405F10u, NativeCallingConvention::thiscall_call},
    {0x00405F60u, NativeCallingConvention::thiscall_call},
    {0x00405FC0u, NativeCallingConvention::fastcall_call},
    {0x00406000u, NativeCallingConvention::fastcall_call},
    {0x00406060u, NativeCallingConvention::thiscall_call},
    {0x004060D0u, NativeCallingConvention::thiscall_call},
    {0x00406140u, NativeCallingConvention::thiscall_call},
    {0x004061B0u, NativeCallingConvention::fastcall_call},
    {0x00406210u, NativeCallingConvention::fastcall_call},
    {0x00406340u, NativeCallingConvention::thiscall_call},
    {0x004063F0u, NativeCallingConvention::fastcall_call},
    {0x00406430u, NativeCallingConvention::thiscall_call},
    {0x00406590u, NativeCallingConvention::thiscall_call},
    {0x00406610u, NativeCallingConvention::thiscall_call},
    {0x00406690u, NativeCallingConvention::cdecl_call},
    {0x00406710u, NativeCallingConvention::cdecl_call},
    {0x00406790u, NativeCallingConvention::cdecl_call},
    {0x00406820u, NativeCallingConvention::thiscall_call},
    {0x00406920u, NativeCallingConvention::thiscall_call},
    {0x00406970u, NativeCallingConvention::thiscall_call},
    {0x004069C0u, NativeCallingConvention::thiscall_call},
    {0x00406A30u, NativeCallingConvention::thiscall_call},
    {0x00406A80u, NativeCallingConvention::thiscall_call},
    {0x00406AD0u, NativeCallingConvention::thiscall_call},
    {0x00406B20u, NativeCallingConvention::thiscall_call},
    {0x00406B70u, NativeCallingConvention::cdecl_call},
    {0x00406BA0u, NativeCallingConvention::thiscall_call},
    {0x00406C10u, NativeCallingConvention::thiscall_call},
    {0x00406C80u, NativeCallingConvention::thiscall_call},
    {0x00406CE0u, NativeCallingConvention::thiscall_call},
    {0x00406D20u, NativeCallingConvention::thiscall_call},
    {0x00406D60u, NativeCallingConvention::thiscall_call},
    {0x00406DA0u, NativeCallingConvention::thiscall_call},
    {0x00406DE0u, NativeCallingConvention::thiscall_call},
    {0x00406E30u, NativeCallingConvention::thiscall_call},
    {0x00406E90u, NativeCallingConvention::thiscall_call},
    {0x00406EE0u, NativeCallingConvention::thiscall_call},
    {0x00406F30u, NativeCallingConvention::thiscall_call},
    {0x00406F80u, NativeCallingConvention::thiscall_call},
    {0x00406FE0u, NativeCallingConvention::thiscall_call},
    {0x00407030u, NativeCallingConvention::thiscall_call},
    {0x00407090u, NativeCallingConvention::thiscall_call},
    {0x004070E0u, NativeCallingConvention::thiscall_call},
    {0x00407130u, NativeCallingConvention::thiscall_call},
    {0x00407180u, NativeCallingConvention::thiscall_call},
    {0x004071D0u, NativeCallingConvention::thiscall_call},
    {0x00407220u, NativeCallingConvention::thiscall_call},
    {0x00407270u, NativeCallingConvention::fastcall_call},
    {0x004072B0u, NativeCallingConvention::fastcall_call},
    {0x00407300u, NativeCallingConvention::fastcall_call},
    {0x00407340u, NativeCallingConvention::fastcall_call},
    {0x00407390u, NativeCallingConvention::thiscall_call},
    {0x004073E0u, NativeCallingConvention::thiscall_call},
    {0x00407430u, NativeCallingConvention::fastcall_call},
    {0x00407470u, NativeCallingConvention::fastcall_call},
    {0x004074C0u, NativeCallingConvention::fastcall_call},
    {0x00407500u, NativeCallingConvention::fastcall_call},
    {0x00407550u, NativeCallingConvention::thiscall_call},
    {0x00407610u, NativeCallingConvention::thiscall_call},
    {0x004076E0u, NativeCallingConvention::thiscall_call},
    {0x004077C0u, NativeCallingConvention::thiscall_call},
    {0x00407890u, NativeCallingConvention::thiscall_call},
    {0x004079E0u, NativeCallingConvention::thiscall_call},
    {0x00407BD0u, NativeCallingConvention::thiscall_call},
    {0x00407C80u, NativeCallingConvention::thiscall_call},
    {0x00408150u, NativeCallingConvention::thiscall_call},
    {0x004081B0u, NativeCallingConvention::thiscall_call},
    {0x004081F0u, NativeCallingConvention::thiscall_call},
    {0x00408230u, NativeCallingConvention::thiscall_call},
    {0x00408270u, NativeCallingConvention::thiscall_call},
    {0x004082E0u, NativeCallingConvention::thiscall_call},
    {0x0040842Bu, NativeCallingConvention::cdecl_call},
    {0x00408450u, NativeCallingConvention::thiscall_call},
    {0x004084D0u, NativeCallingConvention::thiscall_call},
    {0x00408510u, NativeCallingConvention::thiscall_call},
    {0x00408590u, NativeCallingConvention::thiscall_call},
    {0x00408610u, NativeCallingConvention::thiscall_call},
    {0x00408690u, NativeCallingConvention::thiscall_call},
    {0x004088E0u, NativeCallingConvention::thiscall_call},
    {0x00408970u, NativeCallingConvention::thiscall_call},
    {0x004089F0u, NativeCallingConvention::cdecl_call},
    {0x00408A50u, NativeCallingConvention::fastcall_call},
    {0x00408AB0u, NativeCallingConvention::thiscall_call},
    {0x00408D20u, NativeCallingConvention::thiscall_call},
    {0x00408D90u, NativeCallingConvention::thiscall_call},
    {0x00408ECEu, NativeCallingConvention::cdecl_call},
    {0x00408EDAu, NativeCallingConvention::cdecl_call},
    {0x00408FB0u, NativeCallingConvention::fastcall_call},
    {0x00408FF0u, NativeCallingConvention::thiscall_call},
    {0x004090F0u, NativeCallingConvention::thiscall_call},
    {0x00409130u, NativeCallingConvention::thiscall_call},
    {0x00409790u, NativeCallingConvention::thiscall_call},
    {0x004097F0u, NativeCallingConvention::cdecl_call},
    {0x00409850u, NativeCallingConvention::thiscall_call},
    {0x00409AC0u, NativeCallingConvention::thiscall_call},
    {0x00409C90u, NativeCallingConvention::thiscall_call},
    {0x00409CD0u, NativeCallingConvention::thiscall_call},
    {0x00409D10u, NativeCallingConvention::thiscall_call},
    {0x00409D50u, NativeCallingConvention::thiscall_call},
    {0x00409D90u, NativeCallingConvention::thiscall_call},
    {0x00409DD0u, NativeCallingConvention::thiscall_call},
    {0x00409E10u, NativeCallingConvention::thiscall_call},
    {0x00409E50u, NativeCallingConvention::thiscall_call},
    {0x00409E90u, NativeCallingConvention::thiscall_call},
    {0x00409ED0u, NativeCallingConvention::thiscall_call},
    {0x00409F10u, NativeCallingConvention::thiscall_call},
    {0x00409F50u, NativeCallingConvention::thiscall_call},
    {0x00409F90u, NativeCallingConvention::thiscall_call},
    {0x0040A060u, NativeCallingConvention::fastcall_call},
    {0x0040A0C0u, NativeCallingConvention::fastcall_call},
    {0x0040A180u, NativeCallingConvention::thiscall_call},
    {0x0040A220u, NativeCallingConvention::thiscall_call},
    {0x0040A270u, NativeCallingConvention::fastcall_call},
    {0x0040A310u, NativeCallingConvention::thiscall_call},
    {0x0040A470u, NativeCallingConvention::cdecl_call},
    {0x0040A500u, NativeCallingConvention::fastcall_call},
    {0x0040A550u, NativeCallingConvention::thiscall_call},
    {0x0040A590u, NativeCallingConvention::thiscall_call},
    {0x0040A5E0u, NativeCallingConvention::thiscall_call},
    {0x0040A680u, NativeCallingConvention::thiscall_call},
    {0x0040A6F0u, NativeCallingConvention::thiscall_call},
    {0x0040A780u, NativeCallingConvention::thiscall_call},
    {0x0040A7A0u, NativeCallingConvention::thiscall_call},
    {0x0040AB60u, NativeCallingConvention::fastcall_call},
    {0x0040AB90u, NativeCallingConvention::thiscall_call},
    {0x0040AC20u, NativeCallingConvention::thiscall_call},
    {0x0040ACE0u, NativeCallingConvention::fastcall_call},
    {0x0040AD30u, NativeCallingConvention::fastcall_call},
    {0x0040ADC0u, NativeCallingConvention::thiscall_call},
    {0x0040B010u, NativeCallingConvention::thiscall_call},
    {0x0040B260u, NativeCallingConvention::thiscall_call},
    {0x0040B4D0u, NativeCallingConvention::thiscall_call},
    {0x0040B700u, NativeCallingConvention::thiscall_call},
    {0x0040B760u, NativeCallingConvention::thiscall_call},
    {0x0040B7A0u, NativeCallingConvention::fastcall_call},
    {0x0040B7D0u, NativeCallingConvention::thiscall_call},
    {0x0040B810u, NativeCallingConvention::thiscall_call},
    {0x0040B850u, NativeCallingConvention::thiscall_call},
    {0x0040B940u, NativeCallingConvention::cdecl_call},
    {0x0040B9A0u, NativeCallingConvention::cdecl_call},
    {0x0040BA00u, NativeCallingConvention::cdecl_call},
    {0x0040BA80u, NativeCallingConvention::cdecl_call},
    {0x0040BB40u, NativeCallingConvention::fastcall_call},
    {0x0040BBA0u, NativeCallingConvention::fastcall_call},
    {0x0040BC20u, NativeCallingConvention::fastcall_call},
    {0x0040BCE0u, NativeCallingConvention::thiscall_call},
    {0x0040BF50u, NativeCallingConvention::thiscall_call},
    {0x0040C1C0u, NativeCallingConvention::thiscall_call},
    {0x0040C440u, NativeCallingConvention::thiscall_call},
    {0x0040C700u, NativeCallingConvention::thiscall_call},
    {0x0040C770u, NativeCallingConvention::thiscall_call},
    {0x0040C7F0u, NativeCallingConvention::thiscall_call},
    {0x0040C840u, NativeCallingConvention::thiscall_call},
    {0x0040C8D6u, NativeCallingConvention::cdecl_call},
    {0x0040C920u, NativeCallingConvention::cdecl_call},
    {0x0040C9AAu, NativeCallingConvention::cdecl_call},
    {0x0040C9F0u, NativeCallingConvention::thiscall_call},
    {0x0040CBC0u, NativeCallingConvention::thiscall_call},
    {0x0040CCC0u, NativeCallingConvention::thiscall_call},
    {0x0040CE70u, NativeCallingConvention::thiscall_call},
    {0x0040D020u, NativeCallingConvention::fastcall_call},
    {0x0040D250u, NativeCallingConvention::thiscall_call},
    {0x0040D330u, NativeCallingConvention::thiscall_call},
    {0x0040D3B0u, NativeCallingConvention::cdecl_call},
    {0x0040D400u, NativeCallingConvention::thiscall_call},
    {0x0040D4D0u, NativeCallingConvention::thiscall_call},
    {0x0040D5A0u, NativeCallingConvention::thiscall_call},
    {0x0040D670u, NativeCallingConvention::thiscall_call},
    {0x0040D740u, NativeCallingConvention::fastcall_call},
    {0x0040D7C0u, NativeCallingConvention::thiscall_call},
    {0x0040D820u, NativeCallingConvention::thiscall_call},
    {0x0040D8C0u, NativeCallingConvention::thiscall_call},
    {0x0040D950u, NativeCallingConvention::thiscall_call},
    {0x0040D9D0u, NativeCallingConvention::thiscall_call},
    {0x0040DB90u, NativeCallingConvention::thiscall_call},
    {0x0040DCF0u, NativeCallingConvention::thiscall_call},
    {0x0040DEB0u, NativeCallingConvention::thiscall_call},
    {0x0040E070u, NativeCallingConvention::fastcall_call},
    {0x0040E120u, NativeCallingConvention::fastcall_call},
    {0x0040E1D0u, NativeCallingConvention::fastcall_call},
    {0x0040E280u, NativeCallingConvention::fastcall_call},
    {0x0040E330u, NativeCallingConvention::fastcall_call},
    {0x0040E3E0u, NativeCallingConvention::fastcall_call},
    {0x0040E490u, NativeCallingConvention::fastcall_call},
    {0x0040E540u, NativeCallingConvention::fastcall_call},
    {0x0040E5F0u, NativeCallingConvention::fastcall_call},
    {0x0040E6A0u, NativeCallingConvention::cdecl_call},
    {0x0040E860u, NativeCallingConvention::fastcall_call},
    {0x0040E890u, NativeCallingConvention::fastcall_call},
    {0x0040E8C0u, NativeCallingConvention::fastcall_call},
    {0x0040E8F0u, NativeCallingConvention::fastcall_call},
    {0x0040E920u, NativeCallingConvention::fastcall_call},
    {0x0040E960u, NativeCallingConvention::thiscall_call},
    {0x0040EAA0u, NativeCallingConvention::thiscall_call},
    {0x0040EB10u, NativeCallingConvention::thiscall_call},
    {0x0040EB70u, NativeCallingConvention::thiscall_call},
    {0x0040EBE0u, NativeCallingConvention::thiscall_call},
    {0x0040ED40u, NativeCallingConvention::thiscall_call},
    {0x0040EDB0u, NativeCallingConvention::thiscall_call},
    {0x0040EE20u, NativeCallingConvention::thiscall_call},
    {0x0040EE90u, NativeCallingConvention::thiscall_call},
    {0x0040EF20u, NativeCallingConvention::thiscall_call},
    {0x0040F040u, NativeCallingConvention::thiscall_call},
    {0x0040F180u, NativeCallingConvention::thiscall_call},
    {0x0040F300u, NativeCallingConvention::thiscall_call},
    {0x0040F420u, NativeCallingConvention::thiscall_call},
    {0x0040F5A0u, NativeCallingConvention::thiscall_call},
    {0x0040F6E0u, NativeCallingConvention::thiscall_call},
    {0x0040F800u, NativeCallingConvention::thiscall_call},
    {0x0040F980u, NativeCallingConvention::thiscall_call},
    {0x0040FAC0u, NativeCallingConvention::thiscall_call},
    {0x0040FB10u, NativeCallingConvention::thiscall_call},
    {0x0040FB60u, NativeCallingConvention::thiscall_call},
    {0x0040FBB0u, NativeCallingConvention::thiscall_call},
    {0x0040FC00u, NativeCallingConvention::thiscall_call},
    {0x0040FC50u, NativeCallingConvention::thiscall_call},
    {0x0040FCA0u, NativeCallingConvention::thiscall_call},
    {0x0040FCF0u, NativeCallingConvention::thiscall_call},
    {0x0040FD40u, NativeCallingConvention::thiscall_call},
    {0x0040FD90u, NativeCallingConvention::cdecl_call},
    {0x0040FE22u, NativeCallingConvention::cdecl_call},
    {0x0040FE60u, NativeCallingConvention::cdecl_call},
    {0x0040FEF2u, NativeCallingConvention::cdecl_call},
    {0x0040FF30u, NativeCallingConvention::cdecl_call},
    {0x0040FFC4u, NativeCallingConvention::cdecl_call},
    {0x00410000u, NativeCallingConvention::cdecl_call},
    {0x004100B1u, NativeCallingConvention::cdecl_call},
    {0x004100F0u, NativeCallingConvention::cdecl_call},
    {0x00410190u, NativeCallingConvention::cdecl_call},
    {0x00410390u, NativeCallingConvention::thiscall_call},
    {0x004103E0u, NativeCallingConvention::thiscall_call},
    {0x0041052Eu, NativeCallingConvention::cdecl_call},
    {0x00410550u, NativeCallingConvention::thiscall_call},
    {0x00410590u, NativeCallingConvention::thiscall_call},
    {0x004105D0u, NativeCallingConvention::thiscall_call},
    {0x00410610u, NativeCallingConvention::thiscall_call},
    {0x00410650u, NativeCallingConvention::fastcall_call},
    {0x004106A0u, NativeCallingConvention::thiscall_call},
    {0x00410710u, NativeCallingConvention::thiscall_call},
    {0x00410770u, NativeCallingConvention::thiscall_call},
    {0x004107D0u, NativeCallingConvention::thiscall_call},
    {0x00410830u, NativeCallingConvention::thiscall_call},
    {0x00410890u, NativeCallingConvention::thiscall_call},
    {0x004108F0u, NativeCallingConvention::thiscall_call},
    {0x00410950u, NativeCallingConvention::thiscall_call},
    {0x004109EEu, NativeCallingConvention::cdecl_call},
    {0x00410A30u, NativeCallingConvention::thiscall_call},
    {0x00410ACEu, NativeCallingConvention::cdecl_call},
    {0x00410B10u, NativeCallingConvention::thiscall_call},
    {0x00410BB0u, NativeCallingConvention::cdecl_call},
    {0x00410BF0u, NativeCallingConvention::thiscall_call},
    {0x00410CABu, NativeCallingConvention::cdecl_call},
    {0x00410CF0u, NativeCallingConvention::thiscall_call},
    {0x00410D9Cu, NativeCallingConvention::cdecl_call},
    {0x00410DE0u, NativeCallingConvention::cdecl_call},
    {0x00410E83u, NativeCallingConvention::cdecl_call},
    {0x00411060u, NativeCallingConvention::thiscall_call},
    {0x004110F0u, NativeCallingConvention::thiscall_call},
    {0x00411140u, NativeCallingConvention::thiscall_call},
    {0x00411190u, NativeCallingConvention::thiscall_call},
    {0x004111E0u, NativeCallingConvention::thiscall_call},
    {0x00411230u, NativeCallingConvention::thiscall_call},
    {0x00411280u, NativeCallingConvention::thiscall_call},
    {0x004112D0u, NativeCallingConvention::thiscall_call},
    {0x00411320u, NativeCallingConvention::thiscall_call},
    {0x00411370u, NativeCallingConvention::thiscall_call},
    {0x00411450u, NativeCallingConvention::thiscall_call},
    {0x00411520u, NativeCallingConvention::thiscall_call},
    {0x004115F0u, NativeCallingConvention::thiscall_call},
    {0x004116F0u, NativeCallingConvention::thiscall_call},
    {0x004117C0u, NativeCallingConvention::thiscall_call},
    {0x00411820u, NativeCallingConvention::thiscall_call},
    {0x00411890u, NativeCallingConvention::thiscall_call},
    {0x004118E0u, NativeCallingConvention::cdecl_call},
    {0x00411930u, NativeCallingConvention::cdecl_call},
    {0x00411980u, NativeCallingConvention::thiscall_call},
    {0x00411A70u, NativeCallingConvention::thiscall_call},
    {0x00411B60u, NativeCallingConvention::thiscall_call},
    {0x00411C90u, NativeCallingConvention::thiscall_call},
    {0x00411DF0u, NativeCallingConvention::thiscall_call},
    {0x00411F20u, NativeCallingConvention::thiscall_call},
    {0x00411F80u, NativeCallingConvention::thiscall_call},
    {0x00411FE0u, NativeCallingConvention::thiscall_call},
    {0x00412040u, NativeCallingConvention::thiscall_call},
    {0x004120A0u, NativeCallingConvention::thiscall_call},
    {0x00412100u, NativeCallingConvention::thiscall_call},
    {0x00412B70u, NativeCallingConvention::cdecl_call},
    {0x00412BC0u, NativeCallingConvention::thiscall_call},
    {0x00412C80u, NativeCallingConvention::thiscall_call},
    {0x00412D50u, NativeCallingConvention::thiscall_call},
    {0x00412E60u, NativeCallingConvention::thiscall_call},
    {0x00412FA0u, NativeCallingConvention::thiscall_call},
    {0x004130A0u, NativeCallingConvention::thiscall_call},
    {0x00413B30u, NativeCallingConvention::cdecl_call},
    {0x00413B80u, NativeCallingConvention::thiscall_call},
    {0x00414920u, NativeCallingConvention::cdecl_call},
    {0x004149A0u, NativeCallingConvention::fastcall_call},
    {0x004149E0u, NativeCallingConvention::fastcall_call},
    {0x00414A30u, NativeCallingConvention::fastcall_call},
    {0x00414AE0u, NativeCallingConvention::fastcall_call},
    {0x00414BF0u, NativeCallingConvention::fastcall_call},
    {0x00414CA0u, NativeCallingConvention::thiscall_call},
    {0x00414D50u, NativeCallingConvention::fastcall_call},
    {0x00414E00u, NativeCallingConvention::fastcall_call},
    {0x004150C0u, NativeCallingConvention::fastcall_call},
    {0x00415190u, NativeCallingConvention::fastcall_call},
    {0x00415260u, NativeCallingConvention::fastcall_call},
    {0x00415370u, NativeCallingConvention::fastcall_call},
    {0x00415440u, NativeCallingConvention::fastcall_call},
    {0x004156A0u, NativeCallingConvention::fastcall_call},
    {0x00415770u, NativeCallingConvention::fastcall_call},
    {0x00415840u, NativeCallingConvention::fastcall_call},
    {0x00415910u, NativeCallingConvention::fastcall_call},
    {0x004159E0u, NativeCallingConvention::fastcall_call},
    {0x00415DB0u, NativeCallingConvention::fastcall_call},
    {0x00415E00u, NativeCallingConvention::fastcall_call},
    {0x00415EA0u, NativeCallingConvention::fastcall_call},
    {0x00415F40u, NativeCallingConvention::fastcall_call},
    {0x00415FE0u, NativeCallingConvention::fastcall_call},
    {0x00416080u, NativeCallingConvention::fastcall_call},
    {0x004160D0u, NativeCallingConvention::fastcall_call},
    {0x00416120u, NativeCallingConvention::fastcall_call},
    {0x004161D0u, NativeCallingConvention::fastcall_call},
    {0x00416290u, NativeCallingConvention::fastcall_call},
    {0x004163A0u, NativeCallingConvention::fastcall_call},
    {0x00416460u, NativeCallingConvention::fastcall_call},
    {0x00416520u, NativeCallingConvention::fastcall_call},
    {0x00416610u, NativeCallingConvention::fastcall_call},
    {0x00416650u, NativeCallingConvention::fastcall_call},
    {0x00416A30u, NativeCallingConvention::thiscall_call},
    {0x00416AD0u, NativeCallingConvention::thiscall_call},
    {0x00416B70u, NativeCallingConvention::thiscall_call},
    {0x00416C10u, NativeCallingConvention::fastcall_call},
    {0x00416CF0u, NativeCallingConvention::fastcall_call},
    {0x00416DD0u, NativeCallingConvention::fastcall_call},
    {0x00416EB0u, NativeCallingConvention::fastcall_call},
    {0x00416F90u, NativeCallingConvention::fastcall_call},
    {0x00417070u, NativeCallingConvention::fastcall_call},
    {0x004172F0u, NativeCallingConvention::fastcall_call},
    {0x004173D0u, NativeCallingConvention::fastcall_call},
    {0x004174B0u, NativeCallingConvention::fastcall_call},
    {0x00417590u, NativeCallingConvention::fastcall_call},
    {0x00417670u, NativeCallingConvention::fastcall_call},
    {0x00417750u, NativeCallingConvention::fastcall_call},
    {0x00417C70u, NativeCallingConvention::fastcall_call},
    {0x00417CC0u, NativeCallingConvention::thiscall_call},
    {0x00417D20u, NativeCallingConvention::thiscall_call},
    {0x00417D80u, NativeCallingConvention::thiscall_call},
    {0x00417DE0u, NativeCallingConvention::thiscall_call},
    {0x00417E80u, NativeCallingConvention::thiscall_call},
    {0x00417F20u, NativeCallingConvention::fastcall_call},
    {0x00417FA0u, NativeCallingConvention::fastcall_call},
    {0x00418010u, NativeCallingConvention::fastcall_call},
    {0x004180D0u, NativeCallingConvention::fastcall_call},
    {0x00418140u, NativeCallingConvention::fastcall_call},
    {0x004181B0u, NativeCallingConvention::fastcall_call},
    {0x00418220u, NativeCallingConvention::thiscall_call},
    {0x004182C0u, NativeCallingConvention::fastcall_call},
    {0x00418350u, NativeCallingConvention::fastcall_call},
    {0x00418400u, NativeCallingConvention::fastcall_call},
    {0x00418470u, NativeCallingConvention::fastcall_call},
    {0x00418620u, NativeCallingConvention::thiscall_call},
    {0x00418750u, NativeCallingConvention::cdecl_call},
    {0x004188A0u, NativeCallingConvention::fastcall_call},
    {0x004189B0u, NativeCallingConvention::cdecl_call},
    {0x00418A20u, NativeCallingConvention::fastcall_call},
    {0x00418B20u, NativeCallingConvention::fastcall_call},
    {0x00418BB0u, NativeCallingConvention::thiscall_call},
    {0x00418D50u, NativeCallingConvention::fastcall_call},
    {0x00418DD0u, NativeCallingConvention::cdecl_call},
    {0x00419220u, NativeCallingConvention::cdecl_call},
    {0x004193E0u, NativeCallingConvention::thiscall_call},
    {0x00419730u, NativeCallingConvention::fastcall_call},
    {0x00419810u, NativeCallingConvention::fastcall_call},
    {0x00419840u, NativeCallingConvention::fastcall_call},
    {0x00419920u, NativeCallingConvention::thiscall_call},
    {0x00419990u, NativeCallingConvention::thiscall_call},
    {0x00419AD0u, NativeCallingConvention::fastcall_call},
    {0x00419BB0u, NativeCallingConvention::fastcall_call},
    {0x00419BF0u, NativeCallingConvention::fastcall_call},
    {0x00419D10u, NativeCallingConvention::thiscall_call},
    {0x00419EB0u, NativeCallingConvention::cdecl_call},
    {0x00419F30u, NativeCallingConvention::thiscall_call},
    {0x00419F50u, NativeCallingConvention::thiscall_call},
    {0x00419F70u, NativeCallingConvention::fastcall_call},
    {0x0041A010u, NativeCallingConvention::thiscall_call},
    {0x0041A070u, NativeCallingConvention::cdecl_call},
    {0x0041A080u, NativeCallingConvention::cdecl_call},
    {0x0041A090u, NativeCallingConvention::cdecl_call},
    {0x0041A0B0u, NativeCallingConvention::cdecl_call},
    {0x0041A0C0u, NativeCallingConvention::thiscall_call},
    {0x0041A560u, NativeCallingConvention::fastcall_call},
    {0x0041A9F0u, NativeCallingConvention::cdecl_call},
    {0x0041ACF0u, NativeCallingConvention::fastcall_call},
    {0x0041AD50u, NativeCallingConvention::cdecl_call},
    {0x0041AE00u, NativeCallingConvention::cdecl_call},
    {0x0041AE60u, NativeCallingConvention::fastcall_call},
    {0x0041AEE0u, NativeCallingConvention::thiscall_call},
    {0x0041B1E0u, NativeCallingConvention::fastcall_call},
    {0x0041B2F0u, NativeCallingConvention::cdecl_call},
    {0x0041B3C0u, NativeCallingConvention::cdecl_call},
    {0x0041B530u, NativeCallingConvention::thiscall_call},
    {0x0041B560u, NativeCallingConvention::thiscall_call},
    {0x0041B5B0u, NativeCallingConvention::thiscall_call},
    {0x0041B980u, NativeCallingConvention::fastcall_call},
    {0x0041BA00u, NativeCallingConvention::thiscall_call},
    {0x0041BE20u, NativeCallingConvention::cdecl_call},
    {0x0041BEE0u, NativeCallingConvention::cdecl_call},
    {0x0041BF70u, NativeCallingConvention::cdecl_call},
    {0x0041BFF0u, NativeCallingConvention::cdecl_call},
    {0x0041C070u, NativeCallingConvention::thiscall_call},
    {0x0041C1B0u, NativeCallingConvention::thiscall_call},
    {0x0041C1F0u, NativeCallingConvention::thiscall_call},
    {0x0041C220u, NativeCallingConvention::thiscall_call},
    {0x0041C3E0u, NativeCallingConvention::thiscall_call},
    {0x0041C520u, NativeCallingConvention::thiscall_call},
    {0x0041C5B0u, NativeCallingConvention::thiscall_call},
    {0x0041C6C0u, NativeCallingConvention::fastcall_call},
    {0x0041C7F0u, NativeCallingConvention::thiscall_call},
    {0x0041CC90u, NativeCallingConvention::cdecl_call},
    {0x0041CDA0u, NativeCallingConvention::thiscall_call},
    {0x0041D3C0u, NativeCallingConvention::thiscall_call},
    {0x0041E1B0u, NativeCallingConvention::fastcall_call},
    {0x0041E220u, NativeCallingConvention::thiscall_call},
    {0x0041E280u, NativeCallingConvention::fastcall_call},
    {0x0041E310u, NativeCallingConvention::thiscall_call},
    {0x0041E350u, NativeCallingConvention::stdcall_call},
    {0x0041E3C0u, NativeCallingConvention::cdecl_call},
    {0x0041E480u, NativeCallingConvention::cdecl_call},
    {0x0041E550u, NativeCallingConvention::cdecl_call},
    {0x0041E6A0u, NativeCallingConvention::thiscall_call},
    {0x0041E9A0u, NativeCallingConvention::cdecl_call},
    {0x0041EC70u, NativeCallingConvention::fastcall_call},
    {0x0041ECA0u, NativeCallingConvention::fastcall_call},
    {0x0041ED40u, NativeCallingConvention::thiscall_call},
    {0x0041F050u, NativeCallingConvention::fastcall_call},
    {0x0041F080u, NativeCallingConvention::fastcall_call},
    {0x0041F0D0u, NativeCallingConvention::fastcall_call},
    {0x0041F110u, NativeCallingConvention::thiscall_call},
    {0x0041F1C0u, NativeCallingConvention::cdecl_call},
    {0x0041F1D0u, NativeCallingConvention::fastcall_call},
    {0x0041F1F0u, NativeCallingConvention::thiscall_call},
    {0x0041F2B0u, NativeCallingConvention::thiscall_call},
    {0x0041F2F0u, NativeCallingConvention::fastcall_call},
    {0x0041F360u, NativeCallingConvention::fastcall_call},
    {0x0041F3C0u, NativeCallingConvention::thiscall_call},
    {0x0041F400u, NativeCallingConvention::thiscall_call},
    {0x0041F420u, NativeCallingConvention::thiscall_call},
    {0x0041F7F0u, NativeCallingConvention::thiscall_call},
    {0x0041F930u, NativeCallingConvention::thiscall_call},
    {0x0041FA00u, NativeCallingConvention::thiscall_call},
    {0x0041FAB0u, NativeCallingConvention::thiscall_call},
    {0x0041FBB0u, NativeCallingConvention::fastcall_call},
    {0x0041FBC0u, NativeCallingConvention::thiscall_call},
    {0x0041FBF0u, NativeCallingConvention::thiscall_call},
    {0x0041FFE0u, NativeCallingConvention::thiscall_call},
    {0x004205E0u, NativeCallingConvention::fastcall_call},
    {0x00420720u, NativeCallingConvention::thiscall_call},
    {0x00420860u, NativeCallingConvention::thiscall_call},
    {0x00420F90u, NativeCallingConvention::fastcall_call},
    {0x004210D0u, NativeCallingConvention::fastcall_call},
    {0x004214A0u, NativeCallingConvention::fastcall_call},
    {0x00421600u, NativeCallingConvention::thiscall_call},
    {0x004216D0u, NativeCallingConvention::thiscall_call},
    {0x00421710u, NativeCallingConvention::cdecl_call},
    {0x00421720u, NativeCallingConvention::thiscall_call},
    {0x00421750u, NativeCallingConvention::cdecl_call},
    {0x00421760u, NativeCallingConvention::cdecl_call},
    {0x00421780u, NativeCallingConvention::cdecl_call},
    {0x00421790u, NativeCallingConvention::cdecl_call},
    {0x004217A0u, NativeCallingConvention::cdecl_call},
    {0x004217B0u, NativeCallingConvention::cdecl_call},
    {0x004217C0u, NativeCallingConvention::cdecl_call},
    {0x004217E0u, NativeCallingConvention::cdecl_call},
    {0x00421800u, NativeCallingConvention::cdecl_call},
    {0x00421820u, NativeCallingConvention::cdecl_call},
    {0x00421830u, NativeCallingConvention::cdecl_call},
    {0x00421840u, NativeCallingConvention::cdecl_call},
    {0x00421850u, NativeCallingConvention::cdecl_call},
    {0x00421940u, NativeCallingConvention::cdecl_call},
    {0x00421950u, NativeCallingConvention::cdecl_call},
    {0x00421970u, NativeCallingConvention::cdecl_call},
    {0x00421980u, NativeCallingConvention::cdecl_call},
    {0x00421990u, NativeCallingConvention::cdecl_call},
    {0x004219B0u, NativeCallingConvention::cdecl_call},
    {0x004219E0u, NativeCallingConvention::cdecl_call},
    {0x004219F0u, NativeCallingConvention::cdecl_call},
    {0x00421A00u, NativeCallingConvention::cdecl_call},
    {0x00421A10u, NativeCallingConvention::cdecl_call},
    {0x00421A50u, NativeCallingConvention::cdecl_call},
    {0x00421A70u, NativeCallingConvention::cdecl_call},
    {0x00421A80u, NativeCallingConvention::cdecl_call},
    {0x00421A90u, NativeCallingConvention::fastcall_call},
    {0x00421C00u, NativeCallingConvention::fastcall_call},
    {0x00421CF0u, NativeCallingConvention::fastcall_call},
    {0x00421D50u, NativeCallingConvention::fastcall_call},
    {0x00421F10u, NativeCallingConvention::cdecl_call},
    {0x00421FB0u, NativeCallingConvention::cdecl_call},
    {0x00422000u, NativeCallingConvention::fastcall_call},
    {0x00422270u, NativeCallingConvention::thiscall_call},
    {0x004223E0u, NativeCallingConvention::thiscall_call},
    {0x004225F0u, NativeCallingConvention::fastcall_call},
    {0x00422620u, NativeCallingConvention::fastcall_call},
    {0x00422630u, NativeCallingConvention::thiscall_call},
    {0x00422660u, NativeCallingConvention::thiscall_call},
    {0x004226C0u, NativeCallingConvention::fastcall_call},
    {0x00422910u, NativeCallingConvention::thiscall_call},
    {0x00422980u, NativeCallingConvention::thiscall_call},
    {0x004229D0u, NativeCallingConvention::fastcall_call},
    {0x004229F0u, NativeCallingConvention::thiscall_call},
    {0x00422A20u, NativeCallingConvention::fastcall_call},
    {0x00422CB0u, NativeCallingConvention::fastcall_call},
    {0x00422E50u, NativeCallingConvention::thiscall_call},
    {0x00423E70u, NativeCallingConvention::thiscall_call},
    {0x004243C0u, NativeCallingConvention::thiscall_call},
    {0x00424680u, NativeCallingConvention::fastcall_call},
    {0x004246B0u, NativeCallingConvention::thiscall_call},
    {0x004246E0u, NativeCallingConvention::thiscall_call},
    {0x00424790u, NativeCallingConvention::thiscall_call},
    {0x004249C0u, NativeCallingConvention::thiscall_call},
    {0x00424A40u, NativeCallingConvention::fastcall_call},
    {0x00424AC0u, NativeCallingConvention::thiscall_call},
    {0x00424AD0u, NativeCallingConvention::cdecl_call},
    {0x00424D70u, NativeCallingConvention::fastcall_call},
    {0x00425290u, NativeCallingConvention::thiscall_call},
    {0x004253F0u, NativeCallingConvention::thiscall_call},
    {0x00425570u, NativeCallingConvention::fastcall_call},
    {0x004255D0u, NativeCallingConvention::fastcall_call},
    {0x004255F0u, NativeCallingConvention::fastcall_call},
    {0x004258F0u, NativeCallingConvention::fastcall_call},
    {0x00425940u, NativeCallingConvention::fastcall_call},
    {0x00425950u, NativeCallingConvention::fastcall_call},
    {0x004259C0u, NativeCallingConvention::fastcall_call},
    {0x00425A50u, NativeCallingConvention::fastcall_call},
    {0x00425AA0u, NativeCallingConvention::cdecl_call},
    {0x00425B20u, NativeCallingConvention::fastcall_call},
    {0x00425BD0u, NativeCallingConvention::fastcall_call},
    {0x00425BF0u, NativeCallingConvention::fastcall_call},
    {0x00425C00u, NativeCallingConvention::thiscall_call},
    {0x00425C30u, NativeCallingConvention::thiscall_call},
    {0x00425CC0u, NativeCallingConvention::cdecl_call},
    {0x00425CD0u, NativeCallingConvention::cdecl_call},
    {0x00425CE0u, NativeCallingConvention::cdecl_call},
    {0x00425CF0u, NativeCallingConvention::fastcall_call},
    {0x00425D30u, NativeCallingConvention::fastcall_call},
    {0x00425D80u, NativeCallingConvention::cdecl_call},
    {0x00425E30u, NativeCallingConvention::fastcall_call},
    {0x00425E70u, NativeCallingConvention::fastcall_call},
    {0x00425EB0u, NativeCallingConvention::thiscall_call},
    {0x00425F40u, NativeCallingConvention::thiscall_call},
    {0x00425F60u, NativeCallingConvention::fastcall_call},
    {0x00425F90u, NativeCallingConvention::cdecl_call},
    {0x00425FA0u, NativeCallingConvention::fastcall_call},
    {0x00426080u, NativeCallingConvention::thiscall_call},
    {0x004260F0u, NativeCallingConvention::thiscall_call},
    {0x00426160u, NativeCallingConvention::thiscall_call},
    {0x00426180u, NativeCallingConvention::thiscall_call},
    {0x004261A0u, NativeCallingConvention::fastcall_call},
    {0x004261B0u, NativeCallingConvention::fastcall_call},
    {0x004261C0u, NativeCallingConvention::fastcall_call},
    {0x00426440u, NativeCallingConvention::fastcall_call},
    {0x00426640u, NativeCallingConvention::thiscall_call},
    {0x004266B0u, NativeCallingConvention::thiscall_call},
    {0x004266D0u, NativeCallingConvention::fastcall_call},
    {0x00426710u, NativeCallingConvention::fastcall_call},
    {0x00426780u, NativeCallingConvention::thiscall_call},
    {0x00426A50u, NativeCallingConvention::fastcall_call},
    {0x004273E0u, NativeCallingConvention::cdecl_call},
    {0x00427550u, NativeCallingConvention::fastcall_call},
    {0x00427590u, NativeCallingConvention::thiscall_call},
    {0x004275E0u, NativeCallingConvention::thiscall_call},
    {0x004276A0u, NativeCallingConvention::fastcall_call},
    {0x00427750u, NativeCallingConvention::thiscall_call},
    {0x004277C0u, NativeCallingConvention::fastcall_call},
    {0x00427870u, NativeCallingConvention::thiscall_call},
    {0x004278E0u, NativeCallingConvention::fastcall_call},
    {0x00427F10u, NativeCallingConvention::thiscall_call},
    {0x00428A10u, NativeCallingConvention::thiscall_call},
    {0x00428BF0u, NativeCallingConvention::cdecl_call},
    {0x00429000u, NativeCallingConvention::fastcall_call},
    {0x00429280u, NativeCallingConvention::thiscall_call},
    {0x004294E0u, NativeCallingConvention::thiscall_call},
    {0x00429830u, NativeCallingConvention::thiscall_call},
    {0x004298B0u, NativeCallingConvention::thiscall_call},
    {0x00429990u, NativeCallingConvention::fastcall_call},
    {0x00429A10u, NativeCallingConvention::thiscall_call},
    {0x00429A30u, NativeCallingConvention::fastcall_call},
    {0x00429A80u, NativeCallingConvention::thiscall_call},
    {0x00429AF0u, NativeCallingConvention::fastcall_call},
    {0x00429B20u, NativeCallingConvention::fastcall_call},
    {0x00429C10u, NativeCallingConvention::cdecl_call},
    {0x00429F30u, NativeCallingConvention::fastcall_call},
    {0x0042A290u, NativeCallingConvention::fastcall_call},
    {0x0042A320u, NativeCallingConvention::thiscall_call},
    {0x0042A3A0u, NativeCallingConvention::cdecl_call},
    {0x0042A480u, NativeCallingConvention::fastcall_call},
    {0x0042A630u, NativeCallingConvention::cdecl_call},
    {0x0042AA90u, NativeCallingConvention::fastcall_call},
    {0x0042AB10u, NativeCallingConvention::fastcall_call},
    {0x0042AD40u, NativeCallingConvention::fastcall_call},
    {0x0042ADA0u, NativeCallingConvention::fastcall_call},
    {0x0042AFB0u, NativeCallingConvention::fastcall_call},
    {0x0042AFC0u, NativeCallingConvention::fastcall_call},
    {0x0042B0A0u, NativeCallingConvention::cdecl_call},
    {0x0042B0B0u, NativeCallingConvention::cdecl_call},
    {0x0042B130u, NativeCallingConvention::cdecl_call},
    {0x0042B150u, NativeCallingConvention::fastcall_call},
    {0x0042B200u, NativeCallingConvention::thiscall_call},
    {0x0042B260u, NativeCallingConvention::cdecl_call},
    {0x0042B300u, NativeCallingConvention::cdecl_call},
    {0x0042B320u, NativeCallingConvention::fastcall_call},
    {0x0042B3D0u, NativeCallingConvention::cdecl_call},
    {0x0042B3E0u, NativeCallingConvention::cdecl_call},
    {0x0042B480u, NativeCallingConvention::cdecl_call},
    {0x0042B4A0u, NativeCallingConvention::fastcall_call},
    {0x0042B530u, NativeCallingConvention::thiscall_call},
    {0x0042B710u, NativeCallingConvention::cdecl_call},
    {0x0042B720u, NativeCallingConvention::fastcall_call},
    {0x0042B7D0u, NativeCallingConvention::cdecl_call},
    {0x0042B7E0u, NativeCallingConvention::thiscall_call},
    {0x0042B800u, NativeCallingConvention::thiscall_call},
    {0x0042BA50u, NativeCallingConvention::thiscall_call},
    {0x0042BAD0u, NativeCallingConvention::thiscall_call},
    {0x0042C020u, NativeCallingConvention::thiscall_call},
    {0x0042C050u, NativeCallingConvention::thiscall_call},
    {0x0042C570u, NativeCallingConvention::thiscall_call},
    {0x0042C690u, NativeCallingConvention::thiscall_call},
    {0x0042C6B0u, NativeCallingConvention::fastcall_call},
    {0x0042C770u, NativeCallingConvention::thiscall_call},
    {0x0042C800u, NativeCallingConvention::thiscall_call},
    {0x0042CFC0u, NativeCallingConvention::cdecl_call},
    {0x0042D0F0u, NativeCallingConvention::fastcall_call},
    {0x0042D100u, NativeCallingConvention::fastcall_call},
    {0x0042D140u, NativeCallingConvention::thiscall_call},
    {0x0042D160u, NativeCallingConvention::thiscall_call},
    {0x0042D180u, NativeCallingConvention::thiscall_call},
    {0x0042D290u, NativeCallingConvention::thiscall_call},
    {0x0042D430u, NativeCallingConvention::thiscall_call},
    {0x0042D9F0u, NativeCallingConvention::thiscall_call},
    {0x0042E000u, NativeCallingConvention::thiscall_call},
    {0x0042E080u, NativeCallingConvention::thiscall_call},
    {0x0042E1D0u, NativeCallingConvention::cdecl_call},
    {0x0042E210u, NativeCallingConvention::fastcall_call},
    {0x0042E250u, NativeCallingConvention::fastcall_call},
    {0x0042E2F0u, NativeCallingConvention::thiscall_call},
    {0x0042E3F0u, NativeCallingConvention::thiscall_call},
    {0x0042E430u, NativeCallingConvention::cdecl_call},
    {0x0042E440u, NativeCallingConvention::fastcall_call},
    {0x0042E480u, NativeCallingConvention::cdecl_call},
    {0x0042E4C0u, NativeCallingConvention::cdecl_call},
    {0x0042E540u, NativeCallingConvention::thiscall_call},
    {0x0042E6B0u, NativeCallingConvention::fastcall_call},
    {0x0042E770u, NativeCallingConvention::cdecl_call},
    {0x0042E850u, NativeCallingConvention::cdecl_call},
    {0x0042E920u, NativeCallingConvention::cdecl_call},
    {0x0042E990u, NativeCallingConvention::cdecl_call},
    {0x0042EB70u, NativeCallingConvention::cdecl_call},
    {0x0042EBB0u, NativeCallingConvention::fastcall_call},
    {0x0042EBD0u, NativeCallingConvention::cdecl_call},
    {0x0042EBE0u, NativeCallingConvention::cdecl_call},
    {0x0042EBF0u, NativeCallingConvention::fastcall_call},
    {0x0042EE20u, NativeCallingConvention::fastcall_call},
    {0x0042EF20u, NativeCallingConvention::fastcall_call},
    {0x0042F000u, NativeCallingConvention::fastcall_call},
    {0x0042F0E0u, NativeCallingConvention::fastcall_call},
    {0x0042F180u, NativeCallingConvention::fastcall_call},
    {0x0042F2A0u, NativeCallingConvention::cdecl_call},
    {0x0042F2D0u, NativeCallingConvention::fastcall_call},
    {0x0042F3E0u, NativeCallingConvention::fastcall_call},
    {0x0042F450u, NativeCallingConvention::fastcall_call},
    {0x0042F730u, NativeCallingConvention::fastcall_call},
    {0x0042F7D0u, NativeCallingConvention::thiscall_call},
    {0x00430900u, NativeCallingConvention::thiscall_call},
    {0x00430920u, NativeCallingConvention::fastcall_call},
    {0x004309F0u, NativeCallingConvention::fastcall_call},
    {0x00430AC0u, NativeCallingConvention::cdecl_call},
    {0x00430BB0u, NativeCallingConvention::fastcall_call},
    {0x00430BC0u, NativeCallingConvention::fastcall_call},
    {0x00430BE0u, NativeCallingConvention::cdecl_call},
    {0x00430CB0u, NativeCallingConvention::cdecl_call},
    {0x00430D20u, NativeCallingConvention::thiscall_call},
    {0x00430F20u, NativeCallingConvention::cdecl_call},
    {0x00430F40u, NativeCallingConvention::cdecl_call},
    {0x00430F60u, NativeCallingConvention::thiscall_call},
    {0x00431020u, NativeCallingConvention::thiscall_call},
    {0x004311D0u, NativeCallingConvention::cdecl_call},
    {0x004311F0u, NativeCallingConvention::cdecl_call},
    {0x00431210u, NativeCallingConvention::fastcall_call},
    {0x00431220u, NativeCallingConvention::thiscall_call},
    {0x00431240u, NativeCallingConvention::thiscall_call},
    {0x00431260u, NativeCallingConvention::thiscall_call},
    {0x00431280u, NativeCallingConvention::thiscall_call},
    {0x004312A0u, NativeCallingConvention::thiscall_call},
    {0x004312B0u, NativeCallingConvention::thiscall_call},
    {0x004312C0u, NativeCallingConvention::fastcall_call},
    {0x004312E0u, NativeCallingConvention::thiscall_call},
    {0x00431390u, NativeCallingConvention::cdecl_call},
    {0x004313F0u, NativeCallingConvention::cdecl_call},
    {0x00431460u, NativeCallingConvention::thiscall_call},
    {0x00431490u, NativeCallingConvention::thiscall_call},
    {0x004314D0u, NativeCallingConvention::thiscall_call},
    {0x00431500u, NativeCallingConvention::thiscall_call},
    {0x004315A0u, NativeCallingConvention::thiscall_call},
    {0x004315D0u, NativeCallingConvention::thiscall_call},
    {0x00431640u, NativeCallingConvention::thiscall_call},
    {0x00431680u, NativeCallingConvention::fastcall_call},
    {0x00431730u, NativeCallingConvention::thiscall_call},
    {0x004317E0u, NativeCallingConvention::cdecl_call},
    {0x00431800u, NativeCallingConvention::cdecl_call},
    {0x00431820u, NativeCallingConvention::fastcall_call},
    {0x00431850u, NativeCallingConvention::fastcall_call},
    {0x00431880u, NativeCallingConvention::cdecl_call},
    {0x00431980u, NativeCallingConvention::cdecl_call},
    {0x00431A00u, NativeCallingConvention::cdecl_call},
    {0x00431A70u, NativeCallingConvention::fastcall_call},
    {0x00431AE0u, NativeCallingConvention::cdecl_call},
    {0x00431B50u, NativeCallingConvention::cdecl_call},
    {0x00431C20u, NativeCallingConvention::thiscall_call},
    {0x00432790u, NativeCallingConvention::thiscall_call},
    {0x00432880u, NativeCallingConvention::cdecl_call},
    {0x00432970u, NativeCallingConvention::fastcall_call},
    {0x00433400u, NativeCallingConvention::fastcall_call},
    {0x00433470u, NativeCallingConvention::cdecl_call},
    {0x00433960u, NativeCallingConvention::cdecl_call},
    {0x00433A80u, NativeCallingConvention::cdecl_call},
    {0x00433B90u, NativeCallingConvention::fastcall_call},
    {0x00433BB0u, NativeCallingConvention::fastcall_call},
    {0x00433BD0u, NativeCallingConvention::thiscall_call},
    {0x00433C00u, NativeCallingConvention::fastcall_call},
    {0x00433C80u, NativeCallingConvention::fastcall_call},
    {0x00433CF0u, NativeCallingConvention::fastcall_call},
    {0x00433DA0u, NativeCallingConvention::fastcall_call},
    {0x00433E10u, NativeCallingConvention::cdecl_call},
    {0x00433E70u, NativeCallingConvention::cdecl_call},
    {0x00433FF0u, NativeCallingConvention::fastcall_call},
    {0x00434080u, NativeCallingConvention::fastcall_call},
    {0x004340E0u, NativeCallingConvention::fastcall_call},
    {0x004341A0u, NativeCallingConvention::fastcall_call},
    {0x00434240u, NativeCallingConvention::cdecl_call},
    {0x004342A0u, NativeCallingConvention::fastcall_call},
    {0x00434340u, NativeCallingConvention::cdecl_call},
    {0x00434390u, NativeCallingConvention::fastcall_call},
    {0x00434430u, NativeCallingConvention::cdecl_call},
    {0x00434480u, NativeCallingConvention::fastcall_call},
    {0x00434520u, NativeCallingConvention::cdecl_call},
    {0x00434610u, NativeCallingConvention::cdecl_call},
    {0x00434660u, NativeCallingConvention::fastcall_call},
    {0x004346F0u, NativeCallingConvention::thiscall_call},
    {0x00434740u, NativeCallingConvention::fastcall_call},
    {0x00434840u, NativeCallingConvention::cdecl_call},
    {0x004348D0u, NativeCallingConvention::fastcall_call},
    {0x00434900u, NativeCallingConvention::fastcall_call},
    {0x004349A0u, NativeCallingConvention::fastcall_call},
    {0x00434AF0u, NativeCallingConvention::fastcall_call},
    {0x00434D50u, NativeCallingConvention::cdecl_call},
    {0x00434D90u, NativeCallingConvention::cdecl_call},
    {0x00434E80u, NativeCallingConvention::fastcall_call},
    {0x00434F10u, NativeCallingConvention::fastcall_call},
    {0x00434FB0u, NativeCallingConvention::fastcall_call},
    {0x00435020u, NativeCallingConvention::fastcall_call},
    {0x004350C0u, NativeCallingConvention::fastcall_call},
    {0x00435110u, NativeCallingConvention::fastcall_call},
    {0x00435230u, NativeCallingConvention::fastcall_call},
    {0x00435D40u, NativeCallingConvention::fastcall_call},
    {0x004360D0u, NativeCallingConvention::fastcall_call},
    {0x004361E0u, NativeCallingConvention::fastcall_call},
    {0x004362E0u, NativeCallingConvention::fastcall_call},
    {0x00436510u, NativeCallingConvention::fastcall_call},
    {0x004368E0u, NativeCallingConvention::cdecl_call},
    {0x004369A0u, NativeCallingConvention::cdecl_call},
    {0x004369B0u, NativeCallingConvention::cdecl_call},
    {0x004369C0u, NativeCallingConvention::cdecl_call},
    {0x004369E0u, NativeCallingConvention::cdecl_call},
    {0x00436A00u, NativeCallingConvention::cdecl_call},
    {0x00436A60u, NativeCallingConvention::cdecl_call},
    {0x00436AC0u, NativeCallingConvention::cdecl_call},
    {0x00436B20u, NativeCallingConvention::cdecl_call},
    {0x00436B90u, NativeCallingConvention::cdecl_call},
    {0x00436C00u, NativeCallingConvention::cdecl_call},
    {0x00436C70u, NativeCallingConvention::cdecl_call},
    {0x00436CD0u, NativeCallingConvention::cdecl_call},
    {0x00436D30u, NativeCallingConvention::cdecl_call},
    {0x00436D60u, NativeCallingConvention::cdecl_call},
    {0x00436D90u, NativeCallingConvention::cdecl_call},
    {0x00436DD0u, NativeCallingConvention::cdecl_call},
    {0x00436E20u, NativeCallingConvention::cdecl_call},
    {0x00436ED0u, NativeCallingConvention::cdecl_call},
    {0x00436FD0u, NativeCallingConvention::cdecl_call},
    {0x00437020u, NativeCallingConvention::cdecl_call},
    {0x00437070u, NativeCallingConvention::cdecl_call},
    {0x004370C0u, NativeCallingConvention::cdecl_call},
    {0x00437120u, NativeCallingConvention::cdecl_call},
    {0x00437170u, NativeCallingConvention::cdecl_call},
    {0x004371F0u, NativeCallingConvention::cdecl_call},
    {0x00437270u, NativeCallingConvention::cdecl_call},
    {0x004372F0u, NativeCallingConvention::cdecl_call},
    {0x00437370u, NativeCallingConvention::cdecl_call},
    {0x004373F0u, NativeCallingConvention::cdecl_call},
    {0x00437470u, NativeCallingConvention::cdecl_call},
    {0x004374C0u, NativeCallingConvention::cdecl_call},
    {0x00437510u, NativeCallingConvention::cdecl_call},
    {0x00437540u, NativeCallingConvention::cdecl_call},
    {0x004375B0u, NativeCallingConvention::cdecl_call},
    {0x00437620u, NativeCallingConvention::cdecl_call},
    {0x00437690u, NativeCallingConvention::cdecl_call},
    {0x00437700u, NativeCallingConvention::cdecl_call},
    {0x00437750u, NativeCallingConvention::cdecl_call},
    {0x00437760u, NativeCallingConvention::cdecl_call},
    {0x00437780u, NativeCallingConvention::cdecl_call},
    {0x004377A0u, NativeCallingConvention::cdecl_call},
    {0x004377F0u, NativeCallingConvention::cdecl_call},
    {0x00437840u, NativeCallingConvention::cdecl_call},
    {0x00437890u, NativeCallingConvention::cdecl_call},
    {0x004378C0u, NativeCallingConvention::cdecl_call},
    {0x004378F0u, NativeCallingConvention::cdecl_call},
    {0x00437930u, NativeCallingConvention::cdecl_call},
    {0x00437970u, NativeCallingConvention::cdecl_call},
    {0x004379B0u, NativeCallingConvention::cdecl_call},
    {0x004379F0u, NativeCallingConvention::cdecl_call},
    {0x00437A10u, NativeCallingConvention::fastcall_call},
    {0x00437B00u, NativeCallingConvention::fastcall_call},
    {0x00437B10u, NativeCallingConvention::fastcall_call},
    {0x00437B80u, NativeCallingConvention::fastcall_call},
    {0x00437BF0u, NativeCallingConvention::thiscall_call},
    {0x00437CB0u, NativeCallingConvention::fastcall_call},
    {0x00437E10u, NativeCallingConvention::cdecl_call},
    {0x00437E20u, NativeCallingConvention::fastcall_call},
    {0x00437F60u, NativeCallingConvention::fastcall_call},
    {0x00437FF0u, NativeCallingConvention::fastcall_call},
    {0x004380A0u, NativeCallingConvention::thiscall_call},
    {0x00438100u, NativeCallingConvention::thiscall_call},
    {0x00438160u, NativeCallingConvention::thiscall_call},
    {0x004381C0u, NativeCallingConvention::thiscall_call},
    {0x00438220u, NativeCallingConvention::thiscall_call},
    {0x00438380u, NativeCallingConvention::thiscall_call},
    {0x004383F0u, NativeCallingConvention::thiscall_call},
    {0x00438460u, NativeCallingConvention::cdecl_call},
    {0x004384F0u, NativeCallingConvention::cdecl_call},
    {0x004385D0u, NativeCallingConvention::cdecl_call},
    {0x00438640u, NativeCallingConvention::fastcall_call},
    {0x004386C0u, NativeCallingConvention::fastcall_call},
    {0x00439630u, NativeCallingConvention::cdecl_call},
    {0x00439660u, NativeCallingConvention::cdecl_call},
    {0x00439670u, NativeCallingConvention::cdecl_call},
    {0x004396B0u, NativeCallingConvention::cdecl_call},
    {0x004396D0u, NativeCallingConvention::cdecl_call},
    {0x004397F0u, NativeCallingConvention::cdecl_call},
    {0x00439860u, NativeCallingConvention::cdecl_call},
    {0x004398D0u, NativeCallingConvention::cdecl_call},
    {0x00439BD0u, NativeCallingConvention::cdecl_call},
    {0x00439C30u, NativeCallingConvention::fastcall_call},
    {0x0043A290u, NativeCallingConvention::thiscall_call},
    {0x0043A300u, NativeCallingConvention::fastcall_call},
    {0x0043A3D0u, NativeCallingConvention::fastcall_call},
    {0x0043A470u, NativeCallingConvention::thiscall_call},
    {0x0043A520u, NativeCallingConvention::thiscall_call},
    {0x0043A6F0u, NativeCallingConvention::fastcall_call},
    {0x0043A830u, NativeCallingConvention::thiscall_call},
    {0x0043A990u, NativeCallingConvention::thiscall_call},
    {0x0043AA30u, NativeCallingConvention::thiscall_call},
    {0x0043AC30u, NativeCallingConvention::cdecl_call},
    {0x0043AC90u, NativeCallingConvention::cdecl_call},
    {0x0043ACF0u, NativeCallingConvention::cdecl_call},
    {0x0043AD60u, NativeCallingConvention::fastcall_call},
    {0x0043AE00u, NativeCallingConvention::cdecl_call},
    {0x0043AE70u, NativeCallingConvention::cdecl_call},
    {0x0043AED0u, NativeCallingConvention::cdecl_call},
    {0x0043AF30u, NativeCallingConvention::fastcall_call},
    {0x0043AFA0u, NativeCallingConvention::fastcall_call},
    {0x0043B0B0u, NativeCallingConvention::cdecl_call},
    {0x0043B0C0u, NativeCallingConvention::fastcall_call},
    {0x0043B0D0u, NativeCallingConvention::fastcall_call},
    {0x0043B130u, NativeCallingConvention::cdecl_call},
    {0x0043B140u, NativeCallingConvention::cdecl_call},
    {0x0043B160u, NativeCallingConvention::cdecl_call},
    {0x0043B190u, NativeCallingConvention::cdecl_call},
    {0x0043B320u, NativeCallingConvention::cdecl_call},
    {0x0043B4C0u, NativeCallingConvention::cdecl_call},
    {0x0043B610u, NativeCallingConvention::cdecl_call},
    {0x0043B790u, NativeCallingConvention::cdecl_call},
    {0x0043B880u, NativeCallingConvention::cdecl_call},
    {0x0043B8F0u, NativeCallingConvention::fastcall_call},
    {0x0043BA10u, NativeCallingConvention::cdecl_call},
    {0x0043BB30u, NativeCallingConvention::cdecl_call},
    {0x0043BB80u, NativeCallingConvention::cdecl_call},
    {0x0043BBC0u, NativeCallingConvention::fastcall_call},
    {0x0043BBF0u, NativeCallingConvention::fastcall_call},
    {0x0043BC20u, NativeCallingConvention::fastcall_call},
    {0x0043BC50u, NativeCallingConvention::cdecl_call},
    {0x0043BC90u, NativeCallingConvention::cdecl_call},
    {0x0043BCF0u, NativeCallingConvention::fastcall_call},
    {0x0043BD20u, NativeCallingConvention::cdecl_call},
    {0x0043BD80u, NativeCallingConvention::fastcall_call},
    {0x0043BDB0u, NativeCallingConvention::cdecl_call},
    {0x0043BFA0u, NativeCallingConvention::cdecl_call},
    {0x0043C030u, NativeCallingConvention::cdecl_call},
    {0x0043C110u, NativeCallingConvention::fastcall_call},
    {0x0043C150u, NativeCallingConvention::cdecl_call},
    {0x0043C1A0u, NativeCallingConvention::cdecl_call},
    {0x0043C1D0u, NativeCallingConvention::cdecl_call},
    {0x0043C230u, NativeCallingConvention::cdecl_call},
    {0x0043C2C0u, NativeCallingConvention::cdecl_call},
    {0x0043C350u, NativeCallingConvention::cdecl_call},
    {0x0043C3A0u, NativeCallingConvention::cdecl_call},
    {0x0043C770u, NativeCallingConvention::cdecl_call},
    {0x0043C7C0u, NativeCallingConvention::cdecl_call},
    {0x0043C7E0u, NativeCallingConvention::cdecl_call},
    {0x0043C840u, NativeCallingConvention::cdecl_call},
    {0x0043C8A0u, NativeCallingConvention::cdecl_call},
    {0x0043C910u, NativeCallingConvention::cdecl_call},
    {0x0043C980u, NativeCallingConvention::cdecl_call},
    {0x0043CCC0u, NativeCallingConvention::cdecl_call},
    {0x0043D3A0u, NativeCallingConvention::cdecl_call},
    {0x0043D400u, NativeCallingConvention::cdecl_call},
    {0x0043D490u, NativeCallingConvention::cdecl_call},
    {0x0043D4C0u, NativeCallingConvention::cdecl_call},
    {0x0043D550u, NativeCallingConvention::cdecl_call},
    {0x0043D5B0u, NativeCallingConvention::cdecl_call},
    {0x0043D6B0u, NativeCallingConvention::cdecl_call},
    {0x0043D7C0u, NativeCallingConvention::cdecl_call},
    {0x0043D9B0u, NativeCallingConvention::cdecl_call},
    {0x0043DA20u, NativeCallingConvention::cdecl_call},
    {0x0043DA90u, NativeCallingConvention::cdecl_call},
    {0x0043DBC0u, NativeCallingConvention::cdecl_call},
    {0x0043DC60u, NativeCallingConvention::cdecl_call},
    {0x0043DCE0u, NativeCallingConvention::cdecl_call},
    {0x0043DD60u, NativeCallingConvention::cdecl_call},
    {0x0043DDE0u, NativeCallingConvention::cdecl_call},
    {0x0043E0F0u, NativeCallingConvention::fastcall_call},
    {0x0043E220u, NativeCallingConvention::cdecl_call},
    {0x0043E510u, NativeCallingConvention::cdecl_call},
    {0x0043E6C0u, NativeCallingConvention::cdecl_call},
    {0x0043E6F0u, NativeCallingConvention::cdecl_call},
    {0x0043E780u, NativeCallingConvention::cdecl_call},
    {0x0043E840u, NativeCallingConvention::cdecl_call},
    {0x0043E890u, NativeCallingConvention::cdecl_call},
    {0x0043E8C0u, NativeCallingConvention::cdecl_call},
    {0x0043E940u, NativeCallingConvention::cdecl_call},
    {0x0043E9B0u, NativeCallingConvention::cdecl_call},
    {0x0043EA60u, NativeCallingConvention::cdecl_call},
    {0x0043EAB0u, NativeCallingConvention::cdecl_call},
    {0x0043EAD0u, NativeCallingConvention::cdecl_call},
    {0x0043EB20u, NativeCallingConvention::cdecl_call},
    {0x0043EB50u, NativeCallingConvention::cdecl_call},
    {0x0043EBB0u, NativeCallingConvention::cdecl_call},
    {0x0043EBE0u, NativeCallingConvention::cdecl_call},
    {0x0043EC20u, NativeCallingConvention::cdecl_call},
    {0x0043EC50u, NativeCallingConvention::cdecl_call},
    {0x0043ECB0u, NativeCallingConvention::cdecl_call},
    {0x0043ECC0u, NativeCallingConvention::cdecl_call},
    {0x0043ED30u, NativeCallingConvention::cdecl_call},
    {0x0043EE40u, NativeCallingConvention::cdecl_call},
    {0x0043EF50u, NativeCallingConvention::cdecl_call},
    {0x0043EF90u, NativeCallingConvention::cdecl_call},
    {0x0043EFD0u, NativeCallingConvention::cdecl_call},
    {0x0043F010u, NativeCallingConvention::cdecl_call},
    {0x0043F050u, NativeCallingConvention::cdecl_call},
    {0x0043F090u, NativeCallingConvention::cdecl_call},
    {0x0043F0D0u, NativeCallingConvention::cdecl_call},
    {0x0043F100u, NativeCallingConvention::cdecl_call},
    {0x0043F180u, NativeCallingConvention::cdecl_call},
    {0x0043F2B0u, NativeCallingConvention::cdecl_call},
    {0x0043F2F0u, NativeCallingConvention::cdecl_call},
    {0x0043F3E0u, NativeCallingConvention::cdecl_call},
    {0x0043F440u, NativeCallingConvention::cdecl_call},
    {0x0043F480u, NativeCallingConvention::cdecl_call},
    {0x0043F4E0u, NativeCallingConvention::cdecl_call},
    {0x0043F530u, NativeCallingConvention::cdecl_call},
    {0x0043F6B0u, NativeCallingConvention::cdecl_call},
    {0x0043F6E0u, NativeCallingConvention::cdecl_call},
    {0x0043F730u, NativeCallingConvention::cdecl_call},
    {0x0043F840u, NativeCallingConvention::cdecl_call},
    {0x0043F870u, NativeCallingConvention::cdecl_call},
    {0x0043F9E0u, NativeCallingConvention::cdecl_call},
    {0x0043FA70u, NativeCallingConvention::cdecl_call},
    {0x0043FAE0u, NativeCallingConvention::cdecl_call},
    {0x0043FC90u, NativeCallingConvention::cdecl_call},
    {0x0043FDB0u, NativeCallingConvention::cdecl_call},
    {0x0043FEB0u, NativeCallingConvention::cdecl_call},
    {0x0043FF20u, NativeCallingConvention::cdecl_call},
    {0x0043FF90u, NativeCallingConvention::cdecl_call},
    {0x00440000u, NativeCallingConvention::cdecl_call},
    {0x00440030u, NativeCallingConvention::cdecl_call},
    {0x00440090u, NativeCallingConvention::cdecl_call},
    {0x004400F0u, NativeCallingConvention::cdecl_call},
    {0x00440150u, NativeCallingConvention::cdecl_call},
    {0x00440180u, NativeCallingConvention::cdecl_call},
    {0x004401B0u, NativeCallingConvention::cdecl_call},
    {0x00440260u, NativeCallingConvention::fastcall_call},
    {0x004402D0u, NativeCallingConvention::cdecl_call},
    {0x00440330u, NativeCallingConvention::cdecl_call},
    {0x004403B0u, NativeCallingConvention::cdecl_call},
    {0x00440410u, NativeCallingConvention::cdecl_call},
    {0x004404E0u, NativeCallingConvention::cdecl_call},
    {0x00440580u, NativeCallingConvention::cdecl_call},
    {0x00440600u, NativeCallingConvention::cdecl_call},
    {0x004406A0u, NativeCallingConvention::cdecl_call},
    {0x00440750u, NativeCallingConvention::cdecl_call},
    {0x00441C90u, NativeCallingConvention::cdecl_call},
    {0x00441CE0u, NativeCallingConvention::cdecl_call},
    {0x00441D60u, NativeCallingConvention::cdecl_call},
    {0x00441DD0u, NativeCallingConvention::cdecl_call},
    {0x00441E80u, NativeCallingConvention::cdecl_call},
    {0x00441FE0u, NativeCallingConvention::cdecl_call},
    {0x00442030u, NativeCallingConvention::cdecl_call},
    {0x00442140u, NativeCallingConvention::cdecl_call},
    {0x00442220u, NativeCallingConvention::cdecl_call},
    {0x004423A0u, NativeCallingConvention::cdecl_call},
    {0x00442570u, NativeCallingConvention::cdecl_call},
    {0x004425A0u, NativeCallingConvention::cdecl_call},
    {0x004425F0u, NativeCallingConvention::cdecl_call},
    {0x00442660u, NativeCallingConvention::cdecl_call},
    {0x004426D0u, NativeCallingConvention::cdecl_call},
    {0x00442740u, NativeCallingConvention::cdecl_call},
    {0x004427A0u, NativeCallingConvention::cdecl_call},
    {0x00442810u, NativeCallingConvention::cdecl_call},
    {0x00442880u, NativeCallingConvention::cdecl_call},
    {0x00442900u, NativeCallingConvention::cdecl_call},
    {0x00442980u, NativeCallingConvention::cdecl_call},
    {0x00442B60u, NativeCallingConvention::cdecl_call},
    {0x00442B70u, NativeCallingConvention::cdecl_call},
    {0x00442B80u, NativeCallingConvention::cdecl_call},
    {0x00442B90u, NativeCallingConvention::cdecl_call},
    {0x00442BA0u, NativeCallingConvention::cdecl_call},
    {0x00442C40u, NativeCallingConvention::cdecl_call},
    {0x00442D80u, NativeCallingConvention::cdecl_call},
    {0x00442D90u, NativeCallingConvention::cdecl_call},
    {0x00442DA0u, NativeCallingConvention::cdecl_call},
    {0x00442DB0u, NativeCallingConvention::cdecl_call},
    {0x00442DC0u, NativeCallingConvention::cdecl_call},
    {0x00442E80u, NativeCallingConvention::cdecl_call},
    {0x00442F70u, NativeCallingConvention::cdecl_call},
    {0x00443050u, NativeCallingConvention::cdecl_call},
    {0x004430D0u, NativeCallingConvention::thiscall_call},
    {0x00443230u, NativeCallingConvention::thiscall_call},
    {0x004432E0u, NativeCallingConvention::cdecl_call},
    {0x00443680u, NativeCallingConvention::thiscall_call},
    {0x00443730u, NativeCallingConvention::thiscall_call},
    {0x00443860u, NativeCallingConvention::thiscall_call},
    {0x00443990u, NativeCallingConvention::cdecl_call},
    {0x00443EB0u, NativeCallingConvention::cdecl_call},
    {0x00443F20u, NativeCallingConvention::cdecl_call},
    {0x00446D40u, NativeCallingConvention::cdecl_call},
    {0x00447770u, NativeCallingConvention::cdecl_call},
    {0x004478E0u, NativeCallingConvention::thiscall_call},
    {0x00447A40u, NativeCallingConvention::thiscall_call},
    {0x00447CC0u, NativeCallingConvention::thiscall_call},
    {0x00447DD0u, NativeCallingConvention::fastcall_call},
    {0x00447E90u, NativeCallingConvention::thiscall_call},
    {0x00448120u, NativeCallingConvention::thiscall_call},
    {0x004483B0u, NativeCallingConvention::fastcall_call},
    {0x00448490u, NativeCallingConvention::cdecl_call},
    {0x00448540u, NativeCallingConvention::fastcall_call},
    {0x004486E0u, NativeCallingConvention::fastcall_call},
    {0x00448880u, NativeCallingConvention::fastcall_call},
    {0x00448A20u, NativeCallingConvention::fastcall_call},
    {0x00448BC0u, NativeCallingConvention::thiscall_call},
    {0x00448D90u, NativeCallingConvention::thiscall_call},
    {0x00449180u, NativeCallingConvention::cdecl_call},
    {0x004496F0u, NativeCallingConvention::cdecl_call},
    {0x00449EF0u, NativeCallingConvention::cdecl_call},
    {0x0044B130u, NativeCallingConvention::cdecl_call},
    {0x0044B180u, NativeCallingConvention::fastcall_call},
    {0x0044B230u, NativeCallingConvention::thiscall_call},
    {0x0044B340u, NativeCallingConvention::thiscall_call},
    {0x0044B380u, NativeCallingConvention::fastcall_call},
    {0x0044B3B0u, NativeCallingConvention::fastcall_call},
    {0x0044B3C0u, NativeCallingConvention::cdecl_call},
    {0x0044B440u, NativeCallingConvention::thiscall_call},
    {0x0044B510u, NativeCallingConvention::thiscall_call},
    {0x0044B5A0u, NativeCallingConvention::fastcall_call},
    {0x0044B7D0u, NativeCallingConvention::thiscall_call},
    {0x0044B890u, NativeCallingConvention::thiscall_call},
    {0x0044B920u, NativeCallingConvention::fastcall_call},
    {0x0044BB80u, NativeCallingConvention::fastcall_call},
    {0x0044BC70u, NativeCallingConvention::fastcall_call},
    {0x0044BE30u, NativeCallingConvention::fastcall_call},
    {0x0044BEC0u, NativeCallingConvention::fastcall_call},
    {0x0044BF00u, NativeCallingConvention::cdecl_call},
    {0x0044BF50u, NativeCallingConvention::fastcall_call},
    {0x0044BF90u, NativeCallingConvention::cdecl_call},
    {0x0044BFE0u, NativeCallingConvention::fastcall_call},
    {0x0044C020u, NativeCallingConvention::fastcall_call},
    {0x0044C0A0u, NativeCallingConvention::fastcall_call},
    {0x0044C0D0u, NativeCallingConvention::cdecl_call},
    {0x0044C0F0u, NativeCallingConvention::cdecl_call},
    {0x0044C110u, NativeCallingConvention::cdecl_call},
    {0x0044C160u, NativeCallingConvention::cdecl_call},
    {0x0044C1D0u, NativeCallingConvention::fastcall_call},
    {0x0044C210u, NativeCallingConvention::fastcall_call},
    {0x0044C370u, NativeCallingConvention::fastcall_call},
    {0x0044C380u, NativeCallingConvention::cdecl_call},
    {0x0044C4C0u, NativeCallingConvention::cdecl_call},
    {0x0044C600u, NativeCallingConvention::cdecl_call},
    {0x0044C740u, NativeCallingConvention::cdecl_call},
    {0x0044C880u, NativeCallingConvention::cdecl_call},
    {0x0044C9C0u, NativeCallingConvention::cdecl_call},
    {0x0044CB00u, NativeCallingConvention::fastcall_call},
    {0x0044CB70u, NativeCallingConvention::cdecl_call},
    {0x0044CBF0u, NativeCallingConvention::cdecl_call},
    {0x0044CC70u, NativeCallingConvention::cdecl_call},
    {0x0044CD30u, NativeCallingConvention::fastcall_call},
    {0x0044D190u, NativeCallingConvention::fastcall_call},
    {0x0044D5A0u, NativeCallingConvention::cdecl_call},
    {0x0044D700u, NativeCallingConvention::cdecl_call},
    {0x0044D7E0u, NativeCallingConvention::fastcall_call},
    {0x0044D830u, NativeCallingConvention::fastcall_call},
    {0x0044D960u, NativeCallingConvention::fastcall_call},
    {0x0044DAC0u, NativeCallingConvention::cdecl_call},
    {0x0044DB50u, NativeCallingConvention::fastcall_call},
    {0x0044DC10u, NativeCallingConvention::fastcall_call},
    {0x0044DE30u, NativeCallingConvention::cdecl_call},
    {0x0044DF90u, NativeCallingConvention::fastcall_call},
    {0x0044E020u, NativeCallingConvention::cdecl_call},
    {0x0044E090u, NativeCallingConvention::fastcall_call},
    {0x0044E140u, NativeCallingConvention::fastcall_call},
    {0x0044E1B0u, NativeCallingConvention::cdecl_call},
    {0x0044E230u, NativeCallingConvention::cdecl_call},
    {0x0044E2B0u, NativeCallingConvention::thiscall_call},
    {0x0044E400u, NativeCallingConvention::stdcall_call},
    {0x0044E480u, NativeCallingConvention::thiscall_call},
    {0x0044E6A0u, NativeCallingConvention::fastcall_call},
    {0x0044E720u, NativeCallingConvention::fastcall_call},
    {0x0044EB00u, NativeCallingConvention::fastcall_call},
    {0x0044EBC0u, NativeCallingConvention::cdecl_call},
    {0x0044ECA0u, NativeCallingConvention::thiscall_call},
    {0x0044ED70u, NativeCallingConvention::fastcall_call},
    {0x0044EE70u, NativeCallingConvention::fastcall_call},
    {0x0044EF20u, NativeCallingConvention::fastcall_call},
    {0x0044EFE0u, NativeCallingConvention::fastcall_call},
    {0x0044F0F0u, NativeCallingConvention::fastcall_call},
    {0x0044F240u, NativeCallingConvention::fastcall_call},
    {0x0044F370u, NativeCallingConvention::fastcall_call},
    {0x0044F4C0u, NativeCallingConvention::fastcall_call},
    {0x0044F500u, NativeCallingConvention::cdecl_call},
    {0x0044F740u, NativeCallingConvention::fastcall_call},
    {0x0044F800u, NativeCallingConvention::fastcall_call},
    {0x0044F870u, NativeCallingConvention::fastcall_call},
    {0x0044F940u, NativeCallingConvention::fastcall_call},
    {0x0044F9E0u, NativeCallingConvention::fastcall_call},
    {0x0044FA00u, NativeCallingConvention::fastcall_call},
    {0x0044FA20u, NativeCallingConvention::fastcall_call},
    {0x0044FA50u, NativeCallingConvention::fastcall_call},
    {0x0044FA70u, NativeCallingConvention::fastcall_call},
    {0x0044FC60u, NativeCallingConvention::fastcall_call},
    {0x0044FCB0u, NativeCallingConvention::cdecl_call},
    {0x0044FCD0u, NativeCallingConvention::fastcall_call},
    {0x0044FF80u, NativeCallingConvention::fastcall_call},
    {0x004501C0u, NativeCallingConvention::fastcall_call},
    {0x00450260u, NativeCallingConvention::cdecl_call},
    {0x00450A00u, NativeCallingConvention::cdecl_call},
    {0x00450AB0u, NativeCallingConvention::cdecl_call},
    {0x00450B30u, NativeCallingConvention::fastcall_call},
    {0x00450DD0u, NativeCallingConvention::fastcall_call},
    {0x00451100u, NativeCallingConvention::fastcall_call},
    {0x00451390u, NativeCallingConvention::fastcall_call},
    {0x00451460u, NativeCallingConvention::fastcall_call},
    {0x00451570u, NativeCallingConvention::fastcall_call},
    {0x00451580u, NativeCallingConvention::cdecl_call},
    {0x004517D0u, NativeCallingConvention::cdecl_call},
    {0x00451890u, NativeCallingConvention::cdecl_call},
    {0x004518E0u, NativeCallingConvention::cdecl_call},
    {0x00451990u, NativeCallingConvention::fastcall_call},
    {0x004519B0u, NativeCallingConvention::cdecl_call},
    {0x004519D0u, NativeCallingConvention::cdecl_call},
    {0x00451A30u, NativeCallingConvention::fastcall_call},
    {0x00451A40u, NativeCallingConvention::stdcall_call},
    {0x00451B40u, NativeCallingConvention::cdecl_call},
    {0x00451CF0u, NativeCallingConvention::thiscall_call},
    {0x00451D20u, NativeCallingConvention::thiscall_call},
    {0x00451D50u, NativeCallingConvention::thiscall_call},
    {0x00451D90u, NativeCallingConvention::thiscall_call},
    {0x00451DC0u, NativeCallingConvention::cdecl_call},
    {0x00451E00u, NativeCallingConvention::cdecl_call},
    {0x00451EB0u, NativeCallingConvention::cdecl_call},
    {0x004526F0u, NativeCallingConvention::fastcall_call},
    {0x00452A00u, NativeCallingConvention::fastcall_call},
    {0x00452B60u, NativeCallingConvention::fastcall_call},
    {0x00453A20u, NativeCallingConvention::fastcall_call},
    {0x00453D00u, NativeCallingConvention::fastcall_call},
    {0x00454410u, NativeCallingConvention::fastcall_call},
    {0x004549B0u, NativeCallingConvention::fastcall_call},
    {0x00454A40u, NativeCallingConvention::fastcall_call},
    {0x00454BA0u, NativeCallingConvention::fastcall_call},
    {0x00454DC0u, NativeCallingConvention::fastcall_call},
    {0x00454E30u, NativeCallingConvention::fastcall_call},
    {0x00454ED0u, NativeCallingConvention::fastcall_call},
    {0x00454F70u, NativeCallingConvention::fastcall_call},
    {0x00454FF0u, NativeCallingConvention::fastcall_call},
    {0x00455580u, NativeCallingConvention::fastcall_call},
    {0x004556B0u, NativeCallingConvention::fastcall_call},
    {0x004557C0u, NativeCallingConvention::fastcall_call},
    {0x00455820u, NativeCallingConvention::fastcall_call},
    {0x004558A0u, NativeCallingConvention::fastcall_call},
    {0x00455C20u, NativeCallingConvention::fastcall_call},
    {0x00455D00u, NativeCallingConvention::fastcall_call},
    {0x00455D80u, NativeCallingConvention::fastcall_call},
    {0x00455E00u, NativeCallingConvention::fastcall_call},
    {0x00455E40u, NativeCallingConvention::fastcall_call},
    {0x00455F00u, NativeCallingConvention::fastcall_call},
    {0x00455FD0u, NativeCallingConvention::fastcall_call},
    {0x00456010u, NativeCallingConvention::cdecl_call},
    {0x00456040u, NativeCallingConvention::fastcall_call},
    {0x004560A0u, NativeCallingConvention::fastcall_call},
    {0x00456100u, NativeCallingConvention::fastcall_call},
    {0x004562D0u, NativeCallingConvention::cdecl_call},
    {0x004563A0u, NativeCallingConvention::fastcall_call},
    {0x00456450u, NativeCallingConvention::cdecl_call},
    {0x004564A0u, NativeCallingConvention::fastcall_call},
    {0x00456760u, NativeCallingConvention::fastcall_call},
    {0x00456880u, NativeCallingConvention::fastcall_call},
    {0x00456A90u, NativeCallingConvention::cdecl_call},
    {0x00456C20u, NativeCallingConvention::cdecl_call},
    {0x00456D60u, NativeCallingConvention::fastcall_call},
    {0x00456E20u, NativeCallingConvention::fastcall_call},
    {0x00457020u, NativeCallingConvention::cdecl_call},
    {0x004570A0u, NativeCallingConvention::fastcall_call},
    {0x004571F0u, NativeCallingConvention::cdecl_call},
    {0x00457370u, NativeCallingConvention::fastcall_call},
    {0x00457490u, NativeCallingConvention::cdecl_call},
    {0x00457510u, NativeCallingConvention::fastcall_call},
    {0x00457840u, NativeCallingConvention::thiscall_call},
    {0x00457E80u, NativeCallingConvention::cdecl_call},
    {0x00458E80u, NativeCallingConvention::fastcall_call},
    {0x00459080u, NativeCallingConvention::fastcall_call},
    {0x00459150u, NativeCallingConvention::fastcall_call},
    {0x00459370u, NativeCallingConvention::cdecl_call},
    {0x004593C0u, NativeCallingConvention::fastcall_call},
    {0x00459420u, NativeCallingConvention::fastcall_call},
    {0x00459530u, NativeCallingConvention::fastcall_call},
    {0x004595F0u, NativeCallingConvention::cdecl_call},
    {0x00459B10u, NativeCallingConvention::fastcall_call},
    {0x00459CB0u, NativeCallingConvention::fastcall_call},
    {0x00459D10u, NativeCallingConvention::fastcall_call},
    {0x00459DC0u, NativeCallingConvention::fastcall_call},
    {0x00459E40u, NativeCallingConvention::cdecl_call},
    {0x00459FA0u, NativeCallingConvention::cdecl_call},
    {0x0045A8E0u, NativeCallingConvention::fastcall_call},
    {0x0045A9C0u, NativeCallingConvention::fastcall_call},
    {0x0045AA50u, NativeCallingConvention::cdecl_call},
    {0x0045AC40u, NativeCallingConvention::fastcall_call},
    {0x0045ACF0u, NativeCallingConvention::fastcall_call},
    {0x0045AE50u, NativeCallingConvention::fastcall_call},
    {0x0045AFB0u, NativeCallingConvention::cdecl_call},
    {0x0045B060u, NativeCallingConvention::fastcall_call},
    {0x0045B370u, NativeCallingConvention::fastcall_call},
    {0x0045B620u, NativeCallingConvention::fastcall_call},
    {0x0045BC60u, NativeCallingConvention::cdecl_call},
    {0x0045BE50u, NativeCallingConvention::fastcall_call},
    {0x0045C230u, NativeCallingConvention::cdecl_call},
    {0x0045CB30u, NativeCallingConvention::fastcall_call},
    {0x0045CBB0u, NativeCallingConvention::cdecl_call},
    {0x0045CC30u, NativeCallingConvention::fastcall_call},
    {0x0045CD70u, NativeCallingConvention::fastcall_call},
    {0x0045CF00u, NativeCallingConvention::fastcall_call},
    {0x0045D020u, NativeCallingConvention::fastcall_call},
    {0x0045D140u, NativeCallingConvention::fastcall_call},
    {0x0045D280u, NativeCallingConvention::fastcall_call},
    {0x0045D3C0u, NativeCallingConvention::fastcall_call},
    {0x0045D4E0u, NativeCallingConvention::fastcall_call},
    {0x0045D840u, NativeCallingConvention::fastcall_call},
    {0x0045DA60u, NativeCallingConvention::fastcall_call},
    {0x0045DC60u, NativeCallingConvention::fastcall_call},
    {0x0045DCD0u, NativeCallingConvention::fastcall_call},
    {0x0045E560u, NativeCallingConvention::cdecl_call},
    {0x0045E660u, NativeCallingConvention::fastcall_call},
    {0x0045EB60u, NativeCallingConvention::fastcall_call},
    {0x0045EBE0u, NativeCallingConvention::fastcall_call},
    {0x0045ED20u, NativeCallingConvention::fastcall_call},
    {0x0045EF20u, NativeCallingConvention::cdecl_call},
    {0x0045F060u, NativeCallingConvention::fastcall_call},
    {0x0045F760u, NativeCallingConvention::fastcall_call},
    {0x0045F920u, NativeCallingConvention::fastcall_call},
    {0x0045FAE0u, NativeCallingConvention::fastcall_call},
    {0x0045FCA0u, NativeCallingConvention::fastcall_call},
    {0x0045FE00u, NativeCallingConvention::fastcall_call},
    {0x0045FF60u, NativeCallingConvention::fastcall_call},
    {0x004600C0u, NativeCallingConvention::fastcall_call},
    {0x00460110u, NativeCallingConvention::fastcall_call},
    {0x004601F0u, NativeCallingConvention::fastcall_call},
    {0x00460460u, NativeCallingConvention::fastcall_call},
    {0x00460570u, NativeCallingConvention::cdecl_call},
    {0x00460C90u, NativeCallingConvention::fastcall_call},
    {0x00460D50u, NativeCallingConvention::fastcall_call},
    {0x00461170u, NativeCallingConvention::fastcall_call},
    {0x00461220u, NativeCallingConvention::cdecl_call},
    {0x004614E0u, NativeCallingConvention::fastcall_call},
    {0x004615E0u, NativeCallingConvention::fastcall_call},
    {0x00461700u, NativeCallingConvention::fastcall_call},
    {0x004617A0u, NativeCallingConvention::cdecl_call},
    {0x00461DD0u, NativeCallingConvention::fastcall_call},
    {0x00461FD0u, NativeCallingConvention::fastcall_call},
    {0x004623C0u, NativeCallingConvention::cdecl_call},
    {0x00462400u, NativeCallingConvention::cdecl_call},
    {0x00462690u, NativeCallingConvention::cdecl_call},
    {0x00462740u, NativeCallingConvention::cdecl_call},
    {0x00462A90u, NativeCallingConvention::cdecl_call},
    {0x00462F00u, NativeCallingConvention::fastcall_call},
    {0x00463020u, NativeCallingConvention::fastcall_call},
    {0x004634E0u, NativeCallingConvention::fastcall_call},
    {0x00463B30u, NativeCallingConvention::fastcall_call},
    {0x00463EC0u, NativeCallingConvention::cdecl_call},
    {0x00464340u, NativeCallingConvention::cdecl_call},
    {0x00464600u, NativeCallingConvention::fastcall_call},
    {0x00464AA0u, NativeCallingConvention::fastcall_call},
    {0x00464BA0u, NativeCallingConvention::cdecl_call},
    {0x00465B80u, NativeCallingConvention::fastcall_call},
    {0x004676F0u, NativeCallingConvention::cdecl_call},
    {0x00467910u, NativeCallingConvention::fastcall_call},
    {0x00467A70u, NativeCallingConvention::cdecl_call},
    {0x00467E70u, NativeCallingConvention::fastcall_call},
    {0x00468050u, NativeCallingConvention::fastcall_call},
    {0x004681A0u, NativeCallingConvention::cdecl_call},
    {0x00468310u, NativeCallingConvention::cdecl_call},
    {0x00468750u, NativeCallingConvention::fastcall_call},
    {0x004689E0u, NativeCallingConvention::fastcall_call},
    {0x00468B40u, NativeCallingConvention::cdecl_call},
    {0x00468BD0u, NativeCallingConvention::cdecl_call},
    {0x00468D30u, NativeCallingConvention::fastcall_call},
    {0x00468E50u, NativeCallingConvention::fastcall_call},
    {0x00469090u, NativeCallingConvention::fastcall_call},
    {0x0046A070u, NativeCallingConvention::cdecl_call},
    {0x0046B7D0u, NativeCallingConvention::thiscall_call},
    {0x0046B9E0u, NativeCallingConvention::fastcall_call},
    {0x0046BD40u, NativeCallingConvention::fastcall_call},
    {0x0046C0B0u, NativeCallingConvention::fastcall_call},
    {0x0046CBA0u, NativeCallingConvention::fastcall_call},
    {0x0046D240u, NativeCallingConvention::fastcall_call},
    {0x0046D270u, NativeCallingConvention::fastcall_call},
    {0x0046D6A0u, NativeCallingConvention::cdecl_call},
    {0x0046D8B0u, NativeCallingConvention::fastcall_call},
    {0x0046DC30u, NativeCallingConvention::fastcall_call},
    {0x0046DD80u, NativeCallingConvention::cdecl_call},
    {0x0046DED0u, NativeCallingConvention::fastcall_call},
    {0x0046EC60u, NativeCallingConvention::cdecl_call},
    {0x0046EF60u, NativeCallingConvention::cdecl_call},
    {0x0046F280u, NativeCallingConvention::thiscall_call},
    {0x00470350u, NativeCallingConvention::fastcall_call},
    {0x00470640u, NativeCallingConvention::thiscall_call},
    {0x00470B80u, NativeCallingConvention::fastcall_call},
    {0x00470DA0u, NativeCallingConvention::cdecl_call},
    {0x004710A0u, NativeCallingConvention::fastcall_call},
    {0x00471E70u, NativeCallingConvention::fastcall_call},
    {0x004731A0u, NativeCallingConvention::fastcall_call},
    {0x004731C0u, NativeCallingConvention::fastcall_call},
    {0x00473A30u, NativeCallingConvention::thiscall_call},
    {0x00473C20u, NativeCallingConvention::fastcall_call},
    {0x00474120u, NativeCallingConvention::fastcall_call},
    {0x004745C0u, NativeCallingConvention::thiscall_call},
    {0x004748E0u, NativeCallingConvention::thiscall_call},
    {0x00475240u, NativeCallingConvention::thiscall_call},
    {0x00475430u, NativeCallingConvention::fastcall_call},
    {0x004755E0u, NativeCallingConvention::fastcall_call},
    {0x00475A90u, NativeCallingConvention::thiscall_call},
    {0x00475DC0u, NativeCallingConvention::thiscall_call},
    {0x004766E0u, NativeCallingConvention::fastcall_call},
    {0x00476DE0u, NativeCallingConvention::cdecl_call},
    {0x00477020u, NativeCallingConvention::fastcall_call},
    {0x00477FB0u, NativeCallingConvention::fastcall_call},
    {0x004790C0u, NativeCallingConvention::cdecl_call},
    {0x00479530u, NativeCallingConvention::cdecl_call},
    {0x004797D0u, NativeCallingConvention::fastcall_call},
    {0x004798E0u, NativeCallingConvention::cdecl_call},
    {0x00479A30u, NativeCallingConvention::fastcall_call},
    {0x00479FD0u, NativeCallingConvention::thiscall_call},
    {0x0047A150u, NativeCallingConvention::fastcall_call},
    {0x0047AB30u, NativeCallingConvention::cdecl_call},
    {0x0047AFC0u, NativeCallingConvention::thiscall_call},
    {0x0047B3D0u, NativeCallingConvention::fastcall_call},
    {0x0047B8D0u, NativeCallingConvention::cdecl_call},
    {0x0047BD30u, NativeCallingConvention::fastcall_call},
    {0x0047C670u, NativeCallingConvention::fastcall_call},
    {0x0047C980u, NativeCallingConvention::cdecl_call},
    {0x0047CBA0u, NativeCallingConvention::cdecl_call},
    {0x0047CDA0u, NativeCallingConvention::cdecl_call},
    {0x0047D040u, NativeCallingConvention::cdecl_call},
    {0x0047D770u, NativeCallingConvention::thiscall_call},
    {0x0047D9C0u, NativeCallingConvention::thiscall_call},
    {0x0047DB30u, NativeCallingConvention::fastcall_call},
    {0x0047DB70u, NativeCallingConvention::fastcall_call},
    {0x0047E0F0u, NativeCallingConvention::fastcall_call},
    {0x0047E180u, NativeCallingConvention::thiscall_call},
    {0x0047E1C0u, NativeCallingConvention::thiscall_call},
    {0x0047E4A0u, NativeCallingConvention::cdecl_call},
    {0x0047E520u, NativeCallingConvention::thiscall_call},
    {0x0047E700u, NativeCallingConvention::thiscall_call},
    {0x0047E760u, NativeCallingConvention::fastcall_call},
    {0x0047E850u, NativeCallingConvention::fastcall_call},
    {0x0047E870u, NativeCallingConvention::fastcall_call},
    {0x0047E900u, NativeCallingConvention::fastcall_call},
    {0x0047E960u, NativeCallingConvention::cdecl_call},
    {0x0047E990u, NativeCallingConvention::cdecl_call},
    {0x0047EA20u, NativeCallingConvention::fastcall_call},
    {0x0047EA60u, NativeCallingConvention::fastcall_call},
    {0x0047EA90u, NativeCallingConvention::fastcall_call},
    {0x0047EAC0u, NativeCallingConvention::fastcall_call},
    {0x0047EB20u, NativeCallingConvention::fastcall_call},
    {0x0047EBA0u, NativeCallingConvention::fastcall_call},
    {0x0047EBB0u, NativeCallingConvention::thiscall_call},
    {0x0047EC40u, NativeCallingConvention::thiscall_call},
    {0x0047ED10u, NativeCallingConvention::fastcall_call},
    {0x0047ED30u, NativeCallingConvention::fastcall_call},
    {0x0047ED40u, NativeCallingConvention::thiscall_call},
    {0x0047EDB0u, NativeCallingConvention::fastcall_call},
    {0x0047EDD0u, NativeCallingConvention::fastcall_call},
    {0x0047EEE0u, NativeCallingConvention::thiscall_call},
    {0x0047F1D0u, NativeCallingConvention::fastcall_call},
    {0x0047F210u, NativeCallingConvention::cdecl_call},
    {0x0047F230u, NativeCallingConvention::cdecl_call},
    {0x0047F240u, NativeCallingConvention::cdecl_call},
    {0x0047F2E0u, NativeCallingConvention::fastcall_call},
    {0x0047F3C0u, NativeCallingConvention::fastcall_call},
    {0x0047F450u, NativeCallingConvention::fastcall_call},
    {0x0047F4D0u, NativeCallingConvention::thiscall_call},
    {0x0047F5A0u, NativeCallingConvention::cdecl_call},
    {0x0047F5C0u, NativeCallingConvention::cdecl_call},
    {0x0047F6B0u, NativeCallingConvention::cdecl_call},
    {0x0047F6C0u, NativeCallingConvention::fastcall_call},
    {0x0047F6E0u, NativeCallingConvention::fastcall_call},
    {0x0047F730u, NativeCallingConvention::fastcall_call},
    {0x0047F750u, NativeCallingConvention::fastcall_call},
    {0x0047F770u, NativeCallingConvention::fastcall_call},
    {0x0047F7B0u, NativeCallingConvention::cdecl_call},
    {0x0047F820u, NativeCallingConvention::thiscall_call},
    {0x0047F8A0u, NativeCallingConvention::fastcall_call},
    {0x0047F900u, NativeCallingConvention::fastcall_call},
    {0x0047FA20u, NativeCallingConvention::thiscall_call},
    {0x0047FA50u, NativeCallingConvention::cdecl_call},
    {0x0047FB10u, NativeCallingConvention::cdecl_call},
    {0x0047FBA0u, NativeCallingConvention::cdecl_call},
    {0x0047FBF0u, NativeCallingConvention::cdecl_call},
    {0x0047FDC0u, NativeCallingConvention::cdecl_call},
    {0x0047FEB0u, NativeCallingConvention::fastcall_call},
    {0x0047FED0u, NativeCallingConvention::fastcall_call},
    {0x0047FF70u, NativeCallingConvention::cdecl_call},
    {0x00480090u, NativeCallingConvention::fastcall_call},
    {0x00480110u, NativeCallingConvention::cdecl_call},
    {0x004801E0u, NativeCallingConvention::cdecl_call},
    {0x00480220u, NativeCallingConvention::cdecl_call},
    {0x00480280u, NativeCallingConvention::fastcall_call},
    {0x00480300u, NativeCallingConvention::cdecl_call},
    {0x00480380u, NativeCallingConvention::fastcall_call},
    {0x00480390u, NativeCallingConvention::fastcall_call},
    {0x004803B0u, NativeCallingConvention::fastcall_call},
    {0x00480410u, NativeCallingConvention::fastcall_call},
    {0x00480430u, NativeCallingConvention::thiscall_call},
    {0x004805D0u, NativeCallingConvention::fastcall_call},
    {0x00480630u, NativeCallingConvention::fastcall_call},
    {0x00480660u, NativeCallingConvention::fastcall_call},
    {0x00480F10u, NativeCallingConvention::fastcall_call},
    {0x00480FA0u, NativeCallingConvention::fastcall_call},
    {0x00481120u, NativeCallingConvention::cdecl_call},
    {0x00481150u, NativeCallingConvention::cdecl_call},
    {0x00481180u, NativeCallingConvention::cdecl_call},
    {0x004811B0u, NativeCallingConvention::cdecl_call},
    {0x00481200u, NativeCallingConvention::cdecl_call},
    {0x00481250u, NativeCallingConvention::cdecl_call},
    {0x004812A0u, NativeCallingConvention::cdecl_call},
    {0x00481300u, NativeCallingConvention::cdecl_call},
    {0x00481360u, NativeCallingConvention::fastcall_call},
    {0x004813D0u, NativeCallingConvention::fastcall_call},
    {0x004815C0u, NativeCallingConvention::cdecl_call},
    {0x004815D0u, NativeCallingConvention::fastcall_call},
    {0x004815E0u, NativeCallingConvention::fastcall_call},
    {0x00482170u, NativeCallingConvention::fastcall_call},
    {0x004822F0u, NativeCallingConvention::fastcall_call},
    {0x004825A0u, NativeCallingConvention::fastcall_call},
    {0x004826C0u, NativeCallingConvention::fastcall_call},
    {0x00482720u, NativeCallingConvention::fastcall_call},
    {0x00482780u, NativeCallingConvention::fastcall_call},
    {0x004827E0u, NativeCallingConvention::cdecl_call},
    {0x00482A30u, NativeCallingConvention::cdecl_call},
    {0x00482A50u, NativeCallingConvention::cdecl_call},
    {0x00482B00u, NativeCallingConvention::fastcall_call},
    {0x00482CE0u, NativeCallingConvention::fastcall_call},
    {0x00483060u, NativeCallingConvention::fastcall_call},
    {0x00483490u, NativeCallingConvention::fastcall_call},
    {0x004834C0u, NativeCallingConvention::fastcall_call},
    {0x004835D0u, NativeCallingConvention::fastcall_call},
    {0x004836A0u, NativeCallingConvention::fastcall_call},
    {0x00483880u, NativeCallingConvention::fastcall_call},
    {0x00483920u, NativeCallingConvention::fastcall_call},
    {0x00483A80u, NativeCallingConvention::thiscall_call},
    {0x00483B00u, NativeCallingConvention::fastcall_call},
    {0x00483B60u, NativeCallingConvention::thiscall_call},
    {0x00483BF0u, NativeCallingConvention::thiscall_call},
    {0x00483C80u, NativeCallingConvention::thiscall_call},
    {0x00483F40u, NativeCallingConvention::fastcall_call},
    {0x00483F50u, NativeCallingConvention::fastcall_call},
    {0x00484420u, NativeCallingConvention::thiscall_call},
    {0x00484440u, NativeCallingConvention::fastcall_call},
    {0x004844D0u, NativeCallingConvention::thiscall_call},
    {0x00484620u, NativeCallingConvention::thiscall_call},
    {0x004846B0u, NativeCallingConvention::thiscall_call},
    {0x00484A10u, NativeCallingConvention::thiscall_call},
    {0x00484A80u, NativeCallingConvention::thiscall_call},
    {0x00485250u, NativeCallingConvention::thiscall_call},
    {0x00485430u, NativeCallingConvention::fastcall_call},
    {0x004856D0u, NativeCallingConvention::fastcall_call},
    {0x00485AF0u, NativeCallingConvention::thiscall_call},
    {0x00486390u, NativeCallingConvention::fastcall_call},
    {0x004865F0u, NativeCallingConvention::thiscall_call},
    {0x004866A0u, NativeCallingConvention::thiscall_call},
    {0x00487220u, NativeCallingConvention::thiscall_call},
    {0x00487410u, NativeCallingConvention::fastcall_call},
    {0x00487D50u, NativeCallingConvention::thiscall_call},
    {0x00489810u, NativeCallingConvention::fastcall_call},
    {0x00489830u, NativeCallingConvention::fastcall_call},
    {0x004898B0u, NativeCallingConvention::fastcall_call},
    {0x00489BA0u, NativeCallingConvention::fastcall_call},
    {0x00489D50u, NativeCallingConvention::fastcall_call},
    {0x00489DE0u, NativeCallingConvention::thiscall_call},
    {0x00489EF0u, NativeCallingConvention::thiscall_call},
    {0x00489F30u, NativeCallingConvention::fastcall_call},
    {0x0048A1A0u, NativeCallingConvention::fastcall_call},
    {0x0048A1C0u, NativeCallingConvention::fastcall_call},
    {0x0048A210u, NativeCallingConvention::fastcall_call},
    {0x0048A300u, NativeCallingConvention::fastcall_call},
    {0x0048A460u, NativeCallingConvention::fastcall_call},
    {0x0048A6A0u, NativeCallingConvention::fastcall_call},
    {0x0048A740u, NativeCallingConvention::fastcall_call},
    {0x0048B1F0u, NativeCallingConvention::fastcall_call},
    {0x0048B5E0u, NativeCallingConvention::fastcall_call},
    {0x0048B820u, NativeCallingConvention::thiscall_call},
    {0x0048B960u, NativeCallingConvention::fastcall_call},
    {0x0048B970u, NativeCallingConvention::fastcall_call},
    {0x0048BDB0u, NativeCallingConvention::thiscall_call},
    {0x0048BE40u, NativeCallingConvention::fastcall_call},
    {0x0048C570u, NativeCallingConvention::fastcall_call},
    {0x0048C670u, NativeCallingConvention::fastcall_call},
    {0x0048C730u, NativeCallingConvention::fastcall_call},
    {0x0048C860u, NativeCallingConvention::thiscall_call},
    {0x0048CA90u, NativeCallingConvention::thiscall_call},
    {0x0048CE10u, NativeCallingConvention::thiscall_call},
    {0x0048D170u, NativeCallingConvention::thiscall_call},
    {0x0048D390u, NativeCallingConvention::thiscall_call},
    {0x0048D450u, NativeCallingConvention::thiscall_call},
    {0x0048D580u, NativeCallingConvention::thiscall_call},
    {0x0048D9D0u, NativeCallingConvention::fastcall_call},
    {0x0048DA20u, NativeCallingConvention::fastcall_call},
    {0x0048DA70u, NativeCallingConvention::cdecl_call},
    {0x0048DB30u, NativeCallingConvention::cdecl_call},
    {0x0048DB70u, NativeCallingConvention::fastcall_call},
    {0x0048DBA0u, NativeCallingConvention::thiscall_call},
    {0x0048DBE0u, NativeCallingConvention::thiscall_call},
    {0x0048DC00u, NativeCallingConvention::thiscall_call},
    {0x0048DC80u, NativeCallingConvention::thiscall_call},
    {0x0048DCF0u, NativeCallingConvention::thiscall_call},
    {0x0048DD80u, NativeCallingConvention::thiscall_call},
    {0x0048DDB0u, NativeCallingConvention::thiscall_call},
    {0x0048DE70u, NativeCallingConvention::thiscall_call},
    {0x0048DF30u, NativeCallingConvention::cdecl_call},
    {0x0048DFB0u, NativeCallingConvention::fastcall_call},
    {0x0048E030u, NativeCallingConvention::fastcall_call},
    {0x0048E0A0u, NativeCallingConvention::thiscall_call},
    {0x0048E0E0u, NativeCallingConvention::fastcall_call},
    {0x0048E110u, NativeCallingConvention::thiscall_call},
    {0x0048E270u, NativeCallingConvention::thiscall_call},
    {0x0048E360u, NativeCallingConvention::thiscall_call},
    {0x0048E480u, NativeCallingConvention::thiscall_call},
    {0x0048E580u, NativeCallingConvention::fastcall_call},
    {0x0048E610u, NativeCallingConvention::fastcall_call},
    {0x0048E6A0u, NativeCallingConvention::thiscall_call},
    {0x0048E750u, NativeCallingConvention::thiscall_call},
    {0x0048E800u, NativeCallingConvention::cdecl_call},
    {0x0048E950u, NativeCallingConvention::fastcall_call},
    {0x0048EAC0u, NativeCallingConvention::thiscall_call},
    {0x0048EB20u, NativeCallingConvention::cdecl_call},
    {0x0048EB70u, NativeCallingConvention::cdecl_call},
    {0x0048EBC0u, NativeCallingConvention::thiscall_call},
    {0x0048EDB0u, NativeCallingConvention::thiscall_call},
    {0x0048EE60u, NativeCallingConvention::thiscall_call},
    {0x0048EFE0u, NativeCallingConvention::fastcall_call},
    {0x0048F090u, NativeCallingConvention::cdecl_call},
    {0x0048F0F0u, NativeCallingConvention::thiscall_call},
    {0x0048F1B0u, NativeCallingConvention::thiscall_call},
    {0x0048F25Du, NativeCallingConvention::cdecl_call},
    {0x0048F38Du, NativeCallingConvention::cdecl_call},
    {0x0048F420u, NativeCallingConvention::fastcall_call},
    {0x0048F5E0u, NativeCallingConvention::fastcall_call},
    {0x0048F6C0u, NativeCallingConvention::thiscall_call},
    {0x0048F7E0u, NativeCallingConvention::cdecl_call},
    {0x0048F880u, NativeCallingConvention::fastcall_call},
    {0x0048FA20u, NativeCallingConvention::fastcall_call},
    {0x0048FBD0u, NativeCallingConvention::cdecl_call},
    {0x0048FDC0u, NativeCallingConvention::cdecl_call},
    {0x0048FEF0u, NativeCallingConvention::cdecl_call},
    {0x0048FF40u, NativeCallingConvention::cdecl_call},
    {0x00490040u, NativeCallingConvention::fastcall_call},
    {0x00490190u, NativeCallingConvention::fastcall_call},
    {0x004901D0u, NativeCallingConvention::fastcall_call},
    {0x00490240u, NativeCallingConvention::thiscall_call},
    {0x00490280u, NativeCallingConvention::fastcall_call},
    {0x00490350u, NativeCallingConvention::cdecl_call},
    {0x004903C0u, NativeCallingConvention::thiscall_call},
    {0x00490410u, NativeCallingConvention::fastcall_call},
    {0x00490530u, NativeCallingConvention::fastcall_call},
    {0x004905D0u, NativeCallingConvention::fastcall_call},
    {0x00490730u, NativeCallingConvention::fastcall_call},
    {0x00490870u, NativeCallingConvention::fastcall_call},
    {0x00490A70u, NativeCallingConvention::fastcall_call},
    {0x00490C50u, NativeCallingConvention::fastcall_call},
    {0x00491500u, NativeCallingConvention::fastcall_call},
    {0x00491C80u, NativeCallingConvention::fastcall_call},
    {0x00491D00u, NativeCallingConvention::fastcall_call},
    {0x00492010u, NativeCallingConvention::fastcall_call},
    {0x004923E0u, NativeCallingConvention::fastcall_call},
    {0x004927C0u, NativeCallingConvention::fastcall_call},
    {0x00492B40u, NativeCallingConvention::cdecl_call},
    {0x004930A0u, NativeCallingConvention::fastcall_call},
    {0x00493430u, NativeCallingConvention::fastcall_call},
    {0x00493920u, NativeCallingConvention::fastcall_call},
    {0x00493BF0u, NativeCallingConvention::fastcall_call},
    {0x00493C00u, NativeCallingConvention::fastcall_call},
    {0x00493C50u, NativeCallingConvention::fastcall_call},
    {0x00493D20u, NativeCallingConvention::cdecl_call},
    {0x00493D70u, NativeCallingConvention::thiscall_call},
    {0x00493E10u, NativeCallingConvention::thiscall_call},
    {0x00493F70u, NativeCallingConvention::thiscall_call},
    {0x00494030u, NativeCallingConvention::thiscall_call},
    {0x00494150u, NativeCallingConvention::thiscall_call},
    {0x004942C0u, NativeCallingConvention::thiscall_call},
    {0x00494360u, NativeCallingConvention::thiscall_call},
    {0x00494400u, NativeCallingConvention::thiscall_call},
    {0x004944A0u, NativeCallingConvention::thiscall_call},
    {0x00494550u, NativeCallingConvention::thiscall_call},
    {0x004945B0u, NativeCallingConvention::fastcall_call},
    {0x004945C0u, NativeCallingConvention::thiscall_call},
    {0x00494710u, NativeCallingConvention::thiscall_call},
    {0x004947E0u, NativeCallingConvention::fastcall_call},
    {0x00494850u, NativeCallingConvention::thiscall_call},
    {0x004948B0u, NativeCallingConvention::fastcall_call},
    {0x004948C0u, NativeCallingConvention::thiscall_call},
    {0x00494900u, NativeCallingConvention::thiscall_call},
    {0x00494920u, NativeCallingConvention::thiscall_call},
    {0x00494940u, NativeCallingConvention::fastcall_call},
    {0x00494A10u, NativeCallingConvention::thiscall_call},
    {0x00495010u, NativeCallingConvention::thiscall_call},
    {0x00495090u, NativeCallingConvention::cdecl_call},
    {0x00495360u, NativeCallingConvention::cdecl_call},
    {0x00495490u, NativeCallingConvention::cdecl_call},
    {0x00495570u, NativeCallingConvention::thiscall_call},
    {0x004958C0u, NativeCallingConvention::thiscall_call},
    {0x00495910u, NativeCallingConvention::fastcall_call},
    {0x004959B0u, NativeCallingConvention::thiscall_call},
    {0x00495A30u, NativeCallingConvention::thiscall_call},
    {0x00495AC0u, NativeCallingConvention::thiscall_call},
    {0x00495B30u, NativeCallingConvention::fastcall_call},
    {0x00495C80u, NativeCallingConvention::thiscall_call},
    {0x00495DD0u, NativeCallingConvention::thiscall_call},
    {0x00495E50u, NativeCallingConvention::thiscall_call},
    {0x00495ED0u, NativeCallingConvention::thiscall_call},
    {0x00495F40u, NativeCallingConvention::thiscall_call},
    {0x004963F0u, NativeCallingConvention::fastcall_call},
    {0x00496650u, NativeCallingConvention::thiscall_call},
    {0x00496870u, NativeCallingConvention::fastcall_call},
    {0x004968C0u, NativeCallingConvention::thiscall_call},
    {0x00496960u, NativeCallingConvention::thiscall_call},
    {0x00496A40u, NativeCallingConvention::thiscall_call},
    {0x00496BD0u, NativeCallingConvention::thiscall_call},
    {0x00496E00u, NativeCallingConvention::thiscall_call},
    {0x00496F00u, NativeCallingConvention::fastcall_call},
    {0x00496FE0u, NativeCallingConvention::fastcall_call},
    {0x00497040u, NativeCallingConvention::fastcall_call},
    {0x00497150u, NativeCallingConvention::fastcall_call},
    {0x00497370u, NativeCallingConvention::cdecl_call},
    {0x00497400u, NativeCallingConvention::fastcall_call},
    {0x00497470u, NativeCallingConvention::cdecl_call},
    {0x004974B0u, NativeCallingConvention::fastcall_call},
    {0x00497560u, NativeCallingConvention::fastcall_call},
    {0x00497770u, NativeCallingConvention::thiscall_call},
    {0x004977E0u, NativeCallingConvention::fastcall_call},
    {0x00497910u, NativeCallingConvention::fastcall_call},
    {0x00497930u, NativeCallingConvention::fastcall_call},
    {0x00497970u, NativeCallingConvention::cdecl_call},
    {0x00497980u, NativeCallingConvention::fastcall_call},
    {0x004979A0u, NativeCallingConvention::thiscall_call},
    {0x004979E0u, NativeCallingConvention::thiscall_call},
    {0x00497A40u, NativeCallingConvention::thiscall_call},
    {0x00497AA0u, NativeCallingConvention::thiscall_call},
    {0x00497B00u, NativeCallingConvention::cdecl_call},
    {0x00497B60u, NativeCallingConvention::fastcall_call},
    {0x00497B80u, NativeCallingConvention::thiscall_call},
    {0x00497CB0u, NativeCallingConvention::thiscall_call},
    {0x00497E00u, NativeCallingConvention::fastcall_call},
    {0x00497ED0u, NativeCallingConvention::cdecl_call},
    {0x00498060u, NativeCallingConvention::fastcall_call},
    {0x004980A0u, NativeCallingConvention::fastcall_call},
    {0x004980F0u, NativeCallingConvention::cdecl_call},
    {0x004981F0u, NativeCallingConvention::cdecl_call},
    {0x00498240u, NativeCallingConvention::thiscall_call},
    {0x004982F0u, NativeCallingConvention::fastcall_call},
    {0x00498300u, NativeCallingConvention::cdecl_call},
    {0x00498310u, NativeCallingConvention::thiscall_call},
    {0x004983A0u, NativeCallingConvention::thiscall_call},
    {0x00498400u, NativeCallingConvention::fastcall_call},
    {0x00498420u, NativeCallingConvention::thiscall_call},
    {0x004984C0u, NativeCallingConvention::fastcall_call},
    {0x00498550u, NativeCallingConvention::fastcall_call},
    {0x004985E0u, NativeCallingConvention::thiscall_call},
    {0x00498660u, NativeCallingConvention::cdecl_call},
    {0x00498730u, NativeCallingConvention::cdecl_call},
    {0x00498860u, NativeCallingConvention::fastcall_call},
    {0x00498930u, NativeCallingConvention::fastcall_call},
    {0x00498AD0u, NativeCallingConvention::fastcall_call},
    {0x00498C30u, NativeCallingConvention::thiscall_call},
    {0x00498CE0u, NativeCallingConvention::fastcall_call},
    {0x00498CF0u, NativeCallingConvention::thiscall_call},
    {0x00498D90u, NativeCallingConvention::fastcall_call},
    {0x00498ED0u, NativeCallingConvention::fastcall_call},
    {0x00498F70u, NativeCallingConvention::fastcall_call},
    {0x00499070u, NativeCallingConvention::fastcall_call},
    {0x004990F0u, NativeCallingConvention::cdecl_call},
    {0x004991A0u, NativeCallingConvention::thiscall_call},
    {0x00499290u, NativeCallingConvention::thiscall_call},
    {0x00499730u, NativeCallingConvention::fastcall_call},
    {0x00499810u, NativeCallingConvention::cdecl_call},
    {0x004998A0u, NativeCallingConvention::fastcall_call},
    {0x00499980u, NativeCallingConvention::cdecl_call},
    {0x00499A60u, NativeCallingConvention::fastcall_call},
    {0x00499C90u, NativeCallingConvention::cdecl_call},
    {0x00499CD0u, NativeCallingConvention::fastcall_call},
    {0x00499D70u, NativeCallingConvention::fastcall_call},
    {0x00499E20u, NativeCallingConvention::fastcall_call},
    {0x00499EE0u, NativeCallingConvention::cdecl_call},
    {0x00499EF0u, NativeCallingConvention::fastcall_call},
    {0x00499F50u, NativeCallingConvention::fastcall_call},
    {0x00499FA0u, NativeCallingConvention::thiscall_call},
    {0x0049A020u, NativeCallingConvention::thiscall_call},
    {0x0049A100u, NativeCallingConvention::cdecl_call},
    {0x0049A1D0u, NativeCallingConvention::cdecl_call},
    {0x0049A260u, NativeCallingConvention::fastcall_call},
    {0x0049A490u, NativeCallingConvention::cdecl_call},
    {0x0049A4A0u, NativeCallingConvention::cdecl_call},
    {0x0049A4B0u, NativeCallingConvention::cdecl_call},
    {0x0049A4C0u, NativeCallingConvention::cdecl_call},
    {0x0049A4D0u, NativeCallingConvention::cdecl_call},
    {0x0049A550u, NativeCallingConvention::cdecl_call},
    {0x0049A670u, NativeCallingConvention::cdecl_call},
    {0x0049A690u, NativeCallingConvention::fastcall_call},
    {0x0049A6D0u, NativeCallingConvention::fastcall_call},
    {0x0049A730u, NativeCallingConvention::cdecl_call},
    {0x0049A890u, NativeCallingConvention::cdecl_call},
    {0x0049A920u, NativeCallingConvention::fastcall_call},
    {0x0049A950u, NativeCallingConvention::thiscall_call},
    {0x0049A9B0u, NativeCallingConvention::thiscall_call},
    {0x0049AA10u, NativeCallingConvention::cdecl_call},
    {0x0049B0B0u, NativeCallingConvention::fastcall_call},
    {0x0049B2B0u, NativeCallingConvention::thiscall_call},
    {0x0049B470u, NativeCallingConvention::fastcall_call},
    {0x0049B4D0u, NativeCallingConvention::thiscall_call},
    {0x0049B790u, NativeCallingConvention::cdecl_call},
    {0x0049B7F0u, NativeCallingConvention::cdecl_call},
    {0x0049B860u, NativeCallingConvention::fastcall_call},
    {0x0049BA10u, NativeCallingConvention::fastcall_call},
    {0x0049BAC0u, NativeCallingConvention::thiscall_call},
    {0x0049C460u, NativeCallingConvention::thiscall_call},
    {0x0049C510u, NativeCallingConvention::thiscall_call},
    {0x0049C640u, NativeCallingConvention::thiscall_call},
    {0x0049C6E0u, NativeCallingConvention::thiscall_call},
    {0x0049C820u, NativeCallingConvention::thiscall_call},
    {0x0049C8C0u, NativeCallingConvention::thiscall_call},
    {0x0049C980u, NativeCallingConvention::thiscall_call},
    {0x0049CA20u, NativeCallingConvention::thiscall_call},
    {0x0049CC90u, NativeCallingConvention::thiscall_call},
    {0x0049D010u, NativeCallingConvention::cdecl_call},
    {0x0049D090u, NativeCallingConvention::cdecl_call},
    {0x0049D100u, NativeCallingConvention::fastcall_call},
    {0x0049D1F0u, NativeCallingConvention::fastcall_call},
    {0x0049D200u, NativeCallingConvention::cdecl_call},
    {0x0049D220u, NativeCallingConvention::thiscall_call},
    {0x0049D2F0u, NativeCallingConvention::thiscall_call},
    {0x0049D370u, NativeCallingConvention::thiscall_call},
    {0x0049D3F0u, NativeCallingConvention::thiscall_call},
    {0x0049D470u, NativeCallingConvention::thiscall_call},
    {0x0049D520u, NativeCallingConvention::fastcall_call},
    {0x0049D560u, NativeCallingConvention::cdecl_call},
    {0x0049D590u, NativeCallingConvention::thiscall_call},
    {0x0049D5E0u, NativeCallingConvention::thiscall_call},
    {0x0049D6A0u, NativeCallingConvention::thiscall_call},
    {0x0049D710u, NativeCallingConvention::thiscall_call},
    {0x0049D780u, NativeCallingConvention::cdecl_call},
    {0x0049D820u, NativeCallingConvention::cdecl_call},
    {0x0049D910u, NativeCallingConvention::cdecl_call},
    {0x0049DA20u, NativeCallingConvention::thiscall_call},
    {0x0049DC00u, NativeCallingConvention::cdecl_call},
    {0x0049DC60u, NativeCallingConvention::fastcall_call},
    {0x0049DCA0u, NativeCallingConvention::fastcall_call},
    {0x0049DCD0u, NativeCallingConvention::thiscall_call},
    {0x0049DDABu, NativeCallingConvention::cdecl_call},
    {0x0049DE83u, NativeCallingConvention::cdecl_call},
    {0x0049DEA0u, NativeCallingConvention::thiscall_call},
    {0x0049DF00u, NativeCallingConvention::cdecl_call},
    {0x0049E490u, NativeCallingConvention::thiscall_call},
    {0x0049E500u, NativeCallingConvention::thiscall_call},
    {0x0049EC80u, NativeCallingConvention::thiscall_call},
    {0x0049ECD0u, NativeCallingConvention::fastcall_call},
    {0x0049ED60u, NativeCallingConvention::fastcall_call},
    {0x0049EDE0u, NativeCallingConvention::thiscall_call},
    {0x0049F1A0u, NativeCallingConvention::thiscall_call},
    {0x0049F1D0u, NativeCallingConvention::cdecl_call},
    {0x0049F230u, NativeCallingConvention::fastcall_call},
    {0x0049F510u, NativeCallingConvention::fastcall_call},
    {0x0049F5A0u, NativeCallingConvention::thiscall_call},
    {0x0049F5D0u, NativeCallingConvention::thiscall_call},
    {0x0049F5F0u, NativeCallingConvention::thiscall_call},
    {0x0049F690u, NativeCallingConvention::thiscall_call},
    {0x0049F730u, NativeCallingConvention::thiscall_call},
    {0x0049F7A0u, NativeCallingConvention::thiscall_call},
    {0x0049F9C0u, NativeCallingConvention::thiscall_call},
    {0x0049F9F0u, NativeCallingConvention::fastcall_call},
    {0x0049FA20u, NativeCallingConvention::fastcall_call},
    {0x0049FA40u, NativeCallingConvention::fastcall_call},
    {0x0049FAB0u, NativeCallingConvention::fastcall_call},
    {0x0049FB40u, NativeCallingConvention::fastcall_call},
    {0x0049FBD0u, NativeCallingConvention::thiscall_call},
    {0x0049FD20u, NativeCallingConvention::cdecl_call},
    {0x0049FDA0u, NativeCallingConvention::cdecl_call},
    {0x0049FF20u, NativeCallingConvention::thiscall_call},
    {0x004A0110u, NativeCallingConvention::thiscall_call},
    {0x004A01D0u, NativeCallingConvention::thiscall_call},
    {0x004A0270u, NativeCallingConvention::thiscall_call},
    {0x004A0330u, NativeCallingConvention::thiscall_call},
    {0x004A03B9u, NativeCallingConvention::cdecl_call},
    {0x004A0400u, NativeCallingConvention::thiscall_call},
    {0x004A052Fu, NativeCallingConvention::cdecl_call},
    {0x004A06E4u, NativeCallingConvention::cdecl_call},
    {0x004A0770u, NativeCallingConvention::cdecl_call},
    {0x004A0810u, NativeCallingConvention::thiscall_call},
    {0x004A0870u, NativeCallingConvention::thiscall_call},
    {0x004A0A40u, NativeCallingConvention::thiscall_call},
    {0x004A0D00u, NativeCallingConvention::thiscall_call},
    {0x004A0DB0u, NativeCallingConvention::fastcall_call},
    {0x004A0E60u, NativeCallingConvention::fastcall_call},
    {0x004A0ED0u, NativeCallingConvention::thiscall_call},
    {0x004A1200u, NativeCallingConvention::thiscall_call},
    {0x004A12C0u, NativeCallingConvention::thiscall_call},
    {0x004A1350u, NativeCallingConvention::fastcall_call},
    {0x004A13C0u, NativeCallingConvention::thiscall_call},
    {0x004A13E0u, NativeCallingConvention::fastcall_call},
    {0x004A1690u, NativeCallingConvention::thiscall_call},
    {0x004A1740u, NativeCallingConvention::fastcall_call},
    {0x004A17F0u, NativeCallingConvention::fastcall_call},
    {0x004A1860u, NativeCallingConvention::fastcall_call},
    {0x004A18E0u, NativeCallingConvention::fastcall_call},
    {0x004A1A20u, NativeCallingConvention::thiscall_call},
    {0x004A1AD0u, NativeCallingConvention::thiscall_call},
    {0x004A1B00u, NativeCallingConvention::thiscall_call},
    {0x004A1B70u, NativeCallingConvention::fastcall_call},
    {0x004A1DB0u, NativeCallingConvention::cdecl_call},
    {0x004A1DF0u, NativeCallingConvention::thiscall_call},
    {0x004A1E20u, NativeCallingConvention::fastcall_call},
    {0x004A1FA0u, NativeCallingConvention::fastcall_call},
    {0x004A2000u, NativeCallingConvention::fastcall_call},
    {0x004A2040u, NativeCallingConvention::fastcall_call},
    {0x004A21F0u, NativeCallingConvention::cdecl_call},
    {0x004A2280u, NativeCallingConvention::fastcall_call},
    {0x004A2670u, NativeCallingConvention::thiscall_call},
    {0x004A2740u, NativeCallingConvention::thiscall_call},
    {0x004A2810u, NativeCallingConvention::fastcall_call},
    {0x004A2D20u, NativeCallingConvention::fastcall_call},
    {0x004A2E00u, NativeCallingConvention::fastcall_call},
    {0x004A2FE0u, NativeCallingConvention::thiscall_call},
    {0x004A3000u, NativeCallingConvention::thiscall_call},
    {0x004A3400u, NativeCallingConvention::thiscall_call},
    {0x004A3990u, NativeCallingConvention::thiscall_call},
    {0x004A3B20u, NativeCallingConvention::thiscall_call},
    {0x004A3C50u, NativeCallingConvention::fastcall_call},
    {0x004A3D00u, NativeCallingConvention::cdecl_call},
    {0x004A3D60u, NativeCallingConvention::thiscall_call},
    {0x004A3DB0u, NativeCallingConvention::fastcall_call},
    {0x004A3E00u, NativeCallingConvention::fastcall_call},
    {0x004A3E30u, NativeCallingConvention::fastcall_call},
    {0x004A3EB1u, NativeCallingConvention::cdecl_call},
    {0x004A3EF0u, NativeCallingConvention::fastcall_call},
    {0x004A3F30u, NativeCallingConvention::fastcall_call},
    {0x004A3FB1u, NativeCallingConvention::cdecl_call},
    {0x004A3FF0u, NativeCallingConvention::thiscall_call},
    {0x004A40FAu, NativeCallingConvention::cdecl_call},
    {0x004A4110u, NativeCallingConvention::thiscall_call},
    {0x004A4130u, NativeCallingConvention::thiscall_call},
    {0x004A41B0u, NativeCallingConvention::fastcall_call},
    {0x004A41F0u, NativeCallingConvention::fastcall_call},
    {0x004A4250u, NativeCallingConvention::thiscall_call},
    {0x004A43D0u, NativeCallingConvention::thiscall_call},
    {0x004A44D0u, NativeCallingConvention::thiscall_call},
    {0x004A44F0u, NativeCallingConvention::thiscall_call},
    {0x004A4620u, NativeCallingConvention::fastcall_call},
    {0x004A4680u, NativeCallingConvention::thiscall_call},
    {0x004A48A0u, NativeCallingConvention::thiscall_call},
    {0x004A49E0u, NativeCallingConvention::fastcall_call},
    {0x004A4B10u, NativeCallingConvention::cdecl_call},
    {0x004A4B60u, NativeCallingConvention::thiscall_call},
    {0x004A4BE0u, NativeCallingConvention::thiscall_call},
    {0x004A4DB0u, NativeCallingConvention::thiscall_call},
    {0x004A4E10u, NativeCallingConvention::fastcall_call},
    {0x004A5260u, NativeCallingConvention::cdecl_call},
    {0x004A5270u, NativeCallingConvention::fastcall_call},
    {0x004A5330u, NativeCallingConvention::fastcall_call},
    {0x004A53E0u, NativeCallingConvention::fastcall_call},
    {0x004A5460u, NativeCallingConvention::cdecl_call},
    {0x004A5540u, NativeCallingConvention::fastcall_call},
    {0x004A55D0u, NativeCallingConvention::fastcall_call},
    {0x004A5600u, NativeCallingConvention::thiscall_call},
    {0x004A56E0u, NativeCallingConvention::fastcall_call},
    {0x004A57A0u, NativeCallingConvention::thiscall_call},
    {0x004A5800u, NativeCallingConvention::thiscall_call},
    {0x004A58D0u, NativeCallingConvention::fastcall_call},
    {0x004A5990u, NativeCallingConvention::thiscall_call},
    {0x004A59F0u, NativeCallingConvention::fastcall_call},
    {0x004A5A50u, NativeCallingConvention::thiscall_call},
    {0x004A5A70u, NativeCallingConvention::thiscall_call},
    {0x004A5B70u, NativeCallingConvention::fastcall_call},
    {0x004A5BF0u, NativeCallingConvention::fastcall_call},
    {0x004A5D90u, NativeCallingConvention::cdecl_call},
    {0x004A5E90u, NativeCallingConvention::thiscall_call},
    {0x004A5F10u, NativeCallingConvention::cdecl_call},
    {0x004A6220u, NativeCallingConvention::fastcall_call},
    {0x004A6270u, NativeCallingConvention::cdecl_call},
    {0x004A62D0u, NativeCallingConvention::fastcall_call},
    {0x004A6300u, NativeCallingConvention::thiscall_call},
    {0x004A6350u, NativeCallingConvention::cdecl_call},
    {0x004A63C0u, NativeCallingConvention::thiscall_call},
    {0x004A6400u, NativeCallingConvention::fastcall_call},
    {0x004A6440u, NativeCallingConvention::fastcall_call},
    {0x004A6480u, NativeCallingConvention::fastcall_call},
    {0x004A65D0u, NativeCallingConvention::thiscall_call},
    {0x004A6AC0u, NativeCallingConvention::thiscall_call},
    {0x004A6B49u, NativeCallingConvention::cdecl_call},
    {0x004A6B90u, NativeCallingConvention::thiscall_call},
    {0x004A6BE0u, NativeCallingConvention::thiscall_call},
    {0x004A6C00u, NativeCallingConvention::fastcall_call},
    {0x004A6C70u, NativeCallingConvention::thiscall_call},
    {0x004A7700u, NativeCallingConvention::thiscall_call},
    {0x004A77DFu, NativeCallingConvention::cdecl_call},
    {0x004A7800u, NativeCallingConvention::thiscall_call},
    {0x004A7890u, NativeCallingConvention::thiscall_call},
    {0x004A78F0u, NativeCallingConvention::fastcall_call},
    {0x004A7A00u, NativeCallingConvention::fastcall_call},
    {0x004A7BE0u, NativeCallingConvention::fastcall_call},
    {0x004A7C20u, NativeCallingConvention::thiscall_call},
    {0x004A80D0u, NativeCallingConvention::thiscall_call},
    {0x004A8610u, NativeCallingConvention::cdecl_call},
    {0x004A8720u, NativeCallingConvention::cdecl_call},
    {0x004A8760u, NativeCallingConvention::thiscall_call},
    {0x004A88A0u, NativeCallingConvention::thiscall_call},
    {0x004A8A30u, NativeCallingConvention::thiscall_call},
    {0x004A8A80u, NativeCallingConvention::fastcall_call},
    {0x004A8AD0u, NativeCallingConvention::thiscall_call},
    {0x004A8B30u, NativeCallingConvention::fastcall_call},
    {0x004A8C00u, NativeCallingConvention::thiscall_call},
    {0x004A8C50u, NativeCallingConvention::thiscall_call},
    {0x004A8C90u, NativeCallingConvention::fastcall_call},
    {0x004A8CC0u, NativeCallingConvention::cdecl_call},
    {0x004A8CF0u, NativeCallingConvention::thiscall_call},
    {0x004A8D80u, NativeCallingConvention::fastcall_call},
    {0x004A8E20u, NativeCallingConvention::thiscall_call},
    {0x004A8E40u, NativeCallingConvention::thiscall_call},
    {0x004A8FB0u, NativeCallingConvention::fastcall_call},
    {0x004A8FE0u, NativeCallingConvention::thiscall_call},
    {0x004A9010u, NativeCallingConvention::cdecl_call},
    {0x004A9210u, NativeCallingConvention::cdecl_call},
    {0x004A9320u, NativeCallingConvention::fastcall_call},
    {0x004A9360u, NativeCallingConvention::fastcall_call},
    {0x004A93A0u, NativeCallingConvention::fastcall_call},
    {0x004A93D0u, NativeCallingConvention::thiscall_call},
    {0x004A9490u, NativeCallingConvention::fastcall_call},
    {0x004A94D0u, NativeCallingConvention::thiscall_call},
    {0x004A95A0u, NativeCallingConvention::thiscall_call},
    {0x004A96D0u, NativeCallingConvention::fastcall_call},
    {0x004A97C0u, NativeCallingConvention::thiscall_call},
    {0x004A98B0u, NativeCallingConvention::fastcall_call},
    {0x004A9980u, NativeCallingConvention::thiscall_call},
    {0x004A9AA0u, NativeCallingConvention::fastcall_call},
    {0x004A9B20u, NativeCallingConvention::thiscall_call},
    {0x004A9B40u, NativeCallingConvention::thiscall_call},
    {0x004A9C90u, NativeCallingConvention::thiscall_call},
    {0x004A9CC0u, NativeCallingConvention::thiscall_call},
    {0x004A9FF0u, NativeCallingConvention::fastcall_call},
    {0x004AA0D0u, NativeCallingConvention::thiscall_call},
    {0x004AA270u, NativeCallingConvention::thiscall_call},
    {0x004AA3B2u, NativeCallingConvention::cdecl_call},
    {0x004AA410u, NativeCallingConvention::fastcall_call},
    {0x004AA570u, NativeCallingConvention::fastcall_call},
    {0x004AA7A0u, NativeCallingConvention::thiscall_call},
    {0x004AA830u, NativeCallingConvention::fastcall_call},
    {0x004AA900u, NativeCallingConvention::thiscall_call},
    {0x004AA990u, NativeCallingConvention::thiscall_call},
    {0x004AAA20u, NativeCallingConvention::fastcall_call},
    {0x004AAB13u, NativeCallingConvention::cdecl_call},
    {0x004AAB30u, NativeCallingConvention::thiscall_call},
    {0x004AAB50u, NativeCallingConvention::thiscall_call},
    {0x004AAC30u, NativeCallingConvention::thiscall_call},
    {0x004AAC60u, NativeCallingConvention::thiscall_call},
    {0x004AACC0u, NativeCallingConvention::fastcall_call},
    {0x004AAD9Du, NativeCallingConvention::cdecl_call},
    {0x004AADE0u, NativeCallingConvention::thiscall_call},
    {0x004AAFB0u, NativeCallingConvention::thiscall_call},
    {0x004AB05Du, NativeCallingConvention::cdecl_call},
    {0x004AB070u, NativeCallingConvention::thiscall_call},
    {0x004AB0E0u, NativeCallingConvention::fastcall_call},
    {0x004AB160u, NativeCallingConvention::thiscall_call},
    {0x004AB1B0u, NativeCallingConvention::thiscall_call},
    {0x004AB270u, NativeCallingConvention::thiscall_call},
    {0x004AB320u, NativeCallingConvention::fastcall_call},
    {0x004AB430u, NativeCallingConvention::fastcall_call},
    {0x004AB7C0u, NativeCallingConvention::thiscall_call},
    {0x004ABCC0u, NativeCallingConvention::thiscall_call},
    {0x004ABF80u, NativeCallingConvention::thiscall_call},
    {0x004AC070u, NativeCallingConvention::thiscall_call},
    {0x004AC150u, NativeCallingConvention::cdecl_call},
    {0x004AC290u, NativeCallingConvention::thiscall_call},
    {0x004AC350u, NativeCallingConvention::fastcall_call},
    {0x004AC3E0u, NativeCallingConvention::fastcall_call},
    {0x004AC470u, NativeCallingConvention::cdecl_call},
    {0x004AC4D0u, NativeCallingConvention::thiscall_call},
    {0x004AC6F0u, NativeCallingConvention::thiscall_call},
    {0x004AC7C0u, NativeCallingConvention::thiscall_call},
    {0x004AC880u, NativeCallingConvention::thiscall_call},
    {0x004AC950u, NativeCallingConvention::thiscall_call},
    {0x004AC9FAu, NativeCallingConvention::cdecl_call},
    {0x004ACB25u, NativeCallingConvention::cdecl_call},
    {0x004ACBB0u, NativeCallingConvention::thiscall_call},
    {0x004ACD70u, NativeCallingConvention::cdecl_call},
    {0x004ACE10u, NativeCallingConvention::thiscall_call},
    {0x004AD0B0u, NativeCallingConvention::thiscall_call},
    {0x004AD280u, NativeCallingConvention::thiscall_call},
    {0x004AD410u, NativeCallingConvention::thiscall_call},
    {0x004AD590u, NativeCallingConvention::fastcall_call},
    {0x004AD610u, NativeCallingConvention::fastcall_call},
    {0x004AD6E0u, NativeCallingConvention::cdecl_call},
    {0x004AD8B0u, NativeCallingConvention::cdecl_call},
    {0x004AE100u, NativeCallingConvention::thiscall_call},
    {0x004AE200u, NativeCallingConvention::fastcall_call},
    {0x004AE280u, NativeCallingConvention::fastcall_call},
    {0x004AE850u, NativeCallingConvention::fastcall_call},
    {0x004AE9B0u, NativeCallingConvention::fastcall_call},
    {0x004AEC20u, NativeCallingConvention::cdecl_call},
    {0x004AEC80u, NativeCallingConvention::fastcall_call},
    {0x004AECE0u, NativeCallingConvention::thiscall_call},
    {0x004AED40u, NativeCallingConvention::thiscall_call},
    {0x004AED90u, NativeCallingConvention::cdecl_call},
    {0x004AEE90u, NativeCallingConvention::fastcall_call},
    {0x004AEEA0u, NativeCallingConvention::thiscall_call},
    {0x004AF040u, NativeCallingConvention::fastcall_call},
    {0x004AF340u, NativeCallingConvention::fastcall_call},
    {0x004AF350u, NativeCallingConvention::cdecl_call},
    {0x004AF3A0u, NativeCallingConvention::thiscall_call},
    {0x004AF410u, NativeCallingConvention::fastcall_call},
    {0x004AF470u, NativeCallingConvention::fastcall_call},
    {0x004AF510u, NativeCallingConvention::fastcall_call},
    {0x004AF570u, NativeCallingConvention::thiscall_call},
    {0x004AF670u, NativeCallingConvention::thiscall_call},
    {0x004AF790u, NativeCallingConvention::thiscall_call},
    {0x004AF8A0u, NativeCallingConvention::thiscall_call},
    {0x004AF990u, NativeCallingConvention::thiscall_call},
    {0x004AFA50u, NativeCallingConvention::fastcall_call},
    {0x004AFAE0u, NativeCallingConvention::fastcall_call},
    {0x004AFB70u, NativeCallingConvention::cdecl_call},
    {0x004AFC40u, NativeCallingConvention::cdecl_call},
    {0x004AFD50u, NativeCallingConvention::fastcall_call},
    {0x004AFE60u, NativeCallingConvention::thiscall_call},
    {0x004B00C0u, NativeCallingConvention::cdecl_call},
    {0x004B0100u, NativeCallingConvention::fastcall_call},
    {0x004B0250u, NativeCallingConvention::thiscall_call},
    {0x004B0270u, NativeCallingConvention::thiscall_call},
    {0x004B0590u, NativeCallingConvention::thiscall_call},
    {0x004B08B0u, NativeCallingConvention::thiscall_call},
    {0x004B0B20u, NativeCallingConvention::thiscall_call},
    {0x004B0BE0u, NativeCallingConvention::thiscall_call},
    {0x004B0C8Au, NativeCallingConvention::cdecl_call},
    {0x004B0DB5u, NativeCallingConvention::cdecl_call},
    {0x004B0E40u, NativeCallingConvention::cdecl_call},
    {0x004B0EE0u, NativeCallingConvention::thiscall_call},
    {0x004B10B0u, NativeCallingConvention::thiscall_call},
    {0x004B1210u, NativeCallingConvention::fastcall_call},
    {0x004B1340u, NativeCallingConvention::fastcall_call},
    {0x004B1370u, NativeCallingConvention::fastcall_call},
    {0x004B13C0u, NativeCallingConvention::cdecl_call},
    {0x004B14F0u, NativeCallingConvention::fastcall_call},
    {0x004B15C0u, NativeCallingConvention::fastcall_call},
    {0x004B15E0u, NativeCallingConvention::fastcall_call},
    {0x004B15F0u, NativeCallingConvention::fastcall_call},
    {0x004B1600u, NativeCallingConvention::fastcall_call},
    {0x004B1650u, NativeCallingConvention::fastcall_call},
    {0x004B1690u, NativeCallingConvention::fastcall_call},
    {0x004B16D0u, NativeCallingConvention::thiscall_call},
    {0x004B1760u, NativeCallingConvention::thiscall_call},
    {0x004B17F0u, NativeCallingConvention::thiscall_call},
    {0x004B1830u, NativeCallingConvention::thiscall_call},
    {0x004B19D0u, NativeCallingConvention::thiscall_call},
    {0x004B1A20u, NativeCallingConvention::thiscall_call},
    {0x004B1A80u, NativeCallingConvention::fastcall_call},
    {0x004B1C85u, NativeCallingConvention::cdecl_call},
    {0x004B1CA6u, NativeCallingConvention::cdecl_call},
    {0x004B1CB0u, NativeCallingConvention::fastcall_call},
    {0x004B1ED4u, NativeCallingConvention::cdecl_call},
    {0x004B1EF5u, NativeCallingConvention::cdecl_call},
    {0x004B1F00u, NativeCallingConvention::cdecl_call},
    {0x004B2000u, NativeCallingConvention::thiscall_call},
    {0x004B2240u, NativeCallingConvention::cdecl_call},
    {0x004B2280u, NativeCallingConvention::fastcall_call},
    {0x004B2330u, NativeCallingConvention::thiscall_call},
    {0x004B23F0u, NativeCallingConvention::cdecl_call},
    {0x004B2440u, NativeCallingConvention::thiscall_call},
    {0x004B24B0u, NativeCallingConvention::fastcall_call},
    {0x004B2500u, NativeCallingConvention::thiscall_call},
    {0x004B259Eu, NativeCallingConvention::cdecl_call},
    {0x004B25C0u, NativeCallingConvention::thiscall_call},
    {0x004B2650u, NativeCallingConvention::thiscall_call},
    {0x004B2680u, NativeCallingConvention::thiscall_call},
    {0x004B28A0u, NativeCallingConvention::fastcall_call},
    {0x004B2AD0u, NativeCallingConvention::fastcall_call},
    {0x004B2C40u, NativeCallingConvention::thiscall_call},
    {0x004B2CF0u, NativeCallingConvention::thiscall_call},
    {0x004B2D70u, NativeCallingConvention::fastcall_call},
    {0x004B2E65u, NativeCallingConvention::cdecl_call},
    {0x004B2E86u, NativeCallingConvention::cdecl_call},
    {0x004B2EE0u, NativeCallingConvention::thiscall_call},
    {0x004B2FE0u, NativeCallingConvention::thiscall_call},
    {0x004B30C0u, NativeCallingConvention::fastcall_call},
    {0x004B3110u, NativeCallingConvention::fastcall_call},
    {0x004B3200u, NativeCallingConvention::cdecl_call},
    {0x004B3390u, NativeCallingConvention::thiscall_call},
    {0x004B3530u, NativeCallingConvention::fastcall_call},
    {0x004B3760u, NativeCallingConvention::fastcall_call},
    {0x004B3820u, NativeCallingConvention::fastcall_call},
    {0x004B3900u, NativeCallingConvention::fastcall_call},
    {0x004B3970u, NativeCallingConvention::thiscall_call},
    {0x004B3A40u, NativeCallingConvention::fastcall_call},
    {0x004B3B00u, NativeCallingConvention::fastcall_call},
    {0x004B3B70u, NativeCallingConvention::thiscall_call},
    {0x004B3C10u, NativeCallingConvention::fastcall_call},
    {0x004B3D40u, NativeCallingConvention::thiscall_call},
    {0x004B3F60u, NativeCallingConvention::fastcall_call},
    {0x004B4060u, NativeCallingConvention::fastcall_call},
    {0x004B40D0u, NativeCallingConvention::fastcall_call},
    {0x004B4100u, NativeCallingConvention::fastcall_call},
    {0x004B4140u, NativeCallingConvention::fastcall_call},
    {0x004B4180u, NativeCallingConvention::fastcall_call},
    {0x004B41B0u, NativeCallingConvention::cdecl_call},
    {0x004B4270u, NativeCallingConvention::thiscall_call},
    {0x004B45C0u, NativeCallingConvention::thiscall_call},
    {0x004B47D0u, NativeCallingConvention::fastcall_call},
    {0x004B4AB0u, NativeCallingConvention::cdecl_call},
    {0x004B4B60u, NativeCallingConvention::cdecl_call},
    {0x004B4C10u, NativeCallingConvention::thiscall_call},
    {0x004B4CE0u, NativeCallingConvention::fastcall_call},
    {0x004B4D90u, NativeCallingConvention::thiscall_call},
    {0x004B4DD0u, NativeCallingConvention::fastcall_call},
    {0x004B4FB0u, NativeCallingConvention::fastcall_call},
    {0x004B5020u, NativeCallingConvention::fastcall_call},
    {0x004B5090u, NativeCallingConvention::fastcall_call},
    {0x004B5350u, NativeCallingConvention::cdecl_call},
    {0x004B5780u, NativeCallingConvention::thiscall_call},
    {0x004B57C0u, NativeCallingConvention::fastcall_call},
    {0x004B5D10u, NativeCallingConvention::fastcall_call},
    {0x004B6270u, NativeCallingConvention::cdecl_call},
    {0x004B62D0u, NativeCallingConvention::fastcall_call},
    {0x004B6410u, NativeCallingConvention::thiscall_call},
    {0x004B6DD0u, NativeCallingConvention::fastcall_call},
    {0x004B6F10u, NativeCallingConvention::thiscall_call},
    {0x004B6F30u, NativeCallingConvention::thiscall_call},
    {0x004B7360u, NativeCallingConvention::thiscall_call},
    {0x004B7540u, NativeCallingConvention::thiscall_call},
    {0x004B7720u, NativeCallingConvention::fastcall_call},
    {0x004B77A0u, NativeCallingConvention::fastcall_call},
    {0x004B77F0u, NativeCallingConvention::thiscall_call},
    {0x004B7970u, NativeCallingConvention::fastcall_call},
    {0x004B7AF0u, NativeCallingConvention::thiscall_call},
    {0x004B7CA0u, NativeCallingConvention::thiscall_call},
    {0x004B7DC0u, NativeCallingConvention::thiscall_call},
    {0x004B7F10u, NativeCallingConvention::thiscall_call},
    {0x004B7F90u, NativeCallingConvention::thiscall_call},
    {0x004B8030u, NativeCallingConvention::thiscall_call},
    {0x004B80A0u, NativeCallingConvention::fastcall_call},
    {0x004B8150u, NativeCallingConvention::fastcall_call},
    {0x004B8230u, NativeCallingConvention::fastcall_call},
    {0x004B8250u, NativeCallingConvention::fastcall_call},
    {0x004B8360u, NativeCallingConvention::fastcall_call},
    {0x004B83C0u, NativeCallingConvention::cdecl_call},
    {0x004B83D0u, NativeCallingConvention::fastcall_call},
    {0x004B8430u, NativeCallingConvention::fastcall_call},
    {0x004B8490u, NativeCallingConvention::fastcall_call},
    {0x004B84B0u, NativeCallingConvention::fastcall_call},
    {0x004B8630u, NativeCallingConvention::fastcall_call},
    {0x004B8680u, NativeCallingConvention::fastcall_call},
    {0x004B86B0u, NativeCallingConvention::fastcall_call},
    {0x004B86D0u, NativeCallingConvention::fastcall_call},
    {0x004B8700u, NativeCallingConvention::fastcall_call},
    {0x004B8740u, NativeCallingConvention::fastcall_call},
    {0x004B8750u, NativeCallingConvention::fastcall_call},
    {0x004B8780u, NativeCallingConvention::fastcall_call},
    {0x004B87A0u, NativeCallingConvention::fastcall_call},
    {0x004B87C0u, NativeCallingConvention::fastcall_call},
    {0x004B87D0u, NativeCallingConvention::fastcall_call},
    {0x004B87E0u, NativeCallingConvention::cdecl_call},
    {0x004B87F0u, NativeCallingConvention::fastcall_call},
    {0x004B8850u, NativeCallingConvention::cdecl_call},
    {0x004B8A40u, NativeCallingConvention::fastcall_call},
    {0x004B8AA0u, NativeCallingConvention::cdecl_call},
    {0x004B8B10u, NativeCallingConvention::fastcall_call},
    {0x004B8B80u, NativeCallingConvention::thiscall_call},
    {0x004B8D40u, NativeCallingConvention::thiscall_call},
    {0x004B8F00u, NativeCallingConvention::thiscall_call},
    {0x004B8F50u, NativeCallingConvention::thiscall_call},
    {0x004B9070u, NativeCallingConvention::thiscall_call},
    {0x004B90A0u, NativeCallingConvention::fastcall_call},
    {0x004B9140u, NativeCallingConvention::cdecl_call},
    {0x004B9150u, NativeCallingConvention::fastcall_call},
    {0x004B9190u, NativeCallingConvention::cdecl_call},
    {0x004B9200u, NativeCallingConvention::fastcall_call},
    {0x004B92A0u, NativeCallingConvention::thiscall_call},
    {0x004B92D0u, NativeCallingConvention::cdecl_call},
    {0x004B9350u, NativeCallingConvention::fastcall_call},
    {0x004B9390u, NativeCallingConvention::cdecl_call},
    {0x004B9410u, NativeCallingConvention::cdecl_call},
    {0x004B94A0u, NativeCallingConvention::cdecl_call},
    {0x004B9540u, NativeCallingConvention::fastcall_call},
    {0x004B9620u, NativeCallingConvention::cdecl_call},
    {0x004B9820u, NativeCallingConvention::fastcall_call},
    {0x004B9850u, NativeCallingConvention::fastcall_call},
    {0x004B98B0u, NativeCallingConvention::cdecl_call},
    {0x004B9970u, NativeCallingConvention::fastcall_call},
    {0x004B99E0u, NativeCallingConvention::cdecl_call},
    {0x004B9A10u, NativeCallingConvention::fastcall_call},
    {0x004B9A70u, NativeCallingConvention::fastcall_call},
    {0x004B9AD0u, NativeCallingConvention::cdecl_call},
    {0x004B9B10u, NativeCallingConvention::cdecl_call},
    {0x004B9B60u, NativeCallingConvention::thiscall_call},
    {0x004B9BB0u, NativeCallingConvention::cdecl_call},
    {0x004B9C50u, NativeCallingConvention::fastcall_call},
    {0x004B9D00u, NativeCallingConvention::fastcall_call},
    {0x004B9F40u, NativeCallingConvention::cdecl_call},
    {0x004BA190u, NativeCallingConvention::cdecl_call},
    {0x004BA370u, NativeCallingConvention::cdecl_call},
    {0x004BA680u, NativeCallingConvention::fastcall_call},
    {0x004BA6B0u, NativeCallingConvention::fastcall_call},
    {0x004BA750u, NativeCallingConvention::fastcall_call},
    {0x004BA7E0u, NativeCallingConvention::fastcall_call},
    {0x004BA870u, NativeCallingConvention::cdecl_call},
    {0x004BA8C0u, NativeCallingConvention::fastcall_call},
    {0x004BA910u, NativeCallingConvention::fastcall_call},
    {0x004BAAA0u, NativeCallingConvention::fastcall_call},
    {0x004BACE0u, NativeCallingConvention::fastcall_call},
    {0x004BAD10u, NativeCallingConvention::fastcall_call},
    {0x004BAE60u, NativeCallingConvention::thiscall_call},
    {0x004BAFB0u, NativeCallingConvention::fastcall_call},
    {0x004BB750u, NativeCallingConvention::fastcall_call},
    {0x004BB800u, NativeCallingConvention::fastcall_call},
    {0x004BBE80u, NativeCallingConvention::fastcall_call},
    {0x004BBF00u, NativeCallingConvention::cdecl_call},
    {0x004BBF9Bu, NativeCallingConvention::cdecl_call},
    {0x004BBFE0u, NativeCallingConvention::cdecl_call},
    {0x004BC000u, NativeCallingConvention::fastcall_call},
    {0x004BC060u, NativeCallingConvention::fastcall_call},
    {0x004BC0F4u, NativeCallingConvention::cdecl_call},
    {0x004BC130u, NativeCallingConvention::fastcall_call},
    {0x004BC190u, NativeCallingConvention::fastcall_call},
    {0x004BC290u, NativeCallingConvention::cdecl_call},
    {0x004BC480u, NativeCallingConvention::cdecl_call},
    {0x004BC5F0u, NativeCallingConvention::fastcall_call},
    {0x004BC650u, NativeCallingConvention::fastcall_call},
    {0x004BC840u, NativeCallingConvention::thiscall_call},
    {0x004BC93Eu, NativeCallingConvention::cdecl_call},
    {0x004BC960u, NativeCallingConvention::thiscall_call},
    {0x004BC9F0u, NativeCallingConvention::fastcall_call},
    {0x004BCA50u, NativeCallingConvention::thiscall_call},
    {0x004BCAD0u, NativeCallingConvention::cdecl_call},
    {0x004BCD80u, NativeCallingConvention::cdecl_call},
    {0x004BCEF0u, NativeCallingConvention::fastcall_call},
    {0x004BD000u, NativeCallingConvention::fastcall_call},
    {0x004BD340u, NativeCallingConvention::thiscall_call},
    {0x004BD6D0u, NativeCallingConvention::fastcall_call},
    {0x004BD880u, NativeCallingConvention::thiscall_call},
    {0x004BD940u, NativeCallingConvention::thiscall_call},
    {0x004BD970u, NativeCallingConvention::thiscall_call},
    {0x004BDA30u, NativeCallingConvention::thiscall_call},
    {0x004BDA90u, NativeCallingConvention::fastcall_call},
    {0x004BDC80u, NativeCallingConvention::thiscall_call},
    {0x004BDCD0u, NativeCallingConvention::fastcall_call},
    {0x004BDD70u, NativeCallingConvention::thiscall_call},
    {0x004BDE90u, NativeCallingConvention::thiscall_call},
    {0x004BDEF0u, NativeCallingConvention::fastcall_call},
    {0x004BDF90u, NativeCallingConvention::thiscall_call},
    {0x004BE000u, NativeCallingConvention::fastcall_call},
    {0x004BE120u, NativeCallingConvention::fastcall_call},
    {0x004BE170u, NativeCallingConvention::thiscall_call},
    {0x004BE3C0u, NativeCallingConvention::thiscall_call},
    {0x004BE3E0u, NativeCallingConvention::thiscall_call},
    {0x004BE7B0u, NativeCallingConvention::thiscall_call},
    {0x004BE8C0u, NativeCallingConvention::fastcall_call},
    {0x004BEB80u, NativeCallingConvention::fastcall_call},
    {0x004BEBA0u, NativeCallingConvention::fastcall_call},
    {0x004BEBC0u, NativeCallingConvention::fastcall_call},
    {0x004BEC00u, NativeCallingConvention::fastcall_call},
    {0x004BEC20u, NativeCallingConvention::thiscall_call},
    {0x004BEEB0u, NativeCallingConvention::thiscall_call},
    {0x004BEEF0u, NativeCallingConvention::thiscall_call},
    {0x004BF130u, NativeCallingConvention::fastcall_call},
    {0x004BF210u, NativeCallingConvention::fastcall_call},
    {0x004BF9C0u, NativeCallingConvention::thiscall_call},
    {0x004BFA70u, NativeCallingConvention::fastcall_call},
    {0x004BFB90u, NativeCallingConvention::fastcall_call},
    {0x004BFC50u, NativeCallingConvention::fastcall_call},
    {0x004BFD20u, NativeCallingConvention::thiscall_call},
    {0x004BFE80u, NativeCallingConvention::thiscall_call},
    {0x004BFEA0u, NativeCallingConvention::thiscall_call},
    {0x004C0170u, NativeCallingConvention::fastcall_call},
    {0x004C01E0u, NativeCallingConvention::thiscall_call},
    {0x004C04C0u, NativeCallingConvention::fastcall_call},
    {0x004C0590u, NativeCallingConvention::thiscall_call},
    {0x004C08C0u, NativeCallingConvention::thiscall_call},
    {0x004C0D80u, NativeCallingConvention::thiscall_call},
    {0x004C10C0u, NativeCallingConvention::fastcall_call},
    {0x004C1110u, NativeCallingConvention::fastcall_call},
    {0x004C1190u, NativeCallingConvention::fastcall_call},
    {0x004C11E0u, NativeCallingConvention::fastcall_call},
    {0x004C1280u, NativeCallingConvention::fastcall_call},
    {0x004C12E0u, NativeCallingConvention::thiscall_call},
    {0x004C1350u, NativeCallingConvention::fastcall_call},
    {0x004C13E0u, NativeCallingConvention::thiscall_call},
    {0x004C1470u, NativeCallingConvention::fastcall_call},
    {0x004C1510u, NativeCallingConvention::cdecl_call},
    {0x004C15B0u, NativeCallingConvention::cdecl_call},
    {0x004C1610u, NativeCallingConvention::cdecl_call},
    {0x004C1660u, NativeCallingConvention::fastcall_call},
    {0x004C17B0u, NativeCallingConvention::fastcall_call},
    {0x004C18E0u, NativeCallingConvention::thiscall_call},
    {0x004C1A40u, NativeCallingConvention::fastcall_call},
    {0x004C1AE0u, NativeCallingConvention::thiscall_call},
    {0x004C1B30u, NativeCallingConvention::thiscall_call},
    {0x004C23B0u, NativeCallingConvention::fastcall_call},
    {0x004C23F0u, NativeCallingConvention::fastcall_call},
    {0x004C246Bu, NativeCallingConvention::cdecl_call},
    {0x004C24B0u, NativeCallingConvention::fastcall_call},
    {0x004C24F0u, NativeCallingConvention::fastcall_call},
    {0x004C256Bu, NativeCallingConvention::cdecl_call},
    {0x004C25B0u, NativeCallingConvention::thiscall_call},
    {0x004C2695u, NativeCallingConvention::cdecl_call},
    {0x004C26B0u, NativeCallingConvention::thiscall_call},
    {0x004C2710u, NativeCallingConvention::thiscall_call},
    {0x004C2770u, NativeCallingConvention::fastcall_call},
    {0x004C27C0u, NativeCallingConvention::fastcall_call},
    {0x004C2830u, NativeCallingConvention::thiscall_call},
    {0x004C2910u, NativeCallingConvention::thiscall_call},
    {0x004C2A20u, NativeCallingConvention::thiscall_call},
    {0x004C2A40u, NativeCallingConvention::thiscall_call},
    {0x004C2C90u, NativeCallingConvention::thiscall_call},
    {0x004C2DC0u, NativeCallingConvention::thiscall_call},
    {0x004C2FB0u, NativeCallingConvention::fastcall_call},
    {0x004C3060u, NativeCallingConvention::fastcall_call},
    {0x004C30E0u, NativeCallingConvention::thiscall_call},
    {0x004C3140u, NativeCallingConvention::fastcall_call},
    {0x004C3170u, NativeCallingConvention::fastcall_call},
    {0x004C31E5u, NativeCallingConvention::cdecl_call},
    {0x004C3230u, NativeCallingConvention::thiscall_call},
    {0x004C3250u, NativeCallingConvention::fastcall_call},
    {0x004C3270u, NativeCallingConvention::thiscall_call},
    {0x004C3290u, NativeCallingConvention::thiscall_call},
    {0x004C3420u, NativeCallingConvention::thiscall_call},
    {0x004C3520u, NativeCallingConvention::fastcall_call},
    {0x004C35C0u, NativeCallingConvention::thiscall_call},
    {0x004C3640u, NativeCallingConvention::fastcall_call},
    {0x004C3670u, NativeCallingConvention::fastcall_call},
    {0x004C3710u, NativeCallingConvention::thiscall_call},
    {0x004C3720u, NativeCallingConvention::thiscall_call},
    {0x004C3750u, NativeCallingConvention::fastcall_call},
    {0x004C3980u, NativeCallingConvention::fastcall_call},
    {0x004C3A20u, NativeCallingConvention::cdecl_call},
    {0x004C3AB0u, NativeCallingConvention::fastcall_call},
    {0x004C3AC0u, NativeCallingConvention::cdecl_call},
    {0x004C3AD0u, NativeCallingConvention::cdecl_call},
    {0x004C3B40u, NativeCallingConvention::fastcall_call},
    {0x004C3BA0u, NativeCallingConvention::fastcall_call},
    {0x004C3C00u, NativeCallingConvention::fastcall_call},
    {0x004C3DF0u, NativeCallingConvention::fastcall_call},
    {0x004C3EB0u, NativeCallingConvention::thiscall_call},
    {0x004C3FC0u, NativeCallingConvention::thiscall_call},
    {0x004C4220u, NativeCallingConvention::thiscall_call},
    {0x004C42B0u, NativeCallingConvention::fastcall_call},
    {0x004C4360u, NativeCallingConvention::fastcall_call},
    {0x004C43A0u, NativeCallingConvention::fastcall_call},
    {0x004C43C0u, NativeCallingConvention::fastcall_call},
    {0x004C4480u, NativeCallingConvention::thiscall_call},
    {0x004C44F0u, NativeCallingConvention::fastcall_call},
    {0x004C45A0u, NativeCallingConvention::fastcall_call},
    {0x004C45C0u, NativeCallingConvention::fastcall_call},
    {0x004C46D0u, NativeCallingConvention::fastcall_call},
    {0x004C4760u, NativeCallingConvention::fastcall_call},
    {0x004C4820u, NativeCallingConvention::fastcall_call},
    {0x004C48B0u, NativeCallingConvention::fastcall_call},
    {0x004C4960u, NativeCallingConvention::fastcall_call},
    {0x004C49F0u, NativeCallingConvention::fastcall_call},
    {0x004C4AB0u, NativeCallingConvention::fastcall_call},
    {0x004C4C20u, NativeCallingConvention::thiscall_call},
    {0x004C4D90u, NativeCallingConvention::fastcall_call},
    {0x004C5120u, NativeCallingConvention::thiscall_call},
    {0x004C5340u, NativeCallingConvention::fastcall_call},
    {0x004C54F0u, NativeCallingConvention::fastcall_call},
    {0x004C55D0u, NativeCallingConvention::fastcall_call},
    {0x004C57A0u, NativeCallingConvention::fastcall_call},
    {0x004C5990u, NativeCallingConvention::thiscall_call},
    {0x004C59B0u, NativeCallingConvention::thiscall_call},
    {0x004C5A50u, NativeCallingConvention::thiscall_call},
    {0x004C5B30u, NativeCallingConvention::thiscall_call},
    {0x004C5C20u, NativeCallingConvention::thiscall_call},
    {0x004C5D00u, NativeCallingConvention::fastcall_call},
    {0x004C5E10u, NativeCallingConvention::fastcall_call},
    {0x004C5F00u, NativeCallingConvention::thiscall_call},
    {0x004C60D0u, NativeCallingConvention::thiscall_call},
    {0x004C6370u, NativeCallingConvention::thiscall_call},
    {0x004C6460u, NativeCallingConvention::thiscall_call},
    {0x004C6640u, NativeCallingConvention::fastcall_call},
    {0x004C6810u, NativeCallingConvention::thiscall_call},
    {0x004C6A20u, NativeCallingConvention::fastcall_call},
    {0x004C6AD0u, NativeCallingConvention::fastcall_call},
    {0x004C6B80u, NativeCallingConvention::thiscall_call},
    {0x004C6EC0u, NativeCallingConvention::fastcall_call},
    {0x004C7120u, NativeCallingConvention::thiscall_call},
    {0x004C7880u, NativeCallingConvention::fastcall_call},
    {0x004C79A0u, NativeCallingConvention::thiscall_call},
    {0x004C7A70u, NativeCallingConvention::thiscall_call},
    {0x004C7AB0u, NativeCallingConvention::thiscall_call},
    {0x004C7CF0u, NativeCallingConvention::fastcall_call},
    {0x004C7DA0u, NativeCallingConvention::thiscall_call},
    {0x004C7DB0u, NativeCallingConvention::fastcall_call},
    {0x004C7DC0u, NativeCallingConvention::thiscall_call},
    {0x004C7DE0u, NativeCallingConvention::thiscall_call},
    {0x004C7F20u, NativeCallingConvention::fastcall_call},
    {0x004C8020u, NativeCallingConvention::fastcall_call},
    {0x004C8060u, NativeCallingConvention::fastcall_call},
    {0x004C80C0u, NativeCallingConvention::thiscall_call},
    {0x004C8270u, NativeCallingConvention::fastcall_call},
    {0x004C82E0u, NativeCallingConvention::fastcall_call},
    {0x004C83F0u, NativeCallingConvention::thiscall_call},
    {0x004C8450u, NativeCallingConvention::fastcall_call},
    {0x004C8570u, NativeCallingConvention::fastcall_call},
    {0x004C85E0u, NativeCallingConvention::fastcall_call},
    {0x004C8D00u, NativeCallingConvention::thiscall_call},
    {0x004C8F60u, NativeCallingConvention::fastcall_call},
    {0x004C9080u, NativeCallingConvention::fastcall_call},
    {0x004C9150u, NativeCallingConvention::thiscall_call},
    {0x004C9170u, NativeCallingConvention::thiscall_call},
    {0x004C9250u, NativeCallingConvention::thiscall_call},
    {0x004C95F0u, NativeCallingConvention::thiscall_call},
    {0x004C9890u, NativeCallingConvention::thiscall_call},
    {0x004C99D0u, NativeCallingConvention::fastcall_call},
    {0x004C9A80u, NativeCallingConvention::fastcall_call},
    {0x004C9AF0u, NativeCallingConvention::fastcall_call},
    {0x004C9B50u, NativeCallingConvention::cdecl_call},
    {0x004C9C30u, NativeCallingConvention::fastcall_call},
    {0x004C9C40u, NativeCallingConvention::fastcall_call},
    {0x004C9D30u, NativeCallingConvention::cdecl_call},
    {0x004C9D40u, NativeCallingConvention::fastcall_call},
    {0x004C9D60u, NativeCallingConvention::fastcall_call},
    {0x004C9DF0u, NativeCallingConvention::fastcall_call},
    {0x004C9E50u, NativeCallingConvention::cdecl_call},
    {0x004C9EB0u, NativeCallingConvention::cdecl_call},
    {0x004C9FD0u, NativeCallingConvention::fastcall_call},
    {0x004CA0E5u, NativeCallingConvention::cdecl_call},
    {0x004CA100u, NativeCallingConvention::thiscall_call},
    {0x004CA180u, NativeCallingConvention::fastcall_call},
    {0x004CA530u, NativeCallingConvention::fastcall_call},
    {0x004CABD0u, NativeCallingConvention::fastcall_call},
    {0x004CB100u, NativeCallingConvention::fastcall_call},
    {0x004CB700u, NativeCallingConvention::thiscall_call},
    {0x004CB790u, NativeCallingConvention::fastcall_call},
    {0x004CB950u, NativeCallingConvention::fastcall_call},
    {0x004CC280u, NativeCallingConvention::fastcall_call},
    {0x004CD0D0u, NativeCallingConvention::fastcall_call},
    {0x004CD1A0u, NativeCallingConvention::fastcall_call},
    {0x004CD1F0u, NativeCallingConvention::fastcall_call},
    {0x004CD430u, NativeCallingConvention::fastcall_call},
    {0x004CD4A0u, NativeCallingConvention::fastcall_call},
    {0x004CD550u, NativeCallingConvention::thiscall_call},
    {0x004CD760u, NativeCallingConvention::fastcall_call},
    {0x004CD820u, NativeCallingConvention::thiscall_call},
    {0x004CD950u, NativeCallingConvention::thiscall_call},
    {0x004CD990u, NativeCallingConvention::thiscall_call},
    {0x004CD9D0u, NativeCallingConvention::thiscall_call},
    {0x004CDA00u, NativeCallingConvention::fastcall_call},
    {0x004CDA10u, NativeCallingConvention::thiscall_call},
    {0x004CDA30u, NativeCallingConvention::thiscall_call},
    {0x004CDBF0u, NativeCallingConvention::fastcall_call},
    {0x004CDD50u, NativeCallingConvention::thiscall_call},
    {0x004CDE00u, NativeCallingConvention::fastcall_call},
    {0x004CDF00u, NativeCallingConvention::fastcall_call},
    {0x004CDF70u, NativeCallingConvention::thiscall_call},
    {0x004CDFF0u, NativeCallingConvention::thiscall_call},
    {0x004CE0E0u, NativeCallingConvention::fastcall_call},
    {0x004CE140u, NativeCallingConvention::fastcall_call},
    {0x004CE2B0u, NativeCallingConvention::thiscall_call},
    {0x004CE4F0u, NativeCallingConvention::thiscall_call},
    {0x004CE700u, NativeCallingConvention::thiscall_call},
    {0x004CE8A0u, NativeCallingConvention::thiscall_call},
    {0x004CEB70u, NativeCallingConvention::thiscall_call},
    {0x004CEC50u, NativeCallingConvention::fastcall_call},
    {0x004CEDA0u, NativeCallingConvention::fastcall_call},
    {0x004CEE10u, NativeCallingConvention::fastcall_call},
    {0x004CEE60u, NativeCallingConvention::thiscall_call},
    {0x004CEFF0u, NativeCallingConvention::thiscall_call},
    {0x004CF160u, NativeCallingConvention::fastcall_call},
    {0x004CF1A0u, NativeCallingConvention::thiscall_call},
    {0x004CF1F0u, NativeCallingConvention::thiscall_call},
    {0x004CF280u, NativeCallingConvention::fastcall_call},
    {0x004CF2E0u, NativeCallingConvention::fastcall_call},
    {0x004CF310u, NativeCallingConvention::thiscall_call},
    {0x004CF3E0u, NativeCallingConvention::thiscall_call},
    {0x004CF4C0u, NativeCallingConvention::fastcall_call},
    {0x004CF670u, NativeCallingConvention::fastcall_call},
    {0x004CF750u, NativeCallingConvention::fastcall_call},
    {0x004CF770u, NativeCallingConvention::thiscall_call},
    {0x004CF7C0u, NativeCallingConvention::thiscall_call},
    {0x004CFA00u, NativeCallingConvention::fastcall_call},
    {0x004CFD90u, NativeCallingConvention::fastcall_call},
    {0x004CFE70u, NativeCallingConvention::fastcall_call},
    {0x004CFF20u, NativeCallingConvention::fastcall_call},
    {0x004CFFA0u, NativeCallingConvention::cdecl_call},
    {0x004D0060u, NativeCallingConvention::thiscall_call},
    {0x004D0130u, NativeCallingConvention::thiscall_call},
    {0x004D0230u, NativeCallingConvention::thiscall_call},
    {0x004D0520u, NativeCallingConvention::fastcall_call},
    {0x004D0670u, NativeCallingConvention::thiscall_call},
    {0x004D07B0u, NativeCallingConvention::fastcall_call},
    {0x004D0890u, NativeCallingConvention::fastcall_call},
    {0x004D08E0u, NativeCallingConvention::fastcall_call},
    {0x004D09D0u, NativeCallingConvention::thiscall_call},
    {0x004D09F0u, NativeCallingConvention::thiscall_call},
    {0x004D0AC1u, NativeCallingConvention::cdecl_call},
    {0x004D0AE0u, NativeCallingConvention::cdecl_call},
    {0x004D0B4Cu, NativeCallingConvention::cdecl_call},
    {0x004D0B6Bu, NativeCallingConvention::cdecl_call},
    {0x004D0BB0u, NativeCallingConvention::fastcall_call},
    {0x004D0C30u, NativeCallingConvention::thiscall_call},
    {0x004D0CF9u, NativeCallingConvention::cdecl_call},
    {0x004D0D18u, NativeCallingConvention::cdecl_call},
    {0x004D0D7Au, NativeCallingConvention::cdecl_call},
    {0x004D0D93u, NativeCallingConvention::cdecl_call},
    {0x004D0DB0u, NativeCallingConvention::thiscall_call},
    {0x004D0E10u, NativeCallingConvention::cdecl_call},
    {0x004D0EC0u, NativeCallingConvention::thiscall_call},
    {0x004D0F50u, NativeCallingConvention::fastcall_call},
    {0x004D0F70u, NativeCallingConvention::thiscall_call},
    {0x004D0FC0u, NativeCallingConvention::cdecl_call},
    {0x004D1060u, NativeCallingConvention::fastcall_call},
    {0x004D10D0u, NativeCallingConvention::fastcall_call},
    {0x004D1110u, NativeCallingConvention::fastcall_call},
    {0x004D1160u, NativeCallingConvention::fastcall_call},
    {0x004D11A0u, NativeCallingConvention::fastcall_call},
    {0x004D1220u, NativeCallingConvention::cdecl_call},
    {0x004D12C0u, NativeCallingConvention::fastcall_call},
    {0x004D1360u, NativeCallingConvention::fastcall_call},
    {0x004D1370u, NativeCallingConvention::fastcall_call},
    {0x004D1430u, NativeCallingConvention::thiscall_call},
    {0x004D14A0u, NativeCallingConvention::fastcall_call},
    {0x004D15E0u, NativeCallingConvention::cdecl_call},
    {0x004D17F0u, NativeCallingConvention::cdecl_call},
    {0x004D1890u, NativeCallingConvention::cdecl_call},
    {0x004D1930u, NativeCallingConvention::cdecl_call},
    {0x004D19D0u, NativeCallingConvention::thiscall_call},
    {0x004D19E0u, NativeCallingConvention::thiscall_call},
    {0x004D1A00u, NativeCallingConvention::fastcall_call},
    {0x004D1A10u, NativeCallingConvention::fastcall_call},
    {0x004D1A60u, NativeCallingConvention::fastcall_call},
    {0x004D1AC0u, NativeCallingConvention::thiscall_call},
    {0x004D1B00u, NativeCallingConvention::fastcall_call},
    {0x004D1B40u, NativeCallingConvention::thiscall_call},
    {0x004D1C30u, NativeCallingConvention::fastcall_call},
    {0x004D1C50u, NativeCallingConvention::fastcall_call},
    {0x004D1D00u, NativeCallingConvention::thiscall_call},
    {0x004D1E20u, NativeCallingConvention::thiscall_call},
    {0x004D1F10u, NativeCallingConvention::thiscall_call},
    {0x004D20F0u, NativeCallingConvention::thiscall_call},
    {0x004D2180u, NativeCallingConvention::thiscall_call},
    {0x004D23B0u, NativeCallingConvention::thiscall_call},
    {0x004D2420u, NativeCallingConvention::fastcall_call},
    {0x004D2480u, NativeCallingConvention::thiscall_call},
    {0x004D2560u, NativeCallingConvention::thiscall_call},
    {0x004D25E0u, NativeCallingConvention::fastcall_call},
    {0x004D2810u, NativeCallingConvention::fastcall_call},
    {0x004D2870u, NativeCallingConvention::fastcall_call},
    {0x004D28B0u, NativeCallingConvention::thiscall_call},
    {0x004D2A40u, NativeCallingConvention::thiscall_call},
    {0x004D2AE0u, NativeCallingConvention::thiscall_call},
    {0x004D2B80u, NativeCallingConvention::thiscall_call},
    {0x004D2C30u, NativeCallingConvention::thiscall_call},
    {0x004D2D30u, NativeCallingConvention::thiscall_call},
    {0x004D2DA0u, NativeCallingConvention::fastcall_call},
    {0x004D2DD0u, NativeCallingConvention::thiscall_call},
    {0x004D3080u, NativeCallingConvention::fastcall_call},
    {0x004D30E0u, NativeCallingConvention::thiscall_call},
    {0x004D3140u, NativeCallingConvention::thiscall_call},
    {0x004D3290u, NativeCallingConvention::thiscall_call},
    {0x004D32C0u, NativeCallingConvention::fastcall_call},
    {0x004D3360u, NativeCallingConvention::fastcall_call},
    {0x004D3430u, NativeCallingConvention::cdecl_call},
    {0x004D3510u, NativeCallingConvention::fastcall_call},
    {0x004D37D0u, NativeCallingConvention::fastcall_call},
    {0x004D3AC0u, NativeCallingConvention::fastcall_call},
    {0x004D4230u, NativeCallingConvention::thiscall_call},
    {0x004D47B0u, NativeCallingConvention::thiscall_call},
    {0x004D51A0u, NativeCallingConvention::thiscall_call},
    {0x004D5510u, NativeCallingConvention::fastcall_call},
    {0x004D5590u, NativeCallingConvention::cdecl_call},
    {0x004D55F0u, NativeCallingConvention::fastcall_call},
    {0x004D5665u, NativeCallingConvention::cdecl_call},
    {0x004D5674u, NativeCallingConvention::cdecl_call},
    {0x004D56E0u, NativeCallingConvention::cdecl_call},
    {0x004D5760u, NativeCallingConvention::cdecl_call},
    {0x004D5980u, NativeCallingConvention::fastcall_call},
    {0x004D5B90u, NativeCallingConvention::cdecl_call},
    {0x004D5BC0u, NativeCallingConvention::cdecl_call},
    {0x004D5E10u, NativeCallingConvention::cdecl_call},
    {0x004D5EB0u, NativeCallingConvention::cdecl_call},
    {0x004D610Du, NativeCallingConvention::cdecl_call},
    {0x004D6113u, NativeCallingConvention::cdecl_call},
    {0x004D6300u, NativeCallingConvention::fastcall_call},
    {0x004D65B0u, NativeCallingConvention::cdecl_call},
    {0x004D6720u, NativeCallingConvention::fastcall_call},
    {0x004D67E0u, NativeCallingConvention::fastcall_call},
    {0x004D6800u, NativeCallingConvention::fastcall_call},
    {0x004D6820u, NativeCallingConvention::fastcall_call},
    {0x004D6880u, NativeCallingConvention::cdecl_call},
    {0x004D6BE0u, NativeCallingConvention::fastcall_call},
    {0x004D6C30u, NativeCallingConvention::thiscall_call},
    {0x004D6C80u, NativeCallingConvention::thiscall_call},
    {0x004D6CE0u, NativeCallingConvention::thiscall_call},
    {0x004D6D70u, NativeCallingConvention::thiscall_call},
    {0x004D6DE0u, NativeCallingConvention::thiscall_call},
    {0x004D7030u, NativeCallingConvention::thiscall_call},
    {0x004D72A0u, NativeCallingConvention::cdecl_call},
    {0x004D7300u, NativeCallingConvention::thiscall_call},
    {0x004D74D0u, NativeCallingConvention::thiscall_call},
    {0x004D7581u, NativeCallingConvention::cdecl_call},
    {0x004D75C0u, NativeCallingConvention::thiscall_call},
    {0x004D7790u, NativeCallingConvention::cdecl_call},
    {0x004D77B0u, NativeCallingConvention::cdecl_call},
    {0x004D77E0u, NativeCallingConvention::thiscall_call},
    {0x004D7980u, NativeCallingConvention::fastcall_call},
    {0x004D79F0u, NativeCallingConvention::fastcall_call},
    {0x004D7AF0u, NativeCallingConvention::thiscall_call},
    {0x004D7B50u, NativeCallingConvention::thiscall_call},
    {0x004D7BF0u, NativeCallingConvention::fastcall_call},
    {0x004D7C50u, NativeCallingConvention::thiscall_call},
    {0x004D7CB0u, NativeCallingConvention::fastcall_call},
    {0x004D7CF0u, NativeCallingConvention::cdecl_call},
    {0x004D7D00u, NativeCallingConvention::fastcall_call},
    {0x004D7D10u, NativeCallingConvention::cdecl_call},
    {0x004D7D60u, NativeCallingConvention::cdecl_call},
    {0x004D7DA0u, NativeCallingConvention::fastcall_call},
    {0x004D7DD0u, NativeCallingConvention::fastcall_call},
    {0x004D7E10u, NativeCallingConvention::cdecl_call},
    {0x004D7E30u, NativeCallingConvention::cdecl_call},
    {0x004D7E50u, NativeCallingConvention::fastcall_call},
    {0x004D7E60u, NativeCallingConvention::thiscall_call},
    {0x004D7F70u, NativeCallingConvention::fastcall_call},
    {0x004D7FB0u, NativeCallingConvention::thiscall_call},
    {0x004D8030u, NativeCallingConvention::fastcall_call},
    {0x004D80A0u, NativeCallingConvention::fastcall_call},
    {0x004D8100u, NativeCallingConvention::fastcall_call},
    {0x004D8140u, NativeCallingConvention::thiscall_call},
    {0x004D8160u, NativeCallingConvention::thiscall_call},
    {0x004D8180u, NativeCallingConvention::fastcall_call},
    {0x004D82D0u, NativeCallingConvention::fastcall_call},
    {0x004D82E0u, NativeCallingConvention::cdecl_call},
    {0x004D82F0u, NativeCallingConvention::cdecl_call},
    {0x004D8300u, NativeCallingConvention::cdecl_call},
    {0x004D8310u, NativeCallingConvention::fastcall_call},
    {0x004D8340u, NativeCallingConvention::thiscall_call},
    {0x004D8360u, NativeCallingConvention::fastcall_call},
    {0x004D8370u, NativeCallingConvention::thiscall_call},
    {0x004D84A0u, NativeCallingConvention::thiscall_call},
    {0x004D8560u, NativeCallingConvention::fastcall_call},
    {0x004D8740u, NativeCallingConvention::thiscall_call},
    {0x004D8790u, NativeCallingConvention::thiscall_call},
    {0x004D87E0u, NativeCallingConvention::thiscall_call},
    {0x004D8840u, NativeCallingConvention::fastcall_call},
    {0x004D8880u, NativeCallingConvention::thiscall_call},
    {0x004D88E0u, NativeCallingConvention::thiscall_call},
    {0x004D8950u, NativeCallingConvention::thiscall_call},
    {0x004D8970u, NativeCallingConvention::thiscall_call},
    {0x004D8990u, NativeCallingConvention::thiscall_call},
    {0x004D89E0u, NativeCallingConvention::thiscall_call},
    {0x004D8A40u, NativeCallingConvention::thiscall_call},
    {0x004D8AA0u, NativeCallingConvention::thiscall_call},
    {0x004D8AE0u, NativeCallingConvention::thiscall_call},
    {0x004D8B20u, NativeCallingConvention::thiscall_call},
    {0x004D8B70u, NativeCallingConvention::thiscall_call},
    {0x004D8BC0u, NativeCallingConvention::thiscall_call},
    {0x004D8C10u, NativeCallingConvention::thiscall_call},
    {0x004D8C60u, NativeCallingConvention::thiscall_call},
    {0x004D8CB0u, NativeCallingConvention::cdecl_call},
    {0x004D8CE0u, NativeCallingConvention::thiscall_call},
    {0x004D8D30u, NativeCallingConvention::thiscall_call},
    {0x004D8D80u, NativeCallingConvention::thiscall_call},
    {0x004D8DD0u, NativeCallingConvention::thiscall_call},
    {0x004D8E20u, NativeCallingConvention::thiscall_call},
    {0x004D8E70u, NativeCallingConvention::thiscall_call},
    {0x004D8ED0u, NativeCallingConvention::thiscall_call},
    {0x004D8F10u, NativeCallingConvention::thiscall_call},
    {0x004D8F40u, NativeCallingConvention::thiscall_call},
    {0x004D8F90u, NativeCallingConvention::thiscall_call},
    {0x004D8FE0u, NativeCallingConvention::thiscall_call},
    {0x004D9050u, NativeCallingConvention::thiscall_call},
    {0x004D90B0u, NativeCallingConvention::thiscall_call},
    {0x004D90F0u, NativeCallingConvention::thiscall_call},
    {0x004D9140u, NativeCallingConvention::thiscall_call},
    {0x004D9190u, NativeCallingConvention::fastcall_call},
    {0x004D91E0u, NativeCallingConvention::fastcall_call},
    {0x004D9200u, NativeCallingConvention::thiscall_call},
    {0x004D9250u, NativeCallingConvention::thiscall_call},
    {0x004D92A0u, NativeCallingConvention::thiscall_call},
    {0x004D9580u, NativeCallingConvention::thiscall_call},
    {0x004D9740u, NativeCallingConvention::fastcall_call},
    {0x004D97B0u, NativeCallingConvention::fastcall_call},
    {0x004D9820u, NativeCallingConvention::fastcall_call},
    {0x004D9840u, NativeCallingConvention::fastcall_call},
    {0x004D98D0u, NativeCallingConvention::thiscall_call},
    {0x004D9970u, NativeCallingConvention::fastcall_call},
    {0x004D9D60u, NativeCallingConvention::fastcall_call},
    {0x004D9DC0u, NativeCallingConvention::fastcall_call},
    {0x004D9E80u, NativeCallingConvention::thiscall_call},
    {0x004D9F50u, NativeCallingConvention::thiscall_call},
    {0x004D9FE0u, NativeCallingConvention::thiscall_call},
    {0x004DA310u, NativeCallingConvention::fastcall_call},
    {0x004DA3E0u, NativeCallingConvention::cdecl_call},
    {0x004DA450u, NativeCallingConvention::fastcall_call},
    {0x004DA490u, NativeCallingConvention::fastcall_call},
    {0x004DA4D0u, NativeCallingConvention::fastcall_call},
    {0x004DA510u, NativeCallingConvention::thiscall_call},
    {0x004DA590u, NativeCallingConvention::fastcall_call},
    {0x004DA670u, NativeCallingConvention::fastcall_call},
    {0x004DA720u, NativeCallingConvention::thiscall_call},
    {0x004DA7D0u, NativeCallingConvention::thiscall_call},
    {0x004DA880u, NativeCallingConvention::thiscall_call},
    {0x004DA940u, NativeCallingConvention::fastcall_call},
    {0x004DAA60u, NativeCallingConvention::fastcall_call},
    {0x004DABA0u, NativeCallingConvention::cdecl_call},
    {0x004DACD0u, NativeCallingConvention::fastcall_call},
    {0x004DAD30u, NativeCallingConvention::fastcall_call},
    {0x004DADA0u, NativeCallingConvention::thiscall_call},
    {0x004DAF50u, NativeCallingConvention::thiscall_call},
    {0x004DAF70u, NativeCallingConvention::fastcall_call},
    {0x004DB000u, NativeCallingConvention::cdecl_call},
    {0x004DB030u, NativeCallingConvention::fastcall_call},
    {0x004DB1F0u, NativeCallingConvention::cdecl_call},
    {0x004DB280u, NativeCallingConvention::cdecl_call},
    {0x004DB330u, NativeCallingConvention::fastcall_call},
    {0x004DB4C0u, NativeCallingConvention::fastcall_call},
    {0x004DB680u, NativeCallingConvention::thiscall_call},
    {0x004DB800u, NativeCallingConvention::thiscall_call},
    {0x004DB8A0u, NativeCallingConvention::thiscall_call},
    {0x004DB920u, NativeCallingConvention::thiscall_call},
    {0x004DB9A0u, NativeCallingConvention::thiscall_call},
    {0x004DBB00u, NativeCallingConvention::thiscall_call},
    {0x004DBBE0u, NativeCallingConvention::thiscall_call},
    {0x004DBDD0u, NativeCallingConvention::thiscall_call},
    {0x004DBFE0u, NativeCallingConvention::fastcall_call},
    {0x004DC1D0u, NativeCallingConvention::fastcall_call},
    {0x004DC380u, NativeCallingConvention::fastcall_call},
    {0x004DC520u, NativeCallingConvention::fastcall_call},
    {0x004DC710u, NativeCallingConvention::fastcall_call},
    {0x004DC8B0u, NativeCallingConvention::fastcall_call},
    {0x004DCA50u, NativeCallingConvention::fastcall_call},
    {0x004DCC00u, NativeCallingConvention::fastcall_call},
    {0x004DCDA0u, NativeCallingConvention::fastcall_call},
    {0x004DCF40u, NativeCallingConvention::fastcall_call},
    {0x004DD0E0u, NativeCallingConvention::fastcall_call},
    {0x004DD280u, NativeCallingConvention::fastcall_call},
    {0x004DD420u, NativeCallingConvention::cdecl_call},
    {0x004DD550u, NativeCallingConvention::cdecl_call},
    {0x004DD660u, NativeCallingConvention::thiscall_call},
    {0x004DD810u, NativeCallingConvention::cdecl_call},
    {0x004DD8E0u, NativeCallingConvention::cdecl_call},
    {0x004DD9D0u, NativeCallingConvention::cdecl_call},
    {0x004DDA3Bu, NativeCallingConvention::cdecl_call},
    {0x004DDAA4u, NativeCallingConvention::cdecl_call},
    {0x004DDC0Au, NativeCallingConvention::cdecl_call},
    {0x004DDC25u, NativeCallingConvention::cdecl_call},
    {0x004DE540u, NativeCallingConvention::cdecl_call},
    {0x004DE565u, NativeCallingConvention::cdecl_call},
    {0x004DE9F1u, NativeCallingConvention::cdecl_call},
    {0x004DEBDEu, NativeCallingConvention::cdecl_call},
    {0x004DEF60u, NativeCallingConvention::cdecl_call},
    {0x004DEFB0u, NativeCallingConvention::cdecl_call},
    {0x004DF075u, NativeCallingConvention::cdecl_call},
    {0x004DF3D2u, NativeCallingConvention::cdecl_call},
    {0x004DF4C0u, NativeCallingConvention::cdecl_call},
    {0x004DF700u, NativeCallingConvention::cdecl_call},
    {0x004DF93Bu, NativeCallingConvention::cdecl_call},
    {0x004DF9D3u, NativeCallingConvention::cdecl_call},
    {0x004DFF2Au, NativeCallingConvention::cdecl_call},
    {0x004E0259u, NativeCallingConvention::cdecl_call},
    {0x004E0950u, NativeCallingConvention::cdecl_call},
    {0x004E0A07u, NativeCallingConvention::thiscall_call},
    {0x004E0AFFu, NativeCallingConvention::cdecl_call},
    {0x004E1E72u, NativeCallingConvention::cdecl_call},
    {0x004E1F20u, NativeCallingConvention::cdecl_call},
    {0x004E21BEu, NativeCallingConvention::cdecl_call},
    {0x004E21E7u, NativeCallingConvention::cdecl_call},
    {0x004E2200u, NativeCallingConvention::cdecl_call},
    {0x004E2296u, NativeCallingConvention::cdecl_call},
    {0x004E229Bu, NativeCallingConvention::cdecl_call},
    {0x004E2364u, NativeCallingConvention::cdecl_call},
    {0x004E24A3u, NativeCallingConvention::cdecl_call},
    {0x004E2992u, NativeCallingConvention::cdecl_call},
    {0x004E2D4Eu, NativeCallingConvention::cdecl_call},
    {0x004E30EEu, NativeCallingConvention::cdecl_call},
    {0x004E328Du, NativeCallingConvention::cdecl_call},
    {0x004E35C0u, NativeCallingConvention::cdecl_call},
    {0x004E3685u, NativeCallingConvention::thiscall_call},
    {0x004E373Cu, NativeCallingConvention::cdecl_call},
    {0x004E38D9u, NativeCallingConvention::cdecl_call},
    {0x004E3DFCu, NativeCallingConvention::cdecl_call},
    {0x004E4A02u, NativeCallingConvention::cdecl_call},
    {0x004E524Au, NativeCallingConvention::cdecl_call},
    {0x004E52FCu, NativeCallingConvention::cdecl_call},
    {0x004E533Du, NativeCallingConvention::cdecl_call},
    {0x004E5426u, NativeCallingConvention::cdecl_call},
    {0x004E54E2u, NativeCallingConvention::cdecl_call},
    {0x004E5600u, NativeCallingConvention::thiscall_call},
    {0x004E5655u, NativeCallingConvention::cdecl_call},
    {0x004E63BDu, NativeCallingConvention::cdecl_call},
    {0x004E63E0u, NativeCallingConvention::cdecl_call},
    {0x004E6488u, NativeCallingConvention::cdecl_call},
    {0x004E6D56u, NativeCallingConvention::cdecl_call},
    {0x004E6EDBu, NativeCallingConvention::cdecl_call},
    {0x004E6F10u, NativeCallingConvention::cdecl_call},
    {0x004E70F0u, NativeCallingConvention::cdecl_call},
    {0x004E77D4u, NativeCallingConvention::cdecl_call},
    {0x004E77DAu, NativeCallingConvention::cdecl_call},
    {0x004E77E0u, NativeCallingConvention::cdecl_call},
    {0x004E77E6u, NativeCallingConvention::cdecl_call},
    {0x004E77ECu, NativeCallingConvention::cdecl_call},
    {0x004E77F2u, NativeCallingConvention::cdecl_call},
    {0x004E77F8u, NativeCallingConvention::cdecl_call},
    {0x004E77FEu, NativeCallingConvention::cdecl_call},
    {0x004E7804u, NativeCallingConvention::cdecl_call},
    {0x004E780Au, NativeCallingConvention::cdecl_call},
    {0x004E7810u, NativeCallingConvention::cdecl_call},
    {0x004E7816u, NativeCallingConvention::cdecl_call},
    {0x004E781Cu, NativeCallingConvention::cdecl_call},
    {0x004E7822u, NativeCallingConvention::cdecl_call},
    {0x004E7828u, NativeCallingConvention::cdecl_call},
    {0x004E782Eu, NativeCallingConvention::cdecl_call},
    {0x004E7834u, NativeCallingConvention::cdecl_call},
    {0x004E783Au, NativeCallingConvention::cdecl_call},
    {0x004E7840u, NativeCallingConvention::cdecl_call},
    {0x004E7846u, NativeCallingConvention::cdecl_call},
    {0x004E784Cu, NativeCallingConvention::cdecl_call},
    {0x004E7852u, NativeCallingConvention::cdecl_call},
    {0x004E7858u, NativeCallingConvention::cdecl_call},
    {0x004E785Eu, NativeCallingConvention::cdecl_call},
    {0x004E7864u, NativeCallingConvention::cdecl_call},
    {0x004E786Au, NativeCallingConvention::cdecl_call},
    {0x004E7870u, NativeCallingConvention::cdecl_call},
    {0x004E7876u, NativeCallingConvention::cdecl_call},
    {0x004E787Cu, NativeCallingConvention::cdecl_call},
    {0x004EA946u, NativeCallingConvention::cdecl_call},
    {0x004EA94Cu, NativeCallingConvention::cdecl_call},
    {0x004EA952u, NativeCallingConvention::cdecl_call},
    {0x004EA990u, NativeCallingConvention::cdecl_call},
    {0x004EAA20u, NativeCallingConvention::fastcall_call},
    {0x004EB1C0u, NativeCallingConvention::fastcall_call},
    {0x004EB1D0u, NativeCallingConvention::fastcall_call},
    {0x004EB300u, NativeCallingConvention::thiscall_call},
    {0x004EB520u, NativeCallingConvention::fastcall_call},
    {0x004EB8A0u, NativeCallingConvention::fastcall_call},
    {0x004EBD80u, NativeCallingConvention::cdecl_call},
    {0x004EBE20u, NativeCallingConvention::cdecl_call},
    {0x004EBE60u, NativeCallingConvention::fastcall_call},
    {0x004EBE80u, NativeCallingConvention::cdecl_call},
    {0x004EBEA0u, NativeCallingConvention::cdecl_call},
    {0x004EBEF0u, NativeCallingConvention::fastcall_call},
    {0x004EBF20u, NativeCallingConvention::fastcall_call},
    {0x004EBF30u, NativeCallingConvention::fastcall_call},
    {0x004EBF40u, NativeCallingConvention::cdecl_call},
    {0x004EC090u, NativeCallingConvention::fastcall_call},
    {0x004EC1C0u, NativeCallingConvention::fastcall_call},
    {0x004EC1E0u, NativeCallingConvention::fastcall_call},
    {0x004EC2E0u, NativeCallingConvention::cdecl_call},
    {0x004EC500u, NativeCallingConvention::thiscall_call},
    {0x004EC770u, NativeCallingConvention::cdecl_call},
    {0x004EC830u, NativeCallingConvention::fastcall_call},
    {0x004EC8C0u, NativeCallingConvention::thiscall_call},
    {0x004EC980u, NativeCallingConvention::fastcall_call},
    {0x004ECA00u, NativeCallingConvention::thiscall_call},
    {0x004ECAE0u, NativeCallingConvention::thiscall_call},
    {0x004ECBB0u, NativeCallingConvention::fastcall_call},
    {0x004ECE80u, NativeCallingConvention::cdecl_call},
    {0x004ECF60u, NativeCallingConvention::fastcall_call},
    {0x004ECFE0u, NativeCallingConvention::fastcall_call},
    {0x004ED100u, NativeCallingConvention::thiscall_call},
    {0x004ED150u, NativeCallingConvention::cdecl_call},
    {0x004ED380u, NativeCallingConvention::cdecl_call},
    {0x004ED390u, NativeCallingConvention::thiscall_call},
    {0x004ED410u, NativeCallingConvention::thiscall_call},
    {0x004ED470u, NativeCallingConvention::cdecl_call},
    {0x004ED5C0u, NativeCallingConvention::cdecl_call},
    {0x004ED5E0u, NativeCallingConvention::fastcall_call},
    {0x004ED620u, NativeCallingConvention::fastcall_call},
    {0x004ED770u, NativeCallingConvention::cdecl_call},
    {0x004ED790u, NativeCallingConvention::cdecl_call},
    {0x004ED7B0u, NativeCallingConvention::cdecl_call},
    {0x004ED7D0u, NativeCallingConvention::fastcall_call},
    {0x004ED7F0u, NativeCallingConvention::fastcall_call},
    {0x004ED860u, NativeCallingConvention::fastcall_call},
    {0x004ED8E0u, NativeCallingConvention::fastcall_call},
    {0x004ED930u, NativeCallingConvention::thiscall_call},
    {0x004EDA30u, NativeCallingConvention::thiscall_call},
    {0x004EDA50u, NativeCallingConvention::cdecl_call},
    {0x004EDA60u, NativeCallingConvention::thiscall_call},
    {0x004EDB10u, NativeCallingConvention::thiscall_call},
    {0x004EDC70u, NativeCallingConvention::thiscall_call},
    {0x004EDCE0u, NativeCallingConvention::thiscall_call},
    {0x004EDD40u, NativeCallingConvention::thiscall_call},
    {0x004EDDF0u, NativeCallingConvention::thiscall_call},
    {0x004EDE50u, NativeCallingConvention::thiscall_call},
    {0x004EDEF0u, NativeCallingConvention::thiscall_call},
    {0x004EE000u, NativeCallingConvention::fastcall_call},
    {0x004EE2C0u, NativeCallingConvention::cdecl_call},
    {0x004EE31Au, NativeCallingConvention::cdecl_call},
    {0x004EE390u, NativeCallingConvention::thiscall_call},
    {0x004EE470u, NativeCallingConvention::fastcall_call},
    {0x004EE4B0u, NativeCallingConvention::fastcall_call},
    {0x004EE4C0u, NativeCallingConvention::fastcall_call},
    {0x004EE4D0u, NativeCallingConvention::fastcall_call},
    {0x004EE540u, NativeCallingConvention::cdecl_call},
    {0x004EE5D0u, NativeCallingConvention::thiscall_call},
    {0x004EE690u, NativeCallingConvention::thiscall_call},
    {0x004EE7D0u, NativeCallingConvention::fastcall_call},
    {0x004EE7F2u, NativeCallingConvention::cdecl_call},
    {0x004EE7F8u, NativeCallingConvention::cdecl_call},
    {0x004EE7FEu, NativeCallingConvention::cdecl_call},
    {0x004EE804u, NativeCallingConvention::cdecl_call},
    {0x004EE80Au, NativeCallingConvention::cdecl_call},
    {0x004EE810u, NativeCallingConvention::fastcall_call},
    {0x004EE81Fu, NativeCallingConvention::cdecl_call},
    {0x004EE8B7u, NativeCallingConvention::cdecl_call},
    {0x004EE8C0u, NativeCallingConvention::cdecl_call},
    {0x004EE8D7u, NativeCallingConvention::thiscall_call},
    {0x004EE924u, NativeCallingConvention::cdecl_call},
    {0x004EE92Au, NativeCallingConvention::cdecl_call},
    {0x004EE930u, NativeCallingConvention::cdecl_call},
    {0x004EE940u, NativeCallingConvention::fastcall_call},
    {0x004EE976u, NativeCallingConvention::cdecl_call},
    {0x004EE9ECu, NativeCallingConvention::cdecl_call},
    {0x004EE9F2u, NativeCallingConvention::cdecl_call},
    {0x004EE9F8u, NativeCallingConvention::cdecl_call},
    {0x004EE9FEu, NativeCallingConvention::cdecl_call},
    {0x004EEA10u, NativeCallingConvention::cdecl_call},
    {0x004EEA40u, NativeCallingConvention::cdecl_call},
    {0x004EEAF0u, NativeCallingConvention::cdecl_call},
    {0x004EEB1Cu, NativeCallingConvention::cdecl_call},
    {0x004EEB22u, NativeCallingConvention::cdecl_call},
    {0x004EEB28u, NativeCallingConvention::cdecl_call},
    {0x004EEB4Bu, NativeCallingConvention::cdecl_call},
    {0x004EEB74u, NativeCallingConvention::cdecl_call},
    {0x004EEB86u, NativeCallingConvention::cdecl_call},
    {0x004EEBD1u, NativeCallingConvention::cdecl_call},
    {0x004EEBE9u, NativeCallingConvention::cdecl_call},
    {0x004EEC36u, NativeCallingConvention::cdecl_call},
    {0x004EEC4Eu, NativeCallingConvention::cdecl_call},
    {0x004EEC54u, NativeCallingConvention::cdecl_call},
    {0x004EEC60u, NativeCallingConvention::cdecl_call},
    {0x004EED20u, NativeCallingConvention::cdecl_call},
    {0x004EED54u, NativeCallingConvention::cdecl_call},
    {0x004EED5Au, NativeCallingConvention::cdecl_call},
    {0x004EED60u, NativeCallingConvention::cdecl_call},
    {0x004EED66u, NativeCallingConvention::cdecl_call},
    {0x004EED6Cu, NativeCallingConvention::cdecl_call},
    {0x004EED80u, NativeCallingConvention::cdecl_call},
    {0x004EEDF0u, NativeCallingConvention::fastcall_call},
    {0x004EEE10u, NativeCallingConvention::fastcall_call},
    {0x004EEE30u, NativeCallingConvention::cdecl_call},
    {0x004EEE36u, NativeCallingConvention::cdecl_call},
    {0x004EEE3Cu, NativeCallingConvention::cdecl_call},
    {0x004EEE61u, NativeCallingConvention::cdecl_call},
    {0x004EF038u, NativeCallingConvention::cdecl_call},
    {0x004EF04Cu, NativeCallingConvention::cdecl_call},
    {0x004EF088u, NativeCallingConvention::cdecl_call},
    {0x004EF142u, NativeCallingConvention::cdecl_call},
    {0x004EF14Cu, NativeCallingConvention::cdecl_call},
    {0x004EF258u, NativeCallingConvention::cdecl_call},
    {0x004EF25Eu, NativeCallingConvention::cdecl_call},
    {0x004EF264u, NativeCallingConvention::cdecl_call},
    {0x004EF270u, NativeCallingConvention::cdecl_call},
    {0x004EF2B5u, NativeCallingConvention::cdecl_call},
    {0x004EF2C9u, NativeCallingConvention::cdecl_call},
    {0x004EF2DAu, NativeCallingConvention::cdecl_call},
    {0x004EF2E0u, NativeCallingConvention::cdecl_call},
    {0x004EF2E6u, NativeCallingConvention::cdecl_call},
    {0x004EF328u, NativeCallingConvention::cdecl_call},
    {0x004EF336u, NativeCallingConvention::cdecl_call},
    {0x004EF33Cu, NativeCallingConvention::cdecl_call},
    {0x004EF362u, NativeCallingConvention::cdecl_call},
    {0x004EF388u, NativeCallingConvention::cdecl_call},
    {0x004EF390u, NativeCallingConvention::cdecl_call},
    {0x004EF3D0u, NativeCallingConvention::cdecl_call},
    {0x004EF420u, NativeCallingConvention::cdecl_call},
    {0x004EF4ABu, NativeCallingConvention::cdecl_call},
    {0x004EF4BEu, NativeCallingConvention::cdecl_call},
    {0x004EF4DCu, NativeCallingConvention::cdecl_call},
    {0x004EF4E2u, NativeCallingConvention::cdecl_call},
    {0x004EF4E8u, NativeCallingConvention::cdecl_call},
    {0x004EF510u, NativeCallingConvention::cdecl_call},
    {0x004EF513u, NativeCallingConvention::cdecl_call},
    {0x004EF5AEu, NativeCallingConvention::cdecl_call},
    {0x004EF5B4u, NativeCallingConvention::cdecl_call},
    {0x004EF5BAu, NativeCallingConvention::cdecl_call},
    {0x004EF5C0u, NativeCallingConvention::cdecl_call},
    {0x004EF5C6u, NativeCallingConvention::cdecl_call},
    {0x004EF5DCu, NativeCallingConvention::cdecl_call},
    {0x004EF656u, NativeCallingConvention::cdecl_call},
    {0x004EF65Cu, NativeCallingConvention::cdecl_call},
    {0x004EF662u, NativeCallingConvention::cdecl_call},
    {0x004EF668u, NativeCallingConvention::cdecl_call},
    {0x004EF66Eu, NativeCallingConvention::cdecl_call},
    {0x004EF674u, NativeCallingConvention::cdecl_call},
    {0x004EF67Au, NativeCallingConvention::cdecl_call},
    {0x004EF680u, NativeCallingConvention::cdecl_call},
    {0x004EF686u, NativeCallingConvention::cdecl_call},
    {0x004EF690u, NativeCallingConvention::fastcall_call},
    {0x004EF6C0u, NativeCallingConvention::cdecl_call},
    {0x004EF700u, NativeCallingConvention::thiscall_call},
    {0x004EF740u, NativeCallingConvention::thiscall_call},
    {0x004EF781u, NativeCallingConvention::cdecl_call},
    {0x004EF7B4u, NativeCallingConvention::cdecl_call},
    {0x004EF7D0u, NativeCallingConvention::cdecl_call},
    {0x004EF7D8u, NativeCallingConvention::cdecl_call},
    {0x004EF800u, NativeCallingConvention::cdecl_call},
    {0x004EF820u, NativeCallingConvention::cdecl_call},
    {0x004EF840u, NativeCallingConvention::cdecl_call},
    {0x004EF860u, NativeCallingConvention::cdecl_call},
    {0x004EF868u, NativeCallingConvention::cdecl_call},
    {0x004EF870u, NativeCallingConvention::cdecl_call},
    {0x004EF878u, NativeCallingConvention::cdecl_call},
    {0x004EF8A0u, NativeCallingConvention::cdecl_call},
    {0x004EF8A8u, NativeCallingConvention::cdecl_call},
    {0x004EF8D0u, NativeCallingConvention::cdecl_call},
    {0x004EF8D8u, NativeCallingConvention::cdecl_call},
    {0x004EF900u, NativeCallingConvention::cdecl_call},
    {0x004EF908u, NativeCallingConvention::cdecl_call},
    {0x004EF910u, NativeCallingConvention::cdecl_call},
    {0x004EF930u, NativeCallingConvention::cdecl_call},
    {0x004EF938u, NativeCallingConvention::cdecl_call},
    {0x004EF960u, NativeCallingConvention::cdecl_call},
    {0x004EF968u, NativeCallingConvention::cdecl_call},
    {0x004EF990u, NativeCallingConvention::cdecl_call},
    {0x004EF998u, NativeCallingConvention::cdecl_call},
    {0x004EF9C0u, NativeCallingConvention::cdecl_call},
    {0x004EF9D1u, NativeCallingConvention::cdecl_call},
    {0x004EF9F0u, NativeCallingConvention::cdecl_call},
    {0x004EFA01u, NativeCallingConvention::cdecl_call},
    {0x004EFA20u, NativeCallingConvention::cdecl_call},
    {0x004EFA31u, NativeCallingConvention::cdecl_call},
    {0x004EFA50u, NativeCallingConvention::cdecl_call},
    {0x004EFA58u, NativeCallingConvention::cdecl_call},
    {0x004EFA60u, NativeCallingConvention::cdecl_call},
    {0x004EFA80u, NativeCallingConvention::cdecl_call},
    {0x004EFA91u, NativeCallingConvention::cdecl_call},
    {0x004EFAB0u, NativeCallingConvention::cdecl_call},
    {0x004EFAC1u, NativeCallingConvention::cdecl_call},
    {0x004EFAE0u, NativeCallingConvention::cdecl_call},
    {0x004EFAF1u, NativeCallingConvention::cdecl_call},
    {0x004EFB10u, NativeCallingConvention::cdecl_call},
    {0x004EFB21u, NativeCallingConvention::cdecl_call},
    {0x004EFB29u, NativeCallingConvention::cdecl_call},
    {0x004EFB50u, NativeCallingConvention::cdecl_call},
    {0x004EFB61u, NativeCallingConvention::cdecl_call},
    {0x004EFB80u, NativeCallingConvention::cdecl_call},
    {0x004EFB88u, NativeCallingConvention::cdecl_call},
    {0x004EFB90u, NativeCallingConvention::cdecl_call},
    {0x004EFB98u, NativeCallingConvention::cdecl_call},
    {0x004EFBA0u, NativeCallingConvention::cdecl_call},
    {0x004EFBD0u, NativeCallingConvention::cdecl_call},
    {0x004EFBF0u, NativeCallingConvention::cdecl_call},
    {0x004EFC01u, NativeCallingConvention::cdecl_call},
    {0x004EFC20u, NativeCallingConvention::cdecl_call},
    {0x004EFC31u, NativeCallingConvention::cdecl_call},
    {0x004EFC50u, NativeCallingConvention::cdecl_call},
    {0x004EFC61u, NativeCallingConvention::cdecl_call},
    {0x004EFC80u, NativeCallingConvention::cdecl_call},
    {0x004EFC91u, NativeCallingConvention::cdecl_call},
    {0x004EFC99u, NativeCallingConvention::cdecl_call},
    {0x004EFCC0u, NativeCallingConvention::cdecl_call},
    {0x004EFCD1u, NativeCallingConvention::cdecl_call},
    {0x004EFCF0u, NativeCallingConvention::cdecl_call},
    {0x004EFD01u, NativeCallingConvention::cdecl_call},
    {0x004EFD09u, NativeCallingConvention::cdecl_call},
    {0x004EFD30u, NativeCallingConvention::cdecl_call},
    {0x004EFD38u, NativeCallingConvention::cdecl_call},
    {0x004EFD40u, NativeCallingConvention::cdecl_call},
    {0x004EFD48u, NativeCallingConvention::cdecl_call},
    {0x004EFD70u, NativeCallingConvention::cdecl_call},
    {0x004EFD78u, NativeCallingConvention::cdecl_call},
    {0x004EFDA0u, NativeCallingConvention::cdecl_call},
    {0x004EFDA8u, NativeCallingConvention::cdecl_call},
    {0x004EFDB0u, NativeCallingConvention::cdecl_call},
    {0x004EFDD0u, NativeCallingConvention::cdecl_call},
    {0x004EFDD8u, NativeCallingConvention::cdecl_call},
    {0x004EFDE0u, NativeCallingConvention::cdecl_call},
    {0x004EFE00u, NativeCallingConvention::cdecl_call},
    {0x004EFE08u, NativeCallingConvention::cdecl_call},
    {0x004EFE30u, NativeCallingConvention::cdecl_call},
    {0x004EFE38u, NativeCallingConvention::cdecl_call},
    {0x004EFE60u, NativeCallingConvention::cdecl_call},
    {0x004EFE68u, NativeCallingConvention::cdecl_call},
    {0x004EFE70u, NativeCallingConvention::cdecl_call},
    {0x004EFEA0u, NativeCallingConvention::cdecl_call},
    {0x004EFEA8u, NativeCallingConvention::cdecl_call},
    {0x004EFEB0u, NativeCallingConvention::cdecl_call},
    {0x004EFEB8u, NativeCallingConvention::cdecl_call},
    {0x004EFEE0u, NativeCallingConvention::cdecl_call},
    {0x004EFEE8u, NativeCallingConvention::cdecl_call},
    {0x004EFEF0u, NativeCallingConvention::cdecl_call},
    {0x004EFEF8u, NativeCallingConvention::cdecl_call},
    {0x004EFF20u, NativeCallingConvention::cdecl_call},
    {0x004EFF28u, NativeCallingConvention::cdecl_call},
    {0x004EFF30u, NativeCallingConvention::cdecl_call},
    {0x004EFF38u, NativeCallingConvention::cdecl_call},
    {0x004EFF60u, NativeCallingConvention::cdecl_call},
    {0x004EFF68u, NativeCallingConvention::cdecl_call},
    {0x004EFF90u, NativeCallingConvention::cdecl_call},
    {0x004EFF98u, NativeCallingConvention::cdecl_call},
    {0x004EFFA0u, NativeCallingConvention::cdecl_call},
    {0x004EFFA8u, NativeCallingConvention::cdecl_call},
    {0x004EFFB0u, NativeCallingConvention::cdecl_call},
    {0x004EFFD0u, NativeCallingConvention::cdecl_call},
    {0x004EFFD8u, NativeCallingConvention::cdecl_call},
    {0x004F0000u, NativeCallingConvention::cdecl_call},
    {0x004F0008u, NativeCallingConvention::cdecl_call},
    {0x004F0030u, NativeCallingConvention::cdecl_call},
    {0x004F0038u, NativeCallingConvention::cdecl_call},
    {0x004F0040u, NativeCallingConvention::cdecl_call},
    {0x004F0070u, NativeCallingConvention::cdecl_call},
    {0x004F0078u, NativeCallingConvention::cdecl_call},
    {0x004F0080u, NativeCallingConvention::cdecl_call},
    {0x004F0088u, NativeCallingConvention::cdecl_call},
    {0x004F00B0u, NativeCallingConvention::cdecl_call},
    {0x004F00B8u, NativeCallingConvention::cdecl_call},
    {0x004F00C0u, NativeCallingConvention::cdecl_call},
    {0x004F00C8u, NativeCallingConvention::cdecl_call},
    {0x004F00F0u, NativeCallingConvention::cdecl_call},
    {0x004F00F8u, NativeCallingConvention::cdecl_call},
    {0x004F0100u, NativeCallingConvention::cdecl_call},
    {0x004F0130u, NativeCallingConvention::cdecl_call},
    {0x004F0138u, NativeCallingConvention::cdecl_call},
    {0x004F0140u, NativeCallingConvention::cdecl_call},
    {0x004F0148u, NativeCallingConvention::cdecl_call},
    {0x004F0170u, NativeCallingConvention::cdecl_call},
    {0x004F0178u, NativeCallingConvention::cdecl_call},
    {0x004F0180u, NativeCallingConvention::cdecl_call},
    {0x004F0188u, NativeCallingConvention::cdecl_call},
    {0x004F01B0u, NativeCallingConvention::cdecl_call},
    {0x004F01B8u, NativeCallingConvention::cdecl_call},
    {0x004F01C0u, NativeCallingConvention::cdecl_call},
    {0x004F01C8u, NativeCallingConvention::cdecl_call},
    {0x004F01F0u, NativeCallingConvention::cdecl_call},
    {0x004F01F8u, NativeCallingConvention::cdecl_call},
    {0x004F0220u, NativeCallingConvention::cdecl_call},
    {0x004F0228u, NativeCallingConvention::cdecl_call},
    {0x004F0230u, NativeCallingConvention::cdecl_call},
    {0x004F0238u, NativeCallingConvention::cdecl_call},
    {0x004F0240u, NativeCallingConvention::cdecl_call},
    {0x004F0270u, NativeCallingConvention::cdecl_call},
    {0x004F0278u, NativeCallingConvention::cdecl_call},
    {0x004F0280u, NativeCallingConvention::cdecl_call},
    {0x004F0288u, NativeCallingConvention::cdecl_call},
    {0x004F0290u, NativeCallingConvention::cdecl_call},
    {0x004F02C0u, NativeCallingConvention::cdecl_call},
    {0x004F02C8u, NativeCallingConvention::cdecl_call},
    {0x004F02D0u, NativeCallingConvention::cdecl_call},
    {0x004F02D8u, NativeCallingConvention::cdecl_call},
    {0x004F02E0u, NativeCallingConvention::cdecl_call},
    {0x004F0310u, NativeCallingConvention::cdecl_call},
    {0x004F0318u, NativeCallingConvention::cdecl_call},
    {0x004F0323u, NativeCallingConvention::cdecl_call},
    {0x004F0340u, NativeCallingConvention::cdecl_call},
    {0x004F0348u, NativeCallingConvention::cdecl_call},
    {0x004F0353u, NativeCallingConvention::cdecl_call},
    {0x004F0370u, NativeCallingConvention::cdecl_call},
    {0x004F0378u, NativeCallingConvention::cdecl_call},
    {0x004F0383u, NativeCallingConvention::cdecl_call},
    {0x004F03A0u, NativeCallingConvention::cdecl_call},
    {0x004F03ABu, NativeCallingConvention::cdecl_call},
    {0x004F03B6u, NativeCallingConvention::cdecl_call},
    {0x004F03C1u, NativeCallingConvention::cdecl_call},
    {0x004F03CCu, NativeCallingConvention::cdecl_call},
    {0x004F03F0u, NativeCallingConvention::cdecl_call},
    {0x004F03F8u, NativeCallingConvention::cdecl_call},
    {0x004F0403u, NativeCallingConvention::cdecl_call},
    {0x004F0420u, NativeCallingConvention::cdecl_call},
    {0x004F0428u, NativeCallingConvention::cdecl_call},
    {0x004F0450u, NativeCallingConvention::cdecl_call},
    {0x004F0458u, NativeCallingConvention::cdecl_call},
    {0x004F0463u, NativeCallingConvention::cdecl_call},
    {0x004F0480u, NativeCallingConvention::cdecl_call},
    {0x004F0488u, NativeCallingConvention::cdecl_call},
    {0x004F0493u, NativeCallingConvention::cdecl_call},
    {0x004F04B0u, NativeCallingConvention::cdecl_call},
    {0x004F04B8u, NativeCallingConvention::cdecl_call},
    {0x004F04C3u, NativeCallingConvention::cdecl_call},
    {0x004F04E0u, NativeCallingConvention::cdecl_call},
    {0x004F04E8u, NativeCallingConvention::cdecl_call},
    {0x004F04F3u, NativeCallingConvention::cdecl_call},
    {0x004F0510u, NativeCallingConvention::cdecl_call},
    {0x004F0518u, NativeCallingConvention::cdecl_call},
    {0x004F0523u, NativeCallingConvention::cdecl_call},
    {0x004F0540u, NativeCallingConvention::cdecl_call},
    {0x004F054Bu, NativeCallingConvention::cdecl_call},
    {0x004F0556u, NativeCallingConvention::cdecl_call},
    {0x004F0580u, NativeCallingConvention::cdecl_call},
    {0x004F0588u, NativeCallingConvention::cdecl_call},
    {0x004F0593u, NativeCallingConvention::cdecl_call},
    {0x004F05B0u, NativeCallingConvention::cdecl_call},
    {0x004F05B8u, NativeCallingConvention::cdecl_call},
    {0x004F05C3u, NativeCallingConvention::cdecl_call},
    {0x004F05E0u, NativeCallingConvention::cdecl_call},
    {0x004F05E8u, NativeCallingConvention::cdecl_call},
    {0x004F05F0u, NativeCallingConvention::cdecl_call},
    {0x004F0610u, NativeCallingConvention::cdecl_call},
    {0x004F0618u, NativeCallingConvention::cdecl_call},
    {0x004F0640u, NativeCallingConvention::cdecl_call},
    {0x004F0648u, NativeCallingConvention::cdecl_call},
    {0x004F0653u, NativeCallingConvention::cdecl_call},
    {0x004F065Eu, NativeCallingConvention::cdecl_call},
    {0x004F0669u, NativeCallingConvention::cdecl_call},
    {0x004F0690u, NativeCallingConvention::cdecl_call},
    {0x004F0698u, NativeCallingConvention::cdecl_call},
    {0x004F06A3u, NativeCallingConvention::cdecl_call},
    {0x004F06AEu, NativeCallingConvention::cdecl_call},
    {0x004F06B9u, NativeCallingConvention::cdecl_call},
    {0x004F06E0u, NativeCallingConvention::cdecl_call},
    {0x004F06E8u, NativeCallingConvention::cdecl_call},
    {0x004F06F3u, NativeCallingConvention::cdecl_call},
    {0x004F06FEu, NativeCallingConvention::cdecl_call},
    {0x004F0709u, NativeCallingConvention::cdecl_call},
    {0x004F0730u, NativeCallingConvention::cdecl_call},
    {0x004F0738u, NativeCallingConvention::cdecl_call},
    {0x004F0743u, NativeCallingConvention::cdecl_call},
    {0x004F074Eu, NativeCallingConvention::cdecl_call},
    {0x004F0759u, NativeCallingConvention::cdecl_call},
    {0x004F0780u, NativeCallingConvention::cdecl_call},
    {0x004F0788u, NativeCallingConvention::cdecl_call},
    {0x004F07B0u, NativeCallingConvention::cdecl_call},
    {0x004F07B8u, NativeCallingConvention::cdecl_call},
    {0x004F07C3u, NativeCallingConvention::cdecl_call},
    {0x004F07CEu, NativeCallingConvention::cdecl_call},
    {0x004F07D9u, NativeCallingConvention::cdecl_call},
    {0x004F0800u, NativeCallingConvention::cdecl_call},
    {0x004F0808u, NativeCallingConvention::cdecl_call},
    {0x004F0813u, NativeCallingConvention::cdecl_call},
    {0x004F081Eu, NativeCallingConvention::cdecl_call},
    {0x004F0829u, NativeCallingConvention::cdecl_call},
    {0x004F0850u, NativeCallingConvention::cdecl_call},
    {0x004F0858u, NativeCallingConvention::cdecl_call},
    {0x004F0863u, NativeCallingConvention::cdecl_call},
    {0x004F086Eu, NativeCallingConvention::cdecl_call},
    {0x004F0879u, NativeCallingConvention::cdecl_call},
    {0x004F08A0u, NativeCallingConvention::cdecl_call},
    {0x004F08A8u, NativeCallingConvention::cdecl_call},
    {0x004F08B3u, NativeCallingConvention::cdecl_call},
    {0x004F08BEu, NativeCallingConvention::cdecl_call},
    {0x004F08C9u, NativeCallingConvention::cdecl_call},
    {0x004F08F0u, NativeCallingConvention::cdecl_call},
    {0x004F08F8u, NativeCallingConvention::cdecl_call},
    {0x004F0903u, NativeCallingConvention::cdecl_call},
    {0x004F090Eu, NativeCallingConvention::cdecl_call},
    {0x004F0919u, NativeCallingConvention::cdecl_call},
    {0x004F0940u, NativeCallingConvention::cdecl_call},
    {0x004F094Bu, NativeCallingConvention::cdecl_call},
    {0x004F0956u, NativeCallingConvention::cdecl_call},
    {0x004F0961u, NativeCallingConvention::cdecl_call},
    {0x004F0980u, NativeCallingConvention::cdecl_call},
    {0x004F0988u, NativeCallingConvention::cdecl_call},
    {0x004F0990u, NativeCallingConvention::cdecl_call},
    {0x004F09B0u, NativeCallingConvention::cdecl_call},
    {0x004F09B8u, NativeCallingConvention::cdecl_call},
    {0x004F09C3u, NativeCallingConvention::cdecl_call},
    {0x004F09E0u, NativeCallingConvention::cdecl_call},
    {0x004F09E8u, NativeCallingConvention::cdecl_call},
    {0x004F0A10u, NativeCallingConvention::cdecl_call},
    {0x004F0A18u, NativeCallingConvention::cdecl_call},
    {0x004F0A23u, NativeCallingConvention::cdecl_call},
    {0x004F0A40u, NativeCallingConvention::cdecl_call},
    {0x004F0A48u, NativeCallingConvention::cdecl_call},
    {0x004F0A53u, NativeCallingConvention::cdecl_call},
    {0x004F0A70u, NativeCallingConvention::cdecl_call},
    {0x004F0A7Bu, NativeCallingConvention::cdecl_call},
    {0x004F0A86u, NativeCallingConvention::cdecl_call},
    {0x004F0A91u, NativeCallingConvention::cdecl_call},
    {0x004F0A9Cu, NativeCallingConvention::cdecl_call},
    {0x004F0AA7u, NativeCallingConvention::cdecl_call},
    {0x004F0AD0u, NativeCallingConvention::cdecl_call},
    {0x004F0AD8u, NativeCallingConvention::cdecl_call},
    {0x004F0B00u, NativeCallingConvention::cdecl_call},
    {0x004F0B08u, NativeCallingConvention::cdecl_call},
    {0x004F0B30u, NativeCallingConvention::cdecl_call},
    {0x004F0B38u, NativeCallingConvention::cdecl_call},
    {0x004F0B60u, NativeCallingConvention::cdecl_call},
    {0x004F0B6Bu, NativeCallingConvention::cdecl_call},
    {0x004F0BA0u, NativeCallingConvention::cdecl_call},
    {0x004F0BABu, NativeCallingConvention::cdecl_call},
    {0x004F0BD0u, NativeCallingConvention::cdecl_call},
    {0x004F0BDBu, NativeCallingConvention::cdecl_call},
    {0x004F0C00u, NativeCallingConvention::cdecl_call},
    {0x004F0C08u, NativeCallingConvention::cdecl_call},
    {0x004F0C30u, NativeCallingConvention::cdecl_call},
    {0x004F0C3Bu, NativeCallingConvention::cdecl_call},
    {0x004F0C46u, NativeCallingConvention::cdecl_call},
    {0x004F0C80u, NativeCallingConvention::cdecl_call},
    {0x004F0C8Bu, NativeCallingConvention::cdecl_call},
    {0x004F0CC0u, NativeCallingConvention::cdecl_call},
    {0x004F0CCBu, NativeCallingConvention::cdecl_call},
    {0x004F0CF0u, NativeCallingConvention::cdecl_call},
    {0x004F0CFBu, NativeCallingConvention::cdecl_call},
    {0x004F0D06u, NativeCallingConvention::cdecl_call},
    {0x004F0D11u, NativeCallingConvention::cdecl_call},
    {0x004F0D1Cu, NativeCallingConvention::cdecl_call},
    {0x004F0D27u, NativeCallingConvention::cdecl_call},
    {0x004F0D50u, NativeCallingConvention::cdecl_call},
    {0x004F0D5Eu, NativeCallingConvention::cdecl_call},
    {0x004F0D6Cu, NativeCallingConvention::cdecl_call},
    {0x004F0D7Au, NativeCallingConvention::cdecl_call},
    {0x004F0D88u, NativeCallingConvention::cdecl_call},
    {0x004F0D96u, NativeCallingConvention::cdecl_call},
    {0x004F0DA4u, NativeCallingConvention::cdecl_call},
    {0x004F0DE0u, NativeCallingConvention::cdecl_call},
    {0x004F0DE8u, NativeCallingConvention::cdecl_call},
    {0x004F0E10u, NativeCallingConvention::cdecl_call},
    {0x004F0E1Bu, NativeCallingConvention::cdecl_call},
    {0x004F0E26u, NativeCallingConvention::cdecl_call},
    {0x004F0E31u, NativeCallingConvention::cdecl_call},
    {0x004F0E3Cu, NativeCallingConvention::cdecl_call},
    {0x004F0E47u, NativeCallingConvention::cdecl_call},
    {0x004F0E52u, NativeCallingConvention::cdecl_call},
    {0x004F0E5Du, NativeCallingConvention::cdecl_call},
    {0x004F0E68u, NativeCallingConvention::cdecl_call},
    {0x004F0E90u, NativeCallingConvention::cdecl_call},
    {0x004F0E9Au, NativeCallingConvention::cdecl_call},
    {0x004F0EC0u, NativeCallingConvention::cdecl_call},
    {0x004F0ECAu, NativeCallingConvention::cdecl_call},
    {0x004F0EF0u, NativeCallingConvention::cdecl_call},
    {0x004F0EFBu, NativeCallingConvention::cdecl_call},
    {0x004F0F20u, NativeCallingConvention::cdecl_call},
    {0x004F0F28u, NativeCallingConvention::cdecl_call},
    {0x004F0F50u, NativeCallingConvention::cdecl_call},
    {0x004F0F58u, NativeCallingConvention::cdecl_call},
    {0x004F0F80u, NativeCallingConvention::cdecl_call},
    {0x004F0F88u, NativeCallingConvention::cdecl_call},
    {0x004F0FB0u, NativeCallingConvention::cdecl_call},
    {0x004F0FB8u, NativeCallingConvention::cdecl_call},
    {0x004F0FE0u, NativeCallingConvention::cdecl_call},
    {0x004F0FEBu, NativeCallingConvention::cdecl_call},
    {0x004F0FF6u, NativeCallingConvention::cdecl_call},
    {0x004F1020u, NativeCallingConvention::cdecl_call},
    {0x004F1028u, NativeCallingConvention::cdecl_call},
    {0x004F1050u, NativeCallingConvention::cdecl_call},
    {0x004F1058u, NativeCallingConvention::cdecl_call},
    {0x004F1080u, NativeCallingConvention::cdecl_call},
    {0x004F108Eu, NativeCallingConvention::cdecl_call},
    {0x004F10C0u, NativeCallingConvention::cdecl_call},
    {0x004F10CEu, NativeCallingConvention::cdecl_call},
    {0x004F10F0u, NativeCallingConvention::cdecl_call},
    {0x004F10FBu, NativeCallingConvention::cdecl_call},
    {0x004F1120u, NativeCallingConvention::cdecl_call},
    {0x004F112Bu, NativeCallingConvention::cdecl_call},
    {0x004F1136u, NativeCallingConvention::cdecl_call},
    {0x004F1170u, NativeCallingConvention::cdecl_call},
    {0x004F117Eu, NativeCallingConvention::cdecl_call},
    {0x004F118Cu, NativeCallingConvention::cdecl_call},
    {0x004F11C0u, NativeCallingConvention::cdecl_call},
    {0x004F11C8u, NativeCallingConvention::cdecl_call},
    {0x004F11D0u, NativeCallingConvention::cdecl_call},
    {0x004F1200u, NativeCallingConvention::cdecl_call},
    {0x004F1208u, NativeCallingConvention::cdecl_call},
    {0x004F1230u, NativeCallingConvention::cdecl_call},
    {0x004F1238u, NativeCallingConvention::cdecl_call},
    {0x004F1240u, NativeCallingConvention::cdecl_call},
    {0x004F1270u, NativeCallingConvention::cdecl_call},
    {0x004F127Eu, NativeCallingConvention::cdecl_call},
    {0x004F12A0u, NativeCallingConvention::cdecl_call},
    {0x004F12A8u, NativeCallingConvention::cdecl_call},
    {0x004F12B0u, NativeCallingConvention::cdecl_call},
    {0x004F12E0u, NativeCallingConvention::cdecl_call},
    {0x004F12E8u, NativeCallingConvention::cdecl_call},
    {0x004F12F0u, NativeCallingConvention::cdecl_call},
    {0x004F1320u, NativeCallingConvention::cdecl_call},
    {0x004F1328u, NativeCallingConvention::cdecl_call},
    {0x004F1350u, NativeCallingConvention::cdecl_call},
    {0x004F135Bu, NativeCallingConvention::cdecl_call},
    {0x004F1366u, NativeCallingConvention::cdecl_call},
    {0x004F1371u, NativeCallingConvention::cdecl_call},
    {0x004F137Cu, NativeCallingConvention::cdecl_call},
    {0x004F1387u, NativeCallingConvention::cdecl_call},
    {0x004F1392u, NativeCallingConvention::cdecl_call},
    {0x004F139Du, NativeCallingConvention::cdecl_call},
    {0x004F13D0u, NativeCallingConvention::cdecl_call},
    {0x004F13DBu, NativeCallingConvention::cdecl_call},
    {0x004F13E9u, NativeCallingConvention::cdecl_call},
    {0x004F13F7u, NativeCallingConvention::cdecl_call},
    {0x004F1430u, NativeCallingConvention::cdecl_call},
    {0x004F143Eu, NativeCallingConvention::cdecl_call},
    {0x004F1460u, NativeCallingConvention::cdecl_call},
    {0x004F1468u, NativeCallingConvention::cdecl_call},
    {0x004F1490u, NativeCallingConvention::cdecl_call},
    {0x004F1498u, NativeCallingConvention::cdecl_call},
    {0x004F14A0u, NativeCallingConvention::cdecl_call},
    {0x004F14D0u, NativeCallingConvention::cdecl_call},
    {0x004F14DEu, NativeCallingConvention::cdecl_call},
    {0x004F1510u, NativeCallingConvention::cdecl_call},
    {0x004F151Eu, NativeCallingConvention::cdecl_call},
    {0x004F152Cu, NativeCallingConvention::cdecl_call},
    {0x004F153Au, NativeCallingConvention::cdecl_call},
    {0x004F1548u, NativeCallingConvention::cdecl_call},
    {0x004F1556u, NativeCallingConvention::cdecl_call},
    {0x004F1564u, NativeCallingConvention::cdecl_call},
    {0x004F1572u, NativeCallingConvention::cdecl_call},
    {0x004F1580u, NativeCallingConvention::cdecl_call},
    {0x004F15B0u, NativeCallingConvention::cdecl_call},
    {0x004F15BAu, NativeCallingConvention::cdecl_call},
    {0x004F15E0u, NativeCallingConvention::cdecl_call},
    {0x004F15EBu, NativeCallingConvention::cdecl_call},
    {0x004F15F6u, NativeCallingConvention::cdecl_call},
    {0x004F1620u, NativeCallingConvention::cdecl_call},
    {0x004F162Bu, NativeCallingConvention::cdecl_call},
    {0x004F1636u, NativeCallingConvention::cdecl_call},
    {0x004F1670u, NativeCallingConvention::cdecl_call},
    {0x004F167Bu, NativeCallingConvention::cdecl_call},
    {0x004F16B0u, NativeCallingConvention::cdecl_call},
    {0x004F16BBu, NativeCallingConvention::cdecl_call},
    {0x004F16F0u, NativeCallingConvention::cdecl_call},
    {0x004F16FBu, NativeCallingConvention::cdecl_call},
    {0x004F1730u, NativeCallingConvention::cdecl_call},
    {0x004F173Eu, NativeCallingConvention::cdecl_call},
    {0x004F174Cu, NativeCallingConvention::cdecl_call},
    {0x004F175Au, NativeCallingConvention::cdecl_call},
    {0x004F1790u, NativeCallingConvention::cdecl_call},
    {0x004F179Bu, NativeCallingConvention::cdecl_call},
    {0x004F17D0u, NativeCallingConvention::cdecl_call},
    {0x004F17DEu, NativeCallingConvention::cdecl_call},
    {0x004F1800u, NativeCallingConvention::cdecl_call},
    {0x004F1811u, NativeCallingConvention::cdecl_call},
    {0x004F1840u, NativeCallingConvention::cdecl_call},
    {0x004F1860u, NativeCallingConvention::cdecl_call},
    {0x004F1868u, NativeCallingConvention::cdecl_call},
    {0x004F1873u, NativeCallingConvention::cdecl_call},
    {0x004F18A0u, NativeCallingConvention::cdecl_call},
    {0x004F18A8u, NativeCallingConvention::cdecl_call},
    {0x004F18D0u, NativeCallingConvention::cdecl_call},
    {0x004F18D8u, NativeCallingConvention::cdecl_call},
    {0x004F1900u, NativeCallingConvention::cdecl_call},
    {0x004F1919u, NativeCallingConvention::cdecl_call},
    {0x004F1950u, NativeCallingConvention::cdecl_call},
    {0x004F1969u, NativeCallingConvention::cdecl_call},
    {0x004F1971u, NativeCallingConvention::cdecl_call},
    {0x004F19A0u, NativeCallingConvention::cdecl_call},
    {0x004F19B9u, NativeCallingConvention::cdecl_call},
    {0x004F19E0u, NativeCallingConvention::cdecl_call},
    {0x004F19F9u, NativeCallingConvention::cdecl_call},
    {0x004F1A20u, NativeCallingConvention::cdecl_call},
    {0x004F1A28u, NativeCallingConvention::cdecl_call},
    {0x004F1A41u, NativeCallingConvention::cdecl_call},
    {0x004F1A5Au, NativeCallingConvention::cdecl_call},
    {0x004F1A90u, NativeCallingConvention::cdecl_call},
    {0x004F1A98u, NativeCallingConvention::cdecl_call},
    {0x004F1AA0u, NativeCallingConvention::cdecl_call},
    {0x004F1AD0u, NativeCallingConvention::cdecl_call},
    {0x004F1AD8u, NativeCallingConvention::cdecl_call},
    {0x004F1AE0u, NativeCallingConvention::cdecl_call},
    {0x004F1AEBu, NativeCallingConvention::cdecl_call},
    {0x004F1AF3u, NativeCallingConvention::cdecl_call},
    {0x004F1AFEu, NativeCallingConvention::cdecl_call},
    {0x004F1B09u, NativeCallingConvention::cdecl_call},
    {0x004F1B14u, NativeCallingConvention::cdecl_call},
    {0x004F1B1Cu, NativeCallingConvention::cdecl_call},
    {0x004F1B27u, NativeCallingConvention::cdecl_call},
    {0x004F1B2Fu, NativeCallingConvention::cdecl_call},
    {0x004F1B3Du, NativeCallingConvention::cdecl_call},
    {0x004F1B45u, NativeCallingConvention::cdecl_call},
    {0x004F1B53u, NativeCallingConvention::cdecl_call},
    {0x004F1B5Bu, NativeCallingConvention::cdecl_call},
    {0x004F1B66u, NativeCallingConvention::cdecl_call},
    {0x004F1B74u, NativeCallingConvention::cdecl_call},
    {0x004F1BB0u, NativeCallingConvention::cdecl_call},
    {0x004F1BBBu, NativeCallingConvention::cdecl_call},
    {0x004F1BC6u, NativeCallingConvention::cdecl_call},
    {0x004F1BD1u, NativeCallingConvention::cdecl_call},
    {0x004F1BDCu, NativeCallingConvention::cdecl_call},
    {0x004F1BE7u, NativeCallingConvention::cdecl_call},
    {0x004F1BF2u, NativeCallingConvention::cdecl_call},
    {0x004F1BFDu, NativeCallingConvention::cdecl_call},
    {0x004F1C08u, NativeCallingConvention::cdecl_call},
    {0x004F1C10u, NativeCallingConvention::cdecl_call},
    {0x004F1C1Bu, NativeCallingConvention::cdecl_call},
    {0x004F1C26u, NativeCallingConvention::cdecl_call},
    {0x004F1C31u, NativeCallingConvention::cdecl_call},
    {0x004F1C3Cu, NativeCallingConvention::cdecl_call},
    {0x004F1C44u, NativeCallingConvention::cdecl_call},
    {0x004F1C4Fu, NativeCallingConvention::cdecl_call},
    {0x004F1C57u, NativeCallingConvention::cdecl_call},
    {0x004F1C62u, NativeCallingConvention::cdecl_call},
    {0x004F1C6Au, NativeCallingConvention::cdecl_call},
    {0x004F1CA0u, NativeCallingConvention::cdecl_call},
    {0x004F1CB9u, NativeCallingConvention::cdecl_call},
    {0x004F1CE0u, NativeCallingConvention::cdecl_call},
    {0x004F1CE8u, NativeCallingConvention::cdecl_call},
    {0x004F1CF0u, NativeCallingConvention::cdecl_call},
    {0x004F1CF8u, NativeCallingConvention::cdecl_call},
    {0x004F1D30u, NativeCallingConvention::cdecl_call},
    {0x004F1D3Bu, NativeCallingConvention::cdecl_call},
    {0x004F1D43u, NativeCallingConvention::cdecl_call},
    {0x004F1D4Bu, NativeCallingConvention::cdecl_call},
    {0x004F1D56u, NativeCallingConvention::cdecl_call},
    {0x004F1D5Eu, NativeCallingConvention::cdecl_call},
    {0x004F1D69u, NativeCallingConvention::cdecl_call},
    {0x004F1D74u, NativeCallingConvention::cdecl_call},
    {0x004F1D7Fu, NativeCallingConvention::cdecl_call},
    {0x004F1DB0u, NativeCallingConvention::cdecl_call},
    {0x004F1DBCu, NativeCallingConvention::cdecl_call},
    {0x004F1DC7u, NativeCallingConvention::cdecl_call},
    {0x004F1DCFu, NativeCallingConvention::cdecl_call},
    {0x004F1DD7u, NativeCallingConvention::cdecl_call},
    {0x004F1DDFu, NativeCallingConvention::cdecl_call},
    {0x004F1DE7u, NativeCallingConvention::cdecl_call},
    {0x004F1E20u, NativeCallingConvention::cdecl_call},
    {0x004F1E29u, NativeCallingConvention::cdecl_call},
    {0x004F1E31u, NativeCallingConvention::cdecl_call},
    {0x004F1E39u, NativeCallingConvention::cdecl_call},
    {0x004F1E41u, NativeCallingConvention::cdecl_call},
    {0x004F1E49u, NativeCallingConvention::cdecl_call},
    {0x004F1E80u, NativeCallingConvention::cdecl_call},
    {0x004F1E88u, NativeCallingConvention::cdecl_call},
    {0x004F1E90u, NativeCallingConvention::cdecl_call},
    {0x004F1E98u, NativeCallingConvention::cdecl_call},
    {0x004F1EA3u, NativeCallingConvention::cdecl_call},
    {0x004F1EAEu, NativeCallingConvention::cdecl_call},
    {0x004F1EB9u, NativeCallingConvention::cdecl_call},
    {0x004F1EC1u, NativeCallingConvention::cdecl_call},
    {0x004F1ECCu, NativeCallingConvention::cdecl_call},
    {0x004F1ED7u, NativeCallingConvention::cdecl_call},
    {0x004F1EDFu, NativeCallingConvention::cdecl_call},
    {0x004F1EEAu, NativeCallingConvention::cdecl_call},
    {0x004F1EF5u, NativeCallingConvention::cdecl_call},
    {0x004F1F00u, NativeCallingConvention::cdecl_call},
    {0x004F1F08u, NativeCallingConvention::cdecl_call},
    {0x004F1F13u, NativeCallingConvention::cdecl_call},
    {0x004F1F1Bu, NativeCallingConvention::cdecl_call},
    {0x004F1F26u, NativeCallingConvention::cdecl_call},
    {0x004F1F31u, NativeCallingConvention::cdecl_call},
    {0x004F1F60u, NativeCallingConvention::cdecl_call},
    {0x004F1F68u, NativeCallingConvention::cdecl_call},
    {0x004F1F74u, NativeCallingConvention::cdecl_call},
    {0x004F1F7Fu, NativeCallingConvention::cdecl_call},
    {0x004F1F87u, NativeCallingConvention::cdecl_call},
    {0x004F1F8Fu, NativeCallingConvention::cdecl_call},
    {0x004F1FC0u, NativeCallingConvention::cdecl_call},
    {0x004F1FC8u, NativeCallingConvention::cdecl_call},
    {0x004F1FD4u, NativeCallingConvention::cdecl_call},
    {0x004F1FDFu, NativeCallingConvention::cdecl_call},
    {0x004F1FE7u, NativeCallingConvention::cdecl_call},
    {0x004F1FEFu, NativeCallingConvention::cdecl_call},
    {0x004F1FF7u, NativeCallingConvention::cdecl_call},
    {0x004F1FFFu, NativeCallingConvention::cdecl_call},
    {0x004F2007u, NativeCallingConvention::cdecl_call},
    {0x004F2040u, NativeCallingConvention::cdecl_call},
    {0x004F2048u, NativeCallingConvention::cdecl_call},
    {0x004F2054u, NativeCallingConvention::cdecl_call},
    {0x004F205Fu, NativeCallingConvention::cdecl_call},
    {0x004F2067u, NativeCallingConvention::cdecl_call},
    {0x004F206Fu, NativeCallingConvention::cdecl_call},
    {0x004F2077u, NativeCallingConvention::cdecl_call},
    {0x004F20B0u, NativeCallingConvention::cdecl_call},
    {0x004F20B8u, NativeCallingConvention::cdecl_call},
    {0x004F20E0u, NativeCallingConvention::cdecl_call},
    {0x004F20EEu, NativeCallingConvention::cdecl_call},
    {0x004F2120u, NativeCallingConvention::cdecl_call},
    {0x004F212Au, NativeCallingConvention::cdecl_call},
    {0x004F2150u, NativeCallingConvention::cdecl_call},
    {0x004F215Bu, NativeCallingConvention::cdecl_call},
    {0x004F2180u, NativeCallingConvention::cdecl_call},
    {0x004F218Eu, NativeCallingConvention::cdecl_call},
    {0x004F21C0u, NativeCallingConvention::cdecl_call},
    {0x004F21CBu, NativeCallingConvention::cdecl_call},
    {0x004F2200u, NativeCallingConvention::cdecl_call},
    {0x004F2208u, NativeCallingConvention::cdecl_call},
    {0x004F2230u, NativeCallingConvention::cdecl_call},
    {0x004F2238u, NativeCallingConvention::cdecl_call},
    {0x004F2260u, NativeCallingConvention::cdecl_call},
    {0x004F2280u, NativeCallingConvention::cdecl_call},
    {0x004F22A0u, NativeCallingConvention::cdecl_call},
    {0x004F22A8u, NativeCallingConvention::cdecl_call},
    {0x004F22E0u, NativeCallingConvention::cdecl_call},
    {0x004F2300u, NativeCallingConvention::cdecl_call},
    {0x004F2320u, NativeCallingConvention::cdecl_call},
    {0x004F2328u, NativeCallingConvention::cdecl_call},
    {0x004F2350u, NativeCallingConvention::cdecl_call},
    {0x004F2361u, NativeCallingConvention::cdecl_call},
    {0x004F2380u, NativeCallingConvention::cdecl_call},
    {0x004F2391u, NativeCallingConvention::cdecl_call},
    {0x004F23B0u, NativeCallingConvention::cdecl_call},
    {0x004F23D0u, NativeCallingConvention::cdecl_call},
    {0x004F23D8u, NativeCallingConvention::cdecl_call},
    {0x004F23E0u, NativeCallingConvention::cdecl_call},
    {0x004F2410u, NativeCallingConvention::cdecl_call},
    {0x004F241Bu, NativeCallingConvention::cdecl_call},
    {0x004F2440u, NativeCallingConvention::cdecl_call},
    {0x004F2460u, NativeCallingConvention::cdecl_call},
    {0x004F2480u, NativeCallingConvention::cdecl_call},
    {0x004F248Bu, NativeCallingConvention::cdecl_call},
    {0x004F2496u, NativeCallingConvention::cdecl_call},
    {0x004F24A1u, NativeCallingConvention::cdecl_call},
    {0x004F24ACu, NativeCallingConvention::cdecl_call},
    {0x004F24D0u, NativeCallingConvention::cdecl_call},
    {0x004F24DBu, NativeCallingConvention::cdecl_call},
    {0x004F24E6u, NativeCallingConvention::cdecl_call},
    {0x004F24F1u, NativeCallingConvention::cdecl_call},
    {0x004F24FCu, NativeCallingConvention::cdecl_call},
    {0x004F2520u, NativeCallingConvention::cdecl_call},
    {0x004F252Bu, NativeCallingConvention::cdecl_call},
    {0x004F2550u, NativeCallingConvention::cdecl_call},
    {0x004F2558u, NativeCallingConvention::cdecl_call},
    {0x004F2580u, NativeCallingConvention::cdecl_call},
    {0x004F2588u, NativeCallingConvention::cdecl_call},
    {0x004F25B0u, NativeCallingConvention::cdecl_call},
    {0x004F25B8u, NativeCallingConvention::cdecl_call},
    {0x004F25E0u, NativeCallingConvention::cdecl_call},
    {0x004F2600u, NativeCallingConvention::cdecl_call},
    {0x004F2608u, NativeCallingConvention::cdecl_call},
    {0x004F2616u, NativeCallingConvention::cdecl_call},
    {0x004F2624u, NativeCallingConvention::cdecl_call},
    {0x004F2632u, NativeCallingConvention::cdecl_call},
    {0x004F2640u, NativeCallingConvention::cdecl_call},
    {0x004F264Eu, NativeCallingConvention::cdecl_call},
    {0x004F265Cu, NativeCallingConvention::cdecl_call},
    {0x004F266Au, NativeCallingConvention::cdecl_call},
    {0x004F2672u, NativeCallingConvention::cdecl_call},
    {0x004F2690u, NativeCallingConvention::cdecl_call},
    {0x004F26B0u, NativeCallingConvention::cdecl_call},
    {0x004F26B9u, NativeCallingConvention::cdecl_call},
    {0x004F26C1u, NativeCallingConvention::cdecl_call},
    {0x004F26E0u, NativeCallingConvention::cdecl_call},
    {0x004F2700u, NativeCallingConvention::cdecl_call},
    {0x004F2708u, NativeCallingConvention::cdecl_call},
    {0x004F2730u, NativeCallingConvention::cdecl_call},
    {0x004F2738u, NativeCallingConvention::cdecl_call},
    {0x004F2743u, NativeCallingConvention::cdecl_call},
    {0x004F274Eu, NativeCallingConvention::cdecl_call},
    {0x004F2770u, NativeCallingConvention::cdecl_call},
    {0x004F2778u, NativeCallingConvention::cdecl_call},
    {0x004F27B0u, NativeCallingConvention::cdecl_call},
    {0x004F27BBu, NativeCallingConvention::cdecl_call},
    {0x004F27C6u, NativeCallingConvention::cdecl_call},
    {0x004F27D1u, NativeCallingConvention::cdecl_call},
    {0x004F27D9u, NativeCallingConvention::cdecl_call},
    {0x004F27E4u, NativeCallingConvention::cdecl_call},
    {0x004F27EFu, NativeCallingConvention::cdecl_call},
    {0x004F27F7u, NativeCallingConvention::cdecl_call},
    {0x004F2802u, NativeCallingConvention::cdecl_call},
    {0x004F280Du, NativeCallingConvention::cdecl_call},
    {0x004F2840u, NativeCallingConvention::cdecl_call},
    {0x004F2848u, NativeCallingConvention::cdecl_call},
    {0x004F2870u, NativeCallingConvention::cdecl_call},
    {0x004F2890u, NativeCallingConvention::cdecl_call},
    {0x004F2898u, NativeCallingConvention::cdecl_call},
    {0x004F28D0u, NativeCallingConvention::cdecl_call},
    {0x004F28D8u, NativeCallingConvention::cdecl_call},
    {0x004F2900u, NativeCallingConvention::cdecl_call},
    {0x004F2908u, NativeCallingConvention::cdecl_call},
    {0x004F2911u, NativeCallingConvention::cdecl_call},
    {0x004F291Fu, NativeCallingConvention::cdecl_call},
    {0x004F292Du, NativeCallingConvention::cdecl_call},
    {0x004F293Bu, NativeCallingConvention::cdecl_call},
    {0x004F2949u, NativeCallingConvention::cdecl_call},
    {0x004F2957u, NativeCallingConvention::cdecl_call},
    {0x004F2965u, NativeCallingConvention::cdecl_call},
    {0x004F2973u, NativeCallingConvention::cdecl_call},
    {0x004F2990u, NativeCallingConvention::cdecl_call},
    {0x004F2998u, NativeCallingConvention::cdecl_call},
    {0x004F29A3u, NativeCallingConvention::cdecl_call},
    {0x004F29BCu, NativeCallingConvention::cdecl_call},
    {0x004F29F0u, NativeCallingConvention::cdecl_call},
    {0x004F29F8u, NativeCallingConvention::cdecl_call},
    {0x004F2A00u, NativeCallingConvention::cdecl_call},
    {0x004F2A0Bu, NativeCallingConvention::cdecl_call},
    {0x004F2A13u, NativeCallingConvention::cdecl_call},
    {0x004F2A1Eu, NativeCallingConvention::cdecl_call},
    {0x004F2A26u, NativeCallingConvention::cdecl_call},
    {0x004F2A2Eu, NativeCallingConvention::cdecl_call},
    {0x004F2A36u, NativeCallingConvention::cdecl_call},
    {0x004F2A3Eu, NativeCallingConvention::cdecl_call},
    {0x004F2A49u, NativeCallingConvention::cdecl_call},
    {0x004F2A57u, NativeCallingConvention::cdecl_call},
    {0x004F2A65u, NativeCallingConvention::cdecl_call},
    {0x004F2A73u, NativeCallingConvention::cdecl_call},
    {0x004F2A7Bu, NativeCallingConvention::cdecl_call},
    {0x004F2A89u, NativeCallingConvention::cdecl_call},
    {0x004F2A91u, NativeCallingConvention::cdecl_call},
    {0x004F2A9Cu, NativeCallingConvention::cdecl_call},
    {0x004F2AAAu, NativeCallingConvention::cdecl_call},
    {0x004F2AE0u, NativeCallingConvention::cdecl_call},
    {0x004F2AE8u, NativeCallingConvention::cdecl_call},
    {0x004F2AF3u, NativeCallingConvention::cdecl_call},
    {0x004F2AFCu, NativeCallingConvention::cdecl_call},
    {0x004F2B07u, NativeCallingConvention::cdecl_call},
    {0x004F2B12u, NativeCallingConvention::cdecl_call},
    {0x004F2B30u, NativeCallingConvention::cdecl_call},
    {0x004F2B3Cu, NativeCallingConvention::cdecl_call},
    {0x004F2B47u, NativeCallingConvention::cdecl_call},
    {0x004F2B4Fu, NativeCallingConvention::cdecl_call},
    {0x004F2B5Au, NativeCallingConvention::cdecl_call},
    {0x004F2B62u, NativeCallingConvention::cdecl_call},
    {0x004F2B6Au, NativeCallingConvention::cdecl_call},
    {0x004F2B75u, NativeCallingConvention::cdecl_call},
    {0x004F2B7Du, NativeCallingConvention::cdecl_call},
    {0x004F2BB0u, NativeCallingConvention::cdecl_call},
    {0x004F2BB9u, NativeCallingConvention::cdecl_call},
    {0x004F2BC1u, NativeCallingConvention::cdecl_call},
    {0x004F2BE0u, NativeCallingConvention::cdecl_call},
    {0x004F2BF1u, NativeCallingConvention::cdecl_call},
    {0x004F2C10u, NativeCallingConvention::cdecl_call},
    {0x004F2C40u, NativeCallingConvention::cdecl_call},
    {0x004F2C48u, NativeCallingConvention::cdecl_call},
    {0x004F2C56u, NativeCallingConvention::cdecl_call},
    {0x004F2C80u, NativeCallingConvention::cdecl_call},
    {0x004F2C88u, NativeCallingConvention::cdecl_call},
    {0x004F2C91u, NativeCallingConvention::cdecl_call},
    {0x004F2CB0u, NativeCallingConvention::cdecl_call},
    {0x004F2CBBu, NativeCallingConvention::cdecl_call},
    {0x004F2CC3u, NativeCallingConvention::cdecl_call},
    {0x004F2CF0u, NativeCallingConvention::cdecl_call},
    {0x004F2D10u, NativeCallingConvention::cdecl_call},
    {0x004F2D1Bu, NativeCallingConvention::cdecl_call},
    {0x004F2D26u, NativeCallingConvention::cdecl_call},
    {0x004F2D50u, NativeCallingConvention::cdecl_call},
    {0x004F2D59u, NativeCallingConvention::cdecl_call},
    {0x004F2D80u, NativeCallingConvention::cdecl_call},
    {0x004F2D88u, NativeCallingConvention::cdecl_call},
    {0x004F2DB0u, NativeCallingConvention::cdecl_call},
    {0x004F2DB8u, NativeCallingConvention::cdecl_call},
    {0x004F2DE0u, NativeCallingConvention::cdecl_call},
    {0x004F2DE8u, NativeCallingConvention::cdecl_call},
    {0x004F2DF0u, NativeCallingConvention::cdecl_call},
    {0x004F2DF8u, NativeCallingConvention::cdecl_call},
    {0x004F2E20u, NativeCallingConvention::cdecl_call},
    {0x004F2E28u, NativeCallingConvention::cdecl_call},
    {0x004F2E30u, NativeCallingConvention::cdecl_call},
    {0x004F2E38u, NativeCallingConvention::cdecl_call},
    {0x004F2E60u, NativeCallingConvention::cdecl_call},
    {0x004F2E80u, NativeCallingConvention::cdecl_call},
    {0x004F2E88u, NativeCallingConvention::cdecl_call},
    {0x004F2EB0u, NativeCallingConvention::cdecl_call},
    {0x004F2EB8u, NativeCallingConvention::cdecl_call},
    {0x004F2EE0u, NativeCallingConvention::cdecl_call},
    {0x004F2EE8u, NativeCallingConvention::cdecl_call},
    {0x004F2EF0u, NativeCallingConvention::cdecl_call},
    {0x004F2F10u, NativeCallingConvention::cdecl_call},
    {0x004F2F18u, NativeCallingConvention::cdecl_call},
    {0x004F2F20u, NativeCallingConvention::cdecl_call},
    {0x004F2F50u, NativeCallingConvention::cdecl_call},
    {0x004F2F58u, NativeCallingConvention::cdecl_call},
    {0x004F2F60u, NativeCallingConvention::cdecl_call},
    {0x004F2F90u, NativeCallingConvention::cdecl_call},
    {0x004F2F98u, NativeCallingConvention::cdecl_call},
    {0x004F2FC0u, NativeCallingConvention::cdecl_call},
    {0x004F2FC8u, NativeCallingConvention::cdecl_call},
    {0x004F2FF0u, NativeCallingConvention::cdecl_call},
    {0x004F300Du, NativeCallingConvention::cdecl_call},
    {0x004F3019u, NativeCallingConvention::cdecl_call},
    {0x004F3022u, NativeCallingConvention::cdecl_call},
    {0x004F3040u, NativeCallingConvention::cdecl_call},
    {0x004F304Cu, NativeCallingConvention::cdecl_call},
    {0x004F3055u, NativeCallingConvention::cdecl_call},
    {0x004F3070u, NativeCallingConvention::cdecl_call},
    {0x004F3079u, NativeCallingConvention::cdecl_call},
    {0x004F30A0u, NativeCallingConvention::cdecl_call},
    {0x004F30A8u, NativeCallingConvention::cdecl_call},
    {0x004F30B3u, NativeCallingConvention::cdecl_call},
    {0x004F30CCu, NativeCallingConvention::cdecl_call},
    {0x004F3100u, NativeCallingConvention::cdecl_call},
    {0x004F3119u, NativeCallingConvention::cdecl_call},
    {0x004F3140u, NativeCallingConvention::cdecl_call},
    {0x004F314Cu, NativeCallingConvention::cdecl_call},
    {0x004F3157u, NativeCallingConvention::cdecl_call},
    {0x004F315Fu, NativeCallingConvention::cdecl_call},
    {0x004F3167u, NativeCallingConvention::cdecl_call},
    {0x004F31A0u, NativeCallingConvention::cdecl_call},
    {0x004F31A8u, NativeCallingConvention::cdecl_call},
    {0x004F31D0u, NativeCallingConvention::cdecl_call},
    {0x004F31EDu, NativeCallingConvention::cdecl_call},
    {0x004F31F9u, NativeCallingConvention::cdecl_call},
    {0x004F3202u, NativeCallingConvention::cdecl_call},
    {0x004F3220u, NativeCallingConvention::cdecl_call},
    {0x004F322Cu, NativeCallingConvention::cdecl_call},
    {0x004F3235u, NativeCallingConvention::cdecl_call},
    {0x004F3250u, NativeCallingConvention::cdecl_call},
    {0x004F3258u, NativeCallingConvention::cdecl_call},
    {0x004F3261u, NativeCallingConvention::cdecl_call},
    {0x004F326Fu, NativeCallingConvention::cdecl_call},
    {0x004F327Du, NativeCallingConvention::cdecl_call},
    {0x004F328Bu, NativeCallingConvention::cdecl_call},
    {0x004F3299u, NativeCallingConvention::cdecl_call},
    {0x004F32A2u, NativeCallingConvention::cdecl_call},
    {0x004F32C0u, NativeCallingConvention::cdecl_call},
    {0x004F32C8u, NativeCallingConvention::cdecl_call},
    {0x004F32D0u, NativeCallingConvention::cdecl_call},
    {0x004F32D8u, NativeCallingConvention::cdecl_call},
    {0x004F32E0u, NativeCallingConvention::cdecl_call},
    {0x004F32EEu, NativeCallingConvention::cdecl_call},
    {0x004F3320u, NativeCallingConvention::cdecl_call},
    {0x004F3342u, NativeCallingConvention::cdecl_call},
    {0x004F334Au, NativeCallingConvention::cdecl_call},
    {0x004F3355u, NativeCallingConvention::cdecl_call},
    {0x004F335Du, NativeCallingConvention::cdecl_call},
    {0x004F3365u, NativeCallingConvention::cdecl_call},
    {0x004F33A0u, NativeCallingConvention::cdecl_call},
    {0x004F33ABu, NativeCallingConvention::cdecl_call},
    {0x004F33B6u, NativeCallingConvention::cdecl_call},
    {0x004F33C1u, NativeCallingConvention::cdecl_call},
    {0x004F33CCu, NativeCallingConvention::cdecl_call},
    {0x004F33D7u, NativeCallingConvention::cdecl_call},
    {0x004F33DFu, NativeCallingConvention::cdecl_call},
    {0x004F33E7u, NativeCallingConvention::cdecl_call},
    {0x004F33EFu, NativeCallingConvention::cdecl_call},
    {0x004F33F7u, NativeCallingConvention::cdecl_call},
    {0x004F3402u, NativeCallingConvention::cdecl_call},
    {0x004F340Du, NativeCallingConvention::cdecl_call},
    {0x004F3440u, NativeCallingConvention::cdecl_call},
    {0x004F344Bu, NativeCallingConvention::cdecl_call},
    {0x004F3456u, NativeCallingConvention::cdecl_call},
    {0x004F345Eu, NativeCallingConvention::cdecl_call},
    {0x004F3469u, NativeCallingConvention::cdecl_call},
    {0x004F3474u, NativeCallingConvention::cdecl_call},
    {0x004F347Cu, NativeCallingConvention::cdecl_call},
    {0x004F3487u, NativeCallingConvention::cdecl_call},
    {0x004F348Fu, NativeCallingConvention::cdecl_call},
    {0x004F349Au, NativeCallingConvention::cdecl_call},
    {0x004F34A5u, NativeCallingConvention::cdecl_call},
    {0x004F34ADu, NativeCallingConvention::cdecl_call},
    {0x004F34E0u, NativeCallingConvention::cdecl_call},
    {0x004F34E8u, NativeCallingConvention::cdecl_call},
    {0x004F34F6u, NativeCallingConvention::cdecl_call},
    {0x004F3504u, NativeCallingConvention::cdecl_call},
    {0x004F3512u, NativeCallingConvention::cdecl_call},
    {0x004F3520u, NativeCallingConvention::cdecl_call},
    {0x004F352Eu, NativeCallingConvention::cdecl_call},
    {0x004F3536u, NativeCallingConvention::cdecl_call},
    {0x004F3560u, NativeCallingConvention::cdecl_call},
    {0x004F356Bu, NativeCallingConvention::cdecl_call},
    {0x004F3576u, NativeCallingConvention::cdecl_call},
    {0x004F3581u, NativeCallingConvention::cdecl_call},
    {0x004F358Cu, NativeCallingConvention::cdecl_call},
    {0x004F3597u, NativeCallingConvention::cdecl_call},
    {0x004F35A2u, NativeCallingConvention::cdecl_call},
    {0x004F35ADu, NativeCallingConvention::cdecl_call},
    {0x004F35B8u, NativeCallingConvention::cdecl_call},
    {0x004F35F0u, NativeCallingConvention::cdecl_call},
    {0x004F35F8u, NativeCallingConvention::cdecl_call},
    {0x004F3600u, NativeCallingConvention::cdecl_call},
    {0x004F3630u, NativeCallingConvention::cdecl_call},
    {0x004F3638u, NativeCallingConvention::cdecl_call},
    {0x004F3641u, NativeCallingConvention::cdecl_call},
    {0x004F364Fu, NativeCallingConvention::cdecl_call},
    {0x004F365Du, NativeCallingConvention::cdecl_call},
    {0x004F366Bu, NativeCallingConvention::cdecl_call},
    {0x004F3679u, NativeCallingConvention::cdecl_call},
    {0x004F3682u, NativeCallingConvention::cdecl_call},
    {0x004F3690u, NativeCallingConvention::cdecl_call},
    {0x004F36B0u, NativeCallingConvention::cdecl_call},
    {0x004F36B8u, NativeCallingConvention::cdecl_call},
    {0x004F36E0u, NativeCallingConvention::cdecl_call},
    {0x004F36EBu, NativeCallingConvention::cdecl_call},
    {0x004F3710u, NativeCallingConvention::cdecl_call},
    {0x004F371Bu, NativeCallingConvention::cdecl_call},
    {0x004F3726u, NativeCallingConvention::cdecl_call},
    {0x004F3750u, NativeCallingConvention::cdecl_call},
    {0x004F375Cu, NativeCallingConvention::cdecl_call},
    {0x004F3780u, NativeCallingConvention::cdecl_call},
    {0x004F378Eu, NativeCallingConvention::cdecl_call},
    {0x004F379Cu, NativeCallingConvention::cdecl_call},
    {0x004F37C0u, NativeCallingConvention::cdecl_call},
    {0x004F37D1u, NativeCallingConvention::cdecl_call},
    {0x004F37D9u, NativeCallingConvention::cdecl_call},
    {0x004F3800u, NativeCallingConvention::cdecl_call},
    {0x004F3811u, NativeCallingConvention::cdecl_call},
    {0x004F3819u, NativeCallingConvention::cdecl_call},
    {0x004F3840u, NativeCallingConvention::cdecl_call},
    {0x004F384Eu, NativeCallingConvention::cdecl_call},
    {0x004F3880u, NativeCallingConvention::cdecl_call},
    {0x004F388Bu, NativeCallingConvention::cdecl_call},
    {0x004F38B0u, NativeCallingConvention::cdecl_call},
    {0x004F38BEu, NativeCallingConvention::cdecl_call},
    {0x004F38F0u, NativeCallingConvention::cdecl_call},
    {0x004F38F8u, NativeCallingConvention::cdecl_call},
    {0x004F3900u, NativeCallingConvention::cdecl_call},
    {0x004F3930u, NativeCallingConvention::cdecl_call},
    {0x004F3938u, NativeCallingConvention::cdecl_call},
    {0x004F3940u, NativeCallingConvention::cdecl_call},
    {0x004F3948u, NativeCallingConvention::cdecl_call},
    {0x004F3970u, NativeCallingConvention::cdecl_call},
    {0x004F3981u, NativeCallingConvention::cdecl_call},
    {0x004F39A0u, NativeCallingConvention::cdecl_call},
    {0x004F39B1u, NativeCallingConvention::cdecl_call},
    {0x004F39B9u, NativeCallingConvention::cdecl_call},
    {0x004F39E0u, NativeCallingConvention::cdecl_call},
    {0x004F3A00u, NativeCallingConvention::cdecl_call},
    {0x004F3A0Cu, NativeCallingConvention::cdecl_call},
    {0x004F3A18u, NativeCallingConvention::cdecl_call},
    {0x004F3A23u, NativeCallingConvention::cdecl_call},
    {0x004F3A45u, NativeCallingConvention::cdecl_call},
    {0x004F3A70u, NativeCallingConvention::cdecl_call},
    {0x004F3A7Bu, NativeCallingConvention::cdecl_call},
    {0x004F3A86u, NativeCallingConvention::cdecl_call},
    {0x004F3A91u, NativeCallingConvention::cdecl_call},
    {0x004F3AC0u, NativeCallingConvention::cdecl_call},
    {0x004F3AC8u, NativeCallingConvention::cdecl_call},
    {0x004F3AF0u, NativeCallingConvention::cdecl_call},
    {0x004F3AF8u, NativeCallingConvention::cdecl_call},
    {0x004F3B20u, NativeCallingConvention::cdecl_call},
    {0x004F3B40u, NativeCallingConvention::cdecl_call},
    {0x004F3B48u, NativeCallingConvention::cdecl_call},
    {0x004F3B56u, NativeCallingConvention::cdecl_call},
    {0x004F3B5Eu, NativeCallingConvention::cdecl_call},
    {0x004F3B90u, NativeCallingConvention::cdecl_call},
    {0x004F3B9Bu, NativeCallingConvention::cdecl_call},
    {0x004F3BC0u, NativeCallingConvention::cdecl_call},
    {0x004F3BC8u, NativeCallingConvention::cdecl_call},
    {0x004F3BD6u, NativeCallingConvention::cdecl_call},
    {0x004F3C00u, NativeCallingConvention::cdecl_call},
    {0x004F3C0Bu, NativeCallingConvention::cdecl_call},
    {0x004F3C30u, NativeCallingConvention::cdecl_call},
    {0x004F3C3Bu, NativeCallingConvention::cdecl_call},
    {0x004F3C60u, NativeCallingConvention::cdecl_call},
    {0x004F3C68u, NativeCallingConvention::cdecl_call},
    {0x004F3C76u, NativeCallingConvention::cdecl_call},
    {0x004F3CA0u, NativeCallingConvention::cdecl_call},
    {0x004F3CA8u, NativeCallingConvention::cdecl_call},
    {0x004F3CB0u, NativeCallingConvention::cdecl_call},
    {0x004F3CE0u, NativeCallingConvention::cdecl_call},
    {0x004F3CF1u, NativeCallingConvention::cdecl_call},
    {0x004F3D10u, NativeCallingConvention::cdecl_call},
    {0x004F3D21u, NativeCallingConvention::cdecl_call},
    {0x004F3D40u, NativeCallingConvention::cdecl_call},
    {0x004F3D60u, NativeCallingConvention::cdecl_call},
    {0x004F3D71u, NativeCallingConvention::cdecl_call},
    {0x004F3D82u, NativeCallingConvention::cdecl_call},
    {0x004F3DA0u, NativeCallingConvention::cdecl_call},
    {0x004F3DA8u, NativeCallingConvention::cdecl_call},
    {0x004F3DD0u, NativeCallingConvention::cdecl_call},
    {0x004F3DDBu, NativeCallingConvention::cdecl_call},
    {0x004F3DE3u, NativeCallingConvention::cdecl_call},
    {0x004F3DF1u, NativeCallingConvention::cdecl_call},
    {0x004F3E10u, NativeCallingConvention::cdecl_call},
    {0x004F3E21u, NativeCallingConvention::cdecl_call},
    {0x004F3E40u, NativeCallingConvention::cdecl_call},
    {0x004F3E4Bu, NativeCallingConvention::cdecl_call},
    {0x004F3E70u, NativeCallingConvention::cdecl_call},
    {0x004F3E78u, NativeCallingConvention::cdecl_call},
    {0x004F3EA0u, NativeCallingConvention::cdecl_call},
    {0x004F3ED0u, NativeCallingConvention::cdecl_call},
    {0x004F3ED8u, NativeCallingConvention::cdecl_call},
    {0x004F3EE6u, NativeCallingConvention::cdecl_call},
    {0x004F3F10u, NativeCallingConvention::cdecl_call},
    {0x004F3F21u, NativeCallingConvention::cdecl_call},
    {0x004F3F32u, NativeCallingConvention::cdecl_call},
    {0x004F3F50u, NativeCallingConvention::cdecl_call},
    {0x004F3F61u, NativeCallingConvention::cdecl_call},
    {0x004F3F80u, NativeCallingConvention::cdecl_call},
    {0x004F3F91u, NativeCallingConvention::cdecl_call},
    {0x004F3FB0u, NativeCallingConvention::cdecl_call},
    {0x004F3FB8u, NativeCallingConvention::cdecl_call},
    {0x004F3FC6u, NativeCallingConvention::cdecl_call},
    {0x004F3FCEu, NativeCallingConvention::cdecl_call},
    {0x004F4000u, NativeCallingConvention::cdecl_call},
    {0x004F4008u, NativeCallingConvention::cdecl_call},
    {0x004F4010u, NativeCallingConvention::cdecl_call},
    {0x004F4040u, NativeCallingConvention::cdecl_call},
    {0x004F404Bu, NativeCallingConvention::cdecl_call},
    {0x004F4070u, NativeCallingConvention::cdecl_call},
    {0x004F4078u, NativeCallingConvention::cdecl_call},
    {0x004F4086u, NativeCallingConvention::cdecl_call},
    {0x004F4094u, NativeCallingConvention::cdecl_call},
    {0x004F40B0u, NativeCallingConvention::cdecl_call},
    {0x004F40BBu, NativeCallingConvention::cdecl_call},
    {0x004F40C6u, NativeCallingConvention::cdecl_call},
    {0x004F40D1u, NativeCallingConvention::cdecl_call},
    {0x004F4100u, NativeCallingConvention::cdecl_call},
    {0x004F4120u, NativeCallingConvention::cdecl_call},
    {0x004F4128u, NativeCallingConvention::cdecl_call},
    {0x004F4150u, NativeCallingConvention::cdecl_call},
    {0x004F4158u, NativeCallingConvention::cdecl_call},
    {0x004F4180u, NativeCallingConvention::cdecl_call},
    {0x004F4188u, NativeCallingConvention::cdecl_call},
    {0x004F41B0u, NativeCallingConvention::cdecl_call},
    {0x004F41B8u, NativeCallingConvention::cdecl_call},
    {0x004F41C6u, NativeCallingConvention::cdecl_call},
    {0x004F41F0u, NativeCallingConvention::cdecl_call},
    {0x004F41F8u, NativeCallingConvention::cdecl_call},
    {0x004F4206u, NativeCallingConvention::cdecl_call},
    {0x004F4211u, NativeCallingConvention::cdecl_call},
    {0x004F421Cu, NativeCallingConvention::cdecl_call},
    {0x004F4240u, NativeCallingConvention::cdecl_call},
    {0x004F424Bu, NativeCallingConvention::cdecl_call},
    {0x004F4256u, NativeCallingConvention::cdecl_call},
    {0x004F4280u, NativeCallingConvention::cdecl_call},
    {0x004F4288u, NativeCallingConvention::cdecl_call},
    {0x004F4291u, NativeCallingConvention::cdecl_call},
    {0x004F42B0u, NativeCallingConvention::cdecl_call},
    {0x004F42BBu, NativeCallingConvention::cdecl_call},
    {0x004F42E0u, NativeCallingConvention::cdecl_call},
    {0x004F42EBu, NativeCallingConvention::cdecl_call},
    {0x004F42F6u, NativeCallingConvention::cdecl_call},
    {0x004F4320u, NativeCallingConvention::cdecl_call},
    {0x004F432Eu, NativeCallingConvention::cdecl_call},
    {0x004F4350u, NativeCallingConvention::cdecl_call},
    {0x004F435Bu, NativeCallingConvention::cdecl_call},
    {0x004F4366u, NativeCallingConvention::cdecl_call},
    {0x004F4371u, NativeCallingConvention::cdecl_call},
    {0x004F437Fu, NativeCallingConvention::cdecl_call},
    {0x004F438Du, NativeCallingConvention::cdecl_call},
    {0x004F4396u, NativeCallingConvention::cdecl_call},
    {0x004F43A4u, NativeCallingConvention::cdecl_call},
    {0x004F43B2u, NativeCallingConvention::cdecl_call},
    {0x004F43D0u, NativeCallingConvention::cdecl_call},
    {0x004F43DBu, NativeCallingConvention::cdecl_call},
    {0x004F43E6u, NativeCallingConvention::cdecl_call},
    {0x004F43F1u, NativeCallingConvention::cdecl_call},
    {0x004F43FFu, NativeCallingConvention::cdecl_call},
    {0x004F440Du, NativeCallingConvention::cdecl_call},
    {0x004F441Bu, NativeCallingConvention::cdecl_call},
    {0x004F4429u, NativeCallingConvention::cdecl_call},
    {0x004F4450u, NativeCallingConvention::cdecl_call},
    {0x004F445Bu, NativeCallingConvention::cdecl_call},
    {0x004F4466u, NativeCallingConvention::cdecl_call},
    {0x004F4471u, NativeCallingConvention::cdecl_call},
    {0x004F447Cu, NativeCallingConvention::cdecl_call},
    {0x004F4487u, NativeCallingConvention::cdecl_call},
    {0x004F4492u, NativeCallingConvention::cdecl_call},
    {0x004F449Du, NativeCallingConvention::cdecl_call},
    {0x004F44A8u, NativeCallingConvention::cdecl_call},
    {0x004F44B3u, NativeCallingConvention::cdecl_call},
    {0x004F44BEu, NativeCallingConvention::cdecl_call},
    {0x004F44C9u, NativeCallingConvention::cdecl_call},
    {0x004F44D4u, NativeCallingConvention::cdecl_call},
    {0x004F44DFu, NativeCallingConvention::cdecl_call},
    {0x004F44EAu, NativeCallingConvention::cdecl_call},
    {0x004F44F5u, NativeCallingConvention::cdecl_call},
    {0x004F4500u, NativeCallingConvention::cdecl_call},
    {0x004F450Bu, NativeCallingConvention::cdecl_call},
    {0x004F4516u, NativeCallingConvention::cdecl_call},
    {0x004F4521u, NativeCallingConvention::cdecl_call},
    {0x004F452Cu, NativeCallingConvention::cdecl_call},
    {0x004F4537u, NativeCallingConvention::cdecl_call},
    {0x004F4542u, NativeCallingConvention::cdecl_call},
    {0x004F454Du, NativeCallingConvention::cdecl_call},
    {0x004F4558u, NativeCallingConvention::cdecl_call},
    {0x004F4580u, NativeCallingConvention::cdecl_call},
    {0x004F458Eu, NativeCallingConvention::cdecl_call},
    {0x004F45C0u, NativeCallingConvention::cdecl_call},
    {0x004F45CEu, NativeCallingConvention::cdecl_call},
    {0x004F45DCu, NativeCallingConvention::cdecl_call},
    {0x004F4610u, NativeCallingConvention::cdecl_call},
    {0x004F461Bu, NativeCallingConvention::cdecl_call},
    {0x004F4626u, NativeCallingConvention::cdecl_call},
    {0x004F4631u, NativeCallingConvention::cdecl_call},
    {0x004F463Fu, NativeCallingConvention::cdecl_call},
    {0x004F464Du, NativeCallingConvention::cdecl_call},
    {0x004F4656u, NativeCallingConvention::cdecl_call},
    {0x004F4664u, NativeCallingConvention::cdecl_call},
    {0x004F4672u, NativeCallingConvention::cdecl_call},
    {0x004F4680u, NativeCallingConvention::cdecl_call},
    {0x004F46A0u, NativeCallingConvention::cdecl_call},
    {0x004F46AAu, NativeCallingConvention::cdecl_call},
    {0x004F46D0u, NativeCallingConvention::cdecl_call},
    {0x004F46DBu, NativeCallingConvention::cdecl_call},
    {0x004F46E6u, NativeCallingConvention::cdecl_call},
    {0x004F46F1u, NativeCallingConvention::cdecl_call},
    {0x004F46FCu, NativeCallingConvention::cdecl_call},
    {0x004F4707u, NativeCallingConvention::cdecl_call},
    {0x004F4712u, NativeCallingConvention::cdecl_call},
    {0x004F4740u, NativeCallingConvention::cdecl_call},
    {0x004F4751u, NativeCallingConvention::cdecl_call},
    {0x004F4770u, NativeCallingConvention::cdecl_call},
    {0x004F4778u, NativeCallingConvention::cdecl_call},
    {0x004F4780u, NativeCallingConvention::cdecl_call},
    {0x004F47B0u, NativeCallingConvention::cdecl_call},
    {0x004F47B8u, NativeCallingConvention::cdecl_call},
    {0x004F47E0u, NativeCallingConvention::cdecl_call},
    {0x004F47E8u, NativeCallingConvention::cdecl_call},
    {0x004F4810u, NativeCallingConvention::cdecl_call},
    {0x004F481Eu, NativeCallingConvention::cdecl_call},
    {0x004F482Cu, NativeCallingConvention::cdecl_call},
    {0x004F4850u, NativeCallingConvention::cdecl_call},
    {0x004F485Eu, NativeCallingConvention::cdecl_call},
    {0x004F4880u, NativeCallingConvention::cdecl_call},
    {0x004F488Bu, NativeCallingConvention::cdecl_call},
    {0x004F48C0u, NativeCallingConvention::cdecl_call},
    {0x004F48CBu, NativeCallingConvention::cdecl_call},
    {0x004F4900u, NativeCallingConvention::cdecl_call},
    {0x004F490Bu, NativeCallingConvention::cdecl_call},
    {0x004F4940u, NativeCallingConvention::cdecl_call},
    {0x004F494Bu, NativeCallingConvention::cdecl_call},
    {0x004F4980u, NativeCallingConvention::cdecl_call},
    {0x004F498Eu, NativeCallingConvention::cdecl_call},
    {0x004F49C0u, NativeCallingConvention::cdecl_call},
    {0x004F49C8u, NativeCallingConvention::cdecl_call},
    {0x004F49F0u, NativeCallingConvention::cdecl_call},
    {0x004F49F8u, NativeCallingConvention::cdecl_call},
    {0x004F4A20u, NativeCallingConvention::cdecl_call},
    {0x004F4A28u, NativeCallingConvention::cdecl_call},
    {0x004F4A50u, NativeCallingConvention::cdecl_call},
    {0x004F4A5Bu, NativeCallingConvention::cdecl_call},
    {0x004F4A80u, NativeCallingConvention::cdecl_call},
    {0x004F4A8Bu, NativeCallingConvention::cdecl_call},
    {0x004F4AB0u, NativeCallingConvention::cdecl_call},
    {0x004F4AB9u, NativeCallingConvention::cdecl_call},
    {0x004F4AE0u, NativeCallingConvention::cdecl_call},
    {0x004F4B10u, NativeCallingConvention::cdecl_call},
    {0x004F4B50u, NativeCallingConvention::cdecl_call},
    {0x004F4B80u, NativeCallingConvention::cdecl_call},
    {0x004F4BC0u, NativeCallingConvention::cdecl_call},
    {0x004F4BF0u, NativeCallingConvention::cdecl_call},
    {0x004F4C30u, NativeCallingConvention::cdecl_call},
    {0x004F4C60u, NativeCallingConvention::cdecl_call},
    {0x004F4CA0u, NativeCallingConvention::cdecl_call},
    {0x004F4CD0u, NativeCallingConvention::cdecl_call},
    {0x004F4D10u, NativeCallingConvention::cdecl_call},
    {0x004F4D40u, NativeCallingConvention::cdecl_call},
    {0x004F4D80u, NativeCallingConvention::cdecl_call},
    {0x004F4DB0u, NativeCallingConvention::cdecl_call},
    {0x004F4DF0u, NativeCallingConvention::cdecl_call},
    {0x004F4E20u, NativeCallingConvention::cdecl_call},
    {0x004F4E60u, NativeCallingConvention::cdecl_call},
    {0x004F4EA0u, NativeCallingConvention::cdecl_call},
    {0x004F4ED0u, NativeCallingConvention::cdecl_call},
    {0x004F4F10u, NativeCallingConvention::cdecl_call},
    {0x004F4F40u, NativeCallingConvention::cdecl_call},
    {0x004F4F80u, NativeCallingConvention::cdecl_call},
    {0x004F4FB0u, NativeCallingConvention::cdecl_call},
    {0x004F4FF0u, NativeCallingConvention::cdecl_call},
    {0x004F5070u, NativeCallingConvention::cdecl_call},
    {0x004F50E0u, NativeCallingConvention::cdecl_call},
    {0x004F50F0u, NativeCallingConvention::cdecl_call},
    {0x004F5120u, NativeCallingConvention::cdecl_call},
    {0x004F5160u, NativeCallingConvention::cdecl_call},
    {0x004F5190u, NativeCallingConvention::cdecl_call},
    {0x004F51D0u, NativeCallingConvention::cdecl_call},
    {0x004F51F0u, NativeCallingConvention::cdecl_call},
    {0x004F5270u, NativeCallingConvention::cdecl_call},
    {0x004F5330u, NativeCallingConvention::cdecl_call},
    {0x004F5360u, NativeCallingConvention::cdecl_call},
    {0x004F53A0u, NativeCallingConvention::cdecl_call},
    {0x004F53D0u, NativeCallingConvention::cdecl_call},
    {0x004F5410u, NativeCallingConvention::cdecl_call},
    {0x004F5430u, NativeCallingConvention::cdecl_call},
    {0x004F5450u, NativeCallingConvention::cdecl_call},
    {0x004F5480u, NativeCallingConvention::cdecl_call},
    {0x004F54C0u, NativeCallingConvention::cdecl_call},
    {0x004F54F0u, NativeCallingConvention::cdecl_call},
    {0x004F5530u, NativeCallingConvention::cdecl_call},
    {0x004F5550u, NativeCallingConvention::cdecl_call},
    {0x004F5570u, NativeCallingConvention::cdecl_call},
    {0x004F5580u, NativeCallingConvention::cdecl_call},
    {0x004F5590u, NativeCallingConvention::cdecl_call},
    {0x004F55B0u, NativeCallingConvention::cdecl_call},
    {0x004F55E0u, NativeCallingConvention::cdecl_call},
    {0x004F5620u, NativeCallingConvention::cdecl_call},
    {0x004F5690u, NativeCallingConvention::cdecl_call},
    {0x004F5700u, NativeCallingConvention::cdecl_call},
    {0x004F5770u, NativeCallingConvention::cdecl_call},
    {0x004F57A0u, NativeCallingConvention::cdecl_call},
    {0x004F57E0u, NativeCallingConvention::cdecl_call},
    {0x004F5810u, NativeCallingConvention::cdecl_call},
    {0x004F5850u, NativeCallingConvention::cdecl_call},
    {0x004F5870u, NativeCallingConvention::cdecl_call},
    {0x004F5890u, NativeCallingConvention::cdecl_call},
    {0x004F5920u, NativeCallingConvention::cdecl_call},
    {0x004F59B0u, NativeCallingConvention::cdecl_call},
    {0x004F5A40u, NativeCallingConvention::cdecl_call},
    {0x004F5AD0u, NativeCallingConvention::cdecl_call},
    {0x004F5B60u, NativeCallingConvention::cdecl_call},
    {0x004F5BF0u, NativeCallingConvention::cdecl_call},
    {0x004F5C80u, NativeCallingConvention::cdecl_call},
    {0x004F5C90u, NativeCallingConvention::cdecl_call},
    {0x004F5D20u, NativeCallingConvention::cdecl_call},
    {0x004F5DB0u, NativeCallingConvention::cdecl_call},
    {0x004F5DD0u, NativeCallingConvention::cdecl_call},
    {0x004F5DE0u, NativeCallingConvention::cdecl_call},
    {0x004F5E50u, NativeCallingConvention::cdecl_call},
    {0x004F5EC0u, NativeCallingConvention::cdecl_call},
    {0x004F5F30u, NativeCallingConvention::cdecl_call},
    {0x004F5FA0u, NativeCallingConvention::cdecl_call},
    {0x004F6010u, NativeCallingConvention::cdecl_call},
    {0x004F6080u, NativeCallingConvention::cdecl_call},
    {0x004F60F0u, NativeCallingConvention::cdecl_call},
    {0x004F6160u, NativeCallingConvention::cdecl_call},
    {0x004F61D0u, NativeCallingConvention::cdecl_call},
    {0x004F6240u, NativeCallingConvention::cdecl_call},
    {0x004F62B0u, NativeCallingConvention::cdecl_call},
    {0x004F6320u, NativeCallingConvention::cdecl_call},
    {0x004F6390u, NativeCallingConvention::cdecl_call},
    {0x004F6400u, NativeCallingConvention::cdecl_call},
    {0x004F6470u, NativeCallingConvention::cdecl_call},
    {0x004F6510u, NativeCallingConvention::cdecl_call},
    {0x004F6580u, NativeCallingConvention::cdecl_call},
    {0x004F6650u, NativeCallingConvention::cdecl_call},
    {0x004F6720u, NativeCallingConvention::cdecl_call},
    {0x004F67F0u, NativeCallingConvention::cdecl_call},
    {0x004F68C0u, NativeCallingConvention::cdecl_call},
    {0x004F6950u, NativeCallingConvention::cdecl_call},
    {0x004F69C0u, NativeCallingConvention::cdecl_call},
    {0x004F6A30u, NativeCallingConvention::cdecl_call},
    {0x004F6AA0u, NativeCallingConvention::cdecl_call},
    {0x004F6B10u, NativeCallingConvention::cdecl_call},
    {0x004F6B80u, NativeCallingConvention::cdecl_call},
    {0x004F6C10u, NativeCallingConvention::cdecl_call},
    {0x004F6C80u, NativeCallingConvention::cdecl_call},
    {0x004F6CF0u, NativeCallingConvention::cdecl_call},
    {0x004F6D60u, NativeCallingConvention::cdecl_call},
    {0x004F6DD0u, NativeCallingConvention::cdecl_call},
    {0x004F6E40u, NativeCallingConvention::cdecl_call},
    {0x004F6EB0u, NativeCallingConvention::cdecl_call},
    {0x004F6F20u, NativeCallingConvention::cdecl_call},
    {0x004F6FA0u, NativeCallingConvention::cdecl_call},
    {0x004F7010u, NativeCallingConvention::cdecl_call},
    {0x004F7080u, NativeCallingConvention::cdecl_call},
    {0x004F70F0u, NativeCallingConvention::cdecl_call},
    {0x004F7160u, NativeCallingConvention::cdecl_call},
    {0x004F71D0u, NativeCallingConvention::cdecl_call},
    {0x004F7240u, NativeCallingConvention::cdecl_call},
    {0x004F72B0u, NativeCallingConvention::cdecl_call},
    {0x004F7320u, NativeCallingConvention::cdecl_call},
    {0x004F7390u, NativeCallingConvention::cdecl_call},
    {0x004F7400u, NativeCallingConvention::cdecl_call},
    {0x004F7470u, NativeCallingConvention::cdecl_call},
    {0x004F74E0u, NativeCallingConvention::cdecl_call},
    {0x004F7550u, NativeCallingConvention::cdecl_call},
    {0x004F75C0u, NativeCallingConvention::cdecl_call},
    {0x004F7630u, NativeCallingConvention::cdecl_call},
    {0x004F76A0u, NativeCallingConvention::cdecl_call},
    {0x004F7710u, NativeCallingConvention::cdecl_call},
    {0x004F7780u, NativeCallingConvention::cdecl_call},
    {0x004F77B0u, NativeCallingConvention::cdecl_call},
    {0x004F77F0u, NativeCallingConvention::cdecl_call},
    {0x004F7820u, NativeCallingConvention::cdecl_call},
    {0x004F7860u, NativeCallingConvention::cdecl_call},
    {0x004F7890u, NativeCallingConvention::cdecl_call},
    {0x004F78D0u, NativeCallingConvention::cdecl_call},
    {0x004F7900u, NativeCallingConvention::cdecl_call},
    {0x004F7940u, NativeCallingConvention::cdecl_call},
    {0x004F7970u, NativeCallingConvention::cdecl_call},
    {0x004F79B0u, NativeCallingConvention::cdecl_call},
    {0x004F79E0u, NativeCallingConvention::cdecl_call},
    {0x004F7A20u, NativeCallingConvention::cdecl_call},
    {0x004F7A50u, NativeCallingConvention::cdecl_call},
    {0x004F7A90u, NativeCallingConvention::cdecl_call},
    {0x004F7AC0u, NativeCallingConvention::cdecl_call},
    {0x004F7B00u, NativeCallingConvention::cdecl_call},
    {0x004F7B30u, NativeCallingConvention::cdecl_call},
    {0x004F7B70u, NativeCallingConvention::cdecl_call},
    {0x004F7BA0u, NativeCallingConvention::cdecl_call},
    {0x004F7BE0u, NativeCallingConvention::cdecl_call},
    {0x004F7BF0u, NativeCallingConvention::cdecl_call},
    {0x004F7C20u, NativeCallingConvention::cdecl_call},
    {0x004F7C60u, NativeCallingConvention::cdecl_call},
    {0x004F7C80u, NativeCallingConvention::cdecl_call},
    {0x004F7CA0u, NativeCallingConvention::cdecl_call},
    {0x004F7CD0u, NativeCallingConvention::cdecl_call},
    {0x004F7D10u, NativeCallingConvention::cdecl_call},
    {0x004F7D40u, NativeCallingConvention::cdecl_call},
    {0x004F7D80u, NativeCallingConvention::cdecl_call},
    {0x004F7DB0u, NativeCallingConvention::cdecl_call},
    {0x004F7DF0u, NativeCallingConvention::cdecl_call},
    {0x004F7E00u, NativeCallingConvention::cdecl_call},
    {0x004F7E30u, NativeCallingConvention::cdecl_call},
    {0x004F7E70u, NativeCallingConvention::cdecl_call},
    {0x004F7EA0u, NativeCallingConvention::cdecl_call},
    {0x004F7EE0u, NativeCallingConvention::cdecl_call},
    {0x004F7EF0u, NativeCallingConvention::cdecl_call},
    {0x004F7F20u, NativeCallingConvention::cdecl_call},
    {0x004F7F60u, NativeCallingConvention::cdecl_call},
    {0x004F7F90u, NativeCallingConvention::cdecl_call},
    {0x004F7FD0u, NativeCallingConvention::cdecl_call},
    {0x004F8000u, NativeCallingConvention::cdecl_call},
    {0x004F8040u, NativeCallingConvention::cdecl_call},
    {0x004F8070u, NativeCallingConvention::cdecl_call},
    {0x004F80B0u, NativeCallingConvention::cdecl_call},
    {0x004F8120u, NativeCallingConvention::cdecl_call},
    {0x004F8150u, NativeCallingConvention::cdecl_call},
    {0x004F8190u, NativeCallingConvention::cdecl_call},
    {0x004F81C0u, NativeCallingConvention::cdecl_call},
    {0x004F8200u, NativeCallingConvention::cdecl_call},
    {0x004F8220u, NativeCallingConvention::cdecl_call},
    {0x004F8240u, NativeCallingConvention::cdecl_call},
    {0x004F8270u, NativeCallingConvention::cdecl_call},
    {0x004F82B0u, NativeCallingConvention::cdecl_call},
    {0x004F82D0u, NativeCallingConvention::cdecl_call},
    {0x004F82F0u, NativeCallingConvention::cdecl_call},
    {0x004F8320u, NativeCallingConvention::cdecl_call},
    {0x004F8360u, NativeCallingConvention::cdecl_call},
    {0x004F8390u, NativeCallingConvention::cdecl_call},
    {0x004F83D0u, NativeCallingConvention::cdecl_call},
    {0x004F83F0u, NativeCallingConvention::cdecl_call},
    {0x004F8410u, NativeCallingConvention::cdecl_call},
    {0x004F8440u, NativeCallingConvention::cdecl_call},
    {0x004F8480u, NativeCallingConvention::cdecl_call},
    {0x004F84A0u, NativeCallingConvention::cdecl_call},
    {0x004F84C0u, NativeCallingConvention::cdecl_call},
    {0x004F84F0u, NativeCallingConvention::cdecl_call},
    {0x004F8530u, NativeCallingConvention::cdecl_call},
    {0x004F8550u, NativeCallingConvention::cdecl_call},
    {0x004F8570u, NativeCallingConvention::cdecl_call},
    {0x004F85A0u, NativeCallingConvention::cdecl_call},
    {0x004F85E0u, NativeCallingConvention::cdecl_call},
    {0x004F85F0u, NativeCallingConvention::cdecl_call},
    {0x004F8620u, NativeCallingConvention::cdecl_call},
    {0x004F8660u, NativeCallingConvention::cdecl_call},
    {0x004F8680u, NativeCallingConvention::cdecl_call},
    {0x004F86A0u, NativeCallingConvention::cdecl_call},
    {0x004F86D0u, NativeCallingConvention::cdecl_call},
    {0x004F8710u, NativeCallingConvention::cdecl_call},
    {0x004F8740u, NativeCallingConvention::cdecl_call},
    {0x004F8780u, NativeCallingConvention::cdecl_call},
    {0x004F87A0u, NativeCallingConvention::cdecl_call},
    {0x004F87C0u, NativeCallingConvention::cdecl_call},
    {0x004F87F0u, NativeCallingConvention::cdecl_call},
    {0x004F8830u, NativeCallingConvention::cdecl_call},
    {0x004F8850u, NativeCallingConvention::cdecl_call},
    {0x004F8870u, NativeCallingConvention::cdecl_call},
    {0x004F88A0u, NativeCallingConvention::cdecl_call},
    {0x004F88E0u, NativeCallingConvention::cdecl_call},
    {0x004F8900u, NativeCallingConvention::cdecl_call},
    {0x004F8920u, NativeCallingConvention::cdecl_call},
    {0x004F8950u, NativeCallingConvention::cdecl_call},
    {0x004F8990u, NativeCallingConvention::cdecl_call},
    {0x004F89B0u, NativeCallingConvention::cdecl_call},
    {0x004F89D0u, NativeCallingConvention::cdecl_call},
    {0x004F8A00u, NativeCallingConvention::cdecl_call},
    {0x004F8A40u, NativeCallingConvention::cdecl_call},
    {0x004F8A60u, NativeCallingConvention::cdecl_call},
    {0x004F8A80u, NativeCallingConvention::cdecl_call},
    {0x004F8AB0u, NativeCallingConvention::cdecl_call},
    {0x004F8AF0u, NativeCallingConvention::cdecl_call},
    {0x004F8B10u, NativeCallingConvention::cdecl_call},
    {0x004F8B30u, NativeCallingConvention::cdecl_call},
    {0x004F8B90u, NativeCallingConvention::cdecl_call},
    {0x004F8BF0u, NativeCallingConvention::cdecl_call},
    {0x004F8C50u, NativeCallingConvention::cdecl_call},
    {0x004F8C60u, NativeCallingConvention::cdecl_call},
    {0x004F8D20u, NativeCallingConvention::cdecl_call},
    {0x004F8D80u, NativeCallingConvention::cdecl_call},
    {0x004F8DA0u, NativeCallingConvention::cdecl_call},
    {0x004F8DD0u, NativeCallingConvention::cdecl_call},
    {0x004F8E10u, NativeCallingConvention::cdecl_call},
    {0x004F8E30u, NativeCallingConvention::cdecl_call},
    {0x004F8E50u, NativeCallingConvention::cdecl_call},
    {0x004F8E80u, NativeCallingConvention::cdecl_call},
    {0x004F8EC0u, NativeCallingConvention::cdecl_call},
    {0x004F8EF0u, NativeCallingConvention::cdecl_call},
    {0x004F8F30u, NativeCallingConvention::cdecl_call},
    {0x004F8F50u, NativeCallingConvention::cdecl_call},
    {0x004F8F70u, NativeCallingConvention::cdecl_call},
    {0x004F8FA0u, NativeCallingConvention::cdecl_call},
    {0x004F8FE0u, NativeCallingConvention::cdecl_call},
    {0x004F9000u, NativeCallingConvention::cdecl_call},
    {0x004F9020u, NativeCallingConvention::cdecl_call},
    {0x004F9040u, NativeCallingConvention::cdecl_call},
    {0x004F9060u, NativeCallingConvention::cdecl_call},
    {0x004F9080u, NativeCallingConvention::cdecl_call},
    {0x004F90B0u, NativeCallingConvention::cdecl_call},
    {0x004F90F0u, NativeCallingConvention::cdecl_call},
    {0x004F9110u, NativeCallingConvention::cdecl_call},
    {0x004F9130u, NativeCallingConvention::cdecl_call},
    {0x004F9160u, NativeCallingConvention::cdecl_call},
    {0x004F91A0u, NativeCallingConvention::cdecl_call},
    {0x004F91C0u, NativeCallingConvention::cdecl_call},
    {0x004F91E0u, NativeCallingConvention::cdecl_call},
    {0x004F9210u, NativeCallingConvention::cdecl_call},
    {0x004F9250u, NativeCallingConvention::cdecl_call},
    {0x004F9280u, NativeCallingConvention::cdecl_call},
    {0x004F92C0u, NativeCallingConvention::cdecl_call},
    {0x004F92E0u, NativeCallingConvention::cdecl_call},
    {0x004F9300u, NativeCallingConvention::cdecl_call},
    {0x004F9330u, NativeCallingConvention::cdecl_call},
    {0x004F9370u, NativeCallingConvention::cdecl_call},
    {0x004F9390u, NativeCallingConvention::cdecl_call},
    {0x004F93B0u, NativeCallingConvention::cdecl_call},
    {0x004F93E0u, NativeCallingConvention::cdecl_call},
    {0x004F9420u, NativeCallingConvention::cdecl_call},
    {0x004F9440u, NativeCallingConvention::cdecl_call},
    {0x004F9460u, NativeCallingConvention::cdecl_call},
    {0x004F9490u, NativeCallingConvention::cdecl_call},
    {0x004F94D0u, NativeCallingConvention::cdecl_call},
    {0x004F94F0u, NativeCallingConvention::cdecl_call},
    {0x004F9510u, NativeCallingConvention::cdecl_call},
    {0x004F9540u, NativeCallingConvention::cdecl_call},
    {0x004F9580u, NativeCallingConvention::cdecl_call},
    {0x004F95A0u, NativeCallingConvention::cdecl_call},
    {0x004F95C0u, NativeCallingConvention::cdecl_call},
    {0x004F95F0u, NativeCallingConvention::cdecl_call},
    {0x004F9630u, NativeCallingConvention::cdecl_call},
    {0x004F9650u, NativeCallingConvention::cdecl_call},
    {0x004F9670u, NativeCallingConvention::cdecl_call},
    {0x004F96A0u, NativeCallingConvention::cdecl_call},
    {0x004F96E0u, NativeCallingConvention::cdecl_call},
    {0x004F9700u, NativeCallingConvention::cdecl_call},
    {0x004F9720u, NativeCallingConvention::cdecl_call},
    {0x004F9730u, NativeCallingConvention::cdecl_call},
    {0x004F9740u, NativeCallingConvention::cdecl_call},
    {0x004F9750u, NativeCallingConvention::cdecl_call},
    {0x004F9780u, NativeCallingConvention::cdecl_call},
    {0x004F97C0u, NativeCallingConvention::cdecl_call},
    {0x004F97E0u, NativeCallingConvention::cdecl_call},
    {0x004F9800u, NativeCallingConvention::cdecl_call},
    {0x004F9830u, NativeCallingConvention::cdecl_call},
    {0x004F9870u, NativeCallingConvention::cdecl_call},
    {0x004F98A0u, NativeCallingConvention::cdecl_call},
    {0x004F98E0u, NativeCallingConvention::cdecl_call},
    {0x004F9900u, NativeCallingConvention::cdecl_call},
    {0x004F9920u, NativeCallingConvention::cdecl_call},
    {0x004F9950u, NativeCallingConvention::cdecl_call},
    {0x004F9990u, NativeCallingConvention::cdecl_call},
    {0x004F99B0u, NativeCallingConvention::cdecl_call},
    {0x004F99D0u, NativeCallingConvention::cdecl_call},
    {0x004F9A00u, NativeCallingConvention::cdecl_call},
    {0x004F9A40u, NativeCallingConvention::cdecl_call},
    {0x004F9A60u, NativeCallingConvention::cdecl_call},
    {0x004F9A80u, NativeCallingConvention::cdecl_call},
    {0x004F9AB0u, NativeCallingConvention::cdecl_call},
    {0x004F9AF0u, NativeCallingConvention::cdecl_call},
    {0x004F9B50u, NativeCallingConvention::cdecl_call},
    {0x004F9B80u, NativeCallingConvention::cdecl_call},
    {0x004F9BC0u, NativeCallingConvention::cdecl_call},
    {0x004F9BE0u, NativeCallingConvention::cdecl_call},
    {0x004F9C00u, NativeCallingConvention::cdecl_call},
    {0x004F9C20u, NativeCallingConvention::cdecl_call},
    {0x004F9C50u, NativeCallingConvention::cdecl_call},
    {0x004F9C90u, NativeCallingConvention::cdecl_call},
    {0x004F9CC0u, NativeCallingConvention::cdecl_call},
    {0x004F9D00u, NativeCallingConvention::cdecl_call},
    {0x004F9D30u, NativeCallingConvention::cdecl_call},
    {0x004F9D70u, NativeCallingConvention::cdecl_call},
    {0x004F9DA0u, NativeCallingConvention::cdecl_call},
    {0x004F9DE0u, NativeCallingConvention::cdecl_call},
    {0x004F9E10u, NativeCallingConvention::cdecl_call},
    {0x004F9E50u, NativeCallingConvention::cdecl_call},
    {0x004F9E80u, NativeCallingConvention::cdecl_call},
    {0x004F9EC0u, NativeCallingConvention::cdecl_call},
    {0x004F9EF0u, NativeCallingConvention::cdecl_call},
    {0x004F9F30u, NativeCallingConvention::cdecl_call},
    {0x004F9F60u, NativeCallingConvention::cdecl_call},
    {0x004F9FA0u, NativeCallingConvention::cdecl_call},
    {0x004F9FD0u, NativeCallingConvention::cdecl_call},
    {0x004FA010u, NativeCallingConvention::cdecl_call},
    {0x004FA041u, NativeCallingConvention::cdecl_call},
    {0x004FA050u, NativeCallingConvention::cdecl_call},
    {0x004FA060u, NativeCallingConvention::cdecl_call},
    {0x004FA070u, NativeCallingConvention::cdecl_call},
    {0x004FA080u, NativeCallingConvention::cdecl_call},
    {0x004FA090u, NativeCallingConvention::cdecl_call},
    {0x004FA0A0u, NativeCallingConvention::cdecl_call},
    {0x004FA0B0u, NativeCallingConvention::cdecl_call},
    {0x004FA0C0u, NativeCallingConvention::cdecl_call},
    {0x004FA0D0u, NativeCallingConvention::cdecl_call},
    {0x004FA120u, NativeCallingConvention::cdecl_call},
    {0x004FA130u, NativeCallingConvention::cdecl_call},
    {0x004FA140u, NativeCallingConvention::cdecl_call},
    {0x004FA150u, NativeCallingConvention::cdecl_call},
    {0x004FA170u, NativeCallingConvention::cdecl_call},
    {0x004FA1F0u, NativeCallingConvention::cdecl_call},
    {0x004FA250u, NativeCallingConvention::cdecl_call},
    {0x004FA260u, NativeCallingConvention::cdecl_call},
    {0x004FA270u, NativeCallingConvention::cdecl_call},
    {0x004FA280u, NativeCallingConvention::cdecl_call},
    {0x004FA2A0u, NativeCallingConvention::cdecl_call},
    {0x004FA2C0u, NativeCallingConvention::cdecl_call},
    {0x004FA2D0u, NativeCallingConvention::cdecl_call},
    {0x004FA2E0u, NativeCallingConvention::cdecl_call},
    {0x004FA310u, NativeCallingConvention::cdecl_call},
    {0x004FA340u, NativeCallingConvention::cdecl_call},
    {0x004FA350u, NativeCallingConvention::cdecl_call},
    {0x004FA360u, NativeCallingConvention::cdecl_call},
    {0x004FA370u, NativeCallingConvention::cdecl_call},
    {0x004FA3A0u, NativeCallingConvention::cdecl_call},
    {0x004FA3D0u, NativeCallingConvention::cdecl_call},
    {0x004FA3E0u, NativeCallingConvention::cdecl_call},
    {0x004FA400u, NativeCallingConvention::cdecl_call},
    {0x004FA420u, NativeCallingConvention::cdecl_call},
    {0x004FA440u, NativeCallingConvention::cdecl_call},
    {0x004FA450u, NativeCallingConvention::cdecl_call},
    {0x004FA460u, NativeCallingConvention::cdecl_call},
    {0x004FA470u, NativeCallingConvention::cdecl_call},
    {0x004FA490u, NativeCallingConvention::cdecl_call},
    {0x004FA4B0u, NativeCallingConvention::cdecl_call},
    {0x004FA4D0u, NativeCallingConvention::cdecl_call},
    {0x004FA4F0u, NativeCallingConvention::cdecl_call},
    {0x004FA510u, NativeCallingConvention::cdecl_call},
    {0x004FA530u, NativeCallingConvention::cdecl_call},
    {0x004FA550u, NativeCallingConvention::cdecl_call},
    {0x004FA570u, NativeCallingConvention::cdecl_call},
    {0x004FA590u, NativeCallingConvention::cdecl_call},
    {0x004FA5B0u, NativeCallingConvention::cdecl_call},
    {0x004FA5D0u, NativeCallingConvention::cdecl_call},
    {0x004FA5F0u, NativeCallingConvention::cdecl_call},
    {0x004FA610u, NativeCallingConvention::cdecl_call},
    {0x004FA630u, NativeCallingConvention::cdecl_call},
    {0x004FA650u, NativeCallingConvention::cdecl_call},
    {0x004FA670u, NativeCallingConvention::cdecl_call},
    {0x004FA690u, NativeCallingConvention::cdecl_call},
    {0x004FA6B0u, NativeCallingConvention::cdecl_call},
    {0x004FA6D0u, NativeCallingConvention::cdecl_call},
    {0x004FA6F0u, NativeCallingConvention::cdecl_call},
    {0x004FA710u, NativeCallingConvention::cdecl_call},
    {0x004FA730u, NativeCallingConvention::cdecl_call},
    {0x004FA750u, NativeCallingConvention::cdecl_call},
    {0x004FA770u, NativeCallingConvention::cdecl_call},
    {0x004FA790u, NativeCallingConvention::cdecl_call},
    {0x004FA7B0u, NativeCallingConvention::cdecl_call},
    {0x004FA7D0u, NativeCallingConvention::cdecl_call},
    {0x004FA7F0u, NativeCallingConvention::cdecl_call},
    {0x004FA810u, NativeCallingConvention::cdecl_call},
    {0x004FA830u, NativeCallingConvention::cdecl_call},
    {0x004FA850u, NativeCallingConvention::cdecl_call},
    {0x004FA870u, NativeCallingConvention::cdecl_call},
    {0x004FA890u, NativeCallingConvention::cdecl_call},
    {0x004FA8B0u, NativeCallingConvention::cdecl_call},
    {0x004FA8D0u, NativeCallingConvention::cdecl_call},
    {0x004FA8F0u, NativeCallingConvention::cdecl_call},
    {0x004FA910u, NativeCallingConvention::cdecl_call},
    {0x004FA930u, NativeCallingConvention::cdecl_call},
    {0x004FA950u, NativeCallingConvention::cdecl_call},
    {0x004FA970u, NativeCallingConvention::cdecl_call},
    {0x004FA990u, NativeCallingConvention::cdecl_call},
    {0x004FA9B0u, NativeCallingConvention::cdecl_call},
    {0x004FA9D0u, NativeCallingConvention::cdecl_call},
    {0x004FA9F0u, NativeCallingConvention::cdecl_call},
    {0x004FAA10u, NativeCallingConvention::cdecl_call},
    {0x004FAA30u, NativeCallingConvention::cdecl_call},
    {0x004FAA50u, NativeCallingConvention::cdecl_call},
    {0x004FAA70u, NativeCallingConvention::cdecl_call},
    {0x004FAA90u, NativeCallingConvention::cdecl_call},
    {0x004FAAB0u, NativeCallingConvention::cdecl_call},
    {0x004FAAD0u, NativeCallingConvention::cdecl_call},
    {0x004FAAF0u, NativeCallingConvention::cdecl_call},
    {0x004FAB10u, NativeCallingConvention::cdecl_call},
    {0x004FAB30u, NativeCallingConvention::cdecl_call},
    {0x004FAB50u, NativeCallingConvention::cdecl_call},
    {0x004FAB70u, NativeCallingConvention::cdecl_call},
    {0x004FAB90u, NativeCallingConvention::cdecl_call},
    {0x004FABB0u, NativeCallingConvention::cdecl_call},
    {0x004FABD0u, NativeCallingConvention::cdecl_call},
    {0x004FABF0u, NativeCallingConvention::cdecl_call},
    {0x004FAC10u, NativeCallingConvention::cdecl_call},
    {0x004FAC30u, NativeCallingConvention::cdecl_call},
    {0x004FAC60u, NativeCallingConvention::cdecl_call},
    {0x004FAC90u, NativeCallingConvention::cdecl_call},
    {0x004FACF0u, NativeCallingConvention::cdecl_call},
    {0x004FAD00u, NativeCallingConvention::cdecl_call},
    {0x004FAD10u, NativeCallingConvention::cdecl_call},
    {0x004FAD20u, NativeCallingConvention::cdecl_call},
    {0x004FAD30u, NativeCallingConvention::cdecl_call},
    {0x004FAD40u, NativeCallingConvention::cdecl_call},
    {0x004FAD50u, NativeCallingConvention::cdecl_call},
    {0x004FAD60u, NativeCallingConvention::cdecl_call},
    {0x004FAD70u, NativeCallingConvention::cdecl_call},
    {0x004FAD80u, NativeCallingConvention::cdecl_call},
    {0x004FAD90u, NativeCallingConvention::cdecl_call},
    {0x004FADA0u, NativeCallingConvention::cdecl_call},
    {0x004FADB0u, NativeCallingConvention::cdecl_call},
    {0x004FADE0u, NativeCallingConvention::cdecl_call},
    {0x004FAE10u, NativeCallingConvention::cdecl_call},
    {0x004FAE20u, NativeCallingConvention::cdecl_call},
    {0x004FAE30u, NativeCallingConvention::cdecl_call},
    {0x004FAE40u, NativeCallingConvention::cdecl_call},
    {0x004FAEC0u, NativeCallingConvention::cdecl_call},
    {0x004FAED0u, NativeCallingConvention::cdecl_call},
    {0x004FAEE0u, NativeCallingConvention::cdecl_call},
    {0x004FAF20u, NativeCallingConvention::cdecl_call},
    {0x004FAF30u, NativeCallingConvention::cdecl_call},
    {0x004FAF40u, NativeCallingConvention::cdecl_call},
    {0x004FAF50u, NativeCallingConvention::cdecl_call},
    {0x004FAF60u, NativeCallingConvention::cdecl_call},
    {0x004FAF80u, NativeCallingConvention::cdecl_call},
    {0x004FAF90u, NativeCallingConvention::cdecl_call},
    {0x004FAFA0u, NativeCallingConvention::cdecl_call},
    {0x004FAFD0u, NativeCallingConvention::cdecl_call},
    {0x004FB000u, NativeCallingConvention::cdecl_call},
    {0x004FB010u, NativeCallingConvention::cdecl_call},
    {0x004FB040u, NativeCallingConvention::cdecl_call},
    {0x004FB070u, NativeCallingConvention::cdecl_call},
    {0x004FB080u, NativeCallingConvention::cdecl_call},
    {0x004FB090u, NativeCallingConvention::cdecl_call},
    {0x004FB0C0u, NativeCallingConvention::cdecl_call},
    {0x004FB0F0u, NativeCallingConvention::cdecl_call},
    {0x004FB100u, NativeCallingConvention::cdecl_call},
    {0x004FB130u, NativeCallingConvention::cdecl_call},
    {0x004FB160u, NativeCallingConvention::cdecl_call},
    {0x004FB170u, NativeCallingConvention::cdecl_call},
    {0x004FB1A0u, NativeCallingConvention::cdecl_call},
    {0x004FB1D0u, NativeCallingConvention::cdecl_call},
    {0x004FB1E0u, NativeCallingConvention::cdecl_call},
    {0x004FB220u, NativeCallingConvention::cdecl_call},
    {0x004FB230u, NativeCallingConvention::cdecl_call},
    {0x004FB260u, NativeCallingConvention::cdecl_call},
    {0x004FB290u, NativeCallingConvention::cdecl_call},
    {0x004FB2A0u, NativeCallingConvention::cdecl_call},
    {0x004FB2B0u, NativeCallingConvention::cdecl_call},
    {0x004FB2E0u, NativeCallingConvention::cdecl_call},
    {0x004FB310u, NativeCallingConvention::cdecl_call},
    {0x004FB320u, NativeCallingConvention::cdecl_call},
    {0x004FB350u, NativeCallingConvention::cdecl_call},
    {0x004FB380u, NativeCallingConvention::cdecl_call},
    {0x004FB390u, NativeCallingConvention::cdecl_call},
    {0x004FB3C0u, NativeCallingConvention::cdecl_call},
    {0x004FB3F0u, NativeCallingConvention::cdecl_call},
    {0x004FB400u, NativeCallingConvention::cdecl_call},
    {0x004FB430u, NativeCallingConvention::cdecl_call},
    {0x004FB460u, NativeCallingConvention::cdecl_call},
    {0x004FB470u, NativeCallingConvention::cdecl_call},
    {0x004FB4A0u, NativeCallingConvention::cdecl_call},
    {0x004FB4D0u, NativeCallingConvention::cdecl_call},
    {0x004FB4E0u, NativeCallingConvention::cdecl_call},
    {0x004FB510u, NativeCallingConvention::cdecl_call},
    {0x004FB540u, NativeCallingConvention::cdecl_call},
    {0x004FB590u, NativeCallingConvention::cdecl_call},
    {0x004FB5E0u, NativeCallingConvention::cdecl_call},
    {0x004FB630u, NativeCallingConvention::cdecl_call},
    {0x004FB660u, NativeCallingConvention::cdecl_call},
    {0x004FB680u, NativeCallingConvention::fastcall_call},
    {0x004FB6D0u, NativeCallingConvention::cdecl_call},
    {0x004FB6E0u, NativeCallingConvention::cdecl_call},
    {0x004FB6F0u, NativeCallingConvention::cdecl_call},
    {0x004FB720u, NativeCallingConvention::cdecl_call},
    {0x004FB750u, NativeCallingConvention::cdecl_call},
    {0x004FB760u, NativeCallingConvention::cdecl_call},
    {0x004FB770u, NativeCallingConvention::cdecl_call},
    {0x004FB7A0u, NativeCallingConvention::cdecl_call},
    {0x004FB7D0u, NativeCallingConvention::cdecl_call},
    {0x004FB7E0u, NativeCallingConvention::cdecl_call},
    {0x004FB810u, NativeCallingConvention::cdecl_call},
    {0x004FB840u, NativeCallingConvention::cdecl_call},
    {0x004FB870u, NativeCallingConvention::cdecl_call},
    {0x004FB8A0u, NativeCallingConvention::cdecl_call},
    {0x004FB8D0u, NativeCallingConvention::cdecl_call},
    {0x004FB8E0u, NativeCallingConvention::cdecl_call},
    {0x004FB910u, NativeCallingConvention::cdecl_call},
    {0x004FB940u, NativeCallingConvention::cdecl_call},
    {0x004FB950u, NativeCallingConvention::cdecl_call},
    {0x004FB980u, NativeCallingConvention::cdecl_call},
    {0x004FB9B0u, NativeCallingConvention::cdecl_call},
    {0x004FB9C0u, NativeCallingConvention::cdecl_call},
    {0x004FB9D0u, NativeCallingConvention::cdecl_call},
    {0x004FBA00u, NativeCallingConvention::cdecl_call},
    {0x004FBA30u, NativeCallingConvention::cdecl_call},
    {0x004FBA40u, NativeCallingConvention::cdecl_call},
    {0x004FBA70u, NativeCallingConvention::cdecl_call},
    {0x004FBAA0u, NativeCallingConvention::cdecl_call},
    {0x004FBAB0u, NativeCallingConvention::cdecl_call},
    {0x004FBAE0u, NativeCallingConvention::cdecl_call},
    {0x004FBB10u, NativeCallingConvention::cdecl_call},
    {0x004FBB20u, NativeCallingConvention::cdecl_call},
    {0x004FBB50u, NativeCallingConvention::cdecl_call},
    {0x004FBB80u, NativeCallingConvention::cdecl_call},
    {0x004FBB90u, NativeCallingConvention::cdecl_call},
    {0x004FBBC0u, NativeCallingConvention::cdecl_call},
    {0x004FBBF0u, NativeCallingConvention::cdecl_call},
    {0x004FBC00u, NativeCallingConvention::cdecl_call},
    {0x004FBC30u, NativeCallingConvention::cdecl_call},
    {0x004FBC60u, NativeCallingConvention::cdecl_call},
    {0x004FBC70u, NativeCallingConvention::cdecl_call},
    {0x004FBCA0u, NativeCallingConvention::cdecl_call},
    {0x004FBCD0u, NativeCallingConvention::cdecl_call},
    {0x004FBD10u, NativeCallingConvention::cdecl_call},
    {0x004FBD50u, NativeCallingConvention::cdecl_call},
    {0x004FBD90u, NativeCallingConvention::cdecl_call},
    {0x004FBDA0u, NativeCallingConvention::cdecl_call},
    {0x004FBDD0u, NativeCallingConvention::cdecl_call},
    {0x004FBE00u, NativeCallingConvention::cdecl_call},
    {0x004FBE10u, NativeCallingConvention::cdecl_call},
    {0x004FBE20u, NativeCallingConvention::cdecl_call},
    {0x004FBE50u, NativeCallingConvention::cdecl_call},
    {0x004FBE80u, NativeCallingConvention::cdecl_call},
    {0x004FBE90u, NativeCallingConvention::cdecl_call},
    {0x004FBEC0u, NativeCallingConvention::cdecl_call},
    {0x004FBEF0u, NativeCallingConvention::cdecl_call},
    {0x004FBF00u, NativeCallingConvention::cdecl_call},
    {0x004FBF30u, NativeCallingConvention::cdecl_call},
    {0x004FBF60u, NativeCallingConvention::cdecl_call},
    {0x004FBF70u, NativeCallingConvention::cdecl_call},
    {0x004FBFC0u, NativeCallingConvention::cdecl_call},
    {0x004FBFD0u, NativeCallingConvention::cdecl_call},
    {0x004FC000u, NativeCallingConvention::cdecl_call},
    {0x004FC030u, NativeCallingConvention::cdecl_call},
    {0x004FC090u, NativeCallingConvention::cdecl_call},
    {0x004FC0A0u, NativeCallingConvention::cdecl_call},
    {0x004FC0B0u, NativeCallingConvention::cdecl_call},
    {0x004FC0C0u, NativeCallingConvention::cdecl_call},
    {0x004FC0D0u, NativeCallingConvention::cdecl_call},
    {0x004FC0E0u, NativeCallingConvention::cdecl_call},
    {0x004FC0F0u, NativeCallingConvention::cdecl_call},
    {0x004FC100u, NativeCallingConvention::cdecl_call},
    {0x004FC110u, NativeCallingConvention::cdecl_call},
    {0x004FC120u, NativeCallingConvention::cdecl_call},
    {0x004FC130u, NativeCallingConvention::cdecl_call},
    {0x004FC140u, NativeCallingConvention::cdecl_call},
    {0x004FC150u, NativeCallingConvention::cdecl_call},
    {0x004FC15Au, NativeCallingConvention::cdecl_call},
}};
} // namespace
} // namespace native_binding

const NativeEntry* find_native_entry(std::uint32_t source_va) noexcept {
    const auto found = std::lower_bound(native_binding::kNativeEntries.begin(), native_binding::kNativeEntries.end(), source_va, [](const NativeEntry& entry, std::uint32_t address) { return entry.source_va < address; });
    return found != native_binding::kNativeEntries.end() && found->source_va == source_va ? &*found : nullptr;
}

NativeCallingConvention native_abi_hint(std::uint32_t source_va) noexcept {
    const auto found = std::lower_bound(native_binding::kAbiHints.begin(), native_binding::kAbiHints.end(), source_va, [](const native_binding::AbiHint& hint, std::uint32_t address) { return hint.source_va < address; });
    return found != native_binding::kAbiHints.end() && found->source_va == source_va ? found->convention : NativeCallingConvention::cdecl_call;
}

NativeResult invoke_native_entry(const NativeEntry& entry, const NativeArgument* arguments, std::size_t argument_count) { return entry.invoke(arguments, argument_count); }

std::size_t native_entry_count() noexcept { return native_binding::kNativeEntries.size(); }

std::uint64_t native_source_line_coverage() noexcept {
    std::uint64_t result = 0;
    for (const NativeEntry& entry : native_binding::kNativeEntries) { result += entry.source_lines; }
    return result;
}
} // namespace sfera::semantic
