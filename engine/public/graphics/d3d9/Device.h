#pragma once

#include <windows.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>
#include <wrl/client.h>

#include "graphics/DisplayMode.h"
#include "math/Matrix.h"
#include "text/Text.h"

struct SphereRenderPositionNormalUvVertex;
struct SphereRenderPositionColorUvVertex;

class CD3D9Device;
class UnmanagedResourceBase;
class UnmanagedResourceTexture;

class UnmanagedResourceBase
{
  public:
    virtual ~UnmanagedResourceBase();
    virtual void restoreResource() = 0;
    virtual void releaseResource() = 0;
    UnmanagedResourceBase(const UnmanagedResourceBase &) = delete;
    UnmanagedResourceBase &operator=(const UnmanagedResourceBase &) = delete;

  protected:
    explicit UnmanagedResourceBase(CD3D9Device &device, D3DPOOL pool);
    CD3D9Device *device;

  private:
    friend class CD3D9Device;
    bool registered;
};

class UnmanagedResourceTexture final : public UnmanagedResourceBase
{
  public:
    Microsoft::WRL::ComPtr<IDirect3DTexture9> native_texture;
    UnmanagedResourceTexture(CD3D9Device &device, std::uint32_t width, std::uint32_t height, std::uint32_t levels, std::uint32_t usage, D3DFORMAT format, D3DPOOL pool);
    void restoreResource() override;
    void releaseResource() override
    {
        native_texture.Reset();
    }

  private:
    const std::uint32_t width;
    const std::uint32_t height;
    const std::uint32_t levels;
    const std::uint32_t usage;
    const D3DFORMAT format;
    const D3DPOOL pool;
};

template <class Element> class DynamicStream;

template <class Element> using DynamicStreamBuffer = std::conditional_t<std::is_same_v<Element, std::uint16_t>, IDirect3DIndexBuffer9, IDirect3DVertexBuffer9>;

template <class Element> class DynamicStreamMapping
{
  public:
    DynamicStreamMapping(DynamicStreamMapping &&other) noexcept;
    DynamicStreamMapping &operator=(DynamicStreamMapping &&other) noexcept;
    DynamicStreamMapping(const DynamicStreamMapping &) = delete;
    DynamicStreamMapping &operator=(const DynamicStreamMapping &) = delete;
    ~DynamicStreamMapping();
    explicit operator bool() const noexcept
    {
        return buffer_ != nullptr;
    }
    Element *data() const noexcept
    {
        return data_;
    }
    Element &operator[](std::size_t index) const
    {
        return data_[index];
    }
    std::size_t first() const noexcept
    {
        return first_;
    }
    std::size_t size() const noexcept
    {
        return count_;
    }
    DynamicStreamBuffer<Element> *buffer() const noexcept
    {
        return buffer_.Get();
    }
    void unlock();

  private:
    friend class DynamicStream<Element>;
    DynamicStreamMapping(CD3D9Device &device, Microsoft::WRL::ComPtr<DynamicStreamBuffer<Element>> buffer, std::size_t first, std::size_t count, Element *data);
    CD3D9Device *device_;
    Microsoft::WRL::ComPtr<DynamicStreamBuffer<Element>> buffer_;
    std::size_t first_;
    std::size_t count_;
    Element *data_;
};

template <class Element> class DynamicStream final : public UnmanagedResourceBase
{
    static constexpr bool indexed = std::is_same_v<Element, std::uint16_t>;

  public:
    explicit DynamicStream(CD3D9Device &device);
    void reserve(std::size_t count);
    DynamicStreamMapping<Element> lock(std::size_t count);
    void discard() noexcept
    {
        discard_next_ = true;
    }
    void restoreResource() override;
    void releaseResource() override;
    std::size_t capacity() const noexcept
    {
        return capacity_;
    }
    DynamicStreamBuffer<Element> *buffer() const noexcept
    {
        return buffer_.Get();
    }

  private:
    Microsoft::WRL::ComPtr<DynamicStreamBuffer<Element>> buffer_;
    std::size_t capacity_ = 0;
    std::size_t position_ = 0;
    bool discard_next_ = false;
};

