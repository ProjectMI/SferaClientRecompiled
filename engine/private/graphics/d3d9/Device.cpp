#include <windows.h>
#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <d3d9.h>
#include <exception>
#include <filesystem>
#include <format>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#include "binary/Binary.h"
#include "diagnostics/Diagnostics.h"
#include "graphics/DisplayMode.h"
#include "graphics/d3d9/Device.h"
#include "lighting/LightRuntime.h"
#include "math/Matrix.h"
#include "numeric/Numeric.h"
#include "platform/FileMapping.h"
#include "render/GraphicsRuntime.h"
#include "render/VertexFormats.h"
#include "text/Text.h"
#include "ui/Rendering.h"

CD3D9Device::CD3D9Device() : model_vertices(*this), colored_vertices(*this), indices_primary(*this), indices_secondary(*this)
{
    api.Attach(Direct3DCreate9(D3D_SDK_VERSION));
    if (api == nullptr)
    {
        SferaEngineDiagnostics::fatal("CD3D9Device::CD3D9Device() => Direct3DCreate9() failed.");
    }
}

CD3D9Device::~CD3D9Device()
{
    endScene();
    post_effects.reset();
    shaders.reset();
    reflection_target.reset();
    minimap_target.reset();
    for (auto *resource : unmanaged_resources)
    {
        resource->releaseResource();
        resource->device = nullptr;
    }
    unmanaged_resources.clear();
}

HRESULT CD3D9Device::checkResult(HRESULT result, std::string_view operation)
{
    last_hresult = result;
    if (FAILED(result))
    {
        auto message = std::format("{} failed (HRESULT 0x{:08X})", operation, SferaNumeric::lowWord(result));
        SferaEngineDiagnostics::fatal(message);
    }
    return result;
}

void CD3D9Device::enumerateDisplayModes(bool windowed)
{
    if (!api)
        throw std::runtime_error("Graphics interface is unavailable");
    D3DDISPLAYMODE display{};
    checkResult(api->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &display), "GetAdapterDisplayMode");
    display_modes.clear();
    for (const D3DFORMAT format : {D3DFMT_R5G6B5, D3DFMT_X8R8G8B8})
    {
        const auto adapter_format = windowed ? display.Format : format;
        if (FAILED(api->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, adapter_format, format, windowed)) || selectDepthFormat(adapter_format, format) == D3DFMT_UNKNOWN)
            continue;
        const std::uint32_t depth_bits = format == D3DFMT_X8R8G8B8 ? 32u : 16u;
        const UINT count = api->GetAdapterModeCount(D3DADAPTER_DEFAULT, format);
        for (UINT index = 0u; index < count; ++index)
        {
            D3DDISPLAYMODE mode{};
            if (FAILED(api->EnumAdapterModes(D3DADAPTER_DEFAULT, format, index, &mode)))
                continue;
            if (mode.Width < 800u || mode.Height < 600u)
                continue;
            if (windowed && mode.Height >= display.Height)
                continue;
            if (!supportsDisplayMode(mode.Width, mode.Height, depth_bits))
                display_modes.push_back({mode.Width, mode.Height, depth_bits});
        }
        // Windowed back buffers are not restricted to enumerated fullscreen sizes.
        if (windowed && !supportsDisplayMode(800u, 600u, depth_bits))
            display_modes.push_back({800u, 600u, depth_bits});
    }
    if (display_modes.empty())
        throw std::runtime_error("No compatible Direct3D 9 display mode with a depth buffer was found");
}

bool CD3D9Device::supportsDisplayMode(std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits) const
{
    for (const auto &mode : display_modes)
    {
        if (mode.width == width && mode.height == height && mode.depth == depth_bits)
            return true;
    }
    return false;
}

void CD3D9Device::selectBackBufferFormat(const D3DDISPLAYMODE &display, bool windowed, std::uint32_t &width, std::uint32_t &height, D3DFORMAT &format)
{
    if (windowed)
    {
        const std::array candidates{format, display.Format, D3DFMT_X8R8G8B8, D3DFMT_R5G6B5};
        for (const auto candidate : candidates)
        {
            if (SUCCEEDED(api->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, display.Format, candidate, TRUE)) && selectDepthFormat(display.Format, candidate) != D3DFMT_UNKNOWN)
            {
                format = candidate;
                return;
            }
        }
        throw std::runtime_error("No compatible Direct3D 9 windowed back-buffer/depth-stencil combination was found");
    }
    if (display_modes.empty())
        throw std::runtime_error("No compatible Direct3D 9 fullscreen mode was found");
    const auto depth_bits = format == D3DFMT_R5G6B5 ? 16u : 32u;

    // Keep the requested size first, then the desktop size, then a real nearby mode.
    // A colour-depth fallback must select a mode enumerated for that same format.
    auto selected = display_modes.begin();
    for (auto candidate = std::next(selected); candidate != display_modes.end(); ++candidate)
    {
        if (rankDisplayMode(*candidate, width, height, display, depth_bits) < rankDisplayMode(*selected, width, height, display, depth_bits))
            selected = candidate;
    }
    width = selected->width;
    height = selected->height;
    format = selected->depth == 16u ? D3DFMT_R5G6B5 : D3DFMT_X8R8G8B8;
}

D3DFORMAT CD3D9Device::selectDepthFormat(D3DFORMAT adapter_format, D3DFORMAT back_buffer_format) const
{
    // These buffers are never CPU-locked. Lockable formats cannot use DISCARD_DEPTHSTENCIL.
    for (const auto candidate : {D3DFMT_D32, D3DFMT_D24S8, D3DFMT_D24X8, D3DFMT_D24X4S4, D3DFMT_D16, D3DFMT_D15S1})
    {
        if (SUCCEEDED(api->CheckDeviceFormat(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, adapter_format, D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, candidate)) &&
            SUCCEEDED(api->CheckDepthStencilMatch(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, adapter_format, back_buffer_format, candidate)))
            return candidate;
    }
    return D3DFMT_UNKNOWN;
}

