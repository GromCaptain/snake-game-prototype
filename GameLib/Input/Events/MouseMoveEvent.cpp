#include "MouseMoveEvent.h"

#include "Core/Util/CloneFactory.h"

namespace Input
{

namespace
{
bool registered = CloneFactory<InputEvent>::instance().registerProduct<MouseMoveEvent>();
}

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
