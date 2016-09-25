#ifndef ACTOR_H
#define ACTOR_H

#include <map>
#include <chrono>
#include <functional>

#include "Animation.h"
#include "AnimationCollection.h"

#include "Core/String.h"
#include "Core/Utility/Geometry/Point.h"
#include "Core/Utility/Geometry/Rectangle.h"

namespace Graphics
{

class Texture;
class Animation;

using FrameUpdater = std::function<Texture(AnimationCollection&, std::chrono::milliseconds)>;

class Actor
	{
	public:
	Actor(const Point& position, const Animation& animation, const String& animationName = defaultAnimationName);
	Actor(const Point& position, const AnimationCollection& animations, const String& currentAnimation);
	Actor(const Point& position, const Size& size, const AnimationCollection& animations, FrameUpdater updater);

	Actor(const Actor&) = delete;
	Actor& operator=(const Actor&) = delete;

	void update(std::chrono::milliseconds elapsed);

	void switchToAnimation(const String& animationName);

	Texture currentFrame() const;

	void move(const Point& position);
	Rectangle rect() const;
	Texture updatedFrameFromCurrentAnimation(AnimationCollection& animations, std::chrono::milliseconds elapsed);

	static const String defaultAnimationName;

	private:
	const Animation& currentAnimation() const;
	Animation& currentAnimation();

	private:
	AnimationCollection animations_;
	String currAnimation_;
	Rectangle rect_;
	FrameUpdater updater_;
	};

}

#endif // ACTOR_H