void CD3D9Device::initialize(HWND window, std::uint32_t width, std::uint32_t height, std::uint32_t depth_bits, bool windowed)
{
    if (!window || !::IsWindow(window))
        throw std::invalid_argument("CreateDevice requires a valid application window");
    owner_thread_ = ::GetCurrentThreadId();
    if (::GetWindowThreadProcessId(window, nullptr) != owner_thread_)
        throw std::logic_error("CreateDevice must run on the application window thread");
    RECT client{};
    if (!::GetClientRect(window, &client) || client.right <= client.left || client.bottom <= client.top)
        throw std::invalid_argument("CreateDevice requires a non-empty application window");
    if (depth_bits != 16u && depth_bits != 32u)
        depth_bits = 32u;
    width = std::max(width, 800u);
    height = std::max(height, 600u);
    enumerateDisplayModes(windowed);
    D3DDISPLAYMODE display{};
    checkResult(api->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &display), "GetAdapterDisplayMode");
    D3DFORMAT back_buffer = depth_bits == 32u ? D3DFMT_X8R8G8B8 : D3DFMT_R5G6B5;
    selectBackBufferFormat(display, windowed, width, height, back_buffer);
    const auto depth_format = selectDepthFormat(windowed ? display.Format : back_buffer, back_buffer);
    if (depth_format == D3DFMT_UNKNOWN)
        throw std::runtime_error("No matching Direct3D 9 depth-stencil format was found");
    capabilities = {};
    checkResult(api->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &capabilities), "GetDeviceCaps");
    const bool hardware_vertices = (capabilities.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) != 0u;
    // Viewport/state guards use Get* methods, which are not supported by a pure device.
    DWORD behavior = D3DCREATE_FPU_PRESERVE | (hardware_vertices ? D3DCREATE_HARDWARE_VERTEXPROCESSING : D3DCREATE_SOFTWARE_VERTEXPROCESSING);
    D3DPRESENT_PARAMETERS requested{};
    requested.BackBufferWidth = width;
    requested.BackBufferHeight = height;
    requested.BackBufferFormat = back_buffer;
    requested.BackBufferCount = 1u;
    requested.MultiSampleType = D3DMULTISAMPLE_NONE;
    requested.MultiSampleQuality = 0u;
    requested.SwapEffect = D3DSWAPEFFECT_DISCARD;
    requested.hDeviceWindow = window;
    requested.Windowed = windowed ? TRUE : FALSE;
    requested.EnableAutoDepthStencil = TRUE;
    requested.AutoDepthStencilFormat = depth_format;
    requested.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
    requested.FullScreen_RefreshRateInHz = 0u;
    requested.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
    Microsoft::WRL::ComPtr<IDirect3DDevice9> created;
    D3DPRESENT_PARAMETERS accepted{};

    const HRESULT first_result = createNativeDevice(requested, accepted, created, window, behavior);
    HRESULT result = first_result;
    if (hardware_vertices && (result == D3DERR_INVALIDCALL || result == D3DERR_NOTAVAILABLE))
    {
        behavior = D3DCREATE_FPU_PRESERVE | D3DCREATE_SOFTWARE_VERTEXPROCESSING;
        result = createNativeDevice(requested, accepted, created, window, behavior);
    }
    if (FAILED(result))
    {
        auto operation = std::format("CreateDevice [{}x{}, windowed={}, adapterFormat={}, backBuffer={}, depthStencil={}, behavior=0x{:08X}, "
                                     "flags=0x{:08X}, refresh={}, interval=0x{:08X}, HWND={:p}, firstHRESULT=0x{:08X}]",
                                     width, height, windowed ? 1u : 0u, SferaNumeric::enumBits(windowed ? display.Format : back_buffer), SferaNumeric::enumBits(back_buffer),
                                     SferaNumeric::enumBits(depth_format), behavior, requested.Flags, requested.FullScreen_RefreshRateInHz, requested.PresentationInterval, static_cast<void *>(window),
                                     SferaNumeric::lowWord(first_result));
        checkResult(result, operation);
    }
    native_device = std::move(created);
    presentation = accepted;
    g_sfera_graphics_runtime.display_width = presentation.BackBufferWidth;
    g_sfera_graphics_runtime.display_height = presentation.BackBufferHeight;
    g_sfera_graphics_runtime.display_depth_bits = presentation.BackBufferFormat == D3DFMT_R5G6B5 || presentation.BackBufferFormat == D3DFMT_X1R5G5B5 || presentation.BackBufferFormat == D3DFMT_A1R5G5B5
                                                      ? 16u
                                                      : 32u;
    supports_post_effects = capabilities.VertexShaderVersion >= D3DVS_VERSION(2, 0) && capabilities.PixelShaderVersion >= D3DPS_VERSION(2, 0);
    initializeRenderState();
}

void CD3D9Device::applyFiltering()
{
    min_filter = D3DTEXF_ANISOTROPIC;
    mag_filter = D3DTEXF_LINEAR;
    mip_filter = D3DTEXF_LINEAR;
    for (DWORD stage = 0u; stage < 4u; ++stage)
    {
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_MINFILTER, min_filter), "SetSamplerState(MINFILTER)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_MAGFILTER, mag_filter), "SetSamplerState(MAGFILTER)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_MIPFILTER, mip_filter), "SetSamplerState(MIPFILTER)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_MAXANISOTROPY, 4u), "SetSamplerState(MAXANISOTROPY)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP), "SetSamplerState(ADDRESSU)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP), "SetSamplerState(ADDRESSV)");
        checkResult(native_device->SetSamplerState(stage, D3DSAMP_ADDRESSW, D3DTADDRESS_WRAP), "SetSamplerState(ADDRESSW)");
    }
}

void CD3D9Device::initializeRenderState()
{
    const auto identity = SferaMatrix4x4F::identity();
    setTransform(D3DTS_WORLD, identity);
    SphereUIInterfaceRenderer::sprite_render_mode = UINT32_MAX;
    checkResult(native_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW), "SetRenderState(CULLMODE)");
    checkResult(native_device->SetRenderState(D3DRS_ZENABLE, TRUE), "SetRenderState(ZENABLE)");
    checkResult(native_device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE), "SetRenderState(ZWRITEENABLE)");
    checkResult(native_device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL), "SetRenderState(ALPHAFUNC)");
    checkResult(native_device->SetRenderState(D3DRS_ALPHAREF, 1u), "SetRenderState(ALPHAREF)");
    checkResult(native_device->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE), "SetRenderState(ALPHATESTENABLE)");
    checkResult(native_device->SetRenderState(D3DRS_FOGENABLE, FALSE), "SetRenderState(FOGENABLE)");
    checkResult(native_device->SetRenderState(D3DRS_LIGHTING, FALSE), "SetRenderState(LIGHTING)");
    applyFiltering();
    const D3DVIEWPORT9 viewport{0u, 0u, presentation.BackBufferWidth, presentation.BackBufferHeight, 0.0f, 1.0f};
    checkResult(native_device->SetViewport(&viewport), "SetViewport");
    checkResult(native_device->SetRenderState(D3DRS_FOGTABLEMODE, D3DFOG_NONE), "SetRenderState(FOGTABLEMODE)");
    checkResult(native_device->SetRenderState(D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR), "SetRenderState(FOGVERTEXMODE)");
    checkResult(native_device->SetRenderState(D3DRS_RANGEFOGENABLE, TRUE), "SetRenderState(RANGEFOGENABLE)");
    checkResult(native_device->SetRenderState(D3DRS_FOGSTART, 80u), "SetRenderState(FOGSTART)");
    checkResult(native_device->SetRenderState(D3DRS_FOGEND, 150u), "SetRenderState(FOGEND)");
    checkResult(native_device->SetRenderState(D3DRS_LIGHTING, TRUE), "SetRenderState(LIGHTING)");
    setWhiteMaterial(1.0f);
}

