#include "LoadingState.h"

#include <cassert>
#include <functional>
#include <utility>

#include "Core/Task/Async/Async.h"
#include "GameEngine/Settings.h"
#include "Graph/Actor.h"
#include "Graph/Animation.h"
#include "Resources/ResourcesManager.h"
#include "SwitchInfo/SwitchIntroToLoadingInfo.h"
#include "UI/Components/ProgressBar.h"
#include "Window/Window.h"
#include "Window/WindowManager.h"

namespace State
{

LoadingState::LoadingState():
	graphicsScene_(), camera_(graphicsScene_), uiScene_(), loadingProgressBar_(nullptr)
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
	if (loadingPackProgress_.load() >= (1 - 0.0001))
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

	Graphics::Animation bkgAnim(loadingInfo -> loadingBackground);
	std::shared_ptr<Graphics::Actor> backgroundTexture = std::make_shared<Graphics::Actor>(Point(0, 0), bkgAnim);
	graphicsScene_.addActor(Graphics::GraphicsScene::Layer::Background, backgroundTexture);

	Geometry pbGeometry = loadingInfo -> loadingProgressBarGeometry;
	loadingProgressBar_ = std::make_shared<UI::ProgressBar>(uiScene_, pbGeometry, std::bind(&LoadingState::currentPercentProgress, this));
	Graphics::FrameUpdater frameUpdater = std::bind(&LoadingState::updateProgressBarFrame, this, std::placeholders::_1, std::placeholders::_2);
	std::shared_ptr<Graphics::Actor> progressBarActor = std::make_shared<Graphics::Actor>(pbGeometry.position(), pbGeometry.size(), loadingInfo -> loadingProgressBarAnimations, frameUpdater);
	uiScene_.addComponent(loadingProgressBar_);
	graphicsScene_.addActor(Graphics::GraphicsScene::Layer::HUD, progressBarActor);

	auto hourglassActor = std::make_shared<Graphics::Actor>(loadingInfo -> hourglassPosition, loadingInfo -> hourglassAnimation);
	graphicsScene_.addActor(Graphics::GraphicsScene::Layer::HUD, hourglassActor);

	auto settings = GameEngine::Settings::globalSettings();
	auto resolution = settings.resolution();
	graphicsScene_.resizeArea(resolution);
	camera_.setResolution(resolution);
	camera_.moveTo({ resolution.width() / 2, resolution.height() / 2 });
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

Graphics::Texture LoadingState::prepareFrame(std::chrono::milliseconds msecs)
	{
	graphicsScene_.update(msecs);
	return camera_.getFrame();
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
