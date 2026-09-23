#pragma once

// Platform-independent values, numeric policies and bounded binary/text primitives.
// Win32, COM, D3D, input and VM owners do not belong in this header.
#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cerrno>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <format>
#include <functional>
#include <istream>
#include <optional>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

struct SferaColor {
    std::array<std::uint8_t, 4> channels;
    static constexpr SferaColor rgba(std::uint32_t red, std::uint32_t green, std::uint32_t blue, std::uint32_t alpha = 255u) {
        const std::array components{red, green, blue, alpha};
        SferaColor result{};
        for (std::size_t index = 0; index < components.size(); ++index) result.channels[index] = components[index] & 255u;
        return result;
    }
    static constexpr SferaColor fromArgb(std::uint32_t value) { return rgba(value >> 16u, value >> 8u, value, value >> 24u); }
    constexpr std::uint32_t red() const { return channels[0]; }
    constexpr std::uint32_t green() const { return channels[1]; }
    constexpr std::uint32_t blue() const { return channels[2]; }
    constexpr std::uint32_t alpha() const { return channels[3]; }
    constexpr std::uint32_t argb() const { return (alpha() << 24u) | (red() << 16u) | (green() << 8u) | blue(); }
    constexpr SferaColor withAlpha(std::uint32_t value) const { return rgba(red(), green(), blue(), value); }
    constexpr SferaColor scaledAlpha(std::uint32_t factor, std::uint32_t divisor = 255u) const { return withAlpha(alpha() * factor / divisor); }
    constexpr SferaColor scaledRgb(std::uint32_t factor, std::uint32_t divisor) const { return rgba(red() * factor / divisor, green() * factor / divisor, blue() * factor / divisor, alpha()); }
    constexpr std::uint16_t rgb565() const { return ((red() >> 3u) << 11u) | ((green() >> 2u) << 5u) | (blue() >> 3u); }
    static constexpr SferaColor fromArgb4444(std::uint16_t value) { return rgba(((value >> 8u) & 15u) * 17u, ((value >> 4u) & 15u) * 17u, (value & 15u) * 17u, (value >> 12u) * 17u); }
    constexpr std::uint16_t argb4444() const { return ((alpha() >> 4u) << 12u) | ((red() >> 4u) << 8u) | ((green() >> 4u) << 4u) | (blue() >> 4u); }
};

struct SferaScreenVertex {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float rhw;
    std::uint32_t diffuse;
    std::uint32_t specular;
    float u;
    float v;
};

namespace SferaAlgorithms {
    // Preserve input order for equal keys; NaNs sort last and never violate strict weak ordering.
    template<class Range, class Projection> void stableSort(Range&& values, Projection key) {
        std::stable_sort(values.begin(), values.end(), [&](const auto& left, const auto& right) {
            const auto a = key(left), b = key(right);
            if constexpr (std::is_floating_point_v<decltype(a)>) {
                if (std::isnan(a)) return false;
                if (std::isnan(b)) return true;
            }
            return a < b;
        });
    }
}

