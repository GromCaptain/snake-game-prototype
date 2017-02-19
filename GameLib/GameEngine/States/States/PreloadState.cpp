#include "PreloadState.h"

#include "Core/Data/Geometry/Rectangle.h"
#include "Core/Data/Geometry/ResourceLoaders/GeometryLoader.h"
#include "Core/Task/Async/Async.h"
#include "Core/Util/ConfigReader.h"
#include "GameEngine/Settings.h"
#include "GameEngine/States/GameManager.h"
#include "Graph/GraphCore/Animation.h"
#include "Graph/GraphicsManager.h"
#include "Graph/ResourceLoaders/AnimationLoader.h"
#include "Graph/ResourceLoaders/AnimationCollectionLoader.h"
#include "Resources/Resources/Resource.h"
#include "Resources/Resources/ResourceID.h"
#include "Resources/ResourcesManager.h"
#include "SwitchInfo/SwitchToIntroInfo.h"
#include "SwitchInfo/SwitchIntroToLoadingInfo.h"
#include "Window/Window.h"
#include "Window/WindowManager.h"

namespace State
{

const String PreloadState::initConfigName_ = "init.cfg";

PreloadState::PreloadState():
	loadAction_(nullptr),
	switchInfo_(nullptr),
	ScreenWidth_(100), ScreenHeight_(100)
	{
	}

void PreloadState::start(std::shared_ptr<SwitchStateInfo>)
	{
	auto f = std::bind(&PreloadState::prepareApplication, this);
	loadAction_ = std::make_shared<Async::Action>(f);
	Async::doAsync(loadAction_);
	}
void PreloadState::update(std::chrono::milliseconds elapsed)
	{
	if (loadAction_ -> done())
		switchState(StateType::Intro, switchInfo_);
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
	Resources::ResourceID initCfgFileId = Resources::ResourcesManager::instance().getResourceId(initConfigName_);
	Resources::Resource initCfgData = Resources::ResourcesManager::instance().getResource(initCfgFileId);
	return ConfigReader(initCfgData.asString());
	}

void PreloadState::parseConfig(const ConfigReader &cfg)
	{
	ScreenWidth_ = cfg.getInt("ScreenWidth");
	ScreenHeight_ = cfg.getInt("ScreenHeight");
	}

void PreloadState::loadData(const ConfigReader& cfg)
	{
	using Resources::ResourceID;
	using Resources::Resource;
	using Resources::ResourcePack;

	String loadStateCfgFileName = cfg.getString("LoadStateConfigFile");

	auto& resourceManager = Resources::ResourcesManager::instance();

	int introDurationMSecs = cfg.getInt("IntroDurationMilliseconds");

	Graphics::Animation introSplashAnim = loadAnimation(resourceManager, cfg.getString("IntroSplashAnimation"));

	String loadingBackgroundFileName = cfg.getString("LoadingBackgroundFileName");
	ResourceID loadBkgId = resourceManager.getResourceId(loadingBackgroundFileName);
	Resource loadBkg = resourceManager.getResource(loadBkgId);
	Graphics::Texture loadBkgTexture(loadBkg);

	String loadingProgressBarAnimsFileName = cfg.getString("LoadingProgressBarAnimationsFileName");
	ResourceID loadPBarAnimsId = resourceManager.getPackId(loadingProgressBarAnimsFileName);
	ResourcePack loadPBarAnimsPack = resourceManager.getPack(loadPBarAnimsId);
	Graphics::AnimationCollection loadPBarAnims = Graphics::AnimationCollectionLoader::loadFromResources(loadPBarAnimsPack);

	Geometry loadPBarGeometry = loadGeometry(resourceManager, cfg.getString("LoadingProgressBarGeometryFileName"));

	Graphics::Animation hourglassAnim = loadAnimation(resourceManager, cfg.getString("HourglassAnimationFileName"));
	Geometry hourglassGeometry = loadGeometry(resourceManager, cfg.getString("HourglassGeometryFileName"));

	auto mainMenuInitCallback = [](const ResourcePack&, ProgressUpdateCallback){};
	auto switchToLoadingInfo = std::make_shared<SwitchIntroToLoadingInfo>(loadStateCfgFileName, mainMenuInitCallback, loadBkgTexture, loadPBarAnims, loadPBarGeometry, hourglassAnim, hourglassGeometry);
	switchInfo_ = std::make_shared<SwitchToIntroInfo>(std::chrono::milliseconds(introDurationMSecs), switchToLoadingInfo, introSplashAnim);

	String globalSettingsFileName = cfg.getString("SettingsConfigFile");
	GameEngine::Settings::globalSettings().loadFromFile(globalSettingsFileName);
	}

void PreloadState::prepareMainWindow()
	{
	auto& wndMgr = Window::WindowManager::instance();
	Window::Window& mainWnd = wndMgr.mainWindowAsync();
	wndMgr.doWorkInMainThread(std::bind(&Window::Window::setWindowType, &mainWnd, Window::WindowType::Windowed));
	wndMgr.doWorkInMainThread(std::bind(&Window::Window::setResolution, &mainWnd, ScreenWidth_, ScreenHeight_));
	}

Geometry PreloadState::loadGeometry(Resources::ResourcesManager& resourceManager, const String& fileName)
	{
	Resources::ResourceID resourceId = resourceManager.getResourceId(fileName);
	Resources::Resource resource = resourceManager.getResource(resourceId);
	return GeometryLoader::loadFromResources(resource);
	}

Graphics::Animation PreloadState::loadAnimation(Resources::ResourcesManager& resourceManager, const String& fileName)
	{
	Resources::ResourceID resourceId = resourceManager.getPackId(fileName);
	Resources::ResourcePack resource = resourceManager.getPack(resourceId);
	return Graphics::AnimationLoader::loadFromResources(resource);
	}

}
