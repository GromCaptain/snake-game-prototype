#include "UIComponent.h"

namespace UI
{

UIComponent::UIComponent(const Geometry& geometry):
	geometry_(geometry)
	{
	}

void UIComponent::resizeAfterScreen(const Size& screenSize)
	{
	geometry_.resizeAfterScreen(screenSize);
	}

Geometry UIComponent::geometry() const
	{
	return geometry_;
	}

}
