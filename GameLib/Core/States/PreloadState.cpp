#include "PreloadState.h"

#include "GameUtil/ConfigReader.h"
#include "Core/GameManager.h"
#include "Window/Window.h"
#include "Resources/Resources/Resource.h"
#include "Resources/Resources/ResourceID.h"
#include "Resources/ResourcesManager.h"
#include "Graph/GraphicsManager.h"
#include "Window/WindowManager.h"

namespace State
{

const String PreloadState::initConfig = "init.cfg";

PreloadState::PreloadState():
	switchInfo(new SwitchToIntroInfo),
	ScreenWidth(100), ScreenHeight(100)
	{
	}

void PreloadState::start(std::shared_ptr<SwitchStateInfo>)
	{
	thread.start(std::bind(&PreloadState::doWork, this));
	}
void PreloadState::update(unsigned msecs)
	{
	if (thread.finished())
		switchState(StateType::Intro, switchInfo);
	}

void PreloadState::doWork()
	{
	ResourceID cfgId = ResourcesManager::instance().getId(initConfig);
	Resource cfgData = ResourcesManager::instance().getResource(cfgId);
	ConfigReader cfg(cfgData.asString());
	parseConfig(cfg);
	Window& mainWnd = WindowManager::instance().mainWindowAsync();
	WindowManager::instance().doWorkInMainThread(std::bind(&Window::setWindowType, &mainWnd, WindowType::Windowed));
	WindowManager::instance().doWorkInMainThread(std::bind(&Window::setResolution, &mainWnd, ScreenWidth, ScreenHeight));
	}
void PreloadState::parseConfig(const ConfigReader &cfg)
	{
	switchInfo -> loadStateCfgFileName = cfg.getString("LoadStateConfigFile");
	switchInfo -> introSplashFileName = cfg.getString("IntroSplashFileName");
	ScreenWidth = cfg.getInt("ScreenWidth");
	ScreenHeight = cfg.getInt("ScreenHeight");
	}

}
