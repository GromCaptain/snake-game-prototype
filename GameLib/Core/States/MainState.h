#ifndef MAIN_STATE_H
#define MAIN_STATE_H

#include "GameState.h"

namespace State
{

class MainState : public GameState
	{
	public:
	MainState();

	void start(std::shared_ptr<SwitchStateInfo> info) override;
	void update(unsigned msecs) override;
	};

}

#endif // MAIN_STATE_H
