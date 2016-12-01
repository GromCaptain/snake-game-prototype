#include "KeyboardEvent.h"

#include "Core/Util/Assert.h"
#include "Core/Util/CloneFactory.h"

namespace Input
{

namespace
{
bool registered = CloneFactory<InputEvent>::instance().registerProduct<KeyboardEvent>();
}

KeyboardEvent::KeyboardEvent(KeyboardKey key, EventType type):
	InputEvent(type),
	key_(key)
	{
	ASSERT(type == EventType::KeyPress || type == EventType::KeyRelease, "Wrong keyboard event type");
	}

KeyboardKey KeyboardEvent::key() const
	{
	return key_;
	}

}
