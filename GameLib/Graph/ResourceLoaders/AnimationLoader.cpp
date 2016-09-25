#include "AnimationLoader.h"

#include "../Animation.h"
#include "Core/Utility/Geometry/Rectangle.h"
#include "GameUtil/ConfigReader.h"
#include "Resources/Resources/Resource.h"
#include "Resources/Resources/ResourcePack.h"

namespace Graphics
{

AnimationLoader::AnimationLoader()
	{
	}

Animation AnimationLoader::loadFromResources(const ResourcePack& resourcePack)
	{
	auto atlasResource = resourcePack.resource("atlas");
	Texture atlas(atlasResource);
	auto configResource = resourcePack.resource("config");
	ConfigReader reader(configResource.asString());
	unsigned frames = reader.getInt("Frames");
	if (frames == 1)
		return Animation(atlas);

	int frameDuration = reader.getInt("FrameDuration");
	std::vector<Rectangle> frameRects;
	frameRects.reserve(frames);
	for (unsigned i = 0; i < frames; ++i)
		{
		String rectName = String("Rect") + String::fromInt(i + 1);
		std::vector<String> rectCoords = reader.getArray(rectName);
		int x = rectCoords[0].toInt(), y = rectCoords[1].toInt();
		unsigned w = rectCoords[2].toInt(), h = rectCoords[3].toInt();
		frameRects.emplace_back(x, y, w, h);
		}
	return Animation(atlas, frameRects, std::chrono::milliseconds(frameDuration));
	}

}
