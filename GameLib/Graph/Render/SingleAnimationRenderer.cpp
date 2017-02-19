#include "SingleAnimationRenderer.h"

#include "Core/Data/Geometry/Rectangle.h"

namespace Graphics
{

SingleAnimationRenderer::SingleAnimationRenderer():
	animation_({})
	{
	}

SingleAnimationRenderer::SingleAnimationRenderer(const Animation animation):
	animation_(animation)
	{
	}

void SingleAnimationRenderer::setAnimation(const Animation& animation)
	{
	animation_ = animation;
	}

Texture SingleAnimationRenderer::renderFrame() const
	{
	return animation_.currentFrame();
	}

void SingleAnimationRenderer::update(std::chrono::milliseconds elapsed)
	{
	animation_.update(elapsed);
	}

}
