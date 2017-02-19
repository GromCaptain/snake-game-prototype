#include "UIComponent.h"

#include "Graph/Render/UIGraphicsScene/UIActor.h"

namespace UI
{

UIComponent::UIComponent(UIScene& uiScene, std::shared_ptr<Graphics::UIActor> actor, const Geometry& geometry):
	uiScene_(uiScene), actor_(actor), geometry_(geometry)
	{
	}

void UIComponent::resizeAfterScreen(const Size& screenSize)
	{
	geometry_.resizeAfterScreen(screenSize);
	actor_ -> setRect(geometry_.rect());
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
