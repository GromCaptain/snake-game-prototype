#include "Window.h"
#include "PlatformSpecific/Qt/QtWindowImpl.h"

#include "Graph/Texture.h"

namespace Window
{

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

void Window::renderTexture(const Graphics::Texture& texture)
	{
	pImpl -> renderTexture(texture.impl());
	}

Input::Input&Window::input()
	{
	return pImpl -> input();
	}

}
