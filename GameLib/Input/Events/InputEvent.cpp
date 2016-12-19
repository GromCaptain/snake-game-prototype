#include "InputEvent.h"

namespace Input
{

InputEvent::~InputEvent()
	{
	}

InputEvent::InputEvent(EventType type):
	type_(type)
	{
	}

EventType InputEvent::type() const
	{
	return type_;
	}

bool InputEvent::handled() const
	{
	return handled_;
	}

void InputEvent::setHandled()
	{
	handled_ = true;
	}

}
