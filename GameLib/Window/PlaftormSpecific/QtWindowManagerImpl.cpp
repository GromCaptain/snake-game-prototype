#include "QtWindowManagerImpl.h"

#include <QEventLoop>

#include "QtWindowImpl.h"

WindowManagerImpl::WindowManagerImpl():
	mainWnd(nullptr)
	{
	qRegisterMetaType< std::function<void()> >("std::function<void()>");
	connect(this, &WindowManagerImpl::requestForWork, this, &WindowManagerImpl::doWork, Qt::QueuedConnection);
	}

//WindowManagerImpl::WindowManagerImpl(const WindowManagerImpl& winMgr)
//	{
//	}

std::shared_ptr<WindowImpl> WindowManagerImpl::mainWindowAsync()
	{
	if (! mainWnd)
		doWorkInMainThread(std::bind(&WindowManagerImpl::createMainWindow, this));
	return mainWnd;
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
	mainWnd = std::shared_ptr<WindowImpl>(new WindowImpl);
	mainWnd -> show();
	}

