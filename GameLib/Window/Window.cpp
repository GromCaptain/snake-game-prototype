#include "Window.h"
#include "PlaftormSpecific/QtWindowImpl.h"

//Window::Window(WindowType type, unsigned w, unsigned h):
//	pImpl(new WindowImpl)
//	{
//	pImpl -> setWindowType(type);
//	pImpl -> setResolution(w, h);
//	}

//Window& Window::mainWindow()
//	{
//	static Window mainWnd(WindowType::Windowed, 320, 240);
//	return mainWnd;
//	}

Window::Window(std::shared_ptr<WindowImpl> impl):
	pImpl(impl)
	{
	}

void Window::setWindowType(WindowType type)
	{
	pImpl -> setWindowType(type);
	}

void Window::setResolution(unsigned w, unsigned h)
	{
	pImpl -> setResolution(w, h);
	}

