#ifndef ACTION_IMPL_QRUNNABLE_ACTION_H
#define ACTION_IMPL_QRUNNABLE_ACTION_H

#include <functional>

#include "QtActionImpl.h"

#include <QRunnable>

namespace Async
{

class ActionImpl::QRunnableAction : public QRunnable
	{
	public:
	explicit QRunnableAction(const std::function<void()>& f, ActionImpl& owner);

	virtual void run() override;

	private:
	std::function<void()> action_;
	ActionImpl& owner_;
	};

}

#endif
