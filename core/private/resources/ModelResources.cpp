#include <algorithm>
#include <array>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <exception>
#include <filesystem>
#include <format>
#include <functional>
#include <io.h>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <utility>
#include <vector>

#include "animation/Animation.h"
#include "binary/Binary.h"
#include "collision/Collision.h"
#include "config/ConfigDocument.h"
#include "diagnostics/ClientDiagnostics.h"
#include "geometry/Geometry.h"
#include "math/Vector.h"
#include "numeric/Numeric.h"
#include "render/CharacterRenderer.h"
#include "render/Material.h"
#include "render/Model.h"
#include "resources/FileResources.h"
#include "resources/ModelResources.h"
#include "resources/TextureRepository.h"
#include "text/Text.h"
#include "vegetation/VegetationGeometry.h"

SphereRenderCharacterModelsSearchScope::~SphereRenderCharacterModelsSearchScope()
{
    ::_findclose(handle);
}

template <class T> T SphereRenderCharacterModels::characterRead(std::span<const std::uint8_t> bytes, std::size_t offset)
{
    if (offset > bytes.size() || sizeof(T) > bytes.size() - offset)
        WorldDiagnostics::fail("Truncated character model");
    const auto value = SferaBinaryReader(bytes.subspan(offset, sizeof(T))).read<T>();
    if constexpr (std::is_floating_point_v<T>)
        if (!std::isfinite(value))
            WorldDiagnostics::fail("Nonfinite character coordinate");
    return value;
}

std::span<const std::uint8_t> SphereRenderCharacterModels::characterRange(std::span<const std::uint8_t> bytes, std::size_t offset, std::size_t length)
{
    if (offset > bytes.size() || length > bytes.size() - offset)
        WorldDiagnostics::fail("Truncated character model");
    return bytes.subspan(offset, length);
}

int SphereRenderCharacterModels::usesSmallHelm(int sex, int code) const
{
    if (sex == 0)
        return 0;
    const auto index = code > '9' ? code - 'a' + 10 : code - '0';
    if (index < 0 || std::cmp_greater_equal(index, small_helm.size()))
        WorldDiagnostics::fail("Invalid character helm code");
    return small_helm[index];
}

int SphereRenderCharacterModels::textureVariants(bool female, std::string_view part)
{
    if (part.size() != 1u)
        throw std::invalid_argument("Texture part must contain one code unit");
    const std::string prefix = std::string("models\\textures\\") + (female ? "w" : "m") + std::string(part);
    g_sfera_files.setErrorReporting(false);
    int count = 0;
    for (;;)
    {
        // The legacy resource suffix is one encoded byte, including wraparound above 255.
        const std::array<std::uint8_t, 1> suffix{{SferaNumeric::lowByte(SferaNumeric::word(count <= 9 ? '0' + count : 'a' + count - 10))}};
        const auto path = prefix + SferaText::fromBytes(suffix) + "0.dds";
        if (g_sfera_files.fileSize(path) == -1)
            break;
        ++count;
    }
    g_sfera_files.setErrorReporting(true);
    return count;
}

void SphereRenderCharacterModels::loadSkeleton(const std::string &path, SphereRenderCharacterSkeleton &skeleton)
{
    const auto bytes = g_sfera_files.readAll(path);
    const auto data = std::span<const std::uint8_t>(bytes);
    const auto encoded_bones = SphereRenderCharacterModels::characterRead<int>(data, 0);
    const auto encoded_frames = SphereRenderCharacterModels::characterRead<int>(data, 4);
    if (encoded_bones <= 0 || encoded_frames <= 0)
        WorldDiagnostics::fail("Invalid character skeleton size");
    const std::size_t bones = encoded_bones, frames = encoded_frames;
    constexpr std::size_t encoded_pose_size = 28;
    if (frames > data.size() / encoded_pose_size / bones)
        WorldDiagnostics::fail("Truncated character skeleton poses");
    const auto pose_size = bones * frames * encoded_pose_size;
    if (data.size() < 12u || pose_size > data.size() - 12u || bones > (data.size() - 12u - pose_size) / 34u)
        WorldDiagnostics::fail("Truncated character skeleton poses");
    std::size_t offset = 8;
    const auto parent_bytes = SphereRenderCharacterModels::characterRange(data, offset, bones * 4);
    offset += parent_bytes.size();
    const auto name_bytes = SphereRenderCharacterModels::characterRange(data, offset, bones * 30);
    offset += name_bytes.size();
    const auto pose_bytes = SphereRenderCharacterModels::characterRange(data, offset, bones * frames * encoded_pose_size);
    offset += pose_bytes.size();
    const auto encoded_animations = SphereRenderCharacterModels::characterRead<int>(data, offset);
    offset += 4;
    if (encoded_animations <= 0 || std::cmp_greater(encoded_animations, (data.size() - offset) / 4))
        WorldDiagnostics::fail("Invalid character animation count");
    const auto animation_bytes = SphereRenderCharacterModels::characterRange(data, offset, encoded_animations * 4u);
    SphereRenderCharacterSkeleton replacement;
    replacement.parents.resize(bones);
    replacement.names.resize(bones);
    replacement.children.resize(bones);
    replacement.poses.resize(bones * frames);
    replacement.animation_lengths.resize(encoded_animations);
    replacement.initial_pose.resize(bones);
    for (std::size_t bone = 0; bone < bones; ++bone)
    {
        const auto parent = SphereRenderCharacterModels::characterRead<int>(parent_bytes, bone * 4);
        if (parent < -1 || std::cmp_greater_equal(parent, bones) || std::cmp_equal(parent, bone))
            WorldDiagnostics::fail("Invalid skeleton parent");
        if (parent >= 0)
        {
            replacement.parents[bone] = parent;
            replacement.children[parent].push_back(bone);
        }
        const auto encoded_name = name_bytes.subspan(bone * 30, 30);
        const auto terminator = std::find(encoded_name.begin(), encoded_name.end(), 0);
        if (terminator == encoded_name.end())
            WorldDiagnostics::fail("Unterminated skeleton bone name");
        auto &name = replacement.names[bone];
        name.assign(encoded_name.begin(), terminator);
        if (name.starts_with('_'))
        {
            const int slot = name[1] - '0';
            if (slot < 0 || std::cmp_greater_equal(slot, replacement.attachments.size()))
                WorldDiagnostics::fail("Invalid character attachment name");
            replacement.attachments[slot] = bone;
        }
    }
    // Acyclic parent chains are required before recursive pose evaluation.
    std::vector<std::uint8_t> visited(bones, 0);
    for (std::size_t bone = 0; bone < bones; ++bone)
    {
        std::optional<std::size_t> current = bone;
        while (current && visited[*current] == 0)
        {
            visited[*current] = 1;
            current = replacement.parents[*current];
        }
        if (current && visited[*current] == 1)
            WorldDiagnostics::fail("Cyclic character skeleton");
        current = bone;
        while (current && visited[*current] == 1)
        {
            visited[*current] = 2;
            current = replacement.parents[*current];
        }
    }
    for (std::size_t index = 0; index < replacement.poses.size(); ++index)
    {
        auto &pose = replacement.poses[index];
        const std::size_t start = index * encoded_pose_size;
        pose.rotation = {SphereRenderCharacterModels::characterRead<float>(pose_bytes, start), SphereRenderCharacterModels::characterRead<float>(pose_bytes, start + 4),
                         SphereRenderCharacterModels::characterRead<float>(pose_bytes, start + 8), SphereRenderCharacterModels::characterRead<float>(pose_bytes, start + 12)};
        pose.translation = {SphereRenderCharacterModels::characterRead<float>(pose_bytes, start + 16), SphereRenderCharacterModels::characterRead<float>(pose_bytes, start + 20),
                            SphereRenderCharacterModels::characterRead<float>(pose_bytes, start + 24)};
    }
    std::size_t used_frames = 0;
    for (std::size_t index = 0; index < replacement.animation_lengths.size(); ++index)
    {
        const auto length = SphereRenderCharacterModels::characterRead<int>(animation_bytes, index * 4);
        if (length < 0 || std::cmp_greater(length, frames - used_frames))
            WorldDiagnostics::fail("Character animation exceeds its pose data");
        replacement.animation_lengths[index] = length;
        used_frames += length;
    }
    animate(replacement, 0, 0, 0, 0, 0.0f, replacement.initial_pose.data(), false);
    skeleton = std::move(replacement);
}

