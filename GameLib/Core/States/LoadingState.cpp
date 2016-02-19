#include "LoadingState.h"

#include <cassert>
#include <utility>

#include "SwitchInfo/SwitchToLoadingInfo.h"
#include "Graph/Actor.h"
#include "Graph/Animation.h"
#include "GameUtil/Settings.h"
#include "Window/Window.h"
#include "Window/WindowManager.h"

namespace State
{

LoadingState::LoadingState():
	scene(), camera(scene)
	{
	}

void LoadingState::start(std::shared_ptr<SwitchStateInfo> info)
	{
	auto loadingInfo = std::dynamic_pointer_cast<SwitchToLoadingInfo>(info);
	assert(loadingInfo != nullptr);
	Graphics::Actor backgroundTexture({0, 0}, Graphics::Animation(loadingInfo -> loadingBackground));
	scene.addActor(Graphics::GraphicsScene::Layer::Background, backgroundTexture);
	auto settings = Settings::globalSettings();
	scene.resizeArea(settings.resolution());
	camera.setResolution(settings.resolution());
	}

void LoadingState::update(std::chrono::milliseconds elapsed)
	{
	auto frame = prepareFrame(elapsed);
	renderFrame(frame);
	}

Graphics::Texture LoadingState::prepareFrame(std::chrono::milliseconds msecs)
	{
	scene.update(msecs);
	return camera.getFrame();
	}

void LoadingState::renderFrame(const Graphics::Texture& frame)
	{
	WindowManager::instance().mainWindowAsync().renderTexture(frame);
	}

}
