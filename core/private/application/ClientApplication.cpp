#include <windows.h>
#include <algorithm>
#include <array>
#include <commctrl.h>
#include <cstddef>
#include <cstdint>
#include <d3d9.h>
#include <deque>
#include <exception>
#include <fcntl.h>
#include <filesystem>
#include <float.h>
#include <format>
#include <iterator>
#include <mbctype.h>
#include <memory>
#include <objbase.h>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <utility>

#include "animation/Animation.h"
#include "application/ClientApplication.h"
#include "audio/GameAudio.h"
#include "binary/Binary.h"
#include "camera/Camera.h"
#include "chat/ChatFilter.h"
#include "collision/Collision.h"
#include "config/InterfaceConfiguration.h"
#include "diagnostics/ClientDiagnostics.h"
#include "diagnostics/Diagnostics.h"
#include "effects/EffectManager.h"
#include "environment/Environment.h"
#include "gameplay/ActorMotion.h"
#include "graphics/d3d9/Device.h"
#include "input/Cursors.h"
#include "input/DirectInputDevices.h"
#include "lighting/LightRuntime.h"
#include "math/Color.h"
#include "network/Network.h"
#include "numeric/Numeric.h"
#include "platform/windows/ApplicationHost.h"
#include "players/PlayerLists.h"
#include "render/CharacterRenderer.h"
#include "render/GameRendering.h"
#include "render/GraphicsRuntime.h"
#include "render/SceneRenderer.h"
#include "resources/FileResources.h"
#include "resources/ModelResources.h"
#include "resources/TerrainResources.h"
#include "resources/TextureRepository.h"
#include "runtime/Clock.h"
#include "scene/SceneObject.h"
#include "script/ConfigText.h"
#include "script/MbcRuntime.h"
#include "shadows/Shadows.h"
#include "spatial/SpatialIndex.h"
#include "terrain/Terrain.h"
#include "text/Fonts.h"
#include "text/Text.h"
#include "ui/GameInterfaceManager.h"
#include "ui/Rendering.h"
#include "ui/ScriptInterface.h"
#include "ui/UiRuntime.h"
#include "vegetation/Vegetation.h"
#include "world/ServerGeometry.h"
#include "world/WorldObjects.h"

std::string_view SferaClientApplication::commandLineArguments(std::string_view commandLine)
{
    commandLine = commandLine.substr(0, commandLine.find('\0'));
    bool quoted = false;
    std::size_t cursor = 0;
    while (cursor < commandLine.size() && (SferaText::byteValue(commandLine[cursor]) > ' ' || quoted))
    {
        if (commandLine[cursor] == '"')
            quoted = !quoted;
        if (::_ismbblead(SferaText::byteValue(commandLine[cursor])) && cursor + 1 < commandLine.size())
            ++cursor;
        ++cursor;
    }
    while (cursor < commandLine.size() && SferaText::byteValue(commandLine[cursor]) <= ' ')
        ++cursor;
    return commandLine.substr(cursor);
}

auto SferaClientApplication::readCommandLineArgument(std::string_view arguments, std::string_view name, std::string &output, std::size_t limit)
{
    output.clear();
    const auto position = arguments.find(name);
    if (position == std::string_view::npos)
        return false;
    auto value = arguments.substr(position + name.size());
    const auto first = value.find_first_not_of(" \t");
    if (first == std::string_view::npos)
        return true;
    value.remove_prefix(first);
    output = value.substr(0, std::min(value.find_first_of(" \t"), limit));
    return true;
}

int SferaClientApplication::run(HINSTANCE instance)
{
    SferaEngineDiagnosticsAdapter::bind();
    SferaClientApplication application;
    lifecycle = SferaClientApplicationLifecycle::Running;
    instance_handle = instance;
    quit_requested = interrupted = fatal_error_in_progress = false;
    try
    {
        configureResourceDirectory();

        SferaClientApplication::initializeStorage();
        ::SetThreadAffinityMask(::GetCurrentThread(), 1);
        const auto arguments = SferaClientApplication::commandLineArguments(::GetCommandLineA());
        if (arguments.find("/15FCE220-0246-58ec-3EH2-968B3072ACF8") != std::string_view::npos)
        {
            ::MessageBoxA(nullptr, "\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 Sphere.exe.",
                          "\316\370\350\341\352\340 \347\340\357\363\361\352\340.", MB_ICONERROR);
            SferaClientApplication::releaseStorage();
            return 0;
        }

        readCommandLineArgument(arguments, "/locale", SferaClientApplication::locale, 9);
        for (const std::string_view directory : {".\\logs", ".\\players"})
            ::CreateDirectoryA(directory.data(), nullptr);
        SphereRenderSceneRenderer::buildColorRemap(1.0, 0.3f);
        SferaClientApplication::instance_handle = instance;
        if (application.initialize())
        {
            resetWorld();
            application.runMainLoop();
        }
        shutdown();
        SferaClientApplication::releaseStorage();
        return 0;
    }
    catch (const SferaClientApplicationExitRequested &)
    {
        return 0;
    }
    catch (const std::exception &error)
    {
        shutdown();
        g_sfera_log_runtime.write(error.what());
        g_sfera_log_runtime.write("\n");
        ::OutputDebugStringA(error.what());
        SphereUIRuntime::setSystemCursorVisible(true);
        ::MessageBoxA(nullptr, error.what(), "Sphere client error", MB_ICONERROR);
        return 1;
    }
    catch (...)
    {
        shutdown();
        ::OutputDebugStringA("Unhandled client exception");
        return 2;
    }
}

template <class T> auto SferaClientApplication::readIntegerSetting(const SferaConfigTextRuntime &settings, std::string_view name, T &output)
{
    int value = 0;
    if (!settings.readInteger(name, value))
        return false;
    if constexpr (std::is_same_v<T, bool>)
        output = value != 0;
    else if constexpr (std::is_unsigned_v<T>)
        output = SferaNumeric::word(value);
    else
        output = value;
    return true;
}