void SphereRenderCharacterModels::preload(SphereRenderCharacterAsset &asset, const SphereRenderCharacterSkeleton &skeleton)
{
    if (asset.geometry != nullptr)
        return;
    const auto path = directories.at(asset.directory) + asset.name + ".chr";
    const auto bytes = g_sfera_files.readAll(path);
    const auto data = std::span<const std::uint8_t>(bytes);
    if (data.size() < 4 || std::memcmp(data.data(), "sch0", 4) != 0)
        WorldDiagnostics::fail("preload_model: wrong file format");
    std::span<const std::uint8_t> vertexBytes, indexBytes, structureBytes, boneBytes;
    const auto count = SphereRenderCharacterModels::characterRead<int>(data, 8);
    if (count < 0 || std::cmp_greater(count, (data.size() - 12) / 12))
        WorldDiagnostics::fail("Invalid character block count");
    for (std::size_t block = 0; block < count; ++block)
    {
        const auto offset = 12u + block * 12u;
        const auto kind = SphereRenderCharacterModels::characterRead<std::uint32_t>(data, offset);
        const auto chunk = SphereRenderCharacterModels::characterRange(data, SphereRenderCharacterModels::characterRead<std::uint32_t>(data, offset + 4),
                                                                       SphereRenderCharacterModels::characterRead<std::uint32_t>(data, offset + 8));
        if (kind == 1)
            vertexBytes = chunk;
        else if (kind == 2)
            indexBytes = chunk;
        else if (kind == 6)
            structureBytes = chunk;
        else if (kind == 7)
            boneBytes = chunk;
    }
    constexpr std::size_t encoded_vertex_size = 40;
    if (vertexBytes.size() % encoded_vertex_size != 0)
        WorldDiagnostics::fail("Invalid character vertex block");
    auto geometry = std::make_unique<SphereRenderCharacterGeometry>();
    geometry->vertices.resize(vertexBytes.size() / encoded_vertex_size);
    for (std::size_t index = 0; index < geometry->vertices.size(); ++index)
    {
        auto &vertex = geometry->vertices[index];
        const std::size_t start = index * encoded_vertex_size;
        vertex.position = {SphereRenderCharacterModels::characterRead<float>(vertexBytes, start), SphereRenderCharacterModels::characterRead<float>(vertexBytes, start + 4),
                           SphereRenderCharacterModels::characterRead<float>(vertexBytes, start + 8)};
        vertex.normal = {SphereRenderCharacterModels::characterRead<float>(vertexBytes, start + 12), SphereRenderCharacterModels::characterRead<float>(vertexBytes, start + 16),
                         SphereRenderCharacterModels::characterRead<float>(vertexBytes, start + 20)};
        vertex.u = SphereRenderCharacterModels::characterRead<float>(vertexBytes, start + 24);
        vertex.v = SphereRenderCharacterModels::characterRead<float>(vertexBytes, start + 28);
        vertex.first_bone = vertexBytes[start + 32];
        vertex.second_bone = vertexBytes[start + 33];
        vertex.weight = SphereRenderCharacterModels::characterRead<float>(vertexBytes, start + 36);
    }
    const auto groupOffset = SphereRenderCharacterModels::characterRead<std::uint32_t>(structureBytes, 4);
    const auto group = SphereRenderCharacterModels::characterRange(structureBytes, groupOffset, 10);
    const auto triangleCount = SphereRenderCharacterModels::characterRead<std::uint32_t>(group, 6);
    if (triangleCount > indexBytes.size() / 6)
        WorldDiagnostics::fail("Truncated character indices");
    SferaBinaryReader indexReader(SphereRenderCharacterModels::characterRange(indexBytes, 0, triangleCount * 6));
    geometry->indices.resize(triangleCount * 3);
    for (auto &index : geometry->indices)
        index = indexReader.read<std::uint16_t>();
    const auto boneCount = SphereRenderCharacterModels::characterRead<int>(boneBytes, 0);
    if (boneCount < 0 || std::cmp_greater(boneCount, (boneBytes.size() - 4) / 2))
        WorldDiagnostics::fail("Invalid character bone names");
    std::vector<std::size_t> remap(boneCount);
    std::size_t offset = 4;
    for (int bone = 0; bone < boneCount; ++bone)
    {
        const auto length = SphereRenderCharacterModels::characterRead<std::int8_t>(boneBytes, offset++);
        if (length <= 0)
            WorldDiagnostics::fail("Invalid character bone name length");
        const auto name = SphereRenderCharacterModels::characterRange(boneBytes, offset, length);
        if (name.back() != 0)
            WorldDiagnostics::fail("Unterminated character bone name");
        const auto boneName = SferaText::fromBytes(name).substr(0, std::find(name.begin(), name.end(), 0) - name.begin());
        std::size_t match = 0;
        while (match < skeleton.parents.size() && SferaText::compareInsensitive(boneName, skeleton.names[match]) != 0)
            ++match;
        if (match == skeleton.parents.size())
            WorldDiagnostics::fail("Match for bone name not found");
        remap[bone] = match;
        offset += length;
    }
    for (auto &vertex : geometry->vertices)
    {
        const auto first = vertex.first_bone;
        const auto second = vertex.second_bone;
        if (first >= remap.size() || second >= remap.size())
            WorldDiagnostics::fail("Invalid character vertex bone");
        vertex.first_bone = remap[first];
        vertex.second_bone = remap[second];
    }
    for (const auto index : geometry->indices)
        if (index >= geometry->vertices.size())
            WorldDiagnostics::fail("Character face references a missing vertex");
    asset.geometry = std::move(geometry);
}