class RenderTargetScope;

class RenderTargetScope
{
  public:
    RenderTargetScope(CD3D9Device &device, IDirect3DTexture9 &target);
    RenderTargetScope(RenderTargetScope &&other) noexcept;
    RenderTargetScope(const RenderTargetScope &) = delete;
    RenderTargetScope &operator=(const RenderTargetScope &) = delete;
    ~RenderTargetScope();
    HRESULT restore() noexcept;

  private:
    CD3D9Device *device_;
    Microsoft::WRL::ComPtr<IDirect3DSurface9> color_;
    Microsoft::WRL::ComPtr<IDirect3DSurface9> depth_;
    D3DVIEWPORT9 viewport_{};

  private:
    static void recordFailure(HRESULT &result, HRESULT status);
};

class CPostEffectsMgr;
struct CPostEffectsMgrScreenVertex;

struct CPostEffectsMgrScreenVertex
{
    float x;
    float y;
    float z;
    float rhw;
    float u;
    float v;
    float u2;
    float v2;
};

class CPostEffectsMgr
{
  public:
    bool enabled = false;
    explicit CPostEffectsMgr(CD3D9Device &device);
    ~CPostEffectsMgr();
    CPostEffectsMgr(const CPostEffectsMgr &) = delete;
    CPostEffectsMgr &operator=(const CPostEffectsMgr &) = delete;
    void restoreResources();
    void releaseResources();
    void setEnabled(bool value);
    void beginCapture();
    void cancelCapture() noexcept
    {
        capture.reset();
    }
    void compose();

  private:
    CD3D9Device &device;
    std::optional<RenderTargetScope> capture;
    Microsoft::WRL::ComPtr<IDirect3DTexture9> scene_texture;
    Microsoft::WRL::ComPtr<IDirect3DTexture9> blur_texture;
    Microsoft::WRL::ComPtr<IDirect3DTexture9> temporary_texture;
    Microsoft::WRL::ComPtr<IDirect3DVertexDeclaration9> vertex_declaration;
    void configureRenderState();

    void drawQuad(std::uint32_t width, std::uint32_t height);
    void renderToTexture(IDirect3DTexture9 *target);
    void blur();

  private:
    friend struct CPostEffectsMgrScreenVertex;

  private:
    Microsoft::WRL::ComPtr<IDirect3DTexture9> createRenderTexture(std::uint32_t width, std::uint32_t height);
};

class CShaderMgr;
struct CShaderMgrVariant;
struct CShaderMgrWaterParameters;

struct CShaderMgrWaterParameters
{
    float gradient = 0.0f;
    float specular = 0.0f;
    float reflection = 0.0f;
};

struct CShaderMgrVariant
{
    std::string filename;
    Microsoft::WRL::ComPtr<IDirect3DPixelShader9> pixel_shader;
    std::optional<UINT> alpha_register;
    std::optional<UINT> down_filter_register;
    std::optional<UINT> water_gradient_register;
    std::optional<UINT> water_specular_register;
    std::optional<UINT> water_reflection_register;
};

class CShaderMgr
{
  public:
    std::map<std::pair<bool, std::array<std::uint8_t, 8>>, CShaderMgrVariant> variants;
    std::string vertex_directory;
    std::string pixel_directory;
    std::array<float, 512> wave_samples;
    std::array<float, 64> downsample_offsets;
    CShaderMgr(CD3D9Device &device, std::string vertex_directory, std::string pixel_directory);
    CShaderMgr(const CShaderMgr &) = delete;
    CShaderMgr &operator=(const CShaderMgr &) = delete;
    static std::pair<bool, std::array<std::uint8_t, 8>> instanceCode(std::string_view filename, bool pixel);
    static std::array<float, 512> makeWaveSamples();
    static std::array<float, 64> makeDownsampleOffsets(float width, float height);
    static CShaderMgrWaterParameters waterParameters(float environment, float height);
    void loadFolder(const std::string &directory, bool pixel);
    void setPixelShader(std::uint32_t group);