bool SferaClientApplication::initialize()
{
    auto &settings = g_sfera_config_text_runtime;

    g_sfera_files.setErrorReporting(true);
    g_sfera_files.addSearchPath("params");
    g_sfera_files.addSearchPath("mbc");
    g_sfera_log_runtime.initialize();
    const auto comResult = ::CoInitialize(nullptr);
    if (FAILED(comResult))
        throw std::system_error(SferaNumeric::signedWord(comResult), std::system_category(), "CoInitialize");
    com_initialized = true;
    settings.load("config.cfg");
    SferaClientApplication::language = 0;
    readIntegerSetting(settings, "LANG", SferaClientApplication::language);
    if (!SferaClientApplication::locale.empty())
    {
        constexpr std::string_view locales[]{"ru", "en", "pt", "it", "de", "es", "fr"};
        SferaClientApplication::language = 1;
        for (std::uint32_t index = 0; index < std::size(locales); ++index)
            if (std::string_view(SferaClientApplication::locale).substr(0, 2) == locales[index])
            {
                SferaClientApplication::language = index;
                break;
            }
    }
    constexpr std::string_view suffixes[]{"", "_e", "_p", "_i", "_d", "_spa", "_f"};
    g_sfera_font_runtime.language_suffix = SferaClientApplication::language < std::size(suffixes) ? suffixes[SferaClientApplication::language] : "";
    readIntegerSetting(settings, "AUTOFOG", g_sfera_graphics_runtime.auto_fog);
    settings.readFloat("FOGDIST", g_sfera_graphics_runtime.fog_distance);
    g_sfera_graphics_runtime.reflection_quality = 2;
    readIntegerSetting(settings, "REFLQUAL", g_sfera_graphics_runtime.reflection_quality);
    readIntegerSetting(settings, "EFFECTS", g_sfera_effect_manager.effects_enabled);
    readIntegerSetting(settings, "EFFECTDIAG", g_sfera_effect_manager.diagnostics.enabled);
    readIntegerSetting(settings, "LODS", g_sfera_graphics_runtime.lods_enabled);
    readIntegerSetting(settings, "HARDWARE_CURSOR", g_sfera_graphics_runtime.hardware_cursor_enabled);
    readIntegerSetting(settings, "DESCR_AUTO_POPUP", g_sfera_interface.description_auto_popup);
    readIntegerSetting(settings, "INVITE_MESSAGES", g_sfera_interface.invite_messages);

    {
        g_sfera_files.setErrorReporting(false);
        SferaFileManagerScopedFile file(g_sfera_files, g_sfera_files.open("loadcount.bin", _O_RDONLY));
        g_sfera_files.setErrorReporting(true);
        if (file.get() >= 0)
            g_sfera_files.read(file.get(), std::as_writable_bytes(std::span(&GameInterface::loading_total, 1)));
        else
            GameInterface::loading_total = 15000;
    }
    ::InitCommonControls();
    if (!runStartupScripts())
        return false;
    GameInterface::registerNativeWindowClass();
    g_sfera_graphics_runtime.display_width = 640;
    g_sfera_graphics_runtime.display_height = 480;
    settings.load("config.cfg");
    SferaClientApplication::windowed = false;
    readIntegerSetting(settings, "WINDOWED", SferaClientApplication::windowed);
    g_sfera_graphics_runtime.display_width = ::GetSystemMetrics(SM_CXSCREEN);
    g_sfera_graphics_runtime.display_height = ::GetSystemMetrics(SM_CYSCREEN);
    g_sfera_graphics_runtime.display_depth_bits = 16;
    readIntegerSetting(settings, "XRES", g_sfera_graphics_runtime.display_width);
    readIntegerSetting(settings, "YRES", g_sfera_graphics_runtime.display_height);
    readIntegerSetting(settings, "DEPTH", g_sfera_graphics_runtime.display_depth_bits);
    readIntegerSetting(settings, "GRASS", g_sfera_graphics_runtime.grass_depth);
    settings.readFloat("LOD_DISTANCE", g_sfera_graphics_runtime.minimum_lod_distance);
    settings.readFloat("MIN_LOD_DIST", g_sfera_graphics_runtime.lod_distance);
    readIntegerSetting(settings, "POSTEFFECTS", g_sfera_graphics_runtime.post_effects_enabled);
    {
        int configured_fov = static_cast<int>(SferaGraphicsRuntime::default_field_of_view);
        const bool had_fov = settings.readInteger("FOV", configured_fov);
        const int clamped_fov = std::clamp(configured_fov, static_cast<int>(SferaGraphicsRuntime::minimum_field_of_view), static_cast<int>(SferaGraphicsRuntime::maximum_field_of_view));
        g_sfera_graphics_runtime.field_of_view_degrees = static_cast<std::uint32_t>(clamped_fov);
        if (!had_fov || configured_fov != clamped_fov)
        {
            settings.writeValue("FOV", std::to_string(clamped_fov), false);
            settings.save();
        }
    }
    if (g_sfera_graphics_runtime.minimum_lod_distance == 0.0f)
        g_sfera_graphics_runtime.minimum_lod_distance = 23.0f;
    if (g_sfera_graphics_runtime.lod_distance == 0.0f)
        g_sfera_graphics_runtime.lod_distance = 20.0f;
    const std::array<std::pair<std::string_view, bool *>, 3> landscapes{
        {{"landscape_hr", &TerrainAssets::high_resolution_assets}, {"landscape_ph", &TerrainAssets::alternate_ph_assets}, {"landscape_rd", &TerrainAssets::alternate_rd_assets}}};
    for (const auto &[path, enabled] : landscapes)
    {
        const DWORD attributes = ::GetFileAttributesA(path.data());
        *enabled = attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
    }
    GameInterface::createNativeWindow();
    g_sfera_files.addSearchPath("landscape");
    for (const auto &[path, enabled] : landscapes)
        if (*enabled != 0)
            g_sfera_files.addSearchPath(path);
    g_sfera_direct_input_runtime.initialize(SferaClientApplication::main_window);
    g_sfera_graphics_runtime.initialize();
    if (!g_sfera_graphics_runtime.d3d_runtime->supports_post_effects)
        g_sfera_graphics_runtime.post_effects_enabled = false;
    CCursorManager::instance().select(g_sfera_graphics_runtime.hardware_cursor_enabled);
    GameInterface::createWindow(0, 0, g_sfera_graphics_runtime.display_width - 1, g_sfera_graphics_runtime.display_height - 1, 0, 0);
    for (auto &vertex : SphereUIInterfaceRenderer::glyph_vertices)
    {
        vertex.z = 0.0f;
        vertex.rhw = 1.0f;
        vertex.specular = 0;
    }
    ::ShowCursor(FALSE);
    ::ShowCursor(TRUE);
    SphereUIRuntime::setSystemCursorVisible(false);
    for (std::uint32_t index = 0; index < 2; ++index)
    {
        const std::string path = "fonts\\font" + std::to_string(index + 1) +
                                 (SferaClientApplication::language != 0 && SferaClientApplication::language != 1 ? g_sfera_font_runtime.language_suffix : "") + ".pcx";
        g_sfera_font_runtime.load(index, path, 1, 1, index == 0 ? 5 : 3);
    }
    SphereRenderModelPose::coordinate_basis = {};
    SphereRenderModelPose::coordinate_basis.m[2][0] = 1.0f;
    SphereRenderModelPose::coordinate_basis.m[0][1] = -1.0f;
    SphereRenderModelPose::coordinate_basis.m[1][2] = -1.0f;
    SphereRenderModelPose::coordinate_basis.m[3][3] = 1.0f;
    for (std::size_t index = 0; index < std::size(g_sfera_motion.material_scale); ++index)
        g_sfera_motion.material_scale[index] = SferaNumeric::real32(index / 6.0);
    constexpr float weights[]{2.0f, 0.2f, 0.75f, 1.2f, 2.5f, 3.0f, 4.0f};
    for (std::size_t index = 0; index < std::size(weights); ++index)
        g_sfera_motion.surface_friction[index] = weights[index];
    TerrainTextureCache::initialize();
    g_sfera_motion.initializeResponseCurve();
    return true;
}

