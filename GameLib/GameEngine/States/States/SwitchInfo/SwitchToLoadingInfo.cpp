#include "SwitchToLoadingInfo.h"

#include "Core/Data/Geometry/Rectangle.h"
#include "Graph/Animation.h"

namespace State
{

SwitchToLoadingInfo::SwitchToLoadingInfo(const String& loadStateCfgFName, StateInitCallback initCallback):
	loadStateCfgFileName(loadStateCfgFName), initFromPackCallback(initCallback)
	{
	}

}
