#ifndef THREAD_H
#define THREAD_H

#include <functional>
#include <memory>

class ThreadImpl;

class Thread
	{
	public:
	Thread();

	void start(std::function<void()> f);
	void stop();

	bool finished() const;

	private:
	std::shared_ptr<ThreadImpl> pImpl;
	};

#endif // THREAD_H