void CSphereError::write(std::string_view text)
{
    SferaClientApplication::terminateWithError(text);
}

SferaClientApplication::~SferaClientApplication() noexcept
{
    shutdown();
    releaseStorage();
}

auto SferaClientApplication::finishShutdownOperation(auto &&operation) noexcept
{
    try
    {
        operation();
    }
    catch (const std::exception &error)
    {
        ::OutputDebugStringA(error.what());
    }
    catch (...)
    {
        ::OutputDebugStringA("Resource shutdown failed");
    }
}

void SferaClientApplication::shutdown() noexcept
{
    if (lifecycle == SferaClientApplicationLifecycle::Stopping || lifecycle == SferaClientApplicationLifecycle::Stopped || lifecycle == SferaClientApplicationLifecycle::Dormant)
        return;
    lifecycle = SferaClientApplicationLifecycle::Stopping;

    finishShutdownOperation(&SferaClientApplication::stopInterpreterTick);
    finishShutdownOperation(&SferaClientApplication::shutdownNetwork);
    // Registrations remain alive while process-owned UI/world resources are removed.
    finishShutdownOperation(&SferaClientApplication::shutdownInterpreter);
    interpreter_initialized = false;
    finishShutdownOperation(&SferaClientApplication::shutdownEffects);
    finishShutdownOperation(&SferaClientApplication::shutdownSound);
    finishShutdownOperation(&SferaClientApplication::shutdownInterface);
    CCursorManager::shutdown();
    finishShutdownOperation(&SferaClientApplication::shutdownShadows);
    g_sfera_vegetation.animation.reset();
    finishShutdownOperation(&SferaClientApplication::clearWorldObjects);
    finishShutdownOperation(&SferaClientApplication::clearVegetation);
    g_sfera_player_lists.clear();
    g_sfera_models.clear();
    SphereRenderSceneRenderer::characters.reset();
    g_sfera_interface.chat_filter.reset();
    g_sfera_world_objects.contours.reset();
    g_sfera_weather_runtime.highres.reset();
    g_sfera_weather_runtime.standard.reset();
    SceneSky::environment.reset();
    SceneSky::high_resolution_environment.reset();
    SphereRenderSceneRenderer::environment_zones.reset();
    SphereRenderSceneRenderer::alternate_environment_zones.reset();
    g_sfera_direct_input_runtime.release();
    g_sfera_direct_input_runtime.key_queue.clear();
    g_sfera_direct_input_runtime.character_queue.clear();
    g_sfera_font_runtime.clear();
    finishShutdownOperation(&SferaClientApplication::releaseTerrainTextures);
    finishShutdownOperation(&SferaClientApplication::releaseTerrainAssets);
    g_sfera_textures.clear();
    g_sfera_graphics_runtime.d3d_runtime.reset();
    if (main_window != nullptr)
        ::DestroyWindow(std::exchange(main_window, nullptr));
    if (window_class_registered)
    {
        ::UnregisterClassA(GameInterface::nativeWindowClassName.data(), instance_handle);
        window_class_registered = false;
    }
    if (com_initialized)
    {
        ::CoUninitialize();
        com_initialized = false;
    }
    finishShutdownOperation(&SferaClientApplication::finishShutdownLog);
    resources_loaded = main_loop_started = application_active = false;
    lifecycle = SferaClientApplicationLifecycle::Stopped;
}

[[noreturn]] void SferaClientApplication::terminateWithError(std::string_view message)
{
    if (fatal_error_in_progress)
        throw std::runtime_error(message.empty() ? std::string("Client error") : std::string(message));
    fatal_error_in_progress = true;
    std::string description = "ServerN=" + std::to_string(server_number) + "  " + std::string(message);
    if (const auto context = WorldDiagnostics::scriptContext())
    {
        description += '\n';
        description += *context;
    }
    throw std::runtime_error(description);
}

[[noreturn]] void SferaClientApplication::arrayBoundsError(int index)
{
    std::string message;
    if (index < 0)
        message = std::format("BoundCheckArray error: index less than zero\n");
    else
        message = std::format("BoundCheckArray error: index out of range {}\n", index);
    terminateWithError(message);
}

void SferaClientApplication::stopInterpreterTick()
{
    if (interpreter_initialized && !g_sfera_mbc_runtime.final_shutdown)
    {
        g_sfera_mbc_runtime.final_shutdown = true;
        g_sfera_mbc_runtime.halt_state = SferaMbcRuntimeHaltState::Requested;
        g_sfera_mbc_runtime.tick();
    }
}

void SferaClientApplication::shutdownNetwork()
{
    g_sfera_network_runtime.shutdown();
}

void SferaClientApplication::shutdownInterpreter()
{
    g_sfera_mbc_runtime.shutdown();
}

