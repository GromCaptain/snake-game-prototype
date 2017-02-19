#include "Actor.h"

#include <utility>

#include "Graph/GraphCore/Animation.h"
#include "Graph/GraphCore/Texture.h"
#include "Core/Util/Assert.h"

namespace Graphics
{

const String Actor::defaultAnimationName = "animation";

Actor::Actor(const Point& leftTopPosition, const Animation& animation):
	animations_(animation, defaultAnimationName), currAnimation_(defaultAnimationName),
	rect_(leftTopPosition, animation.size()),
	updater_(std::bind(&Actor::updatedFrameFromCurrentAnimation, this, std::placeholders::_1, std::placeholders::_2))
	{
	}

Actor::Actor(const Point& leftTopPosition, const AnimationCollection& animations, const String& currentAnimation):
	animations_(animations), currAnimation_(currentAnimation),
	rect_(leftTopPosition, animations.animation(currentAnimation).size()),
	updater_(std::bind(&Actor::updatedFrameFromCurrentAnimation, this, std::placeholders::_1, std::placeholders::_2))
	{
	ASSERT(!currAnimation_.empty(), "current animation name is empty");
	}

Actor::Actor(const Point& leftTopPosition, const Size& size, const AnimationCollection& animations, FrameUpdater updater):
	animations_(animations), currAnimation_("such_actor_does_not_need_current_animation_name"),
	rect_(leftTopPosition, size), updater_(updater)
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

void Actor::move(const Point& leftTopPosition)
	{
	Size rectSize = rect_.size();
	rect_ = { leftTopPosition, rectSize };
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
