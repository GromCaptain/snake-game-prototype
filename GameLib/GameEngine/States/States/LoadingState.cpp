#include "LoadingState.h"

#include <cassert>
#include <utility>

#include "GameEngine/Settings.h"
#include "Graph/Actor.h"
#include "Graph/Animation.h"
#include "SwitchInfo/SwitchToLoadingInfo.h"
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

		graphicsInitialized_ = true;
		}
	}

void LoadingState::update(std::chrono::milliseconds elapsed)
	{
	auto frame = prepareFrame(elapsed);
	renderFrame(frame);
	totalElapsedForDemo_ += elapsed;
	}

unsigned LoadingState::currentPercentProgress() const
	{
	unsigned percent = totalElapsedForDemo_.count() * 100 / 50000;
	return std::min(percent, 100u);
	}

Graphics::Texture LoadingState::updateProgressBarFrame(Graphics::AnimationCollection& progressBarAnimations, std::chrono::milliseconds elapsed)
	{
	return loadingProgressBar_ -> updateActorFrame(progressBarAnimations, elapsed);
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

}
