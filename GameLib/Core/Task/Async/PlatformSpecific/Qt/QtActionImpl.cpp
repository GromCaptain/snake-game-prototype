#include "QtActionImpl.h"
#include "QtActionImplRunnable.h"

namespace Async
{

ActionImpl::ActionImpl(const std::function<void()>& f):
	qtAction_(new QRunnableAction(f, *this)), isDone_(false)
	{
	}

bool ActionImpl::done() const
	{
	return isDone_.load();
	}

void ActionImpl::wait()
	{
	while (!done()) {}
	}

void ActionImpl::reportDone()
	{
	isDone_.store(true);
	}

ActionImpl::QRunnableAction* ActionImpl::runnable() const
	{
	return qtAction_;
	}

}