void SferaClientApplication::shutdownEffects()
{
    g_sfera_effect_manager.shutdown();
}

void SferaClientApplication::shutdownSound()
{
    g_sfera_sound_runtime.shutdown();
}

void SferaClientApplication::shutdownInterface()
{
    g_sfera_interface.shutdown();
}

void SferaClientApplication::shutdownShadows()
{
    ShadowMap::shutdown();
}

void SferaClientApplication::clearWorldObjects()
{
    g_sfera_world_objects.clear();
}

void SferaClientApplication::clearVegetation()
{
    g_sfera_vegetation.clear();
}

void SferaClientApplication::releaseTerrainTextures()
{
    TerrainTextureCache::release();
}

void SferaClientApplication::releaseTerrainAssets()
{
    TerrainAssets::releaseAll();
}

void SferaClientApplication::finishShutdownLog()
{
    g_sfera_log_runtime.writeTimestamp("**** Quit: ");
    g_sfera_log_runtime.write("\n");
    if (std::cmp_greater(g_sfera_files.fileSize("Error.log"), g_sfera_log_runtime.size_limit))
        g_sfera_files.keepTail("Error.log", g_sfera_log_runtime.size_limit);
}

void SferaClientApplication::releaseStorage() noexcept
{
    if (lifecycle == SferaClientApplicationLifecycle::Running)
        shutdown();
    g_sfera_contacts.clear();
    if (!SferaClientApplication::storage_initialized)
        return;
    SferaClientApplication::storage_initialized = false;
    try
    {
        g_sfera_world_objects.clear();
        g_sfera_vegetation.clear();
    }
    catch (...)
    {
        ::OutputDebugStringA("World storage cleanup failed");
    }
    SphereUIInterfaceConfiguration::close();
    g_sfera_interface.options.edited_chat_fonts.clear();
    g_sfera_interface.options.saved_chat_fonts.clear();
    SphereRenderSceneRenderer::object_order.clear();
    SphereRenderModelPose::attachment_transforms.fill({});
    SphereRenderModelPose::bone_transforms.clear();
    g_sfera_light_runtime.invalidateActiveLights();
    g_sfera_light_runtime.visible_handles.clear();
    g_sfera_light_runtime.handles.clear();
    WorldGuiControls::elements.clear();
    GameInterface::windows.clear();
    GameInterface::active_window = UINT32_MAX;
    try
    {
        TerrainAssets::releaseAll();
    }
    catch (...)
    {
        ::OutputDebugStringA("Terrain storage cleanup failed");
    }
    g_sfera_world_spatial = {};
    TerrainAssets::regions.clear();
    TerrainAssets::map.fill({});

    g_sfera_effect_manager.render_slots.clear();
    g_sfera_error_log_runtime.clear();
}

void SferaClientApplication::initializeStorage()
{
    if (SferaClientApplication::storage_initialized)
        return;
    unsigned int control = 0u;
    if (::_controlfp_s(&control, _PC_53, _MCW_PC) != 0)
        throw std::runtime_error("Cannot initialize floating-point precision");
    ::HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption, nullptr, 0u);
    SferaClientApplication::storage_initialized = true;
    g_sfera_effect_manager.clearListeners();
    g_sfera_error_log_runtime.initialize();
    g_sfera_config_text_runtime.clear();
    g_sfera_mbc_runtime.inverse_coordinate_scale = 1.0f / 40.0f;
    g_sfera_camera = SphereRenderGameCamera{};
    g_sfera_effect_manager.render_slots.resize(10000u);

    WorldGuiControls::elements.resize(7000u);
    g_sfera_world_objects.object_handles.resize(500000u);
    g_sfera_world_objects.extended_object_handles.resize(30000u);
    GameInterface::windows.resize(100u);
    g_sfera_light_runtime.handles.resize(1000u);
    g_sfera_light_runtime.visible_handles.reserve(1000u);
    g_sfera_light_runtime.invalidateActiveLights();
    SphereRenderModelPose::bone_transforms.resize(256u);
    SphereRenderModelPose::attachment_transforms.fill({});
    SphereRenderSceneRenderer::object_order.reserve(10000u);
}

auto SferaClientApplication::containsClientResources(const std::filesystem::path &directory)
{
    std::error_code error;
    return std::filesystem::is_regular_file(directory / L"mbc" / L"_main.mbc", error);
}

void SferaClientApplication::configureResourceDirectory()
{
    std::filesystem::path root;
    const DWORD required = ::GetEnvironmentVariableW(L"SFERA_CLIENT_ROOT", nullptr, 0);
    if (required != 0)
    {
        std::wstring configured(required, L'\0');
        const DWORD length = ::GetEnvironmentVariableW(L"SFERA_CLIENT_ROOT", configured.data(), required);
        if (length == 0 || length >= required)
            throw std::runtime_error("Cannot read SFERA_CLIENT_ROOT");
        configured.resize(length);
        root = std::filesystem::absolute(std::filesystem::path(configured));
        if (!containsClientResources(root))
            throw std::runtime_error("SFERA_CLIENT_ROOT does not contain mbc\\_main.mbc");
    }
    else
    {
        std::wstring executable(512, L'\0');
        for (;;)
        {
            const DWORD length = ::GetModuleFileNameW(nullptr, executable.data(), SferaNumeric::lowWord(executable.size()));
            if (length == 0)
                throw std::runtime_error("Cannot determine the client executable path");
            if (length + 1 < executable.size())
            {
                executable.resize(length);
                break;
            }
            if (executable.size() >= 32768)
                throw std::length_error("Client executable path is too long");
            executable.resize(std::min<std::size_t>(executable.size() * 2, 32768));
        }
        const std::array<std::filesystem::path, 2> starts{std::filesystem::current_path(), std::filesystem::path(executable).parent_path()};
        for (auto candidate : starts)
        {
            for (unsigned depth = 0; depth < 12 && !candidate.empty(); ++depth)
            {
                if (containsClientResources(candidate))
                {
                    root = candidate;
                    break;
                }
                const auto parent = candidate.parent_path();
                if (parent == candidate)
                    break;
                candidate = parent;
            }
            if (!root.empty())
                break;
        }
        if (root.empty())
            throw std::runtime_error("Unable to locate mbc\\_main.mbc. Set SFERA_CLIENT_ROOT to the client resource directory.");
    }
    if (!::SetCurrentDirectoryW(root.c_str()))
        throw std::system_error(SferaNumeric::signedWord(::GetLastError()), std::system_category(), "SetCurrentDirectoryW");
}

