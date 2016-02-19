#include "GraphicsSceneLayer.h"

#include "Actor.h"

namespace Graphics
{

GraphicsSceneLayer::GraphicsSceneLayer()
	{
	}

void GraphicsSceneLayer::update(std::chrono::milliseconds elapsed)
	{
	for (auto& actor : actors_)
		actor.update(elapsed);
	}

void GraphicsSceneLayer::addActor(const Actor& actor)
	{
	actors_.push_back(actor);
	}

const std::vector<Actor> GraphicsSceneLayer::actorsInArea(const Rectangle& area) const
	{
	std::vector<Actor> result;
	for (const auto& actor : actors_)
		if (actor.rect().intersects(area))
			result.push_back(actor);
	return result;
	}

}
