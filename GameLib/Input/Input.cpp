#include "Input.h"
#include "PlatformSpecific/Qt/QtInputImpl.h"

namespace Input
{

Input::Input():
	pImpl(new InputImpl)
	{
	}

void Input::flushEvents()
	{
	pImpl -> flushEvents();
	}

std::queue<std::shared_ptr<InputEvent>> Input::eventQueue() const
	{
	return pImpl -> eventQueue();
	}

InputImpl& Input::impl()
	{
	return *pImpl;
	}

}
