#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include <chrono>

namespace State
{

enum class StateType { Preload, Intro, Loading, Menu, Main };

struct SwitchStateInfo;

class GameState
	{
	public:
	GameState();

	virtual void start(std::shared_ptr<SwitchStateInfo> info) = 0;
	virtual void update(std::chrono::milliseconds elapsed) = 0;

	void switchState(StateType nextState, std::shared_ptr<SwitchStateInfo> info);
	};

typedef std::shared_ptr<GameState> StatePtr;

}

#endif // GAME_STATE_H
