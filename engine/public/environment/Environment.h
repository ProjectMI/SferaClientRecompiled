#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "math/Vector.h"

struct EnvironmentLighting;
struct EnvironmentZone;
class EnvironmentZones;
class SkyEnvironment;
class SphereRenderConfigDocument;

struct EnvironmentLighting
{
    SferaVec3F fogParameters;
    SferaVec3F fogColor;
    SferaVec3F ambientColor;
    SferaVec3F sunColor;
};

struct EnvironmentZone
{
    float originX, originZ, minimumX, maximumX, minimumZ, maximumZ, borderFade;
    SferaVec3F fogParameters;
    std::array<SferaVec3F, 8> fogColors{};
    std::array<SferaVec3F, 8> ambientColors{};
    std::array<SferaVec3F, 8> sunColors{};
    float weight(float x, float z) const;
    void sample(int first, int second, float fraction, EnvironmentLighting &output) const;
};

class EnvironmentZones
{
  public:
    static void interval(double time, int &first, int &second, float &fraction);
    void load(const std::string &filename);
    void calculate(bool useDefault, float x, float z, float time, const SkyEnvironment &sky, EnvironmentLighting &output);
    std::vector<EnvironmentZone> zones;

  private:
    void sampleZone(int first, int second, float fraction, const SferaVec3F &sun, const SferaVec3F &ambient, std::size_t index, EnvironmentLighting &target) const;
    static void configurationError(std::size_t zone, std::string_view field);
    static float parameterScalar(const SphereRenderConfigDocument &configuration, std::size_t index, std::string_view name);
    static float colorComponent(const SphereRenderConfigDocument &colors, std::size_t index, std::size_t day, std::string_view name, std::size_t axis);
    static SferaVec3F parameterColor(const SphereRenderConfigDocument &colors, std::size_t index, std::size_t day, std::string_view name);
};

struct SkyState;
struct SkyStateGradientKey;
class SphereRenderModelParameters;

struct SkyStateGradientKey
{
    SferaVec4F color{};
    float position = 0.0f;
};

struct SkyState
{
    std::array<SkyStateGradientKey, 10> primary{};
    SferaVec4F reference{};
    std::array<SkyStateGradientKey, 6> secondary{};
    float time = 0.0f;
    float sunPhase = 0.0f;
    SferaVec3F sunColor{};
    SferaVec3F ambientColor{};

  private:
    friend struct SkyStateGradientKey;
};

class SkyEnvironment
{
  public:
    std::array<SkyState, 11> states{};
    int sunsetState = 0;
    int sunriseState = 0;
    void load(const std::string &filename);
    void interval(double time, int &first, int &second, float &fraction) const;
    void sample(float time, SkyState &output) const;
    void sunDirection(float time, SferaVec3F &output) const;
    void lighting(float time, SferaVec3F &sun, SferaVec3F &ambient) const;

  private:
    static void skyConfigurationError(const std::string &section);

  private:
    static int parameterInteger(const SphereRenderModelParameters &parameters, const std::string &section, std::string_view key);
    static float parameterScalar(const SphereRenderModelParameters &parameters, const std::string &section, std::string_view key);
    static SferaVec3F parameterChannels(const SphereRenderModelParameters &parameters, const std::string &section, std::string_view prefix);
    static SferaVec4F parameterColor(const SphereRenderModelParameters &parameters, const std::string &section);
    static void loadGradient(const SphereRenderModelParameters &parameters, const std::string &suffix, std::string_view prefix, std::span<SkyStateGradientKey> keys);
    static void interpolateGradient(std::span<SkyStateGradientKey> outputKeys, std::span<const SkyStateGradientKey> firstKeys, std::span<const SkyStateGradientKey> secondKeys, float fraction);
};

struct SceneSkyLayer;
struct SceneSkyLayers;

struct SceneSkyLayer
{
    std::string texture;
    float projectionWarp = 0.0f;
    float uvScale = 0.0f;
    bool trackOffset = false;
    float minimumTime = 0.0f;
    float maximumTime = 0.0f;
    std::array<SferaVec3F, 11> colors{};
};

struct SceneSkyLayers
{
    SceneSkyLayer primary;
    SceneSkyLayer secondary;
    float opacity;
};

class SceneSky;
struct SceneSkyMotion;
struct SceneSkyMotionOffset;
struct SferaScreenVertex;
struct SferaVec3F;
struct SferaVec4F;

struct SceneSkyMotionOffset
{
    float x = 0.0f;
    float y = 0.0f;
};

struct SceneSkyMotion
{
    float angle = 0.0f;
    SceneSkyMotionOffset primary;
    SceneSkyMotionOffset secondary;

  private:
    friend struct SceneSkyMotionOffset;
};

class SceneSky
{
  public:
    static uint32_t layer_alpha[120];
    static float sample_elevation;
    static float horizontal_motion;
    static float azimuth_samples[125];
    static float screen_center_y;
    static float sample_azimuth;
    static SferaScreenVertex sun_quad[4];
    static uint32_t inverse_opacity;
    static float cloud_offset_y;
    static float cloud_offset_x;
    static float sun_glow;
    static std::unique_ptr<SkyEnvironment> high_resolution_environment;
    static uint16_t indices[594];

