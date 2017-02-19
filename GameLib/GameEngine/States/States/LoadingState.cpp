#include "LoadingState.h"

#include <cassert>
#include <functional>
#include <utility>

#include "Core/Task/Async/Async.h"
#include "GameEngine/Settings.h"
#include "Graph/GraphCore/Animation.h"
#include "Graph/Render/SingleAnimationRenderer.h"
#include "Graph/Render/UIGraphicsScene/UIActor.h"
#include "Graph/Render/UIGraphicsScene/UIGraphicsScene.h"
#include "Graph/Render/UIGraphicsScene/UIGraphicsScenePage.h"
#include "Resources/ResourcesManager.h"
#include "SwitchInfo/SwitchIntroToLoadingInfo.h"
#include "UI/Components/ProgressBar.h"
#include "Window/Window.h"
#include "Window/WindowManager.h"

namespace State
{

LoadingState::LoadingState():
	uiScene_(),
	bkgRenderer_(new Graphics::SingleAnimationRenderer()),
	uiGraphicsScene_(new Graphics::UIGraphicsScene<UIPage>({ UIPage::Main }, UIPage::Main)),
	loadingProgressBar_(nullptr),
	renderer_(bkgRenderer_, { uiGraphicsScene_ })
	{
	}

void LoadingState::start(std::shared_ptr<SwitchStateInfo> info)
	{
	auto loadingInfo = std::dynamic_pointer_cast<SwitchToLoadingInfo>(info);
	assert(loadingInfo != nullptr);

	if (!graphicsInitialized_)
		{
		initGraphics(info);
		graphicsInitialized_ = true;
		}

	std::function<void()> loadPackCallback = std::bind(&LoadingState::loadPackAndInitNextState, this, loadingInfo -> loadStateCfgFileName, loadingInfo -> initFromPackCallback);
	Async::doAsync(loadPackCallback);
	}

void LoadingState::update(std::chrono::milliseconds elapsed)
	{
	auto frame = prepareFrame(elapsed);
	renderFrame(frame);
	bool loadingComplete = (loadingPackProgress_.load() >= (1 - 0.0001));
	if (loadingComplete)
		totalElapsedForDemo_ += elapsed;
	}

unsigned LoadingState::currentPercentProgress() const
	{
	unsigned realPercent = static_cast<unsigned>(loadingPackProgress_.load() * 100.0);
	unsigned demoPercent = totalElapsedForDemo_.count() * 100 / 5000;
	unsigned percent = (realPercent + demoPercent) / 2;
	return std::min(percent, 100u);
	}

Graphics::Texture LoadingState::updateProgressBarFrame(Graphics::AnimationCollection& progressBarAnimations, std::chrono::milliseconds elapsed)
	{
	return loadingProgressBar_ -> updateActorFrame(progressBarAnimations, elapsed);
	}

void LoadingState::initGraphics(std::shared_ptr<SwitchStateInfo> info)
	{
	auto loadingInfo = std::dynamic_pointer_cast<SwitchIntroToLoadingInfo>(info);
	assert(loadingInfo != nullptr);

	bkgRenderer_ -> setAnimation(Graphics::Animation(loadingInfo -> loadingBackground));

	Geometry pbGeometry = loadingInfo -> loadingProgressBarGeometry;
	Graphics::UIActor::FrameUpdater frameUpdater = std::bind(&LoadingState::updateProgressBarFrame, this, std::placeholders::_1, std::placeholders::_2);
	auto progressBarActor = std::make_shared<Graphics::UIActor>(pbGeometry.rect(), loadingInfo -> loadingProgressBarAnimations, frameUpdater);
	loadingProgressBar_ = std::make_shared<UI::ProgressBar>(uiScene_, progressBarActor, pbGeometry, std::bind(&LoadingState::currentPercentProgress, this));

	uiScene_.addComponent(loadingProgressBar_);
	uiGraphicsScene_ -> addActor(UIPage::Main, progressBarActor);

	Geometry hgGeometry = loadingInfo -> hourglassGeometry;
	auto hourglassActor = std::make_shared<Graphics::UIActor>(hgGeometry.rect(), loadingInfo -> hourglassAnimation);
	auto hourglassComp = std::make_shared<UI::UIComponent>(uiScene_, hourglassActor, hgGeometry);

	uiScene_.addComponent(hourglassComp);
	uiGraphicsScene_ -> addActor(UIPage::Main, hourglassActor);

	auto settings = GameEngine::Settings::globalSettings();
	auto resolution = settings.resolution();
	uiScene_.resize(resolution);
	}

void LoadingState::loadPackAndInitNextState(const String& packFileName, StateInitCallback initNextStateCallback)
	{
	auto pack = loadPack(packFileName);
	ProgressUpdateCallback initProgressCallback = std::bind(&LoadingState::updateInitFromPackStageProgress, this, std::placeholders::_1);
	initNextStateCallback(pack, initProgressCallback);
	}

Resources::ResourcePack LoadingState::loadPack(const String& fileName)
	{
	std::function<void(double)> updateProgressCallback = std::bind(&LoadingState::updateLoadPackStageProgress, this, std::placeholders::_1);
	auto id = Resources::ResourcesManager::instance().getPackId(fileName, updateProgressCallback);
	auto pack = Resources::ResourcesManager::instance().getPack(id);
	return pack;
	}

Graphics::Texture LoadingState::prepareFrame(std::chrono::milliseconds elapsed)
	{
	renderer_.update(elapsed);
	return renderer_.renderFrame();
	}

void LoadingState::renderFrame(const Graphics::Texture& frame)
	{
	Window::WindowManager::instance().mainWindowAsync().renderTexture(frame);
	}

void LoadingState::updateLoadPackStageProgress(double progress)
	{
	loadingPackProgress_ = progress;
	}

void LoadingState::updateInitFromPackStageProgress(double progress)
	{
	initFromPackProgress_ = progress;
	}

}
