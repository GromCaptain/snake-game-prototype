#ifndef UI_SCENE_H
#define UI_SCENE_H

#include <memory>
#include <vector>

namespace UI
{

class UIComponent;

class UIScene
	{
	public:
	UIScene();

	void addComponent(std::shared_ptr<UIComponent> component);

	private:
	std::vector<std::shared_ptr<UIComponent>> components_;
	};

}

#endif // UI_SCENE_H
