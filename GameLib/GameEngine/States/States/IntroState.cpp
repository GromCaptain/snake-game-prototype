#include "IntroState.h"

#include <cassert>
#include <functional>

#include "GameEngine/Settings.h"
#include "Input/Input.h"
#include "SwitchInfo/SwitchToIntroInfo.h"
#include "Window/Window.h"
#include "Window/WindowManager.h"

#include <QDebug>

namespace State
{

IntroState::IntroState():
	uiScene_(), graphicsScene_(), camera_(graphicsScene_)
	{
	}

void IntroState::start(std::shared_ptr<SwitchStateInfo> info)
	{
	auto loadingInfo = std::dynamic_pointer_cast<SwitchToIntroInfo>(info);
	assert(loadingInfo != nullptr);

	totalElapsed_ = std::chrono::milliseconds(0);
	introDuration_ = loadingInfo -> introDuration;
	switchToLoadingInfo_ = loadingInfo -> switchToLoadingInfo;

	std::function<void()> interruptCallback = std::bind(&IntroState::interruptIntro, this);
	uiScene_.registerKeyPressCallback(Input::KeyboardKey::Enter, interruptCallback);
	uiScene_.registerKeyPressCallback(Input::KeyboardKey::Esc, interruptCallback);
	uiScene_.registerKeyPressCallback(Input::KeyboardKey::Space, interruptCallback);

	auto splashActor = std::make_shared<Graphics::Actor>(Point(0, 0), loadingInfo -> splashAnimation);
	graphicsScene_.addActor(Graphics::GraphicsScene::Layer::Background, splashActor);

	auto settings = GameEngine::Settings::globalSettings();
	auto resolution = settings.resolution();
	graphicsScene_.resizeArea(resolution);
	camera_.setResolution(resolution);
	camera_.moveTo({ resolution.width() / 2, resolution.height() / 2 });
	}
void IntroState::update(std::chrono::milliseconds elapsed)
	{
	totalElapsed_ += elapsed;
	handleInput();
	if (finished())
		{
		switchState(StateType::Loading, switchToLoadingInfo_);
		return;
		}
	auto frame = prepareFrame(elapsed);
	renderFrame(frame);
	}

void IntroState::interruptIntro()
	{
	interrupted_ = true;
	}

void IntroState::handleInput()
	{
	auto eventQueue = Window::WindowManager::instance().mainWindowAsync().input().eventQueue();
	uiScene_.handleInput(eventQueue);
	}

bool IntroState::finished() const
	{
	return (totalElapsed_ >= introDuration_) || interrupted_;
	}

Graphics::Texture IntroState::prepareFrame(std::chrono::milliseconds msecs)
	{
	graphicsScene_.update(msecs);
	return camera_.getFrame();
	}

void IntroState::renderFrame(const Graphics::Texture& frame)
	{
	Window::WindowManager::instance().mainWindowAsync().renderTexture(frame);
	}

}
