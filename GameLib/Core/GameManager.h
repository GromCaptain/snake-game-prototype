#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <map>

#include "States/GameState.h"
#include "Timer.h"

class GameManager
	{
	public:
	static GameManager& instance();

	void switchToState(State::StateType stateType, std::shared_ptr<State::SwitchStateInfo> switchInfo);

	void start();
	void update(unsigned msecs);

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
	//Subsystems subsys;
	bool readyToExit;
	};

#endif // GAME_MANAGER_H
