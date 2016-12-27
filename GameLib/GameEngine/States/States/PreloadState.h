#ifndef PRELOAD_STATE_H
#define PRELOAD_STATE_H

#include "GameState.h"
#include "Core/Data/String.h"
#include "Core/Task/Async/Action.h"

class ConfigReader;

namespace State
{

struct SwitchToIntroInfo;

class PreloadState : public GameState
	{
	public:
	PreloadState();

	void start(std::shared_ptr<SwitchStateInfo>) override;
	void update(std::chrono::milliseconds elapsed) override;

	private:
	void prepareApplication();
	static ConfigReader initConfigReader();
	void parseConfig(const ConfigReader& cfg);
	void loadData(const ConfigReader& cfg);
	void prepareMainWindow();

	private:
	static const String initConfigName_;
	std::shared_ptr<Async::Action> loadAction_;
	std::shared_ptr<SwitchToIntroInfo> switchInfo_;
	unsigned ScreenWidth_, ScreenHeight_;
	};

}

#endif // PRELOAD_STATE_H
