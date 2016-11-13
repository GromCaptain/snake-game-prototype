#ifndef MOUSE_BUTTON_EVENT_H
#define MOUSE_BUTTON_EVENT_H

#include "InputEvent.h"
#include "Input/MouseButton.h"

namespace Input
{

class MouseButtonEvent : public InputEvent
	{
	public:
	MouseButtonEvent(MouseButton button, EventType type);

	MouseButton button() const;

	private:
	MouseButton button_;
	};

}

#endif // MOUSE_BUTTON_EVENT_H