void SphereRenderCharacterModels::load(std::span<const std::string_view> folders)
{
    if (folders.size() >= 100)
        WorldDiagnostics::fail("Character model directory limit exceeded");
    auto replacement = std::make_unique<SphereRenderCharacterModels>();
    replacement->initializeBounds();
    replacement->loadSkeleton("xadd\\man.skl", replacement->skeletons[0]);
    replacement->loadSkeleton("xadd\\woman.skl", replacement->skeletons[1]);
    for (const auto path : folders)
    {
        if (path.size() >= 200)
            WorldDiagnostics::fail("Character model directory name too long");
        const auto directory = replacement->directories.size();
        replacement->directories.emplace_back(path);
        _finddata64i32_t entry{};
        const auto handle = ::_findfirst64i32((std::string(path) + "*.chr").c_str(), &entry);
        if (handle == -1)
            continue;
        SphereRenderCharacterModelsSearchScope search{handle};
        do
        {
            if ((entry.attrib & _A_SUBDIR) != 0u)
                continue;
            std::string name(entry.name);
            if (name.size() < 5u || name.size() >= 32u)
                WorldDiagnostics::fail("Invalid character model filename");
            name.resize(name.find_last_of('.'));
            SferaText::transformBytes(name, SferaText::asciiFold);
            replacement->assets.push_back({std::move(name), directory, {}});
        } while (::_findnext64i32(handle, &entry) == 0);
    }
    SphereRenderConfigDocument::setStorageMode(SphereRenderConfigDocumentStorageMode::Plain);
    auto configuration = SphereRenderConfigDocument::open("xadd\\subobjs.dat");
    const auto countParts = configuration.arraySize("subobjs");
    if (!countParts || *countParts == 0u)
        WorldDiagnostics::fail("wrong format of subobjs.dat");
    replacement->parts.resize(*countParts);
    for (std::size_t index = 0; index < *countParts; ++index)
    {
        const auto *record = configuration.objectAt("subobjs", index);
        const auto code = record == nullptr ? std::nullopt : record->text("s");
        const auto name = record == nullptr ? std::nullopt : record->text("m");
        if (!code || !name)
            WorldDiagnostics::fail("wrong format of subobjs.dat");
        const auto asset = std::find_if(replacement->assets.begin(), replacement->assets.end(), std::bind_front(&SphereRenderCharacterModels::characterAssetNamed, *name));
        if (asset == replacement->assets.end())
            WorldDiagnostics::fail(std::format("char model not found. name={}", *name));
        auto &part = replacement->parts[index];
        part.asset = asset - replacement->assets.begin();
        part.textures.fill(-1);
        const auto textures = record->arraySize("t");
        if (!textures || *textures == 0u || *textures > part.textures.size())
            WorldDiagnostics::fail("wrong format of subobjs.dat");
        for (std::size_t texture = 0; texture < *textures; ++texture)
        {
            const auto textureName = record->textAt("t", texture);
            if (!textureName)
                WorldDiagnostics::fail("wrong format of subobjs.dat");
            part.textures[texture] = g_sfera_textures.find(*textureName);
            if (part.textures[texture] == -1)
                WorldDiagnostics::fail(std::format("texture for char model not found. name={}", *textureName));
        }
        if (code->size() != 3u || ((*code)[0] != 'm' && (*code)[0] != 'w') || (*code)[1] < 'a' || (*code)[1] > 'z')
            WorldDiagnostics::fail("wrong format of subobjs.dat");
        replacement->part_indices[(*code)[0] == 'w'][(*code)[1] - 'a'][SferaText::byteValue((*code)[2])] = index;
    }
    const auto helms = configuration.arraySize("womanhelmsmall");
    if (!helms || *helms == 0u || *helms > replacement->small_helm.size())
        WorldDiagnostics::fail("wrong format of subobjs.dat");
    for (std::size_t index = 0; index < *helms; ++index)
    {
        const auto value = configuration.integerAt("womanhelmsmall", index);
        if (!value)
            WorldDiagnostics::fail("wrong format of subobjs.dat");
        replacement->small_helm[index] = *value;
    }
    clear();
    *this = std::move(*replacement);
}

bool SphereRenderCharacterModels::characterAssetNamed(std::string_view name, const SphereRenderCharacterAsset &value)
{
    return value.name == name;
}

std::unique_ptr<SphereRenderModel> SphereRenderModel::load(std::string_view model_name, std::string_view directory, const SphereRenderModelParameters &parameters,
                                                           const SphereRenderMaterialLibrary &materials)
{
    try
    {
        const std::string path = std::format("{}{}.mdl", directory, model_name);
        const std::vector<std::uint8_t> bytes = g_sfera_files.readAll(path);
        return decode(model_name, bytes, parameters, materials);
    }
    catch (const std::exception &exception)
    {
        CSphereError error;
        error.write(exception.what());
        throw;
    }
}

