#ifndef CAMERA_H
#define CAMERA_H

#include "Core/Data/Geometry/Point.h"
#include "Core/Data/Geometry/Size.h"

namespace Graphics
{

class GraphicsScene;
class Texture;

class Camera
	{
	public:
	explicit Camera(const GraphicsScene& scene);

	void setResolution(const Size& resolution);
	void moveTo(const Point& viewportCenter);
	Texture getFrame() const;

	private:
	const GraphicsScene& scene_;
	Size resolution_;
	Point viewportCenter_;
	};

}

#endif // CAMERA_H
