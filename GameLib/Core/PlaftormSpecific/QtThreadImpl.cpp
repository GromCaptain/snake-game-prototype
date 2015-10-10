#include "QtThreadImpl.h"

ThreadImpl::ThreadImpl():
	isFinished(false)
	{
	}

void ThreadImpl::start(Functor<void> f)
	{
	fun = f;
	isFinished = false;
	connect(this, &ThreadImpl::workDone, this, &ThreadImpl::finish);
	connect(this, &ThreadImpl::workDone, this, &ThreadImpl::quit);
	QThread::start();
	}

void ThreadImpl::stop()
	{
	QThread::quit();
	}

bool ThreadImpl::done() const
	{
	return isFinished;
	}

void ThreadImpl::run()
	{
	fun();
	emit workDone();
	}

void ThreadImpl::finish()
	{
	isFinished = true;
	}