std::unique_ptr<SphereRenderModel> SphereRenderModel::decode(std::string_view model_name, std::span<const std::uint8_t> bytes, const SphereRenderModelParameters &parameters,
                                                             const SphereRenderMaterialLibrary &materials)
{
    if (model_name.size() >= 32u)
        failDecode(model_name, "model name is too long");
    if (bytes.size() < 258u)
        failDecode(model_name, "truncated MDL header");

    const std::size_t source_vertex_count = readModelWord(model_name, bytes, 4u);
    const std::size_t source_face_count = readModelWord(model_name, bytes, 6u);
    const std::size_t source_submesh_count = readModelWord(model_name, bytes, 8u);
    const std::size_t source_material_count = readModelByte(model_name, bytes, 10u);
    const std::size_t material_name_bytes = readModelWord(model_name, bytes, 11u);
    const std::size_t source_bone_count = readModelByte(model_name, bytes, 13u);
    const std::size_t child_bone_count = readModelByte(model_name, bytes, 14u);
    const std::size_t keyframe_count = readModelWord(model_name, bytes, 16u);
    const std::size_t animation_frame_count = readModelWord(model_name, bytes, 18u);
    const std::size_t source_animation_count = readModelByte(model_name, bytes, 20u);
    const std::uint8_t source_has_colors = readModelByte(model_name, bytes, 23u);
    const std::size_t vertex_color_count = readModelWord(model_name, bytes, 24u);
    const std::uint32_t source_collision_kind = readModelInteger(bytes, 26u);
    if (source_collision_kind > SferaNumeric::enumBits(SphereRenderCollisionKind::None))
        failDecode(model_name, "invalid collision kind");
    const std::size_t source_collision_group_count = readModelInteger(bytes, 250u);
    const std::size_t collision_triangle_count = readModelInteger(bytes, 254u);
    std::size_t cursor = 258u;

    const std::size_t source_material_names = takeModelSection(model_name, bytes, cursor, material_name_bytes, 1u);
    const std::size_t source_vertices = takeModelSection(model_name, bytes, cursor, source_vertex_count, 32u);
    const std::size_t source_faces = takeModelSection(model_name, bytes, cursor, source_face_count, 10u);
    const std::size_t source_submeshes = takeModelSection(model_name, bytes, cursor, source_submesh_count, 15u);
    const std::size_t source_bones = takeModelSection(model_name, bytes, cursor, source_bone_count, 39u);
    const std::size_t source_children = takeModelSection(model_name, bytes, cursor, child_bone_count, 1u);
    const std::size_t source_keyframes = source_animation_count != 0u ? takeModelSection(model_name, bytes, cursor, keyframe_count, 28u) : cursor;
    const std::size_t source_animation_frames = source_animation_count != 0u ? takeModelSection(model_name, bytes, cursor, animation_frame_count, 3u) : cursor;
    const std::size_t source_animation_lengths = source_animation_count != 0u ? takeModelSection(model_name, bytes, cursor, source_animation_count, 2u) : cursor;
    const std::size_t source_colors = source_has_colors == 1u ? takeModelSection(model_name, bytes, cursor, vertex_color_count, 4u) : cursor;
    const std::size_t source_face_colors = source_has_colors == 1u ? takeModelSection(model_name, bytes, cursor, source_face_count, 6u) : cursor;
    const std::size_t source_bone_bounds = source_animation_count == 0u ? takeModelSection(model_name, bytes, cursor, source_bone_count, 24u) : cursor;
    const std::size_t source_collision_groups = source_collision_kind == 2u ? takeModelSection(model_name, bytes, cursor, source_collision_group_count, 12u) : cursor;
    const std::size_t source_collision_triangles = source_collision_kind == 2u ? takeModelSection(model_name, bytes, cursor, collision_triangle_count, 80u) : cursor;
    if (cursor != bytes.size())
        failDecode(model_name, "MDL section sizes do not match the file size");

    auto model = std::make_unique<SphereRenderModel>();
    if (auto catalogue = materials.snapshot())
        model->material_lifetimes.push_back(std::move(catalogue));
    model->name = model_name;
    model->root_bone = readModelByte(model_name, bytes, 15u);
    model->frame_count = readModelWord(model_name, bytes, 21u);
    model->has_vertex_colors = source_has_colors == 1u;
    model->collision_kind = SferaNumeric::enumFromBits<SphereRenderCollisionKind>(source_collision_kind);
    model->minimum = readModelPoint(model_name, bytes, 30u);
    model->maximum = readModelPoint(model_name, bytes, 42u);
    for (std::size_t index = 0u; index < 8u; ++index)
    {
        model->oriented_corners.corners[index] = readModelPoint(model_name, bytes, 54u + index * 12u);
        model->collision_corners.corners[index] = readModelPoint(model_name, bytes, 150u + index * 12u);
    }
    model->radius = readModelReal(model_name, bytes, 246u);
    model->casts_static_shadow = model->radius > 2.0f && source_animation_count == 0u;
    model->lod_distance = parameters.floatValue(model_name, "lod_f").value_or(1000.0f);
    model->lod_power = parameters.floatValue(model_name, "lod_pow").value_or(-1.0f);
    model->shadow_fade = parameters.floatValue(model_name, "shad_f").value_or(0.5f);
    model->shadow_scale = parameters.floatValue(model_name, "shad_s").value_or(2.0f);
    model->shadow_spread = parameters.floatValue(model_name, "shad_sp").value_or(0.8500000238418579f);
    if (const auto alpha = parameters.floatValue(model_name, "land_shade_affect_K"))
    {
        const float rounded = std::floor(*alpha * 255.0f + 0.5f);
        if (!std::isfinite(rounded) || rounded < (INT32_MIN) || rounded > INT32_MAX)
            failDecode(model_name, "invalid landscape shadow coefficient");
        model->landscape_shadow_alpha = std::min(SferaNumeric::truncateInt(rounded), 255);
    }

    model->materials.resize(source_material_count);
    cursor = source_material_names;
    for (std::size_t index = 0u; index < source_material_count; ++index)
    {
        if (cursor == source_vertices)
            failDecode(model_name, "missing material name");
        const std::size_t length = readModelByte(model_name, bytes, cursor++);
        if (length > source_vertices - cursor)
            failDecode(model_name, "material name exceeds its section");
        const std::string material_name(SferaText::prefix(std::span(bytes).subspan(cursor, length), length));
        const auto material = materials.find(material_name);
        if (!material)
            failDecode(model_name, "material is absent from the material library: " + material_name);
        model->materials[index] = material;
        cursor += length;
    }

    model->vertices.resize(source_vertex_count);
    for (std::size_t index = 0u; index < source_vertex_count; ++index)
    {
        const std::size_t offset = source_vertices + index * 32u;
        model->vertices[index].position = readModelPoint(model_name, bytes, offset);
        model->vertices[index].normal = readModelPoint(model_name, bytes, offset + 12u);
        model->vertices[index].u = readModelReal(model_name, bytes, offset + 24u);
        model->vertices[index].v = readModelReal(model_name, bytes, offset + 28u);
    }
    model->faces.resize(source_face_count);
    for (std::size_t index = 0u; index < source_face_count; ++index)
    {
        const std::size_t offset = source_faces + index * 10u;
        for (std::size_t vertex = 0u; vertex < 3u; ++vertex)
            model->faces[index].vertices[vertex] = readModelWord(model_name, bytes, offset + vertex * 2u);
    }
    model->submeshes.resize(source_submesh_count);
    for (std::size_t index = 0u; index < source_submesh_count; ++index)
    {
        const std::size_t offset = source_submeshes + index * 15u;
        SphereRenderSubmesh &submesh = model->submeshes[index];
        submesh.bone_index = readModelByte(model_name, bytes, offset) % 128u;
        submesh.inverted_fade = readModelByte(model_name, bytes, offset) / 128u != 0u;
        const std::size_t material = readModelByte(model_name, bytes, offset + 1u);
        if (material >= source_material_count)
            failDecode(model_name, "invalid submesh material");
        submesh.material = model->materials[material];
        submesh.first_face = readModelWord(model_name, bytes, offset + 2u);
        submesh.face_count = readModelWord(model_name, bytes, offset + 4u);
        submesh.first_vertex = readModelWord(model_name, bytes, offset + 6u);
        submesh.vertex_count = readModelWord(model_name, bytes, offset + 8u);

        if (submesh.first_face + submesh.face_count > source_face_count || submesh.first_vertex + submesh.vertex_count > source_vertex_count)
            failDecode(model_name, "submesh range exceeds its geometry");
        if (submesh.bone_index >= source_bone_count)
            failDecode(model_name, "invalid submesh bone");
        for (std::size_t face = submesh.first_face; face < submesh.first_face + submesh.face_count; ++face)
            for (std::uint16_t vertex : model->faces[face].vertices)
                if (vertex >= submesh.vertex_count)
                    failDecode(model_name, "face vertex exceeds its submesh");
        const SphereRenderMaterial *material_data = submesh.material;
        if (material_data == nullptr)
            failDecode(model_name, "invalid material index");
        if (material_data->hasColorVariation)
            model->color_variation = material_data->colorVariation;
    }
    model->bones.resize(source_bone_count);
    for (std::size_t index = 0u; index < source_bone_count; ++index)
    {
        const std::size_t offset = source_bones + index * 39u;
        SphereRenderBone &bone = model->bones[index];
        const auto boneName = std::span(bytes).subspan(offset, 32u);
        if (std::find(boneName.begin(), boneName.end(), std::uint8_t{}) == boneName.end())
            failDecode(model_name, "unterminated bone name");
        bone.name.assign(SferaText::prefix(boneName, boneName.size()));
        bone.has_geometry = readModelByte(model_name, bytes, offset + 32u) != 2u;
        bone.child_count = readModelByte(model_name, bytes, offset + 33u);
        bone.first_child = readModelByte(model_name, bytes, offset + 34u);
        if (bone.first_child + bone.child_count > child_bone_count)
            failDecode(model_name, "bone children exceed the child table");
        if (source_animation_count != 0u)
        {
            bone.data.emplace<SphereRenderBoneAnimation>();
            bone.animation().animated = readModelByte(model_name, bytes, offset + 35u);
            bone.animation().pose_index = readModelWord(model_name, bytes, offset + 36u);
            bone.animation().suppress_secondary_animation = readModelByte(model_name, bytes, offset + 38u);
            if (bone.animation().pose_index >= (bone.animation().animated ? animation_frame_count : keyframe_count))
                failDecode(model_name, "invalid bone animation offset");
            const std::string_view name = bone.name;

            if (SferaText::asciiEqual(bone.name, "back_swo"))
                bone.animation().attachment_slot = 0u;
            else if (SferaText::asciiEqual(bone.name, "back_ara"))
                bone.animation().attachment_slot = 1u;
            else if (SferaText::asciiEqual(bone.name, "back_axe"))
                bone.animation().attachment_slot = 2u;
            else if (SferaText::asciiEqual(bone.name, "back_spe"))
                bone.animation().attachment_slot = 3u;
            else if (SferaText::asciiEqual(bone.name, "back_cam"))
                bone.animation().attachment_slot = 4u;
            else if (SferaText::asciiEqual(bone.name, "finl_m1o1") || SferaText::asciiEqual(bone.name, "fingl_m1o1"))
                bone.animation().attachment_slot = 100u;
            else if (SferaText::asciiEqual(bone.name, "finr_m1o1") || SferaText::asciiEqual(bone.name, "fingr_m1o1"))
                bone.animation().attachment_slot = 101u;
            else if (SferaText::asciiEqual(bone.name, "neck_m1o1"))
                bone.animation().attachment_slot = 102u;
            else if (name.size() >= 4u && SferaText::asciiEqual(std::string(name.substr(0u, 4u)), "head"))
                bone.animation().attachment_slot = 103u;
        }
        else
        {
            const std::size_t bounds_offset = source_bone_bounds + index * 24u;
            bone.bounds().minimum = readModelPoint(model_name, bytes, bounds_offset);
            bone.bounds().maximum = readModelPoint(model_name, bytes, bounds_offset + 12u);
            bone.bounds().corners = SferaBoundsCornersRuntime::fromExtents(bone.bounds().minimum, bone.bounds().maximum);
            bone.bounds().center = (bone.bounds().minimum + bone.bounds().maximum) * 0.5f;
            const SferaVec3F diagonal = bone.bounds().maximum - bone.bounds().minimum;
            bone.bounds().diagonal_length = diagonal.length<double, float>();
        }
    }
    model->child_bones.resize(child_bone_count);
    for (std::size_t index = 0u; index < child_bone_count; ++index)
    {
        model->child_bones[index] = readModelByte(model_name, bytes, source_children + index);
        if (model->child_bones[index] >= source_bone_count)
            failDecode(model_name, "invalid child bone");
    }
    std::vector<std::uint8_t> visitation(source_bone_count);

    for (std::size_t index = 0; index < source_bone_count; ++index)
        visitDecodedBone(model_name, *model, visitation, index);
    if (source_animation_count != 0u)
    {
        model->keyframes.resize(keyframe_count);
        for (std::size_t index = 0u; index < keyframe_count; ++index)
        {
            const std::size_t offset = source_keyframes + index * 28u;
            model->keyframes[index].translation = readModelPoint(model_name, bytes, offset);
            model->keyframes[index].rotation = {readModelReal(model_name, bytes, offset + 12u), readModelReal(model_name, bytes, offset + 16u), readModelReal(model_name, bytes, offset + 20u),
                                                readModelReal(model_name, bytes, offset + 24u)};
        }
        model->animation_frames.resize(animation_frame_count);
        for (std::size_t index = 0u; index < animation_frame_count; ++index)
        {
            SphereRenderAnimationFrame &frame = model->animation_frames[index];
            frame.keyframe = readModelWord(model_name, bytes, source_animation_frames + index * 3u);
            frame.interpolation = readModelByte(model_name, bytes, source_animation_frames + index * 3u + 2u);
            if (frame.keyframe >= keyframe_count || (frame.interpolation != 255u && frame.keyframe + 1u >= keyframe_count))
                failDecode(model_name, "invalid animation keyframe");
        }
        model->animation_lengths.resize(source_animation_count);
        std::size_t sequence_begin = 0u;
        std::size_t required_frames = 0u;
        for (std::size_t index = 0u; index < source_animation_count; ++index)
        {
            const std::uint16_t length = readModelWord(model_name, bytes, source_animation_lengths + index * 2u);
            model->animation_lengths[index] = length;
            required_frames = std::max(required_frames, sequence_begin + std::max<std::size_t>(length, 1u));
            sequence_begin += length;
        }
        for (std::size_t index = 0u; index < source_bone_count; ++index)
            if (model->bones[index].animation().animated != 0u && model->bones[index].animation().pose_index + required_frames > animation_frame_count)
                failDecode(model_name, "bone animation sequences exceed the frame table");
    }
    if (source_has_colors == 1u)
    {
        model->vertex_colors.resize(vertex_color_count);
        for (std::size_t index = 0u; index < vertex_color_count; ++index)
            model->vertex_colors[index] = readModelInteger(bytes, source_colors + index * 4u);
        model->face_colors.resize(source_face_count);
        for (std::size_t index = 0u; index < source_face_count; ++index)
            for (std::size_t vertex = 0u; vertex < 3u; ++vertex)
            {
                const std::uint16_t color = readModelWord(model_name, bytes, source_face_colors + index * 6u + vertex * 2u);
                if (color >= vertex_color_count)
                    failDecode(model_name, "invalid face color index");
                model->face_colors[index].vertices[vertex] = color;
            }
    }
    if (source_collision_kind == 2u)
    {
        model->collision_groups.resize(source_collision_group_count);
        for (std::size_t index = 0u; index < source_collision_group_count; ++index)
        {
            SphereRenderModelCollisionGroup &group = model->collision_groups[index];
            group.bone = readModelInteger(bytes, source_collision_groups + index * 12u);
            group.triangle_count = readModelInteger(bytes, source_collision_groups + index * 12u + 4u);
            group.first_triangle = readModelInteger(bytes, source_collision_groups + index * 12u + 8u);
            if (group.bone >= source_bone_count || group.first_triangle > collision_triangle_count || group.triangle_count > collision_triangle_count - group.first_triangle)
                failDecode(model_name, "invalid collision group");
        }
        model->collision_triangles.resize(collision_triangle_count);
        for (std::size_t index = 0u; index < collision_triangle_count; ++index)
        {
            const std::size_t offset = source_collision_triangles + index * 80u;
            SphereRenderModelCollisionTriangle &triangle = model->collision_triangles[index];
            triangle.minimum = readModelPoint(model_name, bytes, offset);
            triangle.maximum = readModelPoint(model_name, bytes, offset + 12u);
            for (std::size_t vertex = 0u; vertex < 3u; ++vertex)
                triangle.vertices[vertex] = readModelPoint(model_name, bytes, offset + 24u + vertex * 12u);
            triangle.normal = readModelPoint(model_name, bytes, offset + 60u);
            triangle.plane_distance = readModelReal(model_name, bytes, offset + 72u);
            triangle.collision_flags = readModelInteger(bytes, offset + 76u);
        }
    }
    model->recoverBounds();
    if (model->minimum_size < 0.05000000074505806f)
        failDecode(model_name, "object size is below MIN_OBJECT_SIZE");
    model->assignMaterials();
    model->prepareVegetation(parameters);
    return model;
}

