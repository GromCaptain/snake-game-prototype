#include "QtTimerImpl.h"

TimerImpl::TimerImpl()
	{
	QObject::connect(&timer_, &QTimer::timeout, this, &TimerImpl::tick);
	}

void TimerImpl::start(std::chrono::milliseconds interval, std::function<void (std::chrono::milliseconds)> func)
	{
	onTick_ = func;
	timerInterval_ = interval;
	timer_.start(interval.count());
	}

void TimerImpl::stop()
	{
	timer_.stop();
	}

void TimerImpl::tick()
	{
	onTick_(timerInterval_);
	}

