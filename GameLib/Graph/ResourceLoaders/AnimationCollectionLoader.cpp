#include "AnimationCollectionLoader.h"

#include "../GraphCore/Animation.h"
#include "../GraphCore/AnimationCollection.h"
#include "AnimationLoader.h"
#include "Resources/Resources/Resource.h"
#include "Resources/Resources/ResourcePack.h"

#include "Core/Data/Geometry/Rectangle.h"

namespace Graphics
{

AnimationCollectionLoader::AnimationCollectionLoader()
	{
	}

AnimationCollection AnimationCollectionLoader::loadFromResources(const Resources::ResourcePack& resourcePack)
	{
	std::vector<String> animationNames = resourcePack.innerPackNames();
	std::map<String, Animation> animations;
	for (auto name : animationNames)
		{
		auto animation = AnimationLoader::loadFromResources(resourcePack.innerPack(name));
		animations.emplace(name, animation);
		}
	return AnimationCollection(animations);
	}

}
