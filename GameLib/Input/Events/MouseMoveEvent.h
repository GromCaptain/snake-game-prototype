#ifndef MOUSE_MOVE_EVENT_H
#define MOUSE_MOVE_EVENT_H

#include "InputEvent.h"
#include "Core/Data/Geometry/Point.h"

namespace Input
{

class MouseMoveEvent : public InputEvent
	{
	public:
	MouseMoveEvent(Point pos);

	Point pos() const;

	private:
	Point pos_;
	};

}

#endif // MOUSE_MOVE_EVENT_H
