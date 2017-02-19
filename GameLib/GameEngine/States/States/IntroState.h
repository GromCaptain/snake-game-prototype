#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include <memory>

#include "GameState.h"

#include "Graph/Render/RenderingPipeline.h"
#include "Graph/Render/UIGraphicsScene/UIGraphicsScene.h"
#include "UI/UIScene.h"

namespace Graphics
{
class SingleAnimationRenderer;
}

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
	Graphics::Texture prepareFrame(std::chrono::milliseconds elapsed);
	void renderFrame(const Graphics::Texture& frame);

	private:
	enum class UIPage { Main };

	private:
	UI::UIScene uiScene_;
	const std::shared_ptr<Graphics::SingleAnimationRenderer> splashAnimRenderer_;
	const std::shared_ptr<Graphics::UIGraphicsScene<UIPage>> uiGraphicsScene_;
	Graphics::RenderingPipeline renderer_;

	std::chrono::milliseconds totalElapsed_;
	std::chrono::milliseconds introDuration_;
	std::shared_ptr<SwitchStateInfo> switchToLoadingInfo_;
	bool interrupted_ = false;
	};

}

#endif // INTRO_STATE_H
