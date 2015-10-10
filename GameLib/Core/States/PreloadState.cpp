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

const String PreloadState::initConfig = "D:\\init.cfg";

PreloadState::PreloadState():
	switchInfo(new SwitchToIntroInfo),
	ScreenWidth(100), ScreenHeight(100)
	{
	}

void PreloadState::start(std::shared_ptr<SwitchStateInfo>)
	{
	thread.start(Functor<void>(this, PreloadState::doWork));
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
	auto fSetWindowType = bindFirst(Functor<void, WindowType>(&mainWnd, &Window::setWindowType), WindowType::Windowed);
	WindowManager::instance().doWorkInMainThread(fSetWindowType);
	auto fSetResolution = bindFirst(bindFirst(Functor<void, unsigned, unsigned>(&mainWnd, &Window::setResolution), ScreenWidth), ScreenHeight);
	WindowManager::instance().doWorkInMainThread(fSetResolution);
	}
void PreloadState::parseConfig(const ConfigReader &cfg)
	{
	switchInfo -> loadStateCfgFileName = cfg.getString("LoadStateConfigFile");
	switchInfo -> introSplashFileName = cfg.getString("IntroSplashFileName");
	ScreenWidth = cfg.getInt("ScreenWidth");
	ScreenHeight = cfg.getInt("ScreenHeight");
	}

}
