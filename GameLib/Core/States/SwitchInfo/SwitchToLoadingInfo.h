#ifndef SWITCH_TO_LOADING_INFO_H
#define SWITCH_TO_LOADING_INFO_H

#include "Core/String.h"
#include "Graph/Texture.h"
#include "SwitchStateInfo.h"

namespace State
{

struct SwitchToLoadingInfo : public SwitchStateInfo
	{
	String loadStateCfgFileName;
	Graphics::Texture loadingBackground;
	};

}

#endif // SWITCH_TO_LOADING_INFO_H