void CD3D9Device::setTransform(D3DTRANSFORMSTATETYPE kind, const SferaMatrix4x4F &matrix)
{
    D3DMATRIX native{};
    for (std::size_t row = 0; row < 4; ++row)
        std::copy_n(matrix.m[row], 4, native.m[row]);
    const HRESULT result = native_device->SetTransform(kind, &native);
    last_hresult = result;
    checkResult(result, "SetTransform");
    if (kind == D3DTS_WORLD)
        world_transform = matrix;
}

void CD3D9Device::setAlphaBlending(D3DBLEND source, D3DBLEND destination)
{
    native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    native_device->SetRenderState(D3DRS_SRCBLEND, source);
    native_device->SetRenderState(D3DRS_DESTBLEND, destination);
}

void CD3D9Device::setColorOperation(std::uint32_t stage, D3DTEXTUREOP operation, std::uint32_t first, std::uint32_t second)
{
    native_device->SetTextureStageState(stage, D3DTSS_COLOROP, operation);
    native_device->SetTextureStageState(stage, D3DTSS_COLORARG1, first);
    native_device->SetTextureStageState(stage, D3DTSS_COLORARG2, second);
}

void CD3D9Device::setAlphaOperation(std::uint32_t stage, D3DTEXTUREOP operation, std::uint32_t first, std::uint32_t second)
{
    native_device->SetTextureStageState(stage, D3DTSS_ALPHAOP, operation);
    native_device->SetTextureStageState(stage, D3DTSS_ALPHAARG1, first);
    native_device->SetTextureStageState(stage, D3DTSS_ALPHAARG2, second);
}

void CD3D9Device::setWhiteMaterial(float alpha)
{
    D3DMATERIAL9 material{};
    material.Diffuse = {1.0f, 1.0f, 1.0f, alpha};
    material.Ambient = {1.0f, 1.0f, 1.0f, 0.0f};
    checkResult(native_device->SetMaterial(&material), "SetMaterial");
}

UINT CD3D9Device::primitiveCount(D3DPRIMITIVETYPE topology, UINT elements)
{
    switch (topology)
    {
    case D3DPT_POINTLIST:
        return elements;
    case D3DPT_LINELIST:
        return elements / 2u;
    case D3DPT_LINESTRIP:
        return elements > 1u ? elements - 1u : 0u;
    case D3DPT_TRIANGLELIST:
        return elements / 3u;
    case D3DPT_TRIANGLESTRIP:
    case D3DPT_TRIANGLEFAN:
        return elements > 2u ? elements - 2u : 0u;
    default:
        throw std::invalid_argument("Unknown Direct3D primitive topology");
    }
}

void CD3D9Device::applyDrawState(std::uint32_t flags)
{
    checkResult(native_device->SetRenderState(D3DRS_CULLMODE, (flags & CD3D9Devicetwo_sided) != 0u ? D3DCULL_NONE : D3DCULL_CW), "SetRenderState(CULLMODE)");
    checkResult(native_device->SetRenderState(D3DRS_LIGHTING, (flags & CD3D9Devicelighting) != 0u), "SetRenderState(LIGHTING)");
    checkResult(native_device->SetRenderState(D3DRS_CLIPPING, (flags & CD3D9Devicedisable_clipping) == 0u), "SetRenderState(CLIPPING)");
}

void CD3D9Device::drawBuffer(IDirect3DVertexBuffer9 *vertices, D3DPRIMITIVETYPE topology, std::uint32_t flags, std::ptrdiff_t base_vertex, std::size_t vertex_count, IDirect3DIndexBuffer9 *indices,
                             std::size_t index_count, std::size_t start_index, std::size_t stride)
{
    if (!native_device)
        return;
    if (vertex_count > UINT_MAX || index_count > UINT_MAX || stride > UINT_MAX || start_index > UINT_MAX || !std::in_range<INT>(base_vertex) || (index_count == 0 && base_vertex < 0))
        throw std::length_error("Draw range exceeds the Direct3D API limits");
    const UINT primitives = primitiveCount(topology, SferaNumeric::lowWord(index_count ? index_count : vertex_count));
    if (primitives == 0)
        return;
    if (!vertices || vertex_count == 0 || stride == 0)
        throw std::invalid_argument("Empty Direct3D vertex buffer range");
    applyDrawState(flags);
    D3DVERTEXBUFFER_DESC description{};
    checkResult(vertices->GetDesc(&description), "GetDesc(vertex buffer)");
    checkResult(native_device->SetFVF(description.FVF), "SetFVF");
    checkResult(native_device->SetStreamSource(0u, vertices, 0u, SferaNumeric::lowWord(stride)), "SetStreamSource");
    if (index_count)
    {
        if (!indices)
            indices = indices_primary.buffer();
        if (!indices)
            throw std::invalid_argument("Empty Direct3D index buffer");
        checkResult(native_device->SetIndices(indices), "SetIndices");
        checkResult(native_device->DrawIndexedPrimitive(topology, SferaNumeric::signedWord(SferaNumeric::lowWord(base_vertex)), 0u, SferaNumeric::lowWord(vertex_count),
                                                        SferaNumeric::lowWord(start_index), primitives),
                    "DrawIndexedPrimitive");
    }
    else
    {
        checkResult(native_device->DrawPrimitive(topology, SferaNumeric::lowWord(base_vertex), primitives), "DrawPrimitive");
    }
}

void CD3D9Device::drawVertices(D3DPRIMITIVETYPE topology, std::uint32_t flags, const void *vertices, std::size_t vertex_count, const std::uint16_t *indices, std::size_t index_count,
                               std::size_t stride)
{
    if (!native_device)
        return;
    if (vertex_count > UINT_MAX || index_count > UINT_MAX || stride > UINT_MAX)
        throw std::length_error("Draw range exceeds the Direct3D API limits");
    const UINT primitives = primitiveCount(topology, SferaNumeric::lowWord(index_count ? index_count : vertex_count));
    if (primitives == 0)
        return;
    if (!vertices || vertex_count == 0 || stride == 0 || (index_count && !indices))
        throw std::invalid_argument("Empty Direct3D draw range");
    applyDrawState(flags);
    if (index_count)
    {
        checkResult(native_device->DrawIndexedPrimitiveUP(topology, 0u, SferaNumeric::lowWord(vertex_count), primitives, indices, D3DFMT_INDEX16, vertices, SferaNumeric::lowWord(stride)),
                    "DrawIndexedPrimitiveUP");
    }
    else
    {
        checkResult(native_device->DrawPrimitiveUP(topology, primitives, vertices, SferaNumeric::lowWord(stride)), "DrawPrimitiveUP");
    }
}

