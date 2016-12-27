#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <functional>
#include <memory>

namespace Window
{

class Window;
class WindowManagerImpl;

class WindowManager
	{
	public:
	static WindowManager& instance();

	Window& mainWindowAsync();
	void doWorkInMainThread(std::function<void()> f);

	void prepareInput();

	private:
	WindowManager();

	private:
	std::shared_ptr<WindowManagerImpl> pImpl;
	std::shared_ptr<Window> mainWnd_;
	};

}

#endif // WINDOW_MANAGER_H
