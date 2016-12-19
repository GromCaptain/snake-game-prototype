#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <functional>

#include "UIComponent.h"
#include "Core/Util/UnorderedMap.h"
#include "Input/KeyboardKey.h"

namespace Input
{
class InputEvent;
}

namespace UI
{

class Background : public UIComponent
	{
	public:
	Background(UIScene& uiScene, const Geometry& geometry);

	void handleKeyboardEvent(std::shared_ptr<Input::KeyboardEvent> keyboardEvent) override;
	void handleMouseButtonEvent(std::shared_ptr<Input::MouseButtonEvent> mouseButtonEvent) override;
	void handleMouseMoveEvent(std::shared_ptr<Input::MouseMoveEvent> mouseMoveEvent) override;

	void registerKeyPressCallback(Input::KeyboardKey key, std::function<void()> callback);
	void registerKeyReleaseCallback(Input::KeyboardKey key, std::function<void()> callback);

	private:
	void findAndInvokeCallback(UnorderedMap<Input::KeyboardKey, std::function<void()>>& key2Callback, Input::KeyboardKey key);

	private:
	UnorderedMap<Input::KeyboardKey, std::function<void()>> key2PressCallback_;
	UnorderedMap<Input::KeyboardKey, std::function<void()>> key2ReleaseCallback_;
	};

}

#endif // BACKGROUND_H
