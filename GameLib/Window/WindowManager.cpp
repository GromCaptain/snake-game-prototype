#include "WindowManager.h"
#include "PlatformSpecific/Qt/QtWindowManagerImpl.h"
#include "Window.h"

#include "Input/Input.h"

namespace Window
{

WindowManager::WindowManager():
	pImpl(new WindowManagerImpl)
	{
	}

WindowManager& WindowManager::instance()
	{
	static WindowManager mgr;
	return mgr;
	}

Window& WindowManager::mainWindowAsync()
	{
	if (!mainWnd_)
		mainWnd_ = std::shared_ptr<Window>(new Window(pImpl -> mainWindowAsync()));
	return *mainWnd_;
	}

void WindowManager::doWorkInMainThread(std::function<void()> f)
	{
	pImpl -> doWorkInMainThread(f);
	}

void WindowManager::prepareInput()
	{
	mainWindowAsync().input().flushEvents();
	}

}
