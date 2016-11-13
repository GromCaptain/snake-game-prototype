#include "SwitchToIntroInfo.h"

#include "Core/Data/Geometry/Rectangle.h"

namespace State
{

SwitchToIntroInfo::SwitchToIntroInfo(std::chrono::milliseconds duration, std::shared_ptr<SwitchStateInfo> switchToLoadInfo, const Graphics::Animation& splashAnim):
	introDuration(duration), switchToLoadingInfo(switchToLoadInfo), splashAnimation(splashAnim)
	{
	}

}
