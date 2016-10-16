#include "WindowManager.h"
#include "PlatformSpecific/Qt/QtWindowManagerImpl.h"
#include "Window.h"

namespace Window
{

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

void WindowManager::doWorkInMainThread(std::function<void()> f)
	{
	pImpl -> doWorkInMainThread(f);
	}

}