namespace SferaBinary {
    template<class T, std::size_t Extent>
    std::span<T> range(std::span<T, Extent> bytes, std::size_t offset, std::size_t count) {
        if (offset > bytes.size() || count > bytes.size() - offset)
            throw std::out_of_range("Binary range exceeds its buffer");
        return bytes.subspan(offset, count);
    }
    inline void copy(std::span<std::uint8_t> destination, std::span<const std::uint8_t> source) {
        if (source.size() > destination.size()) throw std::out_of_range("Binary destination is too small");
        if (!source.empty()) std::memmove(destination.data(), source.data(), source.size());
    }
    inline bool read(std::istream& stream, std::span<std::uint8_t> destination) {
        if (!std::in_range<std::streamsize>(destination.size())) throw std::length_error("Binary read is too large");
        if (destination.empty()) return true;
        std::string input(destination.size(), '\0');
        // Preserve untouched bytes even when the stream buffer writes a prefix and throws.
        // gcount() alone cannot describe that partial write on every exception path.
        std::memcpy(input.data(), destination.data(), destination.size());
        const auto commit = [&] { std::memcpy(destination.data(), input.data(), input.size()); };
        try {
            stream.read(input.data(), static_cast<std::streamsize>(input.size()));
        } catch (...) {
            commit();
            throw;
        }
        commit();
        return !stream.fail();
    }
    template<class T, class Byte> requires (std::is_integral_v<T> && !std::is_same_v<T, bool> &&
        (std::is_same_v<Byte, std::uint8_t> || std::is_same_v<Byte, std::byte>))
    T readLittleEndian(const Byte* bytes) noexcept {
        using Unsigned = std::make_unsigned_t<T>;
        Unsigned value = 0;
        for (std::size_t index = sizeof(T); index != 0; --index) {
            if constexpr (sizeof(T) > 1) value <<= 8;
            if constexpr (std::is_same_v<Byte, std::byte>) value |= std::to_integer<unsigned int>(bytes[index - 1]);
            else value |= bytes[index - 1];
        }
        if constexpr (std::is_signed_v<T>) {
            if (value > std::numeric_limits<T>::max()) {
                const T complement = std::numeric_limits<Unsigned>::max() - value;
                return -1 - complement;
            }
        }
        return value;
    }
    template<class T, class Byte> requires (std::is_integral_v<T> && !std::is_same_v<T, bool> &&
        (std::is_same_v<Byte, std::uint8_t> || std::is_same_v<Byte, std::byte>))
    void writeLittleEndian(Byte* bytes, T value) noexcept {
        // Unsigned arithmetic preserves the complete two's-complement representation.
        std::make_unsigned_t<T> bits = value;
        for (std::size_t index = 0; index < sizeof(T); ++index) {
            if constexpr (std::is_same_v<Byte, std::byte>) bytes[index] = static_cast<std::byte>(bits & 255u);
            else bytes[index] = bits & 255u;
            if constexpr (sizeof(T) > 1) bits >>= 8;
        }
    }
    class ReadError : public std::runtime_error {
    public:
        using std::runtime_error::runtime_error;
    };
    class Reader {
    public:
        explicit Reader(std::span<const std::uint8_t> bytes) : bytes_(bytes) {}
        std::span<const std::uint8_t> take(std::size_t size) {
            if (size > bytes_.size()) throw ReadError("Truncated binary record");
            const auto result = bytes_.first(size);
            bytes_ = bytes_.subspan(size);
            return result;
        }
        std::size_t remaining() const noexcept { return bytes_.size(); }
        std::string readTerminated(std::size_t capacity) {
            const auto field = bytes_.first(std::min(bytes_.size(), capacity));
            const auto end = std::find(field.begin(), field.end(), std::uint8_t{});
            if (end == field.end()) throw ReadError("Unterminated binary string");
            const std::size_t count = end - field.begin();
            const auto value = take(count + 1);
            return std::string(value.begin(), value.begin() + count);
        }
        template<class T> T read() {
            if constexpr (std::is_same_v<T, float>) return std::bit_cast<float>(read<std::uint32_t>());
            else return readLittleEndian<T>(take(sizeof(T)).data());
        }
    private:
        std::span<const std::uint8_t> bytes_;
    };

}

