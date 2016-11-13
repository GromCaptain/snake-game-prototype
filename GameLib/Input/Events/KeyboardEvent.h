#ifndef KEYBOARD_EVENT_H
#define KEYBOARD_EVENT_H

#include "InputEvent.h"
#include "Input/KeyboardKey.h"

namespace Input
{

class KeyboardEvent : public InputEvent
	{
	public:
	KeyboardEvent(KeyboardKey key, EventType type);

	public:
	KeyboardKey key() const;

	private:
	KeyboardKey key_;
	};

}

#endif // KEYBOARD_EVENT_H
