#include "Actor.h"

#include <utility>

#include "Core/Assert.h"
#include "Animation.h"
#include "Texture.h"

namespace Graphics
{

const String Actor::defaultAnimationName = "animation";
const AnimationUpdater Actor::simpleUpdater = [](Animation& anim, std::chrono::milliseconds elapsed) { anim.update(elapsed); };

Actor::Actor(const Point& position, const Animation& animation, const String& animationName, AnimationUpdater updater):
	animations_({{animationName, animation}}), currAnimation_(animationName),
	position_(position), rect_({0, 0}, animation.size()), updater_(updater)
	{
	}

Actor::Actor(const Point& position, const std::map<String, Animation>& animations, const String& currentAnimation, AnimationUpdater updater):
	animations_(animations), currAnimation_(currentAnimation),
	position_(position), rect_({0, 0}, (animations.begin() -> second).size()), updater_(updater)
	{
	ASSERT(animations_.find(currAnimation_) != animations_.end(), "current animation name initialized by invalid value");
	}

void Actor::update(std::chrono::milliseconds elapsed)
	{
	updater_(currentAnimation(), elapsed);
	}

void Actor::switchToAnimation(const String& animationName)
	{
	if (currAnimation_ == animationName)
		return;
	auto it = animations_.find(animationName);
	if (it == animations_.end())
		return;
	currAnimation_ = animationName;
	(it -> second).reset();
	}

Texture Actor::currentFrame() const
	{
	return currentAnimation().currentFrame();
	}

Point Actor::position() const
	{
	return position_;
	}

void Actor::move(const Point& position)
	{
	position_ = position;
	}

Rectangle Actor::rect() const
	{
	return rect_;
	}

const Animation& Actor::currentAnimation() const
	{
	auto it = animations_.find(currAnimation_);
	ASSERT(it != animations_.end(), "invalid current animation name");
	return it -> second;
	}

Animation&Actor::currentAnimation()
	{
	auto it = animations_.find(currAnimation_);
	ASSERT(it != animations_.end(), "invalid current animation name");
	return it -> second;
	}

}
