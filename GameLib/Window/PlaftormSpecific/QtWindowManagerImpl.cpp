#include "QtWindowManagerImpl.h"

#include <QEventLoop>

#include "QtWindowImpl.h"

WindowManagerImpl::WindowManagerImpl():
	mainWnd(nullptr)
	{
	qRegisterMetaType< Functor<void> >("Functor<void>");
	connect(this, &WindowManagerImpl::requestForWork, this, &WindowManagerImpl::doWork, Qt::QueuedConnection);
	}

//WindowManagerImpl::WindowManagerImpl(const WindowManagerImpl& winMgr)
//	{
//	}

std::shared_ptr<WindowImpl> WindowManagerImpl::mainWindowAsync()
	{
	if (! mainWnd)
		doWorkInMainThread(Functor<void>(this, &WindowManagerImpl::createMainWindow));
	return mainWnd;
	}

void WindowManagerImpl::doWorkInMainThread(Functor<void> f)
	{
	QEventLoop loop;
	connect(this, &WindowManagerImpl::workDone, &loop, &QEventLoop::quit);
	emit requestForWork(f);
	loop.exec();
	}

void WindowManagerImpl::doWork(Functor<void> f)
	{
	f();
	emit workDone();
	}

void WindowManagerImpl::createMainWindow()
	{
	mainWnd = std::shared_ptr<WindowImpl>(new WindowImpl);
	mainWnd -> show();
	}

