#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <chrono>
#include <map>

#include "Core/Task/Timer.h"
#include "States/GameState.h"

namespace GameEngine
{

class GameManager
	{
	public:
	static GameManager& instance();

	void switchToState(State::StateType stateType, std::shared_ptr<State::SwitchStateInfo> switchInfo);

	void start();
	void update(std::chrono::milliseconds msecs);

	private:
	GameManager();

	void init();
	void initStates();
	void initResources();
	void initGraphics();
	void initWindows();

	private:
	std::map<State::StateType, State::StatePtr> states;
	State::StatePtr currState;
	Timer timer;
	bool readyToExit;
	};

}

#endif // GAME_MANAGER_H
