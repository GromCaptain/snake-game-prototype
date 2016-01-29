#include <gtest/gtest.h>
#include "Core/Async/Async.h"
#include "Core/Async/Action.h"

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
		for (long long i = 1; i < 100000000; ++i)
			i += std::sqrt(double(i));
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
		zzz += std::sqrt(double(i));
	EXPECT_EQ(1, x);
	}
