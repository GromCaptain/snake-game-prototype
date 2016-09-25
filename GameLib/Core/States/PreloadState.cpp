#include "PreloadState.h"

#include "Core/GameManager.h"
#include "Core/Async/Async.h"
#include "Core/Utility/Geometry/Rectangle.h"
#include "Core/Utility/Geometry/ResourceLoaders/GeometryLoader.h"
#include "GameUtil/ConfigReader.h"
#include "GameUtil/Settings.h"
#include "Graph/Animation.h"
#include "Graph/GraphicsManager.h"
#include "Graph/ResourceLoaders/AnimationCollectionLoader.h"
#include "Resources/Resources/Resource.h"
#include "Resources/Resources/ResourceID.h"
#include "Resources/ResourcesManager.h"
#include "SwitchInfo/SwitchToLoadingInfo.h"
#include "Window/Window.h"
#include "Window/WindowManager.h"

namespace State
{

const String PreloadState::initConfigName = "init.cfg";

PreloadState::PreloadState():
	loadAction(nullptr),
	switchInfo(nullptr),
	ScreenWidth(100), ScreenHeight(100)
	{
	}

void PreloadState::start(std::shared_ptr<SwitchStateInfo>)
	{
	auto f = std::bind(&PreloadState::prepareApplication, this);
	loadAction = std::make_shared<Async::Action>(f);
	Async::doAsync(loadAction);
	}
void PreloadState::update(std::chrono::milliseconds elapsed)
	{
	if (loadAction -> done())
		switchState(StateType::Loading, switchInfo);
	}

void PreloadState::prepareApplication()
	{
	ConfigReader initCfgReader = initConfigReader();
	parseConfig(initCfgReader);
	loadData(initCfgReader);
	prepareMainWindow();
	}
ConfigReader PreloadState::initConfigReader()
	{
	ResourceID initCfgFileId = ResourcesManager::instance().getResourceId(initConfigName);
	Resource initCfgData = ResourcesManager::instance().getResource(initCfgFileId);
	return ConfigReader(initCfgData.asString());
	}
void PreloadState::parseConfig(const ConfigReader &cfg)
	{
	ScreenWidth = cfg.getInt("ScreenWidth");
	ScreenHeight = cfg.getInt("ScreenHeight");
	}

void PreloadState::loadData(const ConfigReader& cfg)
	{
	String loadStateCfgFileName = cfg.getString("LoadStateConfigFile");

	auto& resourceManager = ResourcesManager::instance();

	String loadingBackgroundFileName = cfg.getString("LoadingBackgroundFileName");
	ResourceID loadBkgId = resourceManager.getResourceId(loadingBackgroundFileName);
	Resource loadBkg = resourceManager.getResource(loadBkgId);
	Graphics::Texture loadBkgTexture(loadBkg);

	String loadingProgressBarAnimsFileName = cfg.getString("LoadingProgressBarAnimationsFileName");
	ResourceID loadPBarAnimsId = resourceManager.getPackId(loadingProgressBarAnimsFileName);
	ResourcePack loadPBarAnimsPack = resourceManager.getPack(loadPBarAnimsId);
	Graphics::AnimationCollection loadPBarAnims = Graphics::AnimationCollectionLoader::loadFromResources(loadPBarAnimsPack);

	String loadingProgressBarGeometryFileName = cfg.getString("LoadingProgressBarGeometryFileName");
	ResourceID loadPBarGeomId = resourceManager.getResourceId(loadingProgressBarGeometryFileName);
	Resource loadPBarGeomResource = resourceManager.getResource(loadPBarGeomId);
	Geometry loadPBarGeometry = GeometryLoader::loadFromResources(loadPBarGeomResource);

	switchInfo = std::make_shared<SwitchToLoadingInfo>(loadStateCfgFileName, loadBkgTexture, loadPBarAnims, loadPBarGeometry);

	String globalSettingsFileName = cfg.getString("SettingsConfigFile");
	Settings::globalSettings().loadFromFile(globalSettingsFileName);
	}
void PreloadState::prepareMainWindow()
	{
	Window& mainWnd = WindowManager::instance().mainWindowAsync();
	WindowManager::instance().doWorkInMainThread(std::bind(&Window::setWindowType, &mainWnd, WindowType::Windowed));
	WindowManager::instance().doWorkInMainThread(std::bind(&Window::setResolution, &mainWnd, ScreenWidth, ScreenHeight));
	}

}
