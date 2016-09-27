#include "Actor.h"

#include <utility>

#include "Core/Assert.h"
#include "Animation.h"
#include "Texture.h"

namespace Graphics
{

const String Actor::defaultAnimationName = "animation";

Actor::Actor(const Point& position, const Animation& animation, const String& animationName):
	animations_(animation, animationName), currAnimation_(animationName),
	rect_(position, animation.size()),
	updater_(std::bind(&Actor::updatedFrameFromCurrentAnimation, this, std::placeholders::_1, std::placeholders::_2))
	{
	ASSERT(!currAnimation_.empty(), "current animation name is empty");
	}

Actor::Actor(const Point& position, const AnimationCollection& animations, const String& currentAnimation):
	animations_(animations), currAnimation_(currentAnimation),
	rect_(position, animations.animation(currentAnimation).size()),
	updater_(std::bind(&updatedFrameFromCurrentAnimation, this, std::placeholders::_1, std::placeholders::_2))
	{
	ASSERT(!currAnimation_.empty(), "current animation name is empty");
	}

Actor::Actor(const Point& position, const Size& size, const AnimationCollection& animations, FrameUpdater updater):
	animations_(animations), currAnimation_("such_actor_does_not_need_current_animation_name"),
	rect_(position, size), updater_(updater)
	{
	}

void Actor::update(std::chrono::milliseconds elapsed)
	{
	animations_.setCurrentFrame(updater_(animations_, elapsed));
	}

void Actor::switchToAnimation(const String& animationName)
	{
	if (currAnimation_ == animationName)
		return;
	if (!animations_.contains(animationName))
		return;
	currAnimation_ = animationName;
	animations_.animation(animationName).reset();
	}

Texture Actor::currentFrame() const
	{
	return animations_.currentFrame();
	}

void Actor::move(const Point& position)
	{
	Size rectSize = rect_.size();
	rect_ = { position, rectSize };
	}

Rectangle Actor::rect() const
	{
	return rect_;
	}

Texture Actor::updatedFrameFromCurrentAnimation(AnimationCollection& animations, std::chrono::milliseconds elapsed)
	{
	auto& currAnim = animations.animation(currAnimation_);
	currAnim.update(elapsed);
	return currAnim.currentFrame();
	}

const Animation& Actor::currentAnimation() const
	{
	return animations_.animation(currAnimation_);
	}

Animation& Actor::currentAnimation()
	{
	return animations_.animation(currAnimation_);
	}

}
