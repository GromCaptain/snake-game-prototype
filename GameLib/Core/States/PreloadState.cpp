#include "PreloadState.h"

#include "GameUtil/ConfigReader.h"
#include "Core/GameManager.h"
#include "Core/Async/Async.h"
#include "Window/Window.h"
#include "Resources/Resources/Resource.h"
#include "Resources/Resources/ResourceID.h"
#include "Resources/ResourcesManager.h"
#include "Graph/GraphicsManager.h"
#include "Window/WindowManager.h"

namespace State
{

const String PreloadState::initConfigName = "init.cfg";

PreloadState::PreloadState():
	loadAction(nullptr),
	switchInfo(new SwitchToIntroInfo),
	ScreenWidth(100), ScreenHeight(100)
	{
	}

void PreloadState::start(std::shared_ptr<SwitchStateInfo>)
	{
	auto f = std::bind(&PreloadState::prepareApplication, this);
	loadAction = std::make_shared<Async::Action>(f);
	Async::doAsync(loadAction);
	}
void PreloadState::update(unsigned msecs)
	{
	if (loadAction -> done())
		switchState(StateType::Intro, switchInfo);
	}

void PreloadState::prepareApplication()
	{
	ConfigReader initCfgReader = initConfigReader();
	parseConfig(initCfgReader);
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
	switchInfo -> introSplashFileName = cfg.getString("IntroSplashFileName");
	ScreenWidth = cfg.getInt("ScreenWidth");
	ScreenHeight = cfg.getInt("ScreenHeight");
	}
void PreloadState::prepareMainWindow()
	{
	Window& mainWnd = WindowManager::instance().mainWindowAsync();
	WindowManager::instance().doWorkInMainThread(std::bind(&Window::setWindowType, &mainWnd, WindowType::Windowed));
	WindowManager::instance().doWorkInMainThread(std::bind(&Window::setResolution, &mainWnd, ScreenWidth, ScreenHeight));
	}

}
