#pragma once

#include <array>
#include <chrono>
#include <compare>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <filesystem>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <set>
#include <span>
#include <string>
#include <string_view>
#include <unordered_map>
#include <variant>
#include <vector>

namespace sfera::semantic {

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Matrix3x4 {
    std::array<float, 12> values{};
};

struct Matrix3x3 {
    std::array<float, 9> values{};
};

struct Plane {
    Vec3 normal{};
    float distance{};
};

struct TransformReference {
    const Matrix3x4* matrix{};
};

void transform_point(Vec3* destination, const Matrix3x4* transform, const Vec3* source);
std::uint32_t is_model_file(const char* path);

namespace script {

struct Sequence;
struct LinkedSequence;
struct OrderedMap;
struct OrderedSet;

enum class ScalarKind : std::uint8_t {
    null_value,
    signed_integer,
    unsigned_integer,
    floating_point,
    boolean,
    text,
    vector3,
    sequence,
    linked_sequence,
    ordered_map,
    ordered_set
};

class Value {
public:
    using Storage = std::variant<std::monostate, std::int32_t, std::uint32_t, float, bool, std::string, Vec3, std::shared_ptr<Sequence>, std::shared_ptr<LinkedSequence>, std::shared_ptr<OrderedMap>, std::shared_ptr<OrderedSet>>;

    Value() = default;
    Value(std::int32_t value);
    Value(std::uint32_t value);
    Value(float value);
    Value(bool value);
    Value(std::string value);
    Value(std::string_view value);
    Value(const char* value);
    Value(Vec3 value);

    static Value sequence();
    static Value linked_sequence();
    static Value ordered_map();
    static Value ordered_set();

    ScalarKind kind() const noexcept;
    bool is_number() const noexcept;
    double number() const;
    std::int64_t integer() const;
    bool truthy() const noexcept;
    std::string text() const;
    const Storage& storage() const noexcept;
    Storage& storage() noexcept;

private:
    Storage storage_{};
    explicit Value(Storage storage);
};

struct ValueLess {
    bool operator()(const Value& left, const Value& right) const;
};

struct Sequence {
    std::vector<Value> values;
};

struct LinkedSequence {
    std::list<Value> values;
};

struct OrderedMap {
    std::map<Value, Value, ValueLess> values;
};

struct OrderedSet {
    std::set<Value, ValueLess> values;
};

enum class Operator : std::uint8_t {
    add,
    subtract,
    multiply,
    divide,
    remainder,
    equal,
    not_equal,
    less,
    less_equal,
    greater,
    greater_equal,
    logical_and,
    logical_or,
    bit_and,
    bit_or,
    bit_xor,
    shift_left,
    shift_right
};

Value apply(Operator operation, const Value& left, const Value& right);
Value negate(const Value& value);
Value logical_not(const Value& value);
std::optional<Value> find(const Value& collection, const Value& key);
void assign(Value& collection, Value key, Value value);
bool erase(Value& collection, const Value& key);
std::size_t size(const Value& collection) noexcept;

enum class OpCode : std::uint8_t {
    push_constant,
    load_variable,
    store_variable,
    binary,
    unary_negate,
    unary_not,
    call,
    jump,
    jump_if_false,
    discard,
    halt
};

struct Instruction {
    OpCode opcode{OpCode::halt};
    std::uint32_t operand{};
    Operator operation{Operator::add};
};

class VirtualMachine {
public:
    using Procedure = std::function<Value(std::span<const Value>)>;

