#include "IntroState.h"

#include <cassert>

#include "GameEngine/Settings.h"
#include "SwitchInfo/SwitchToIntroInfo.h"
#include "Window/Window.h"
#include "Window/WindowManager.h"

#include <QDebug>

namespace State
{

IntroState::IntroState():
	graphicsScene(), camera(graphicsScene)
	{
	}

void IntroState::start(std::shared_ptr<SwitchStateInfo> info)
	{
	auto loadingInfo = std::dynamic_pointer_cast<SwitchToIntroInfo>(info);
	assert(loadingInfo != nullptr);

	totalElapsed = std::chrono::milliseconds(0);
	introDuration = loadingInfo -> introDuration;
	switchToLoadingInfo = loadingInfo -> switchToLoadingInfo;

	auto splashActor = std::make_shared<Graphics::Actor>(Point(0, 0), loadingInfo -> splashAnimation);
	graphicsScene.addActor(Graphics::GraphicsScene::Layer::Background, splashActor);

	auto settings = GameEngine::Settings::globalSettings();
	auto resolution = settings.resolution();
	graphicsScene.resizeArea(resolution);
	camera.setResolution(resolution);
	camera.moveTo({ resolution.width() / 2, resolution.height() / 2 });
	}
void IntroState::update(std::chrono::milliseconds elapsed)
	{
	totalElapsed += elapsed;
	if (totalElapsed >= introDuration)
		{
		switchState(StateType::Loading, switchToLoadingInfo);
		return;
		}
	auto frame = prepareFrame(elapsed);
	renderFrame(frame);
	}

Graphics::Texture IntroState::prepareFrame(std::chrono::milliseconds msecs)
	{
	graphicsScene.update(msecs);
	return camera.getFrame();
	}

void IntroState::renderFrame(const Graphics::Texture& frame)
	{
	Window::WindowManager::instance().mainWindowAsync().renderTexture(frame);
	}

}
