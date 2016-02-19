#include "Camera.h"

#include "Texture.h"
#include "GraphicsScene.h"
#include "Core/Utility/Geometry/Rectangle.h"

namespace Graphics
{

Camera::Camera(const GraphicsScene& scene):
	scene_(scene), resolution_(scene.areaSize())
	{
	}

void Camera::setResolution(const Size& resolution)
	{
	resolution_ = resolution;
	}

void Camera::moveTo(const Point& viewportCenter)
	{
	viewportCenter_ = viewportCenter;
	}

Texture Camera::getFrame() const
	{
	int left = viewportCenter_.x() - resolution_.width() / 2, top = viewportCenter_.y() - resolution_.height() / 2;
	Rectangle viewport = { Point(left, top), resolution_ };
	Texture output(scene_.areaSize());
	for (auto layerId : GraphicsScene::layersOrder)
		{
		auto actorsToRender = scene_.actorsInArea(layerId, viewport);
		for (const auto& actor : actorsToRender)
			output.drawTexture(actor.currentFrame(), actor.rect());
		}
	return output;
	}

}
