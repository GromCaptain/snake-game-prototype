#include "Async.h"

#include "ThreadPool.h"
#include "Action.h"

#include "Core/Util/Assert.h"

namespace Async
{

void doAsync(const std::function<void()>& f)
	{
	auto action = std::make_shared<Action>(f);
	ThreadPool::mainThreadPool().addAction(action);
	}

void doAsync(std::shared_ptr<Action> action)
	{
	ASSERT(!action -> done(), "Cannot reuse already done actions");
	ThreadPool::mainThreadPool().addAction(action);
	}

}
