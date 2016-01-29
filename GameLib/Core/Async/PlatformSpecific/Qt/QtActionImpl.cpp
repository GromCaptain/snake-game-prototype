#include "QtActionImpl.h"
#include "QtActionImplRunnable.h"

namespace Async
{

ActionImpl::ActionImpl(const std::function<void()>& f):
	qtAction(new QRunnableAction(f, *this)), isDone(false)
	{
	}

bool ActionImpl::done() const
	{
	return isDone.load();
	}

void ActionImpl::wait()
	{
	while (!done()) {}
	}

void ActionImpl::reportDone()
	{
	isDone.store(true);
	}

ActionImpl::QRunnableAction* ActionImpl::runnable() const
	{
	return qtAction;
	}

}
