#include "ThreadPool.h"
#include "PlatformSpecific/Qt/QtThreadPoolImpl.h"

#include "Action.h"

namespace Async
{

ThreadPool::ThreadPool():
	pImpl(new ThreadPoolImpl)
	{
	}

ThreadPool& ThreadPool::mainThreadPool()
	{
	static ThreadPool mainPool(ThreadPoolImpl::mainThreadPool());
	return mainPool;
	}

void ThreadPool::addAction(std::shared_ptr<Action> action)
	{
	pImpl -> addAction(action -> impl());
	}

ThreadPool::ThreadPool(std::shared_ptr<ThreadPoolImpl> pool):
	pImpl(pool)
	{
	}

}