#ifndef GAME_GRAPHICS_SCENE_H
#define GAME_GRAPHICS_SCENE_H

#include <array>
#include <chrono>

#include "ActorID.h"
#include "Camera.h"
#include "GraphicsSceneLayer.h"
#include "LayersOwner.h"
#include "../InitialRenderingStage.h"

namespace Graphics
{

enum class GameLayer { Background, Actors };

class GameGraphicsScene : public InitialRenderingStage, LayersOwner<GameLayer>
	{
	public:
	GameGraphicsScene(const Size& areaSize);

	virtual Texture renderFrame() const override;
	virtual void update(std::chrono::milliseconds elapsed) override;

	void resizeArea(const Size& areaSize);
	void moveCamera(const Point& viewportCenter);
	void setCameraResolution(const Size& resolution);

	ActorID addActor(GameLayer targetLayer, std::shared_ptr<Actor> actor);

	void deleteActor(GameLayer ownerLayer, ActorID id);

	private:
	const GraphicsSceneLayer& getLayer(GameLayer layer) const;
	GraphicsSceneLayer& getLayer(GameLayer layer);

	private:
	static const std::array<GameLayer, 2> layersOrder;

	private:
	Size areaSize_;
	std::map<GameLayer, GraphicsSceneLayer> layers_;
	Camera<GameLayer> camera_;
	};

}

#endif // GAME_GRAPHICS_SCENE_H
