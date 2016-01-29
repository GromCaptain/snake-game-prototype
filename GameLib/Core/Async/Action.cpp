#include "Action.h"
#include "PlatformSpecific/Qt/QtActionImpl.h"

#include "ThreadPool.h"

namespace Async
{

Action::Action(const std::function<void()>& f):
	pImpl(new ActionImpl(f))
	{
	}

bool Action::done() const
	{
	return pImpl -> done();
	}

void Action::wait()
	{
	pImpl -> wait();
	}

std::shared_ptr<ActionImpl> Action::impl() const
	{
	return pImpl;
	}

}
