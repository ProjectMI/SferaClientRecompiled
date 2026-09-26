#pragma once

#include <cstdint>

#include "math/Vector.h"

struct ScriptProgramDiagnostic;
class SferaGameCameraPolicy;

class SferaGameCameraPolicy
{
  public:
    static float scene_field_of_view(double width, double height);

  private:
    static bool character_selection_active();
    static bool activeCharacterSelection(const ScriptProgramDiagnostic &program);
};

struct ExtendedWorldObject;
class SphereRenderGameCameraFrame;

class SphereRenderGameCameraFrame
{
  public:
    SphereRenderGameCameraFrame(std::uint32_t mode, bool reflection, float water_height);
    SphereRenderGameCameraFrame(const SphereRenderGameCameraFrame &) = delete;
    SphereRenderGameCameraFrame &operator=(const SphereRenderGameCameraFrame &) = delete;
    ~SphereRenderGameCameraFrame() noexcept;

  private:
    std::uint32_t controlled_handle_ = UINT32_MAX;
    SferaVec3F controlled_position_{}, camera_position_{}, camera_rotation_{};
    bool restore_camera_ = false;

  private:
    void saveCameraState(const ExtendedWorldObject *camera);
};

struct SferaVec3F;

// Assembles a game frame from engine rendering passes, world state and UI.
class SferaGameSceneRenderer
{
  public:
    static void drawFrame();

  private:
    static void drawPass(std::uint32_t mode);
    static void drawMinimap();
    static void drawReflection();
    static SferaVec3F &observerPosition(SferaVec3F &output);
    static void setupEnvironment(std::uint32_t mode, bool useDefault, float time);
    static void sceneUnderwaterOverlay();
    static int underwaterChannel(float heightFactor, double light, float base);
};
