#include "QtWindowManagerImpl.h"

#include <QEventLoop>

#include "QtWindowImpl.h"

namespace Window
{

WindowManagerImpl::WindowManagerImpl():
	mainWnd_(nullptr)
	{
	qRegisterMetaType< std::function<void()> >("std::function<void()>");
	connect(this, &WindowManagerImpl::requestForWork, this, &WindowManagerImpl::doWork, Qt::QueuedConnection);
	}

std::shared_ptr<WindowImpl> WindowManagerImpl::mainWindowAsync()
	{
	if (! mainWnd_)
		doWorkInMainThread(std::bind(&WindowManagerImpl::createMainWindow, this));
	return mainWnd_;
	}

void WindowManagerImpl::doWorkInMainThread(std::function<void()> f)
	{
	QEventLoop loop;
	connect(this, &WindowManagerImpl::workDone, &loop, &QEventLoop::quit);
	emit requestForWork(f);
	loop.exec();
	}

void WindowManagerImpl::doWork(std::function<void()> f)
	{
	f();
	emit workDone();
	}

void WindowManagerImpl::createMainWindow()
	{
	mainWnd_ = std::shared_ptr<WindowImpl>(new WindowImpl);
	mainWnd_ -> show();
	}

}
