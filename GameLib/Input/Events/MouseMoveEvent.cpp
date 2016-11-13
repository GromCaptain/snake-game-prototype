#include "MouseMoveEvent.h"

namespace Input
{

MouseMoveEvent::MouseMoveEvent(Point pos):
	InputEvent(EventType::MouseMove),
	pos_(pos)
	{
	}

Point MouseMoveEvent::pos() const
	{
	return pos_;
	}

}