void SphereRenderModel::prepareVegetation(const SphereRenderModelParameters &parameters)
{
    vegetation_kind = SferaNumeric::enumFromBits<SphereRenderVegetationKind>(parameters.intValue(name, "dg_type").value_or(-1));
    const float ground_y = parameters.floatValue(name, "ground_y").value_or(0.0f);
    if (vegetation_kind == SphereRenderVegetationKind::Grass || vegetation_kind == SphereRenderVegetationKind::SynchronizedGrass || vegetation_kind == SphereRenderVegetationKind::InteractiveGrass)
        prepareGrass(vegetation_kind == SphereRenderVegetationKind::SynchronizedGrass, ground_y);
    if (vegetation_kind == SphereRenderVegetationKind::InteractiveGrass)
    {
        auto &grass_data = *grass();
        grass_data.bending.resize(vertices.size());
        for (std::size_t index = 0u; index < vertices.size(); ++index)
        {
            SphereRenderGrassBendingBasis &basis = grass_data.bending[index];
            basis.anchor = {vertices[index].position.x, -0.15000000596046448f, vertices[index].position.z};
            const SphereRenderGrassInfluence &influence = grass_data.influences[index];
            if (influence.anchor_kind != SphereRenderGrassInfluenceAnchor::Vertex)
                continue;
            const SferaVec3F direction = vertices[index].position - vertices[influence.anchor_vertex].position;
            const SferaVec3F first_axis = SferaVec3F{0.0f, 0.0f, 1.0f}.cross(direction);
            const SferaVec3F second_axis = direction.cross({1.0f, 0.0f, 0.0f});
            const float first_length = first_axis.length<double, float>();
            const float second_length = second_axis.length<double, float>();
            basis.first_axis = first_axis * (influence.distance / first_length);
            basis.second_axis = second_axis * (influence.distance / second_length);
        }
    }
    if (vegetation_kind == SphereRenderVegetationKind::Tree)
    {
        const auto dead_radius = parameters.floatValue(name, "deadRadius");
        const auto phase_multiplier = parameters.floatValue(name, "phaseMul");
        if (!dead_radius || !phase_multiplier)
            throw std::runtime_error(std::string("Missing deadRadius or phaseMul for tree model '") + name + "'");
        prepareTree(*dead_radius, *phase_multiplier);
    }
}

