#include "GraphicsScene.h"

#include "Actor.h"
#include "GraphicsSceneLayer.h"
#include "Core/Assert.h"

namespace Graphics
{

const std::array<GraphicsScene::Layer, 3> GraphicsScene::layersOrder = { Layer::Background, Layer::Actors, Layer::HUD };

GraphicsScene::GraphicsScene():
	layers_({ { Layer::Background, {} }, { Layer::Actors, {} }, { Layer::HUD, {} } })
	{
	}

Size GraphicsScene::areaSize() const
	{
	return areaSize_;
	}

void GraphicsScene::resizeArea(const Size& areaSize)
	{
	areaSize_ = areaSize;
	}

void GraphicsScene::update(std::chrono::milliseconds elapsed)
	{
	for (auto& layer : layers_)
		layer.second.update(elapsed);
	}

void GraphicsScene::addActor(GraphicsScene::Layer targetLayer, const Actor& actor)
	{
	getLayer(targetLayer).addActor(actor);
	}

const std::vector<Actor> GraphicsScene::actorsInArea(GraphicsScene::Layer sourceLayer, const Rectangle& area) const
	{
	return getLayer(sourceLayer).actorsInArea(area);
	}

const GraphicsSceneLayer& GraphicsScene::getLayer(GraphicsScene::Layer layer) const
	{
	auto it = layers_.find(layer);
	ASSERT(it != layers_.end(), "invalid graphics scene layer");
	return it -> second;
	}

GraphicsSceneLayer& GraphicsScene::getLayer(GraphicsScene::Layer layer)
	{
	auto it = layers_.find(layer);
	ASSERT(it != layers_.end(), "invalid graphics scene layer");
	return it -> second;
	}

}
