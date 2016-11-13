#ifndef SWITCH_TO_LOADING_INFO_H
#define SWITCH_TO_LOADING_INFO_H

#include "SwitchStateInfo.h"
#include "Core/Data/String.h"
#include "Core/Data/Geometry/Geometry.h"
#include "Graph/Animation.h"
#include "Graph/AnimationCollection.h"
#include "Graph/Texture.h"

namespace State
{

struct SwitchToLoadingInfo : public SwitchStateInfo
	{
	SwitchToLoadingInfo(const String& loadStateCfgFName, const Graphics::Texture& loadingBkg, const Graphics::AnimationCollection& loadingPBarAnims, const Geometry& loadingPBarGeom, const Graphics::Animation& hourglassAnim, const Point& hourglassPos);
	const String loadStateCfgFileName;
	const Graphics::Texture loadingBackground;
	const Graphics::AnimationCollection loadingProgressBarAnimations;
	const Geometry loadingProgressBarGeometry;
	const Graphics::Animation hourglassAnimation;
	const Point hourglassPosition;
	};

}

#endif // SWITCH_TO_LOADING_INFO_H
