#pragma once

#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <filesystem>
#include <span>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include <wrl/client.h>

struct SferaD3D9TextureLoadResult;
class SphereRenderTextureRepository;
struct SphereRenderTextureRepositoryEntry;
struct SphereUITextExtent;

struct SphereRenderTextureRepositoryEntry
{
    std::string name;
    std::filesystem::path filename;
    Microsoft::WRL::ComPtr<IDirect3DBaseTexture9> texture;
    bool has_alpha = false;
};

class SphereRenderTextureRepository
{
  public:
    void initialize();
    void addFolder(const std::string &directory);
    void finishRegistration()
    {
        default_texture = find("default");
    }
    void clear();
    int find(std::string_view name) const;
    IDirect3DBaseTexture9 *resource(int index);
    SphereUITextExtent size(int index);
    bool hasAlpha(int index);
    std::size_t count() const
    {
        return entries.size();
    }
    int defaultTexture() const
    {
        return default_texture;
    }

  private:
    std::vector<SphereRenderTextureRepositoryEntry> entries;
    std::unordered_map<std::string, int> names;
    int default_texture = -1;
    bool initialized = false;
    SphereRenderTextureRepositoryEntry *resolve(int index);
    void load(SphereRenderTextureRepositoryEntry &entry, std::span<const std::uint8_t> bytes);

  private:
    friend struct SphereRenderTextureRepositoryEntry;
};

extern SphereRenderTextureRepository g_sfera_textures;