template <class T> auto SferaClientApplication::loadConfigurationOwner(std::unique_ptr<T> &owner, const std::string &path)
{
    auto replacement = std::make_unique<T>();
    replacement->load(path);
    owner = std::move(replacement);
}

void SferaClientApplication::loadResources()
{
    if (SferaClientApplication::resources_loaded)
        return;
    g_sfera_interface.showLoadingScreen(true, g_sfera_graphics_runtime.display_width, g_sfera_graphics_runtime.display_height, SferaClientApplication::language != 0);
    ::Sleep(50);
    for (int refresh = 0; refresh < 2; ++refresh)
    {
        g_sfera_graphics_runtime.rebuild_percent = -1;
        GameInterface::updateLoadingProgress(0);
    }
    ::Sleep(50);
    g_sfera_effect_manager.initialize();
    ::Sleep(50);
    g_sfera_materials.load("models\\materls.mtr");
    ::Sleep(50);
    TerrainAssets::loadMap();
    ::Sleep(50);

    loadConfigurationOwner(SceneSky::environment, "sky.txt");
    if (TerrainAssets::high_resolution_assets)
        loadConfigurationOwner(SceneSky::high_resolution_environment, "landscape_hr\\sky_hr.txt");
    ::Sleep(50);
    g_sfera_models.initialize();
    g_sfera_models.addFolder("models\\");
    if (TerrainAssets::high_resolution_assets)
        g_sfera_models.addFolder("models_hr\\");
    if (TerrainAssets::alternate_ph_assets)
        g_sfera_models.addFolder("models_ph\\");
    if (TerrainAssets::alternate_rd_assets)
        g_sfera_models.addFolder("models_rd\\");
    g_sfera_models.finishRegistration();
    constexpr std::string_view folders[]{"xadd\\"};
    auto characters = std::make_unique<SphereRenderCharacterModels>();
    characters->load(folders);
    characters->setDistances(g_sfera_graphics_runtime.lod_distance, g_sfera_graphics_runtime.minimum_lod_distance);
    if (SphereRenderSceneRenderer::characters)
        SphereRenderSceneRenderer::characters->clear();
    SphereRenderSceneRenderer::characters = std::move(characters);
    ::Sleep(50);
    auto contours = std::make_unique<Contours>(2000, 2999);
    contours->load();
    g_sfera_world_objects.contours = std::move(contours);
    ::Sleep(50);
    loadConfigurationOwner(g_sfera_weather_runtime.standard, "landscape\\weather.txt");
    if (TerrainAssets::high_resolution_assets)
        loadConfigurationOwner(g_sfera_weather_runtime.highres, "landscape_hr\\weather_hr.txt");
    ::Sleep(50);
    for (std::uint32_t expectedHandle = 0u; expectedHandle < 2u; ++expectedHandle)
    {
        const auto handle = g_sfera_world_objects.create("cam_cube", nullptr, expectedHandle == 0u ? 0u : 5u, true);
        if (handle != expectedHandle)
        {
            terminateWithError(std::format("Camera initialization: expected handle {}, got {}", expectedHandle, handle));
        }
        auto *camera = g_sfera_world_objects.extendedObject(handle);
        if (camera == nullptr)
            terminateWithError(std::format("Camera object {} was not created", handle));
        if (expectedHandle == 0u)
            camera->render_enabled = false;
    }
    g_sfera_vegetation.initialize();
    ::Sleep(50);
    g_sfera_interface.chat_filter = std::make_unique<SphereUIChatFilter>();
    SferaClientApplication::resources_loaded = true;
}

int SferaClientApplication::frame_samples{};
std::uint64_t SferaClientApplication::frame_anchor{};
uint32_t SferaClientApplication::frame_elapsed_ticks{};
bool SferaClientApplication::main_loop_started{};
HINSTANCE SferaClientApplication::instance_handle{};
bool SferaClientApplication::interpreter_initialized{};
uint32_t SferaClientApplication::language{};
bool SferaClientApplication::resources_loaded{};
bool SferaClientApplication::windowed{};
HWND SferaClientApplication::main_window{};
float SferaClientApplication::measured_fps{};
bool SferaClientApplication::interrupted{};
bool SferaClientApplication::quit_requested{};
bool SferaClientApplication::startup_complete{};
uint32_t SferaClientApplication::desktop_width{};
bool SferaClientApplication::application_active{};
SferaClientApplicationLifecycle SferaClientApplication::lifecycle = SferaClientApplicationLifecycle::Dormant;
bool SferaClientApplication::com_initialized = false;
bool SferaClientApplication::window_class_registered = false;
bool SferaClientApplication::fatal_error_in_progress{};
int SferaClientApplication::server_number{};
uint32_t SferaClientApplication::desktop_height{};
bool SferaClientApplication::storage_initialized{};

constexpr WPARAM kSystemCommandMask = 0xFFF0u;