  private:
    CD3D9Device &device;
    CShaderMgrVariant &loadVariant(const std::pair<bool, std::array<std::uint8_t, 8>> &code);

  private:
    friend struct CShaderMgrWaterParameters;
    friend struct CShaderMgrVariant;

  private:
    static std::optional<UINT> resolveConstant(const std::unordered_map<std::string, int, SferaTextHash, std::equal_to<>> &constants, std::string_view name);
    void setFloatConstant(std::optional<UINT> shader_register, float value);
    static std::unordered_map<std::string, int, SferaTextHash, std::equal_to<>> readShaderConstants(std::span<const std::uint8_t> code);
};

struct CD3D9DeviceResetGuard;

enum CD3D9DeviceDrawFlag : std::uint32_t
{
    CD3D9Devicedisable_clipping = 1u,
    CD3D9Devicetwo_sided = 4u,
    CD3D9Devicelighting = 16u
};

class CD3D9Device
{
    std::vector<UnmanagedResourceBase *> unmanaged_resources;

  public:
    Microsoft::WRL::ComPtr<IDirect3D9> api;
    Microsoft::WRL::ComPtr<IDirect3DDevice9> native_device;
    D3DPRESENT_PARAMETERS presentation{};
    D3DCAPS9 capabilities{};
    HRESULT last_hresult = S_OK;
    SferaMatrix4x4F world_transform{};
    Microsoft::WRL::ComPtr<IDirect3DQuery9> sync_query;
    bool supports_post_effects = false;
    std::vector<SphereUIDisplayMode> display_modes;
    std::unique_ptr<CShaderMgr> shaders;
    std::unique_ptr<CPostEffectsMgr> post_effects;
    std::unique_ptr<UnmanagedResourceTexture> reflection_target;
    std::unique_ptr<UnmanagedResourceTexture> minimap_target;
    DynamicStream<SphereRenderPositionNormalUvVertex> model_vertices;
    DynamicStream<SphereRenderPositionColorUvVertex> colored_vertices;
    DynamicStream<std::uint16_t> indices_primary;
    DynamicStream<std::uint16_t> indices_secondary;
    D3DTEXTUREFILTERTYPE min_filter = D3DTEXF_ANISOTROPIC;
    D3DTEXTUREFILTERTYPE mag_filter = D3DTEXF_LINEAR;
    D3DTEXTUREFILTERTYPE mip_filter = D3DTEXF_LINEAR;
    CD3D9Device();
    ~CD3D9Device();
    CD3D9Device(const CD3D9Device &) = delete;
    CD3D9Device &operator=(const CD3D9Device &) = delete;
    HRESULT checkResult(HRESULT result, std::string_view operation);
    void initialize(HWND window, std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits, bool windowed);
    void enumerateDisplayModes(bool windowed);
    bool supportsDisplayMode(std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits) const;
    void selectBackBufferFormat(const D3DDISPLAYMODE &display, bool windowed, std::uint32_t &width, std::uint32_t &height, D3DFORMAT &format);
    D3DFORMAT selectDepthFormat(D3DFORMAT adapter_format, D3DFORMAT back_buffer_format) const;
    void initializeRenderState();
    void applyFiltering();
    void setTransform(D3DTRANSFORMSTATETYPE kind, const SferaMatrix4x4F &matrix);
    void setAlphaBlending(D3DBLEND source, D3DBLEND destination);
    void setColorOperation(std::uint32_t stage, D3DTEXTUREOP operation, std::uint32_t first, std::uint32_t second);
    void setAlphaOperation(std::uint32_t stage, D3DTEXTUREOP operation, std::uint32_t first, std::uint32_t second);
    void setWhiteMaterial(float alpha);
    void applyDrawState(std::uint32_t flags);
    static UINT primitiveCount(D3DPRIMITIVETYPE topology, UINT elements);
    void drawBuffer(IDirect3DVertexBuffer9 *vertices, D3DPRIMITIVETYPE topology, std::uint32_t flags, std::ptrdiff_t base_vertex, std::size_t vertex_count, IDirect3DIndexBuffer9 *indices,
                    std::size_t index_count, std::size_t start_index, std::size_t stride);
    void drawVertices(D3DPRIMITIVETYPE topology, std::uint32_t flags, const void *vertices, std::size_t vertex_count, const std::uint16_t *indices, std::size_t index_count, std::size_t stride);
    bool beginScene();
    HRESULT endScene() noexcept;
    bool present();
    bool sceneActive() const noexcept
    {
        return scene_open_;
    }
    void releaseResources();
    void restoreResources();
    void waitForGpu();
    UnmanagedResourceTexture &minimapTexture();

