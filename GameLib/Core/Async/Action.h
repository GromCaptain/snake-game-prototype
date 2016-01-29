#ifndef ACTION_H
#define ACTION_H

#include <functional>
#include <memory>

namespace Async
{

class ActionImpl;

class Action
	{
	public:
	explicit Action(const std::function<void()>& f);

	bool done() const;
	void wait();

	std::shared_ptr<ActionImpl> impl() const;

	private:
	std::shared_ptr<ActionImpl> pImpl;
	};

}

#endif
