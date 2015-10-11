#include "Thread.h"
#include "PlaftormSpecific/QtThreadImpl.h"

Thread::Thread():
	pImpl(new ThreadImpl)
	{
	}

void Thread::start(std::function<void()> f)
	{
	pImpl -> start(f);
	}

void Thread::stop()
	{
	pImpl -> stop();
	}

bool Thread::finished() const
	{
	return pImpl -> done();
	}

