#ifndef THREAD_IMPL_H
#define THREAD_IMPL_H

#include <QThread>

#include "Util/Functor.h"

class ThreadImpl : public QThread
	{
	Q_OBJECT
	public:
	ThreadImpl();

	void start(Functor<void> f);
	void stop();
	bool done() const;

	// Платформенно-зависимые функции, не для использования в клиентском коде
	void run() override;
	void finish();

	signals:
	void workDone();

	private:
	Functor<void> fun;
	bool isFinished;
	};

#endif // THREAD_IMPL_H