void CD3D9Device::releaseResources()
{
    sync_query.Reset();
    if (post_effects != nullptr)
        post_effects->releaseResources();
    for (auto *resource : unmanaged_resources)
        resource->releaseResource();
}

void CD3D9Device::restoreResources()
{
    initializeRenderState();
    last_hresult = native_device->CreateQuery(D3DQUERYTYPE_EVENT, sync_query.ReleaseAndGetAddressOf());
    if (last_hresult != S_OK)
    {
        SferaEngineDiagnostics::write("Render err: cant create query:");
        SferaEngineDiagnostics::write(SferaNumeric::signedWord(last_hresult));
    }
    if (post_effects != nullptr)
        post_effects->restoreResources();
    for (auto *resource : unmanaged_resources)
        resource->restoreResource();
    g_sfera_light_runtime.invalidateActiveLights();
    g_sfera_light_runtime.disableActiveLights();
}

void CD3D9Device::waitForGpu()
{
    if (sync_query == nullptr || sync_query->Issue(D3DISSUE_END) == D3DERR_DEVICELOST)
        return;
    while (sync_query->GetData(nullptr, 0u, D3DGETDATA_FLUSH) == S_FALSE)
        ::Sleep(0u);
}

UnmanagedResourceTexture &CD3D9Device::minimapTexture()
{
    if (minimap_target == nullptr)
        minimap_target = std::make_unique<UnmanagedResourceTexture>(*this, 256u, 256u, 1u, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT);
    return *minimap_target;
}

bool CD3D9Device::beginScene()
{
    if (!native_device || scene_open_ || resetting_)
        return false;
    if (owner_thread_ != ::GetCurrentThreadId())
        throw std::logic_error("Direct3D used from a non-owner thread");
    last_hresult = native_device->TestCooperativeLevel();
    if (last_hresult == D3DERR_DEVICELOST)
        return false;
    if (last_hresult == D3DERR_DEVICENOTRESET)
    {
        CD3D9DeviceResetGuard guard{resetting_};
        resetting_ = true;
        releaseResources();
        auto requested = presentation; // Reset is allowed to modify its argument.
        last_hresult = native_device->Reset(&requested);
        if (last_hresult == D3DERR_DEVICELOST || last_hresult == D3DERR_DEVICENOTRESET)
            return false;
        checkResult(last_hresult, "Reset");
        try
        {
            restoreResources();
        }
        catch (...)
        {
            releaseResources();
            throw;
        }
    }
    else
    {
        checkResult(last_hresult, "TestCooperativeLevel");
    }
    last_hresult = native_device->BeginScene();
    if (last_hresult == D3DERR_DEVICELOST)
        return false;
    checkResult(last_hresult, "BeginScene");
    scene_open_ = true;
    return true;
}

HRESULT CD3D9Device::endScene() noexcept
{
    if (!std::exchange(scene_open_, false) || !native_device)
        return S_OK;
    if (post_effects)
        post_effects->cancelCapture();
    return last_hresult = native_device->EndScene();
}

bool CD3D9Device::present()
{
    if (!native_device || scene_open_ || resetting_)
        return false;
    last_hresult = native_device->Present(nullptr, nullptr, nullptr, nullptr);
    if (last_hresult == D3DERR_DEVICELOST || last_hresult == D3DERR_DEVICENOTRESET)
        return false;
    return SUCCEEDED(checkResult(last_hresult, "Present"));
}

std::tuple<unsigned, std::uint64_t, unsigned> CD3D9Device::rankDisplayMode(const SphereUIDisplayMode &mode, std::uint32_t width, std::uint32_t height, const D3DDISPLAYMODE &display,
                                                                           std::uint32_t depth_bits)
{
    const unsigned size_rank = mode.width == width && mode.height == height ? 0u : (mode.width == display.Width && mode.height == display.Height ? 1u : 2u);
    const std::uint64_t dx = mode.width > width ? mode.width - width : width - mode.width;
    const std::uint64_t dy = mode.height > height ? mode.height - height : height - mode.height;
    return std::tuple{size_rank, dx + dy, mode.depth == depth_bits ? 0u : 1u};
}

HRESULT CD3D9Device::createNativeDevice(const D3DPRESENT_PARAMETERS &requested, D3DPRESENT_PARAMETERS &accepted, Microsoft::WRL::ComPtr<IDirect3DDevice9> &created, HWND window, DWORD behavior)
{
    accepted = requested; // A failed CreateDevice may also modify presentation parameters.
    return api->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window, behavior, &accepted, created.ReleaseAndGetAddressOf());
}

template <class Element> DynamicStream<Element>::DynamicStream(CD3D9Device &owner) : UnmanagedResourceBase(owner, D3DPOOL_DEFAULT)
{
}

template <class Element>
DynamicStreamMapping<Element>::DynamicStreamMapping(CD3D9Device &device, Microsoft::WRL::ComPtr<DynamicStreamBuffer<Element>> buffer, std::size_t first, std::size_t count, Element *data)
    : device_(&device), buffer_(std::move(buffer)), first_(first), count_(count), data_(data)
{
}

template <class Element>
DynamicStreamMapping<Element>::DynamicStreamMapping(DynamicStreamMapping<Element> &&other) noexcept
    : device_(std::exchange(other.device_, nullptr)), buffer_(std::move(other.buffer_)), first_(other.first_), count_(other.count_), data_(std::exchange(other.data_, nullptr))
{
}

template <class Element> DynamicStreamMapping<Element> &DynamicStreamMapping<Element>::operator=(DynamicStreamMapping<Element> &&other) noexcept
{
    if (this == std::addressof(other))
        return *this;
    if (buffer_ && data_)
        buffer_->Unlock();
    buffer_ = std::move(other.buffer_);
    device_ = other.device_;
    first_ = other.first_;
    count_ = other.count_;
    data_ = std::exchange(other.data_, nullptr);
    return *this;
}

template <class Element> DynamicStreamMapping<Element>::~DynamicStreamMapping()
{
    if (buffer_ && data_)
        buffer_->Unlock();
}

template <class Element> void DynamicStreamMapping<Element>::unlock()
{
    if (!buffer_ || !std::exchange(data_, nullptr))
        return;
    device_->checkResult(buffer_->Unlock(), std::is_same_v<Element, std::uint16_t> ? "IndexBuffer::Unlock" : "VertexBuffer::Unlock");
}