LRESULT CALLBACK GameInterface::main_window_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) noexcept
{
    try
    {
        switch (message)
        {
        case WM_ACTIVATEAPP:
            SferaClientApplication::application_active = wparam != 0;
            g_sfera_direct_input_runtime.focusChanged(wparam != 0);
            CCursorManager::focusChanged(wparam != 0);
            if (wparam == 0)
            {
                g_sfera_direct_input_runtime.mouse = {};
                g_sfera_direct_input_runtime.character_queue.clear();
                g_sfera_direct_input_runtime.key_queue.clear();
                g_sfera_direct_input_runtime.virtual_key = 0;
                g_sfera_direct_input_runtime.character = 0;
                g_sfera_interface.drag_drop_active = false;
            }
            g_sfera_sound_runtime.refreshMusicVolume();
            g_sfera_sound_runtime.volume_refresh_frames = 0.0;
            g_sfera_sound_runtime.volume_refresh_active = true;
            return 0;
        case WM_CAPTURECHANGED:
        case WM_CANCELMODE:
            g_sfera_interface.drag_drop_active = false;
            if (::GetCapture() == window)
                ::ReleaseCapture();
            return 0;
        case WM_QUERYENDSESSION:
            ::PostQuitMessage(0);
            return 0;
        case WM_CLOSE:
            ::PostQuitMessage(0);
            return 0;
        case WM_SETCURSOR:
            if (CCursorManager::hasActiveCursor())
            {
                return TRUE;
            }
            return 0;
        case WM_KEYDOWN:
            if (g_sfera_direct_input_runtime.binding_capture != 0u)
            {
                g_sfera_direct_input_runtime.binding_key = SferaNumeric::lowWord(wparam);
                return 0;
            }
            if (g_sfera_direct_input_runtime.text_filter != 0u)
            {
                const std::uint32_t key = SferaNumeric::lowWord(wparam);
                if (key < 256u && g_sfera_font_runtime.glyphs[key].defined != 0u && g_sfera_direct_input_runtime.allowed_glyphs[key] == 0u)
                {
                    return 0;
                }
            }
            if (g_sfera_direct_input_runtime.key_queue.size() < 30u)
            {
                g_sfera_direct_input_runtime.key_queue.push_back(SferaNumeric::lowWord(wparam));
            }
            return 0;
        case WM_CHAR:
        {
            const std::uint32_t ch = SferaNumeric::lowWord(wparam);
            if (ch < 256u && g_sfera_font_runtime.glyphs[ch].defined == 1u && g_sfera_direct_input_runtime.character_queue.size() < 30u)
            {
                g_sfera_direct_input_runtime.character_queue.push_back(ch);
            }
            return 0;
        }
        case WM_SYSCOMMAND:
        {
            const WPARAM command = wparam & kSystemCommandMask;
            if (command == SC_SCREENSAVE || command == SC_MONITORPOWER)
            {
                return 0;
            }
            return ::DefWindowProcA(window, message, wparam, lparam);
        }
        default:
            return ::DefWindowProcA(window, message, wparam, lparam);
        }
    }
    catch (...)
    {
        SferaClientApplication::interrupted = true;
        return 0;
    }
}

void GameInterface::registerNativeWindowClass()
{
    WNDCLASSEXA windowClass{};
    windowClass.cbSize = SferaNumeric::lowWord(sizeof(windowClass));
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc = &main_window_proc;
    windowClass.hInstance = SferaClientApplication::instance_handle;
    windowClass.hIcon = ::LoadIconA(windowClass.hInstance, MAKEINTRESOURCEA(113));
    windowClass.hCursor = ::LoadCursorW(nullptr, IDC_ARROW);
    windowClass.hbrBackground = reinterpret_cast<HBRUSH>(::GetStockObject(BLACK_BRUSH));
    windowClass.lpszClassName = nativeWindowClassName.data();
    windowClass.hIconSm = windowClass.hIcon;
    if (::RegisterClassExA(&windowClass) == 0)
        WorldDiagnostics::fail("RegisterClassEx() failed! => init_main_window_class()");
    SferaClientApplication::window_class_registered = true;
}

void GameInterface::createNativeWindow()
{
    const auto desktopWidth = ::GetSystemMetrics(SM_CXSCREEN);
    const auto desktopHeight = ::GetSystemMetrics(SM_CYSCREEN);
    SferaClientApplication::desktop_width = desktopWidth;
    SferaClientApplication::desktop_height = desktopHeight;
    auto &graphics = g_sfera_graphics_runtime;
    graphics.display_width = std::max(800, graphics.display_width);
    graphics.display_height = std::max(600, graphics.display_height);
    auto width = graphics.display_width;
    auto height = graphics.display_height;
    DWORD style = WS_POPUP;
    int left = 0, top = 0;
    if (SferaClientApplication::windowed)
    {
        const DWORD windowedStyle = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
        RECT rectangle{0, 0, width, height};
        if (!::AdjustWindowRect(&rectangle, windowedStyle, FALSE))
            WorldDiagnostics::fail("AdjustWindowRect() failed! => init_main_window()");
        const auto outerHeight = rectangle.bottom - rectangle.top;
        if (outerHeight >= desktopHeight)
            SferaClientApplication::windowed = false;
        else
        {
            style = windowedStyle;
            width = rectangle.right - rectangle.left;
            height = outerHeight;
            left = (desktopWidth - width) / 2;
            top = (desktopHeight - height) / 2;
        }
    }
    const auto instance = SferaClientApplication::instance_handle;
    const auto window = ::CreateWindowExA(0, nativeWindowClassName.data(), "Sphere", style, left, top, width, height, nullptr, nullptr, instance, nullptr);
    SferaClientApplication::main_window = window;
    if (window == nullptr)
        WorldDiagnostics::fail("CreateWindowEx() failed! => init_main_window()");
    ::ShowWindow(window, SW_SHOWNORMAL);
    ::InvalidateRect(window, nullptr, TRUE);
    ::UpdateWindow(window);
    ::BringWindowToTop(window);
}

void SferaClientApplication::dispatch_application_messages()
{
    MSG message{};
    while (::PeekMessageA(&message, nullptr, 0, 0, PM_REMOVE))
    {
        if (message.message == WM_QUIT)
        {
            SferaClientApplication::quit_requested = true;
            return;
        }
        ::TranslateMessage(&message);
        ::DispatchMessageA(&message);
    }
}

void SferaClientApplication::resetWorld()
{
    g_sfera_world_objects.destroyAll();
    g_sfera_sound_runtime.initialize();
    ShadowMap::initialize(1);
    WorldGuiControls::destroyAllText();

    g_sfera_interface.default_cursor_name = "cursor1";
    g_sfera_world_objects.controlled_object_handle = UINT32_MAX;
    g_sfera_interface.world_interaction_enabled = false;
    g_sfera_motion.acceleration = {};
    SphereRenderSceneRenderer::visible_character_parts = UINT8_MAX;
    GameInterface::active_window = UINT32_MAX;
    SphereRenderModelPose::scale = {};
    SphereRenderModelPose::scale.y = 1.0f;
    g_sfera_direct_input_runtime.text_filter = 0;
    g_sfera_interface.overlay_alpha = 0;
    for (auto &entry : TerrainTextureCache::entries)
    {
        entry.owner = nullptr;
        entry.use_count = 0;
    }
    {
        auto zones = std::make_unique<EnvironmentZones>();
        zones->load("Landscape\\zoning.cfg");
        SphereRenderSceneRenderer::environment_zones = std::move(zones);
    }
    {
        auto zones = std::make_unique<EnvironmentZones>();
        zones->load("Landscape\\zoningHaron.cfg");
        SphereRenderSceneRenderer::alternate_environment_zones = std::move(zones);
    }
}

