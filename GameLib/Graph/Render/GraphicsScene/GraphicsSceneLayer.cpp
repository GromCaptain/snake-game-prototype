#include "GraphicsSceneLayer.h"

#include "Actor.h"

namespace Graphics
{

GraphicsSceneLayer::GraphicsSceneLayer():
	nextId_(1)
	{
	}

void GraphicsSceneLayer::update(std::chrono::milliseconds elapsed)
	{
	for (auto& actorPair : actors_)
		actorPair.second -> update(elapsed);
	}

ActorID GraphicsSceneLayer::addActor(std::shared_ptr<Actor> actor)
	{
	ActorID id = nextId_++;
	actors_.emplace(id, actor);
	return id;
	}

void GraphicsSceneLayer::deleteActor(ActorID id)
	{
	auto it = actors_.find(id);
	if (it != actors_.end())
		actors_.erase(it);
	}

const std::vector<std::shared_ptr<Actor> > GraphicsSceneLayer::actorsInArea(const Rectangle& area) const
	{
	std::vector<std::shared_ptr<Actor>> result;
	for (const auto& actorPair : actors_)
		{
		const auto& actor = actorPair.second;
		if (actor -> rect().intersects(area))
			result.push_back(actor);
		}
	return result;
	}

}
