#ifndef WINDOW_H
#define WINDOW_H

#include <memory>

#include "WindowType.h"

class WindowImpl;

class Window
	{
	public:
	Window(std::shared_ptr<WindowImpl> impl);

	void setWindowType(WindowType type);
	void setResolution(unsigned w, unsigned h);

	private:
	std::shared_ptr<WindowImpl> pImpl;
	};

#endif // WINDOW_H