int SferaClientApplication::advanceClock()
{
    const std::uint32_t current = SferaNumeric::lowWord(WorldClock::nowTicks());
    const auto elapsed = SferaNumeric::signedWord(SferaNumeric::word(tick_remainder_) + current - previous_tick_);
    previous_tick_ = current;
    tick_remainder_ = std::min(elapsed, 10000);
    const auto steps = (tick_remainder_ + 26) / 52;
    tick_remainder_ -= steps * 52;
    return steps;
}

bool SferaClientApplication::runStartupScripts()
{
    g_sfera_mbc_runtime.initialize();
    SferaClientApplication::interpreter_initialized = true;
    previous_tick_ = SferaNumeric::lowWord(WorldClock::nowTicks());
    tick_remainder_ = 0;
    SferaClientApplication::startup_complete = false;
    for (;;)
    {
        const auto steps = advanceClock();
        for (int index = 0; index < steps; ++index)
        {
            g_sfera_mbc_runtime.tick();
            if (SferaClientApplication::startup_complete)
                return true;
        }
        dispatch_application_messages();
        if (SferaClientApplication::quit_requested)
            return false;
        ::Sleep(10);
    }
}

auto SferaClientApplication::takeQueuedEffect(std::deque<std::uint32_t> &queue, std::uint32_t &current)
{
    if (queue.empty())
        return;
    current = queue.front();
    queue.pop_front();
}

void SferaClientApplication::updateSimulation()
{
    takeQueuedEffect(g_sfera_direct_input_runtime.character_queue, g_sfera_direct_input_runtime.character);
    takeQueuedEffect(g_sfera_direct_input_runtime.key_queue, g_sfera_direct_input_runtime.virtual_key);
    const auto key = g_sfera_direct_input_runtime.takeKeyPress();
    g_sfera_direct_input_runtime.scan_code = key;
    if (SferaClientApplication::interrupted)
    {
        SferaClientApplication::interrupted = false;
        throw std::runtime_error("Client execution interrupted");
    }
    g_sfera_direct_input_runtime.pollKeyboard();
    auto &mouse = g_sfera_direct_input_runtime.mouse;
    mouse = g_sfera_direct_input_runtime.pollMouse();
    if ((g_sfera_direct_input_runtime.view_adjust_state & SferaInputDevices::pressedMask) != 0)
    {
        mouse.dx = 0;
        mouse.dy = 0;
    }
    GameInterface::updateInput();
    g_sfera_interface.update(SferaNumeric::lowByte(g_sfera_direct_input_runtime.virtual_key), SferaNumeric::lowByte(g_sfera_direct_input_runtime.character), mouse.buttons,
                             SferaNumeric::lowByte(mouse.wheel));
    if (g_sfera_motion.control_mode == 1 && !g_sfera_interface.world_interaction_enabled && g_sfera_motion.orientation_blocked == 0)
    {
        g_sfera_motion.updateOrientation();
    }
    else
    {
        g_sfera_motion.displacement = {};
        g_sfera_motion.acceleration = {};
        g_sfera_direct_input_runtime.pollMouse();
    }
    g_sfera_mbc_runtime.tick();
    if (g_sfera_motion.control_mode == 0)
        g_sfera_motion.updateControlled(1.0f / 192.0f);
    if (++object_update_ticks_ == 4)
    {
        object_update_ticks_ = 0;
        g_sfera_motion.updateObjects(1.0f / 48.0f);
    }
    if (++effect_update_ticks_ == 6)
    {
        SphereRenderSceneRenderer::adaptFog();
        effect_update_ticks_ = 0;
        if (SferaClientApplication::resources_loaded)
            g_sfera_effect_manager.updateActiveEffects();
    }
    if (++maintenance_ticks_ == 6)
    {
        maintenance_ticks_ = 0;
        if (++SphereRenderSceneRenderer::texture_animation_frame == 32)
            SphereRenderSceneRenderer::texture_animation_frame = 0;
        TerrainAssets::evictUnused();
    }
    g_sfera_world_objects.updateExtendedSpatialIndices();
    g_sfera_direct_input_runtime.virtual_key = 0;
    g_sfera_direct_input_runtime.character = 0;
    auto &phase = SceneSky::animation_phase;
    const double precise_phase = phase;
    constexpr double phase_step = 0.0005f;
    phase = SferaNumeric::real32(precise_phase + phase_step);
    if (phase > 1.0f)
        phase = SferaNumeric::real32(phase - 1.0);
    g_sfera_vegetation.updateGrassView();
}

void SferaClientApplication::renderFrame()
{
    if (SferaClientApplication::resources_loaded)
    {
        bool highResolution = false;
        if (TerrainAssets::high_resolution_assets)
        {
            const auto *reference = g_sfera_world_objects.object(1);
            if (reference == nullptr)
                WorldDiagnostics::fail("Weather update: missing reference object");
            highResolution = reference->position.y > 300.0f && reference->position.y < 800.0f;
        }
        auto *weather = highResolution ? g_sfera_weather_runtime.highres.get() : g_sfera_weather_runtime.standard.get();
        if (weather == nullptr)
            weather = highResolution ? g_sfera_weather_runtime.standard.get() : g_sfera_weather_runtime.highres.get();
        if (weather != nullptr)
            weather->update(SferaNumeric::signedWord(WorldClock::calendarTicks()), g_sfera_graphics_runtime.environment_factor, g_sfera_weather_runtime.current,
                            SphereWorldVegetation::alternatePatterns());
        if (g_sfera_sound_runtime.volume_refresh_active)
        {
            const bool increase = g_sfera_sound_runtime.volume_refresh_direction;
            g_sfera_sound_runtime.adjustMusicVolume(increase ? 1 : -1);
            g_sfera_sound_runtime.volume_refresh_direction = !increase;
            g_sfera_sound_runtime.volume_refresh_frames = SferaNumeric::real32(g_sfera_sound_runtime.volume_refresh_frames + 1.0);
            if (g_sfera_sound_runtime.volume_refresh_frames > 50.0f)
                g_sfera_sound_runtime.volume_refresh_active = false;
        }
        SferaGameSceneRenderer::drawFrame();
        g_sfera_effect_manager.writeDiagnostics();
        return;
    }
    if (!SferaClientApplication::application_active)
    {
        if (!SferaClientApplication::windowed)
            return;
        ::Sleep(100);
    }
    auto &device = *g_sfera_graphics_runtime.d3d_runtime;
    SceneScope scene(device);
    if (!scene)
        return;
    device.checkResult(device.native_device->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, SferaColor::rgba(0u, 0u, 0u).argb(), 1.0f, 0), "Clear");
    GameInterface::drawFrame();
    scene.finish();
    device.present();
}