void SphereRenderModel::failDecode(std::string_view model_name, std::string_view reason)
{
    throw std::runtime_error("Cannot load model '" + std::string(model_name) + "': " + std::string(reason));
}

std::uint8_t SphereRenderModel::readModelByte(std::string_view model_name, std::span<const std::uint8_t> bytes, std::size_t offset)
{
    if (offset >= bytes.size())
        failDecode(model_name, "truncated MDL field");
    return bytes[offset];
}

std::uint16_t SphereRenderModel::readModelWord(std::string_view model_name, std::span<const std::uint8_t> bytes, std::size_t offset)
{
    return readModelByte(model_name, bytes, offset) | (readModelByte(model_name, bytes, offset + 1u) << 8u);
}

std::uint32_t SphereRenderModel::readModelInteger(std::span<const std::uint8_t> bytes, std::size_t offset)
{
    return SferaBinary::readLittleEndian<std::uint32_t>(bytes.data() + offset);
}

float SphereRenderModel::readModelReal(std::string_view model_name, std::span<const std::uint8_t> bytes, std::size_t offset)
{
    const float value = SferaBinary::floatFromBits(readModelInteger(bytes, offset));
    if (!std::isfinite(value))
        failDecode(model_name, "non-finite MDL coordinate");
    return value;
}

