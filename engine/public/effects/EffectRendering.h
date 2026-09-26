#pragma once

#include <windows.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <d3d9types.h>
#include <optional>
#include <vector>

#include "math/Vector.h"

struct SphereRenderPositionColorUvVertex;

struct SferaEffectRenderSlot;

struct SferaEffectRenderSlot
{
    SferaVec3F position[4];
    std::uint32_t color[4][4];
    float uv[4][2];
    int resource_id;
    int self_illumination;
    bool additive;
    bool custom_uv;
};

class CD3D9Device;
class EffectRendering;
struct EffectRenderingParticleBatch;

struct EffectRenderingParticleBatch
{
    std::size_t first_index;
    std::size_t index_count;
    bool additive;
    int texture;
};

class EffectRendering
{
  public:
    static int ambientBrightness();
    static void renderState(CD3D9Device &device, D3DRENDERSTATETYPE state, DWORD value);
    static void samplerState(CD3D9Device &device, D3DSAMPLERSTATETYPE state, DWORD value);
    static void identityWorld(CD3D9Device &device);
};

template <class Element> class DynamicStreamMapping;
struct SferaEffectRenderStatistics
{
    bool enabled{};
    std::uint64_t budget_rejected{}, render_calls{}, submitted_quads{}, alpha_vertices{};
};
struct SferaEffectRenderState
{
    std::size_t render_slot_count{};
    std::array<std::uint16_t, 65536> particle_random_table{};
    SferaVec3F viewer_position{};
    std::vector<SferaEffectRenderSlot> render_slots;
    std::vector<std::size_t> render_order;
    float viewerDistance(const SferaVec3F &position) const;
    void drawFlare(int texture, int x, int y, int size, int alpha_level) const;
    void sortRenderSlots();
    void renderParticles(SferaEffectRenderStatistics &diagnostics);
    SferaEffectRenderSlot *acquireRenderSlot()
    {
        if (render_slot_count >= render_slots.size())
            return nullptr;
        return &render_slots[render_slot_count++];
    }
    void finalizeBillboard(SferaEffectRenderSlot &slot, const SferaVec3F &position, float size) const;

  private:
    static int visibilityAlpha(const SferaVec3F &position);
    static bool compareRenderSlots(const SferaEffectRenderSlot *slots, std::size_t left, std::size_t right);
    void flushParticles(SferaEffectRenderStatistics &diagnostics, CD3D9Device &device, DynamicStreamMapping<SphereRenderPositionColorUvVertex> &vertices,
                        std::vector<EffectRenderingParticleBatch> &batches, std::vector<std::uint16_t> &indices, std::optional<bool> &active_blend, int &bound_texture, std::size_t &vertex_count);
    static std::uint32_t scaleParticleColor(const SferaEffectRenderSlot &slot, std::size_t vertex, std::size_t channel, std::int64_t factor);
};

class SferaEffectHost
{
  public:
    virtual ~SferaEffectHost() = default;
    virtual SferaEffectRenderState &renderState() = 0;
    virtual void rejectRenderBudget() = 0;
    static SferaEffectHost &current();
    static void bind(SferaEffectHost &host)
    {
        instance = &host;
    }

  private:
    static SferaEffectHost *instance;
};
