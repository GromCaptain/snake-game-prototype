#include "GameManager.h"

#include "States/PreloadState.h"
#include "States/LoadingState.h"
#include "States/IntroState.h"
#include "States/MenuState.h"
#include "States/MainState.h"
#include "Graph/GraphicsManager.h"
#include "Resources/ResourcesManager.h"
#include "Window/WindowManager.h"

namespace GameEngine
{

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
	currState_ = states_[stateType];
	currState_ -> start(switchInfo);
	}

void GameManager::start()
	{
	init();
	currState_ = states_[State::StateType::Preload];
	currState_ -> start(std::shared_ptr<State::SwitchStateInfo>(nullptr));
	const std::chrono::milliseconds timerInterval = std::chrono::milliseconds(100);
	std::function<void(std::chrono::milliseconds)> pUpdate = std::bind(&GameManager::update, this, std::placeholders::_1);
	timer_.start(timerInterval, pUpdate);
	}

void GameManager::update(std::chrono::milliseconds msecs)
	{
	Window::WindowManager::instance().prepareInput();
	currState_ -> update(msecs);
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
	states_[StateType::Preload]	= std::shared_ptr<GameState>(new PreloadState());
	states_[StateType::Loading]	= std::shared_ptr<GameState>(new LoadingState());
	states_[StateType::Intro]	= std::shared_ptr<GameState>(new IntroState());
	states_[StateType::Menu]		= std::shared_ptr<GameState>(new MenuState());
	states_[StateType::Main]		= std::shared_ptr<GameState>(new MainState());
	}

void GameManager::initResources()
	{
	auto mgr = Resources::ResourcesManager::instance();
	mgr.init();
	}
void GameManager::initGraphics()
	{
	auto mgr = Graphics::GraphicsManager::instance();
	mgr.init();
	}

void GameManager::initWindows()
	{
	auto mgr = Window::WindowManager::instance();
	}

}
