#pragma once

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "render/Material.h"

class SphereRenderModel;

class SphereRenderModelParameters;
struct SphereRenderModelParametersObject;
struct SphereRenderModelParametersParameter;

struct SphereRenderModelParametersParameter
{
    std::string name;
    std::optional<std::string> value;
};

struct SphereRenderModelParametersObject
{
    std::string name;
    std::vector<SphereRenderModelParametersParameter> parameters;
};

class SphereRenderModelParameters
{
  public:
    void load(const std::string &path);
    void parse(std::string_view source);
    void clear();
    bool contains(std::string_view model, std::string_view parameter) const
    {
        return findParameter(model, parameter) != nullptr;
    }
    bool hasModel(std::string_view model) const
    {
        return findObject(model) != nullptr;
    }
    std::optional<float> floatValue(std::string_view model, std::string_view parameter) const;
    std::optional<int> intValue(std::string_view model, std::string_view parameter) const;
    std::optional<std::string_view> stringValue(std::string_view model, std::string_view parameter) const;

  private:
    const SphereRenderModelParametersObject *findObject(std::string_view name) const;
    const SphereRenderModelParametersParameter *findParameter(std::string_view model, std::string_view parameter) const;
    std::vector<SphereRenderModelParametersObject> objects_;
    bool initialized_ = false;

  private:
    friend struct SphereRenderModelParametersParameter;
    friend struct SphereRenderModelParametersObject;

  private:
    template <class Number> static std::optional<Number> modelNumber(std::optional<std::string_view> source);
};

class SphereRenderModelRepository;
struct SphereRenderModelRepositoryEntry;

struct SphereRenderModelRepositoryEntry
{
    std::string name;
    std::string directory;
    std::shared_ptr<SphereRenderModel> model;
    std::chrono::steady_clock::time_point last_used;
};

class SphereRenderModelRepository
{
  public:
    static constexpr std::size_t invalid_index = std::numeric_limits<std::size_t>::max();

    void initialize();
    void addFolder(const std::string &directory);
    void finishRegistration();
    std::size_t find(std::string_view name) const;
    std::shared_ptr<SphereRenderModel> model(std::size_t index);
    void releaseModels();
    void evictUnused(std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now());
    void clear();
    std::size_t count() const
    {
        return entries.size();
    }
    SphereRenderModelParameters parameters;

  private:
    std::vector<SphereRenderModelRepositoryEntry> entries;
    std::unordered_map<std::string, std::size_t> names;
    std::size_t requests_since_scan = 0;
    std::size_t scan_index = 0;

  private:
    friend struct SphereRenderModelRepositoryEntry;
};

extern SphereRenderModelRepository g_sfera_models;

class SphereRenderMaterialLibrary;

class SphereRenderMaterialLibrary
{
  public:
    void load(const std::string &binary_path, const std::string &configuration_path = "Models\\Materials.cfg");
    void clear();
    const SphereRenderMaterial *find(std::string_view name) const;
    const SphereRenderMaterial *at(std::size_t index) const
    {
        return materials_ && index < materials_->size() ? &(*materials_)[index] : nullptr;
    }
    const SphereRenderMaterial *defaultMaterial() const
    {
        return default_index_ ? at(*default_index_) : nullptr;
    }
    std::shared_ptr<const std::vector<SphereRenderMaterial>> snapshot() const noexcept
    {
        return materials_;
    }
    std::size_t size() const
    {
        return materials_ ? materials_->size() : 0u;
    }

  private:
    std::shared_ptr<const std::vector<SphereRenderMaterial>> materials_;
    std::optional<std::size_t> default_index_;

  private:
    static std::span<const std::uint8_t> takeMaterialBytes(std::span<const std::uint8_t> bytes, std::size_t &cursor, std::size_t length);
    static std::uint32_t readMaterialInteger(std::span<const std::uint8_t> bytes, std::size_t &cursor);
    static std::string readMaterialName(std::span<const std::uint8_t> bytes, std::size_t &cursor);
};

extern SphereRenderMaterialLibrary g_sfera_materials;

struct SphereRenderCharacterModelsSearchScope;

struct SphereRenderCharacterModelsSearchScope
{
    std::intptr_t handle;
    ~SphereRenderCharacterModelsSearchScope();
};
