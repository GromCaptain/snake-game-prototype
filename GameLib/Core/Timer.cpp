#include "Timer.h"
#include "PlaftormSpecific/QtTimerImpl.h"

#include "GameManager.h"

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