template <class Element> void DynamicStream<Element>::reserve(std::size_t count)
{
    if (count <= capacity_ && buffer_)
        return;
    count = std::max(count, capacity_);
    if (count == 0)
        return;
    constexpr auto limit = std::numeric_limits<UINT>::max() / sizeof(Element);
    if (count > limit)
        throw std::length_error("Direct3D stream exceeds the API size limit");
    if (!device || !device->native_device)
        throw std::logic_error("Direct3D stream has no device");
    Microsoft::WRL::ComPtr<DynamicStreamBuffer<Element>> replacement;
    const UINT bytes = SferaNumeric::lowWord(count * sizeof(Element));
    if constexpr (indexed)
    {
        device->checkResult(device->native_device->CreateIndexBuffer(bytes, D3DUSAGE_DYNAMIC, D3DFMT_INDEX16, D3DPOOL_DEFAULT, replacement.GetAddressOf(), nullptr), "CreateIndexBuffer");
    }
    else
    {
        constexpr DWORD fvf = std::is_same_v<Element, SphereRenderPositionNormalUvVertex> ? D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 : D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1;
        device->checkResult(device->native_device->CreateVertexBuffer(bytes, D3DUSAGE_DYNAMIC, fvf, D3DPOOL_DEFAULT, replacement.GetAddressOf(), nullptr), "CreateVertexBuffer");
    }
    buffer_ = std::move(replacement);
    capacity_ = count;
    position_ = 0;
}

template <class Element> DynamicStreamMapping<Element> DynamicStream<Element>::lock(std::size_t count)
{
    if (!device)
        throw std::logic_error("Direct3D stream has no device");
    constexpr auto limit = std::numeric_limits<UINT>::max() / sizeof(Element);
    if (count > limit)
        throw std::length_error("Direct3D stream exceeds the API size limit");
    if (count == 0)
        return DynamicStreamMapping<Element>(*device, buffer_, position_, 0, nullptr);
    if (count > capacity_)
        reserve(count + std::min(count / 4, limit - count));
    else if (!buffer_)
        restoreResource();
    const bool discard = discard_next_ || position_ > capacity_ || count > capacity_ - position_;
    const std::size_t first = discard ? 0 : position_;
    void *data = nullptr;
    device->checkResult(buffer_->Lock(0, 0, &data, discard ? D3DLOCK_DISCARD : D3DLOCK_NOOVERWRITE), indexed ? "IndexBuffer::Lock" : "VertexBuffer::Lock");
    if (!data)
    {
        buffer_->Unlock();
        throw std::runtime_error("Direct3D returned an empty mapping");
    }
    position_ = first + count;
    discard_next_ = false;
    return DynamicStreamMapping<Element>(*device, buffer_, first, count, static_cast<Element *>(data) + first);
}

template <class Element> void DynamicStream<Element>::releaseResource()
{
    buffer_.Reset();
    position_ = 0;
    discard_next_ = true;
}

template <class Element> void DynamicStream<Element>::restoreResource()
{
    reserve(capacity_);
}

template class DynamicStream<SphereRenderPositionNormalUvVertex>;

template class DynamicStream<SphereRenderPositionColorUvVertex>;

template class DynamicStream<std::uint16_t>;

template class DynamicStreamMapping<SphereRenderPositionNormalUvVertex>;

template class DynamicStreamMapping<SphereRenderPositionColorUvVertex>;

template class DynamicStreamMapping<std::uint16_t>;

CPostEffectsMgr::CPostEffectsMgr(CD3D9Device &owner) : device(owner)
{
    const D3DVERTEXELEMENT9 elements[] = {{0, 0, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITIONT, 0},
                                          {0, 16, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0},
                                          {0, 24, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 1},
                                          D3DDECL_END()};
    device.checkResult(device.native_device->CreateVertexDeclaration(elements, vertex_declaration.GetAddressOf()), "CreateVertexDeclaration");
}

CPostEffectsMgr::~CPostEffectsMgr()
{
    releaseResources();
}

void CPostEffectsMgr::restoreResources()
{
    if (!enabled)
        return;
    device.checkResult(device.native_device->TestCooperativeLevel(), "TestCooperativeLevel");

    auto scene = createRenderTexture(g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height);
    auto temporary = createRenderTexture(128, 128);
    auto blurred = createRenderTexture(128, 128);
    capture.reset();
    scene_texture = std::move(scene);
    temporary_texture = std::move(temporary);
    blur_texture = std::move(blurred);
}

void CPostEffectsMgr::releaseResources()
{
    capture.reset();
    blur_texture.Reset();
    temporary_texture.Reset();
    scene_texture.Reset();
}

void CPostEffectsMgr::setEnabled(bool value)
{
    if (enabled == value)
        return;
    enabled = value;
    if (!enabled)
    {
        releaseResources();
        return;
    }
    try
    {
        restoreResources();
    }
    catch (...)
    {
        enabled = false;
        throw;
    }
}

void CPostEffectsMgr::beginCapture()
{
    if (!enabled)
        return;
    if (capture)
        throw std::logic_error("Post-effects capture is already active");
    if (!scene_texture)
        restoreResources();
    capture.emplace(device, *scene_texture.Get());
}

void CPostEffectsMgr::configureRenderState()
{
    device.checkResult(device.native_device->SetRenderState(D3DRS_ZENABLE, FALSE), "SetRenderState(ZENABLE)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE), "SetRenderState(ZWRITEENABLE)");
    for (DWORD sampler = 0u; sampler < 2u; ++sampler)
    {
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP), "SetSamplerState(ADDRESSU)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP), "SetSamplerState(ADDRESSV)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_MINFILTER, D3DTEXF_LINEAR), "SetSamplerState(MINFILTER)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR), "SetSamplerState(MAGFILTER)");
        device.checkResult(device.native_device->SetSamplerState(sampler, D3DSAMP_MIPFILTER, D3DTEXF_NONE), "SetSamplerState(MIPFILTER)");
    }
    device.checkResult(device.native_device->SetVertexShader(nullptr), "SetVertexShader");
    device.checkResult(device.native_device->SetVertexDeclaration(vertex_declaration.Get()), "SetVertexDeclaration");
}

void CPostEffectsMgr::drawQuad(std::uint32_t width, std::uint32_t height)
{
    const float right = width - 0.5f;
    const float bottom = height - 0.5f;
    const CPostEffectsMgrScreenVertex vertices[] = {{-0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
                                                    {-0.5f, bottom, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f},
                                                    {right, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f},
                                                    {right, bottom, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f}};
    device.checkResult(device.native_device->Clear(0u, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0u), "Clear");
    device.checkResult(device.native_device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2u, vertices, sizeof(CPostEffectsMgrScreenVertex)), "DrawPrimitiveUP(post effects)");
}