struct SferaVec3F {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    SferaVec3F operator+(const SferaVec3F& other) const;
    SferaVec3F operator-(const SferaVec3F& other) const;
    SferaVec3F operator*(float factor) const;
    SferaVec3F subtractScaled(const SferaVec3F& direction, float factor) const;
    template<class Accumulator = double, bool YFirst = false> Accumulator dot(const SferaVec3F& other) const {
        const std::array<Accumulator, 3> components{x, y, z};
        if constexpr (YFirst) return components[1] * other.y + components[0] * other.x + components[2] * other.z;
        else return components[0] * other.x + components[1] * other.y + components[2] * other.z;
    }
    template<class Accumulator = double, class Root = double, bool YFirst = false>
    float length() const {
        const float squared = dot<Accumulator, YFirst>(*this);
        const Root radicand = squared;
        return std::sqrt(radicand);
    }
    // A zero threshold, precision and divide-vs-reciprocal are observable in old effects.
    template<class Accumulator = double, class Root = double, bool Divide = false, bool PropagateNaN = false>
    SferaVec3F unit(float threshold, const SferaVec3F& fallback) const {
        const float magnitude = length<Accumulator, Root>();
        if (magnitude <= threshold || (!PropagateNaN && std::isnan(magnitude))) return fallback;
        if constexpr (Divide) return {x / magnitude, y / magnitude, z / magnitude};
        else return *this * (1.0f / magnitude);
    }
    SferaVec3F normalized(int diagnosticCode = 0) const;
    void normalize();
    template<class Accumulator = double> SferaVec3F cross(const SferaVec3F& other) const {
        const std::array<Accumulator, 3> components{x, y, z};
        SferaVec3F result;
        result.x = components[1] * other.z - components[2] * other.y;
        result.y = components[2] * other.x - components[0] * other.z;
        result.z = components[0] * other.y - components[1] * other.x;
        return result;
    }
    float component(std::size_t axis) const;
    void setComponent(std::size_t axis, float value);
    static void rotatePair(float& first, float& second, float angle);
    bool containsConvexPolygonPoint(std::span<const SferaVec3F* const> vertices, const SferaVec3F& point) const;
};

namespace SphereRender {
    struct PositionNormalUvVertex {
        SferaVec3F position;
        SferaVec3F normal;
        float u;
        float v;
    };
    struct PositionColorUvVertex {
        SferaVec3F position;
        std::uint32_t diffuse;
        std::uint32_t specular;
        float u;
        float v;
    };
}

class SferaAngle8 {
public:
    explicit SferaAngle8(float radians);
    float distanceTo(SferaAngle8 other) const;
private:
    std::uint8_t steps;
};

struct SferaVec4F {
    float x;
    float y;
    float z;
    float w;
};

namespace SferaMath {
    inline float interpolate(float first, double second, float fraction) {
        return (second - first) * fraction + first;
    }
    struct RotationTerms {
        double sine;
        double cosine;
    };
    inline RotationTerms rotationTerms(double angle) {
        // Rotation formulas historically use single-rounded trigonometric values.
        const float sine = std::sin(angle), cosine = std::cos(angle);
        return {sine, cosine};
    }
    inline SferaVec3F interpolate(const SferaVec3F& a, const SferaVec3F& b, float fraction) {
        return {interpolate(a.x, b.x, fraction), interpolate(a.y, b.y, fraction), interpolate(a.z, b.z, fraction)};
    }
    inline SferaVec4F interpolate(const SferaVec4F& a, const SferaVec4F& b, float fraction) {
        return {interpolate(a.x, b.x, fraction), interpolate(a.y, b.y, fraction), interpolate(a.z, b.z, fraction), interpolate(a.w, b.w, fraction)};
    }
}

struct SferaMatrix3x3F {
    float m[3][3];
};

struct SferaQuaternionF {
    float w;
    float x;
    float y;
    float z;

    SferaMatrix3x3F rotationMatrix() const;
    SferaQuaternionF interpolated(const SferaQuaternionF& other, float factor) const;
};

struct SferaMatrix4x4F {
    enum class Axis { x, y, z };
    float m[4][4];

