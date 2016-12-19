#include "UIComponent.h"

namespace UI
{

UIComponent::UIComponent(UIScene& uiScene, const Geometry& geometry):
	uiScene_(uiScene), geometry_(geometry)
	{
	}

void UIComponent::resizeAfterScreen(const Size& screenSize)
	{
	geometry_.resizeAfterScreen(screenSize);
	}

void UIComponent::handleKeyboardEvent(std::shared_ptr<Input::KeyboardEvent> keyboardEvent)
	{
	}

void UIComponent::handleMouseButtonEvent(std::shared_ptr<Input::MouseButtonEvent> mouseButtonEvent)
	{
	}

void UIComponent::handleMouseMoveEvent(std::shared_ptr<Input::MouseMoveEvent> mouseMoveEvent)
	{
	}

Geometry UIComponent::geometry() const
	{
	return geometry_;
	}

}
