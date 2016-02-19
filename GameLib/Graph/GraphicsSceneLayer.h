#ifndef GRAPHICS_SCENE_LAYER_H
#define GRAPHICS_SCENE_LAYER_H

#include <chrono>
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

	void addActor(const Actor& actor);

	const std::vector<Actor> actorsInArea(const Rectangle& area) const;

	private:
	std::vector<Actor> actors_;
	};

}

#endif // GRAPHICS_SCENE_LAYER_H
