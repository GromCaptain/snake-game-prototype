#include "UIScene.h"

namespace UI
{

UIScene::UIScene()
	{
	}

void UIScene::addComponent(std::shared_ptr<UIComponent> component)
	{
	components_.push_back(component);
	}

}
