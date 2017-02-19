#include "UIActor.h"

#include "Core/Util/Assert.h"
#include "Graph/GraphCore/Animation.h"

namespace Graphics
{

const String UIActor::defaultAnimationName = "animation";

UIActor::UIActor(const Rectangle& rect, const Animation& animation):
	rect_(rect), currAnimation_(defaultAnimationName), animations_(animation, currAnimation_),
	updater_(std::bind(&UIActor::updateFrameFromCurrAnimation, this, std::placeholders::_1, std::placeholders::_2))
	{
	}

UIActor::UIActor(const Rectangle& rect, const AnimationCollection& animations, const String& currentAnimation):
	rect_(rect), currAnimation_(currentAnimation), animations_(animations),
	updater_(std::bind(&UIActor::updateFrameFromCurrAnimation, this, std::placeholders::_1, std::placeholders::_2))
	{
	ASSERT(!currAnimation_.empty(), "current animation name is empty");
	}

UIActor::UIActor(const Rectangle& rect, const AnimationCollection& animations, FrameUpdater updater):
	rect_(rect), currAnimation_("such_actor_does_not_need_current_animation_name"), animations_(animations), updater_(updater)
	{
	}

void UIActor::update(std::chrono::milliseconds elapsed)
	{
	animations_.setCurrentFrame(updater_(animations_, elapsed));
	}

Texture UIActor::currentFrame() const
	{
	return animations_.currentFrame();
	}

Rectangle UIActor::rect() const
	{
	return rect_;
	}

void UIActor::setRect(const Rectangle& rect)
	{
	rect_ = rect;
	}

int UIActor::zValue() const
	{
	return zValue_;
	}

void UIActor::setZValue(int zValue)
	{
	zValue_ = zValue;
	}

Texture UIActor::updateFrameFromCurrAnimation(AnimationCollection& animations, std::chrono::milliseconds elapsed)
	{
	auto& currAnim = animations.animation(currAnimation_);
	currAnim.update(elapsed);
	return currAnim.currentFrame();
	}

}
