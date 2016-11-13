#include "PreloadState.h"

#include "Core/Data/Geometry/Rectangle.h"
#include "Core/Data/Geometry/ResourceLoaders/GeometryLoader.h"
#include "Core/Task/Async/Async.h"
#include "Core/Util/ConfigReader.h"
#include "GameEngine/Settings.h"
#include "GameEngine/States/GameManager.h"
#include "Graph/Animation.h"
#include "Graph/GraphicsManager.h"
#include "Graph/ResourceLoaders/AnimationLoader.h"
#include "Graph/ResourceLoaders/AnimationCollectionLoader.h"
#include "Resources/Resources/Resource.h"
#include "Resources/Resources/ResourceID.h"
#include "Resources/ResourcesManager.h"
#include "SwitchInfo/SwitchToIntroInfo.h"
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
		switchState(StateType::Intro, switchInfo);
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
	Resources::ResourceID initCfgFileId = Resources::ResourcesManager::instance().getResourceId(initConfigName);
	Resources::Resource initCfgData = Resources::ResourcesManager::instance().getResource(initCfgFileId);
	return ConfigReader(initCfgData.asString());
	}
void PreloadState::parseConfig(const ConfigReader &cfg)
	{
	ScreenWidth = cfg.getInt("ScreenWidth");
	ScreenHeight = cfg.getInt("ScreenHeight");
	}

void PreloadState::loadData(const ConfigReader& cfg)
	{
	using Resources::ResourceID;
	using Resources::Resource;
	using Resources::ResourcePack;

	String loadStateCfgFileName = cfg.getString("LoadStateConfigFile");

	auto& resourceManager = Resources::ResourcesManager::instance();

	int introDurationMSecs = cfg.getInt("IntroDurationMilliseconds");

	String introSplashFileName = cfg.getString("IntroSplashAnimation");
	ResourceID introSplashId = resourceManager.getPackId(introSplashFileName);
	ResourcePack introSplashPack = resourceManager.getPack(introSplashId);
	Graphics::Animation introSplashAnim = Graphics::AnimationLoader::loadFromResources(introSplashPack);

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

	String hourglassAnimationFileName = cfg.getString("HourglassAnimationFileName");
	ResourceID hourglassAnimId = resourceManager.getPackId(hourglassAnimationFileName);
	ResourcePack hourglassAnimPack = resourceManager.getPack(hourglassAnimId);
	Graphics::Animation hourglassAnim = Graphics::AnimationLoader::loadFromResources(hourglassAnimPack);

	int hourglassX = cfg.getInt("HourglassX"), hourglassY = cfg.getInt("HourglassY");

	auto switchToLoadingInfo = std::make_shared<SwitchToLoadingInfo>(loadStateCfgFileName, loadBkgTexture, loadPBarAnims, loadPBarGeometry, hourglassAnim, Point(hourglassX, hourglassY));
	switchInfo = std::make_shared<SwitchToIntroInfo>(std::chrono::milliseconds(introDurationMSecs), switchToLoadingInfo, introSplashAnim);

	String globalSettingsFileName = cfg.getString("SettingsConfigFile");
	GameEngine::Settings::globalSettings().loadFromFile(globalSettingsFileName);
	}
void PreloadState::prepareMainWindow()
	{
	auto& wndMgr = Window::WindowManager::instance();
	Window::Window& mainWnd = wndMgr.mainWindowAsync();
	wndMgr.doWorkInMainThread(std::bind(&Window::Window::setWindowType, &mainWnd, Window::WindowType::Windowed));
	wndMgr.doWorkInMainThread(std::bind(&Window::Window::setResolution, &mainWnd, ScreenWidth, ScreenHeight));
	}

}
