#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "GameState.h"

namespace State
{

class IntroState : public GameState
	{
	public:
	IntroState();

	void start(std::shared_ptr<SwitchStateInfo> info) override;
	void update(std::chrono::milliseconds elapsed) override;
	};

}

#endif // INTRO_STATE_H
