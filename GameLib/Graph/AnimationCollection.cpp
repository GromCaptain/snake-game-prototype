#include "AnimationCollection.h"

#include "Animation.h"
#include "Core/Assert.h"
#include "Core/Utility/Geometry/Rectangle.h"

namespace Graphics
{

AnimationCollection::AnimationCollection(const Animation& animation, const String& animationName):
	animations_({ { animationName, animation } })
	{
	}

AnimationCollection::AnimationCollection(const std::map<String, Animation>& animations):
	animations_(animations)
	{
	}

bool AnimationCollection::contains(const String& animationName) const
	{
	return animations_.find(animationName) != animations_.end();
	}

const Animation& AnimationCollection::animation(const String& name) const
	{
	auto it = animations_.find(name);
	ASSERT(it != animations_.end(), "invalid animation name");
	return it -> second;
	}

Animation& AnimationCollection::animation(const String& name)
	{
	auto it = animations_.find(name);
	ASSERT(it != animations_.end(), "invalid animation name");
	return it -> second;
	}

void AnimationCollection::setCurrentFrame(const Texture& frame)
	{
	currentFrame_ = frame;
	}

Texture AnimationCollection::currentFrame() const
	{
	return currentFrame_;
	}

}
