#ifndef TIMER_H
#define TIMER_H

#include <functional>

#include <QObject>
#include <QTimer>

#include "Util/Functor.h"

class GameManager;

class Timer : public QObject
	{
	Q_OBJECT
	public:
	Timer();

	//void start(unsigned interval, std::function<void(GameManager&, unsigned)> func);
	void start(unsigned interval, Functor<void, unsigned> func);
	void stop();

	void tick();

	private:
	QTimer timer;
	//std::function<void(GameManager&, unsigned)> onTick;
	Functor<void, unsigned> onTick;
	unsigned timerInterval;
	};

#endif // TIMER_H
