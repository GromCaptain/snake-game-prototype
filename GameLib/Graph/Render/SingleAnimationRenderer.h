#ifndef SINGLE_ANIMATION_RENDERER_H
#define SINGLE_ANIMATION_RENDERER_H

#include "InitialRenderingStage.h"
#include "Graph/GraphCore/Animation.h"

namespace Graphics
{

class SingleAnimationRenderer : public InitialRenderingStage
	{
	public:
	SingleAnimationRenderer();
	SingleAnimationRenderer(const Animation animation);
	void setAnimation(const Animation& animation);

	virtual Texture renderFrame() const override;
	virtual void update(std::chrono::milliseconds elapsed) override;

	private:
	Animation animation_;
	};

}

#endif // SINGLE_ANIMATION_RENDERER_H