    void set_program(std::vector<Instruction> program, std::vector<Value> constants);
    void register_procedure(std::uint32_t identifier, Procedure procedure);
    void set_variable(std::uint32_t identifier, Value value);
    const Value* variable(std::uint32_t identifier) const noexcept;
    void push(Value value);
    Value pop();
    bool step();
    void run(std::size_t instruction_budget = 100000u);
    bool halted() const noexcept;
    std::size_t instruction_pointer() const noexcept;
    const std::vector<Value>& stack() const noexcept;

private:
    std::vector<Instruction> program_;
    std::vector<Value> constants_;
    std::vector<Value> stack_;
    std::unordered_map<std::uint32_t, Value> variables_;
    std::unordered_map<std::uint32_t, Procedure> procedures_;
    std::size_t instruction_pointer_{};
    bool halted_{true};
};

} // namespace script

namespace network {

struct PacketHeader {
    std::uint16_t size{};
    std::uint16_t checksum{};
    std::uint16_t sequence{};
    std::uint16_t opcode{};
};

struct Packet {
    PacketHeader header;
    std::vector<std::uint8_t> payload;
};

class PacketQueue {
public:
    explicit PacketQueue(std::size_t capacity = 80000u);
    bool enqueue(std::uint16_t opcode, std::span<const std::uint8_t> payload, std::uint16_t sequence_increment, std::uint16_t checksum_seed);
    std::span<const std::uint8_t> pending() const noexcept;
    void consume(std::size_t byte_count);
    void clear() noexcept;
    std::size_t packet_count() const noexcept;

private:
    std::size_t capacity_;
    std::vector<std::uint8_t> bytes_;
    std::uint16_t sequence_{};
    std::size_t packet_count_{};
};

class PacketStream {
public:
    explicit PacketStream(std::size_t capacity = 60000u);
    bool append(std::span<const std::uint8_t> bytes);
    std::optional<Packet> next();
    void clear() noexcept;

private:
    std::size_t capacity_;
    std::vector<std::uint8_t> bytes_;
};

enum class ConnectionState : std::uint8_t {
    stopped,
    connecting,
    handshaking,
    connected,
    closing,
    failed
};

class ConnectionSession {
public:
    void begin(std::string host, std::uint16_t port);
    void accept_handshake(std::uint32_t peer_identifier, std::uint16_t checksum_seed);
    void mark_connected() noexcept;
    void fail(std::string reason);
    void close() noexcept;
    ConnectionState state() const noexcept;
    const std::string& host() const noexcept;
    std::uint16_t port() const noexcept;
    std::uint32_t peer_identifier() const noexcept;
    std::uint16_t checksum_seed() const noexcept;
    const std::string& error() const noexcept;

private:
    ConnectionState state_{ConnectionState::stopped};
    std::string host_;
    std::uint16_t port_{};
    std::uint32_t peer_identifier_{};
    std::uint16_t checksum_seed_{};
    std::string error_;
};

} // namespace network

namespace assets {

struct ManifestEntry {
    std::filesystem::path path;
    std::uint32_t size{};
    std::uint32_t timestamp{};
    std::uint32_t checksum{};
};

std::uint32_t crc32(std::span<const std::uint8_t> bytes, std::uint32_t initial = 0u) noexcept;
std::uint32_t manifest_checksum(std::string_view relative_path, std::uint32_t size, std::uint32_t timestamp) noexcept;
std::vector<std::filesystem::path> split_search_path(std::string_view search_path);
std::vector<ManifestEntry> scan_manifest(const std::filesystem::path& root, std::string_view wildcard, std::size_t pause_after = 0u, const std::function<void()>& pause = {});

} // namespace assets

namespace character {

struct Quaternion {
    float x{};
    float y{};
    float z{};
    float w{1.0f};
};

struct BonePose {
    Vec3 translation{};
    Quaternion rotation{};
};

struct Bone {
    std::string name;
    std::int32_t parent{-1};
    Matrix3x4 inverse_bind{};
};

class Skeleton {
public:
    std::size_t add_bone(Bone bone);
    std::optional<std::size_t> find_bone(std::string_view name) const noexcept;
    std::vector<Matrix3x4> build_matrices(std::span<const BonePose> pose) const;
    const std::vector<Bone>& bones() const noexcept;

private:
    std::vector<Bone> bones_;
    std::unordered_map<std::string, std::size_t> by_name_;
};

Quaternion normalize(Quaternion value) noexcept;
Quaternion interpolate(Quaternion from, Quaternion to, float amount) noexcept;
BonePose interpolate(const BonePose& from, const BonePose& to, float amount) noexcept;
Matrix3x4 compose(const BonePose& pose) noexcept;
Matrix3x4 multiply(const Matrix3x4& left, const Matrix3x4& right) noexcept;

} // namespace character

namespace effects {

struct BloodVertex {
    Vec3 position{};
    float u{};
    float v{};
};

struct BloodMark {
    float lifetime{};
    std::vector<BloodVertex> vertices;
};

class BloodEffect {
public:
    explicit BloodEffect(std::size_t maximum_marks = 30u);
    bool add(std::span<const Vec3> polygon, const Matrix3x4& transform, float lifetime, float texture_scale, float texture_offset_u, float texture_offset_v);
    void update(float elapsed_seconds) noexcept;
    void clear() noexcept;
    const std::deque<BloodMark>& marks() const noexcept;
    std::size_t vertex_count() const noexcept;

private:
    std::size_t maximum_marks_;
    std::deque<BloodMark> marks_;
};

} // namespace effects

namespace render {

enum class ResourceKind : std::uint8_t {
    vertex_buffer,
    index_buffer,
    texture,
    shader
};

struct ResourceHandle {
    std::uint32_t value{};
    constexpr explicit operator bool() const noexcept { return value != 0u; }
    constexpr auto operator<=>(const ResourceHandle&) const = default;
};

struct ResourceDescription {
    ResourceKind kind{ResourceKind::texture};
    std::uint32_t width{};
    std::uint32_t height{};
    std::uint32_t bytes{};
    bool managed{};
    std::string name;
};

class ResourceRegistry {
public:
    ResourceHandle add(ResourceDescription description);
    bool remove(ResourceHandle handle) noexcept;
    const ResourceDescription* find(ResourceHandle handle) const noexcept;
    std::vector<ResourceHandle> unmanaged_resources() const;
    void clear_unmanaged();
    std::size_t size() const noexcept;

private:
    std::uint32_t next_identifier_{1u};
    std::unordered_map<std::uint32_t, ResourceDescription> resources_;
};

struct RenderStateKey {
    std::uint16_t category{};
    std::uint16_t slot{};
    constexpr auto operator<=>(const RenderStateKey&) const = default;
};

struct RenderStateKeyHash {
    std::size_t operator()(RenderStateKey key) const noexcept;
};

class StateCache {
public:
    using Apply = std::function<void(RenderStateKey, std::uint32_t)>;
    explicit StateCache(Apply apply = {});
    bool set(RenderStateKey key, std::uint32_t value);
    std::optional<std::uint32_t> get(RenderStateKey key) const noexcept;
    void invalidate() noexcept;

private:
    Apply apply_;
    std::unordered_map<RenderStateKey, std::uint32_t, RenderStateKeyHash> values_;
};

struct ShaderConstant {
    std::string name;
    std::vector<float> values;
};

class ShaderProgram {
public:
    explicit ShaderProgram(std::string name = {});
    void set(std::string name, std::span<const float> values);
    const ShaderConstant* constant(std::string_view name) const noexcept;
    const std::string& name() const noexcept;

private:
    std::string name_;
    std::unordered_map<std::string, ShaderConstant> constants_;
};

struct PostEffectPass {
    std::string shader;
    ResourceHandle input;
    ResourceHandle output;
    std::vector<ShaderConstant> constants;
};

class PostEffects {
public:
    void append(PostEffectPass pass);
    std::optional<PostEffectPass> take_next();
    void clear() noexcept;
    std::size_t size() const noexcept;

private:
    std::deque<PostEffectPass> passes_;
};

} // namespace render

namespace service {

class MemoryTracker {
public:
    struct Record {
        std::size_t size{};
        std::string file;
        std::uint32_t line{};
    };

