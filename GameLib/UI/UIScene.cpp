#include "UIScene.h"

#include "Core/Util/Assert.h"
#include "Input/Events/KeyboardEvent.h"
#include "Input/Events/MouseButtonEvent.h"
#include "Input/Events/MouseMoveEvent.h"

namespace UI
{

UIScene::UIScene():
	size_(100, 100),
	background_(*this)
	{
	}

void UIScene::resize(const Size& size)
	{
	for (auto compPtr : components_)
		compPtr -> resizeAfterScreen(size);
	size_ = size;
	}

void UIScene::addComponent(std::shared_ptr<UIComponent> component)
	{
	components_.push_back(component);
	}

void UIScene::handleInput(std::queue<std::shared_ptr<Input::InputEvent>>& eventQueue)
	{
	while (!eventQueue.empty())
		{
		auto eventPtr = eventQueue.front();
		eventQueue.pop();

		switch (eventPtr -> type())
			{
			case Input::EventType::KeyPress:
			case Input::EventType::KeyRelease:
				{
				auto keyEvent = std::dynamic_pointer_cast<Input::KeyboardEvent>(eventPtr);
				handleKeyboardEvent(keyEvent);
				} break;
			case Input::EventType::MousePress:
			case Input::EventType::MouseRelease:
				{
				auto mouseEvent = std::dynamic_pointer_cast<Input::MouseButtonEvent>(eventPtr);
				handleMouseButtonEvent(mouseEvent);
				} break;
			case Input::EventType::MouseMove:
				{
				auto moveEvent = std::dynamic_pointer_cast<Input::MouseMoveEvent>(eventPtr);
				handleMouseMoveEvent(moveEvent);
				}
			default:
				ASSERT(false, "Unknown input event type");
			}
		}
	}

void UIScene::registerBkgKeyPressCallback(Input::KeyboardKey key, std::function<void ()> callback)
	{
	background_.registerKeyPressCallback(key, callback);
	}

void UIScene::registerBkgKeyReleaseCallback(Input::KeyboardKey key, std::function<void ()> callback)
	{
	background_.registerKeyReleaseCallback(key, callback);
	}

void UIScene::handleKeyboardEvent(std::shared_ptr<Input::KeyboardEvent> keyboardEvent)
	{
	if (!keyboardEvent -> handled())
		background_.handleKeyboardEvent(keyboardEvent);
	}

void UIScene::handleMouseButtonEvent(std::shared_ptr<Input::MouseButtonEvent> mouseButtonEvent)
	{
	//
	}

void UIScene::handleMouseMoveEvent(std::shared_ptr<Input::MouseMoveEvent> mouseMoveEvent)
	{
	//
	}

}
