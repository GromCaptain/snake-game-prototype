#include <gtest/gtest.h>
#include <Core/Thread.h>

#include <QThread>

class ThreadTest : public ::testing::Test
	{
	protected:
	virtual void SetUp() override { attempts = 0; }

	void doLoop() { while (!thread.finished() && attempts < maxAttempts) ++attempts; }
	void wait(unsigned msecs) { QThread::msleep(msecs); }

	protected:
	const unsigned maxAttempts = 1000 * 1000 * 1000;
	unsigned attempts;
	Thread thread;
	};

TEST_F(ThreadTest, Finished)
	{
	std::function<void()> doNothing = [] {};
	thread.start(doNothing);
	doLoop();
	ASSERT_LT(attempts, maxAttempts);
	EXPECT_TRUE(thread.finished());
	}

TEST_F(ThreadTest, ReallyExecutes)
	{
	int a = 0;
	std::function<void()> incA = [&a]{ ++a; };
	thread.start(incA);
	doLoop();
	ASSERT_LT(attempts, maxAttempts);
	EXPECT_TRUE(thread.finished());
	EXPECT_EQ(1, a);
	}

TEST_F(ThreadTest, Stop)
	{
	std::function<void()> foreverLoop = [] { while(true) {} };
	thread.start(foreverLoop);
	wait(200);
	thread.stop();
	EXPECT_TRUE(thread.finished());
	}

TEST_F(ThreadTest, RerunningAfterFinished)
	{
	int a = 0;
	std::function<void()> incA = [&a]{ ++a; };
	thread.start(incA);
	doLoop();
	ASSERT_LT(attempts, maxAttempts);
	EXPECT_TRUE(thread.finished());
	EXPECT_EQ(1, a);

	SetUp();
	thread.start(incA);
	doLoop();
	ASSERT_LT(attempts, maxAttempts);
	EXPECT_TRUE(thread.finished());
	EXPECT_EQ(2, a);
	}

TEST_F(ThreadTest, RerunningAfterStopped)
	{
	std::function<void()> foreverLoop = [] { while(true) {} };
	thread.start(foreverLoop);
	wait(200);
	thread.stop();
	EXPECT_TRUE(thread.finished());

	int a = 0;
	std::function<void()> incA = [&a]{ ++a; };
	thread.start(incA);
	doLoop();
	ASSERT_LT(attempts, maxAttempts);
	EXPECT_TRUE(thread.finished());
	EXPECT_EQ(1, a);
	}
