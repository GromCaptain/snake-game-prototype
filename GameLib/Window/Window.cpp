#include "Window.h"
#include "PlaftormSpecific/QtWindowImpl.h"

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