void CPostEffectsMgr::renderToTexture(IDirect3DTexture9 *target)
{
    D3DSURFACE_DESC description{};
    device.checkResult(target->GetLevelDesc(0, &description), "GetLevelDesc");
    RenderTargetScope selected(device, *target);
    drawQuad(description.Width, description.Height);
}

void CPostEffectsMgr::blur()
{
    device.checkResult(device.native_device->SetTexture(0u, scene_texture.Get()), "SetTexture(scene)");
    device.shaders->setPixelShader(6u);
    renderToTexture(blur_texture.Get());
    device.checkResult(device.native_device->SetTexture(0u, blur_texture.Get()), "SetTexture(blur)");
    device.shaders->setPixelShader(7u);
    renderToTexture(temporary_texture.Get());
    device.checkResult(device.native_device->SetTexture(0u, temporary_texture.Get()), "SetTexture(blur temporary)");
    device.shaders->setPixelShader(8u);
    renderToTexture(blur_texture.Get());
}

void CPostEffectsMgr::compose()
{
    if (!enabled || !capture)
        return;
    auto frame = std::move(capture);
    capture.reset();
    RenderStateScope state(device);
    configureRenderState();
    blur();
    device.checkResult(frame->restore(), "RestoreRenderTarget");
    device.checkResult(device.native_device->SetTexture(0, scene_texture.Get()), "SetTexture(scene)");
    device.checkResult(device.native_device->SetTexture(1, blur_texture.Get()), "SetTexture(blur)");
    device.shaders->setPixelShader(9);
    drawQuad(g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height);
}

Microsoft::WRL::ComPtr<IDirect3DTexture9> CPostEffectsMgr::createRenderTexture(std::uint32_t width, std::uint32_t height)
{
    Microsoft::WRL::ComPtr<IDirect3DTexture9> texture;
    device.checkResult(device.native_device->CreateTexture(width, height, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, texture.GetAddressOf(), nullptr), "CreateTexture(post effects)");
    return texture;
}

RenderStateScope::RenderStateScope(CD3D9Device &device, RenderStateScopeFailurePolicy failure)
    : device_(device), world_transform_(device.world_transform), active_lights_(g_sfera_light_runtime.active_lights), active_light_count_(g_sfera_light_runtime.active_count),
      sprite_render_mode_(SphereUIInterfaceRenderer::sprite_render_mode)
{
    device.last_hresult = device.native_device->CreateStateBlock(D3DSBT_ALL, state_.GetAddressOf());
    if (failure == RenderStateScopeFailurePolicy::Throw)
        device.checkResult(device.last_hresult, "CreateStateBlock");
}

RenderStateScope::~RenderStateScope() noexcept
{
    if (!state_)
        return;
    const HRESULT result = state_->Apply();
    if (SUCCEEDED(result))
    {
        // CPU caches must describe the same state that the block restored on the GPU.
        // Invalidating only the light cache would leave enabled GPU slots invisible
        // to disableActiveLights; retaining the pass matrix breaks shadow projection.
        device_.world_transform = world_transform_;
        g_sfera_light_runtime.active_lights = active_lights_;
        g_sfera_light_runtime.active_count = active_light_count_;
        SphereUIInterfaceRenderer::sprite_render_mode = sprite_render_mode_;
    }
    else
    {
        device_.last_hresult = result;
        g_sfera_light_runtime.invalidateActiveLights();
        SphereUIInterfaceRenderer::sprite_render_mode = UINT32_MAX;
    }
}

RenderTargetScope::RenderTargetScope(CD3D9Device &device, IDirect3DTexture9 &target) : device_(&device)
{
    auto *native = device.native_device.Get();
    if (!native)
        throw std::logic_error("Render target has no Direct3D device");
    device.checkResult(native->GetRenderTarget(0, color_.GetAddressOf()), "GetRenderTarget");
    const HRESULT depthStatus = native->GetDepthStencilSurface(depth_.GetAddressOf());
    if (depthStatus != D3DERR_NOTFOUND)
        device.checkResult(depthStatus, "GetDepthStencilSurface");
    device.checkResult(native->GetViewport(&viewport_), "GetViewport");
    Microsoft::WRL::ComPtr<IDirect3DSurface9> surface;
    device.checkResult(target.GetSurfaceLevel(0, surface.GetAddressOf()), "GetSurfaceLevel");
    const HRESULT status = native->SetRenderTarget(0, surface.Get());
    if (FAILED(status))
        restore();
    device.checkResult(status, "SetRenderTarget");
}

RenderTargetScope::RenderTargetScope(RenderTargetScope &&other) noexcept
    : device_(std::exchange(other.device_, nullptr)), color_(std::move(other.color_)), depth_(std::move(other.depth_)), viewport_(other.viewport_)
{
}

RenderTargetScope::~RenderTargetScope()
{
    restore();
}

HRESULT RenderTargetScope::restore() noexcept
{
    auto *owner = std::exchange(device_, nullptr);
    if (!owner || !owner->native_device)
        return S_OK;
    auto *native = owner->native_device.Get();
    HRESULT result = native->SetRenderTarget(0, color_.Get());

    recordFailure(result, native->SetDepthStencilSurface(depth_.Get()));
    recordFailure(result, native->SetViewport(&viewport_));
    return result;
}

void RenderTargetScope::recordFailure(HRESULT &result, HRESULT status)
{
    if (SUCCEEDED(result) && FAILED(status))
        result = status;
}

void SceneScope::finish()
{
    auto *device = std::exchange(device_, nullptr);
    if (!device)
        return;
    const auto result = device->endScene();
    if (result != D3DERR_DEVICELOST)
        device->checkResult(result, "EndScene");
}

std::pair<bool, std::array<std::uint8_t, 8>> CShaderMgr::instanceCode(std::string_view filename, bool pixel)
{
    std::pair<bool, std::array<std::uint8_t, 8>> code{pixel, {}};
    std::size_t position = 0u;
    for (unsigned pin = 0u;; ++pin)
    {
        if (pin == 8u)
            throw std::invalid_argument("Too many shader pins: " + std::string(filename));
        if (position + 1u >= filename.size())
            throw std::invalid_argument("Incomplete shader pin: " + std::string(filename));
        const auto tens = filename[position];
        const auto units = filename[position + 1u];
        if (tens < '0' || tens > '9' || units < '0' || units > '9')
            throw std::invalid_argument("Invalid shader pin: " + std::string(filename));
        code.second[pin] = (tens - '0') * 10 + units - '0';
        position += 2u;
        if (position == filename.size() || filename[position] != '_')
            return code;
        ++position;
    }
}

