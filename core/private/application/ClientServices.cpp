#include <array>
#include <cstdint>
#include <deque>
#include <memory>
#include <string>
#include <vector>

#include "application/ClientApplication.h"
#include "audio/GameAudio.h"
#include "camera/Camera.h"
#include "collision/Collision.h"
#include "diagnostics/ClientDiagnostics.h"
#include "diagnostics/Diagnostics.h"
#include "effects/EffectManager.h"
#include "environment/Environment.h"
#include "gameplay/ActorMotion.h"
#include "geometry/Geometry.h"
#include "input/DirectInputDevices.h"
#include "lighting/LightRuntime.h"
#include "network/Network.h"
#include "players/PlayerLists.h"
#include "render/GraphicsRuntime.h"
#include "resources/FileResources.h"
#include "resources/ModelResources.h"
#include "resources/TerrainResources.h"
#include "resources/TextureRepository.h"
#include "script/ConfigText.h"
#include "script/MbcRuntime.h"
#include "shadows/Shadows.h"
#include "spatial/SpatialIndex.h"
#include "terrain/Terrain.h"
#include "text/Fonts.h"
#include "ui/Canvas.h"
#include "ui/GameInterfaceManager.h"
#include "ui/ScriptInterface.h"
#include "vegetation/Vegetation.h"
#include "world/ServerGeometry.h"
#include "world/WorldObjects.h"

std::string SferaClientApplication::locale;
GrassMapMngr TerrainAssets::color_map{};
std::unique_ptr<SkyEnvironment> SceneSky::high_resolution_environment{};
std::unique_ptr<SkyEnvironment> SceneSky::environment{};
std::string WorldDiagnostics::message;
SferaMbcRuntime g_sfera_mbc_runtime;
SferaFileManager g_sfera_files;
SferaErrorLogRuntime g_sfera_error_log_runtime;
SferaLogRuntime g_sfera_log_runtime;
SferaGraphicsRuntime g_sfera_graphics_runtime{.fog_distance = 100.0f,
                                              .saved_fog_distance = 50.0f,
                                              .lods_enabled = 1u,
                                              .hardware_cursor_enabled = 1u,
                                              .environment_factor = 0.8500000238418579f,
                                              .base_microtexture_id = UINT16_MAX,
                                              .view_scale = 1.0f,
                                              .post_effects_enabled = 1u,
                                              .rebuild_percent = -1};
SferaPolygon3F g_sfera_clipped_polygon;
SphereUIFontFactory g_sfera_fonts;
SphereRenderMaterialLibrary g_sfera_materials;
SphereRenderTextureRepository g_sfera_textures;
SphereRenderModelRepository g_sfera_models;
SphereWorldWorldSpatialIndex g_sfera_world_spatial;
SphereWorldContactQuery g_sfera_contacts;
SphereWorldVegetation g_sfera_vegetation;
TerrainRenderer g_sfera_terrain_renderer;
SphereWorldMotion g_sfera_motion;
SphereRenderGameCamera g_sfera_camera;
std::unique_ptr<ShadowMap> g_sfera_shadows;
GameFontAtlas g_sfera_font_runtime;
PlayerLists g_sfera_player_lists;
SferaInputDevices g_sfera_direct_input_runtime;
SferaServerWall g_sfera_server_wall{.texture_id = -1};
SferaConfigTextRuntime g_sfera_config_text_runtime;
WorldObjects g_sfera_world_objects{.max_occupied_object_handle = UINT32_MAX, .controlled_object_handle = UINT32_MAX};
SferaLightRuntime g_sfera_light_runtime;
SferaWeatherRuntime g_sfera_weather_runtime;

SferaEffectManager g_sfera_effect_manager{.render_cycle = 31u, .last_processed_generation = UINT32_MAX};
std::vector<TerrainAssetsMicrotexture> TerrainAssets::microtextures;
std::array<TerrainAssetsMapCell, 6400> TerrainAssets::map{};
std::deque<TerrainRegion> TerrainAssets::regions;
std::vector<std::unique_ptr<GameUiElement>> WorldGuiControls::elements;
std::array<TerrainTextureEntry, 50> TerrainTextureCache::entries{};

std::vector<std::unique_ptr<GameUiWindow>> GameInterface::windows;
std::array<std::uint16_t, 65536> TerrainAssets::microtexture_remap = TerrainAssets::makeMicrotextureRemap();
SferaSoundRuntime g_sfera_sound_runtime;
SphereUIInterfaceManager g_sfera_interface;
SferaNetworkRuntime g_sfera_network_runtime;

// Process-wide services: constructed here in dependency order, released by the application.
