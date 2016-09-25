#ifndef ANIMATION_LOADER_H
#define ANIMATION_LOADER_H

class ResourcePack;

namespace Graphics
{

class Animation;

class AnimationLoader
	{
	public:
	AnimationLoader();
	
	static Animation loadFromResources(const ResourcePack& resourcePack);
	};

}

#endif // ANIMATION_LOADER_H