std::array<float, 512> CShaderMgr::makeWaveSamples()
{
    constexpr double random_range = RAND_MAX;
    std::array<float, 10> phases{};
    std::array<float, 10> amplitudes{};
    for (std::size_t harmonic = 0; harmonic < phases.size(); ++harmonic)
    {
        phases[harmonic] = SferaNumeric::real32(std::rand() / random_range * 6.2831854820251465);
        amplitudes[harmonic] = SferaNumeric::real32(std::rand() / random_range + 1.0);
    }
    std::array<float, 512> samples{};
    float peak = 0.0f;
    for (std::size_t sample = 0; sample < samples.size(); ++sample)
    {
        const float angle = SferaNumeric::real32(sample * 0.012271846644580364);
        for (std::size_t harmonic = 0; harmonic < phases.size(); ++harmonic)
        {
            const float phase = ((harmonic + 1u) * angle + phases[harmonic]);
            samples[sample] += std::sin(phase) * amplitudes[harmonic];
        }
        peak = std::max(peak, std::abs(samples[sample]));
    }
    if (peak > 0.0f)
        for (float &sample : samples)
            sample *= 1.0f / peak;
    return samples;
}

std::array<float, 64> CShaderMgr::makeDownsampleOffsets(float width, float height)
{
    if (width <= 0.0f || height <= 0.0f)
        throw std::invalid_argument("Shader sampling dimensions must be positive");
    std::array<float, 64> offsets{};
    for (unsigned column = 0; column < 4; ++column)
    {
        for (unsigned row = 0; row < 4; ++row)
        {
            const auto first = (column * 4u + row) * 4u;
            offsets[first] = (1.5f - column) / width;
            offsets[first + 1] = (row - 1.5f) / height;
        }
    }
    return offsets;
}

CShaderMgrWaterParameters CShaderMgr::waterParameters(float environment, float height)
{
    CShaderMgrWaterParameters result;
    float reflection_scale = 0.5f;
    if (environment >= 0.34f && environment <= 0.66f)
    {
        result.specular = 0.35f;
    }
    else if (environment <= 0.19f || environment >= 0.81f)
    {
        result.gradient = 1.0f;
        result.specular = 0.15f;
        reflection_scale = 0.3f;
    }
    else if (environment < 0.34f)
    {
        const float transition = (environment - 0.19f) / 0.15f;
        result.gradient = 1.0f - transition;
        result.specular = 0.15f + transition * 0.2f;
    }
    else
    {
        const float transition = (environment - 0.66f) / 0.15f;
        result.gradient = transition;
        result.specular = 0.35f - transition * 0.2f;
    }
    if (height < 0.0f)
    {
        constexpr double exponent = 0.3f;
        const float reflected = SferaNumeric::real32(std::pow(-height, exponent));
        result.reflection = reflected * reflection_scale;
    }
    return result;
}

void CShaderMgr::loadFolder(const std::string &directory, bool pixel)
{
    std::error_code error;
    std::filesystem::directory_iterator files(directory, error);
    if (error)
        return;
    for (const auto &file : files)
    {
        if (!file.is_regular_file())
            continue;
        std::string extension = file.path().extension().string();
        SferaText::lowercaseLocale(extension);
        if (extension != (pixel ? ".psc" : ".vsc"))
            continue;
        const std::string filename = file.path().filename().string();
        const auto code = instanceCode(filename, pixel);
        auto inserted = variants.try_emplace(code);
        if (!inserted.second)
            throw std::runtime_error("Duplicate shader pin combination: " + filename);
        inserted.first->second.filename = filename;
    }
}

CShaderMgr::CShaderMgr(CD3D9Device &owner, std::string vertex_path, std::string pixel_path) : vertex_directory(std::move(vertex_path)), pixel_directory(std::move(pixel_path)), device(owner)
{
    try
    {
        loadFolder(vertex_directory, false);
        loadFolder(pixel_directory, true);
        wave_samples = makeWaveSamples();
        downsample_offsets = makeDownsampleOffsets(SferaNumeric::real32(g_sfera_graphics_runtime.display_width), SferaNumeric::real32(g_sfera_graphics_runtime.display_height));
    }
    catch (const std::exception &error)
    {
        SferaEngineDiagnostics::fatal(error.what());
    }
}

CShaderMgrVariant &CShaderMgr::loadVariant(const std::pair<bool, std::array<std::uint8_t, 8>> &code)
{
    auto found = variants.find(code);
    if (found == variants.end())
    {
        SferaEngineDiagnostics::fatal(("Unexpected shader group: " + std::to_string(code.second.front())));
        throw std::out_of_range("Shader variant does not exist");
    }
    CShaderMgrVariant &variant = found->second;
    if (variant.pixel_shader)
        return variant;

    const std::string filename = (std::filesystem::path(pixel_directory) / variant.filename).string();
    SferaFileMap file(filename);
    const auto mapped = file.bytes();
    if (!file.isOpen() || mapped.size() < sizeof(DWORD) || mapped.size() % sizeof(DWORD) != 0u)
    {
        SferaEngineDiagnostics::fatal(("Invalid compiled shader: " + filename));
        throw std::runtime_error("Compiled shader could not be read");
    }

    const auto bytes = mapped;
    const auto constants = readShaderConstants(bytes);
    std::vector<DWORD> words(bytes.size() / sizeof(DWORD));
    SferaBinaryReader reader(bytes);
    for (auto &word : words)
        word = reader.read<std::uint32_t>();
    CShaderMgrVariant replacement;
    replacement.filename = variant.filename;
    device.checkResult(device.native_device->CreatePixelShader(words.data(), replacement.pixel_shader.GetAddressOf()), "CreatePixelShader");

    replacement.alpha_register = resolveConstant(constants, "gAlpha");
    replacement.down_filter_register = resolveConstant(constants, "gTexelCoordsDownFilter");
    replacement.water_gradient_register = resolveConstant(constants, "gWaterGradientCoefficient");
    replacement.water_specular_register = resolveConstant(constants, "gWaterSpecular");
    replacement.water_reflection_register = resolveConstant(constants, "gWaterReflectCoefficient");
    variant = std::move(replacement);
    return variant;
}

std::optional<UINT> CShaderMgr::resolveConstant(const std::unordered_map<std::string, int, SferaTextHash, std::equal_to<>> &constants, std::string_view name)
{
    const auto iterator = constants.find(name);
    return iterator == constants.end() ? std::nullopt : std::optional<UINT>{iterator->second};
}

void CShaderMgr::setFloatConstant(std::optional<UINT> shader_register, float value)
{
    if (!shader_register)
        return;
    const float data[4] = {value, 0.0f, 0.0f, 0.0f};
    device.checkResult(device.native_device->SetPixelShaderConstantF(*shader_register, data, 1u), "SetPixelShaderConstantF");
}

