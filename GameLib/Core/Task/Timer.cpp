#include "Timer.h"
#include "PlatformSpecific/Qt/QtTimerImpl.h"

#include "GameEngine/States/GameManager.h"

Timer::Timer():
	pImpl(new TimerImpl())
	{
	}

void Timer::start(std::chrono::milliseconds interval, std::function<void(std::chrono::milliseconds)> func)
	{
	pImpl -> start(interval, func);
	}
void Timer::stop()
	{
	pImpl -> stop();
	}
