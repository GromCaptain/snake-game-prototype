#ifndef ANIMATION_COLLECTION_LOADER_H
#define ANIMATION_COLLECTION_LOADER_H

class ResourcePack;

namespace Graphics
{

class AnimationCollection;

class AnimationCollectionLoader
	{
	public:
	AnimationCollectionLoader();

	static AnimationCollection loadFromResources(const ResourcePack& resourcePack);
	};

}

#endif // ANIMATION_COLLECTION_LOADER_H
