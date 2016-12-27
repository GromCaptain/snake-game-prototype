#include "QtThreadPoolImpl.h"

#include <QThreadPool>

#include "QtActionImpl.h"
#include "QtActionImplRunnable.h"

namespace Async
{

ThreadPoolImpl::ThreadPoolImpl():
	threadPool_(new QThreadPool), isOwner_(true)
	{
	}

ThreadPoolImpl::~ThreadPoolImpl()
	{
	if (isOwner_)
		delete threadPool_;
	}

std::shared_ptr<ThreadPoolImpl> ThreadPoolImpl::mainThreadPool()
	{
	static auto mainPool = std::shared_ptr<ThreadPoolImpl>(new ThreadPoolImpl(QThreadPool::globalInstance(), false));//std::make_shared<ThreadPoolImpl>(QThreadPool::globalInstance(), false);
	return mainPool;
	}

void ThreadPoolImpl::addAction(std::shared_ptr<ActionImpl> action)
	{
	threadPool_ -> start(action -> runnable());
	}

ThreadPoolImpl::ThreadPoolImpl(QThreadPool* pool, bool isPoolOwner):
	threadPool_(pool), isOwner_(isPoolOwner)
	{
	}

}
