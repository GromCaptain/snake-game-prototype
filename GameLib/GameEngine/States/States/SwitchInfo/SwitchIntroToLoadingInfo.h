#ifndef SWITCH_INTRO_TO_LOADING_INFO_H
#define SWITCH_INTRO_TO_LOADING_INFO_H

#include "SwitchToLoadingInfo.h"
#include "Core/Data/Geometry/Geometry.h"
#include "Graph/Animation.h"
#include "Graph/AnimationCollection.h"
#include "Graph/Texture.h"

class String;

namespace State
{

class SwitchIntroToLoadingInfo : public SwitchToLoadingInfo
	{
	public:
	SwitchIntroToLoadingInfo(const String& loadStateCfgFName, StateInitCallback initCallback,
							 const Graphics::Texture& loadingBkg, const Graphics::AnimationCollection& loadingPBarAnims, const Geometry& loadingPBarGeom,
							 const Graphics::Animation& hourglassAnim, const Point& hourglassPos);
	const Graphics::Texture loadingBackground;
	const Graphics::AnimationCollection loadingProgressBarAnimations;
	const Geometry loadingProgressBarGeometry;
	const Graphics::Animation hourglassAnimation;
	const Point hourglassPosition;
	};

}

#endif // SWITCH_INTRO_TO_LOADING_INFO_H
