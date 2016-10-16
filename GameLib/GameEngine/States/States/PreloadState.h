#ifndef PRELOAD_STATE_H
#define PRELOAD_STATE_H

#include "GameState.h"
#include "Core/Data/String.h"
#include "Core/Task/Async/Action.h"

class ConfigReader;

namespace State
{

struct SwitchToLoadingInfo;

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
	static const String initConfigName;
	std::shared_ptr<Async::Action> loadAction;
	std::shared_ptr<SwitchToLoadingInfo> switchInfo;
	unsigned ScreenWidth, ScreenHeight;
	};

}

#endif // PRELOAD_STATE_H
