#ifndef ACTION_IMPL_H
#define ACTION_IMPL_H

#include <functional>
#include <atomic>

namespace Async
{

class ActionImpl
	{
	public:
	explicit ActionImpl(const std::function<void()>& f);

	bool done() const;
	void wait();

	void reportDone();

	class QRunnableAction;

	QRunnableAction* runnable() const;

	private:
	QRunnableAction* qtAction;
	std::atomic_bool isDone;
	};

}

#endif
