#ifndef ANIMATION_LOADER_H
#define ANIMATION_LOADER_H

namespace Resources
{
class ResourcePack;
}

namespace Graphics
{

class Animation;

class AnimationLoader
	{
	public:
	AnimationLoader();
	
	static Animation loadFromResources(const Resources::ResourcePack& resourcePack);
	};

}

#endif // ANIMATION_LOADER_H
