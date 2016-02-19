#ifndef GRAPHICS_SCENE_H
#define GRAPHICS_SCENE_H

#include <chrono>
#include <array>
#include <map>

#include "GraphicsSceneLayer.h"
#include "Core/Utility/Geometry/Size.h"

namespace Graphics
{

class Actor;
class GraphicsSceneLayer;

class GraphicsScene
	{
	public:
	GraphicsScene();

	Size areaSize() const;
	void resizeArea(const Size& areaSize);

	void update(std::chrono::milliseconds elapsed);

	enum class Layer { Background, Actors, HUD };

	void addActor(Layer targetLayer, const Actor& actor);

	const std::vector<Actor> actorsInArea(Layer sourceLayer, const Rectangle& area) const;

	static const std::array<Layer, 3> layersOrder;

	private:
	const GraphicsSceneLayer& getLayer(Layer layer) const;
	GraphicsSceneLayer& getLayer(Layer layer);

	private:
	Size areaSize_;
	std::map<Layer, GraphicsSceneLayer> layers_;
	};

}

#endif // GRAPHICS_SCENE_H
