#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include <memory>

#include "GameState.h"

#include "Graph/GraphicsScene.h"
#include "Graph/Camera.h"

namespace State
{

class IntroState : public GameState
	{
	public:
	IntroState();

	void start(std::shared_ptr<SwitchStateInfo> info) override;
	void update(std::chrono::milliseconds elapsed) override;

	private:
	Graphics::Texture prepareFrame(std::chrono::milliseconds msecs);
	void renderFrame(const Graphics::Texture& frame);

	private:
	Graphics::GraphicsScene graphicsScene;
	Graphics::Camera camera;
	std::chrono::milliseconds totalElapsed;
	std::chrono::milliseconds introDuration;
	std::shared_ptr<SwitchStateInfo> switchToLoadingInfo;
	};

}

#endif // INTRO_STATE_H
