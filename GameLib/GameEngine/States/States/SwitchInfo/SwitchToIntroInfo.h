#ifndef SWITCH_TO_INTRO_INFO_H
#define SWITCH_TO_INTRO_INFO_H

#include <chrono>
#include <memory>

#include "SwitchStateInfo.h"
#include "Graph/Animation.h"

namespace State
{

class SwitchToIntroInfo : public SwitchStateInfo
	{
	public:
	SwitchToIntroInfo(std::chrono::milliseconds duration, std::shared_ptr<SwitchStateInfo> switchToLoadInfo, const Graphics::Animation& splashAnim);
	const std::chrono::milliseconds introDuration;
	std::shared_ptr<SwitchStateInfo> switchToLoadingInfo;
	const Graphics::Animation splashAnimation;
	};

}

#endif // SWITCH_TO_INTRO_INFO_H