    static SferaMatrix4x4F identity();
    template<class Trigonometry = double> static SferaMatrix4x4F fromAxisRotation(Axis axis, float angle) {
        SferaMatrix4x4F result = identity();
        const std::size_t first = axis == Axis::x ? 1u : axis == Axis::y ? 2u : 0u;
        const std::size_t second = (first + 1u) % 3u;
        const Trigonometry radians = angle;
        const float sine = std::sin(radians), cosine = std::cos(radians);
        result.m[first][first] = result.m[second][second] = cosine;
        result.m[first][second] = -sine;
        result.m[second][first] = sine;
        return result;
    }
    static SferaMatrix4x4F fromRollPitchYaw(float roll, float pitch, float yaw);
    static SferaMatrix4x4F fromEuler(const SferaVec3F& translation, const SferaVec3F& angles);
    static SferaMatrix4x4F fromQuaternion(const SferaQuaternionF& rotation, const SferaVec3F& translation = {});
    template<class Accumulator = double> SferaVec3F transformPoint(const SferaVec3F& point) const {
        SferaVec3F result{};
        for (std::size_t row = 0; row < 3; ++row) {
            const std::array<Accumulator, 3> basis{m[row][0], m[row][1], m[row][2]};
            result.setComponent(row, basis[0] * point.x + basis[1] * point.y + basis[2] * point.z + m[row][3]);
        }
        return result;
    }
    SferaVec3F inverseTransformPoint(const SferaVec3F& point) const;
    template<class Accumulator = double> SferaMatrix4x4F multiplied(const SferaMatrix4x4F& other) const {
        SferaMatrix4x4F result{};
        for (std::size_t row = 0; row < 4; ++row) for (std::size_t column = 0; column < 4; ++column) {
            Accumulator value = 0;
            for (std::size_t axis = 0; axis < 4; ++axis) {
                const Accumulator element = m[row][axis];
                value += element * other.m[axis][column];
            }
            result.m[row][column] = value;
        }
        return result;
    }
    static SferaMatrix4x4F fromXyzRotation(const SferaVec3F& angles) {
        return fromAxisRotation<float>(Axis::x, angles.x).multiplied<float>(fromAxisRotation<float>(Axis::y, angles.y))
            .multiplied<float>(fromAxisRotation<float>(Axis::z, angles.z));
    }
    SferaMatrix4x4F transposed() const;
    void scaleAxes(const SferaVec3F& scale);
};

struct SferaBoundsCornersRuntime {
    SferaVec3F corners[8];

    static SferaBoundsCornersRuntime fromExtents(const SferaVec3F& minimum, const SferaVec3F& maximum);
    static SferaBoundsCornersRuntime empty();
    void getExtents(SferaVec3F& minimum, SferaVec3F& maximum) const;
};

struct SferaPlaneF {
    SferaVec3F normal;
    float distance;

    double evaluate(const SferaVec3F& point) const;
    int intersectLine(const SferaVec3F& start, const SferaVec3F& end, SferaVec3F& intersection) const;
};

struct SferaFrustumF {
    SferaPlaneF planes[6];

    int classifyPoints(std::span<const SferaVec3F> points) const;
};

class SferaPolygon3F {
public:
    std::vector<SferaVec3F> vertices;

    void clipToAxis(std::size_t axis, float boundary, bool keepGreater);
    bool clipTriangleToBounds(const SferaVec3F& first, const SferaVec3F& second, const SferaVec3F& third, const SferaVec3F& minimum, const SferaVec3F& maximum);
};

struct SferaIntBounds3 {
    std::int64_t min_x;
    std::int64_t max_x;
    std::int64_t min_y;
    std::int64_t max_y;
    std::int64_t min_z;
    std::int64_t max_z;
};

struct SferaViewProjectionScratchRuntime {
    SferaVec3F corners[8];
    SferaIntBounds3 clipping_bounds;

    SferaViewProjectionScratchRuntime translated(const SferaVec3F& offset) const;
};

struct SferaParserRange {
    std::ptrdiff_t begin;
    std::ptrdiff_t end;
};

// Scoped restoration of CPU-side render state, independent of D3D state-blocks.
template<class T> class SferaRestore {
public:
    explicit SferaRestore(T& target) : target_(target), saved_(target) {}
    ~SferaRestore() noexcept { restore(); }
    void restore() noexcept { if (std::exchange(active_, false)) target_ = std::move(saved_); }
    SferaRestore(const SferaRestore&) = delete;
    SferaRestore& operator=(const SferaRestore&) = delete;
private:
    static_assert(std::is_nothrow_move_assignable_v<T>);
    T& target_;
    T saved_;
    bool active_ = true;
};

