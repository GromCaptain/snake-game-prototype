#ifndef LOADING_STATE_H
#define LOADING_STATE_H

#include <atomic>

#include "GameState.h"

//#include "Graph/Render/GraphicsScene/Camera.h"
//#include "Graph/Render/GraphicsScene/GraphicsScene.h"
#include "Graph/Render/RenderingPipeline.h"
#include "Graph/Render/UIGraphicsScene/UIGraphicsScene.h"
#include "SwitchInfo/SwitchToLoadingInfo.h"
#include "UI/UIScene.h"

namespace Graphics
{
class Texture;
class AnimationCollection;

class SingleAnimationRenderer;
}

namespace Resources
{
class ResourcePack;
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
	void initGraphics(std::shared_ptr<SwitchStateInfo> info);
	void loadPackAndInitNextState(const String& packFileName, StateInitCallback initNextStateCallback);
	Resources::ResourcePack loadPack(const String& fileName);
	Graphics::Texture prepareFrame(std::chrono::milliseconds elapsed);
	void renderFrame(const Graphics::Texture& frame);
	void updateLoadPackStageProgress(double progress);
	void updateInitFromPackStageProgress(double progress);

	private:
	enum class UIPage { Main };

	private:
	UI::UIScene uiScene_;
	const std::shared_ptr<Graphics::SingleAnimationRenderer> bkgRenderer_;
	const std::shared_ptr<Graphics::UIGraphicsScene<UIPage>> uiGraphicsScene_;
	std::shared_ptr<UI::ProgressBar> loadingProgressBar_;
	Graphics::RenderingPipeline renderer_;
	bool graphicsInitialized_ = false;

	std::atomic<double> loadingPackProgress_;
	std::atomic<double> initFromPackProgress_;
	std::chrono::milliseconds totalElapsedForDemo_ = std::chrono::milliseconds(0);
	};

}

#endif // LOADING_STATE_H
