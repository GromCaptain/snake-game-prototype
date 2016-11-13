#ifndef INPUT_H
#define INPUT_H

#include <memory>
#include <queue>

namespace Input
{

class InputImpl;
class InputEvent;

class Input
	{
	public:
	Input();

	void flushEvents();
	std::queue<std::shared_ptr<InputEvent>> eventQueue() const;

	InputImpl& impl();

	private:
	std::shared_ptr<InputImpl> pImpl;
	};

}

#endif // INPUT_H
