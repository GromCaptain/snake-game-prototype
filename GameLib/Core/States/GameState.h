#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>

namespace State
{

enum class StateType { Preload, Intro, Menu, Main };

class SwitchStateInfo {};

class GameState
	{
	public:
	GameState();

	virtual void start(std::shared_ptr<SwitchStateInfo> info) = 0;
	virtual void update(unsigned msecs) = 0;

	void switchState(StateType nextState, std::shared_ptr<SwitchStateInfo> info);
	};

typedef std::shared_ptr<GameState> StatePtr;

}

#endif // GAME_STATE_H
