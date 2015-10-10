#ifndef PRELOAD_STATE_H
#define PRELOAD_STATE_H

#include "GameState.h"
#include "Core/String.h"
#include "Core/Thread.h"

class ConfigReader;

namespace State
{

struct SwitchToIntroInfo : public SwitchStateInfo
	{
	String loadStateCfgFileName;
	String introSplashFileName;
	};

class PreloadState : public GameState
	{
	public:
	PreloadState();

	void start(std::shared_ptr<SwitchStateInfo>) override;
	void update(unsigned msecs) override;

	private:
	void doWork();
	void parseConfig(const ConfigReader& cfg);

	private:
	static const String initConfig;
	Thread thread;
	std::shared_ptr<SwitchToIntroInfo> switchInfo;
	unsigned ScreenWidth, ScreenHeight;
	};

}

#endif // PRELOAD_STATE_H