std::unordered_map<std::string, int, SferaTextHash, std::equal_to<>> CShaderMgr::readShaderConstants(std::span<const std::uint8_t> code)
{
    constexpr std::uint32_t comment_opcode = 0xfffeu;
    constexpr std::uint32_t end_opcode = 0x0000ffffu;
    constexpr std::uint32_t ctab_signature = 0x42415443u;
    std::unordered_map<std::string, int, SferaTextHash, std::equal_to<>> constants;
    if (code.size() < 8 || code.size() % 4 != 0)
        throw std::runtime_error("Truncated compiled shader");
    const bool explicit_lengths = ((SferaBinary::readLittleEndian<std::uint32_t>(code.data()) >> 8u) & 0xffu) >= 2u;
    if (!explicit_lengths && SferaBinary::readLittleEndian<std::uint32_t>(code.data() + code.size() - 4) != end_opcode)
    {
        throw std::runtime_error("Compiled shader has no END instruction");
    }
    auto instructions = code.subspan(4);
    while (instructions.size() >= 4)
    {
        const auto token = SferaBinary::readLittleEndian<std::uint32_t>(instructions.data());
        if (token == end_opcode)
            return constants;
        const bool comment = (token & 0xffffu) == comment_opcode;
        const std::size_t words = comment ? (token >> 16u) & 0x7fffu : (token >> 24u) & 0x0fu;
        instructions = instructions.subspan(4);
        if (words > instructions.size() / 4)
        {
            if (!explicit_lengths && !comment)
                return constants;
            throw std::runtime_error("Truncated shader instruction");
        }
        const auto payload = instructions.first(words * 4);
        instructions = instructions.subspan(payload.size());
        if (!comment || payload.size() < 4 || SferaBinary::readLittleEndian<std::uint32_t>(payload.data()) != ctab_signature)
            continue;
        const auto table = payload.subspan(4);
        if (table.size() < 20)
            throw std::runtime_error("Truncated shader constant table");
        const auto count = SferaBinary::readLittleEndian<std::uint32_t>(table.data() + 12);
        const auto offset = SferaBinary::readLittleEndian<std::uint32_t>(table.data() + 16);
        if (offset > table.size() || count > (table.size() - offset) / 20)
        {
            throw std::runtime_error("Invalid shader constant range");
        }
        for (std::size_t index = 0; index < count; ++index)
        {
            const auto entry = table.subspan(offset + index * 20, 20);
            const auto name_offset = SferaBinary::readLittleEndian<std::uint32_t>(entry.data());
            const auto register_set = SferaBinary::readLittleEndian<std::uint16_t>(entry.data() + 4);
            const auto register_index = SferaBinary::readLittleEndian<std::uint16_t>(entry.data() + 6);
            if (register_set != 2)
                continue;
            if (name_offset >= table.size())
                throw std::runtime_error("Invalid shader constant name");
            const auto name = table.subspan(name_offset);
            const auto end = std::find(name.begin(), name.end(), std::uint8_t{0});
            if (end == name.end())
                throw std::runtime_error("Unterminated shader constant name");
            constants[std::string(SferaText::fromBytes(name.first(end - name.begin())))] = register_index;
        }
    }
    if (!explicit_lengths)
        return constants;
    throw std::runtime_error("Compiled shader has no END instruction");
}

TextureMapping::TextureMapping(IDirect3DTexture9 *texture, UINT level, DWORD flags) noexcept : texture_(texture), level_(level)
{
    if (!texture_)
        return;
    status_ = texture_->GetLevelDesc(level_, &description_);
    if (FAILED(status_))
        return;
    status_ = texture_->LockRect(level_, &rectangle_, nullptr, flags);
    locked_ = SUCCEEDED(status_);
    if (locked_ && !rectangle_.pBits)
    {
        unlock();
        status_ = D3DERR_INVALIDCALL;
    }
}

TextureMapping::TextureMapping(TextureMapping &&other) noexcept
    : texture_(std::move(other.texture_)), level_(other.level_), description_(other.description_), rectangle_(std::exchange(other.rectangle_, {})), status_(other.status_),
      locked_(std::exchange(other.locked_, false))
{
}

TextureMapping::~TextureMapping()
{
    unlock();
}

HRESULT TextureMapping::unlock() noexcept
{
    rectangle_ = {};
    return texture_ && std::exchange(locked_, false) ? texture_->UnlockRect(level_) : S_OK;
}

std::span<std::uint8_t> TextureMapping::row(std::size_t index, std::size_t bytes) const noexcept
{
    const std::int64_t pitch = rectangle_.Pitch;
    const std::uint64_t magnitude = pitch < 0 ? -pitch : pitch;
    if (!texture_ || !locked_ || !rectangle_.pBits || index >= description_.Height || bytes > magnitude || (magnitude != 0 && index > std::numeric_limits<std::ptrdiff_t>::max() / magnitude))
        return {};
    const std::ptrdiff_t row_index = index;
    const std::ptrdiff_t offset = row_index * pitch;
    return {static_cast<std::uint8_t *>(rectangle_.pBits) + offset, bytes};
}

HRESULT TextureMapping::copyRows(std::span<const std::byte> source, std::size_t rowBytes, std::size_t rows) noexcept
{
    if (rows == 0 || rowBytes == 0)
        return S_OK;
    if (rowBytes > source.size() / rows || rows > description_.Height)
        return D3DERR_INVALIDCALL;
    for (std::size_t index = 0; index < rows; ++index)
    {
        const auto destination = row(index, rowBytes);
        if (destination.size() != rowBytes)
            return D3DERR_INVALIDCALL;
        std::memcpy(destination.data(), source.data() + index * rowBytes, rowBytes);
    }
    return S_OK;
}

UnmanagedResourceBase::UnmanagedResourceBase(CD3D9Device &owner, D3DPOOL pool) : device(&owner), registered(pool != D3DPOOL_MANAGED)
{
    if (registered)
        owner.unmanaged_resources.push_back(this);
}

UnmanagedResourceBase::~UnmanagedResourceBase()
{
    if (registered && device != nullptr)
        std::erase(device->unmanaged_resources, this);
}

UnmanagedResourceTexture::UnmanagedResourceTexture(CD3D9Device &owner, std::uint32_t width, std::uint32_t height, std::uint32_t levels, std::uint32_t usage, D3DFORMAT format, D3DPOOL pool)
    : UnmanagedResourceBase(owner, pool), width(width), height(height), levels(levels), usage(usage), format(format), pool(pool)
{
    restoreResource();
}

void UnmanagedResourceTexture::restoreResource()
{
    if (native_texture || !device || !device->native_device)
        return;
    Microsoft::WRL::ComPtr<IDirect3DTexture9> replacement;
    device->checkResult(device->native_device->CreateTexture(width, height, levels, usage, format, pool, replacement.GetAddressOf(), nullptr), "CreateTexture");
    native_texture = std::move(replacement);
}
