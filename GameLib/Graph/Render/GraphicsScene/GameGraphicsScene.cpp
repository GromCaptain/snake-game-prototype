#include "GameGraphicsScene.h"

#include "Core/Util/Assert.h"

namespace Graphics
{

GameGraphicsScene::GameGraphicsScene(const Size& areaSize):
	areaSize_(areaSize), layers_{ { GameLayer::Background, GraphicsSceneLayer{} }, { GameLayer::Actors, GraphicsSceneLayer{} } }, camera_(*this, areaSize)
	{
	}

Texture GameGraphicsScene::renderFrame() const
	{
	return camera_.getFrame();
	}

void GameGraphicsScene::resizeArea(const Size& areaSize)
	{
	areaSize_ = areaSize;
	}

void GameGraphicsScene::moveCamera(const Point& viewportCenter)
	{
	camera_.moveTo(viewportCenter);
	}

void GameGraphicsScene::setCameraResolution(const Size& resolution)
	{
	camera_.setResolution(resolution);
	}

ActorID GameGraphicsScene::addActor(GameLayer targetLayer, std::shared_ptr<Actor> actor)
	{
	return getLayer(targetLayer).addActor(actor);
	}

void GameGraphicsScene::update(std::chrono::milliseconds elapsed)
	{
	for (auto& layer : layers_)
		layer.second.update(elapsed);
	}

void GameGraphicsScene::deleteActor(GameLayer ownerLayer, ActorID id)
	{
	getLayer(ownerLayer).deleteActor(id);
	}

const GraphicsSceneLayer& GameGraphicsScene::getLayer(GameLayer layer) const
	{
	auto it = layers_.find(layer);
	ASSERT(it != layers_.end(), "invalid graphics scene layer");
	return it -> second;
	}

GraphicsSceneLayer& GameGraphicsScene::getLayer(GameLayer layer)
	{
	auto it = layers_.find(layer);
	ASSERT(it != layers_.end(), "invalid graphics scene layer");
	return it -> second;
	}

}
