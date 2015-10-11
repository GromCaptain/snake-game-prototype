#include "Timer.h"

#include "GameManager.h"

Timer::Timer()
	{
	QObject::connect(&timer, &QTimer::timeout, this, &Timer::tick);
	}

void Timer::start(unsigned interval, std::function<void(unsigned)> func)
	{
	onTick = func;
	timerInterval = interval;
	timer.start(interval);
	}
void Timer::stop()
	{
	timer.stop();
	}

void Timer::tick()
	{
	onTick(timerInterval);
	}