SferaVec3F SphereRenderModel::readModelPoint(std::string_view model_name, std::span<const std::uint8_t> bytes, std::size_t offset)
{
    return {readModelReal(model_name, bytes, offset), readModelReal(model_name, bytes, offset + 4u), readModelReal(model_name, bytes, offset + 8u)};
}

std::size_t SphereRenderModel::takeModelSection(std::string_view model_name, std::span<const std::uint8_t> bytes, std::size_t &cursor, std::size_t count, std::size_t width)
{
    if (count > (bytes.size() - cursor) / width)
        failDecode(model_name, "truncated MDL section");
    const std::size_t begin = cursor;
    cursor += count * width;
    return begin;
}

void SphereRenderModel::visitDecodedBone(std::string_view model_name, const SphereRenderModel &model, std::vector<std::uint8_t> &visitation, std::size_t index)
{
    if (visitation[index] == 1)
        failDecode(model_name, "cyclic bone hierarchy");
    if (visitation[index] == 2)
        return;
    visitation[index] = 1;
    const auto &bone = model.bones[index];
    for (std::size_t child = 0; child < bone.child_count; ++child)
        visitDecodedBone(model_name, model, visitation, model.child_bones[bone.first_child + child]);
    visitation[index] = 2;
}

void SphereRenderModelParameters::load(const std::string &path)
{
    if (initialized_)
    {
        CSphereError error;
        error.write("CObjParamManager::Open: object already initialized");
    }
    try
    {
        const auto bytes = g_sfera_files.readAll(path);
        parse(SferaText::fromBytes(bytes));
    }
    catch (const std::exception &exception)
    {
        CSphereError error;
        error.write(exception.what());
        throw;
    }
}

void SphereRenderModelParameters::parse(std::string_view source)
{
    source = source.substr(0, source.find('\0'));
    std::vector<SphereRenderModelParametersObject> parsed;
    while (!source.empty() && source.front() != '\0')
    {
        const auto end = source.find_first_of("\r\n\0", 0, 3);
        auto line = source.substr(0, end);
        source = end == std::string_view::npos ? std::string_view{} : source.substr(end + 1);
        if (line.empty() || line.front() == ' ')
            continue;
        const auto separator = line.find(' ');
        if (separator == std::string_view::npos)
            throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
        SphereRenderModelParametersObject object;
        object.name = line.substr(0, separator);
        line.remove_prefix(separator + 1);
        while (!line.empty())
        {
            while (!line.empty() && line.front() == ' ')
                line.remove_prefix(1);
            if (line.empty())
                throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
            const auto comma = line.find(',');
            auto item = line.substr(0, comma);
            line = comma == std::string_view::npos ? std::string_view{} : line.substr(comma + 1);
            const auto name_end = item.find_first_of(" =");
            SphereRenderModelParametersParameter parameter;
            parameter.name = item.substr(0, name_end);
            if (parameter.name.empty())
                throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
            if (name_end != std::string_view::npos)
            {
                item.remove_prefix(name_end);
                while (!item.empty() && item.front() == ' ')
                    item.remove_prefix(1);
                if (!item.empty())
                {
                    if (item.front() != '=')
                        throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
                    item.remove_prefix(1);
                    while (!item.empty() && item.front() == ' ')
                        item.remove_prefix(1);
                    parameter.value = std::string(item);
                }
            }
            object.parameters.push_back(std::move(parameter));
        }
        parsed.push_back(std::move(object));
    }
    objects_ = std::move(parsed);
    initialized_ = true;
}

void SphereRenderModelParameters::clear()
{
    objects_.clear();
    initialized_ = false;
}

const SphereRenderModelParametersObject *SphereRenderModelParameters::findObject(std::string_view name) const
{
    for (const auto &object : objects_)
        if (SferaText::asciiEqual(object.name, name))
            return &object;
    return nullptr;
}

const SphereRenderModelParametersParameter *SphereRenderModelParameters::findParameter(std::string_view model, std::string_view parameter) const
{
    const auto *object = findObject(model);
    if (object == nullptr)
        return nullptr;
    for (const auto &value : object->parameters)
        if (SferaText::asciiEqual(value.name, parameter))
            return &value;
    return nullptr;
}



std::optional<std::string_view> SphereRenderModelParameters::stringValue(std::string_view model, std::string_view parameter) const
{
    const auto *value = findParameter(model, parameter);
    if (value == nullptr)
        return std::nullopt;
    if (!value->value)
        throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
    return *value->value;
}

template <class Number> std::optional<Number> SphereRenderModelParameters::modelNumber(std::optional<std::string_view> source)
{
    if (!source)
        return std::nullopt;
    auto text = *source;
    while (!text.empty() && SferaText::isSpace(text.front()))
        text.remove_prefix(1);
    if (text.starts_with('+'))
        text.remove_prefix(1);
    Number value{};
    if (text.empty() || std::from_chars(text.data(), text.data() + text.size(), value).ec != std::errc{})
        throw std::runtime_error("CObjParamManager::GetObjParam: wrong file format");
    return value;
}

std::optional<float> SphereRenderModelParameters::floatValue(std::string_view model, std::string_view parameter) const
{
    return SphereRenderModelParameters::modelNumber<float>(stringValue(model, parameter));
}

std::optional<int> SphereRenderModelParameters::intValue(std::string_view model, std::string_view parameter) const
{
    return SphereRenderModelParameters::modelNumber<int>(stringValue(model, parameter));
}

void SphereRenderModelRepository::initialize()
{
    clear();
    parameters.load("models\\mdlparam.txt");
}

void SphereRenderModelRepository::addFolder(const std::string &directory)
{
    if (directory.empty())
        return;
    const std::filesystem::path folder(directory);
    std::error_code error;
    for (std::filesystem::directory_iterator iterator(folder, error), end; !error && iterator != end; iterator.increment(error))
    {
        if (!iterator->is_regular_file(error) || error || SferaText::resourceKey(iterator->path().extension().string()) != ".mdl")
            continue;
        const auto name = iterator->path().stem().string();
        const auto index = entries.size();
        entries.push_back({name, directory, nullptr, {}});
        names.try_emplace(SferaText::resourceKey(name), index);
    }
}

