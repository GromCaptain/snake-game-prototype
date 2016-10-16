//#include <gtest/gtest.h>
//#include "Core/Task/Async/Timer.h"

//#include <chrono>

//#include <atomic>

//using std::chrono::milliseconds;
//using std::chrono::steady_clock;
//using std::chrono::time_point;

//milliseconds durationMs(steady_clock::time_point startTime, steady_clock::time_point endTime)
//	{
//	return std::chrono::duration_cast<milliseconds>(endTime - startTime);
//	}

//class TimerTester
//	{
//	public:
//	TimerTester(std::function<void(milliseconds)> f): f_(f) {}

//	void start(milliseconds tick)
//		{
//		startTime = steady_clock::now();
//		timer.start(tick, std::bind(onTick, this));
//		}
//	void onTick(milliseconds tick)
//		{
//		f_(tick);
//		auto endTime = steady_clock::now();
//		unsigned elapsed = durationMs(startTime, endTime).count();
//		msecs.store(elapsed);
//		}

//	void startOnce(milliseconds tick)
//		{
//		startTime = steady_clock::now();
//		timer.start(tick, std::bind(onTickOnce, this));
//		}
//	void onTickOnce(milliseconds tick)
//		{
//		timer.stop();
//		f_(tick);
//		auto endTime = steady_clock::now();
//		unsigned elapsed = durationMs(startTime, endTime).count();
//		msecs.store(elapsed);
//		}

//	private:
//	Timer timer;
//	std::function<void(milliseconds)> f_;
//	steady_clock::time_point startTime;
//	std::atomic_uint msecs;
//	};

//void wait(milliseconds interval)
//	{
//	auto startTime = steady_clock::now();
//	while (steady_clock::now() - startTime < interval) {}
//	}

//TEST(Timer, WorkDone)
//	{
//	int x = 0;
//	Timer timer;
//	timer.start(milliseconds(10), [&x](std::chrono::milliseconds){ ++x; });
//	wait(milliseconds(100));
//	EXPECT_EQ(1, x);
//	}

//TEST(Timer, ElapsedAtLeastAsSpecified)
//	{
//	Timer timer;
//	steady_clock::time_point startTime = steady_clock::now(), endTime;
//	milliseconds interval(100);
//	timer.start(interval, [&endTime](milliseconds) { endTime = steady_clock::now(); });
//	auto elapsed = durationMs(startTime, endTime);
//	EXPECT_GE(elapsed.count(), interval.count());
//	}

//TEST(Timer, ElapsedNotMuchLongerThenSpecified)
//	{
//	Timer timer;
//	steady_clock::time_point startTime = steady_clock::now(), endTime;
//	milliseconds interval(100);
//	timer.start(interval, [&endTime](milliseconds) { endTime = steady_clock::now(); });
//	auto elapsed = durationMs(startTime, endTime);
//	EXPECT_LE(elapsed.count(), 2 * interval.count());
//	}