namespace SferaText {
    template<class Mapping> void transformBytes(std::string& text, Mapping mapping) {
        for (auto& byte : std::as_writable_bytes(std::span(text)))
            byte = static_cast<std::byte>(mapping(std::to_integer<std::uint8_t>(byte)));
    }
    inline void lowercaseLocale(std::string& text) {
        transformBytes(text, [](std::uint8_t value) { return std::tolower(value); });
    }
    struct Hash {
        using is_transparent = void;
        std::size_t operator()(std::string_view value) const noexcept { return std::hash<std::string_view>{}(value); }
    };
    constexpr std::uint8_t asciiFold(std::uint8_t byte) noexcept {
        return byte >= 'A' && byte <= 'Z' ? static_cast<std::uint8_t>(byte + ('a' - 'A')) : byte;
    }
    constexpr bool asciiEqual(std::string_view a, std::string_view b) noexcept {
        if (a.size() != b.size()) return false;
        for (std::size_t i = 0; i < a.size(); ++i)
            if (asciiFold(static_cast<std::uint8_t>(a[i])) != asciiFold(static_cast<std::uint8_t>(b[i]))) return false;
        return true;
    }
    const std::array<char32_t, 256>& unicodeCp1251();
    const std::array<std::uint8_t, 256>& lowercaseCp1251();
    std::string resourceKey(std::string_view name);
    std::size_t findInsensitive(std::string_view text, std::string_view needle);
    std::string_view fileName(std::string_view path);
    std::string encodeUri(std::string_view source, std::size_t capacity = std::numeric_limits<std::size_t>::max());
    bool matchesWildcard(std::string_view text, std::string_view pattern);
    int compare(std::string_view first, std::string_view second);
    int compareInsensitive(std::string_view first, std::string_view second);
    // Byte-backed fields are decoded into owned text. No view aliases binary memory.
    // This preserves every code unit of the client's single-byte encoding, including NUL.
    inline std::string fromBytes(std::span<const std::byte> bytes) {
        std::string text(bytes.size(), '\0');
        if (!bytes.empty()) std::memcpy(text.data(), bytes.data(), bytes.size());
        return text;
    }
    inline std::string fromBytes(std::span<const std::uint8_t> bytes) {
        return fromBytes(std::as_bytes(bytes));
    }
    inline std::size_t length(std::span<const std::uint8_t> bytes,
                              std::size_t limit = std::numeric_limits<std::size_t>::max()) {
        if (limit == 0) return 0;
        const auto field = bytes.first(std::min(bytes.size(), limit));
        const auto end = std::find(field.begin(), field.end(), std::uint8_t{});
        if (end == field.end() && limit > bytes.size()) throw std::out_of_range("Unterminated text buffer");
        return field.empty() ? 0u : static_cast<std::size_t>(end - field.begin());
    }
    inline std::string prefix(std::span<const std::uint8_t> bytes, std::size_t limit) {
        return fromBytes(bytes.first(length(bytes, limit)));
    }
    inline std::string terminated(std::span<const std::uint8_t> bytes) {
        return prefix(bytes, std::numeric_limits<std::size_t>::max());
    }

