#include "WindowManager.h"
#include "PlaftormSpecific/QtWindowManagerImpl.h"
#include "Window.h"

WindowManager::WindowManager():
	pImpl(new WindowManagerImpl)
	{
	}

//WindowManager::WindowManager(const WindowManagerImpl& impl):
//	pImpl(new WindowManagerImpl(impl))
//	{
//	}

WindowManager& WindowManager::instance()
	{
	static WindowManager mgr;
	return mgr;
	}

Window& WindowManager::mainWindowAsync()
	{
	if (!mainWnd)
		mainWnd = std::shared_ptr<Window>(new Window(pImpl -> mainWindowAsync()));
	return *mainWnd;
	}

void WindowManager::doWorkInMainThread(Functor<void> f)
	{
	pImpl -> doWorkInMainThread(f);
	}

