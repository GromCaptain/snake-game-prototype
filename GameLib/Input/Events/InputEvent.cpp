#include "InputEvent.h"

namespace Input
{

InputEvent::InputEvent(EventType type):
	type_(type)
	{
	}

EventType InputEvent::type() const
	{
	return type_;
	}

}
