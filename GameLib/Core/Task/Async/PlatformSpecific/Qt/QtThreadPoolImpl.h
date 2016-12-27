#ifndef THREAD_POOL_IMPL_H
#define THREAD_POOL_IMPL_H

#include <memory>

#include <QThreadPool>

namespace Async
{

class ActionImpl;

class ThreadPoolImpl
	{
	public:
	ThreadPoolImpl();
	~ThreadPoolImpl();

	ThreadPoolImpl(const ThreadPoolImpl&) = delete;

	static std::shared_ptr<ThreadPoolImpl> mainThreadPool();

	void addAction(std::shared_ptr<ActionImpl> action);

	private:
	ThreadPoolImpl(QThreadPool* pool, bool isPoolOwner = false);

	private:
	QThreadPool* threadPool_;
	bool isOwner_;
	};

}

#endif
