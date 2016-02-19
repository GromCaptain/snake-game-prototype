#ifndef LOADING_STATE_H
#define LOADING_STATE_H

#include "GameState.h"

#include "Graph/GraphicsScene.h"
#include "Graph/Camera.h"

namespace Graphics
{
class Texture;
}

namespace State
{

class LoadingState : public GameState
	{
	public:
	LoadingState();

	void start(std::shared_ptr<SwitchStateInfo> info) override;
	void update(std::chrono::milliseconds elapsed) override;

	private:
	Graphics::Texture prepareFrame(std::chrono::milliseconds msecs);
	void renderFrame(const Graphics::Texture& frame);

	private:
	Graphics::GraphicsScene scene;
	Graphics::Camera camera;
	};

}

#endif // LOADING_STATE_H
