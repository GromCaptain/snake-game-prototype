#ifndef UI_ACTOR_H
#define UI_ACTOR_H

#include <chrono>
#include <functional>

#include "Graph/GraphCore/AnimationCollection.h"
#include "Core/Data/Geometry/Rectangle.h"

namespace Graphics
{

class Texture;
class Animation;

class UIActor
	{
	public:
	using FrameUpdater = std::function<Texture(AnimationCollection&, std::chrono::milliseconds)>;

	UIActor(const Rectangle& rect, const Animation& animation);
	UIActor(const Rectangle& rect, const AnimationCollection& animations, const String& currentAnimation);
	UIActor(const Rectangle& rect, const AnimationCollection& animations, FrameUpdater updater);

	void update(std::chrono::milliseconds elapsed);
	Texture currentFrame() const;

	Rectangle rect() const;
	void setRect(const Rectangle& rect);

	int zValue() const;
	void setZValue(int zValue);

	private:
	Texture updateFrameFromCurrAnimation(AnimationCollection& animations, std::chrono::milliseconds elapsed);

	private:
	static const String defaultAnimationName;

	private:
	Rectangle rect_;
	int zValue_;
	String currAnimation_;
	AnimationCollection animations_;
	FrameUpdater updater_;
	};

}

#endif // UIACTOR_H
