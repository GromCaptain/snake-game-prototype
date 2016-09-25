#include "SwitchToLoadingInfo.h"

#include "Core/Utility/Geometry/Rectangle.h"
#include "Graph/Animation.h"

namespace State
{

SwitchToLoadingInfo::SwitchToLoadingInfo(const String& loadStateCfgFName, const Graphics::Texture& loadingBkg, const Graphics::AnimationCollection& loadingPBarAnims, const Geometry& loadingPBarGeom):
	loadStateCfgFileName(loadStateCfgFName), loadingBackground(loadingBkg), loadingProgressBarAnimations(loadingPBarAnims), loadingProgressBarGeometry(loadingPBarGeom)
	{
	}

}
