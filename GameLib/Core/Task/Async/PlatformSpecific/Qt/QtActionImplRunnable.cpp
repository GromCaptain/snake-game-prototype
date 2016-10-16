#include "QtActionImplRunnable.h"

namespace Async
{

ActionImpl::QRunnableAction::QRunnableAction(const std::function<void ()>& f, ActionImpl& owner):
	action(f), owner_(owner)
	{
	}

void ActionImpl::QRunnableAction::run()
	{
	action();
	owner_.reportDone();
	}

}
