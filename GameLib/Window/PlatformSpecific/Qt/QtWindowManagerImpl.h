#ifndef WINDOW_MANAGER_IMPL_H
#define WINDOW_MANAGER_IMPL_H

#include <functional>
#include <memory>

#include <QObject>

namespace Window
{

class WindowImpl;

class WindowManagerImpl : public QObject
	{
	Q_OBJECT
	public:
	WindowManagerImpl();

	std::shared_ptr<WindowImpl> mainWindowAsync();
	void doWorkInMainThread(std::function<void()> f);

	public slots:
	void doWork(std::function<void()> f);

	signals:
	void requestForWork(std::function<void()> f);
	void workDone();

	private:
	void createMainWindow();

	private:
	std::shared_ptr<WindowImpl> mainWnd_;
	};

}

#endif // WINDOW_MANAGER_IMPL_H
