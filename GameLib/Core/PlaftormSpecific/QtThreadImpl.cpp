#include "QtThreadImpl.h"

ThreadImpl::ThreadImpl():
	isFinished(false)
	{
	}

void ThreadImpl::start(std::function<void()> f)
	{
	fun = f;
	isFinished = false;
	connect(this, &ThreadImpl::finished, this, &ThreadImpl::finish, Qt::DirectConnection);
	QThread::start();
	}

void ThreadImpl::stop()
	{
	QThread::terminate();
	QThread::wait();
	}

bool ThreadImpl::done() const
	{
	return isFinished;
	}

void ThreadImpl::run()
	{
	fun();
	}

void ThreadImpl::finish()
	{
	isFinished = true;
	}

