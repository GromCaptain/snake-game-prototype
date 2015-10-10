#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameState.h"

namespace State
{

class MenuState : public GameState
	{
	public:
	MenuState();

	void start(std::shared_ptr<SwitchStateInfo> info) override;
	void update(unsigned msecs) override;
	};

}

#endif // MENU_STATE_H
