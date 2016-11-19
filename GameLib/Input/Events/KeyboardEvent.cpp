#include "KeyboardEvent.h"

#include "Core/Util/Assert.h"
#include "Core/Util/CloneFactory.h"

namespace Input
{

namespace
{
InputEvent* cloneKeyboardEvent(const InputEvent* event)
	{
	auto keyboardEvent = dynamic_cast<const KeyboardEvent*>(event);
	return new KeyboardEvent(*keyboardEvent);
	}

bool registered = CloneFactory<InputEvent>::instance().registerProduct({ typeid(KeyboardEvent) }, cloneKeyboardEvent);
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
