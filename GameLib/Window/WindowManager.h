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
	//WindowManager(const WindowManagerImpl& impl);

	Window& mainWindowAsync();
	void doWorkInMainThread(std::function<void()> f);

	private:
	WindowManager();

	private:
	std::shared_ptr<WindowManagerImpl> pImpl;
	std::shared_ptr<Window> mainWnd;
	};

}

#endif // WINDOW_MANAGER_H
