#include "MouseMoveEvent.h"

#include "Core/Util/CloneFactory.h"

namespace Input
{

namespace
{
InputEvent* cloneMouseMoveEvent(const InputEvent* event)
	{
	auto mouseMoveEvent = dynamic_cast<const MouseMoveEvent*>(event);
	return new MouseMoveEvent(*mouseMoveEvent);
	}

bool registered = CloneFactory<InputEvent>::instance().registerProduct({ typeid(MouseMoveEvent) }, cloneMouseMoveEvent);
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
