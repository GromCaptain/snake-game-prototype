#ifndef GRAPHICS_SCENE_LAYER_H
#define GRAPHICS_SCENE_LAYER_H

#include <chrono>
#include <memory>
#include <vector>

#include "Actor.h"

class Rectangle;

namespace Graphics
{

class Actor;

class GraphicsSceneLayer
	{
	public:
	GraphicsSceneLayer();

	void update(std::chrono::milliseconds elapsed);

	void addActor(std::shared_ptr<Actor> actor);

	const std::vector<std::shared_ptr<Actor>> actorsInArea(const Rectangle& area) const;

	private:
	std::vector<std::shared_ptr<Actor>> actors_;
	};

}

#endif // GRAPHICS_SCENE_LAYER_H
