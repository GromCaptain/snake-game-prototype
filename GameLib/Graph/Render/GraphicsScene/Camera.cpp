#include "Camera.h"

#include "Graph/GraphCore/Texture.h"
#include "GraphicsScene.h"
#include "Core/Data/Geometry/Rectangle.h"

namespace Graphics
{

template<typename Layer>
Camera<Layer>::Camera(const LayersOwner<Layer>& scene, const Size& sceneAreaSize):
	scene_(scene), sceneAreaSize_(sceneAreaSize)
	{
	}

template<typename Layer>
void Camera<Layer>::setResolution(const Size& resolution)
	{
	resolution_ = resolution;
	}

template<typename Layer>
void Camera<Layer>::moveTo(const Point& viewportCenter)
	{
	viewportCenter_ = viewportCenter;
	}

template<typename Layer>
Texture Camera<Layer>::getFrame() const
	{
	int left = viewportCenter_.x() - resolution_.width() / 2, top = viewportCenter_.y() - resolution_.height() / 2;
	Rectangle viewport = { Point(left, top), resolution_ };
	Texture output(sceneAreaSize_);
	for (auto layerId : scene_.layersOrder())
		{
		auto actorsToRender = scene_.actorsInArea(layerId, viewport);
		for (const auto& actor : actorsToRender)
			{
			Rectangle actorRect = actor -> rect();
			Point relativeActorLeftTop = { actorRect.left() - left, actorRect.top() - top };
			output.drawTexture(actor -> currentFrame(), { relativeActorLeftTop, actorRect.size() });
			}
		}
	return output;
	}

}
