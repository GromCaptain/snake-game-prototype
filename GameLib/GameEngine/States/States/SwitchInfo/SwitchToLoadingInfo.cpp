#include "SwitchToLoadingInfo.h"

#include "Core/Data/Geometry/Rectangle.h"
#include "Graph/GraphCore/Animation.h"

namespace State
{

SwitchToLoadingInfo::SwitchToLoadingInfo(const String& loadStateCfgFName, StateInitCallback initCallback):
	loadStateCfgFileName(loadStateCfgFName), initFromPackCallback(initCallback)
	{
	}

}
