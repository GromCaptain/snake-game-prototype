#ifndef GEOMETRY_LOADER_H
#define GEOMETRY_LOADER_H

class Geometry;
class Resource;

class GeometryLoader
	{
	public:
	GeometryLoader();

	static Geometry loadFromResources(const Resource& resource);
	};

#endif // GEOMETRY_LOADER_H
