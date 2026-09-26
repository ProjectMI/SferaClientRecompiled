#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <filesystem>
#include <limits>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <utility>

#include "graphics/d3d9/Device.h"
#include "numeric/Numeric.h"
#include "render/GraphicsRuntime.h"
#include "render/TextureAccess.h"
#include "render/Textures.h"
#include "resources/FileResources.h"
#include "resources/TextureRepository.h"
#include "text/Text.h"
#include "ui/UiTypes.h"

void SphereRenderTextureRepository::initialize()
{
    clear();
    initialized = true;
}

void SphereRenderTextureRepository::addFolder(const std::string &directory)
{
    if (directory.empty())
        return;
    const std::filesystem::path folder(directory);
    std::error_code error;
    for (std::filesystem::directory_iterator iterator(folder, error), end; !error && iterator != end; iterator.increment(error))
    {
        if (!iterator->is_regular_file(error) || error || SferaText::resourceKey(iterator->path().extension().string()) != ".dds")
            continue;
        auto name = iterator->path().filename().string();
        name.resize(name.find('.'));
        if (name.empty())
            continue;
        if (entries.size() >= std::size_t{std::numeric_limits<int>::max()})
            throw std::length_error("Resource ID range exhausted");
        const int index = SferaNumeric::signedWord(SferaNumeric::lowWord(entries.size()));
        SphereRenderTextureRepositoryEntry entry;
        entry.name = name;
        entry.filename = iterator->path();
        entries.push_back(std::move(entry));
        names.insert_or_assign(SferaText::resourceKey(name), index);
    }
}


void SphereRenderTextureRepository::clear()
{
    entries.clear();
    names.clear();
    default_texture = -1;
    initialized = false;
}

int SphereRenderTextureRepository::find(std::string_view name) const
{
    // The existing texture lookup contract uses entry zero for an unknown name.
    if (!initialized || name.empty())
        return 0;
    const auto found = names.find(SferaText::resourceKey(name));
    return found == names.end() ? 0 : found->second;
}

SphereRenderTextureRepositoryEntry *SphereRenderTextureRepository::resolve(int index)
{
    if (index < 0 || index >= entries.size())
        index = default_texture;
    return index >= 0 && index < entries.size() ? &entries[index] : nullptr;
}

IDirect3DBaseTexture9 *SphereRenderTextureRepository::resource(int index)
{
    auto *entry = resolve(index);
    if (entry == nullptr)
        return nullptr;
    if (entry->texture != nullptr)
        return entry->texture.Get();
    const auto bytes = g_sfera_files.readAll(entry->filename.string());
    load(*entry, bytes);
    return entry->texture.Get();
}

SphereUITextExtent SphereRenderTextureRepository::size(int index)
{
    auto *entry = resolve(index);
    if (entry == nullptr || resource(index) == nullptr)
        return {};
    D3DSURFACE_DESC description{};
    HRESULT result = E_NOINTERFACE;
    if (entry->texture->GetType() == D3DRTYPE_CUBETEXTURE)
    {
        Microsoft::WRL::ComPtr<IDirect3DCubeTexture9> texture;
        result = entry->texture.As(&texture);
        if (SUCCEEDED(result))
            result = texture->GetLevelDesc(0u, &description);
    }
    else
    {
        Microsoft::WRL::ComPtr<IDirect3DTexture9> texture;
        result = entry->texture.As(&texture);
        if (SUCCEEDED(result))
            result = texture->GetLevelDesc(0u, &description);
    }
    return SUCCEEDED(result) ? SphereUITextExtent{SferaNumeric::signedWord(description.Width), SferaNumeric::signedWord(description.Height)} : SphereUITextExtent{};
}

bool SphereRenderTextureRepository::hasAlpha(int index)
{
    resource(index);
    const auto *entry = resolve(index);
    return entry != nullptr && entry->has_alpha;
}

void SphereRenderTextureRepository::load(SphereRenderTextureRepositoryEntry &entry, std::span<const std::uint8_t> bytes)
{
    if (g_sfera_graphics_runtime.d3d_runtime == nullptr)
        return;
    auto &runtime = *g_sfera_graphics_runtime.d3d_runtime;
    auto loaded = SferaTextureUpload::fromDds(runtime.native_device.Get(), bytes);
    runtime.last_hresult = loaded.status;
    if (SUCCEEDED(loaded.status))
    {
        entry.texture = std::move(loaded.texture);
        entry.has_alpha = loaded.has_alpha;
    }
}

int SferaTextureAccess::find(std::string_view name)
{
    return g_sfera_textures.find(name);
}

IDirect3DBaseTexture9 *SferaTextureAccess::resource(int index)
{
    return g_sfera_textures.resource(index);
}

SphereUITextExtent SferaTextureAccess::size(int index)
{
    return g_sfera_textures.size(index);
}

bool SferaTextureAccess::hasAlpha(int index)
{
    return g_sfera_textures.hasAlpha(index);
}
