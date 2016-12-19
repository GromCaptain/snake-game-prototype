#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <functional>
#include <chrono>

#include "UIComponent.h"

namespace Graphics
{

class Texture;
class AnimationCollection;

}

namespace UI
{

class ProgressBar : public UIComponent
	{
	public:
	using ProgressUpdater = std::function<unsigned()>;

	ProgressBar(UIScene& uiScene, const Geometry& geometry, ProgressUpdater progressUpdater);

	Graphics::Texture updateActorFrame(Graphics::AnimationCollection& animations, std::chrono::milliseconds elapsed);

	private:
	Graphics::Texture buildBackgroundTexture(const Graphics::AnimationCollection& animations) const;
	Graphics::Texture buildProgressLineTexture(Graphics::AnimationCollection& animations, std::chrono::milliseconds elapsed, unsigned width, unsigned percent) const;

	private:
	ProgressUpdater progressUpdater_;
	};

}

#endif // PROGRESS_BAR_H