void SphereRenderModelRepository::finishRegistration()
{
    if (entries.size() >= 5000u)
        throw std::length_error("Model repository exceeds the model ID range");
}

std::size_t SphereRenderModelRepository::find(std::string_view name) const
{
    if (name.empty())
        return invalid_index;
    const auto found = names.find(SferaText::resourceKey(name));
    return found == names.end() ? invalid_index : found->second;
}

std::shared_ptr<SphereRenderModel> SphereRenderModelRepository::model(std::size_t index)
{
    if (index >= entries.size())
        throw std::out_of_range("Model repository: invalid model ID");
    auto &entry = entries[index];
    entry.last_used = std::chrono::steady_clock::now();
    if (entry.model == nullptr)
        entry.model = SphereRenderModel::load(entry.name, entry.directory, parameters, g_sfera_materials);
    if (++requests_since_scan > 100000u)
    {
        requests_since_scan = 0u;
        evictUnused();
    }
    return entry.model;
}

void SphereRenderModelRepository::releaseModels()
{
    for (auto &entry : entries)
    {
        if (SphereRenderModelPose::active_model == entry.model.get())
            SphereRenderModelPose::active_model = nullptr;
        entry.model.reset();
    }
}

void SphereRenderModelRepository::evictUnused(std::chrono::steady_clock::time_point now)
{
    if (entries.empty())
        return;
    auto &entry = entries[scan_index];
    if (entry.model != nullptr && entry.model.use_count() == 1 && now - entry.last_used > std::chrono::minutes(15))
    {
        if (SphereRenderModelPose::active_model == entry.model.get())
            SphereRenderModelPose::active_model = nullptr;
        entry.model.reset();
    }
    scan_index = (scan_index + 1u) % entries.size();
}

void SphereRenderModelRepository::clear()
{
    releaseModels();
    entries.clear();
    names.clear();
    parameters.clear();
    requests_since_scan = 0u;
    scan_index = 0u;
}

void SphereRenderMaterialLibrary::clear()
{
    materials_.reset();
    default_index_.reset();
}

const SphereRenderMaterial *SphereRenderMaterialLibrary::find(std::string_view name) const
{
    if (!materials_)
        return nullptr;
    for (const auto &material : *materials_)
        if (SferaText::asciiEqual(material.name, name))
            return &material;
    return nullptr;
}




void SphereRenderMaterialLibrary::load(const std::string &binary_path, const std::string &configuration_path)
{
    try
    {
        SphereRenderConfigDocument::setStorageMode(SphereRenderConfigDocumentStorageMode::Plain);
        const auto configuration = SphereRenderConfigDocument::open(configuration_path);
        const auto count_configured = configuration.arraySize("materials").value_or(0);
        const auto bytes = g_sfera_files.readAll(binary_path);
        std::size_t cursor = 0;

        const auto count = readMaterialInteger(bytes, cursor);
        if (count > 65536 || count > (bytes.size() - cursor) / 654)
            throw std::runtime_error("MaterialLibrary: invalid material count");
        std::vector<SphereRenderMaterial> materials;
        materials.reserve(count);
        std::optional<std::size_t> default_index = count == 0 ? std::nullopt : std::optional<std::size_t>(0);
        for (std::size_t index = 0; index < count; ++index)
        {
            SphereRenderMaterial material;
            material.name = readMaterialName(bytes, cursor);
            if (SferaText::asciiEqual(material.name, "default"))
                default_index = index;
            const auto texture_count = readMaterialInteger(bytes, cursor);
            if (texture_count > 16)
                throw std::runtime_error("MaterialLibrary: invalid texture count");
            material.textures.reserve(texture_count);
            for (std::uint32_t texture = 0; texture < 16; ++texture)
            {
                if (texture >= texture_count)
                {
                    takeMaterialBytes(bytes, cursor, 36);
                    continue;
                }
                auto texture_name = readMaterialName(bytes, cursor);
                if (texture_name.size() < 2)
                    throw std::runtime_error("MaterialLibrary: invalid texture name");
                texture_name.resize(texture_name.size() - 2);
                material.textures.push_back(g_sfera_textures.find(texture_name));
            }
            for (auto &channel : material.color)
                channel = SferaBinary::floatFromBits(readMaterialInteger(bytes, cursor));
            takeMaterialBytes(bytes, cursor, 22);
            for (std::size_t configured = 0; configured < count_configured; ++configured)
            {
                const auto *record = configuration.objectAt("materials", configured);
                if (record == nullptr)
                    throw std::runtime_error("Can't go into material struct " + std::to_string(configured));
                const auto configured_name = record->text("name");
                if (!configured_name)
                    throw std::runtime_error("Field name is absent in material " + std::to_string(configured));
                if (!SferaText::asciiEqual(*configured_name, material.name))
                    continue;
                const auto red = record->realAt("rgbRand", 0);
                if (red)
                {
                    const auto green = record->realAt("rgbRand", 1);
                    const auto blue = record->realAt("rgbRand", 2);
                    if (!green || !blue)
                        throw std::runtime_error("Wrong format of rgbRand in material struct " + std::to_string(configured));
                    material.colorVariation = {*red, *green, *blue};
                    material.hasColorVariation = true;
                }
                break;
            }
            materials.push_back(std::move(material));
        }
        materials_ = std::make_shared<const std::vector<SphereRenderMaterial>>(std::move(materials));
        default_index_ = default_index;
    }
    catch (const std::exception &exception)
    {
        CSphereError error;
        error.write(exception.what());
        throw;
    }
}

std::span<const std::uint8_t> SphereRenderMaterialLibrary::takeMaterialBytes(std::span<const std::uint8_t> bytes, std::size_t &cursor, std::size_t length)
{
    if (length > bytes.size() - cursor)
        throw std::runtime_error("MaterialLibrary: truncated material file");
    const auto result = std::span<const std::uint8_t>(bytes).subspan(cursor, length);
    cursor += length;
    return result;
}

std::uint32_t SphereRenderMaterialLibrary::readMaterialInteger(std::span<const std::uint8_t> bytes, std::size_t &cursor)
{
    const auto data = takeMaterialBytes(bytes, cursor, 4);
    return SferaBinary::readLittleEndian<std::uint32_t>(data.data());
}

std::string SphereRenderMaterialLibrary::readMaterialName(std::span<const std::uint8_t> bytes, std::size_t &cursor)
{
    const auto data = takeMaterialBytes(bytes, cursor, 36);
    const auto end = std::find(data.begin(), data.end(), std::uint8_t{});
    if (end == data.end())
        throw std::runtime_error("MaterialLibrary: unterminated material or texture name");
    return std::string(data.begin(), end);
}
