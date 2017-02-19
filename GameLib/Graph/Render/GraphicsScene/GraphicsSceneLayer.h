#ifndef GRAPHICS_SCENE_LAYER_H
#define GRAPHICS_SCENE_LAYER_H

#include <chrono>
#include <memory>
#include <vector>

#include "Actor.h"
#include "ActorID.h"

class Rectangle;

namespace Graphics
{

class Actor;

class GraphicsSceneLayer
	{
	public:
	GraphicsSceneLayer();

	void update(std::chrono::milliseconds elapsed);

	ActorID addActor(std::shared_ptr<Actor> actor);
	void deleteActor(ActorID id);

	const std::vector<std::shared_ptr<Actor>> actorsInArea(const Rectangle& area) const;

	private:
	ActorID nextId_;
	std::map<ActorID, std::shared_ptr<Actor>> actors_;
	};

}

#endif // GRAPHICS_SCENE_LAYER_H
