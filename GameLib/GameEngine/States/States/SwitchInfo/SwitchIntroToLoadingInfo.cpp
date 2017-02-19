#include "SwitchIntroToLoadingInfo.h"

#include "Core/Data/Geometry/Rectangle.h"
#include "Graph/GraphCore/Animation.h"

namespace State
{

SwitchIntroToLoadingInfo::SwitchIntroToLoadingInfo(const String& loadStateCfgFName, StateInitCallback initCallback,
												   const Graphics::Texture& loadingBkg, const Graphics::AnimationCollection& loadingPBarAnims, const Geometry& loadingPBarGeom,
												   const Graphics::Animation& hourglassAnim, const Geometry& hourglassGeom):
	SwitchToLoadingInfo(loadStateCfgFName, initCallback),
	loadingBackground(loadingBkg),
	loadingProgressBarAnimations(loadingPBarAnims), loadingProgressBarGeometry(loadingPBarGeom),
	hourglassAnimation(hourglassAnim), hourglassGeometry(hourglassGeom)
	{
	}

}
