#ifndef WINDOW_H
#define WINDOW_H

#include <memory>

#include "WindowType.h"

class WindowImpl;

class Window
	{
	public:
	Window(std::shared_ptr<WindowImpl> impl);
//	static Window& mainWindow();

	void setWindowType(WindowType type);
	void setResolution(unsigned w, unsigned h);

	private:
//	Window(WindowType type, unsigned w, unsigned h);
	std::shared_ptr<WindowImpl> pImpl;
	};

#endif // WINDOW_H
