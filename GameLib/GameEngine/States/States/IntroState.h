#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include <memory>

#include "GameState.h"

#include "Graph/Render/GraphicsScene/GraphicsScene.h"
#include "Graph/Render/GraphicsScene/Camera.h"
#include "UI/UIScene.h"

namespace State
{

class IntroState : public GameState
	{
	public:
	IntroState();

	void start(std::shared_ptr<SwitchStateInfo> info) override;
	void update(std::chrono::milliseconds elapsed) override;

	void interruptIntro();

	private:
	void handleInput();

	bool finished() const;
	Graphics::Texture prepareFrame(std::chrono::milliseconds msecs);
	void renderFrame(const Graphics::Texture& frame);

	private:
	UI::UIScene uiScene_;
	Graphics::GraphicsScene graphicsScene_;
	Graphics::Camera camera_;
	std::chrono::milliseconds totalElapsed_;
	std::chrono::milliseconds introDuration_;
	std::shared_ptr<SwitchStateInfo> switchToLoadingInfo_;
	bool interrupted_ = false;
	};

}

#endif // INTRO_STATE_H
