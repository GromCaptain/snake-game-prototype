#ifndef ACTOR_H
#define ACTOR_H

#include <map>
#include <chrono>
#include <functional>

#include "Animation.h"

#include "Core/String.h"
#include "Core/Utility/Geometry/Point.h"
#include "Core/Utility/Geometry/Rectangle.h"

namespace Graphics
{

class Animation;
class Texture;

using AnimationUpdater = std::function<void(Animation&, std::chrono::milliseconds)>;

class Actor
	{
	public:
	Actor(const Point& position, const Animation& animation, const String& animationName = defaultAnimationName, AnimationUpdater updater = simpleUpdater);
	Actor(const Point& position, const std::map<String, Animation>& animations, const String& currentAnimation, AnimationUpdater updater = simpleUpdater);

	void update(std::chrono::milliseconds elapsed);

	void switchToAnimation(const String& animationName);

	Texture currentFrame() const;

	Point position() const;
	void move(const Point& position);
	Rectangle rect() const;

	static const String defaultAnimationName;
	static const AnimationUpdater simpleUpdater;

	private:
	const Animation& currentAnimation() const;
	Animation& currentAnimation();

	private:
	std::map<String, Animation> animations_;
	String currAnimation_;
	Point position_;
	Rectangle rect_;
	AnimationUpdater updater_;
	};

}

#endif // ACTOR_H
