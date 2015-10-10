#include "GameState.h"

#include "Core/GameManager.h"

namespace State
{

GameState::GameState()
	{
	}
void GameState::switchState(StateType nextState, std::shared_ptr<SwitchStateInfo> info)
	{
	GameManager::instance().switchToState(nextState, info);
	}

}