    static SceneSkyMotion motion;
    static SferaVec3F previous_origin;
    static SferaVec3F projected_offset;
    static SferaVec3F projected_center;
    static float texture_phase_v;
    static float glow_samples[120];
    static float elevation_samples[120];
    static float texture_phase_u;
    static bool sample_visible[120];
    static float screen_center_x;
    static float vertical_motion;
    static uint32_t sample_color;
    static uint32_t flare_visible;
    static float animation_phase;
    static SferaVec3F flare_world_position;
    static std::unique_ptr<SkyEnvironment> environment;
    static SferaScreenVertex vertices[120];
    static SferaVec3F flare_screen_position;
    static SkyState interpolated;

    static void rotateUv(double x, double y, double angle, float &u, float &v);
    static std::size_t buildLayerGeometry(const SceneSkyLayer &layer, double opacity);
    static void layerColor(const SceneSkyLayer &layer, SferaVec3F &output);
    static void drawColorLayer(std::string_view texture, const SferaVec3F &color, std::size_t indices);
    static void drawMaskLayer(std::string_view texture, std::size_t indices);
    static void drawLayers(const SceneSkyLayers &layers);
    static void orbit(float &x, float &y, std::uint32_t orbit);
    static float horizonFog(float elevation, double amount);
    static void sampleDirection(bool refresh, const SferaVec3F &direction);
    static double drawStars();
    static void drawSunMoon(float rotation);

  private:
    friend struct SceneSkyMotion;

  private:
    static std::uint32_t skyChannel(float value);
    template <std::size_t Count> static SferaVec4F skyPeriodicSample(const std::array<SkyStateGradientKey, Count> &keys, double position);
    static void skySubmit(std::size_t count);
    static void skyWrap(float &value, double period);

  private:
    static int roundedColorChannel(float value);
};

struct WeatherKeyframe;
struct WeatherScenario;
class WeatherScenarios;
struct WeatherSkyPair;
struct WeatherState;

struct WeatherState
{
    float rain = 0.0f;
    float lightning = 0.0f;
    float wind = 0.0f;
    float cloud = 0.0f;
    SceneSkyLayers sky{};
    SceneSkyLayers clouds{};
    float windX = 0.0f;
    float windZ = 0.0f;
};

struct WeatherSkyPair
{
    std::string primary;
    std::string secondary;
    bool operator==(const WeatherSkyPair &) const = default;
};

struct WeatherKeyframe
{
    int time;
    std::array<float, 4> properties;
};

struct WeatherScenario
{
    int duration = 0;
    WeatherSkyPair sky;
    float skyStart = 0.0f;
    float skyEnd = 0.0f;
    std::vector<WeatherKeyframe> keyframes;
};

class WeatherScenarios
{
  public:
    std::vector<SceneSkyLayer> textures;
    std::vector<WeatherSkyPair> pairs;
    std::vector<WeatherScenario> scenarios;
    std::vector<std::uint16_t> sequence;
    int totalDuration = 0;
    int lastUpdate = 0;
    void load(const std::string &filename);
    void update(int time, float dayTime, WeatherState &output, bool alternateClouds);
    void locate(int time, std::size_t &sequenceIndex, int &startTime, int &localTime) const;
    int advance(std::size_t &sequenceIndex, std::size_t &keyframe) const;
    int retreat(std::size_t &sequenceIndex, std::size_t &keyframe) const;
    double nextValue(std::size_t sequenceIndex, int time, std::size_t property, int &distance) const;
    double previousValue(std::size_t sequenceIndex, int time, std::size_t property, int &distance) const;
    WeatherSkyPair selectSky(int time, float dayTime) const;
    void copyTexture(std::string_view name, SceneSkyLayer &output) const;
    static void windDirection(bool refresh, int seed, float &x, float &z);

  private:
    const WeatherScenario &at(std::size_t sequenceIndex) const;

  private:
    static std::string weatherIndex(std::string_view prefix, std::size_t index, std::size_t digits = 2u);
    [[noreturn]] static void weatherFormatError(std::string_view model, std::string_view parameter);
    static std::string weatherName(std::string_view name);

  private:
    static float parameterNumber(const SphereRenderModelParameters &parameters, std::string_view model, std::string_view key);
    static int parameterInteger(const SphereRenderModelParameters &parameters, std::string_view model, std::string_view key);
    static std::string_view parameterText(const SphereRenderModelParameters &parameters, std::string_view model, std::string_view key);
    static std::string skyTextureName(const SphereRenderModelParameters &parameters, std::string_view model, std::string_view key);
    static WeatherSkyPair skyNames(const SphereRenderModelParameters &parameters, std::string_view model);
    int distanceToChange(int time, float dayTime, const WeatherSkyPair &selected, int direction, int transitionSteps, double dayStep) const;
};

struct SferaWeatherRuntime;

struct SferaWeatherRuntime
{
    float direction_cos_component = 0.0f;
    float direction_sin_component = 0.0f;
    std::unique_ptr<WeatherScenarios> standard;
    std::unique_ptr<WeatherScenarios> highres;
    WeatherState current;
};

extern SferaWeatherRuntime g_sfera_weather_runtime;
