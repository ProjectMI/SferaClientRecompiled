#include "semantic_native.h"

#include <array>
#include <bit>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>

namespace semantic = sfera::semantic;

namespace {

bool near(float left, float right) {
    return std::fabs(left - right) < 0.0001f;
}

std::size_t bitstream_diagnostic_count = 0u;
std::string bitstream_last_diagnostic;

void capture_bitstream_diagnostic(std::string_view message) {
    ++bitstream_diagnostic_count;
    bitstream_last_diagnostic.assign(message);
}

semantic::NativeArgument pointer_argument(const void* pointer) {
    return {reinterpret_cast<std::uintptr_t>(pointer), 0.0L, semantic::NativeValueKind::word, 4u};
}

semantic::NativeArgument integer_argument(std::uint64_t value, std::uint8_t width) {
    return {value, 0.0L, semantic::NativeValueKind::word, width};
}

semantic::Matrix3x4 identity_transform() {
    return {{{1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f}}};
}

void test_bitstream_contract() {
    semantic::attach_runtime({{}, &capture_bitstream_diagnostic, 0u, nullptr, nullptr});
    std::array<std::uint8_t, 96> source{};
    for (std::size_t index = 0; index < source.size(); ++index) { source[index] = static_cast<std::uint8_t>((index * 37u + 11u) & 0xffu); }
    std::array<std::uint8_t, 8> destination{};
    std::uint32_t source_bit = 29u;
    std::uint32_t destination_bit = 0u;
    bitstream_diagnostic_count = 0u;
    bitstream_last_diagnostic.clear();
    semantic::copy_bits(destination.data(), &destination_bit, source.data(), &source_bit, 8, 4);
    std::uint8_t expected = 0u;
    for (std::uint32_t index = 0; index < 8u; ++index) { expected |= static_cast<std::uint8_t>(((source[(29u + index) >> 3u] >> ((29u + index) & 7u)) & 1u) << index); }
    assert(destination[0] == expected && source_bit == 37u && destination_bit == 8u);
    assert(bitstream_diagnostic_count == 0u);
    source_bit = 0u;
    destination_bit = 29u;
    semantic::copy_bits(destination.data(), &destination_bit, source.data(), &source_bit, 8, 4);
    assert(bitstream_diagnostic_count == 1u);
    assert(bitstream_last_diagnostic.find("position=29, count=8, size=4") != std::string::npos);
}

void test_geometry_and_binding() {
    assert(semantic::native_entry_count() == 98u);
    assert(semantic::native_source_line_coverage() == 18055u);
    semantic::Matrix3x4 transform{{{2.0f, 0.0f, 0.0f, 10.0f, 0.0f, 3.0f, 0.0f, 20.0f, 0.0f, 0.0f, 4.0f, 30.0f}}};
    semantic::Vec3 source{1.0f, 2.0f, 3.0f};
    semantic::Vec3 destination{};
    semantic::transform_point(&destination, &transform, &source);
    assert(near(destination.x, 12.0f) && near(destination.y, 26.0f) && near(destination.z, 42.0f));
    assert(semantic::is_model_file("actors/hero.MDL") == 1u);
    assert(semantic::is_model_file("hero.md2") == 0u);

    const semantic::NativeEntry* transform_entry = semantic::find_native_entry(0x00419F70u);
    assert(transform_entry && transform_entry->convention == semantic::NativeCallingConvention::fastcall_call);
    assert(transform_entry->parameter_count == 3u && transform_entry->stack_bytes == 4u);
    assert(transform_entry->parameters[0].storage == semantic::NativeParameterStorage::ecx);
    assert(transform_entry->parameters[1].storage == semantic::NativeParameterStorage::edx);
    assert(transform_entry->parameters[2].storage == semantic::NativeParameterStorage::stack);
    semantic::Vec3 bridged{};
    const std::array transform_arguments{pointer_argument(&bridged), pointer_argument(&transform), pointer_argument(&source)};
    const semantic::NativeResult transform_result = semantic::invoke_native_entry(*transform_entry, transform_arguments.data(), transform_arguments.size(), nullptr);
    assert(transform_result.kind == semantic::NativeValueKind::none);
    assert(near(bridged.x, 12.0f) && near(bridged.y, 26.0f) && near(bridged.z, 42.0f));

    const semantic::NativeEntry* model_entry = semantic::find_native_entry(0x0041E350u);
    assert(model_entry && model_entry->convention == semantic::NativeCallingConvention::stdcall_call && model_entry->stack_bytes == 4u);
    const char model_name[] = "sample.mdl";
    const semantic::NativeArgument model_argument = pointer_argument(model_name);
    assert(semantic::invoke_native_entry(*model_entry, &model_argument, 1u, nullptr).word == 1u);
}

void test_scripted_effects_audio_and_logs() {
    using namespace semantic::effect_runtime;
    EffectLibrary effects;
    ScriptedEffectDefinition definition{"storm", 2.0f, {{PartKind::sound, "thunder", {0.0f, 1.0f}, AttachmentPoint::world, {}, 1.0f}, {PartKind::light, "flash", {0.5f, 2.0f}, AttachmentPoint::between_hands, {1.0f, 2.0f, 3.0f}, 2.0f}}};
    assert(effects.store(std::move(definition)) && effects.size() == 1u);
    EffectScheduler scheduler(effects);
    const auto effect = scheduler.spawn("STORM", {10.0f, 20.0f, 30.0f});
    assert(effect && scheduler.active_parts().size() == 1u);
    scheduler.update(0.75f);
    const auto active = scheduler.active_parts();
    assert(active.size() == 2u && near(active.back().position.x, 11.0f));
    assert(scheduler.move(*effect, {0.0f, 0.0f, 0.0f}));
    scheduler.update(1.3f);
    assert(scheduler.size() == 0u);

    BladeTrail trail(0.5f, 2u);
    trail.append({1.0f, 0.0f, 0.0f});
    trail.append({2.0f, 0.0f, 0.0f});
    trail.append({3.0f, 0.0f, 0.0f});
    assert(trail.points().size() == 2u && near(trail.points().front().position.x, 2.0f));
    trail.update(0.6f);
    assert(trail.points().empty());
    RainField rain({0.0f, 0.0f, 0.0f}, {10.0f, 10.0f, 10.0f}, 4.0f, 5.0f, 7u);
    rain.update(0.5f);
    assert(rain.drops().size() == 2u);

    semantic::audio_runtime::SoundLibrary sounds;
    assert(sounds.store({"thunder", "sounds/thunder.wav", 0.8f, 1.0f, 1.0f, 1.0f, 100.0f, false, "effects"}));
    assert(sounds.store({"storm cue", {{0.0f, "thunder"}, {0.5f, "thunder"}}}));
    semantic::audio_runtime::Mixer mixer(sounds);
    mixer.set_master_gain(0.5f);
    mixer.set_group_gain("effects", 0.25f);
    assert(mixer.play_cue("storm cue").size() == 2u);
    assert(mixer.voices().size() == 2u && near(mixer.voices().front().effective_gain, 0.1f));
    mixer.update(0.75f);
    assert(mixer.active_voice_count() == 2u);
    mixer.update(1.0f);
    assert(mixer.active_voice_count() == 0u);

    auto memory = std::make_shared<semantic::log_runtime::MemorySink>();
    semantic::log_runtime::Registry logs;
    logs.attach_to_all(memory);
    const auto logger = logs.logger("script");
    logger->write(semantic::log_runtime::Severity::information, "module loaded");
    assert(logs.size() == 1u && memory->records().size() == 1u);
    assert(semantic::log_runtime::format(memory->records().front()).find("module loaded") != std::string::npos);
}

void test_shared_runtime() {
    using namespace semantic::shared_runtime;
    assert(hash_key("Models/Hero.MDL") == hash_key("models/hero.mdl"));
    assert(wildcard_match("actors/hero.mdl", "actors/*.m?l") == 1u);
    assert(wildcard_match("actors/hero.mdl", "effects/*") == 0u);
    assert(is_transport_mode(4) == 1u && is_transport_mode(5) == 1u && is_transport_mode(3) == 0u);
    assert(interop_storage_class(0u) == 1u && interop_storage_class(1u) == 12u && interop_storage_class(0x10u) == 4u);
    assert(wrapped_heading_delta(0x4000, 0) == -0x4000 && wrapped_heading_delta(0, 0x4000) == 0x4000);

    StringIndex index(16u);
    const auto hero = index.insert("Hero");
    assert(hero && index.find("HERO") == hero && index.key(*hero) == std::optional<std::string>("hero"));
    assert(!index.insert("hero") && index.insert("hero", true) == hero);
    assert(index.erase("HeRo") && index.size() == 0u);

    ItemList items;
    assert(items.add({1u, "Potion", "consumable", 2, {}}));
    assert(items.add({2u, "Sword", "weapon", 1, {}}));
    assert(items.add({3u, "potion", "consumable", 5, {{"quality", semantic::script::Value(3)}}}, InsertMode::merge_quantity));
    assert(items.size() == 2u && items.total_quantity() == 8);
    assert(items.find("POTION") && items.find("potion")->quantity == 7);
    assert(items.first() && items.next(items.first()->name));

    ServerDirectory servers;
    assert(servers.update({2u, "Busy", "127.0.0.2", 2593u, 200u, true}));
    assert(servers.update({1u, "Quiet", "127.0.0.1", 2593u, 20u, true}));
    assert(servers.update({3u, "Offline", "127.0.0.3", 2593u, 0u, false}));
    const auto online = servers.online_servers();
    assert(online.size() == 2u && online.front().identifier == 1u && servers.find("busy")->identifier == 2u);

    BytecodeModule module;
    assert(module.load("Inter", {0u, 1u, 2u, 3u, 4u, 5u}, {{10u, 0u, 2u}, {20u, 2u, 4u}}));
    assert(module.array(20u).size() == 4u && module.array(20u).front() == 2u);
    BytecodeModule invalid;
    assert(!invalid.load("bad", {0u, 1u, 2u}, {{1u, 0u, 2u}, {2u, 1u, 2u}}));
    ModuleRegistry modules;
    assert(modules.store(std::move(module)) && modules.find("INTER") && modules.names().front() == "Inter");

    CommandRegistry commands;
    assert(commands.register_handler("sum", [](std::span<const semantic::script::Value> arguments) {
        std::int64_t result = 0;
        for (const auto& argument : arguments) { result += argument.integer(); }
        return semantic::script::Value(static_cast<std::int32_t>(result));
    }));
    const std::array command_arguments{semantic::script::Value(19), semantic::script::Value(23)};
    assert(commands.invoke("SUM", command_arguments).integer() == 42);

    WorldMapImage image(2u, 2u);
    image.set_pixel(0u, 0u, 0xff112233u);
    image.set_pixel(1u, 0u, 0xff445566u);
    image.set_pixel(0u, 1u, 0xff778899u);
    image.set_pixel(1u, 1u, 0xffaabbccu);
    const std::vector<std::uint8_t> bitmap = image.encode_bmp();
    WorldMapImage decoded;
    assert(decoded.decode_bmp(bitmap) && decoded.width() == 2u && decoded.height() == 2u);
    assert(std::equal(decoded.pixels().begin(), decoded.pixels().end(), image.pixels().begin()));

    const std::array<std::uint8_t, 4> payload{9u, 8u, 7u, 6u};
    TransportSession transport;
    transport.begin({"127.0.0.1", 2593u}, 0x4321u);
    transport.mark_connected();
    assert(transport.send(0x1001u, payload));
    const std::vector<std::uint8_t> packet_bytes(transport.outgoing().begin(), transport.outgoing().end());
    assert(transport.receive(packet_bytes));
    const auto packet = transport.next_packet();
    assert(packet && packet->header.opcode == 0x1001u && packet->payload == std::vector<std::uint8_t>(payload.begin(), payload.end()));
    transport.consume_outgoing(packet_bytes.size());
    assert(transport.outgoing().empty());

    NetworkManager network;
    const std::uint32_t session_id = network.create_session({"game.example", 2593u}, 7u);
    assert(network.session(session_id) && network.session(session_id)->state() == TransportState::connecting);
    network.close_all();
    assert(network.session(session_id)->state() == TransportState::stopped);
}

void test_world_math_and_bindings() {
    using namespace semantic::world_runtime;
    semantic::Matrix3x4 matrix = identity_transform();
    matrix.values[3] = 1.0f;
    matrix.values[7] = 2.0f;
    matrix.values[11] = 3.0f;
    const semantic::TransformReference transform{&matrix};
    const semantic::Vec3 source{6.0f, 8.0f, 10.0f};
    semantic::Vec3 destination{};
    inverse_transform_point(&destination, &transform, &source);
    assert(near(destination.x, 5.0f) && near(destination.y, 6.0f) && near(destination.z, 7.0f));

    const PackedQuaternion identity{};
    semantic::Matrix3x3 rotation{};
    quaternion_matrix(&identity, &rotation);
    assert(near(rotation.values[0], 1.0f) && near(rotation.values[4], 1.0f) && near(rotation.values[8], 1.0f));
    const semantic::Vec3 horizontal{1.0f, 0.0f, 0.0f};
    const semantic::Vec3 vertical{0.0f, 1.0f, 0.0f};
    semantic::Vec3 cross{};
    assert(cross_product(&cross, &horizontal, &vertical) == &cross);
    assert(near(cross.x, 0.0f) && near(cross.y, 0.0f) && near(cross.z, 1.0f));
    assert(contains_substring("effects/fire.sef", "fire") == 1u && contains_substring("effects/fire.sef", "rain") == 0u);
    assert(near(scaled_effect_time(0.2f, 2.0f), 1.0f) && near(scaled_effect_time(1.0f, 2.0f), 2.0f));
    const semantic::NativeEntry* scaled_time_entry = semantic::find_native_entry(0x0044E400u);
    assert(scaled_time_entry && scaled_time_entry->convention == semantic::NativeCallingConvention::stdcall_call && scaled_time_entry->stack_bytes == 8u);
    semantic::Vec3 tiny{0.00001f, -0.00001f, 0.0f};
    assert(snap_near_zero(&tiny) && tiny.x == 0.0f && tiny.y == 0.0f);
    assert(grid_index(1, 1, 1) == 7);
    const semantic::Plane plane{{0.0f, 1.0f, 0.0f}, 0.0f};
    const semantic::Vec3 above{0.0f, 1.0f, 0.0f};
    const semantic::Vec3 below{0.0f, -1.0f, 0.0f};
    semantic::Vec3 intersection{};
    assert(intersect_plane_segment(&plane, &above, &below, &intersection) == 1 && near(intersection.y, 0.0f));
    const semantic::NativeEntry* intersect_entry = semantic::find_native_entry(0x00451A40u);
    assert(intersect_entry && intersect_entry->convention == semantic::NativeCallingConvention::stdcall_call && intersect_entry->stack_bytes == 16u);

    const semantic::NativeEntry* wildcard_entry = semantic::find_native_entry(0x00434080u);
    assert(wildcard_entry && wildcard_entry->convention == semantic::NativeCallingConvention::fastcall_call && wildcard_entry->parameter_count == 2u);
    const char text[] = "models/hero.mdl";
    const char pattern[] = "models/*.mdl";
    const std::array wildcard_arguments{pointer_argument(text), pointer_argument(pattern)};
    assert(semantic::invoke_native_entry(*wildcard_entry, wildcard_arguments.data(), wildcard_arguments.size(), nullptr).word == 1u);

    const semantic::NativeEntry* cross_entry = semantic::find_native_entry(0x0044C1D0u);
    assert(cross_entry && cross_entry->convention == semantic::NativeCallingConvention::fastcall_call && cross_entry->parameter_count == 3u && cross_entry->stack_bytes == 4u && cross_entry->result_kind == semantic::NativeValueKind::word);
    semantic::Vec3 bridged_cross{};
    const std::array cross_arguments{pointer_argument(&bridged_cross), pointer_argument(&horizontal), pointer_argument(&vertical)};
    const semantic::NativeResult cross_result = semantic::invoke_native_entry(*cross_entry, cross_arguments.data(), cross_arguments.size(), nullptr);
    assert(cross_result.kind == semantic::NativeValueKind::word && cross_result.width == 4u && cross_result.word == reinterpret_cast<std::uintptr_t>(&bridged_cross));
    assert(near(bridged_cross.z, 1.0f));
}

void test_world_runtime() {
    using namespace semantic::world_runtime;
    const semantic::character::BonePose first{{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}};
    const semantic::character::BonePose last{{10.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}};
    AnimationLibrary animations;
    assert(animations.store({"walk", 1.0f, true, {{0.0f, {first}}, {1.0f, {last}}}}));
    const auto sampled = animations.sample("WALK", 0.5f);
    assert(sampled.size() == 1u && near(sampled.front().translation.x, 5.0f));

    ModelCatalog models;
    assert(models.store({"hero", "models/hero.mdl", {}, {"walk"}, 2.0f}));
    ObjectManager objects;
    SceneObject root;
    root.name = "root";
    root.model = "hero";
    root.position = {1.0f, 0.0f, 0.0f};
    root.animation = "walk";
    const ObjectHandle root_handle = objects.create(std::move(root));
    SceneObject child;
    child.name = "child";
    child.model = "hero";
    child.position = {2.0f, 0.0f, 0.0f};
    const ObjectHandle child_handle = objects.create(std::move(child));
    assert(objects.link(child_handle, root_handle) && !objects.link(root_handle, child_handle));
    const semantic::Matrix3x4 child_transform = objects.world_transform(child_handle);
    assert(near(child_transform.values[3], 3.0f));
    objects.update_animations(0.5f, animations);
    assert(near(objects.find(root_handle)->animation_time, 0.5f));

    SceneRenderer renderer;
    const auto commands = renderer.build(objects, models, {});
    assert(commands.size() == 2u && commands.front().distance_squared <= commands.back().distance_squared);

    LightManager lights;
    const std::uint64_t close_light = lights.add({0u, {1.0f, 0.0f, 0.0f}, {}, 5.0f, 1.0f, true});
    lights.add({0u, {20.0f, 0.0f, 0.0f}, {}, 2.0f, 1.0f, true});
    assert(lights.active({}, 8u).size() == 1u && lights.active({}, 8u).front().identifier == close_light);

    HeightField terrain;
    assert(terrain.reset(2u, 2u, 1.0f, {0.0f, 2.0f, 2.0f, 4.0f}));
    assert(near(terrain.height(0.5f, 0.5f), 2.0f));
    const semantic::Vec3 normal = terrain.normal(0.5f, 0.5f);
    assert(normal.y > 0.0f);

    PlantingMap planting;
    assert(planting.load("# model x y z scale rotation\ntree.mdl 0 0 0 1 0\ngrass.mdl 10 0 0 0.5 90\n"));
    assert(planting.plants().size() == 2u && planting.in_radius({}, 1.0f).size() == 1u);

    WeatherTimeline weather;
    assert(weather.set({{0.0f, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f}, {10.0f, {1.0f, 1.0f, 1.0f}, 1.0f, 0.5f, 2.0f}}, 10.0f));
    const WeatherKeyframe midpoint = weather.sample(5.0f);
    assert(near(midpoint.fog_density, 0.5f) && near(midpoint.wind, 1.0f));

    assert(objects.destroy(child_handle) && !objects.find(child_handle));
    const ObjectHandle replacement = objects.create({});
    assert(replacement.index == child_handle.index && replacement.generation != child_handle.generation);
}

void test_configuration_parsing() {
    std::array<char, 256> owned{};
    char* active = owned.data();
    std::uint32_t active_length = 0u;
    semantic::attach_runtime({{&active, &active_length, owned.data(), owned.size()}, nullptr, 0u, nullptr, nullptr});
    constexpr char configuration[] = "answer 42\nratio 3.5\nname \"semantic\"\nbad nope\n";
    std::array<char, 16> status{"pending"};
    assert(semantic::install_config_text(status.data(), configuration, sizeof(configuration) - 1u) == sizeof(configuration) - 1u);
    assert(status[0] == '\0' && semantic::config_text_length() == sizeof(configuration) - 1u);

    std::int32_t answer = -1;
    float ratio = 0.0f;
    std::array<char, 16> name{};
    assert(semantic::read_config_int("answer", &answer) && answer == 42);
    assert(semantic::read_config_float("ratio", &ratio) && near(ratio, 3.5f));
    assert(semantic::read_config_string("name", name.data(), name.size()) && std::string_view(name.data()) == "semantic");
    assert(semantic::read_config_int("bad", &answer) && answer == 42);
    std::array<char, 8> copied{};
    semantic::copy_c_string(copied.data(), "config");
    assert(std::string_view(copied.data()) == "config");
}

void test_script_runtime() {
    using namespace semantic::script;
    assert(apply(Operator::add, Value(7), Value(5)).integer() == 12);
    assert(apply(Operator::multiply, Value(7), Value(6)).integer() == 42);
    assert(apply(Operator::add, Value("semantic "), Value("lift")).text() == "semantic lift");
    const Value vector_sum = apply(Operator::add, Value(semantic::Vec3{1.0f, 2.0f, 3.0f}), Value(semantic::Vec3{4.0f, 5.0f, 6.0f}));
    const auto& vector = std::get<semantic::Vec3>(vector_sum.storage());
    assert(near(vector.x, 5.0f) && near(vector.y, 7.0f) && near(vector.z, 9.0f));

    Value sequence = Value::sequence();
    assign(sequence, Value(0), Value("first"));
    assign(sequence, Value(2), Value("third"));
    assert(size(sequence) == 3u && find(sequence, Value(2))->text() == "third");
    assert(erase(sequence, Value(1)) && size(sequence) == 2u);

    Value map = Value::ordered_map();
    assign(map, Value("key"), Value(77));
    assert(find(map, Value("key"))->integer() == 77);

    VirtualMachine machine;
    machine.set_program({
        {OpCode::push_constant, 0u, Operator::add},
        {OpCode::push_constant, 1u, Operator::add},
        {OpCode::binary, 0u, Operator::multiply},
        {OpCode::store_variable, 9u, Operator::add},
        {OpCode::halt, 0u, Operator::add},
    }, {Value(6), Value(7)});
    machine.run();
    assert(machine.halted() && machine.variable(9u) && machine.variable(9u)->integer() == 42);
}

void test_network() {
    const std::array<std::uint8_t, 3> payload{1u, 2u, 3u};
    semantic::network::PacketQueue queue(64u);
    assert(queue.enqueue(0x3456u, payload, 2u, 0x1234u));
    const std::span<const std::uint8_t> bytes = queue.pending();
    assert(bytes.size() == 11u && bytes[0] == 11u && bytes[1] == 0u);
    assert(bytes[4] == 2u && bytes[5] == 0u && bytes[6] == 0x56u && bytes[7] == 0x34u);
    std::uint16_t sum = 0u;
    for (std::size_t index = 4u; index < bytes.size(); ++index) { sum = static_cast<std::uint16_t>(sum + bytes[index]); }
    const std::uint16_t checksum = static_cast<std::uint16_t>(bytes[2] | static_cast<std::uint16_t>(bytes[3]) << 8u);
    assert(checksum == static_cast<std::uint16_t>(0x1234u ^ sum));

    semantic::network::PacketStream stream(64u);
    assert(stream.append(bytes.first(5u)) && !stream.next());
    assert(stream.append(bytes.subspan(5u)));
    const auto packet = stream.next();
    assert(packet && packet->header.opcode == 0x3456u && packet->header.sequence == 2u && packet->payload == std::vector<std::uint8_t>(payload.begin(), payload.end()));
    queue.consume(bytes.size());
    assert(queue.pending().empty() && queue.packet_count() == 0u);

    semantic::network::ConnectionSession connection;
    connection.begin("127.0.0.1", 2593u);
    connection.accept_handshake(0x12345678u, 0x55aau);
    connection.mark_connected();
    assert(connection.state() == semantic::network::ConnectionState::connected);
    assert(connection.peer_identifier() == 0x12345678u && connection.checksum_seed() == 0x55aau);
}

void test_assets_and_services() {
    const std::array<std::uint8_t, 4> data{1u, 2u, 3u, 4u};
    assert(semantic::assets::crc32(data) == semantic::assets::crc32(data));
    assert(semantic::assets::manifest_checksum("Models/Hero.MDL", 100u, 200u) == semantic::assets::manifest_checksum("models/hero.mdl", 100u, 200u));
    assert(semantic::assets::split_search_path("data;mods;cache").size() == 3u);

    const std::filesystem::path fixture = std::filesystem::temp_directory_path() / "sfera_semantic_test.bin";
    {
        std::ofstream output(fixture, std::ios::binary);
        output.write(reinterpret_cast<const char*>(data.data()), static_cast<std::streamsize>(data.size()));
    }
    semantic::service::FileImage image;
    assert(image.open(fixture) && image.bytes().size() == data.size());
    assert(std::equal(image.bytes().begin(), image.bytes().end(), data.begin()));
    image.close();
    assert(!image.is_open());
    std::filesystem::remove(fixture);

    semantic::service::MemoryTracker tracker;
    int allocation = 0;
    tracker.register_allocation(&allocation, {128u, "semantic", 10u});
    assert(tracker.allocation_count() == 1u && tracker.allocated_bytes() == 128u);
    assert(tracker.find(&allocation)->line == 10u);
    assert(tracker.release(&allocation)->size == 128u && tracker.allocation_count() == 0u);

    semantic::service::AntifloodQueue antiflood(std::chrono::seconds(1));
    const auto beginning = std::chrono::steady_clock::time_point(std::chrono::seconds(10));
    assert(antiflood.accept("message", beginning));
    assert(!antiflood.accept("message", beginning + std::chrono::milliseconds(500)));
    assert(antiflood.suppressed("message") == 1u);
    assert(antiflood.accept("message", beginning + std::chrono::seconds(2)));
}

void test_character_effects_and_rendering() {
    using namespace semantic::character;
    const BonePose root_pose{{1.0f, 2.0f, 3.0f}, {0.0f, 0.0f, 0.0f, 1.0f}};
    const semantic::Matrix3x4 root_matrix = compose(root_pose);
    assert(near(root_matrix.values[3], 1.0f) && near(root_matrix.values[7], 2.0f) && near(root_matrix.values[11], 3.0f));
    const BonePose halfway = interpolate(root_pose, {{3.0f, 4.0f, 5.0f}, {0.0f, 0.0f, 0.0f, 1.0f}}, 0.5f);
    assert(near(halfway.translation.x, 2.0f) && near(halfway.translation.z, 4.0f));

    Skeleton skeleton;
    skeleton.add_bone({"Root", -1, identity_transform()});
    skeleton.add_bone({"Hand", 0, identity_transform()});
    assert(skeleton.find_bone("hand") == 1u);
    const std::array pose{root_pose, BonePose{{2.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}}};
    const auto matrices = skeleton.build_matrices(pose);
    assert(matrices.size() == 2u && near(matrices[1].values[3], 3.0f));

    semantic::effects::BloodEffect blood(2u);
    const std::array polygon{semantic::Vec3{0.0f, 0.0f, 0.0f}, semantic::Vec3{1.0f, 0.0f, 0.0f}, semantic::Vec3{0.0f, 0.0f, 1.0f}};
    assert(blood.add(polygon, identity_transform(), 1.0f, 1.0f, 0.0f, 0.0f));
    assert(blood.vertex_count() == 3u);
    blood.update(1.1f);
    assert(blood.marks().empty());

    semantic::render::ResourceRegistry resources;
    const auto managed = resources.add({semantic::render::ResourceKind::texture, 64u, 64u, 16384u, true, "managed"});
    resources.add({semantic::render::ResourceKind::texture, 32u, 32u, 4096u, false, "temporary"});
    assert(resources.size() == 2u && resources.find(managed));
    resources.clear_unmanaged();
    assert(resources.size() == 1u);

    std::size_t state_changes = 0u;
    semantic::render::StateCache states([&state_changes](semantic::render::RenderStateKey, std::uint32_t) { ++state_changes; });
    assert(states.set({1u, 2u}, 3u));
    assert(!states.set({1u, 2u}, 3u) && state_changes == 1u);

    semantic::render::ShaderProgram shader("blood");
    const std::array constants{1.0f, 2.0f, 3.0f, 4.0f};
    shader.set("color", constants);
    assert(shader.constant("color") && shader.constant("color")->values.size() == 4u);
    semantic::render::PostEffects effects;
    effects.append({"blood", managed, {}, {}});
    assert(effects.take_next()->shader == "blood" && effects.size() == 0u);
}


void test_completion_runtime() {
    using namespace semantic;

    const std::array<std::string_view, 8> launch_args{"sphere.exe", "/locale", "ru", "/login=tester", "/gamexp_sid", "sid42", "/connect_type", "direct"};
    const auto launch = client_runtime::parse_launch_arguments(launch_args);
    assert(launch.locale && *launch.locale == "ru" && launch.login && *launch.login == "tester");
    assert(launch.gamexp_session && *launch.gamexp_session == "sid42" && launch.connect_type == "direct");
    const auto connect_cfg = client_runtime::parse_key_value_config("CONNECT_TYPE=tcp\nHOST = 127.0.0.1\n");
    assert(connect_cfg.at("connect_type") == "tcp" && connect_cfg.at("host") == "127.0.0.1");

    client_runtime::ModelManager models;
    assert(models.register_folder("Models") && models.register_model("Hero", "Models/Hero.mdl") == 0);
    assert(models.by_name("hero") && models.by_id(0) && models.size() == 1u);
    const auto ping = client_runtime::parse_ping_report("Packets: Sent = 1, Received = 1, Lost = 0; time=17ms TTL=64");
    assert(ping.health == client_runtime::ConnectionHealth::reachable && ping.received == 1u && ping.round_trip_ms == 17u);

    content_runtime::MaterialFilter filter;
    filter.set_rules({{"metal", "metal.dds", 1.0f, {"armor"}}, {"metal", "metal_heavy.dds", 2.0f, {"armor"}}});
    filter.set_exceptions({"skip"});
    assert(filter.match("METAL", "armor") && filter.match("metal", "armor")->texture == "metal_heavy.dds" && filter.excluded("SKIP"));

    content_runtime::ObjectConfig object_config;
    std::string parse_error;
    assert(object_config.parse("name = hero; stats = { hp = 100; speed = 2.5; }; flags = [true, false, 3]", &parse_error));
    assert(object_config.find("name") && object_config.find("name")->text() && *object_config.find("name")->text() == "hero");
    assert(object_config.find("stats.hp") && object_config.find("stats.hp")->integer() == 100);
    assert(object_config.find("flags") && object_config.find("flags")->at(1u) && object_config.find("flags")->at(1u)->boolean() == false);

    content_runtime::ScalarCurve curve;
    assert(curve.set({{0.0f, 0.0f}, {1.0f, 10.0f}}, content_runtime::Interpolation::linear));
    assert(near(curve.sample(0.25f), 2.5f));
    content_runtime::ParticleLibrary particles;
    content_runtime::ParticleSystemDefinition particle;
    particle.name = "rain";
    particle.particle_count = 128u;
    particle.size = curve;
    assert(particles.store(std::move(particle)) && particles.find("RAIN"));

    content_runtime::QuadTree tree({0.0f, 0.0f, 100.0f, 100.0f}, 1u, 4u);
    assert(tree.insert({1u, {10.0f, 10.0f, 20.0f, 20.0f}}));
    assert(tree.insert({2u, {70.0f, 70.0f, 80.0f, 80.0f}}));
    const auto near_origin = tree.query({0.0f, 0.0f, 30.0f, 30.0f});
    assert(near_origin.size() == 1u && near_origin[0] == 1u);

    content_runtime::QuickFileArchive archive;
    assert(archive.add("_main.mbc", {1u, 2u, 3u}) && archive.find("_MAIN.MBC").size() == 3u);
    content_runtime::ServerWall wall;
    wall.set_segments({{{5.0f, 0.0f, -1.0f}, {5.0f, 0.0f, 1.0f}, 0u}});
    assert(wall.blocked({0.0f, 0.0f, 0.0f}, {10.0f, 0.0f, 0.0f}));

    content_runtime::MapGenerator map_generator;
    const auto generated = map_generator.generate(4u, 3u, 123u, 2.0f);
    assert(generated.width == 4u && generated.height == 3u && generated.heights.size() == 12u);
    content_runtime::NatureManager nature;
    nature.register_rain_class(7u, "storm"); nature.set_state({1.5f, 2.0f, 7u});
    assert(nature.rain_class(7u) && *nature.rain_class(7u) == "storm" && near(nature.state().rain, 1.0f));
    content_runtime::ZoningManager zoning;
    assert(zoning.set_zones({{0, 0, 0.0f, 0.0f, 10.0f, 10.0f, 3u}}));
    assert(zoning.zone_at(5.0f, 5.0f) && zoning.zone_at(5.0f, 5.0f)->identifier == 3u);

    content_runtime::TextureSet textures;
    assert(textures.set("Diffuse", "Effects/diffuse.dds") && textures.find("diffuse"));
    content_runtime::UpdatePlan update;
    update.set_local({{"a.bin", 10u, 1u}});
    update.set_remote({{"a.bin", 10u, 2u}, {"b.bin", 5u, 3u}});
    assert(update.required().size() == 2u);

    markup_runtime::HyperTextDocument document;
    assert(document.parse("Hello <b>bold</b> <a href=\"player:Adam\">Adam</a>"));
    assert(document.plain_text() == "Hello bold Adam");
    assert(document.runs().back().link && document.runs().back().link->scheme == "player" && document.runs().back().link->value == "Adam");
    markup_runtime::TokenStream tokens("a = \"two words\"\n# comment\nb");
    assert(tokens.next() == "a" && tokens.next() == "=" && tokens.next() == "two words" && tokens.next() == "b");

    sky_runtime::SkyTimeline sky;
    assert(sky.set_states({{0.0f, {0.0f, 0.0f, 0.0f}, 1.0f, 0.0f}, {12.0f, {1.0f, 1.0f, 1.0f}, 0.0f, 1.0f}}, 24.0f));
    assert(near(sky.sample(6.0f).color.x, 0.5f));

    legacy_sound::SoundLibrary sounds;
    assert(sounds.store({"click", legacy_sound::play_random, {{"click.wav", 1.0f, 1.0f}}, 0.0f}) && sounds.find("CLICK"));
    legacy_sound::SoundTrack track;
    track.set_playlist({"one.ogg", "two.ogg"}, true);
    assert(track.current() && *track.current() == "one.ogg");
    assert(track.advance() && *track.current() == "two.ogg");
    assert(track.advance() && *track.current() == "one.ogg");

    ui_runtime::PropertyBag properties;
    assert(properties.parse("range=1 9; color=10 20 30 40; horizontal=true"));
    assert(properties.rectangle("range") == std::nullopt && properties.color("color") && properties.boolean("horizontal") == true);
    ui_runtime::InterfaceModel interface_model;
    assert(interface_model.add_sprite({"button", {32, 16}, {"button.dds"}, {}}));
    assert(interface_model.add_font({"main", "font.dds", 256u, 14}));
    ui_runtime::Control window; window.identifier = 1u; window.name = "window"; window.kind = ui_runtime::ControlKind::generic; window.bounds = {0, 0, 100, 100};
    ui_runtime::Control button; button.identifier = 2u; button.name = "button"; button.kind = ui_runtime::ControlKind::button; button.bounds = {10, 10, 30, 30}; button.parent = 1u;
    assert(interface_model.create(std::move(window)));
    assert(interface_model.create(std::move(button)));
    assert(interface_model.find(1u)->children.size() == 1u && interface_model.hit_test({15, 15}).size() == 2u);

    ui_runtime::TextBuffer edit;
    edit.configure(8u, false, true);
    assert(edit.set("secret") && edit.display_text() == "******");
    ui_runtime::ScrollModel scroll;
    scroll.set_range(0, 100); scroll.set_page(10); scroll.set_step(2); scroll.set_position(50); scroll.line(1); scroll.page_move(-1);
    assert(scroll.position() == 42);
    ui_runtime::ProgressModel progress{0, 200, 50};
    assert(near(progress.fraction(), 0.25f) && progress.label(true) == "25%");
    ui_runtime::OptionsModel options;
    const ui_runtime::VideoMode mode{1920u, 1080u, 60u, 21u};
    options.set_video_modes({mode, mode});
    assert(options.video_modes().size() == 1u && options.choose_video_mode(mode));
}

void test_directx_table() {
    assert(std::string_view(semantic::directx::error_description(-2147483638)) == "The data necessary to complete this operation is not yet available.");
    assert(std::string_view(semantic::directx::error_description(123456789)) == "n/a");
}

void test_compiler_runtime() {
    using namespace semantic::compiler_runtime;
    assert(signed_divide(-100, 7) == -14);
    assert(signed_remainder(-100, 7) == -2);
    assert(unsigned_divide(UINT64_C(0xfedcba9876543210), UINT64_C(0x12345678)) == UINT64_C(0x0000000e00000077));
    assert(multiply(UINT64_C(0xffffffffffffffff), 2u) == UINT64_C(0xfffffffffffffffe));

    const semantic::NativeEntry* divide_entry = semantic::find_native_entry(0x004EEA40u);
    assert(divide_entry && divide_entry->convention == semantic::NativeCallingConvention::stdcall_call);
    assert(divide_entry->parameter_count == 2u && divide_entry->parameters[0].width == 8u && divide_entry->stack_bytes == 16u);
    const std::array divide_arguments{integer_argument(std::bit_cast<std::uint64_t>(INT64_C(-100)), 8u), integer_argument(7u, 8u)};
    const auto result = semantic::invoke_native_entry(*divide_entry, divide_arguments.data(), divide_arguments.size(), nullptr);
    assert(std::bit_cast<std::int64_t>(result.word) == -14);

    std::array<std::uint8_t, 4> copied{};
    const std::array<std::uint8_t, 4> original{4u, 3u, 2u, 1u};
    const semantic::NativeEntry* copy_entry = semantic::find_native_entry(0x004EE804u);
    assert(copy_entry && copy_entry->parameter_count == 3u);
    const std::array copy_arguments{pointer_argument(copied.data()), pointer_argument(original.data()), integer_argument(original.size(), 4u)};
    semantic::invoke_native_entry(*copy_entry, copy_arguments.data(), copy_arguments.size(), nullptr);
    assert(copied == original);
}

} // namespace

int main() {
    test_bitstream_contract();
    test_geometry_and_binding();
    test_scripted_effects_audio_and_logs();
    test_shared_runtime();
    test_world_math_and_bindings();
    test_world_runtime();
    test_configuration_parsing();
    test_script_runtime();
    test_network();
    test_assets_and_services();
    test_character_effects_and_rendering();
    test_completion_runtime();
    test_directx_table();
    test_compiler_runtime();
    std::cout << "semantic native subsystem checks passed" << std::endl;
}