void SferaClientApplication::runMainLoop()
{
    object_update_ticks_ = effect_update_ticks_ = maintenance_ticks_ = 0;
    SferaClientApplication::main_loop_started = true;
    previous_tick_ = SferaNumeric::lowWord(WorldClock::nowTicks());
    tick_remainder_ = 0;
    for (;;)
    {
        const auto steps = advanceClock();
        if (steps == 0)
        {
            const auto delay = (52 - tick_remainder_) / 10;
            if (delay > 50)
                ::Sleep(19);
            else if (delay > 1)
                ::Sleep(delay - 1);
        }
        for (int index = 0; index < steps; ++index)
            updateSimulation();
        renderFrame();
        if (SferaClientApplication::resources_loaded)
            g_sfera_sound_runtime.update();
        dispatch_application_messages();
        if (SferaClientApplication::quit_requested)
            return;
    }
}

HWND SferaApplicationHost::mainWindow()
{
    return SferaClientApplication::main_window;
}

bool SferaApplicationHost::active()
{
    return SferaClientApplication::application_active;
}

float SferaApplicationHost::measuredFramesPerSecond()
{
    return SferaClientApplication::measured_fps;
}

std::uint32_t SferaApplicationHost::frameElapsedTicks()
{
    return SferaClientApplication::frame_elapsed_ticks;
}

void SferaGraphicsRuntime::initializeWater()
{
    d3d_runtime->reflection_target = std::make_unique<UnmanagedResourceTexture>(*d3d_runtime, 256u, 256u, 1u, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT);
    water_materials[1] = {1u, 1u, 0.7f, 0.4f, 0.15f, 0.12f};
    water_materials[2] = {2u, 2u, 0.6f, 0.2f, 0.2f, 0.02f};
    water_materials[3] = {1u, 2u, 0.6f, 0.33f, 0.23f, 0.08f};
    water_materials[4] = {2u, 2u, 0.7f, 0.35f, 0.2f, 0.06f};
    water_materials[5] = {3u, 3u, 0.8f, 0.5f, 0.1f, 0.08f};
    water_materials[6] = {4u, 4u, 1.0f, 0.45f, 0.0f, 0.04f};
    water_materials[7] = {3u, 3u, 0.6f, 0.4f, 0.1f, 0.04f};
}

void SferaGraphicsRuntime::initialize()
{
    d3d_runtime = std::make_unique<CD3D9Device>();
    auto &device = *d3d_runtime;
    device.initialize(SferaClientApplication::main_window, display_width, display_height, g_sfera_graphics_runtime.display_depth_bits, SferaClientApplication::windowed);
    if (device.supports_post_effects)
    {
        device.post_effects = std::make_unique<CPostEffectsMgr>(device);
        device.post_effects->setEnabled(true);
    }
    g_sfera_textures.initialize();
    g_sfera_textures.addFolder("landscape\\");
    if (TerrainAssets::high_resolution_assets)
        g_sfera_textures.addFolder("landscape_hr\\");
    if (TerrainAssets::alternate_ph_assets)
        g_sfera_textures.addFolder("landscape_ph\\");
    if (TerrainAssets::alternate_rd_assets)
        g_sfera_textures.addFolder("landscape_rd\\");
    g_sfera_textures.addFolder("models\\textures\\");
    if (TerrainAssets::high_resolution_assets)
        g_sfera_textures.addFolder("models_hr\\textures\\");
    if (TerrainAssets::alternate_ph_assets)
        g_sfera_textures.addFolder("models_ph\\textures\\");
    if (TerrainAssets::alternate_rd_assets)
        g_sfera_textures.addFolder("models_rd\\textures\\");
    g_sfera_textures.addFolder("textures\\");
    g_sfera_textures.addFolder("textures\\fx\\");
    g_sfera_textures.addFolder("textures\\emblems\\");
    g_sfera_textures.addFolder("xadd\\");
    g_sfera_textures.addFolder("players\\");
    g_sfera_textures.finishRegistration();
    device.checkResult(device.native_device->SetRenderState(D3DRS_LIGHTING, TRUE), "SetRenderState(LIGHTING)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_SPECULARENABLE, FALSE), "SetRenderState(SPECULARENABLE)");
    device.setWhiteMaterial(1.0f);
    device.checkResult(device.native_device->SetRenderState(D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR), "SetRenderState(FOGVERTEXMODE)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_RANGEFOGENABLE, TRUE), "SetRenderState(RANGEFOGENABLE)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_FOGSTART, SferaBinary::floatBits(50.0f)), "SetRenderState(FOGSTART)");
    device.checkResult(device.native_device->SetRenderState(D3DRS_FOGEND, SferaBinary::floatBits(100.0f)), "SetRenderState(FOGEND)");
    device.model_vertices.reserve(30000);
    device.colored_vertices.reserve(30000);
    device.indices_primary.reserve(5000);
    device.indices_secondary.reserve(5000);
    device.last_hresult = device.native_device->CreateQuery(D3DQUERYTYPE_EVENT, device.sync_query.ReleaseAndGetAddressOf());
    if (device.last_hresult != S_OK)
    {
        g_sfera_log_runtime.write("Render err: cant create query:");
        g_sfera_log_runtime.write(SferaNumeric::signedWord(device.last_hresult));
    }
    device.checkResult(device.native_device->Clear(0u, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0u), "Clear");
    initializeWater();
    device.shaders = std::make_unique<CShaderMgr>(device, "Shaders\\Vertex\\", "Shaders\\Pixel\\");
}
