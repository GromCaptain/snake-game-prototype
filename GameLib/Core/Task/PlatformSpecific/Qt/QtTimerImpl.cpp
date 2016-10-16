#include "QtTimerImpl.h"

TimerImpl::TimerImpl()
	{
	QObject::connect(&timer, &QTimer::timeout, this, &TimerImpl::tick);
	}

void TimerImpl::start(std::chrono::milliseconds interval, std::function<void (std::chrono::milliseconds)> func)
	{
	onTick = func;
	timerInterval = interval;
	timer.start(interval.count());
	}

void TimerImpl::stop()
	{
	timer.stop();
	}

void TimerImpl::tick()
	{
	onTick(timerInterval);
	}

