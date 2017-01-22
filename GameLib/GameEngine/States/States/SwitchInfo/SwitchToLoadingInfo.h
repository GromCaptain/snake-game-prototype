#ifndef SWITCH_TO_LOADING_INFO_H
#define SWITCH_TO_LOADING_INFO_H

#include <functional>

#include "SwitchStateInfo.h"
#include "Core/Data/String.h"

namespace Resources
{
class ResourcePack;
}

namespace State
{

using ProgressUpdateCallback = std::function<void(double)>;
using StateInitCallback = std::function<void(const Resources::ResourcePack&, ProgressUpdateCallback)>;

struct SwitchToLoadingInfo : public SwitchStateInfo
	{
	SwitchToLoadingInfo(const String& loadStateCfgFName, StateInitCallback initCallback);
	const String loadStateCfgFileName;
	StateInitCallback initFromPackCallback;
	};

}

#endif // SWITCH_TO_LOADING_INFO_H
