#include "UIGraphicsScenePage.h"

#include <algorithm>

#include "UIActor.h"
#include "Graph/GraphCore/Texture.h"

namespace Graphics
{

UIGraphicsScenePage::UIGraphicsScenePage()
	{
	}

Texture UIGraphicsScenePage::render(const Texture& background) const
	{
	Texture frame = background;
	auto sortedActors = actorsSortedByZ();
	for (auto actorPtr : sortedActors)
		frame.drawTexture(actorPtr -> currentFrame(), actorPtr -> rect());
	return frame;
	}

void UIGraphicsScenePage::update(std::chrono::milliseconds elapsed)
	{
	for (auto actorPtr : actors_)
		actorPtr -> update(elapsed);
	}

void UIGraphicsScenePage::addActor(std::shared_ptr<UIActor> actor)
	{
	actors_.push_back(actor);
	}

std::vector<std::shared_ptr<UIActor>> UIGraphicsScenePage::actorsSortedByZ() const
	{
	std::vector<std::shared_ptr<UIActor>> result = actors_;
	std::sort(result.begin(), result.end(), [](const std::shared_ptr<UIActor>& actor1, const std::shared_ptr<UIActor>& actor2) { return (actor1 -> zValue()) < (actor2 -> zValue()); });
	return result;
	}

}
