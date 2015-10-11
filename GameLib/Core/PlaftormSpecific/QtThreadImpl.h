#ifndef THREAD_IMPL_H
#define THREAD_IMPL_H

#include <functional>

#include <QThread>

class ThreadImpl : public QThread
	{
	Q_OBJECT
	public:
	ThreadImpl();

	void start(std::function<void()> f);
	void stop();
	bool done() const;

	// Платформенно-зависимые функции, не для использования в клиентском коде
	void run() override;
	void finish();

	signals:
	void workDone();

	private:
	std::function<void()> fun;
	bool isFinished;
	};

#endif // THREAD_IMPL_H