    void register_allocation(void* pointer, Record record);
    std::optional<Record> release(void* pointer);
    std::optional<Record> find(const void* pointer) const;
    std::size_t allocation_count() const noexcept;
    std::size_t allocated_bytes() const noexcept;

private:
    mutable std::mutex mutex_;
    std::unordered_map<const void*, Record> allocations_;
    std::size_t allocated_bytes_{};
};

class FileImage {
public:
    bool open(const std::filesystem::path& path);
    void close() noexcept;
    bool is_open() const noexcept;
    std::span<const std::uint8_t> bytes() const noexcept;
    const std::filesystem::path& path() const noexcept;

private:
    std::filesystem::path path_;
    std::vector<std::uint8_t> bytes_;
};

class AntifloodQueue {
public:
    explicit AntifloodQueue(std::chrono::milliseconds interval = std::chrono::seconds(1));
    bool accept(std::string_view message, std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now());
    std::size_t suppressed(std::string_view message) const noexcept;
    void clear() noexcept;

private:
    struct Entry {
        std::chrono::steady_clock::time_point last{};
        std::size_t suppressed{};
    };
    std::chrono::milliseconds interval_;
    std::unordered_map<std::string, Entry> entries_;
};

} // namespace service

namespace effect_runtime {

enum class AttachmentPoint : std::uint8_t {
    world,
    left_hand,
    right_hand,
    between_hands
};

enum class PartKind : std::uint8_t {
    light,
    particle_system,
    mesh,
    sound,
    scripted_effect
};

struct TimeRange {
    float begin{};
    float end{};
    bool contains(float time) const noexcept;
    float duration() const noexcept;
};

struct PartDefinition {
    PartKind kind{PartKind::particle_system};
    std::string resource;
    TimeRange time;
    AttachmentPoint attachment{AttachmentPoint::world};
    Vec3 offset{};
    float scale{1.0f};
};

struct ScriptedEffectDefinition {
    std::string name;
    float time_limit{};
    std::vector<PartDefinition> parts;
    bool valid() const noexcept;
    float duration() const noexcept;
};

class EffectLibrary {
public:
    bool store(ScriptedEffectDefinition definition, bool replace = false);
    bool erase(std::string_view name);
    std::shared_ptr<const ScriptedEffectDefinition> resolve(std::string_view name) const noexcept;
    std::vector<std::string> names() const;
    std::size_t size() const noexcept;

private:
    std::unordered_map<std::string, std::shared_ptr<const ScriptedEffectDefinition>> definitions_;
};

struct ActivePart {
    PartKind kind{PartKind::particle_system};
    std::string resource;
    AttachmentPoint attachment{AttachmentPoint::world};
    Vec3 position{};
    float age{};
    float progress{};
    float scale{1.0f};
};

class EffectInstance {
public:
    EffectInstance(std::uint64_t identifier, std::shared_ptr<const ScriptedEffectDefinition> definition, Vec3 origin);
    void update(float elapsed_seconds) noexcept;
    void move(Vec3 origin) noexcept;
    bool finished() const noexcept;
    std::uint64_t identifier() const noexcept;
    std::string_view name() const noexcept;
    std::vector<ActivePart> active_parts() const;

private:
    std::uint64_t identifier_{};
    std::shared_ptr<const ScriptedEffectDefinition> definition_;
    Vec3 origin_{};
    float elapsed_{};
};

class EffectScheduler {
public:
    explicit EffectScheduler(const EffectLibrary& library);
    std::optional<std::uint64_t> spawn(std::string_view name, Vec3 origin = {});
    bool move(std::uint64_t identifier, Vec3 origin) noexcept;
    bool cancel(std::uint64_t identifier) noexcept;
    void update(float elapsed_seconds) noexcept;
    std::vector<ActivePart> active_parts() const;
    std::size_t size() const noexcept;

private:
    const EffectLibrary* library_{};
    std::uint64_t next_identifier_{1u};
    std::vector<EffectInstance> instances_;
};

struct TrailPoint {
    Vec3 position{};
    float lifetime{};
};

class BladeTrail {
public:
    explicit BladeTrail(float point_lifetime = 0.2f, std::size_t maximum_points = 64u);
    void append(Vec3 point);
    void update(float elapsed_seconds) noexcept;
    const std::deque<TrailPoint>& points() const noexcept;

private:
    float point_lifetime_{};
    std::size_t maximum_points_{};
    std::deque<TrailPoint> points_;
};

struct RainDrop {
    Vec3 position{};
    float speed{};
};

class RainField {
public:
    RainField(Vec3 minimum, Vec3 maximum, float drops_per_second, float fall_speed, std::uint32_t seed = 1u);
    void update(float elapsed_seconds);
    void clear() noexcept;
    const std::vector<RainDrop>& drops() const noexcept;

private:
    float random_unit() noexcept;
    Vec3 minimum_{};
    Vec3 maximum_{};
    float drops_per_second_{};
    float fall_speed_{};
    float spawn_credit_{};
    std::uint32_t random_state_{};
    std::vector<RainDrop> drops_;
};

} // namespace effect_runtime

namespace audio_runtime {

struct SoundDefinition {
    std::string name;
    std::filesystem::path file;
    float gain{1.0f};
    float pitch{1.0f};
    float duration{};
    float minimum_distance{1.0f};
    float maximum_distance{100.0f};
    bool loop{};
    std::string group{"effects"};
};

struct CueEvent {
    float time{};
    std::string sound;
};

struct SoundCue {
    std::string name;
    std::vector<CueEvent> events;
    float duration() const noexcept;
};

class SoundLibrary {
public:
    bool store(SoundDefinition definition, bool replace = false);
    bool store(SoundCue cue, bool replace = false);
    const SoundDefinition* sound(std::string_view name) const noexcept;
    const SoundCue* cue(std::string_view name) const noexcept;
    std::size_t sound_count() const noexcept;
    std::size_t cue_count() const noexcept;

private:
    std::unordered_map<std::string, SoundDefinition> sounds_;
    std::unordered_map<std::string, SoundCue> cues_;
};

enum class VoiceState : std::uint8_t {
    scheduled,
    playing,
    paused,
    stopped
};

struct VoiceSnapshot {
    std::uint64_t identifier{};
    std::string sound;
    VoiceState state{VoiceState::stopped};
    Vec3 position{};
    float playback_time{};
    float effective_gain{};
};

class Mixer {
public:
    explicit Mixer(const SoundLibrary& library);
    std::optional<std::uint64_t> play(std::string_view sound, Vec3 position = {}, float delay = 0.0f);
    std::vector<std::uint64_t> play_cue(std::string_view cue, Vec3 position = {});
    bool stop(std::uint64_t identifier) noexcept;
    bool pause(std::uint64_t identifier, bool paused) noexcept;
    void set_master_gain(float gain) noexcept;
    void set_group_gain(std::string group, float gain);
    void update(float elapsed_seconds) noexcept;
    std::vector<VoiceSnapshot> voices() const;
    std::size_t active_voice_count() const noexcept;

private:
    struct Voice {
        std::uint64_t identifier{};
        SoundDefinition sound;
        VoiceState state{VoiceState::scheduled};
        Vec3 position{};
        float delay{};
        float playback_time{};
    };
    float effective_gain(const Voice& voice) const noexcept;
    const SoundLibrary* library_{};
    std::uint64_t next_identifier_{1u};
    float master_gain_{1.0f};
    std::unordered_map<std::string, float> group_gains_;
    std::vector<Voice> voices_;
};

} // namespace audio_runtime

namespace log_runtime {

enum class Severity : std::uint8_t {
    trace,
    information,
    warning,
    error,
    critical
};

struct Record {
    std::chrono::system_clock::time_point time;
    Severity severity{Severity::information};
    std::string channel;
    std::string message;
};

std::string format(const Record& record);

class Sink {
public:
    virtual ~Sink() = default;
    virtual void write(const Record& record) = 0;
};

class MemorySink final : public Sink {
public:
    void write(const Record& record) override;
    std::vector<Record> records() const;
    void clear() noexcept;

private:
    mutable std::mutex mutex_;
    std::vector<Record> records_;
};

class FileSink final : public Sink {
public:
    explicit FileSink(std::filesystem::path path);
    void write(const Record& record) override;
    const std::filesystem::path& path() const noexcept;

private:
    std::filesystem::path path_;
    std::mutex mutex_;
};

class Logger {
public:
    explicit Logger(std::string channel = {});
    void add_sink(std::shared_ptr<Sink> sink);
    void set_minimum_severity(Severity severity) noexcept;
    void write(Severity severity, std::string message);
    const std::string& channel() const noexcept;

private:
    std::string channel_;
    Severity minimum_severity_{Severity::trace};
    std::mutex mutex_;
    std::vector<std::shared_ptr<Sink>> sinks_;
};

class Registry {
public:
    std::shared_ptr<Logger> logger(std::string channel);
    void attach_to_all(std::shared_ptr<Sink> sink);
    std::size_t size() const noexcept;

private:
    mutable std::mutex mutex_;
    std::unordered_map<std::string, std::shared_ptr<Logger>> loggers_;
    std::vector<std::shared_ptr<Sink>> shared_sinks_;
};

} // namespace log_runtime

namespace shared_runtime {

std::string normalize_key(std::string_view value);
std::uint32_t hash_key(std::string_view value) noexcept;
std::uint32_t wildcard_match(const char* text, const char* pattern);
std::uint32_t is_transport_mode(std::int32_t mode);
std::uint8_t interop_storage_class(std::uint32_t kind);
std::int32_t wrapped_heading_delta(std::int32_t left, std::int32_t right);

class StringIndex {
public:
    explicit StringIndex(std::size_t maximum_key_length = 255u);
    std::optional<std::uint32_t> insert(std::string key, bool replace = false);
    bool erase(std::string_view key) noexcept;
    std::optional<std::uint32_t> find(std::string_view key) const noexcept;
    std::optional<std::string> key(std::uint32_t index) const;
    std::size_t size() const noexcept;
    void clear() noexcept;

private:
    std::size_t maximum_key_length_{};
    std::uint32_t next_index_{};
    std::unordered_map<std::string, std::uint32_t> by_key_;
    std::unordered_map<std::uint32_t, std::string> by_index_;
};

struct ItemRecord {
    std::uint64_t identifier{};
    std::string name;
    std::string type;
    std::int64_t quantity{1};
    std::map<std::string, script::Value> attributes;
};

enum class InsertMode : std::uint8_t {
    reject_existing,
    replace_existing,
    merge_quantity
};

class ItemList {
public:
    bool add(ItemRecord item, InsertMode mode = InsertMode::reject_existing);
    std::optional<ItemRecord> remove(std::string_view name);
    ItemRecord* find(std::string_view name) noexcept;
    const ItemRecord* find(std::string_view name) const noexcept;
    const ItemRecord* first() const noexcept;
    const ItemRecord* next(std::string_view current_name) const noexcept;
    std::vector<std::string> names() const;
    std::int64_t total_quantity() const noexcept;
    std::size_t size() const noexcept;
    void clear() noexcept;

private:
    std::map<std::string, ItemRecord> items_;
};

struct ServerInfo {
    std::uint32_t identifier{};
    std::string name;
    std::string host;
    std::uint16_t port{};
    std::uint32_t population{};
    bool online{};
};

class ServerDirectory {
public:
    bool update(ServerInfo server);
    bool remove(std::uint32_t identifier) noexcept;
    const ServerInfo* find(std::uint32_t identifier) const noexcept;
    const ServerInfo* find(std::string_view name) const noexcept;
    std::vector<ServerInfo> online_servers() const;
    std::size_t size() const noexcept;

private:
    std::unordered_map<std::uint32_t, ServerInfo> servers_;
};

struct ModuleArray {
    std::uint32_t tag{};
    std::uint32_t offset{};
    std::uint32_t size{};
};

class BytecodeModule {
public:
    bool load(std::string name, std::vector<std::uint8_t> bytecode, std::vector<ModuleArray> arrays);
    std::span<const std::uint8_t> array(std::uint32_t tag) const noexcept;
    std::span<const std::uint8_t> bytes() const noexcept;
    std::string_view name() const noexcept;
    bool valid() const noexcept;

private:
    std::string name_;
    std::vector<std::uint8_t> bytecode_;
    std::vector<ModuleArray> arrays_;
    bool valid_{};
};

class ModuleRegistry {
public:
    bool store(BytecodeModule module, bool replace = false);
    bool erase(std::string_view name) noexcept;
    const BytecodeModule* find(std::string_view name) const noexcept;
    std::vector<std::string> names() const;
    std::size_t size() const noexcept;

private:
    std::unordered_map<std::string, BytecodeModule> modules_;
};

class CommandRegistry {
public:
    using Handler = std::function<script::Value(std::span<const script::Value>)>;
    bool register_handler(std::string name, Handler handler, bool replace = false);
    bool erase(std::string_view name) noexcept;
    script::Value invoke(std::string_view name, std::span<const script::Value> arguments) const;
    bool contains(std::string_view name) const noexcept;
    std::size_t size() const noexcept;

private:
    std::unordered_map<std::string, Handler> handlers_;
};

class WorldMapImage {
public:
    WorldMapImage() = default;
    WorldMapImage(std::uint32_t width, std::uint32_t height, std::uint32_t color = 0xff000000u);
    void resize(std::uint32_t width, std::uint32_t height, std::uint32_t color = 0xff000000u);
    std::uint32_t pixel(std::uint32_t x, std::uint32_t y) const;
    void set_pixel(std::uint32_t x, std::uint32_t y, std::uint32_t color);
    std::vector<std::uint8_t> encode_bmp() const;
    bool decode_bmp(std::span<const std::uint8_t> bytes);
    std::uint32_t width() const noexcept;
    std::uint32_t height() const noexcept;
    std::span<const std::uint32_t> pixels() const noexcept;

private:
    std::size_t index(std::uint32_t x, std::uint32_t y) const;
    std::uint32_t width_{};
    std::uint32_t height_{};
    std::vector<std::uint32_t> pixels_;
};

struct Endpoint {
    std::string host;
    std::uint16_t port{};
};

enum class TransportState : std::uint8_t {
    stopped,
    connecting,
    connected,
    failed
};

class TransportSession {
public:
    explicit TransportSession(std::size_t send_capacity = 80000u, std::size_t receive_capacity = 60000u);
    void begin(Endpoint endpoint, std::uint16_t checksum_seed = 0u);
    void mark_connected() noexcept;
    void fail(std::string reason);
    void close() noexcept;
    bool send(std::uint16_t opcode, std::span<const std::uint8_t> payload);
    bool receive(std::span<const std::uint8_t> bytes);
    std::optional<network::Packet> next_packet();
    std::span<const std::uint8_t> outgoing() const noexcept;
    void consume_outgoing(std::size_t byte_count);
    TransportState state() const noexcept;
    const Endpoint& endpoint() const noexcept;
    const std::string& error() const noexcept;

private:
    Endpoint endpoint_;
    TransportState state_{TransportState::stopped};
    std::string error_;
    std::uint16_t checksum_seed_{};
    network::PacketQueue outgoing_;
    network::PacketStream incoming_;
};

class NetworkManager {
public:
    std::uint32_t create_session(Endpoint endpoint, std::uint16_t checksum_seed = 0u);
    bool remove_session(std::uint32_t identifier) noexcept;
    TransportSession* session(std::uint32_t identifier) noexcept;
    const TransportSession* session(std::uint32_t identifier) const noexcept;
    std::size_t size() const noexcept;
    void close_all() noexcept;

private:
    std::uint32_t next_identifier_{1u};
    std::unordered_map<std::uint32_t, TransportSession> sessions_;
};

} // namespace shared_runtime

namespace world_runtime {

struct PackedQuaternion {
    float w{1.0f};
    float x{};
    float y{};
    float z{};
};

void inverse_transform_point(Vec3* destination, const TransformReference* transform, const Vec3* source);
void inverse_transform_in_place(const TransformReference* transform, Vec3* point);
void quaternion_matrix(const PackedQuaternion* quaternion, Matrix3x3* destination);
Vec3* cross_product(Vec3* destination, const Vec3* left, const Vec3* right);
std::uint32_t contains_substring(const char* text, const char* fragment);
float scaled_effect_time(float time, float scale);
bool snap_near_zero(Vec3* value);
std::int32_t grid_index(std::int32_t layer, std::int32_t row, std::int32_t column);
std::int32_t intersect_plane_segment(const Plane* plane, const Vec3* begin, const Vec3* end, Vec3* intersection);

struct ObjectHandle {
    std::uint32_t index{};
    std::uint32_t generation{};
    constexpr explicit operator bool() const noexcept { return generation != 0u; }
    constexpr auto operator<=>(const ObjectHandle&) const = default;
};

struct AnimationFrame {
    float time{};
    std::vector<character::BonePose> bones;
};

struct AnimationClip {
    std::string name;
    float duration{};
    bool loop{true};
    std::vector<AnimationFrame> frames;
    bool valid() const noexcept;
};

class AnimationLibrary {
public:
    bool store(AnimationClip clip, bool replace = false);
    bool erase(std::string_view name) noexcept;
    const AnimationClip* find(std::string_view name) const noexcept;
    std::vector<character::BonePose> sample(std::string_view name, float time) const;
    std::size_t size() const noexcept;

private:
    std::unordered_map<std::string, AnimationClip> clips_;
};

struct SceneObject {
    ObjectHandle handle;
    std::string name;
    std::string model;
    Vec3 position{};
    character::Quaternion orientation{};
    Vec3 scale{1.0f, 1.0f, 1.0f};
    std::optional<ObjectHandle> parent;
    std::vector<ObjectHandle> children;
    std::string animation;
    float animation_time{};
    float animation_rate{1.0f};
    bool visible{true};
};

class ObjectManager {
public:
    ObjectHandle create(SceneObject object);
    bool destroy(ObjectHandle handle) noexcept;
    SceneObject* find(ObjectHandle handle) noexcept;
    const SceneObject* find(ObjectHandle handle) const noexcept;
    ObjectHandle find(std::string_view name) const noexcept;
    bool link(ObjectHandle child, ObjectHandle parent);
    bool unlink(ObjectHandle child) noexcept;
    bool move(ObjectHandle handle, Vec3 position) noexcept;
    bool rotate(ObjectHandle handle, character::Quaternion orientation) noexcept;
    Matrix3x4 world_transform(ObjectHandle handle) const;
    std::vector<ObjectHandle> handles() const;
    void update_animations(float elapsed_seconds, const AnimationLibrary& animations) noexcept;
    std::size_t size() const noexcept;

private:
    struct Slot {
        std::uint32_t generation{1u};
        std::optional<SceneObject> object;
    };
    bool creates_cycle(ObjectHandle child, ObjectHandle parent) const noexcept;
    std::vector<Slot> slots_;
    std::vector<std::uint32_t> free_slots_;
};

struct Light {
    std::uint64_t identifier{};
    Vec3 position{};
    Vec3 color{1.0f, 1.0f, 1.0f};
    float radius{1.0f};
    float intensity{1.0f};
    bool enabled{true};
};

class LightManager {
public:
    std::uint64_t add(Light light);
    bool remove(std::uint64_t identifier) noexcept;
    Light* find(std::uint64_t identifier) noexcept;
    std::vector<Light> active(Vec3 observer, std::size_t maximum = 8u) const;
    std::size_t size() const noexcept;

private:
    std::uint64_t next_identifier_{1u};
    std::unordered_map<std::uint64_t, Light> lights_;
};

class HeightField {
public:
    bool reset(std::uint32_t width, std::uint32_t height, float cell_size, std::vector<float> heights);
    float height(float x, float z) const noexcept;
    Vec3 normal(float x, float z) const noexcept;
    std::uint32_t width() const noexcept;
    std::uint32_t height_count() const noexcept;

private:
    float sample(std::uint32_t x, std::uint32_t z) const noexcept;
    std::uint32_t width_{};
    std::uint32_t height_{};
    float cell_size_{1.0f};
    std::vector<float> heights_;
};

struct PlantInstance {
    std::string model;
    Vec3 position{};
    float scale{1.0f};
    float rotation{};
};

class PlantingMap {
public:
    bool load(std::string_view text);
    std::vector<PlantInstance> in_radius(Vec3 center, float radius) const;
    const std::vector<PlantInstance>& plants() const noexcept;
    void clear() noexcept;

private:
    std::vector<PlantInstance> plants_;
};

struct WeatherKeyframe {
    float time{};
    Vec3 fog_color{};
    float fog_density{};
    float rain{};
    float wind{};
};

class WeatherTimeline {
public:
    bool set(std::vector<WeatherKeyframe> keyframes, float duration);
    WeatherKeyframe sample(float time) const noexcept;
    float duration() const noexcept;

private:
    std::vector<WeatherKeyframe> keyframes_;
    float duration_{};
};

struct MaterialDefinition {
    std::string name;
    std::string diffuse_texture;
    std::string microtexture;
    Vec3 color{1.0f, 1.0f, 1.0f};
    float opacity{1.0f};
};

struct ModelDefinition {
    std::string name;
    std::filesystem::path file;
    std::vector<MaterialDefinition> materials;
    std::vector<std::string> animations;
    float bounding_radius{};
};

class ModelCatalog {
public:
    bool store(ModelDefinition model, bool replace = false);
    bool erase(std::string_view name) noexcept;
    const ModelDefinition* find(std::string_view name) const noexcept;
    std::vector<std::string> names() const;
    std::size_t size() const noexcept;

private:
    std::unordered_map<std::string, ModelDefinition> models_;
};

struct DrawCommand {
    ObjectHandle object;
    std::string model;
    Matrix3x4 transform;
    float distance_squared{};
    std::string animation;
    float animation_time{};
};

class SceneRenderer {
public:
    std::vector<DrawCommand> build(const ObjectManager& objects, const ModelCatalog& models, Vec3 observer) const;
};

class World {
public:
    void update(float elapsed_seconds) noexcept;
    ObjectManager& objects() noexcept;
    const ObjectManager& objects() const noexcept;
    AnimationLibrary& animations() noexcept;
    LightManager& lights() noexcept;
    HeightField& terrain() noexcept;
    PlantingMap& planting() noexcept;
    WeatherTimeline& weather() noexcept;
    ModelCatalog& models() noexcept;
    float time() const noexcept;

private:
    float time_{};
    ObjectManager objects_;
    AnimationLibrary animations_;
    LightManager lights_;
    HeightField terrain_;
    PlantingMap planting_;
    WeatherTimeline weather_;
    ModelCatalog models_;
};

} // namespace world_runtime

namespace client_runtime {

struct LaunchOptions {
    std::optional<std::string> locale;
    std::optional<std::string> login;
    std::optional<std::string> gamexp_session;
    std::string connect_type;
};

LaunchOptions parse_launch_arguments(std::span<const std::string_view> arguments);
std::unordered_map<std::string, std::string> parse_key_value_config(std::string_view text);

struct ManagedModel {
    std::int32_t identifier{-1};
    std::string name;
    std::filesystem::path file;
};

class ModelManager {
public:
    bool register_folder(std::filesystem::path folder);
    std::int32_t register_model(std::string name, std::filesystem::path file);
    const ManagedModel* by_id(std::int32_t identifier) const noexcept;
    const ManagedModel* by_name(std::string_view name) const noexcept;
    std::size_t size() const noexcept;
    void clear() noexcept;

private:
    std::vector<std::filesystem::path> folders_;
    std::vector<ManagedModel> models_;
    std::unordered_map<std::string, std::int32_t> names_;
};

enum class ConnectionHealth : std::uint8_t { unknown, reachable, unreachable };

struct ConnectionProbe {
    ConnectionHealth health{ConnectionHealth::unknown};
    std::uint32_t sent{};
    std::uint32_t received{};
    std::uint32_t lost{};
    std::optional<std::uint32_t> round_trip_ms;
};

ConnectionProbe parse_ping_report(std::string_view text);

} // namespace client_runtime

namespace content_runtime {

struct MaterialRule {
    std::string word;
    std::string texture;
    float weight{1.0f};
    std::set<std::string> tags;
};

class MaterialFilter {
public:
    void set_rules(std::vector<MaterialRule> rules);
    void set_exceptions(std::set<std::string> exceptions);
    const MaterialRule* match(std::string_view word, std::string_view tag = {}) const noexcept;
    bool excluded(std::string_view word) const noexcept;
    std::size_t size() const noexcept;

private:
    std::vector<MaterialRule> rules_;
    std::set<std::string> exceptions_;
};

enum class ConfigKind : std::uint8_t { null_value, integer, real, boolean, text, array, object };

class ConfigNode {
public:
    ConfigNode() = default;
    explicit ConfigNode(std::int64_t value);
    explicit ConfigNode(double value);
    explicit ConfigNode(bool value);
    explicit ConfigNode(std::string value);
    static ConfigNode array();
    static ConfigNode object();
    ConfigKind kind() const noexcept;
    std::optional<std::int64_t> integer() const noexcept;
    std::optional<double> real() const noexcept;
    std::optional<bool> boolean() const noexcept;
    const std::string* text() const noexcept;
    const std::vector<ConfigNode>* array_items() const noexcept;
    std::vector<ConfigNode>* array_items() noexcept;
    const std::map<std::string, ConfigNode>* object_items() const noexcept;
    std::map<std::string, ConfigNode>* object_items() noexcept;
    const ConfigNode* find(std::string_view key) const noexcept;
    const ConfigNode* at(std::size_t index) const noexcept;

private:
    ConfigKind kind_{ConfigKind::null_value};
    std::int64_t integer_{};
    double real_{};
    bool boolean_{};
    std::string text_;
    std::vector<ConfigNode> array_;
    std::map<std::string, ConfigNode> object_;
};

class ObjectConfig {
public:
    bool parse(std::string_view text, std::string* error = nullptr);
    const ConfigNode& root() const noexcept;
    const ConfigNode* find(std::string_view dotted_path) const noexcept;
    void clear() noexcept;

private:
    ConfigNode root_{ConfigNode::object()};
};

enum class Interpolation : std::uint8_t { linear, cosine };
enum class EmitterShape : std::uint8_t { line, disk, ring, box, cylinder, sphere, disk2 };

struct ScalarKey {
    float time{};
    float value{};
};

class ScalarCurve {
public:
    bool set(std::vector<ScalarKey> keys, Interpolation interpolation = Interpolation::linear);
    float sample(float time) const noexcept;
    const std::vector<ScalarKey>& keys() const noexcept;

private:
    std::vector<ScalarKey> keys_;
    Interpolation interpolation_{Interpolation::linear};
};

struct ColorKey {
    float time{};
    std::array<float, 4> value{};
};

class ColorCurve {
public:
    bool set(std::vector<ColorKey> keys, Interpolation interpolation = Interpolation::linear);
    std::array<float, 4> sample(float time) const noexcept;

private:
    std::vector<ColorKey> keys_;
    Interpolation interpolation_{Interpolation::linear};
};

struct EffectMeshDefinition {
    std::string name;
    std::string mesh;
    std::string texture;
    std::uint32_t flags{};
    bool self_illumination{};
    std::array<std::uint8_t, 4> color{255u, 255u, 255u, 255u};
};

struct ParticleSystemDefinition {
    std::string name;
    std::uint32_t particle_count{};
    std::uint32_t flags{};
    EmitterShape emitter{EmitterShape::line};
    std::array<Vec3, 3> transform{};
    ScalarCurve size;
    ScalarCurve rotation;
    ColorCurve color;
    std::optional<EffectMeshDefinition> effect_mesh;
};

class ParticleLibrary {
public:
    bool store(ParticleSystemDefinition definition, bool replace = false);
    const ParticleSystemDefinition* find(std::string_view name) const noexcept;
    bool erase(std::string_view name) noexcept;
    std::size_t size() const noexcept;

private:
    std::unordered_map<std::string, ParticleSystemDefinition> systems_;
};

struct Rect2 {
    float left{};
    float top{};
    float right{};
    float bottom{};
};

struct SpatialRecord {
    std::uint32_t identifier{};
    Rect2 bounds{};
};

class QuadTree {
public:
    explicit QuadTree(Rect2 bounds = {}, std::size_t bucket_capacity = 8u, std::size_t maximum_depth = 8u);
    bool insert(SpatialRecord record);
    std::vector<std::uint32_t> query(Rect2 bounds) const;
    void clear();
    std::size_t size() const noexcept;

private:
    struct Node {
        Rect2 bounds{};
        std::vector<SpatialRecord> records;
        std::array<std::unique_ptr<Node>, 4> children{};
    };
    bool insert(Node& node, SpatialRecord record, std::size_t depth);
    void query(const Node& node, Rect2 bounds, std::vector<std::uint32_t>& result) const;
    void split(Node& node);
    Rect2 bounds_{};
    std::size_t bucket_capacity_{8u};
    std::size_t maximum_depth_{8u};
    std::size_t size_{};
    std::unique_ptr<Node> root_;
};

class QuickFileArchive {
public:
    bool add(std::string name, std::vector<std::uint8_t> bytes, bool replace = false);
    std::span<const std::uint8_t> find(std::string_view name) const noexcept;
    bool erase(std::string_view name) noexcept;
    std::vector<std::string> names() const;
    void clear() noexcept;

private:
    std::unordered_map<std::string, std::vector<std::uint8_t>> files_;
};

struct WallSegment {
    Vec3 begin{};
    Vec3 end{};
    std::uint32_t flags{};
};

class ServerWall {
public:
    void set_segments(std::vector<WallSegment> segments);
    std::optional<Vec3> first_intersection(Vec3 begin, Vec3 end) const noexcept;
    bool blocked(Vec3 begin, Vec3 end) const noexcept;
    std::size_t size() const noexcept;

private:
    std::vector<WallSegment> segments_;
};

struct ShadowSettings {
    bool enabled{true};
    bool spot_shadows{true};
    std::uint32_t quality{1u};
    float maximum_distance{100.0f};
};

struct GeneratedMap {
    std::uint32_t width{};
    std::uint32_t height{};
    std::vector<float> heights;
};

class MapGenerator {
public:
    GeneratedMap generate(std::uint32_t width, std::uint32_t height, std::uint32_t seed, float amplitude) const;
};

struct NatureState {
    float rain{};
    float wind{};
    std::uint32_t rain_class{};
};

class NatureManager {
public:
    void register_rain_class(std::uint32_t class_id, std::string name);
    const std::string* rain_class(std::uint32_t class_id) const noexcept;
    void set_state(NatureState state) noexcept;
    NatureState state() const noexcept;

private:
    std::unordered_map<std::uint32_t, std::string> rain_classes_;
    NatureState state_{};
};

struct ZoneParameters {
    std::int32_t x_patch_min{};
    std::int32_t z_patch_min{};
    float x_min{};
    float z_min{};
    float x_max{};
    float z_max{};
    std::uint32_t identifier{};
};

class ZoningManager {
public:
    bool set_zones(std::vector<ZoneParameters> zones);
    const ZoneParameters* zone_at(float x, float z) const noexcept;
    std::optional<std::uint32_t> patch_owner(std::int32_t x_patch, std::int32_t z_patch) const noexcept;
    std::size_t size() const noexcept;

private:
    std::vector<ZoneParameters> zones_;
};

class TextureSet {
public:
    bool set(std::string name, std::filesystem::path file, bool replace = true);
    const std::filesystem::path* find(std::string_view name) const noexcept;
    bool erase(std::string_view name) noexcept;
    std::size_t size() const noexcept;

private:
    std::unordered_map<std::string, std::filesystem::path> textures_;
};

struct UpdateEntry {
    std::filesystem::path file;
    std::uint64_t size{};
    std::uint32_t checksum{};
};

class UpdatePlan {
public:
    void set_local(std::vector<UpdateEntry> entries);
    void set_remote(std::vector<UpdateEntry> entries);
    std::vector<UpdateEntry> required() const;

private:
    std::unordered_map<std::string, UpdateEntry> local_;
    std::unordered_map<std::string, UpdateEntry> remote_;
};

} // namespace content_runtime

namespace markup_runtime {

struct LinkTarget {
    std::string scheme;
    std::string value;
};

struct TextRun {
    std::string text;
    std::optional<LinkTarget> link;
    bool bold{};
    bool italic{};
};

class HyperTextDocument {
public:
    bool parse(std::string_view text);
    const std::vector<TextRun>& runs() const noexcept;
    std::string plain_text() const;
    void clear() noexcept;

private:
    std::vector<TextRun> runs_;
};

class TokenStream {
public:
    explicit TokenStream(std::string_view text = {});
    void reset(std::string_view text);
    std::optional<std::string> next();
    std::size_t line() const noexcept;

private:
    std::string text_;
    std::size_t offset_{};
    std::size_t line_{1u};
};

bool parse_boolean(std::string_view token, bool& value) noexcept;

} // namespace markup_runtime

namespace sky_runtime {

struct SkyState {
    float time{};
    Vec3 color{};
    float fog{};
    float sun_intensity{1.0f};
};

class SkyTimeline {
public:
    bool set_states(std::vector<SkyState> states, float day_length = 24.0f);
    SkyState sample(float time) const noexcept;
    std::size_t size() const noexcept;

private:
    std::vector<SkyState> states_;
    float day_length_{24.0f};
};

} // namespace sky_runtime

namespace legacy_sound {

enum SoundFlags : std::uint32_t {
    play_random = 1u << 0u,
    play_random_mix = 1u << 1u,
    play_looped = 1u << 2u,
    type_environment = 1u << 3u,
    play_use_region = 1u << 4u
};

struct SoundSource {
    std::string file;
    float volume{1.0f};
    float probability{1.0f};
};

struct SoundEffect {
    std::string name;
    std::uint32_t flags{};
    std::vector<SoundSource> sources;
    float silence{};
};

class SoundLibrary {
public:
    bool store(SoundEffect effect, bool replace = false);
    const SoundEffect* find(std::string_view name) const noexcept;
    bool erase(std::string_view name) noexcept;
    std::size_t size() const noexcept;

private:
    std::unordered_map<std::string, SoundEffect> effects_;
};

class SoundTrack {
public:
    void set_playlist(std::vector<std::string> files, bool loop);
    const std::string* current() const noexcept;
    const std::string* advance() noexcept;
    void reset() noexcept;

private:
    std::vector<std::string> files_;
    std::size_t index_{};
    bool loop_{};
};

} // namespace legacy_sound

namespace ui_runtime {

struct Point {
    std::int32_t x{};
    std::int32_t y{};
};

struct Rect {
    std::int32_t left{};
    std::int32_t top{};
    std::int32_t right{};
    std::int32_t bottom{};
    std::int32_t width() const noexcept { return right - left; }
    std::int32_t height() const noexcept { return bottom - top; }
    bool contains(Point point) const noexcept { return point.x >= left && point.x < right && point.y >= top && point.y < bottom; }
};

struct Color {
    std::uint8_t red{255u};
    std::uint8_t green{255u};
    std::uint8_t blue{255u};
    std::uint8_t alpha{255u};
};

enum class ControlKind : std::uint8_t { generic, button, checkbox, edit, image, list, menu_list, progress, radio_button, rich_edit, scrollbar, slider, slot, spin, hypertext, minimap };

class PropertyBag {
public:
    bool parse(std::string_view text);
    void set(std::string key, std::string value);
    const std::string* get(std::string_view key) const noexcept;
    std::optional<std::int32_t> integer(std::string_view key) const noexcept;
    std::optional<float> real(std::string_view key) const noexcept;
    std::optional<bool> boolean(std::string_view key) const noexcept;
    std::optional<Rect> rectangle(std::string_view key) const noexcept;
    std::optional<Color> color(std::string_view key) const noexcept;

private:
    std::unordered_map<std::string, std::string> values_;
};

struct SpriteDefinition {
    std::string name;
    Point size{};
    std::vector<std::filesystem::path> textures;
    Color tint{};
};

struct FontDefinition {
    std::string name;
    std::filesystem::path texture;
    std::uint32_t glyph_count{};
    std::int32_t line_height{};
};

struct Control {
    std::uint32_t identifier{};
    std::string name;
    ControlKind kind{ControlKind::generic};
    Rect bounds{};
    bool visible{true};
    bool enabled{true};
    std::optional<std::uint32_t> parent;
    std::vector<std::uint32_t> children;
    PropertyBag properties;
};

class InterfaceModel {
public:
    bool add_sprite(SpriteDefinition sprite, bool replace = false);
    bool add_font(FontDefinition font, bool replace = false);
    bool create(Control control);
    bool destroy(std::uint32_t identifier);
    Control* find(std::uint32_t identifier) noexcept;
    const Control* find(std::uint32_t identifier) const noexcept;
    const SpriteDefinition* sprite(std::string_view name) const noexcept;
    const FontDefinition* font(std::string_view name) const noexcept;
    bool attach(std::uint32_t parent, std::uint32_t child);
    std::vector<std::uint32_t> hit_test(Point point) const;
    std::size_t control_count() const noexcept;

private:
    std::unordered_map<std::uint32_t, Control> controls_;
    std::unordered_map<std::string, SpriteDefinition> sprites_;
    std::unordered_map<std::string, FontDefinition> fonts_;
};

class TextBuffer {
public:
    void configure(std::size_t maximum_symbols, bool numeric, bool password);
    bool set(std::string text);
    bool insert(std::size_t position, std::string_view text);
    bool erase(std::size_t position, std::size_t count);
    const std::string& text() const noexcept;
    std::string display_text() const;
    std::size_t maximum_symbols() const noexcept;

private:
    std::size_t maximum_symbols_{1024u};
    bool numeric_{};
    bool password_{};
    std::string text_;
};

class ScrollModel {
public:
    void set_range(std::int32_t minimum, std::int32_t maximum);
    void set_page(std::int32_t page) noexcept;
    void set_step(std::int32_t step) noexcept;
    void set_position(std::int32_t position) noexcept;
    std::int32_t position() const noexcept;
    std::int32_t minimum() const noexcept;
    std::int32_t maximum() const noexcept;
    std::int32_t page() const noexcept;
    void line(std::int32_t direction) noexcept;
    void page_move(std::int32_t direction) noexcept;

private:
    std::int32_t minimum_{};
    std::int32_t maximum_{};
    std::int32_t page_{1};
    std::int32_t step_{1};
    std::int32_t position_{};
};

class ListModel {
public:
    void set_items(std::vector<std::string> items);
    bool select(std::size_t index) noexcept;
    std::optional<std::size_t> selection() const noexcept;
    const std::vector<std::string>& items() const noexcept;
    void clear() noexcept;

private:
    std::vector<std::string> items_;
    std::optional<std::size_t> selection_;
};

struct ProgressModel {
    std::int32_t minimum{};
    std::int32_t maximum{100};
    std::int32_t value{};
    float fraction() const noexcept;
    std::string label(bool percent) const;
};

struct SlotModel {
    std::optional<std::uint32_t> item;
    std::string full_sprite;
    std::string empty_sprite;
    std::string border_sprite;
};

struct VideoMode {
    std::uint32_t width{};
    std::uint32_t height{};
    std::uint32_t refresh_rate{};
    std::uint32_t format{};
    auto operator<=>(const VideoMode&) const = default;
};

class OptionsModel {
public:
    void set_video_modes(std::vector<VideoMode> modes);
    const std::vector<VideoMode>& video_modes() const noexcept;
    bool choose_video_mode(VideoMode mode) noexcept;
    std::optional<VideoMode> video_mode() const noexcept;
    void set(std::string key, std::string value);
    const std::string* get(std::string_view key) const noexcept;

private:
    std::vector<VideoMode> video_modes_;
    std::optional<VideoMode> selected_mode_;
    std::unordered_map<std::string, std::string> values_;
};

} // namespace ui_runtime

namespace compiler_runtime {

void* copy_memory(void* destination, const void* source, std::uint32_t size);
void* fill_memory(void* destination, std::int32_t value, std::uint32_t size);
std::int64_t signed_divide(std::int64_t dividend, std::int64_t divisor);
std::int64_t signed_remainder(std::int64_t dividend, std::int64_t divisor);
std::uint64_t unsigned_divide(std::uint64_t dividend, std::uint64_t divisor);
std::uint64_t multiply(std::uint64_t left, std::uint64_t right);

} // namespace compiler_runtime

struct BoxCorners {
    std::array<Vec3, 8> vertices;
};

struct BitSlice {
    std::uint8_t* bytes;
    std::uint32_t* bit_position;
    std::uint32_t byte_count;
};

struct ByteView {
    std::uint32_t size;
    const std::uint8_t* data;
};

struct ConfigurationStorage {
    char** active_text;
    std::uint32_t* active_length;
    char* owned_text;
    std::size_t owned_capacity;
};

using DiagnosticSink = void (*)(std::string_view message);
using MemoryCopyService = void* (*)(void* destination, const void* source, std::uint32_t size);

enum class NativeCallingConvention : std::uint8_t {
    automatic,
    cdecl_call,
    stdcall_call,
    thiscall_call,
    fastcall_call
};

enum class NativeValueKind : std::uint8_t {
    none,
    word,
    floating
};

enum class NativeParameterStorage : std::uint8_t {
    stack,
    ecx,
    edx
};

struct NativeArgument {
    std::uint64_t word;
    long double floating;
    NativeValueKind kind;
    std::uint8_t width;
};

struct NativeResult {
    std::uint64_t word;
    long double floating;
    NativeValueKind kind;
    std::uint8_t width;
};

struct NativeParameter {
    NativeValueKind kind;
    NativeParameterStorage storage;
    std::uint16_t stack_offset;
    std::uint8_t width;
};

struct NativeCall {
    std::uint32_t target;
    std::uint32_t source_va;
    std::uint32_t callsite;
    NativeCallingConvention convention;
    const NativeArgument* arguments;
    std::size_t argument_count;
    NativeValueKind expected_result;
};

using LegacyCallInvoker = NativeResult (*)(void* bridge_context, const NativeCall& call);
using NativeEntryInvoker = NativeResult (*)(const NativeArgument* arguments, std::size_t argument_count);

struct NativeEntry {
    std::uint32_t source_va;
    NativeCallingConvention convention;
    const NativeParameter* parameters;
    std::uint16_t parameter_count;
    std::uint16_t stack_bytes;
    NativeValueKind result_kind;
    NativeEntryInvoker invoke;
    const char* name;
    std::uint32_t source_lines;
};

struct RuntimeServices {
    ConfigurationStorage configuration;
    DiagnosticSink diagnostic;
    std::uint32_t image_base;
    LegacyCallInvoker invoke_legacy;
    MemoryCopyService copy_memory;
};

void attach_runtime(RuntimeServices services) noexcept;
char* filename_component(char* path);
BoxCorners* build_box_corners(BoxCorners* destination, const Vec3* minimum, const Vec3* maximum);
BitSlice* construct_bit_slice(BitSlice* destination, std::uint8_t* bytes, std::uint32_t* bit_position, std::uint32_t byte_count);
void copy_bits(std::uint8_t* destination, std::uint32_t* destination_bit, const std::uint8_t* source, std::uint32_t* source_bit, std::int32_t bit_count, std::int32_t destination_bytes);
bool token_equals(const char* expected, const char* token_begin, const char* token_end);
void copy_c_string(char* destination, const char* source);
std::uint32_t install_config_text(char* status, const char* text, std::uint32_t length);
std::uint32_t config_text_length();
const char* find_config_value(const char* key);
bool write_binary_file(const char* path, const void* data, std::uint32_t size);
void reset_config_text(char* status, const char* status_value);
void attach_config_text(char* status, char* text);
bool read_config_int(const char* key, std::int32_t* value);
bool read_config_float(const char* key, float* value);
bool read_config_string(const char* key, char* destination, std::uint32_t capacity);
bool read_config_bits(const char* key, std::uint8_t* destination, std::int32_t destination_bytes);
std::uint32_t copy_config_text(void* destination, std::uint32_t capacity);
std::int32_t compare_bytes(const void* left, const void* right, std::uint32_t size);
bool equal_byte_views(const ByteView* left, const ByteView* right);
std::string decimal_string(std::uint32_t value);
namespace zlib113 {
int compress(std::uint8_t* destination, std::uint32_t* destination_size, const std::uint8_t* source, std::uint32_t source_size, int level);
int decompress(std::uint8_t* destination, std::uint32_t* destination_size, const std::uint8_t* source, std::uint32_t source_size);
}
namespace directx {
const char* error_description(std::int32_t result);
}
const NativeEntry* find_native_entry(std::uint32_t source_va) noexcept;
NativeCallingConvention native_abi_hint(std::uint32_t source_va) noexcept;
NativeResult invoke_native_entry(const NativeEntry& entry, const NativeArgument* arguments, std::size_t argument_count, void* bridge_context);
std::size_t native_entry_count() noexcept;
std::uint64_t native_source_line_coverage() noexcept;

} // namespace sfera::semantic
