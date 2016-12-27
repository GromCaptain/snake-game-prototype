#include "QtActionImplRunnable.h"

namespace Async
{

ActionImpl::QRunnableAction::QRunnableAction(const std::function<void ()>& f, ActionImpl& owner):
	action_(f), owner_(owner)
	{
	}

void ActionImpl::QRunnableAction::run()
	{
	action_();
	owner_.reportDone();
	}

}
