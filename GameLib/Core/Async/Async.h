#ifndef ASYNC_H
#define ASYNC_H

#include <functional>
#include <memory>

namespace Async
{

class Action;

void doAsync(const std::function<void()>& f);
void doAsync(std::shared_ptr<Action> action);

}

#endif // ASYNC_H
