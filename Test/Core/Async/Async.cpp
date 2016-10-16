#include <gtest/gtest.h>
#include "Core/Task/Async/Async.h"
#include "Core/Task/Async/Action.h"

#include <cmath>

using Async::Action;

TEST(Async, SimpleActionDone)
	{
	int i = 0;
	auto action = std::make_shared<Action>([&i]() {++i;});
	Async::doAsync(action);
	action -> wait();
	EXPECT_EQ(1, i);
	}

TEST(Async, LongActionNeedWait)
	{
	auto longFunc = []()
		{
		double x = 1;
		for (int i = 0; i < 100; ++i)
			for (long long j = 1; j < 10000000; ++j)
				x += std::sqrt(double(j));
		};
	auto action = std::make_shared<Action>(longFunc);
	Async::doAsync(action);
	EXPECT_FALSE(action -> done());
	action -> wait();
	EXPECT_TRUE(action -> done());
	}

TEST(Async, SimpleFunctionDone)
	{
	int x = 0;
	auto inc = [&x]() {++x;};
	Async::doAsync(inc);
	double zzz = 0;
	for (int i = 0; i < 1000000; ++i)
		for (int j = 0; j < 1000; ++j)
			zzz += std::sqrt(double(i));
	EXPECT_EQ(1, x);
	}
