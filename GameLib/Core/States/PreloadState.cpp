#include "PreloadState.h"

#include "Core/GameManager.h"
#include "Core/Async/Async.h"
#include "GameUtil/ConfigReader.h"
#include "GameUtil/Settings.h"
#include "Graph/GraphicsManager.h"
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
	switchInfo(new SwitchToLoadingInfo),
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
	loadData();
	prepareMainWindow();
	}
ConfigReader PreloadState::initConfigReader()
	{
	ResourceID initCfgFileId = ResourcesManager::instance().getId(initConfigName);
	Resource initCfgData = ResourcesManager::instance().getResource(initCfgFileId);
	return ConfigReader(initCfgData.asString());
	}
void PreloadState::parseConfig(const ConfigReader &cfg)
	{
	switchInfo -> loadStateCfgFileName = cfg.getString("LoadStateConfigFile");
	loadingBackgroundFileName = cfg.getString("LoadingBackgroundFileName");
	ScreenWidth = cfg.getInt("ScreenWidth");
	ScreenHeight = cfg.getInt("ScreenHeight");
	globalSettingsFileName = cfg.getString("SettingsConfigFile");
	}

void PreloadState::loadData()
	{
	ResourceID loadBkgId = ResourcesManager::instance().getId(loadingBackgroundFileName);
	Resource loadBkg = ResourcesManager::instance().getResource(loadBkgId);
	Graphics::Texture loadBkgTexture(loadBkg);
	switchInfo -> loadingBackground = loadBkgTexture;
	Settings::globalSettings().loadFromFile(globalSettingsFileName);
	}
void PreloadState::prepareMainWindow()
	{
	Window& mainWnd = WindowManager::instance().mainWindowAsync();
	WindowManager::instance().doWorkInMainThread(std::bind(&Window::setWindowType, &mainWnd, WindowType::Windowed));
	WindowManager::instance().doWorkInMainThread(std::bind(&Window::setResolution, &mainWnd, ScreenWidth, ScreenHeight));
	}

}
