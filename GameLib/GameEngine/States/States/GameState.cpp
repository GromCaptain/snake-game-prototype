#include "GameState.h"

#include "GameEngine/States/GameManager.h"

namespace State
{

GameState::GameState()
	{
	}
void GameState::switchState(StateType nextState, std::shared_ptr<SwitchStateInfo> info)
	{
	GameEngine::GameManager::instance().switchToState(nextState, info);
	}

}
