#ifndef THREAD_H
#define THREAD_H

#include <memory>

#include "Util/Functor.h"

class ThreadImpl;

class Thread
	{
	public:
	Thread();

	void start(Functor<void> f);
	void stop();

	bool finished() const;

	private:
	std::shared_ptr<ThreadImpl> pImpl;
	};

#endif // THREAD_H