  private:
    friend class UnmanagedResourceBase;
    bool scene_open_ = false;
    bool resetting_ = false;
    DWORD owner_thread_ = 0;

  private:
    static std::tuple<unsigned, std::uint64_t, unsigned> rankDisplayMode(const SphereUIDisplayMode &mode, std::uint32_t width, std::uint32_t height, const D3DDISPLAYMODE &display,
                                                                         std::uint32_t depth_bits);
    HRESULT createNativeDevice(const D3DPRESENT_PARAMETERS &requested, D3DPRESENT_PARAMETERS &accepted, Microsoft::WRL::ComPtr<IDirect3DDevice9> &created, HWND window, DWORD behavior);
};

struct CD3D9DeviceResetGuard
{
    bool &value;
    ~CD3D9DeviceResetGuard()
    {
        value = false;
    }
};

class RenderStateScope;

enum class RenderStateScopeFailurePolicy
{
    Throw,
    Skip
};

class RenderStateScope
{
  public:
    explicit RenderStateScope(CD3D9Device &device, RenderStateScopeFailurePolicy failure = RenderStateScopeFailurePolicy::Throw);
    explicit operator bool() const noexcept
    {
        return state_.Get() != nullptr;
    }
    RenderStateScope(const RenderStateScope &) = delete;
    RenderStateScope &operator=(const RenderStateScope &) = delete;
    ~RenderStateScope() noexcept;

  private:
    CD3D9Device &device_;
    SferaMatrix4x4F world_transform_;
    std::array<bool, 31> active_lights_;
    std::size_t active_light_count_;
    std::uint32_t sprite_render_mode_;
    Microsoft::WRL::ComPtr<IDirect3DStateBlock9> state_;
};

class SceneScope;

class SceneScope
{
  public:
    explicit SceneScope(CD3D9Device &device) : device_(device.beginScene() ? &device : nullptr)
    {
    }
    SceneScope(const SceneScope &) = delete;
    SceneScope &operator=(const SceneScope &) = delete;
    ~SceneScope()
    {
        if (device_)
            device_->endScene();
    }
    explicit operator bool() const noexcept
    {
        return device_ != nullptr;
    }
    void finish();

  private:
    CD3D9Device *device_;
};

class TextureMapping;

class TextureMapping
{
  public:
    TextureMapping(IDirect3DTexture9 *texture, UINT level = 0, DWORD flags = 0) noexcept;
    TextureMapping(TextureMapping &&other) noexcept;
    TextureMapping(const TextureMapping &) = delete;
    TextureMapping &operator=(const TextureMapping &) = delete;
    ~TextureMapping();
    HRESULT status() const noexcept
    {
        return status_;
    }
    const D3DSURFACE_DESC &description() const noexcept
    {
        return description_;
    }
    const D3DLOCKED_RECT &rectangle() const noexcept
    {
        return rectangle_;
    }
    std::span<std::uint8_t> row(std::size_t index, std::size_t bytes) const noexcept;
    HRESULT unlock() noexcept;
    HRESULT copyRows(std::span<const std::byte> source, std::size_t rowBytes, std::size_t rows) noexcept;

  private:
    Microsoft::WRL::ComPtr<IDirect3DTexture9> texture_;
    UINT level_;
    D3DSURFACE_DESC description_{};
    D3DLOCKED_RECT rectangle_{};
    HRESULT status_ = D3DERR_INVALIDCALL;
    bool locked_ = false;
};
