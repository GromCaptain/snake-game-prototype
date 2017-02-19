#ifndef UI_GRAPHICS_SCENE_PAGE_H
#define UI_GRAPHICS_SCENE_PAGE_H

#include <chrono>
#include <memory>
#include <vector>

namespace Graphics
{

class Texture;
class UIActor;

class UIGraphicsScenePage
	{
	public:
	UIGraphicsScenePage();

	Texture render(const Texture& background) const;

	void update(std::chrono::milliseconds elapsed);
	void addActor(std::shared_ptr<UIActor> actor);

	private:
	std::vector<std::shared_ptr<UIActor>> actorsSortedByZ() const;

	private:
	std::vector<std::shared_ptr<UIActor>> actors_;
	};

}

#endif // UI_GRAPHICS_SCENE_PAGE_H
