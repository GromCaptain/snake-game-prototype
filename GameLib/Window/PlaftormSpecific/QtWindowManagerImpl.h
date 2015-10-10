#ifndef WINDOW_MANAGER_IMPL_H
#define WINDOW_MANAGER_IMPL_H

#include <memory>

#include <QObject>

#include "Util/Functor.h"

class WindowImpl;

class WindowManagerImpl : public QObject
	{
	Q_OBJECT
	public:
	WindowManagerImpl();
	//WindowManagerImpl(const WindowManagerImpl& winMgr);

	std::shared_ptr<WindowImpl> mainWindowAsync();
	void doWorkInMainThread(Functor<void> f);

	public slots:
//	void initMainWindow();
	void doWork(Functor<void> f);

	signals:
	void requestForWork(Functor<void> f);
	void workDone();
//	void askForInitMainWindow();
//	void reportMainWindowInited();

	private:
	void createMainWindow();

	private:
	std::shared_ptr<WindowImpl> mainWnd;
	};

#endif // WINDOW_MANAGER_IMPL_H
