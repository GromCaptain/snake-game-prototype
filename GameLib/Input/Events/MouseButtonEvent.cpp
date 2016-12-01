#include "MouseButtonEvent.h"

#include "Core/Util/Assert.h"
#include "Core/Util/CloneFactory.h"

namespace Input
{

namespace
{
bool registered = CloneFactory<InputEvent>::instance().registerProduct<MouseButtonEvent>();
}

MouseButtonEvent::MouseButtonEvent(MouseButton button, EventType type):
	InputEvent(type),
	button_(button)
	{
	ASSERT(type == EventType::MousePress || type == EventType::MouseRelease, "Wrong mouse button event type");
	}

MouseButton MouseButtonEvent::button() const
	{
	return button_;
	}

}
