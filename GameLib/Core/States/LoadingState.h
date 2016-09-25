#ifndef LOADING_STATE_H
#define LOADING_STATE_H

#include "GameState.h"

#include "Graph/GraphicsScene.h"
#include "Graph/Camera.h"
#include "UI/UIScene.h"

namespace Graphics
{
class Texture;
}

namespace UI
{
class ProgressBar;
}

namespace State
{

class LoadingState : public GameState
	{
	public:
	LoadingState();

	void start(std::shared_ptr<SwitchStateInfo> info) override;
	void update(std::chrono::milliseconds elapsed) override;

	unsigned currentPercentProgress() const;
	Graphics::Texture updateProgressBarFrame(Graphics::AnimationCollection& progressBarAnimations, std::chrono::milliseconds elapsed);

	private:
	Graphics::Texture prepareFrame(std::chrono::milliseconds msecs);
	void renderFrame(const Graphics::Texture& frame);

	private:
	Graphics::GraphicsScene graphicsScene;
	Graphics::Camera camera;
	UI::UIScene uiScene;
	std::shared_ptr<UI::ProgressBar> loadingProgressBar;
	bool graphicsInitialized = false;

	std::chrono::milliseconds totalElapsedForDemo = std::chrono::milliseconds(0);
	};

}

#endif // LOADING_STATE_H
