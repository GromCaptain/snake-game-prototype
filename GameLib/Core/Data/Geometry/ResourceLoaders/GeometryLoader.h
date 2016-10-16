#ifndef GEOMETRY_LOADER_H
#define GEOMETRY_LOADER_H

class Geometry;

namespace Resources
{

class Resource;

}

class GeometryLoader
	{
	public:
	GeometryLoader();

	static Geometry loadFromResources(const Resources::Resource& resource);
	};

#endif // GEOMETRY_LOADER_H
