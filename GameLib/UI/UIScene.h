#ifndef UI_SCENE_H
#define UI_SCENE_H

#include <memory>
#include <queue>
#include <vector>

#include "Components/Background.h"
#include "Core/Data/Geometry/Size.h"

class Geometry;

namespace Input
{
class InputEvent;
}

namespace UI
{

class UIComponent;

class UIScene
	{
	public:
	UIScene();

	void resize(const Size& size);
	void addComponent(std::shared_ptr<UIComponent> component);

	void handleInput(std::queue<std::shared_ptr<Input::InputEvent>>& eventQueue);

	void registerBkgKeyPressCallback(Input::KeyboardKey key, std::function<void()> callback);
	void registerBkgKeyReleaseCallback(Input::KeyboardKey key, std::function<void()> callback);

	private:
	void handleKeyboardEvent(std::shared_ptr<Input::KeyboardEvent> keyboardEvent);
	void handleMouseButtonEvent(std::shared_ptr<Input::MouseButtonEvent> mouseButtonEvent);
	void handleMouseMoveEvent(std::shared_ptr<Input::MouseMoveEvent> mouseMoveEvent);

	private:
	Size size_;
	std::vector<std::shared_ptr<UIComponent>> components_;
	Background background_;
	std::shared_ptr<UIComponent> activeComponent_;
	};

}

#endif // UI_SCENE_H
