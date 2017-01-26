#ifndef ANIMATION_COLLECTION_H
#define ANIMATION_COLLECTION_H

#include <map>

#include "Texture.h"
#include "Core/Data/String.h"

class ResourcePack;

namespace Graphics
{

class Animation;

class AnimationCollection
	{
	public:
	AnimationCollection(const Animation& animation, const String& animationName);
	explicit AnimationCollection(const std::map<String, Animation>& animations);

	bool contains(const String& animationName) const;
	const Animation& animation(const String& name) const;
	Animation& animation(const String& name);

	void setCurrentFrame(const Texture& frame);
	Texture currentFrame() const;

	private:
	std::map<String, Animation> animations_;
	Texture currentFrame_;
	};

}

#endif // ANIMATION_COLLECTION_H
