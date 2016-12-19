#include "Background.h"

#include "Input/Events/KeyboardEvent.h"

namespace UI
{

Background::Background(UIScene& uiScene, const Geometry& geometry):
	UIComponent(uiScene, geometry)
	{
	}

void Background::handleKeyboardEvent(std::shared_ptr<Input::KeyboardEvent> keyboardEvent)
	{
	Input::KeyboardKey key = keyboardEvent -> key();
	if (keyboardEvent -> type() == Input::EventType::KeyPress)
		findAndInvokeCallback(key2PressCallback_, key);
	findAndInvokeCallback(key2ReleaseCallback_, key);
	}

void Background::handleMouseButtonEvent(std::shared_ptr<Input::MouseButtonEvent> mouseButtonEvent)
	{
	//
	}

void Background::handleMouseMoveEvent(std::shared_ptr<Input::MouseMoveEvent> mouseMoveEvent)
	{
	//
	}

void Background::registerKeyPressCallback(Input::KeyboardKey key, std::function<void ()> callback)
	{
	key2PressCallback_.emplace(key, callback);
	}

void Background::registerKeyReleaseCallback(Input::KeyboardKey key, std::function<void ()> callback)
	{
	key2ReleaseCallback_.emplace(key, callback);
	}

void Background::findAndInvokeCallback(UnorderedMap<Input::KeyboardKey, std::function<void()>>& key2Callback, Input::KeyboardKey key)
	{
	auto it = key2Callback.find(key);
	if (it == key2Callback.end())
		return;
	(it -> second)();
	}

}
