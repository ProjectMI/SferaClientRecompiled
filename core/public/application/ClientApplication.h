#pragma once

#include <windows.h>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <filesystem>
#include <memory>
#include <string>
#include <string_view>

class SferaClientApplication;
struct SferaClientApplicationExitRequested;
struct SferaConfigTextRuntime;

enum class SferaClientApplicationLifecycle
{
    Dormant,
    Running,
    Stopping,
    Stopped
};
struct SferaClientApplicationExitRequested
{
};

class SferaClientApplication
{
  public:
    static int frame_samples;
    static std::uint64_t frame_anchor;
    static uint32_t frame_elapsed_ticks;
    static bool main_loop_started;
    static HINSTANCE instance_handle;
    static bool interpreter_initialized;
    static uint32_t language;
    static bool resources_loaded;
    static bool windowed;
    static HWND main_window;
    static float measured_fps;
    static bool interrupted;
    static bool quit_requested;
    static bool startup_complete;
    static std::string locale;
    static uint32_t desktop_width;
    static bool application_active;

    static SferaClientApplicationLifecycle lifecycle;
    static bool com_initialized;
    static bool window_class_registered;

    SferaClientApplication() = default;
    SferaClientApplication(const SferaClientApplication &) = delete;
    SferaClientApplication &operator=(const SferaClientApplication &) = delete;
    ~SferaClientApplication() noexcept;
    static bool fatal_error_in_progress;
    static int server_number;
    static uint32_t desktop_height;
    static bool storage_initialized;

    static int run(HINSTANCE instance);
    static void initializeStorage();
    static void releaseStorage() noexcept;
    static std::string_view commandLineArguments(std::string_view commandLine);
    static void loadResources();
    static void shutdown() noexcept;
    [[noreturn]] static void terminateWithError(std::string_view message);
    [[noreturn]] static void arrayBoundsError(int index);

  private:
    static void configureResourceDirectory();
    static void resetWorld();
    static void renderFrame();
    bool initialize();
    bool runStartupScripts();
    void runMainLoop();
    void updateSimulation();
    int advanceClock();
    std::uint32_t previous_tick_ = 0;
    int tick_remainder_ = 0;
    std::uint32_t object_update_ticks_ = 0;
    std::uint32_t effect_update_ticks_ = 0;
    std::uint32_t maintenance_ticks_ = 0;

  private:
    static void dispatch_application_messages();

  private:
    static auto containsClientResources(const std::filesystem::path &directory);
    static auto readCommandLineArgument(std::string_view arguments, std::string_view name, std::string &output, std::size_t limit);
    template <class T> static auto readIntegerSetting(const SferaConfigTextRuntime &settings, std::string_view name, T &output);
    static auto takeQueuedEffect(std::deque<std::uint32_t> &queue, std::uint32_t &current);
    template <class T> static auto loadConfigurationOwner(std::unique_ptr<T> &owner, const std::string &path);
    static auto finishShutdownOperation(auto &&operation) noexcept;

  private:
    static void stopInterpreterTick();
    static void shutdownNetwork();
    static void shutdownInterpreter();
    static void shutdownEffects();
    static void shutdownSound();
    static void shutdownInterface();
    static void shutdownShadows();
    static void clearWorldObjects();
    static void clearVegetation();
    static void releaseTerrainTextures();
    static void releaseTerrainAssets();
    static void finishShutdownLog();
};
