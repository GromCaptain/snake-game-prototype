#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <memory>

namespace Async
{

class ThreadPoolImpl;
class Action;

class ThreadPool
	{
	public:
	ThreadPool();

	static ThreadPool& mainThreadPool();

	void addAction(std::shared_ptr<Action> action);

	private:
	explicit ThreadPool(std::shared_ptr<ThreadPoolImpl> pool);

	private:
	std::shared_ptr<ThreadPoolImpl> pImpl;
	};

}

#endif
