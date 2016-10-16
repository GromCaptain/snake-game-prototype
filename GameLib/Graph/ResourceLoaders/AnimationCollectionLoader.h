#ifndef ANIMATION_COLLECTION_LOADER_H
#define ANIMATION_COLLECTION_LOADER_H

namespace Resources
{
class ResourcePack;
}

namespace Graphics
{

class AnimationCollection;

class AnimationCollectionLoader
	{
	public:
	AnimationCollectionLoader();

	static AnimationCollection loadFromResources(const Resources::ResourcePack& resourcePack);
	};

}

#endif // ANIMATION_COLLECTION_LOADER_H
