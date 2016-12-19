#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

namespace Input
{

enum EventType { KeyPress, KeyRelease, MousePress, MouseRelease, MouseMove };

class InputEvent
	{
	public:
	InputEvent(EventType type);
	virtual ~InputEvent() = 0;

	EventType type() const;

	bool handled() const;
	void setHandled();

	private:
	EventType type_;
	bool handled_ = false;
	};

}

#endif // INPUT_EVENT_H
