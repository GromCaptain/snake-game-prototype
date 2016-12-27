#ifndef QT_TIMER_IMPL_H
#define QT_TIMER_IMPL_H

#include <functional>
#include <chrono>

#include <QTimer>

class TimerImpl : public QObject
	{
	Q_OBJECT
	public:
	TimerImpl();

	void start(std::chrono::milliseconds interval, std::function<void(std::chrono::milliseconds)> func);
	void stop();

	void tick();

	private:
	QTimer timer_;
	std::function<void(std::chrono::milliseconds)> onTick_;
	std::chrono::milliseconds timerInterval_;
	};

#endif // QT_TIMER_IMPL_H
