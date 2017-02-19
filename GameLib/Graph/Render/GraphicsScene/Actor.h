#ifndef ACTOR_H
#define ACTOR_H

#include <map>
#include <chrono>
#include <functional>

#include "Graph/GraphCore/Animation.h"
#include "Graph/GraphCore/AnimationCollection.h"

#include "Core/Data/String.h"
#include "Core/Data/Geometry/Point.h"
#include "Core/Data/Geometry/Rectangle.h"

namespace Graphics
{

class Texture;
class Animation;

using FrameUpdater = std::function<Texture(AnimationCollection&, std::chrono::milliseconds)>;

class Actor
	{
	public:
	Actor(const Point& leftTopPosition, const Animation& animation);
	Actor(const Point& leftTopPosition, const AnimationCollection& animations, const String& currentAnimation);
	Actor(const Point& leftTopPosition, const Size& size, const AnimationCollection& animations, FrameUpdater updater);

	Actor(const Actor&) = delete;
	Actor& operator=(const Actor&) = delete;

	void update(std::chrono::milliseconds elapsed);

	void switchToAnimation(const String& animationName);

	Texture currentFrame() const;

	void move(const Point& leftTopPosition);
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
