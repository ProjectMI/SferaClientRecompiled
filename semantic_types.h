#pragma once

// Platform-independent values, numeric policies and bounded binary/text primitives.
// Win32, COM, D3D, input and VM owners do not belong in this header.
#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cerrno>
#include <cstdlib>
#include <cstring>
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
    static constexpr SferaColor rgba(std::uint32_t red, std::uint32_t green, std::uint32_t blue, std::uint32_t alpha = 255u) { return {{static_cast<std::uint8_t>(red), static_cast<std::uint8_t>(green), static_cast<std::uint8_t>(blue), static_cast<std::uint8_t>(alpha)}}; }
    static constexpr SferaColor fromArgb(std::uint32_t value) { return rgba(value >> 16u, value >> 8u, value, value >> 24u); }
    constexpr std::uint8_t red() const { return channels[0]; }
    constexpr std::uint8_t green() const { return channels[1]; }
    constexpr std::uint8_t blue() const { return channels[2]; }
    constexpr std::uint8_t alpha() const { return channels[3]; }
    constexpr std::uint32_t argb() const { return (std::uint32_t(alpha()) << 24u) | (std::uint32_t(red()) << 16u) | (std::uint32_t(green()) << 8u) | blue(); }
    constexpr SferaColor withAlpha(std::uint32_t value) const { return rgba(red(), green(), blue(), value); }
    constexpr SferaColor scaledAlpha(std::uint32_t factor, std::uint32_t divisor = 255u) const { return withAlpha(std::uint32_t(alpha()) * factor / divisor); }
    constexpr SferaColor scaledRgb(std::uint32_t factor, std::uint32_t divisor) const { return rgba(std::uint32_t(red()) * factor / divisor, std::uint32_t(green()) * factor / divisor, std::uint32_t(blue()) * factor / divisor, alpha()); }
    constexpr std::uint16_t rgb565() const { return static_cast<std::uint16_t>(((red() >> 3u) << 11u) | ((green() >> 2u) << 5u) | (blue() >> 3u)); }
    static constexpr SferaColor fromArgb4444(std::uint16_t value) { return rgba(((value >> 8u) & 15u) * 17u, ((value >> 4u) & 15u) * 17u, (value & 15u) * 17u, (value >> 12u) * 17u); }
    constexpr std::uint16_t argb4444() const { return static_cast<std::uint16_t>(((alpha() >> 4u) << 12u) | ((red() >> 4u) << 8u) | ((green() >> 4u) << 4u) | (blue() >> 4u)); }
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
    template<class T> requires (std::is_integral_v<T> && !std::is_same_v<T, bool>)
    T readLittleEndian(const std::uint8_t* bytes) noexcept {
        using Unsigned = std::make_unsigned_t<T>;
        Unsigned value = 0;
        for (std::size_t index = 0; index < sizeof(T); ++index) value |= static_cast<Unsigned>(static_cast<Unsigned>(bytes[index]) << (index * 8));
        return std::bit_cast<T>(value);
    }
    template<class T> requires (std::is_integral_v<T> && !std::is_same_v<T, bool>)
    void writeLittleEndian(std::uint8_t* bytes, T value) noexcept {
        const auto bits = std::bit_cast<std::make_unsigned_t<T>>(value);
        for (std::size_t index = 0; index < sizeof(T); ++index) bytes[index] = static_cast<std::uint8_t>(bits >> (index * 8));
    }
    class Reader {
    public:
        explicit Reader(std::span<const std::uint8_t> bytes) : bytes_(bytes) {}
        std::span<const std::uint8_t> take(std::size_t size) {
            if (size > bytes_.size()) throw std::runtime_error("Truncated binary record");
            const auto result = bytes_.first(size);
            bytes_ = bytes_.subspan(size);
            return result;
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
    template<class Accumulator = double> Accumulator dot(const SferaVec3F& other) const {
        return Accumulator(x) * other.x + Accumulator(y) * other.y + Accumulator(z) * other.z;
    }
    template<class Accumulator = double, class Root = double, bool YFirst = false>
    float length() const {
        const float squared = YFirst
            ? (Accumulator(y) * y + Accumulator(x) * x) + Accumulator(z) * z
            : dot<Accumulator>(*this);
        return static_cast<float>(std::sqrt(Root(squared)));
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
        return {static_cast<float>(Accumulator(y) * other.z - Accumulator(z) * other.y),
                static_cast<float>(Accumulator(z) * other.x - Accumulator(x) * other.z),
                static_cast<float>(Accumulator(x) * other.y - Accumulator(y) * other.x)};
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
    inline float interpolate(float first, float second, float fraction) {
        return static_cast<float>((double(second) - first) * fraction + first);
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
    const float sine = std::sin(Trigonometry(angle));
    const float cosine = std::cos(Trigonometry(angle));
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
        for (std::size_t row = 0; row < 3; ++row)
            result.setComponent(row, static_cast<float>(Accumulator(m[row][0]) * point.x +
                Accumulator(m[row][1]) * point.y + Accumulator(m[row][2]) * point.z + m[row][3]));
        return result;
    }
    SferaVec3F inverseTransformPoint(const SferaVec3F& point) const;
    template<class Accumulator = double> SferaMatrix4x4F multiplied(const SferaMatrix4x4F& other) const {
        SferaMatrix4x4F result{};
        for (std::size_t row = 0; row < 4; ++row) for (std::size_t column = 0; column < 4; ++column) {
            Accumulator value = 0;
            for (std::size_t axis = 0; axis < 4; ++axis) value += Accumulator(m[row][axis]) * other.m[axis][column];
            result.m[row][column] = static_cast<float>(value);
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
    constexpr std::uint8_t asciiFold(std::uint8_t byte) noexcept {
        return byte >= 'A' && byte <= 'Z' ? static_cast<std::uint8_t>(byte + ('a' - 'A')) : byte;
    }
    constexpr bool asciiEqual(std::string_view a, std::string_view b) noexcept {
        if (a.size() != b.size()) return false;
        for (std::size_t i = 0; i < a.size(); ++i)
            if (asciiFold(static_cast<std::uint8_t>(a[i])) != asciiFold(static_cast<std::uint8_t>(b[i]))) return false;
        return true;
    }
    inline bool asciiEqual(const char* a, const char* b) noexcept {
        return a && b && asciiEqual(std::string_view(a), std::string_view(b));
    }
    const std::array<char32_t, 256>& unicodeCp1251();
    const std::array<std::uint8_t, 256>& lowercaseCp1251();
    std::string resourceKey(std::string_view name);
    const char* findInsensitive(const char* text, const char* needle);
    const char* fileName(const char* path);
    void encodeUri(char* destination, const char* source, std::size_t capacity);
    bool matchesWildcard(const char* text, const char* pattern);
    // MBC compatibility operation: capacity<=0 means caller-validated complete destination.
    std::uint32_t copyString(char* destination, const char* source, int capacity);
    inline void copy(std::span<char> destination, const char* source) {
        if (destination.empty()) return;
        std::size_t length = 0;
        if (source) while (length + 1 < destination.size() && source[length]) ++length;
        if (length) std::memmove(destination.data(), source, length);
        destination[length] = 0;
    }
    // Retain the existing CRT prefix, sign, locale and hexadecimal-float grammar.
    template<class Number> bool readNumber(std::string_view text, Number& output) {
        static_assert(std::is_same_v<Number, int> || std::is_same_v<Number, float>);
        const std::string input(text);
        char* end = nullptr;
        if constexpr (std::is_same_v<Number, float>) {
            const float value = std::strtof(input.c_str(), &end);
            if (end == input.c_str()) return false;
            output = value;
        } else {
            errno = 0;
            const auto value = std::strtol(input.c_str(), &end, 10);
            if (end == input.c_str() || errno == ERANGE || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) return false;
            output = static_cast<int>(value);
        }
        return true;
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
