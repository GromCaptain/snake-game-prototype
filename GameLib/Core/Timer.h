#ifndef TIMER_H
#define TIMER_H

#include <functional>
#include <chrono>
#include <memory>

class TimerImpl;

class Timer
	{
	public:
	Timer();

	void start(std::chrono::milliseconds interval, std::function<void(std::chrono::milliseconds)> func);
	void stop();

	private:
	std::shared_ptr<TimerImpl> pImpl;
	};

#endif // TIMER_H
