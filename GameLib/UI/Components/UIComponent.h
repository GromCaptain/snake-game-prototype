#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H

#include <memory>
#include <vector>

#include "Core/Data/Geometry/Geometry.h"

namespace Input
{
class KeyboardEvent;
class MouseButtonEvent;
class MouseMoveEvent;
}

namespace UI
{

class UIScene;

class UIComponent
	{
	public:
	explicit UIComponent(UIScene& uiScene, const Geometry& geometry);

	void resizeAfterScreen(const Size& screenSize);

	virtual void handleKeyboardEvent(std::shared_ptr<Input::KeyboardEvent> keyboardEvent);
	virtual void handleMouseButtonEvent(std::shared_ptr<Input::MouseButtonEvent> mouseButtonEvent);
	virtual void handleMouseMoveEvent(std::shared_ptr<Input::MouseMoveEvent> mouseMoveEvent);

	protected:
	Geometry geometry() const;

	protected:
	UIScene& uiScene_;

	private:
	std::vector<std::shared_ptr<UIComponent>> children_;
	Geometry geometry_;
	};

}

#endif // UI_COMPONENT_H
