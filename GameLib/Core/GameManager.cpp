#include "GameManager.h"

#include "States/PreloadState.h"
#include "States/IntroState.h"
#include "States/MenuState.h"
#include "States/MainState.h"
#include "Resources/ResourcesManager.h"
#include "Graph/GraphicsManager.h"
#include "Window/WindowManager.h"

GameManager::GameManager()
	{
	}

GameManager& GameManager::instance()
	{
	static GameManager manager;
	return manager;
	}

void GameManager::switchToState(State::StateType stateType, std::shared_ptr<State::SwitchStateInfo> switchInfo)
	{
	currState = states[stateType];
	currState -> start(switchInfo);
	}

void GameManager::start()
	{
	init();
	currState = states[State::StateType::Preload];
	currState -> start(std::shared_ptr<State::SwitchStateInfo>(nullptr));
	const unsigned timerInterval = 100;
	//Functor<void, unsigned> pUpdate(this, &GameManager::update);
	std::function<void(unsigned)> pUpdate = std::bind(&GameManager::update, this, std::placeholders::_1);
	timer.start(timerInterval, pUpdate);
	}

void GameManager::update(unsigned msecs)
	{
	currState -> update(msecs);
	}

void GameManager::init()
	{
	initStates();
	initResources();
	initGraphics();
	initWindows();
	}
void GameManager::initStates()
	{
	using namespace State;
	states[StateType::Preload]	= std::shared_ptr<GameState>(new PreloadState());
	states[StateType::Intro]	= std::shared_ptr<GameState>(new IntroState());
	states[StateType::Menu]		= std::shared_ptr<GameState>(new MenuState());
	states[StateType::Main]		= std::shared_ptr<GameState>(new MainState());
	}

void GameManager::initResources()
	{
	auto mgr = ResourcesManager::instance();
	mgr.init();
	}
void GameManager::initGraphics()
	{
	auto mgr = GraphicsManager::instance();
	mgr.init();
	}

void GameManager::initWindows()
	{
	auto mgr = WindowManager::instance();
	}