    // Mutable text exists only at a binary boundary. Every write reserves a terminator;
    // no raw character pointer or unchecked element access escapes this interface.
    class Buffer {
    public:
        explicit Buffer(std::span<std::uint8_t> bytes) noexcept : bytes_(bytes) {}
        std::size_t size() const noexcept { return bytes_.size(); }
        bool empty() const noexcept { return bytes_.empty(); }
        Buffer limited(std::size_t capacity) const noexcept { return Buffer(bytes_.first(std::min(size(), capacity))); }
        std::size_t length() const { return SferaText::length(bytes_); }
        std::size_t write(std::string_view source) const {
            if (empty()) return 0;
            const auto count = std::min(source.size(), size() - 1);
            if (count != 0) std::memmove(bytes_.data(), source.data(), count);
            bytes_[count] = 0;
            return count;
        }
        void assign(std::string_view source) const {
            if (source.size() >= size()) throw std::out_of_range("Text destination is too small");
            write(source);
        }
        void append(std::string_view source) const {
            const auto count = length();
            Buffer(bytes_.subspan(count)).assign(source);
        }
        // Bounded formatting leaves untouched padding except for the final sentinel.
        std::size_t writeBounded(std::string_view source, std::size_t capacity) const {
            if (capacity == 0) return 0;
            if (capacity > size()) throw std::out_of_range("Bounded text destination is too small");
            const auto copied = limited(capacity).write(source);
            bytes_[capacity - 1] = 0;
            return copied;
        }
        // MBC bounded copies write count bytes of payload/padding and one final NUL.
        std::size_t writePadded(std::string_view source, std::size_t count) const {
            if (count >= size()) throw std::out_of_range("Padded text destination is too small");
            const auto copied = limited(count + 1).write(source);
            std::fill(bytes_.begin() + copied, bytes_.begin() + count + 1, std::uint8_t{});
            return copied;
        }
    private:
        std::span<std::uint8_t> bytes_;
    };
    // The returned count includes the terminator, as required by the MBC instruction set.
    std::uint32_t copyString(Buffer destination, std::string_view source, int capacity);

    inline std::optional<std::string> readTerminated(std::istream& stream, std::size_t capacity) {
        std::string value;
        for (std::size_t index = 0; index < capacity; ++index) {
            const auto input = stream.get();
            if (std::istream::traits_type::eq_int_type(input, std::istream::traits_type::eof())) return std::nullopt;
            const auto character = std::istream::traits_type::to_char_type(input);
            if (character == '\0') return value;
            value.push_back(character);
        }
        return std::nullopt;
    }

    // Retain the existing CRT prefix, sign, locale and hexadecimal-float grammar.
    template<class Number> bool readNumber(std::string_view text, Number& output) {
        static_assert(std::is_same_v<Number, int> || std::is_same_v<Number, float>);
        const std::string input(text);
        try {
            if constexpr (std::is_same_v<Number, float>) output = std::stof(input);
            else {
                errno = 0;
                output = std::stoi(input, nullptr, 10);
            }
            return true;
        } catch (const std::invalid_argument&) {
            return false;
        } catch (const std::out_of_range&) {
            if constexpr (std::is_same_v<Number, float>) {
                // The legacy float parser accepts underflow/overflow. Keep its CRT
                // result after stof has established that a numeric prefix exists.
                output = std::strtof(input.c_str(), nullptr);
                return true;
            }
            return false;
        }
    }
    inline std::size_t configValueOffset(std::string_view text, std::string_view key) {
        for (std::size_t line = 0; line < text.size();) {
            auto end = line;
            while (end < text.size() && text[end] != ' ' && text[end] != '\t' && text[end] != '\r' && text[end] != '\0') ++end;
            if (text.substr(line, end - line) == key) {
                while (end < text.size() && (text[end] == ' ' || text[end] == '\t')) ++end;
                return end;
            }
            while (line < text.size() && text[line] != '\n' && text[line] != '\0') ++line;
            if (line == text.size() || text[line] == '\0') break;
            ++line;
        }
        return std::string_view::npos;
    }
    inline bool replaceConfigValue(std::string& text, std::string_view key, std::string_view value,
                                   bool quoted, std::size_t capacity) {
        const std::string name(key), replacement(value);
        std::string next(text);
        const auto offset = configValueOffset(next, name);
        if (offset != std::string::npos) {
            const bool preserveQuotes = offset < next.size() && next[offset] == '"';
            const auto begin = offset + (preserveQuotes ? 1u : 0u);
            const auto end = next.find_first_of(preserveQuotes ? "\"\r\0" : "\r\0", begin, preserveQuotes ? 3u : 2u);
            next.replace(begin, (end == std::string::npos ? next.size() : end) - begin, replacement);
        } else {
            if (!next.empty()) next += "\r\n";
            next += name; next += '\t';
            if (quoted) next += '"';
            next += replacement;
            if (quoted) next += '"';
        }
        if (next.size() >= capacity) return false;
        text.swap(next);
        return true;
    }
}
