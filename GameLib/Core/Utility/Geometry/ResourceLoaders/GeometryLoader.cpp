#include "GeometryLoader.h"

#include "../Geometry.h"
#include "GameUtil/ConfigReader.h"
#include "Resources/Resources/Resource.h"

GeometryLoader::GeometryLoader()
	{
	}

Geometry GeometryLoader::loadFromResources(const Resource& resource)
	{
	ConfigReader cfg(resource.asString());
	String horType = cfg.getString("HorizontalType");
	String vertType = cfg.getString("VerticalType");
	if (horType == "fixed")
		{
		int x = cfg.getInt("PosX");
		unsigned width = cfg.getInt("Width");
		if (vertType == String("fixed"))
			{
			int y = cfg.getInt("PosY");
			unsigned height = cfg.getInt("Height");
			return Geometry::fixed({x, y}, {width, height});
			}
		else
			{
			int yPercent = cfg.getInt("YPercent");
			unsigned hPercent = cfg.getInt("HeightPercent");
			unsigned scrHeight = cfg.getInt("OriginalScreenHeight");
			return Geometry::fixedHorizontalScalableVertical(x, width, yPercent, hPercent, scrHeight);
			}
		}
	else
		{
		int xPercent = cfg.getInt("XPercent");
		unsigned wPercent = cfg.getInt("WidthPercent");
		unsigned scrWidth = cfg.getInt("OriginalScreenWidth");
		if (vertType == String("fixed"))
			{
			int y = cfg.getInt("PosY");
			unsigned height = cfg.getInt("Height");
			return Geometry::scalableHorizontalFixedVertical(xPercent, wPercent, scrWidth, y, height);
			}
		else
			{
			int yPercent = cfg.getInt("YPercent");
			unsigned hPercent = cfg.getInt("HeightPercent");
			unsigned scrHeight = cfg.getInt("OriginalScreenHeight");
			return Geometry::scalable({xPercent, yPercent}, {wPercent, hPercent}, {scrWidth, scrHeight});
			}
		}
	}

