#ifndef CAMERA_H
#define CAMERA_H

#include <map>

#include "LayersOwner.h"
#include "Core/Data/Geometry/Point.h"
#include "Core/Data/Geometry/Size.h"

namespace Graphics
{
class GraphicsSceneLayer;
class Texture;

template<typename Layer>
class Camera
	{
	public:
	explicit Camera(const LayersOwner<Layer>& scene, const Size& sceneAreaSize);

	void setResolution(const Size& resolution);
	void moveTo(const Point& viewportCenter);
	Texture getFrame() const;

	private:
	const LayersOwner<Layer>& scene_;
	const Size sceneAreaSize_;
	Size resolution_;
	Point viewportCenter_;
	};

}

#endif // CAMERA_H
