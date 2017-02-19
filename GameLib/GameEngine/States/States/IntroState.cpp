#include "IntroState.h"

#include <cassert>
#include <functional>

#include "Core/Data/Geometry/Rectangle.h"
#include "GameEngine/Settings.h"
#include "Graph/Render/SingleAnimationRenderer.h"
#include "Graph/Render/UIGraphicsScene/UIGraphicsScenePage.h"
#include "Input/Input.h"
#include "SwitchInfo/SwitchToIntroInfo.h"
#include "Window/Window.h"
#include "Window/WindowManager.h"

namespace State
{

IntroState::IntroState():
	uiScene_(),
	splashAnimRenderer_(new Graphics::SingleAnimationRenderer()),
	uiGraphicsScene_(new Graphics::UIGraphicsScene<UIPage>({ UIPage::Main }, UIPage::Main)),
	renderer_(splashAnimRenderer_, {})
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
	uiScene_.registerBkgKeyPressCallback(Input::KeyboardKey::Enter, interruptCallback);
	uiScene_.registerBkgKeyPressCallback(Input::KeyboardKey::Esc, interruptCallback);
	uiScene_.registerBkgKeyPressCallback(Input::KeyboardKey::Space, interruptCallback);

	splashAnimRenderer_ -> setAnimation(loadingInfo -> splashAnimation);
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

Graphics::Texture IntroState::prepareFrame(std::chrono::milliseconds elapsed)
	{
	renderer_.update(elapsed);
	return renderer_.renderFrame();
	}

void IntroState::renderFrame(const Graphics::Texture& frame)
	{
	Window::WindowManager::instance().mainWindowAsync().renderTexture(frame);
	}

}
