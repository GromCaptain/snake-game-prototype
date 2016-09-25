#include "LoadingState.h"

#include <cassert>
#include <utility>

#include "SwitchInfo/SwitchToLoadingInfo.h"
#include "Graph/Actor.h"
#include "Graph/Animation.h"
#include "GameUtil/Settings.h"
#include "UI/Components/ProgressBar.h"
#include "Window/Window.h"
#include "Window/WindowManager.h"

namespace State
{

LoadingState::LoadingState():
	graphicsScene(), camera(graphicsScene), uiScene(), loadingProgressBar(nullptr)
	{
	}

void LoadingState::start(std::shared_ptr<SwitchStateInfo> info)
	{
	auto loadingInfo = std::dynamic_pointer_cast<SwitchToLoadingInfo>(info);
	assert(loadingInfo != nullptr);

	if (!graphicsInitialized)
		{
		Graphics::Animation bkgAnim(loadingInfo -> loadingBackground);
		std::shared_ptr<Graphics::Actor> backgroundTexture = std::make_shared<Graphics::Actor>(Point(0, 0), bkgAnim);
		graphicsScene.addActor(Graphics::GraphicsScene::Layer::Background, backgroundTexture);

		Geometry pbGeometry = loadingInfo -> loadingProgressBarGeometry;
		loadingProgressBar = std::make_shared<UI::ProgressBar>(pbGeometry, std::bind(LoadingState::currentPercentProgress, this));
		Graphics::FrameUpdater frameUpdater = std::bind(LoadingState::updateProgressBarFrame, this, std::placeholders::_1, std::placeholders::_2);
		std::shared_ptr<Graphics::Actor> progressBarActor = std::make_shared<Graphics::Actor>(pbGeometry.position(), pbGeometry.size(), loadingInfo -> loadingProgressBarAnimations, frameUpdater);
		uiScene.addComponent(loadingProgressBar);
		graphicsScene.addActor(Graphics::GraphicsScene::Layer::Actors, progressBarActor);

		auto settings = Settings::globalSettings();
		auto resolution = settings.resolution();
		graphicsScene.resizeArea(resolution);
		camera.setResolution(resolution);
		camera.moveTo({ resolution.width() / 2, resolution.height() / 2 });

		graphicsInitialized = true;
		}
	}

void LoadingState::update(std::chrono::milliseconds elapsed)
	{
	auto frame = prepareFrame(elapsed);
	renderFrame(frame);
	totalElapsedForDemo += elapsed;
	}

unsigned LoadingState::currentPercentProgress() const
	{
	unsigned percent = totalElapsedForDemo.count() * 100 / 50000;
	return std::min(percent, 100u);
	}

Graphics::Texture LoadingState::updateProgressBarFrame(Graphics::AnimationCollection& progressBarAnimations, std::chrono::milliseconds elapsed)
	{
	return loadingProgressBar -> updateActorFrame(progressBarAnimations, elapsed);
	}

Graphics::Texture LoadingState::prepareFrame(std::chrono::milliseconds msecs)
	{
	graphicsScene.update(msecs);
	return camera.getFrame();
	}

void LoadingState::renderFrame(const Graphics::Texture& frame)
	{
	WindowManager::instance().mainWindowAsync().renderTexture(frame);
	}

}
