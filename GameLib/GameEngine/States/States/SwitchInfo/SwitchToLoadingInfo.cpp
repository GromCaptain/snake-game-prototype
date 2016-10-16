#include "SwitchToLoadingInfo.h"

#include "Core/Data/Geometry/Rectangle.h"
#include "Graph/Animation.h"

namespace State
{

SwitchToLoadingInfo::SwitchToLoadingInfo(const String& loadStateCfgFName, const Graphics::Texture& loadingBkg, const Graphics::AnimationCollection& loadingPBarAnims, const Geometry& loadingPBarGeom, const Graphics::Animation hourglassAnim, const Point& hourglassPos):
	loadStateCfgFileName(loadStateCfgFName), loadingBackground(loadingBkg),
	loadingProgressBarAnimations(loadingPBarAnims), loadingProgressBarGeometry(loadingPBarGeom),
	hourglassAnimation(hourglassAnim), hourglassPosition(hourglassPos)
	{
	}

}
